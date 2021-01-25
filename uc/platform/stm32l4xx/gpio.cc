extern "C" {
#include <stdint.h>
#include "stm32l4xx_hal.h"
}

#include "uc/hal/gpio.h"

namespace uc {
namespace hal {

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

void Gpio::SetMode(GPIO_TypeDef* portx, GPIO_InitTypeDef* pin) {
    // XXX TODO (hj) obv dont' hard code a port for later
    HAL_GPIO_Init(portx, pin);
}

void Gpio::Set(GPIO_TypeDef* portx, uint16_t pin_num, GPIO_PinState pin_state) {
    HAL_GPIO_WritePin(portx, pin_num, pin_state);
}

} // namespace hal
} // namespace uc
