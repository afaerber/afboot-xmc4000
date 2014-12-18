ENTRY(reset)
MEMORY
{
	FLASH_cached      (RX)  : ORIGIN = 0x08000000, LENGTH = 0x00100000
	FLASH_uncached    (RX)  : ORIGIN = 0x0C000000, LENGTH = 0x00100000
	PSRAM             (RWX) : ORIGIN = 0x10000000, LENGTH = 0x00010000
	DSRAM1 /*system*/ (RWX) : ORIGIN = 0x20000000, LENGTH = 0x00010000
	DSRAM2 /*comm*/   (RWX) : ORIGIN = 0x30000000, LENGTH = 0x00008000
	STACK             (RW)  : ORIGIN = 0x2000ffff, LENGTH = 0
}
SECTIONS
{
	. = ORIGIN(FLASH_uncached);

	.text :
	{
		KEEP(*(.vector_table))
		*(.text)
		*(.rodata)
		*(.rodata.*)
		_end_text = .;
	} >FLASH_uncached

	.data :
	{
		_start_data = .;
		*(.data)
		_end_data = .;
	} >DSRAM1 AT >FLASH_uncached

	.bss :
	{
		_start_bss = .;
		*(.bss)
		_end_bss = .;
	} >DSRAM1

	.stack :
	{
		_stack_top = .;
	} >STACK
}
