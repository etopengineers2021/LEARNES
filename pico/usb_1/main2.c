#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#define UART_TX 0
#define UART_RX 1




 int  red_one_char(void){

  int ch = 0 ; 
  while (1){
   ch = getchar_timeout_us(100000);
  if(ch == PICO_ERROR_TIMEOUT){
  continue; 
  }
  // skip this 
  if(ch == '\r' || ch == '\n'){ 
    continue ;
    }
   return ch;      // real character
 }}

 void soft_uart_tx_byte( uint8_t data ){
   // UART idel state is HIGH 
   //START BIT , STOP BIT , PAIRT BIT , DATA BIT .  
   gpio_put(SOFT)

 }
int main(){
      stdio_init_all(); // print initilize 
      // led 
      gpio_init(25);
      gpio_set_dir(25,GPIO_OUT);
      gpio_put(25, 1); 
      //check usb cdc work
      printf("usb cdc works\n");
       // uart initlize       
      uart_init(uart0,115200 );
      gpio_set_function(UART_TX , GPIO_FUNC_UART);
      gpio_set_function(UART_RX , GPIO_FUNC_UART);

while(1){ 
       int ce = red_one_char();   // function call
       printf("uart  resived char %c\n",ce);
       sleep_ms(1000);
       uart_putc(uart0, (char)ce);
       sleep_ms(20);
       if (uart_is_readable(uart0)) {
          char rx = uart_getc(uart0);
          printf("UART1 RX GP5 received: %c\r\n", rx);
          } else {
            printf("UART1 RX got nothing. Check GP4 to GP5 wire.\r\n");
        }

        printf("----------------------\r\n");

   
}
}

          
// printf("USB received char  : %c\r\n", ch);
//  //send same character through uart tx 
//   uart_putc(uart0, (char)ch);
//   printf("send the char  to tx %c\n",ch);

 

 
        
//      // 5. Check whether it came back on UART RX GP1
//             if (uart_is_readable(uart0)) {
//                 char rx = uart_getc(uart0);
//                 printf("UART RX GP1 received: %c\r\n", rx);
//             } else {
//                 printf("UART RX got nothing. Check GP0-GP1 wire.\r\n");
//             }

//             printf("-------------------------\r\n");
//  sleep_ms(1000);
//         }
//            }
           
//     }
   
  



    //    while(1){
    //     //char tx_data = 's';
    //     char tx_data = 'A';  //uart_puts() means UART put string.
    //     uart_putc(uart0 , tx_data);
    //     if(uart_is_readable(uart0)){
    //         char rx_data = uart_getc(uart0);
    //         printf("the send data %c - the resived data %c\n",tx_data,rx_data);
    //     } else{
    //          printf("no_data\n");
    //     }
    //  sleep_ms(100);
    //    }

    
