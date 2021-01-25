#include <cstdint>

extern "C" {
#include "stm32l4xx_hal.h"
}

#include "uc/app/app.h"
#include "uc/hal/gpio.h"

uint16_t delay_ms= 500;
static uc::hal::Gpio::GpioPinStruct gpio_struct;

void uc::app::Main(void) {
    GPIO_InitTypeDef pin_desc;
    pin_desc.Mode = GPIO_MODE_OUTPUT_PP;
    pin_desc.Pull = GPIO_PULLUP;
    pin_desc.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    pin_desc.Pin = GPIO_PIN_5;

    gpio_struct.port = GPIOA;
    gpio_struct.pin  = &pin_desc;
 
    uc::hal::Gpio::SetMode(&gpio_struct);
    GPIO_PinState on = GPIO_PIN_SET;
    GPIO_PinState off = GPIO_PIN_RESET;

    while(1) {
        uc::hal::Gpio::Set(&gpio_struct, off);
        HAL_Delay(delay_ms); // Time in ms
        uc::hal::Gpio::Set(&gpio_struct, on);
        HAL_Delay(delay_ms);
    } 
}
