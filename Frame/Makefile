# CROSS_COMPILE = arm-linux-
CROSS_COMPILE = arm-linux-gnueabihf-
AS		= $(CROSS_COMPILE)as
LD		= $(CROSS_COMPILE)ld
CC		= $(CROSS_COMPILE)gcc
CPP		= $(CC) -E
AR		= $(CROSS_COMPILE)ar
NM		= $(CROSS_COMPILE)nm

STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump

export AS LD CC CPP AR NM
export STRIP OBJCOPY OBJDUMP

CFLAGS := -Wall -O2 -g
CFLAGS += -I $(shell pwd)/inc   # Find header files
CFLAGS += -I $(shell pwd)       # 当前目录下的头文件
CFLAGS += -I /usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/arm-linux-gnueabihf/libc/usr/include/freetype2

LDFLAGS := -lpthread -lm -lfreetype    # Choose link library,example -lpthread      

export CFLAGS LDFLAGS

TOPDIR := $(shell pwd)
export TOPDIR

TARGET := DeviceApp


obj-y += main.o
obj-y += src/     # Identified as a folder by '/'
obj-y += CAL/     # Identified as a folder by '/'
obj-y += KAL/     # Identified as a folder by '/'
obj-y += Display/     # Identified as a folder by '/'
obj-y += Fonts/     # Identified as a folder by '/'
obj-y += Encoding/     # Identified as a folder by '/'


all : start_recursive_build $(TARGET)
	@echo $(TARGET) has been built!

start_recursive_build:
	make -C ./ -f $(TOPDIR)/Makefile.build

$(TARGET) : start_recursive_build
	$(CC) -o $(TARGET) built-in.o $(LDFLAGS)

clean:
	rm -f $(shell find -name "*.o")
	rm -f $(TARGET)

distclean:
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.d")
	rm -f $(TARGET)
	