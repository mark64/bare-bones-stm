#pragma once

#include <cstdint>

namespace uc {
namespace hal {

class Gpio {
  public:
    typedef struct {
      GPIO_TypeDef* port;
      GPIO_InitTypeDef* pin;
    }GpioPinStruct;
    // Gpio Functions
    static void Init();
    static void SetMode(GpioPinStruct* gpio_pin);
    static void Set(GpioPinStruct* gpio_pin, GPIO_PinState pin_state);
    static void Get(GpioPinStruct* gpio_pin);
};

} // namespace uc
} // namespace hal
