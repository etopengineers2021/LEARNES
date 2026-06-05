#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

#define SOFT_UART_TX_PIN 2
#define UART_RX_PIN 5

#define BAUDRATE 9600
#define BIT_TIME_US 104

int read_one_char(void) {
    int ch;

    while (1) {
        ch = getchar_timeout_us(100000);
        if (ch == PICO_ERROR_TIMEOUT) {
            continue;
        }

        if (ch == '\n' || ch == '\r') {
            continue;
        }

        printf("Terminal received: %c\r\n", ch);
        return ch;
    }
}

void soft_uart_tx_byte(uint8_t data) {
    // UART idle state = HIGH
    gpio_put(SOFT_UART_TX_PIN, 1);
    busy_wait_us(BIT_TIME_US);

    // Start bit = LOW
    gpio_put(SOFT_UART_TX_PIN, 0);
    busy_wait_us(BIT_TIME_US);

    // Send 8 data bits, LSB first
    for (int i = 0; i < 8; i++) {
        int bit = (data >> i) & 1;
        gpio_put(SOFT_UART_TX_PIN, bit);
        busy_wait_us(BIT_TIME_US);
    }

    // Stop bit = HIGH
    gpio_put(SOFT_UART_TX_PIN, 1);
    busy_wait_us(BIT_TIME_US);
}

int main() {
    stdio_init_all();

    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }

    printf("\r\nSoftware UART TX test\r\n");
    printf("Connect GP2 to GP5\r\n");
    printf("Type one character\r\n\r\n");

    gpio_init(15);
    gpio_set_dir(15, GPIO_OUT);

    // GP2 = software UART TX
    gpio_init(SOFT_UART_TX_PIN);
    gpio_set_dir(SOFT_UART_TX_PIN, GPIO_OUT);
    gpio_put(SOFT_UART_TX_PIN, 1);   // idle HIGH

    // GP5 = UART1 RX
    uart_init(uart1, BAUDRATE);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    while (1) {
        int ch = read_one_char();

        // clear old UART1 RX data
        while (uart_is_readable(uart1)) {
            uart_getc(uart1);
        }

        printf("Sending using software UART TX on GP2...\r\n");

        soft_uart_tx_byte((uint8_t)ch);

        sleep_ms(20);

        if (uart_is_readable(uart1)) {
            char rx = uart_getc(uart1);
            printf("UART1 RX GP5 received data: %c\r\n", rx);
        } 
        else {
            printf("UART1 RX got nothing. Check GP2 to GP5 wire.\r\n");
        }

        printf(".....................................\r\n");
    }
}