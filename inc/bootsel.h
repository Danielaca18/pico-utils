#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/sync.h"
#include "hardware/structs/ioqspi.h"
#include "hardware/structs/sio.h"

/**
 * @brief Temporarily delays code
 * @param delay duration of delay
 */
__force_inline void inlineSleep(int delay) {
    for (volatile int i = 0; i < delay; ++i);
}

/** 
 * @brief Sets impedence of the specified chip select pin.
 * @param pin CS pin to be altered.
 * @param state State of CS pin. (0: High, !0: Low)
*/
__force_inline static void setCSImp(uint pin, int state) {
    uint gpio_state = state ? GPIO_OVERRIDE_NORMAL : GPIO_OVERRIDE_LOW;
    gpio_state = gpio_state << IO_QSPI_GPIO_QSPI_SS_CTRL_OEOVER_LSB;
    hw_write_masked(&ioqspi_hw->io[pin].ctrl, gpio_state, IO_QSPI_GPIO_QSPI_SS_CTRL_OEOVER_BITS);
}

/**
 * @brief Gets the state of the bootsel button
 * @return State of on-board bootsel button
 */
bool __no_inline_not_in_flash_func(get_bootsel_button)();