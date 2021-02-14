LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS := \
	$(LOCAL_DIR)/repo/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal.c \
	$(LOCAL_DIR)/repo/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_cortex.c \
	$(LOCAL_DIR)/repo/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_gpio.c \
	$(LOCAL_DIR)/repo/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_pwr.c \
	$(LOCAL_DIR)/repo/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_pwr_ex.c \
        $(LOCAL_DIR)/repo/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_rcc.c

GLOBAL_INCLUDES += \
	$(LOCAL_DIR)/repo/Drivers/CMSIS/ \
	$(LOCAL_DIR)/repo/Drivers/CMSIS/Device/ST/STM32F3xx/Include \
	$(LOCAL_DIR)/repo/Drivers/CMSIS/Include \
	$(LOCAL_DIR)/repo/Drivers/STM32F3xx_HAL_Driver/Inc

include $(MAKEDIR)/module.mk
