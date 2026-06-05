#include <stdio.h>
#include <pico/stdlib.h>
#include "hardware/gpio.h"
#include "hardware/watchdog.h"

#define IO_BASE 0x40014000
#define SIO_BA  0xd0000000

#define gpl(num) gpio_init(num)
#define MEM32(address ) (*(volatile  uint32_t* ) (address))
#define GPIO_1 MEM32(IO_BASE + 0x00c  ) 
#define LED 1
#define LED1 25 
#define ICSR   MEM32(0xE000ED04u)   //INTERRUPT CONTROL AND STATE REGISTER 
#define vtor  MEM32(0xe0000000 + 0xed08) //(0xE000ED08u)
#define shpr2 MEM32(0xE000ED1Cu)
#define shcsr MEM32(0xE000ED24u)
volatile uint32_t saved_ipsr;
volatile uint32_t saved_icsr;
volatile uint32_t saved_vtor;
volatile uint32_t saved_shpr2;
volatile uint32_t saved_shcsr;
//core system execption svc index- 11
void isr_svcall(void){
gpio_put(LED1, 1);
// saved_ipsr = read_ipsr();
    saved_icsr = ICSR;
    saved_vtor = vtor;
    saved_shpr2 = shpr2;
    saved_shcsr = shcsr;

 
 }

 static inline uint32_t read_ipsr(void) {
    uint32_t value;
    __asm volatile ("mrs %0, ipsr" : "=r"(value));
    return value;
}
 
int main(){
  stdio_init_all();
uint32_t *vector_table = (uint32_t *)vtor;
//  gpio_init(LED);
GPIO_1 = 5 ;//SET SIO 

MEM32(SIO_BASE +  0x024 ) = 1U << 1;//set pin into output mode. 
for(int i = 0 ; i < 2 ; i++){

MEM32(SIO_BASE  +  0x014 ) = 1U << 1; // gpio out high  

sleep_ms(2000);
MEM32(SIO_BASE  +  0x018 ) = 1U << 1;  // gpio low 
sleep_ms(2000);  
}

gpl(LED1);
gpio_set_dir(LED1, GPIO_OUT);



// for( int i = 0 ; i < 11 ; i++){
//    gpio_put(LED, 1); sleep_ms(300);
//    gpio_put(LED,0); sleep_ms(300);
// }
printf("before svs execption \n");
printf("ipsr = %u\n",read_ipsr());
printf("icsr = ox%08lx\n",ICSR);
printf("VTOR = 0x%08lx\n",vtor);

__asm volatile ("svc #0");  // call svc execption 
printf("after svc execption called\n ");

printf("ipsr = %u\n",saved_ipsr);
printf("icsr = ox%08lx\n",saved_icsr); //icsr = ox0000000b
printf("VTOR = 0x%08lx\n",saved_vtor);
 printf("Saved SHPR2 = 0x%08lx\n", saved_shpr2);
    printf("Saved SHCSR = 0x%08lx\n", saved_shcsr);
    printf("Vector[11] = 0x%08lx\n", vector_table[11]);
        printf("Vector[12] = 0x%08lx\n", vector_table[12]);
printf("isr_svcall = 0x%08lx\n", (uint32_t)isr_svcall);
// watchdog(0,0,0);
while(1);


 
}