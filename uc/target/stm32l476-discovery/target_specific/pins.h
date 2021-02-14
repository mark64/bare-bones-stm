#pragma once

#include "uc/platform/stm32l4xx/pins.h"

namespace uc {
namespace target_specific {

// The green LED pin on the board.
static constexpr uint16_t kLedPin = uc::platform::stm32l4xx::PA5;

}
}
