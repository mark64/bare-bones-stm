LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS := \
	$(LOCAL_DIR)/dummy.c

flash: $(OUTELF)
	openocd $(OPENOCD_FLAGS) -c 'program $(OUTELF) reset exit'

.PHONY: flash

include $(MAKEDIR)/module.mk
