#pragma once

#include "uc/platform/stm32f3xx/pins.h"

namespace uc {
namespace target_specific {

// LEDs in a circle on the board
// TODO (hj) There are many different LED pins but the abstraction
// only supports 1 well. 
static constexpr uint16_t kLedPin = uc::platform::stm32f3xx::PE8;
static constexpr uint16_t kLedPin2 = uc::platform::stm32f3xx::PE9;
static constexpr uint16_t kLedPin3 = uc::platform::stm32f3xx::PE10;
static constexpr uint16_t kLedPin4 = uc::platform::stm32f3xx::PE11;
static constexpr uint16_t kLedPin5 = uc::platform::stm32f3xx::PE12;
static constexpr uint16_t kLedPin6 = uc::platform::stm32f3xx::PE13;
static constexpr uint16_t kLedPin7 = uc::platform::stm32f3xx::PE14;
static constexpr uint16_t kLedPin8 = uc::platform::stm32f3xx::PE15;

}
}
