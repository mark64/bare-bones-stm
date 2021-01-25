#include <cstdint>

#include "stm32l4xx_hal.h"

#include "uc/hal/gpio.h"
#include "uc/platform/platform.h"


namespace uc {
namespace platform {

void Init() {
    // Init the HAL
    HAL_Init();

    // Init GPIO
    uc::hal::Gpio::Init();
}

} // namespace platform
} // namespace uc
