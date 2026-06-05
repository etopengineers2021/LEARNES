#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pico/multicore.h"

#define UART1_TX 8
#define UART1_RX 9
#define BAUDRATE 115200

void core1_main() {
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    while (1) {
        // LED ON means core1 loop started
        gpio_put(25, 1);
        sleep_ms(200);

        // Try UART1 from core1
        uart_puts(uart1, "CORE1 UART1 TEST\r\n");

        // LED OFF means uart_puts finished
        gpio_put(25, 0);
        sleep_ms(800);
    }
}
int main() {
    // Initialize UART1 in core0 before launching core1
    uart_init(uart1, BAUDRATE);
    gpio_set_function(UART1_TX, GPIO_FUNC_UART);  // GP8 = UART1 TX
    gpio_set_function(UART1_RX, GPIO_FUNC_UART);  // GP9 = UART1 RX

    sleep_ms(1000);

    multicore_launch_core1(core1_main);

    // Core0 stays alive but does nothing
    while (1) {
        tight_loop_contents();
    }
}