#pragma once

#include <cstdint>

namespace uc {
namespace hal {

class Gpio {
  public:
    enum PinType {
      // XXX TODO (hj) add more pin types here
      OUTPUT = 0,
      INTPUT = 1
    };
    // Gpio Functions
    static void Init();
    static void SetMode(uint16_t pin_num, PinType pin_mode);
    static void Set(uint16_t pin_num, uint8_t pin_state);
    static void Get(uint16_t pin_num);

  private:
    static GPIO_TypeDef* _GetPinPort(uint16_t pin_num);
    static uint16_t _GetPinNum(uint16_t pin_num);
    static GPIO_InitTypeDef _GetPinDef(uint16_t pin_num, PinType pin_mode);
};

} // namespace uc
} // namespace hal
