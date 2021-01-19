#include <cstdint>

//#include "Device/ST/STM32L4xx/Include/stm32l432xx.h"


extern "C" {
#include <stdint.h>
#include "stm32l4xx_hal.h"
}

#include "uc/app/app.h"
#include "uc/hal/gpio.h"

static GPIO_InitTypeDef gpio_struct;

void uc::app::Main(void) {
    HAL_Init();

    // XXX TODO (hj) add clock setup here too
   
    uc::hal::Gpio::Init();
    gpio_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_struct.Pull = GPIO_PULLUP;
    gpio_struct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    gpio_struct.Pin = GPIO_PIN_2;
 
    uc::hal::Gpio::SetMode(gpio_struct);
    uint16_t delay_ms= 500;

    while(1) {
        uc::hal::Gpio::Set(GPIO_PIN_2, GPIO_PinState.GPIO_PIN_SET);
        HAL_Delay(delay_ms); // Time in ms
	uc::hal::Gpio::Set(GPIO_PIN_2, GPIO_PinState.GPIO_PIN_RESET);
	HAL_Delay(delay_ms);
    } 

	
   //RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
   //GPIOA->MODER = 0xFFFF'F7FF;
   //GPIOA->PUPDR = 0x2 << 10;
   //int value = 0;
   //while (1) {
   //  // XXX uint32_t value = ((GPIOB->IDR >> 5) & 0x1);
   //  GPIOA->BSRR = (value << 5) | (((~value) & 0x1) << (16 + 5));
   //  value = !value;
   //  int delay = 100'000;
   //  while (delay--)
   //    ;
   //}
}

// XXX
void SystemInit() {}
