CROSS_COMPILE ?= arm-none-eabi-

CC = $(CROSS_COMPILE)gcc
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
SIZE = $(CROSS_COMPILE)size
GDB = $(CROSS_COMPILE)gdb
OPENOCD = openocd

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

flash-jlink: test
	$(GDB) test.elf -ex "target remote :2331" -ex "monitor reset" -ex "load" -ex "monitor reset" -ex "monitor go"

flash-sdram: test
	$(OPENOCD) -f interface/jlink.cfg -c "transport select swd" \
	  -f board/xmc4500-application-kit-sdram.cfg \
	  -c "init" \
	  -c "reset init" \
	  -c "flash probe 0" \
	  -c "flash info 0" \
	  -c "flash write_image erase test.bin 0x0C000000" \
	  -c "reset run" \
	  -c "shutdown"
