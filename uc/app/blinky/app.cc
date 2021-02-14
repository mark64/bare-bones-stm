#include <cstdint>
#include <chrono>

#include "uc/app/app.h"
#include "uc/hal/gpio.h"
#include "uc/hal/sleep.h"
#include "uc/target_specific/pins.h"

std::chrono::milliseconds delay_ms{500};

void uc::app::Main(void) {
    //uint16_t led_pin = PA5;
    uint16_t led_pin = uc::target_specific::kLedPin;
    uc::hal::Gpio::SetMode(led_pin, uc::hal::Gpio::OUTPUT);

    while(1) {
        uc::hal::Gpio::Set(led_pin, 0);
	uc::hal::Sleep(delay_ms);
        uc::hal::Gpio::Set(led_pin, 1);
	uc::hal::Sleep(delay_ms);
    } 
}
