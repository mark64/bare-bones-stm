LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS := \
	$(LOCAL_DIR)/platform.cc

MODULE_DEPS += \
	external/stm32cubel4

LINKER_SCRIPT := $(LOCAL_DIR)/sections.ld

ARCH := arm
ARM_CPU := cortex-m4

include $(MAKEDIR)/module.mk