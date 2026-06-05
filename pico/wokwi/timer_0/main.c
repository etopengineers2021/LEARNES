#include<stdio.h>
#include<pico/stdlib.h>


#define MEM32(add) (*(volatile uint32_t *) (add))
//NVIC REGISTER 
#define NVIC_ICPR    MEM32(0xE000e280)
#define NVIC_ISER    MEM32(0XE000E100)
#define  SC_VTOR MEM32( 0xe0000000 + 0xed08)


//TIMER REGISTER 
#define TIMER_BASE       0x40054000  
#define TIMER_ALARM0     MEM32(TIMER_BASE + 0x010u)
#define TIMER_TIMERAWL   MEM32(TIMER_BASE + 0x028u) 
#define TIMER_INTR       MEM32(TIMER_BASE + 0x034u) //raw 
#define TIMER_INTE       MEM32(TIMER_BASE + 0x038u)  //enable 
#define TIMER_INTS       MEM32(TIMER_BASE + 0x040u)  //status 

#define TIMER_IRQ_0  0 
#define  ALARM0_BIT (1U << 0 )   

void isr_timer0(){
  printf("isr_timer \n");
   TIMER_INTR = ALARM0_BIT;              // clear interrupt  
   //TIMER_ALARM0 = TIMER_TIMERAWL + 1000000u; // next 1 sec
      TIMER_ALARM0 = TIMER_TIMERAWL + 1000000U; 
   gpio_put(10,1);
}


int main() {
    stdio_init_all();
    gpio_init(10);
    gpio_set_dir(10, GPIO_OUT);
    // clear old timer interrupt
    // TIMER_INTR = ALARM0_BIT;
    // // clear old NVIC pending
    // NVIC_ICPR = 1u << TIMER_IRQ_0;
    //vector tabler is a pointer variable 
    uint32_t *vector_table =  ((uint32_t *)SC_VTOR );   // enable the  interrupt 
    vector_table[16 + TIMER_IRQ_0] =  (uint32_t ) isr_timer0;
    TIMER_INTE |= ALARM0_BIT;    // this line enable timer peripheral 
    NVIC_ISER = 1u << TIMER_IRQ_0; // cpu nvic enable 
    
    printf("TIMER_INTE = 0x%08lx\n", TIMER_INTE);
    TIMER_ALARM0 = TIMER_TIMERAWL + 1000000U; 
    printf("TIMER_INTE = 0x%08lx\n", TIMER_INTE);
  // clear old timer interrupt
     TIMER_INTR = ALARM0_BIT;
     // clear old NVIC pending
     NVIC_ICPR = 1u << TIMER_IRQ_0;
   
    //set the handler function 
    //  irq_set_exclusive_handler(TIMER_IRQ_0 , isr_timer0);
    //  irq_set_enabled(TIMER_IRQ_0 , true ) ; 
 
  // NVIC_ISER = 1u << 0;
  while(1){
        __asm volatile ("wfi");
  };
}

//#define TIMER_INTE    MEM32(0x40054034) 
// #define TIMER_ALARM0  MEM32( 0x40054010)
//#define TIMER_TIMERAWL MEM32(0x40054028) 
//#define TIMER_INTR      MEM32( 0X400054034)