#include <cstdint>

#include "external/STM32CubeL4/Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l432xx.h"
// XXX do I have hardfloat?
// https://launchpadlibrarian.net/170926122/readme.txt

int main(int argc, char** argv) {
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
  GPIOB->MODER = 0xFFFFF27F;
  GPIOB->PUPDR = 0x2 << 10;
  bool value = true;
  while (1) {
    // XXX uint32_t value = ((GPIOB->IDR >> 5) & 0x1);
    GPIOB->BSRR = (value << 3) | (((~value) & 0x1) << (16 + 3));
    value = !value;
    int delay = 10'000;
    while (delay--)
      ;
  }
}

// XXX
void SystemInit() {}
