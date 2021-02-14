LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS := \
	$(LOCAL_DIR)/gpio.cc \
	$(LOCAL_DIR)/hal_defines.c \
	$(LOCAL_DIR)/interrupts.c \
	$(LOCAL_DIR)/platform.cc \
	$(LOCAL_DIR)/sleep.cc

MODULE_DEPS += \
	external/stm32cubel4

LINKER_SCRIPT := $(LOCAL_DIR)/sections.ld

GLOBAL_INCLUDES += $(LOCAL_DIR)/external_inc

ARCH := arm
ARM_CPU := cortex-m4

include $(MAKEDIR)/module.mk
