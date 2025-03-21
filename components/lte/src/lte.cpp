#include "lte.h"
#include <math.h>
#include <stdlib.h>
#include "driver/uart.h"
#include <string.h>

#define UART_NUM UART_NUM_1

// --- Read Response from LTE Module ---
void read_uart_response(const char *tag) {
    uint8_t data[512];
    int length = uart_read_bytes(UART_NUM, data, sizeof(data) - 1, pdMS_TO_TICKS(1000));
    if (length > 0) {
        data[length] = '\0';
        ESP_LOGI(tag, "Response: %s", data);
    }
}

// --- Send AT Command to LTE Module ---
void send_at_command(const char *cmd) {
    uart_write_bytes(UART_NUM, cmd, strlen(cmd));
    uart_write_bytes(UART_NUM, "\r\n", 2);
}

void initialise_lte(void *param, const char *tag) {
    ESP_LOGI(tag, "Initializing LTE...");

    send_at_command("AT");  // Check if the module is responding
    vTaskDelay(pdMS_TO_TICKS(1000));
    read_uart_response(tag);

    send_at_command("AT+CPIN?");  // Check SIM card
    vTaskDelay(pdMS_TO_TICKS(1000));
    read_uart_response(tag);

    send_at_command("AT+CREG?");  // Check network registration
    vTaskDelay(pdMS_TO_TICKS(1000));
    read_uart_response(tag);

    send_at_command("AT+COPS?");  // Check operator
    vTaskDelay(pdMS_TO_TICKS(1000));
    read_uart_response(tag);

    send_at_command("AT+CGATT?");  // Check if attached to network
    vTaskDelay(pdMS_TO_TICKS(1000));
    read_uart_response(tag);

    send_at_command("AT+CIPSTATUS");  // Check IP connection status
    vTaskDelay(pdMS_TO_TICKS(1000));
    read_uart_response(tag);

    send_at_command("AT+QIACT=1");  // Activate PDP context
    vTaskDelay(pdMS_TO_TICKS(1000));
    read_uart_response(tag);

    send_at_command("AT+QIOPEN=1,0,\"TCP\",\"www.google.com\",80,0,1");  // Open TCP connection
    vTaskDelay(pdMS_TO_TICKS(3000));
    read_uart_response(tag);

    ESP_LOGI(tag, "LTE Initialization Complete");
    vTaskDelete(NULL);
}
