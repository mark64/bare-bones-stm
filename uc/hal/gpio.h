#pragma once

#include <cstdint>

namespace uc {
namespace hal {

class Gpio {
  public:
    // Gpio Functions
    static void Init();
    static void SetMode(GPIO_InitTypeDef p);
    static void Set(Pin p, bool val);
    static void Get(Pin p, bool val);
};

} // namespace uc
} // namespace hal
