#include <stdio.h>
#include <pico/stdlib.h>
#include "hardware/spi.h"

#define  SPI_PORT spi0  //spi port 
//pins for sio
#define PIN_MISO 16   //rx
#define PIN_CS  17  // chipselecct 
#define PIN_SCK   18 // clk 
#define PIN_MOSI   19 // tx 

int main(){
  stdio_init_all();   //initilize  the printf 
   spi_init(SPI_PORT,10*1000);; // initilize the spi0 perpheral 
  //led 
   gpio_init(25);
   gpio_set_dir(25,GPIO_OUT);
   gpio_put(25,1);

   // NORMAL GPIO TO SPI communication  PINS 
   gpio_set_function(PIN_MISO,GPIO_FUNC_SPI);  
   gpio_set_function(PIN_SCK , GPIO_FUNC_SPI);
   gpio_set_function(PIN_MOSI,GPIO_FUNC_SPI);
   
  gpio_init(PIN_CS);
  gpio_set_dir(PIN_CS,GPIO_OUT);
  gpio_put(PIN_CS,1);
 // api for spi 
  spi_set_format(
    SPI_PORT,  // port 0  or 1  
    8,   // bit per clk 
    SPI_CPOL_0 ,   
    SPI_CPHA_0
    ,SPI_MSB_FIRST
  );

    sleep_ms(2000);
     printf("SPI Test Started\n");
     uint8_t data =  0x07;   //data 
     while(1){
      gpio_put(PIN_CS , 0 );  //cs off spi read(start)
      spi_write_blocking(SPI_PORT,&data,1);  //api 
      gpio_put(PIN_CS , 1);  //cs on spi stop (end)
      printf("Sent: 0x07 \n");

        sleep_ms(1000);
     } 
         }



