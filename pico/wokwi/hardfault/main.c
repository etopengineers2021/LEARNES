#include <stdio.h>
#include <pico/stdlib.h>
#include "hardware/gpio.h"

#define  IO_BASE  0x40014000
#define SIO_BASE 0xd0000000
#define MEM32(ADDRER) (*(volatile uint32_t*) (ADDRER))
void isr_hardfault(void) {
  MEM32(SIO_BASE + 0X014) = 1U << 6 ;
}
int main(){
  stdio_init_all();
  MEM32(IO_BASE + 0x0cc ) = 5 ;
  MEM32(SIO_BASE + 0x024 ) = 1u << 25 ;
  MEM32(SIO_BASE + 0X014) = 1U << 25 ;

  MEM32(IO_BASE + 0x034 ) = 5 ;
  MEM32(SIO_BASE + 0x024 ) = 1u << 6 ;

MEM32(0x40014000 +0x00c)  = 5;
MEM32(SIO_BASE + 0x024 )  = 1U << 1;
MEM32(SIO_BASE + 0X014 )   = 1U<<1 ;
 printf("welcome back \n");
 sleep_ms(3000);
volatile uint32_t *badaddres = (volatile uint32_t *)0x20000001u;
volatile uint32_t value = *badaddres;
printf("fine , no issue \n");
  __asm volatile (".hword 0xDE00");
  sleep_ms(3000);
  MEM32(0x40014000 + 0x024)  = 5;
MEM32(SIO_BASE + 0x024 )  = 1U << 4;
MEM32(SIO_BASE + 0X014 )   = 1U<<4 ;
  printf("no fault/n");
while(1){
    tight_loop_contents();
}
    
}