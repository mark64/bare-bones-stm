LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

TOOLCHAIN_PREFIX := toolchain/arm/bin/arm-none-eabi-

ARCH_COMPILEFLAGS += -mthumb -mcpu=$(ARM_CPU) --specs=nosys.specs

ifeq ($(ARM_CPU),cortex-m4)
# TODO(mark): add floating point support
# ARCH_COMPILEFLAGS += -mfloat-abi=hard -mfpu=vfpv3

MODULE_SRCS += \
	$(LOCAL_DIR)/startup_ARMCM4.S
else
$(error unsupported CPU)
endif

include $(MAKEDIR)/module.mk
