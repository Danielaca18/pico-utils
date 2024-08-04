#include "bootsel.h"

bool __no_inline_not_in_flash_func(get_bootsel_button)() {
    const uint CS_PIN_INDEX = 1;
    uint32_t flags = save_and_disable_interrupts();
    setCSImp(CS_PIN_INDEX, 0);
    inlineSleep(10);

    // The HI GPIO registers in SIO can observe and control the 6 QSPI pins.
    bool button_state = !(sio_hw->gpio_hi_in & (1u << CS_PIN_INDEX));

    setCSImp(CS_PIN_INDEX, 1);
    restore_interrupts(flags);
    return button_state;
}