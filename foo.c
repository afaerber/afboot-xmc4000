#include <stdlib.h>
#include <stdint.h>

#define IOCRn_PCx_GP    0x10UL
#define IOCRn_PCx_MASK	0x1fUL

#define PDRn_PDx_STRONG	0x2UL
#define PDRn_PDx_MASK	0x7UL

int main(void)
{
	volatile uint32_t *P3_IOCR8 = (void *)(0x48028018 + 3 * 0x100);
	//volatile uint32_t *P3_PDR1  = (void *)(0x48028044 + 3 * 0x100);
	volatile uint32_t *P3_OMR   = (void *)(0x48028004 + 3 * 0x100);
	int i;

	// P3.9 -> GPO
	*P3_IOCR8 &= IOCRn_PCx_MASK << (3 + 8);
	*P3_IOCR8 |= IOCRn_PCx_GP << (3 + 8);
	// P3.9 -> strong
	//*P3_PDR1 &= PDRn_PDx_MASK << 4;
	//*P3_PDR1 |= PDRn_PDx_STRONG << 4;

	while (1) {
		*P3_OMR = (1 << (16 + 9)) | (1 << 9);
		for (i = 0; i < 1000000; i++) {
			asm volatile ("nop");
		}
	}

	return 0;
}

static void noop(void)
{
	while (1) {
	}
}

extern unsigned int _end_text;
extern unsigned int _start_data;
extern unsigned int _end_data;
extern unsigned int _start_bss;
extern unsigned int _end_bss;

void reset(void);

void reset(void)
{
	unsigned int *src, *dst;

	src = &_end_text;
	dst = &_start_data;
	while (dst < &_end_data) {
		*dst++ = *src++;
	}

	dst = &_start_bss;
	while (dst < &_end_bss) {
		*dst++ = 0;
	}

	main();
}

extern unsigned long _stack_top;

__attribute__((section(".vector_table")))
void (*vector_table[128])(void) = {
	(void (*))&_stack_top,
	reset,
	noop,
	noop,
	noop,
	noop,
	noop,
	NULL,
	NULL,
	NULL,
	NULL,
	noop,
	noop,
	NULL,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
	noop,
};
