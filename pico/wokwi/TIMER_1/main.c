#include <stdio.h>
#include "pico/stdlib.h"
#define MEM32(ADD) (*(volatile uint32_t *) (ADD))

#define LED 1 
#define TIMER_IRQ_1 1 
//cortex register 
#define NVIC_ICPR    MEM32(0xe000e280)  //use clear the interrupt 
#define SC_VTOR      MEM32(0xe000ed08)
#define NVIC_ISER    MEM32(0xE000E100) //use to enable irq1 

//timer register '
#define  TIMER_BASE    (0x40054000)
#define  ALARM1        MEM32(0x40054014)
#define TIMERAWH       MEM32(0x40054024)
#define TIMERAWL       MEM32(0x40054028)
#define TIMER_INTR     MEM32(0x40054034)
#define TIMER_INTE     MEM32(0x40054038)
#define TIMER_INTS     MEM32(0x40054040)


#define  ALARM0_BIT    ( 1u << 1 )
#define   TIMER_IRQ_1 1 
void isr_timer1(){
   printf("the alarm is firmed \n");
    TIMER_INTR = ALARM0_BIT;

}
int main() {
  stdio_init_all();
   gpio_init(LED);
   gpio_set_dir(LED,GPIO_OUT);
   gpio_put(LED,1);
 
   //1. SET HANDLER 
    uint32_t *vector = (uint32_t *) SC_VTOR;
    vector[16 + TIMER_IRQ_1  ] = (uint32_t ) isr_timer1;
// SET HANDLER  USING API 
  //  irq_set_exclusive_handler(TIMER_IRQ_1,isr_timer );
  //  irq_set_enabled(TIMER_IRQ_1 , true ); 
       printf("VECTOR[16] = 0x%08lx\n", (unsigned long)vector[16]);
       printf(" isr_timer  = 0x%08lx\n", (unsigned long)isr_timer1);

   printf("before clear \n");
   printf("TIMER)INTR   = 0x%08lx\n", TIMER_INTR);
   printf("NVIC_ICSR    = 0x%08lx\n",NVIC_ICPR);
     printf("NVIC_ISER    = 0x%08lx\n",NVIC_ISER );

  //2.CLEAR THE OLD  TIMER INTERR
    TIMER_INTR  = ALARM0_BIT;
    NVIC_ICPR  = 1 <<  TIMER_IRQ_1; 
     printf("after  \n");
        printf("TIMER_INTR   = 0x%08lx\n", TIMER_INTR);
   printf("NVIC_ISER    = 0x%08lx\n",NVIC_ISER );
 //SET AND FIRE ALARM   

      TIMER_INTE  |= ALARM0_BIT; 
     NVIC_ISER  = 1 <<  TIMER_IRQ_1;  
     ALARM1 =  TIMERAWL + 1000000U;
    
    printf("after  \n");
    printf("TIMER_INTR   = 0x%08lx\n", TIMER_INTR);
    printf("TIMER_INTE  = 0x%08lx\n", TIMER_INTE);
    printf("TIMER_INTS = 0x%08lx\n", TIMER_INTS);
     
   printf("NVIC_ISER    = 0x%08lx\n",NVIC_ISER );


}