#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0

#define PIN_MOSI 19   // DIN
#define PIN_SCK  18   // CLK
#define PIN_CS   17   // CS / LOAD

void max7219_write(uint8_t reg, uint8_t data) {
    uint8_t buf[2];

    buf[0] = reg;    // register address
    buf[1] = data;   // register data

    gpio_put(PIN_CS, 0);                 // CS LOW: start
    spi_write_blocking(SPI_PORT, buf, 2);
    gpio_put(PIN_CS, 1);                 // CS HIGH: latch data
}

void max7219_clear() {
    for (int row = 1; row <= 8; row++) {
        max7219_write(row, 0x00);
    }
}

void max7219_init() {
    max7219_write(0x0F, 0x00);   // Display test OFF
    max7219_write(0x09, 0x00);   // Decode mode OFF
    max7219_write(0x0B, 0x07);   // Scan limit: use all 8 rows
    max7219_write(0x0A, 0x03);   // Brightness low
    max7219_write(0x0C, 0x01);   // Shutdown OFF, normal operation

    max7219_clear();
}

int main() {
    stdio_init_all();

    // 1. Start SPI0
    spi_init(SPI_PORT, 100 * 1000);   // 100 kHz, easy speed

    // 2. Route SPI pins
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SCK,  GPIO_FUNC_SPI);

    // 3. CS is normal GPIO
    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);

    // 4. SPI mode 0, 8-bit, MSB first
    spi_set_format(
        SPI_PORT,
        8,
        SPI_CPOL_0,
        SPI_CPHA_0,
        SPI_MSB_FIRST
    );

    sleep_ms(1000);
    printf("MAX7219 SPI started\n");

    max7219_init();

    while (1) {
        for (int row = 1; row <= 8; row++) {
            max7219_clear();

            // Turn ON all LEDs in one row
            max7219_write(row, 0xFF);

            sleep_ms(300);
        }
    }
}