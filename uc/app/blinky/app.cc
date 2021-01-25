#include <cstdint>

extern "C" {
#include "stm32l4xx_hal.h"
}

#include "uc/app/app.h"
#include "uc/hal/gpio.h"
#include "uc/platform/stm32l4xx/pins.h"

uint16_t delay_ms= 500;

void uc::app::Main(void) {
    uint16_t led_pin = PA5;
    uc::hal::Gpio::SetMode(led_pin, uc::hal::Gpio::OUTPUT);

    while(1) {
        uc::hal::Gpio::Set(led_pin, 0);
        HAL_Delay(delay_ms); // Time in ms
        uc::hal::Gpio::Set(led_pin, 1);
        HAL_Delay(delay_ms);
    } 
}
