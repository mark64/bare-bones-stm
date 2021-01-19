#pragma once

#include <cstdint>

namespace uc {
namespace hal {

class Gpio {
  public:
    // Gpio Functions
    static void Init();
    static void SetMode(GPIO_InitTypeDef* pin);
    static void Set(uint16_t pin_num, GPIO_PinState pin_state);
    static void Get(GPIO_InitTypeDef pin, bool val);
};

} // namespace uc
} // namespace hal
