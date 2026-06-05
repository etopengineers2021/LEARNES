#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

#define UART0_TX 0
#define UART0_RX 1

#define UART1_TX 4 
#define UART1_RX 5 

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
   while(1){ 
         printf("\nROUND %d\n",count++ );
// send data from UART 0 
    uart_putc_raw(uart0 , 'A');

//send data from UART 1
   uart_putc_raw(uart1, 'B');
   sleep_ms(100);
    
//check UART0 RX 
    if(uart_is_readable(uart0) ){   //rx and tx loop backed its work , okey
     char c0 = uart_getc(uart0);   //if uart0 get data ,then print happen otherwise else
    printf("uart0 RESIVED %c\n",c0);
  }
  else{
    printf(" uart0 get nothing \n");
  }
//check uart1 RX 
    if(uart_is_readable(uart1)){  
     char c1 = uart_getc(uart1);  
 printf(" uart1 resived %c \n", c1);
 }
 else { 
     printf("uart1 get nothing \n");
  }
   sleep_ms(1000); 
   }
    
   

 
 
}

 
 
 