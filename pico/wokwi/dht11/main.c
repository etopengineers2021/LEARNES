#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#define DHT11 4 
#define I2C_PORT i2co
#define I2C_SDA  4
#define I2C_SCL  5
#define lcd_addr 0x27
int main(){
   stdio_init_all();
   printf("never give up ");
  // init dht11
   gpio_init(DHT11);
   gpio_pull_up(DHT11);
   
       // I2C setup
    i2c_init(I2C_PORT, 100 * 1000); // 100 kHz
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
   


}