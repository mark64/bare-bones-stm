LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS := \
	$(LOCAL_DIR)/main.cc

flash: all
	openocd $(OPENOCD_FLAGS) -c 'program $(OUTELF) reset exit'

.PHONY: flash

include $(MAKEDIR)/module.mk
