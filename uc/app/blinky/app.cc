#include <cstdint>

extern "C" {
#include "stm32l4xx_hal.h"
}

#include "uc/app/app.h"
#include "uc/hal/gpio.h"

uint16_t delay_ms= 500;
static GPIO_InitTypeDef gpio_struct;

void uc::app::Main(void) {
    gpio_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_struct.Pull = GPIO_PULLUP;
    gpio_struct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    gpio_struct.Pin = GPIO_PIN_5;
 
    uc::hal::Gpio::SetMode(GPIOA, &gpio_struct);
    GPIO_PinState on = GPIO_PIN_SET;
    GPIO_PinState off = GPIO_PIN_RESET;

    while(1) {
        uc::hal::Gpio::Set(GPIOA, GPIO_PIN_5, off);
        HAL_Delay(delay_ms); // Time in ms
        uc::hal::Gpio::Set(GPIOA, GPIO_PIN_5, on);
        HAL_Delay(delay_ms);
    } 
}
