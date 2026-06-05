#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
 #include "hardware/adc.h"

/*
int main(){
  stdio_init_all();
 printf("ADC Example ,measuring GPIO26\n");
 adc_init();
 //make sure GPIO is high-impedance ,no pullups etc 
 adc_gpio_init(26);
 //select adc input 0 (GPIO26)
 adc_select_input(0);
 // Select ADC input 4 (internal temperature sensor)
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
  
 while(1) {
    // 12 -bit converstion ,assume max value == ADC_VREF == 3.3 V 
    const float conversion_factor = 3.3f / (1 << 12 ); 
    uint16_t result = adc_read();
    printf("raw value: 0x%03x, voltage: %f V\n", result,result * conversion_factor);
    sleep_ms(500);  
}

 } */


int main() {
    stdio_init_all();
    while(!stdio_usb_connected){
        sleep_ms(1000); 
       }
    printf("Onboard Temperature Sensor Example\n");

    adc_init();
    // Select ADC input 4 (internal temperature sensor)
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);

    const float conversion_factor = 3.3f / (1 << 12);

    while (1) {
        uint16_t raw = adc_read();
        float voltage = raw * conversion_factor;

        // Formula from RP2040 datasheet:
        // Temperature (°C) = 27 - (Vtemp - 0.706)/0.001721
        float temperature = 27.0f - (voltage - 0.706f) / 0.001721f;

        printf("Raw: %u, Voltage: %f V, Temp: %f °C\n", raw, voltage, temperature);
        sleep_ms(500);
    }
}