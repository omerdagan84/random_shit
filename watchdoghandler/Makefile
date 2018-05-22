CROSS := armv5l-timesys-linux-gnueabi-
TOOLCHAIN_PATH=/home/risco/work/at91sam9260_ek/toolchain

ARCH=arm

BUILD_PATH := $(shell pwd)
SRC_PATH := $(shell pwd)
OUTPUT_PATH := $(shell pwd)

DEBUG := 1
LDFLAGS_STATIC += 

LDFLAGS_LIB += -rdynamic -shared

CFLAGS += -fPIC -funwind-tables -Wall -D_GNU_SOURCE -D__USE_GNU \
	-I$(TOOLCHAIN_PATH)/include \
	
CFLAGS += -O3


CFLAGS += -DFS_PREFIX="\"\"" -D__arm__

GCC := $(CROSS)gcc
CPP := $(CROSS)cpp

$(BUILD_PATH)/%.d: $(SRC_PATH)/%.c
	@mkdir -p "$(@D)"
	@echo -n $(@D)/ > $(BUILD_PATH)/$*.d
	@$(CPP) -MM $(CFLAGS) $(SRC_PATH)/$*.c >> $(BUILD_PATH)/$*.d

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(BUILD_PATH)/%.d
	@mkdir -p "$(@D)"
	@cd $(dir $<) ; $(GCC) -c $(CFLAGS) $(notdir $<) -o $@

all: handlewatchdog

HANDLEWATCHDOG_FILES := \
watchdoghandler.c 

HANDLEWATCHDOG_OBJ_FILES := $(addprefix $(BUILD_PATH)/, $(HANDLEWATCHDOG_FILES:.c=.o))

handlewatchdog: $(HANDLEWATCHDOG_OBJ_FILES)
	@echo $@
	@mkdir -p "$(@D)"
	@$(GCC) -o $@ -Wl,--start-group $(HANDLEWATCHDOG_OBJ_FILES) -Wl,--end-group

DEPS_LIST := \
$(addprefix $(BUILD_PATH)/, $(HANDLEWATCHDOG_FILES:.c=.d)) 

dep: $(DEPS_LIST)

ifeq (0, $(words $(findstring $(MAKECMDGOALS), clean distclean )))
-include $(DEPS_LIST)
endif

clean:
