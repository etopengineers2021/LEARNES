#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
 
#define SOFT_UART_TX_PIN 2 
#define UART_RX_PIN 5
#define BANDRATE 9600
#define BIT_TIME_US 104

int read_one_char(void){
int ch;
 while(1){
    // this api read the terminal input 
    ch = getchar_timeout_us(100000);
    // this api used for CHECK IN DATASHEET,ITS SAY ABOUT THAT INPUT  
    if(ch == PICO_ERROR_TIMEOUT){ 
      continue;}
 if(ch == '\n' || ch =='\r'){
     continue;}
  printf("Terminal received : %c\n", ch );
   return ch ;
  } 
 
 }
 int main(){
    stdio_init_all();
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
 //   gpio_put(25, 1);
 
      uart_init(uart0,115200 );
      gpio_set_function(0 , GPIO_FUNC_UART);
      gpio_set_function(1 , GPIO_FUNC_UART);
  
            
      uart_init(uart1,115200 );
      gpio_set_function(8 , GPIO_FUNC_UART);
      gpio_set_function(9 , GPIO_FUNC_UART);
  
    //  gpio_putc(uart0, " HELLOW I MA HERE..");
    
     int ch = read_one_char();
     printf("the read char from uart = %c", ch );

 while(1){
 
     uart_puts(uart1, "Hello world!");
 
 }
while(1);
 }