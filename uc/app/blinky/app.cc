#include <cstdint>

//#include "Device/ST/STM32L4xx/Include/stm32l432xx.h"


extern "C" {
#include <stdint.h>
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_cortex.h"
#include "stm32l4xx_hal_rcc.h"
}

#include "uc/app/app.h"
#include "uc/hal/gpio.h"

static GPIO_InitTypeDef gpio_struct;
// XXX TODO (hj) This should NOT live here, but testing things out rn
// From
// https://github.com/STMicroelectronics/STM32CubeL4/blob/master/Projects/32L476GDISCOVERY/Examples/GPIO/GPIO_IOToggle/Src/system_stm32l4xx.c
uint32_t SystemCoreClock = 4000000;
const uint8_t  AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t  APBPrescTable[8] =  {0, 0, 0, 0, 1, 2, 3, 4};
const uint32_t MSIRangeTable[12] = {100000, 200000, 400000, 800000, 1000000, 2000000, \
	                                        4000000, 8000000, 16000000, 24000000, 32000000, 48000000};

void uc::app::Main(void) {
    HAL_Init();

    // XXX TODO (hj) add clock setup here too
   
    uc::hal::Gpio::Init();
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    gpio_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_struct.Pull = GPIO_PULLUP;
    gpio_struct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    gpio_struct.Pin = GPIO_PIN_5;
 
    uc::hal::Gpio::SetMode(&gpio_struct);
    uint16_t delay_ms= 1000;
    GPIO_PinState on = GPIO_PIN_SET;
    GPIO_PinState off = GPIO_PIN_RESET;
    GPIO_PinState pin_state;

    while(1) {
        uc::hal::Gpio::Set(GPIO_PIN_5, off);
        HAL_Delay(delay_ms); // Time in ms
        uc::hal::Gpio::Set(GPIO_PIN_5, on);
        HAL_Delay(delay_ms);
    } 
     //while(1) {
     //    int delay = 100'000;
     //    if (pin_state == on) { pin_state = off; }
     //    else {pin_state = on;}
     //    uc::hal::Gpio::Set(GPIO_PIN_5, pin_state);
     //    while (delay--) ;
     //}
	
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
