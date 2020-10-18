#!/bin/bash
set -e
set -o pipefail
INCLUDES="-I external/STM32CubeL4/Drivers/CMSIS/Include/ -I ."
./toolchain/arm/bin/arm-none-eabi-gcc -c main.cc -o main.o $INCLUDES -mthumb -mcpu=cortex-m4 --specs=nosys.specs -I external/STM32CubeL4/Drivers/STM32L4xx_HAL_Driver/Inc/
./toolchain/arm/bin/arm-none-eabi-gcc -c -o startup_ARMCM4.o toolchain/arm/share/gcc-arm-none-eabi/samples/startup/startup_ARMCM4.S
./toolchain/arm/bin/arm-none-eabi-gcc main.o startup_ARMCM4.o -o test.elf $INCLUDES -mthumb -mcpu=cortex-m4 --specs=nosys.specs -I external/STM32CubeL4/Drivers/STM32L4xx_HAL_Driver/Inc/ -Tsections.ld
