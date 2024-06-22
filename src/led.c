#include "led.h"

int setLed(bool state) {
    if (cyw43_arch_init()) return 1;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, state);
}