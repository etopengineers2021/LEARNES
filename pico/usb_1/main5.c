#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pico/multicore.h"

#define  LED 25
#define SOFT_UART_TX_PIN 2 
#define UART_RX_PIN 5

#define BIT_TIME_US 104 //104.16us

int read_one_char(void){
    int ch;

    while (1){
        // this api read the terminal input 
        ch = getchar_timeout_us(100000);
       // this api used for CHECK IN DATASHEET,ITS SAY ABOUT THAT INPUT  
        if (ch == PICO_ERROR_TIMEOUT){ 
        continue;}
    
        if (ch == '\n' || ch =='\r'){
        continue;}
        printf("Terminal received : %c\r\n", ch );
        return ch ;
  } 
 }

void soft_uart_tx_byte(uint8_t data ){
        // uart  ideal state high 
        // gpio_put(SOFT_UART_TX_PIN, 1);
        // INSTEAD OF -sleep_us(BIT_TIME_US);  
        // busy_wait_us(BIT_TIME_US);// 104 MICRO SECOND THE BIT GOES TO HIGH 
  // UART idle state = HIGH
    gpio_put(SOFT_UART_TX_PIN, 1);
    busy_wait_us(BIT_TIME_US);
        // START BIT = LOW 
        gpio_put(SOFT_UART_TX_PIN , 0 );
        busy_wait_us(BIT_TIME_US);

        //Send 8 data bits , LSB  first
        for(int i  = 0 ; i < 8 ; i++ ){ 
        int bit = (data >> i ) & 1 ; 
        gpio_put(SOFT_UART_TX_PIN , bit);
        busy_wait_us(BIT_TIME_US);
   }
        //soft bit = high
        gpio_put(SOFT_UART_TX_PIN, 1 );
        busy_wait_us(BIT_TIME_US);
 }


 int main(){
    stdio_init_all();
//     while (!stdio_usb_connected()) {
//     sleep_ms(100);
// }
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
    gpio_put(25 , 1);

    gpio_init(15);
    gpio_set_dir(15, GPIO_OUT);
    gpio_init(15);
    gpio_set_dir(15, GPIO_OUT);
       
    gpio_init(SOFT_UART_TX_PIN);
    gpio_set_dir(SOFT_UART_TX_PIN, GPIO_OUT);
    gpio_put(SOFT_UART_TX_PIN, 1);
 
   //UART1 RX IS USED TO CHECK THE SOFT TX
    uart_init(uart1,9600 );
    gpio_set_function(UART_RX_PIN  , GPIO_FUNC_UART);
  
    printf("the usb cdc works ");
while(1){
    int ch = read_one_char();  //
    // clear old rx data 

    while(uart_is_readable(uart1)){
    uart_getc(uart1);}

    printf("Sending using software UART TX on GP2...\r\n");
    // the input is transfered to tx use of this function   

    soft_uart_tx_byte( (uint8_t)ch);
    sleep_ms(20);

    // print the resived data
    if( uart_is_readable(uart1)){
    char rx = uart_getc(uart1); 
    printf("UART1 UART_RX_PIN RESIVED DATA %c\r\n",rx);

    }else {
          printf("uart1 Rx got nothing ,check GP2 to GP5 wire .\r\n ");
    }
       printf(".....................................\r\n"); 
             
 }
  gpio_put(15,1);

  while (1) {
        tight_loop_contents();
     }
 }