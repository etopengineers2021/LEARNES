/**
 * BMP180 Temperature & Pressure sensor - Raspberry Pi Pico (I2C)
 *
 * Adapted from the Pico SDK BME280 SPI example.
 * BMP180 uses I2C only (no SPI support), no humidity output.
 *
 * Wiring:
 *   GPIO 4 (pin 6)  SDA -> SDA on BMP180
 *   GPIO 5 (pin 7)  SCL -> SCL on BMP180
 *   3.3v  (pin 36)  VCC -> VCC on BMP180
 *   GND   (pin 38)  GND -> GND on BMP180
 *
 * BMP180 I2C address: 0x77 (fixed, cannot be changed)
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

// ── I2C config ──────────────────────────────────────────────────────────────
#define I2C_PORT       i2c0
#define I2C_SDA_PIN    4
#define I2C_SCL_PIN    5
#define BMP180_ADDR    0x77

// ── BMP180 registers ────────────────────────────────────────────────────────
#define BMP180_REG_ID          0xD0   // Should return 0x55
#define BMP180_REG_RESET       0xE0
#define BMP180_REG_CTRL        0xF4
#define BMP180_REG_DATA_MSB    0xF6
#define BMP180_REG_CALIB_START 0xAA   // 22 bytes: 0xAA–0xBF

// ── Oversampling setting (OSS) ───────────────────────────────────────────────
// 0 = ultra-low power, 1 = standard, 2 = high res, 3 = ultra-high res
#define OSS 1

// ── Calibration coefficients (read from chip at startup) ────────────────────
int16_t  AC1, AC2, AC3;
uint16_t AC4, AC5, AC6;
int16_t  B1, B2;
int16_t  MB, MC, MD;

// ── Low-level I2C helpers ────────────────────────────────────────────────────
static void bmp180_write_reg(uint8_t reg, uint8_t value) {
    uint8_t buf[2] = { reg, value };
    i2c_write_blocking(I2C_PORT, BMP180_ADDR, buf, 2, false);
}

static uint8_t bmp180_read_reg(uint8_t reg) {
    uint8_t val;
    i2c_write_blocking(I2C_PORT, BMP180_ADDR, &reg, 1, true);  // keep bus active
    i2c_read_blocking(I2C_PORT, BMP180_ADDR, &val, 1, false);
    return val;
}

static void bmp180_read_regs(uint8_t reg, uint8_t *buf, uint8_t len) {
    i2c_write_blocking(I2C_PORT, BMP180_ADDR, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, BMP180_ADDR, buf, len, false);
}

// ── Read 22-byte calibration block from EEPROM ──────────────────────────────
void bmp180_read_calibration() {
    uint8_t buf[22];
    bmp180_read_regs(BMP180_REG_CALIB_START, buf, 22);

    // All coefficients are big-endian (MSB first) — opposite of BME280!
    AC1 = (int16_t) ((buf[0]  << 8) | buf[1]);
    AC2 = (int16_t) ((buf[2]  << 8) | buf[3]);
    AC3 = (int16_t) ((buf[4]  << 8) | buf[5]);
    AC4 = (uint16_t)((buf[6]  << 8) | buf[7]);
    AC5 = (uint16_t)((buf[8]  << 8) | buf[9]);
    AC6 = (uint16_t)((buf[10] << 8) | buf[11]);
    B1  = (int16_t) ((buf[12] << 8) | buf[13]);
    B2  = (int16_t) ((buf[14] << 8) | buf[15]);
    MB  = (int16_t) ((buf[16] << 8) | buf[17]);
    MC  = (int16_t) ((buf[18] << 8) | buf[19]);
    MD  = (int16_t) ((buf[20] << 8) | buf[21]);

    printf("Calibration loaded: AC1=%d AC2=%d AC3=%d AC4=%u AC5=%u AC6=%u\n",
           AC1, AC2, AC3, AC4, AC5, AC6);
}

// ── Read raw uncompensated temperature (UT) ──────────────────────────────────
int32_t bmp180_read_raw_temp() {
    bmp180_write_reg(BMP180_REG_CTRL, 0x2E);  // trigger temp measurement
    sleep_ms(5);                               // datasheet: wait ≥4.5 ms
    uint8_t buf[2];
    bmp180_read_regs(BMP180_REG_DATA_MSB, buf, 2);
    return (int32_t)((buf[0] << 8) | buf[1]);
}

// ── Read raw uncompensated pressure (UP) ─────────────────────────────────────
int32_t bmp180_read_raw_pressure() {
    // Command byte: 0x34 + (OSS << 6)
    bmp180_write_reg(BMP180_REG_CTRL, 0x34 | (OSS << 6));

    // Wait time depends on OSS (datasheet Table 3)
    const int wait_ms[4] = { 5, 8, 14, 26 };
    sleep_ms(wait_ms[OSS]);

    uint8_t buf[3];
    bmp180_read_regs(BMP180_REG_DATA_MSB, buf, 3);
    int32_t up = ((int32_t)buf[0] << 16 | (int32_t)buf[1] << 8 | buf[2]) >> (8 - OSS);
    return up;
}

// ── Bosch compensation algorithm (from BMP180 datasheet §4.1.3) ──────────────
//
// Returns temperature in units of 0.1 °C  (e.g. 251 → 25.1 °C)
// Also computes the shared B5 value needed by pressure compensation.

int32_t B5_global;   // shared between temp & pressure compensation

int32_t bmp180_compensate_temp(int32_t UT) {
    int32_t X1 = ((UT - (int32_t)AC6) * (int32_t)AC5) >> 15;
    int32_t X2 = ((int32_t)MC << 11) / (X1 + (int32_t)MD);
    B5_global  = X1 + X2;
    return (B5_global + 8) >> 4;   // T in 0.1 °C
}

// Returns pressure in Pa
int32_t bmp180_compensate_pressure(int32_t UP) {
    int32_t B6 = B5_global - 4000;

    int32_t X1 = ((int32_t)B2 * ((B6 * B6) >> 12)) >> 11;
    int32_t X2 = ((int32_t)AC2 * B6) >> 11;
    int32_t X3 = X1 + X2;
    int32_t B3 = ((((int32_t)AC1 * 4 + X3) << OSS) + 2) >> 2;

    X1 = ((int32_t)AC3 * B6) >> 13;
    X2 = ((int32_t)B1 * ((B6 * B6) >> 12)) >> 16;
    X3 = ((X1 + X2) + 2) >> 2;
    uint32_t B4 = ((uint32_t)AC4 * (uint32_t)(X3 + 32768)) >> 15;
    uint32_t B7 = ((uint32_t)(UP - B3) * (50000 >> OSS));

    int32_t p;
    if (B7 < 0x80000000)
        p = (int32_t)((B7 << 1) / B4);
    else
        p = (int32_t)((B7 / B4) << 1);

    X1 = (p >> 8) * (p >> 8);
    X1 = (X1 * 3038) >> 16;
    X2 = (-7357 * p) >> 16;
    p = p + ((X1 + X2 + 3791) >> 4);

    return p;   // Pa
}

// ── Altitude from pressure (ISA standard atmosphere) ────────────────────────
float bmp180_altitude(int32_t pressure_pa) {
    // P0 = 101325 Pa at sea level
    return 44330.0f * (1.0f - powf((float)pressure_pa / 101325.0f, 1.0f / 5.255f));
}

// ── main ─────────────────────────────────────────────────────────────────────
int main() {
    stdio_init_all();

    // Initialise I2C at 400 kHz
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);

    // Make pins visible to picotool
    bi_decl(bi_2pins_with_func(I2C_SDA_PIN, I2C_SCL_PIN, GPIO_FUNC_I2C));

    printf("Hello, BMP180!\n");

    // Verify chip ID (should be 0x55)
    uint8_t chip_id = bmp180_read_reg(BMP180_REG_ID);
    printf("Chip ID: 0x%02X %s\n", chip_id,
           chip_id == 0x55 ? "(OK)" : "(unexpected — check wiring!)");

    // Load factory calibration coefficients
    bmp180_read_calibration();

    // Main measurement loop
    while (1) {
        // 1. Read & compensate temperature first (also populates B5_global)
        int32_t raw_temp = bmp180_read_raw_temp();
        int32_t temp     = bmp180_compensate_temp(raw_temp);

        // 2. Read & compensate pressure
        int32_t raw_pres = bmp180_read_raw_pressure();
        int32_t pressure = bmp180_compensate_pressure(raw_pres);

        // 3. Derive altitude
        float altitude = bmp180_altitude(pressure);

        printf("Temp.    = %.1f °C\n",   temp / 10.0f);
        printf("Pressure = %.2f hPa\n",  pressure / 100.0f);
        printf("Altitude = %.1f m\n\n",  altitude);

        sleep_ms(1000);
    }

    return 0;
}