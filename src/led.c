#include "led.h"

int cyw43_arch_init_once() {
    static bool called = false;
    int code = 0;
    if (!called) {
        code = cyw43_arch_init();
        called = true;
    } return code;
}

int set_led(bool state) {
    if (cyw43_arch_init_once()) return 1;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, state);
}