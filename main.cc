#include <cstdint>

#include "external/STM32CubeL4/Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l432xx.h"
// XXX
// XXX#include
// "external/STM32CubeL4/Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_hal.h"
// XXX do I have hardfloat?
// https://launchpadlibrarian.net/170926122/readme.txt

int main(int argc, char** argv) {
  // XXX replace
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
  GPIOB->MODER = 0xFFFFFEAF;
  int delay = 10'000;
  while (1) {
    GPIOB->ODR |= 0U << 3;
    delay = 10'000;
    while (--delay)
      ;
    GPIOB->ODR |= 1U << 3;
    delay = 10'000;
    while (--delay)
      ;
  }
  /*
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN |
                  RCC_AHB2ENR_GPIOCEN |
                  RCC_AHB2ENR_GPIOHEN;  // XXX | RCC_AHB2ENR_ADCEN;
  GPIOB->MODER &= ~(uint32_t{0x3F} << 6);
  GPIOB->MODER |= uint32_t{0x22} << 6;
  GPIOB->BSRR = 1 << 5;
  GPIOB->BSRR = 1 << 4;
  GPIOB->BSRR = 1 << 3;
  while (1)
    ;
  while (1) {
    uint32_t value = ((GPIOB->IDR >> 4) & 0x1);
    //    GPIOB->BSRR = (value << 3) | (((~value) & 0x1) << (16 + 3));
  }
  */
}

// XXX where does this come from?
void SystemInit() {}

// XXX
