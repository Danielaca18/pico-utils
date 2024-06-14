#include <stdio.h>
#include "pico/stdio.h"
#include "bootsel.h"

int main() {
    stdio_init_all();

    static bool button_state;
    button_state = false;

    while (true) {
        if (button_state != get_bootsel_button()) {
            button_state = !button_state;
            printf("Button is %s\n", button_state?"on":"off");
        }
    }

    return 1;
}