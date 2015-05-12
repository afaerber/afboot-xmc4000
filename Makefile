CROSS_COMPILE ?= arm-none-eabi-

CC = $(CROSS_COMPILE)gcc
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
SIZE = $(CROSS_COMPILE)size
GDB = $(CROSS_COMPILE)gdb

CFLAGS := -mthumb -mcpu=cortex-m4
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -Os -std=gnu99 -Wall
CFLAGS += -DSDRAM_BOARD
LDFLAGS := -nostartfiles -Wl,--gc-sections

obj-y += foo.o

all: test.elf test

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

test.elf: $(obj-y) Makefile
	$(CC) -T xmc4500.lds $(LDFLAGS) -o test.elf $(obj-y)

test: test.elf Makefile
	$(OBJCOPY) -Obinary test.elf test.bin
	$(OBJDUMP) -S test.elf > test.lst
	$(SIZE) test.elf

clean:
	@rm -f *.o *.elf *.bin *.lst

flash: test
	$(GDB) test.elf -ex "target remote :2331" -ex "monitor reset" -ex "load" -ex "monitor reset" -ex "monitor go"
