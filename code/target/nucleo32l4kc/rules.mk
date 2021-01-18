LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS := \
	$(LOCAL_DIR)/target.cc

STM32_CHIP := stm32l432kc

PLATFORM := stm32l4xx

OPENOCD_FLAGS := -f $(LOCAL_DIR)/openocd.cfg

include $(MAKEDIR)/module.mk
