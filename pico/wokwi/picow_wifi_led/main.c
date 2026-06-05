#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/cyw43_arch.h"

#include "lwip/tcp.h"
#include "lwip/netif.h"
#include "lwip/ip4_addr.h"

#define LED_PIN 15
#define HTTP_PORT 80

static bool led_state = false;
static struct tcp_pcb *server_pcb = NULL;

/*
    This function sends HTML page to phone/laptop browser.
*/
static void send_web_page(struct tcp_pcb *tpcb) {
    char response[1200];

    const char *state_text = led_state ? "ON" : "OFF";

    int len = snprintf(response, sizeof(response),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
        "<title>Pico W LED Control</title>"
        "<meta name='viewport' content='width=device-width, initial-scale=1'>"
        "<style>"
        "body{font-family:Arial;text-align:center;margin-top:50px;}"
        "button{font-size:30px;padding:20px;margin:15px;width:160px;}"
        ".on{background:#2ecc71;}"
        ".off{background:#e74c3c;}"
        "</style>"
        "</head>"
        "<body>"
        "<h1>Pico W LED Control</h1>"
        "<h2>LED is %s</h2>"
        "<a href='/on'><button class='on'>ON</button></a>"
        "<a href='/off'><button class='off'>OFF</button></a>"
        "</body>"
        "</html>",
        state_text
    );

    tcp_write(tpcb, response, len, TCP_WRITE_FLAG_COPY);
    tcp_output(tpcb);
}

/*
    This function runs when browser sends request.
    Example:
        GET /on
        GET /off
*/
static err_t http_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {
    if (p == NULL) {
        tcp_close(tpcb);
        return ERR_OK;
    }

    char request[512];

    uint16_t copy_len = p->tot_len;
    if (copy_len >= sizeof(request)) {
        copy_len = sizeof(request) - 1;
    }

    pbuf_copy_partial(p, request, copy_len, 0);
    request[copy_len] = '\0';

    tcp_recved(tpcb, p->tot_len);
    pbuf_free(p);

    printf("Browser request: %s\n", request);

    if (strncmp(request, "GET /on", 7) == 0) {
        gpio_put(LED_PIN, 1);
        led_state = true;
        printf("LED ON\n");
    }
    else if (strncmp(request, "GET /off", 8) == 0) {
        gpio_put(LED_PIN, 0);
        led_state = false;
        printf("LED OFF\n");
    }

    send_web_page(tpcb);

    tcp_close(tpcb);
    return ERR_OK;
}

/*
    This function runs when a browser connects to Pico W.
*/
static err_t http_accept(void *arg, struct tcp_pcb *newpcb, err_t err) {
    tcp_recv(newpcb, http_recv);
    return ERR_OK;
}

/*
    Start TCP server on port 80.
*/
static bool start_web_server(void) {
    server_pcb = tcp_new_ip_type(IPADDR_TYPE_ANY);

    if (server_pcb == NULL) {
        printf("Failed to create TCP server\n");
        return false;
    }

    err_t err = tcp_bind(server_pcb, IP_ANY_TYPE, HTTP_PORT);

    if (err != ERR_OK) {
        printf("TCP bind failed: %d\n", err);
        return false;
    }

    server_pcb = tcp_listen(server_pcb);

    if (server_pcb == NULL) {
        printf("TCP listen failed\n");
        return false;
    }

    tcp_accept(server_pcb, http_accept);

    printf("Web server started on port %d\n", HTTP_PORT);
    return true;
}

int main() {
    stdio_init_all();
    sleep_ms(3000);

    printf("\nPico W WiFi LED control started\n");

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);

    if (cyw43_arch_init()) {
        printf("WiFi init failed\n");
        return 1;
    }

    cyw43_arch_enable_sta_mode();

    printf("Connecting to WiFi: %s\n", WIFI_SSID);

    int result = cyw43_arch_wifi_connect_timeout_ms(
        WIFI_SSID,
        WIFI_PASSWORD,
        CYW43_AUTH_WPA2_AES_PSK,
        30000
    );

    if (result) {
        printf("WiFi connection failed. Error = %d\n", result);
        return 1;
    }

    printf("WiFi connected\n");

    if (netif_default) {
        printf("Pico W IP address: %s\n",
               ip4addr_ntoa(netif_ip4_addr(netif_default)));
    }

    /*
        lwIP raw TCP setup should be protected when using
        pico_cyw43_arch_lwip_threadsafe_background.
    */
    cyw43_arch_lwip_begin();
    bool server_ok = start_web_server();
    cyw43_arch_lwip_end();

    if (!server_ok) {
        printf("Web server start failed\n");
        return 1;
    }

    printf("Open this in phone/laptop browser:\n");
    printf("http://PICO_IP/on  -> LED ON\n");
    printf("http://PICO_IP/off -> LED OFF\n");

    while (true) {
        sleep_ms(1000);
    }

    cyw43_arch_deinit();
    return 0;
}