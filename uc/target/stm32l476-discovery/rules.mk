LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS := \
	$(LOCAL_DIR)/target.cc

STM32_CHIP := stm32l476rg

PLATFORM := stm32l4xx

OPENOCD_FLAGS := -f $(LOCAL_DIR)/openocd.cfg

GLOBAL_NO_EDIT_DEFINES += STM32L476xx=1 \
			  USE_HAL_DRIVER=1  #XXX huh

include $(MAKEDIR)/module.mk
