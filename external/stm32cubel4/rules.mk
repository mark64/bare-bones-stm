LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS := \
	$(LOCAL_DIR)/dummy.c

GLOBAL_INCLUDES += \
	$(LOCAL_DIR)/repo/Drivers/CMSIS/ \
	$(LOCAL_DIR)/repo/Drivers/CMSIS/Include \
	$(LOCAL_DIR)/repo/Drivers/STM32L4xx_HAL_Driver/Inc

include $(MAKEDIR)/module.mk
