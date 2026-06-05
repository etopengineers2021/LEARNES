#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/watchdog.h"
#define LED 25
enum{
  OFFF,
  ONN
};
int main() {
  stdio_init_all();
  printf("new call \n");
 gpio_init(LED);
 gpio_set_dir(LED, GPIO_OUT );
 gpio_init(1);
 gpio_set_dir(1,GPIO_OUT);
 gpio_put(1,1);
 sleep_ms(2000);
 gpio_put(1,0);
 for(int i = 0 ; i  < 10 ; i++) {
   gpio_put(LED ,ONN ); sleep_ms(500); // offsecond 
  gpio_put(LED, OFFF ); sleep_ms(500);

 }
 watchdog_reboot(0,0,0); //hardware reset ->resethandler
 while(1);
 



}