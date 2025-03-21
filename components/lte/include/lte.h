#ifndef LTE_H
#define LTE_H

#include <esp_log.h>

void initialise_lte(void *param, const char *tag);
void read_uart_response();
void send_at_command(const char *cmd);

#endif // LTE_H