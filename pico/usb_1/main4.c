#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
// #include "pico/multicore.h"
#include "pico/multicore.h"
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
void core1_main() {
     
  while(1){ 
        gpio_put(25, 1);
        sleep_ms(1000);
        uart_puts(uart1, "Message from UART1 from CORE 1  GP8\r\n");   
         gpio_put(25, 0);
        sleep_ms(1000);
}


}
 int main(){
      stdio_init_all();
      gpio_init(15);
      gpio_set_dir(15, GPIO_OUT);

 //   gpio_put(25, 1);
 
      uart_init(uart0,115200 );
      gpio_set_function(0 , GPIO_FUNC_UART);
      gpio_set_function(1 , GPIO_FUNC_UART);
  
      gpio_init(25);
      gpio_set_dir(25, GPIO_OUT);
      uart_init(uart1,115200 );
      gpio_set_function(8 , GPIO_FUNC_UART);
      gpio_set_function(9 , GPIO_FUNC_UART);


  
    //  gpio_putc(uart0, " HELLOW I MA HERE..");
       // Start core1
sleep_ms(1000);
    multicore_launch_core1(core1_main);
    int count = 0 ; 
    while(1){
         gpio_put(15, 1);
         sleep_ms(1000);
         uart_puts(uart0, "Message from UART0 GP0\r\n");
   //    uart_puts(uart1, "Message from UART1 GP8\r\n"); 
         gpio_put(15, 0);
         sleep_ms(1000);
      
 }

//   while (1) {
//         tight_loop_contents();
//     }
 }