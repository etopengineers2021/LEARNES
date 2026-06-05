#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

#define UART0_TX 0
#define UART0_RX 1

#define UART1_TX 4 
#define UART1_RX 5 
typedef enum { 
   SEND_TO_UART0,
   SEND_TO_UART1 
 }send_target_t;
 void term_puts( const char *s){
   uart_puts(uart0 , s);
 }
int main(){
   stdio_init_all();
   
   gpio_init(25);
   gpio_set_dir(25,GPIO_OUT);
   gpio_put(25,1); 
   uart_init(uart0,115200);
   gpio_set_function(UART0_TX ,GPIO_FUNC_UART );
   gpio_set_function(UART0_RX , GPIO_FUNC_UART);
  

   uart_init(uart1,115200);
   gpio_set_function (UART1_TX , GPIO_FUNC_UART);
   gpio_set_function (UART1_RX , GPIO_FUNC_UART);
   int count = 0 ; 
  bool command_mode = false;

while(1){ 
         
  term_puts("\n uart print work ");
  sleep_ms(1000);
  if(ch == '@' ){
   command_mode = true; 
         continue ; 
   }
 if(ch == '?'){
   term_puts("\r\n command :\r\n");
   term_puts(" @0 - send typed data to UART0\r\n");
   term_puts("@1 = send typed data to uart1\r\n");
   term_puts( " ? = show menu \r\n\r\n");
   continue;
}
 //send data based on selected target 
 if(target == SEND_TO_UART0){

}
 
}
}
 
 
 