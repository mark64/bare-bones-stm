#include "uc/hal/gpio.h"

extern "C" {
#include <stdint.h>
#include "stm32l4xx_hal.h"
}

namespace uc {
namespace hal {

static void Init() {
    // XXX TODO (hj) This should live in a separate place probably and not in
    // init
    __HAL_RCC_GPIOx_CLK_ENABLE();
}

static void SetMode(GPIO_InitTypeDef* pin) {
    // XXX TODO (hj) obv dont' hard code a port for later
    HAL_GPIO_Init(GPIOA, &pin)
}

static void Set(uint16_t pin_num, GPIO_PinState pin_state) {
    HAL_GPIO_WritePin(GPIOA, pin_num, pin_state);
}

} // namespace hal
} // namespace uc
