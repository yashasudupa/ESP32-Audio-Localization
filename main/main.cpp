#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Choose an external LED pin (e.g., GPIO 12)
constexpr gpio_num_t LED_PIN = GPIO_NUM_12;

extern "C" void app_main() {
    // Configure the LED pin as output
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << LED_PIN);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);

    while (true) {
        gpio_set_level(LED_PIN, 1);  // Turn the LED on
        vTaskDelay(pdMS_TO_TICKS(10000));  // Delay for 1000 ms
        gpio_set_level(LED_PIN, 0);  // Turn the LED off
        vTaskDelay(pdMS_TO_TICKS(10000));  // Delay for 1000 ms
    }
}
