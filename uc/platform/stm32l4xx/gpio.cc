extern "C" {
#include <stdint.h>
#include "stm32l4xx_hal.h"
}

#include "uc/hal/gpio.h"

namespace uc {
namespace hal {

namespace {

GPIO_TypeDef* _GetPinPort(uint16_t pin_num){
    // XXX TODO (hj) map these correctly
    return GPIOA;
}

uint16_t _GetPinNum(uint16_t pin_num) {
    // XXX TODO (hj) map these correctly
    return GPIO_PIN_5;
}

GPIO_InitTypeDef _GetPinDef(uint16_t pin_num, Gpio::PinType pin_mode) {
    // XXX TODO (hj) make these other pin options avaliable
    // Right now, only OUTPUT and INPUT is available 
    GPIO_InitTypeDef gpio_pin;
    gpio_pin.Pull = GPIO_PULLUP;
    gpio_pin.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    gpio_pin.Pin = _GetPinNum(pin_num);
    switch(pin_mode) {
        case Gpio::OUTPUT:
            gpio_pin.Mode = GPIO_MODE_OUTPUT_PP;
            break;
         default:
	    gpio_pin.Mode = GPIO_MODE_INPUT;
    }
    return gpio_pin;
}

}

void Gpio::Init() {
    // Init CLK to all GPIO banks
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
}

void Gpio::SetMode(uint16_t pin_num, uc::hal::Gpio::PinType pin_mode) {
    // Get the pin's port, mode, speed, and pin number
    GPIO_TypeDef* port = _GetPinPort(pin_num);
    GPIO_InitTypeDef gpio_pin = _GetPinDef(pin_num, pin_mode);
    // Init the pin through HAL
    HAL_GPIO_Init(port, &gpio_pin);
}

void Gpio::Set(uint16_t pin_num, uint8_t pin_state) {
    // Get the pin port and number
    GPIO_TypeDef* port = _GetPinPort(pin_num);
    uint16_t port_pin_num = _GetPinNum(pin_num);
    // Get the pin state
    GPIO_PinState gpio_pin_state = GPIO_PIN_RESET;
    if (pin_state)
	 gpio_pin_state = GPIO_PIN_SET;
    // Write the pin state through HAL
    HAL_GPIO_WritePin(port, port_pin_num, gpio_pin_state);
}

} // namespace hal
} // namespace uc
