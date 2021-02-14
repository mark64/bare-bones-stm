#include "uc/hal/sleep.h"

extern "C" {
#include "stm32l4xx_hal.h"
}

namespace uc {
namespace hal {

void Sleep(std::chrono::milliseconds delay) {
    HAL_Delay(delay.count());
}

} // hal
} // uc
