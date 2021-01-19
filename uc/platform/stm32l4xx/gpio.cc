extern "C" {
#include <stdint.h>
#include "stm32l4xx_hal.h"
}

#include "uc/hal/gpio.h"

namespace uc {
namespace hal {

void Gpio::Init() {
    // XXX TODO (hj) This should live in a separate place probably and not in
    // init
    __HAL_RCC_GPIOA_CLK_ENABLE();
}

void Gpio::SetMode(GPIO_InitTypeDef* pin) {
    // XXX TODO (hj) obv dont' hard code a port for later
    HAL_GPIO_Init(GPIOA, pin);
}

void Gpio::Set(uint16_t pin_num, GPIO_PinState pin_state) {
    HAL_GPIO_WritePin(GPIOA, pin_num, pin_state);
}

} // namespace hal
} // namespace uc
