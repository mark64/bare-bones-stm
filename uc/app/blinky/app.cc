#include <cstdint>

#include "Device/ST/STM32L4xx/Include/stm32l432xx.h"

int main(void) {
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  GPIOA->MODER = 0xFFFF'F7FF;
  GPIOA->PUPDR = 0x2 << 10;
  int value = 0;
  while (1) {
    // XXX uint32_t value = ((GPIOB->IDR >> 5) & 0x1);
    GPIOA->BSRR = (value << 5) | (((~value) & 0x1) << (16 + 5));
    value = !value;
    int delay = 100'000;
    while (delay--)
      ;
  }
  return 0;
}

// XXX
void SystemInit() {}