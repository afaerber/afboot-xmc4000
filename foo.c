#include <stdlib.h>
#include <stdint.h>

#define SCU_BASE	0x50004000UL

#define SCU_TRAPCLR_SOSCWDGT	(1UL << 0)
#define SCU_TRAPCLR_SVCOLCKT	(1UL << 2)

#define SCU_PWRSTAT_HIBEN	(1UL << 0)

#define SCU_PWRSET_HIB		(1UL << 0)

#define SCU_RCU_BASE	(SCU_BASE + 0x0400)

#define SCU_RSTSTAT_HIBRS	(1UL << 9)

#define SCU_RSTCLR_HIBRS	(1UL << 9)

#define SCU_PRSTAT0_USIC0RS	(1UL << 11)

#define SCU_PRCLR0_USIC0RS	(1UL << 11)

#define SCU_PRSTAT3_EBURS	(1UL << 2)

#define SCU_PRCLR3_EBURS	(1UL << 2)

#define SCU_CCU_BASE	(SCU_BASE + 0x0600)

#define SCU_CLKSET_EBUCEN	(1UL << 3)

#define SCU_SYSCLKCR_SYSSEL_PLL	(1UL << 16)

#define SCU_OSCHPCTRL_MODE_MASK		(0x3UL << 4)
#define SCU_OSCHPCTRL_OSCVAL_MASK	(0xfUL << 16)

#define SCU_PLLSTAT_VCOLOCK	(1UL << 2)
#define SCU_PLLSTAT_PLLLV	(1UL << 7)
#define SCU_PLLSTAT_PLLHV	(1UL << 8)
#define SCU_PLLSTAT_PLLSP	(1UL << 9)

#define SCU_PLLCON0_VCOBYP	(1UL << 0)
#define SCU_PLLCON0_VCOPWD	(1UL << 1)
#define SCU_PLLCON0_FINDIS	(1UL << 4)
#define SCU_PLLCON0_OSCDISCDIS	(1UL << 6)
#define SCU_PLLCON0_PLLPWD	(1UL << 16)
#define SCU_PLLCON0_OSCRES	(1UL << 17)
#define SCU_PLLCON0_RESLD	(1UL << 18)
#define SCU_PLLCON0_AOTREN	(1UL << 19)
#define SCU_PLLCON0_FOTR	(1UL << 20)

#define SCU_PLLCON2_PINSEL	(1UL << 0)

#define USIC_CH0_BASE	0x40030000UL

#define USIC_CHx_KSCFG_MODEN	(1UL << 0)
#define USIC_CHx_KSCFG_BPMODEN	(1UL << 1)

#define USIC_CHx_DXnCR_DSEL_MASK	(0x3UL << 0)

#define USIC_CHx_FDR_STEP_MASK	(0x3ffUL << 0)
#define USIC_CHx_FDR_DM_NORMAL	(0x1UL << 14)
#define USIC_CHx_FDR_DM_FRAC	(0x2UL << 14)
#define USIC_CHx_FDR_DM_MASK	(0x3UL << 14)

#define USIC_CHx_BRG_PCTQ_MASK	(0x3UL << 8)
#define USIC_CHx_BRG_DCTQ_MASK	(0x1fUL << 10)
#define USIC_CHx_BRG_PDIV_MASK	(0x3ffUL << 16)

#define USIC_CHx_SCTR_PDL_0	(0UL << 1)
#define USIC_CHx_SCTR_PDL_1	(1UL << 1)
#define USIC_CHx_SCTR_PDL_MASK	(1UL << 1)
#define USIC_CHx_SCTR_TRM_1	(0x1UL << 8)
#define USIC_CHx_SCTR_TRM_0	(0x2UL << 8)
#define USIC_CHx_SCTR_TRM_MASK	(0x3UL << 8)
#define USIC_CHx_SCTR_FLE_MASK	(0x3fUL << 16)
#define USIC_CHx_SCTR_WLE_MASK	(0xfUL << 24)

#define USIC_CHx_TCSR_TDV	(1UL << 7)
#define USIC_CHx_TCSR_TDSSM	(1UL << 8)
#define USIC_CHx_TCSR_TDEN_MASK	(0x3UL << 10)

#define USIC_CHx_PCR_ASC_SMD		(1UL << 0)
#define USIC_CHx_PCR_ASC_STPB_1		(0UL << 1)
#define USIC_CHx_PCR_ASC_STPB_2		(1UL << 1)
#define USIC_CHx_PCR_ASC_STPB_MASK	(1UL << 1)
#define USIC_CHx_PCR_ASC_SP_MASK	(0x1fUL << 8)

#define USIC_CHx_PSR_ASC_TBIF		(1UL << 13)

#define USIC_CHx_CCR_MODE_DISABLED	(0x0UL << 0)
#define USIC_CHx_CCR_MODE_SSC		(0x1UL << 0)
#define USIC_CHx_CCR_MODE_ASC		(0x2UL << 0)
#define USIC_CHx_CCR_MODE_I2C		(0x3UL << 0)
#define USIC_CHx_CCR_MODE_I2S		(0x4UL << 0)
#define USIC_CHx_CCR_MODE_MASK		(0xfUL << 0)
#define USIC_CHx_CCR_PM_NONE		(0x0UL << 8)
#define USIC_CHx_CCR_PM_EVEN		(0x2UL << 8)
#define USIC_CHx_CCR_PM_ODD		(0x3UL << 8)
#define USIC_CHx_CCR_PM_MASK		(0x3UL << 8)

#define USIC_CHx_TRBSR_TFULL		(1UL << 12)

#define USIC_CHx_TBCTR_DPTR_MASK	(0x3fUL << 0)
#define USIC_CHx_TBCTR_LIMIT_MASK	(0x3fUL << 8)
#define USIC_CHx_TBCTR_SIZE_2		(0x1UL << 24)
#define USIC_CHx_TBCTR_SIZE_16		(0x4UL << 24)
#define USIC_CHx_TBCTR_SIZE_MASK	(0x7UL << 24)

#define USIC_CHx_RBCTR_DPTR_MASK	(0x3fUL << 0)
#define USIC_CHx_RBCTR_LIMIT_MASK	(0x3fUL << 8)
#define USIC_CHx_RBCTR_SIZE_2		(0x1UL << 24)
#define USIC_CHx_RBCTR_SIZE_MASK	(0x7UL << 24)
#define USIC_CHx_RBCTR_LOF		(1UL << 28)

#define EBU_BASE	0x58008000

#define EBU_BUSRCONx_FDBKEN		(1UL << 5)
#define EBU_BUSRCONx_BCGEN_CTRL		(1UL << 20)

#define EBU_BUSWCONx_BCGEN_CTRL		(1UL << 20)

#define EBU_ADDRSELx_REGENAB	(1UL << 0)
#define EBU_ADDRSELx_ALTENAB	(1UL << 1)

#define EBU_SDRMOD_COLDSTART	(1UL << 15)

#define EBU_SDRMREF_AUTOSELFR	(1UL << 13)
#define EBU_SDRMREF_ARFSH	(1UL << 24)

#define PORTS_IOCRn_PCx_OUT_PP_GP	0x10UL
#define PORTS_IOCRn_PCx_OUT_PP_ALT2	0x12UL
#define PORTS_IOCRn_PCx_MASK		0x1fUL

#define PORTS_PDRn_PDx_MASK	0x7UL

#define PORTS_HWSEL_HWx_SW	0x0UL
#define PORTS_HWSEL_HWx_HW0	0x1UL
#define PORTS_HWSEL_HWx_HW1	0x2UL
#define PORTS_HWSEL_HWx_MASK	0x3UL

#define CONFIG_CRYSTAL_FREQ	12000000UL
#define CONFIG_PLL_PDIV		0
#define CONFIG_PLL_NDIV		39
#define CONFIG_PLL_K1DIV	0
#define CONFIG_PLL_K2DIV	3
#define CLOCK_FSYS_FREQ		120000000UL

static void delay(uint32_t timeout)
{
	uint32_t i;

	for (i = 0; i < timeout; i++) {
		asm volatile ("nop; nop; nop; nop");
	}
}

static void clock_setup(void)
{
	volatile uint32_t *SCU_TRAPCLR   = (void *)(SCU_BASE + 0x016C);
	volatile uint32_t *SCU_PWRSTAT   = (void *)(SCU_BASE + 0x0200);
	volatile uint32_t *SCU_PWRSET    = (void *)(SCU_BASE + 0x0204);
	volatile uint32_t *SCU_RSTSTAT   = (void *)(SCU_BASE + 0x0400);
	volatile uint32_t *SCU_RSTCLR    = (void *)(SCU_BASE + 0x0408);
	volatile uint32_t *SCU_SYSCLKCR  = (void *)(SCU_BASE + 0x060C);
	volatile uint32_t *SCU_OSCHPCTRL = (void *)(SCU_BASE + 0x0704);
	volatile uint32_t *SCU_PLLSTAT   = (void *)(SCU_BASE + 0x0710);
	volatile uint32_t *SCU_PLLCON0   = (void *)(SCU_BASE + 0x0714);
	volatile uint32_t *SCU_PLLCON1   = (void *)(SCU_BASE + 0x0718);
	volatile uint32_t *SCU_PLLCON2   = (void *)(SCU_BASE + 0x071C);
	const uint32_t pllstat_osc_usable = SCU_PLLSTAT_PLLSP |
	                                    SCU_PLLSTAT_PLLHV |
	                                    SCU_PLLSTAT_PLLLV;
	uint32_t vco, k2div;

	if (!(*SCU_PWRSTAT & SCU_PWRSTAT_HIBEN)) {
		*SCU_PWRSET = SCU_PWRSET_HIB;
		while (!(*SCU_PWRSTAT & SCU_PWRSTAT_HIBEN)) {
		}
	}
	if (*SCU_RSTSTAT & SCU_RSTSTAT_HIBRS) {
		*SCU_RSTCLR = SCU_RSTCLR_HIBRS;
	}
	*SCU_PLLCON0 &= ~SCU_PLLCON0_FOTR;
	delay(100); /* 50 µs @ 50 MHz*/
	*SCU_PLLCON0 |= SCU_PLLCON0_AOTREN;

	delay(100); /* 50 µs @ 50 MHz*/

	*SCU_PLLCON0 &= ~(SCU_PLLCON0_PLLPWD | SCU_PLLCON0_VCOPWD);
	if ((*SCU_OSCHPCTRL & SCU_OSCHPCTRL_MODE_MASK) != (0U << 4)) {
		*SCU_OSCHPCTRL &= ~SCU_OSCHPCTRL_MODE_MASK |
		                  (0U << 4);
		*SCU_OSCHPCTRL |= ((CONFIG_CRYSTAL_FREQ / 2500000U) - 1) << 16;
		*SCU_PLLCON2 &= ~(SCU_PLLCON2_PINSEL);
		*SCU_PLLCON0 &= ~(SCU_PLLCON0_OSCRES);
		do {
			delay(10); // 8 µs @ 50 MHz
		} while ((*SCU_PLLSTAT & pllstat_osc_usable) != pllstat_osc_usable);
	}

	if (!(*SCU_PLLSTAT & SCU_PLLSTAT_VCOLOCK)) {
		vco = (CONFIG_CRYSTAL_FREQ / (CONFIG_PLL_PDIV + 1)) *
		      (CONFIG_PLL_NDIV + 1);
		k2div = (vco / 24000000U) - 1;
		*SCU_PLLCON0 |= SCU_PLLCON0_VCOBYP;
		*SCU_PLLCON0 |= SCU_PLLCON0_FINDIS;
		*SCU_PLLCON1 = (CONFIG_PLL_PDIV << 24) | (k2div << 16) |
		               (CONFIG_PLL_NDIV << 8) | CONFIG_PLL_K1DIV;
		*SCU_PLLCON0 |= SCU_PLLCON0_OSCDISCDIS;
		*SCU_PLLCON0 &= ~SCU_PLLCON0_FINDIS;
		*SCU_PLLCON0 |= SCU_PLLCON0_RESLD;
		do {
			delay(10); // 8 µs @ 50 MHz
		} while (!(*SCU_PLLSTAT & SCU_PLLSTAT_VCOLOCK));
		*SCU_PLLCON0 &= ~SCU_PLLCON0_VCOBYP;
	}

	*SCU_SYSCLKCR |= SCU_SYSCLKCR_SYSSEL_PLL;

	*SCU_PLLCON0 &= ~SCU_PLLCON0_OSCDISCDIS;

	delay(100); /* 50 µs @ 50 MHz*/
	k2div = (vco / 60000000UL) - 1;
	*SCU_PLLCON1 = (CONFIG_PLL_PDIV << 24) | (k2div << 16) |
	               (CONFIG_PLL_NDIV << 8) | CONFIG_PLL_K1DIV;

	delay(100); /* 50 µs @ 50 MHz*/
	k2div = (vco / 90000000UL) - 1;
	*SCU_PLLCON1 = (CONFIG_PLL_PDIV << 24) | (k2div << 16) |
	               (CONFIG_PLL_NDIV << 8) | CONFIG_PLL_K1DIV;

	delay(150); /* 50 µs @ 90 MHz*/
	*SCU_PLLCON1 = (CONFIG_PLL_PDIV << 24) | (CONFIG_PLL_K2DIV << 16) |
	               (CONFIG_PLL_NDIV << 8) | CONFIG_PLL_K1DIV;

	*SCU_TRAPCLR = SCU_TRAPCLR_SVCOLCKT | SCU_TRAPCLR_SOSCWDGT;
}

static void ports_set_iocr(int port, int pin, uint8_t value)
{
	volatile uint8_t *PORTS_Pn_IOCRx = (void *)(0x48028010 + port * 0x100 + pin);
	uint32_t temp;

	temp = *PORTS_Pn_IOCRx;
	temp &= ~(PORTS_IOCRn_PCx_MASK << 3);
	temp |= (value & PORTS_IOCRn_PCx_MASK) << 3;
	*PORTS_Pn_IOCRx = temp;
}

static void ports_set_pdr(int port, int pin, uint8_t value)
{
	volatile uint32_t *PORTS_Pn_PDR0  = (void *)(0x48028040 + port * 0x100);
	volatile uint32_t *PORTS_Pn_PDR1  = (void *)(0x48028044 + port * 0x100);
	volatile uint32_t *PORTS_Pn_PDR;
	int shift;
	uint32_t temp;

	if (pin >= 8) {
		PORTS_Pn_PDR = PORTS_Pn_PDR1;
		shift = (pin - 8) * 4;
	} else {
		PORTS_Pn_PDR = PORTS_Pn_PDR0;
		shift = pin * 4;
	}
	temp = *PORTS_Pn_PDR;
	temp &= ~(PORTS_PDRn_PDx_MASK << shift);
	temp |= (value & PORTS_PDRn_PDx_MASK) << shift;
	*PORTS_Pn_PDR = temp;
}

static void ports_set_hwsel(int port, int pin, uint8_t value)
{
	volatile uint32_t *PORTS_Pn_HWSEL = (void *)(0x48028000 + port * 0x100 + 0x0074);
	int shift = pin * 2;
	uint32_t temp;

	temp = *PORTS_Pn_HWSEL;
	temp &= ~(PORTS_HWSEL_HWx_MASK << shift);
	temp |= (value & PORTS_HWSEL_HWx_MASK) << shift;
	*PORTS_Pn_HWSEL = temp;
}

static void usic_setup(void)
{
	volatile uint32_t *SCU_PRSTAT0 = (void *)(SCU_BASE + 0x040C);
	volatile uint32_t *SCU_PRCLR0  = (void *)(SCU_BASE + 0x0414);
	volatile uint32_t *USIC_CH0_KSCFG = (void *)(USIC_CH0_BASE + 0x0C);
	volatile uint32_t *USIC_CH0_FDR   = (void *)(USIC_CH0_BASE + 0x10);
	volatile uint32_t *USIC_CH0_BRG   = (void *)(USIC_CH0_BASE + 0x14);
	volatile uint32_t *USIC_CH0_DX0CR = (void *)(USIC_CH0_BASE + 0x1C);
	volatile uint32_t *USIC_CH0_SCTR  = (void *)(USIC_CH0_BASE + 0x34);
	volatile uint32_t *USIC_CH0_TCSR  = (void *)(USIC_CH0_BASE + 0x38);
	volatile uint32_t *USIC_CH0_PCR   = (void *)(USIC_CH0_BASE + 0x3C);
	volatile uint32_t *USIC_CH0_CCR   = (void *)(USIC_CH0_BASE + 0x40);
	volatile uint32_t *USIC_CH0_PSR   = (void *)(USIC_CH0_BASE + 0x48);
	volatile uint32_t *USIC_CH0_TBCTR = (void *)(USIC_CH0_BASE + 0x108);
	volatile uint32_t *USIC_CH0_RBCTR = (void *)(USIC_CH0_BASE + 0x10C);
	const unsigned int tx_port = 1;
	const unsigned int tx_pin = 5;
	const unsigned int data_bits = 8;
	uint32_t val;

	if (*SCU_PRSTAT0 & SCU_PRSTAT0_USIC0RS) {
		*SCU_PRCLR0 = SCU_PRCLR0_USIC0RS;
		while (*SCU_PRSTAT0 & SCU_PRSTAT0_USIC0RS) {}
	}

	val = *USIC_CH0_CCR;
	val &= ~USIC_CHx_CCR_MODE_MASK;
	val |= USIC_CHx_CCR_MODE_DISABLED;
	*USIC_CH0_CCR = val;

	*USIC_CH0_KSCFG |= USIC_CHx_KSCFG_BPMODEN | USIC_CHx_KSCFG_MODEN;
	val = *USIC_CH0_FDR;
	val &= ~(USIC_CHx_FDR_DM_MASK | USIC_CHx_FDR_STEP_MASK);
	val |= USIC_CHx_FDR_DM_FRAC | (834 << 0);
	*USIC_CH0_FDR = val;
	val = *USIC_CH0_BRG;
	val &= ~(USIC_CHx_BRG_PDIV_MASK | USIC_CHx_BRG_DCTQ_MASK | USIC_CHx_BRG_PCTQ_MASK);
	val |= (508 << 16) | (9 << 10) | (0 << 8);
	*USIC_CH0_BRG = val;
	val = *USIC_CH0_SCTR;
	val &= ~(USIC_CHx_SCTR_WLE_MASK | USIC_CHx_SCTR_FLE_MASK | USIC_CHx_SCTR_TRM_MASK | USIC_CHx_SCTR_PDL_MASK);
	val |= ((data_bits - 1) << 24) | ((data_bits - 1) << 16) |
	       USIC_CHx_SCTR_TRM_1 | USIC_CHx_SCTR_PDL_1;
	*USIC_CH0_SCTR = val;
	val = *USIC_CH0_TCSR;
	val &= ~(USIC_CHx_TCSR_TDEN_MASK);
	val |= (0x1UL << 10) | USIC_CHx_TCSR_TDSSM;
	*USIC_CH0_TCSR = val;
	val = *USIC_CH0_PCR;
	val &= ~(USIC_CHx_PCR_ASC_SP_MASK | USIC_CHx_PCR_ASC_STPB_MASK);
	val |= (6 << 8) | USIC_CHx_PCR_ASC_STPB_1 | USIC_CHx_PCR_ASC_SMD;
	*USIC_CH0_PCR = val;
	//if (0) {
	*USIC_CH0_PSR |= USIC_CHx_PSR_ASC_TBIF;
	//} else {
	val = *USIC_CH0_TBCTR;
	val &= ~(USIC_CHx_TBCTR_LIMIT_MASK);
	val |= (1 << 8);
	*USIC_CH0_TBCTR = val;
	//}
	val = *USIC_CH0_RBCTR;
	val &= ~(USIC_CHx_RBCTR_LIMIT_MASK);
	val |= (1 << 8) | USIC_CHx_RBCTR_LOF;
	*USIC_CH0_RBCTR = val;
	val = *USIC_CH0_DX0CR;
	val &= ~USIC_CHx_DXnCR_DSEL_MASK;
	val |= (0x1 << 0);
	*USIC_CH0_DX0CR = val;
	val = *USIC_CH0_CCR;
	val &= ~(USIC_CHx_CCR_PM_MASK | USIC_CHx_CCR_MODE_MASK);
	val |= USIC_CHx_CCR_PM_NONE | USIC_CHx_CCR_MODE_ASC;
	*USIC_CH0_CCR = val;

	val = *USIC_CH0_TBCTR;
	val &= ~(USIC_CHx_TBCTR_SIZE_MASK | USIC_CHx_TBCTR_DPTR_MASK);
	val |= USIC_CHx_TBCTR_SIZE_2 | (2 << 0);
	*USIC_CH0_TBCTR = val;
	val = *USIC_CH0_RBCTR;
	val &= ~(USIC_CHx_RBCTR_SIZE_MASK | USIC_CHx_RBCTR_DPTR_MASK);
	val |= USIC_CHx_RBCTR_SIZE_2 | (0 << 0);
	*USIC_CH0_RBCTR = val;

	ports_set_iocr(tx_port, tx_pin, PORTS_IOCRn_PCx_OUT_PP_ALT2); // U0C0.DOUT0
	ports_set_pdr(tx_port, tx_pin, 0); // strong driver soft edge
	//ports_set_hwsel(tx_port, tx_pin, PORTS_HWSEL_HWx_HW0);
	ports_set_hwsel(tx_port, tx_pin, PORTS_HWSEL_HWx_SW);
}

static void usic_putch(char ch)
{
	volatile uint32_t *USIC_CH0_TCSR  = (void *)(USIC_CH0_BASE + 0x38);
	volatile uint32_t *USIC_CH0_TBUF0 = (void *)(USIC_CH0_BASE + 0x080 + 0 * 4);
	volatile uint32_t *USIC_CH0_TRBSR = (void *)(USIC_CH0_BASE + 0x114);
	volatile uint32_t *USIC_CH0_IN0   = (void *)(USIC_CH0_BASE + 0x180 + 0 * 4);

	if (1) {
		while (*USIC_CH0_TRBSR & USIC_CHx_TRBSR_TFULL) {
		}

		*USIC_CH0_IN0 = (uint8_t)ch;
	} else {
		while (*USIC_CH0_TCSR & USIC_CHx_TCSR_TDV) {
		}

		*USIC_CH0_TBUF0 = (uint8_t)ch;
	}
}

#ifdef SDRAM_BOARD
static void ebu_setup(void)
{
	volatile uint32_t *SCU_PRSTAT3  = (void *)(SCU_BASE + 0x0430);
	volatile uint32_t *SCU_PRCLR3   = (void *)(SCU_BASE + 0x0438);
	//volatile uint32_t *SCU_CLKSTAT  = (void *)(SCU_BASE + 0x0600);
	volatile uint32_t *SCU_CLKSET   = (void *)(SCU_BASE + 0x0604);
	volatile uint32_t *SCU_EBUCLKCR = (void *)(SCU_BASE + 0x061C);
	volatile uint32_t *EBU_CLC      = (void *)(EBU_BASE + 0x000);
	volatile uint32_t *EBU_MODCON   = (void *)(EBU_BASE + 0x004);
	volatile uint32_t *EBU_USERCON  = (void *)(EBU_BASE + 0x00C);
	volatile uint32_t *EBU_ADDRSEL0 = (void *)(EBU_BASE + 0x018 + 0 * 4);
	volatile uint32_t *EBU_BUSRCON0 = (void *)(EBU_BASE + 0x028 + 0 * 0x10);
	volatile uint32_t *EBU_BUSRAP0  = (void *)(EBU_BASE + 0x02C + 0 * 0x10);
	volatile uint32_t *EBU_BUSWCON0 = (void *)(EBU_BASE + 0x030 + 0 * 0x10);
	volatile uint32_t *EBU_BUSWAP0  = (void *)(EBU_BASE + 0x034 + 0 * 0x10);
	volatile uint32_t *EBU_SDRMCON  = (void *)(EBU_BASE + 0x068);
	volatile uint32_t *EBU_SDRMOD   = (void *)(EBU_BASE + 0x06C);
	volatile uint32_t *EBU_SDRMREF  = (void *)(EBU_BASE + 0x070);
	int i;

	*SCU_EBUCLKCR = (1 << 0);
	*SCU_CLKSET |= SCU_CLKSET_EBUCEN;

	if (*SCU_PRSTAT3 & SCU_PRSTAT3_EBURS) {
		*SCU_PRCLR3 = SCU_PRCLR3_EBURS;
		while (*SCU_PRSTAT3 & SCU_PRSTAT3_EBURS) {}
	}

	*EBU_CLC = 0;
	*EBU_MODCON = 0x0000FFE0;
	*EBU_USERCON = (0x1ff << 16);

	for (i = 2; i <= 5; i++) {
		ports_set_hwsel(0, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(0, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(0, i, 1);
	}
	for (i = 7; i <= 8; i++) {
		ports_set_hwsel(0, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(0, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(0, i, 1);
	}
	for (i = 2; i <= 3; i++) {
		ports_set_hwsel(1, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(1, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(1, i, 1);
	}
	for (i = 6; i <= 9; i++) {
		ports_set_hwsel(1, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(1, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(1, i, 1);
	}
	for (i = 12; i <= 15; i++) {
		ports_set_hwsel(1, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(1, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(1, i, 1);
	}
	for (i = 0; i <= 11; i++) {
		ports_set_hwsel(2, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(2, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(2, i, 1);
	}
	for (i = 14; i <= 15; i++) {
		ports_set_hwsel(2, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(2, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(2, i, 1);
	}
	for (i = 1; i <= 1; i++) {
		ports_set_hwsel(3, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(3, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(3, i, 1);
	}
	for (i = 5; i <= 6; i++) {
		ports_set_hwsel(3, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(3, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(3, i, 1);
	}
	for (i = 0; i <= 1; i++) {
		ports_set_hwsel(4, i, PORTS_HWSEL_HWx_HW1);
		ports_set_iocr(4, i, PORTS_IOCRn_PCx_OUT_PP_GP);
		ports_set_pdr(4, i, 1);
	}

	ports_set_hwsel(3, 2, PORTS_HWSEL_HWx_HW1);
	ports_set_pdr(3, 2, 1);

	ports_set_hwsel(6, 4, PORTS_HWSEL_HWx_HW0);
	ports_set_pdr(6, 4, 1);
	for (i = 3; i <= 5; i++) {
		ports_set_hwsel(5, i, PORTS_HWSEL_HWx_HW0);
		ports_set_pdr(5, i, 1);
	}

	*EBU_SDRMREF |= (0xff << 16);
	*EBU_BUSRCON0 = (8U << 28) | (1 << 22) | EBU_BUSRCONx_BCGEN_CTRL | (4 << 0);
	*EBU_BUSWCON0 = (8U << 28) | (1 << 22) | EBU_BUSWCONx_BCGEN_CTRL | (4 << 0);
	*EBU_BUSRCON0 |= EBU_BUSRCONx_FDBKEN;
	*EBU_BUSRAP0 = 0xFFF0A4FF;
	*EBU_BUSWAP0 = 0xFFF0A4FF;
	*EBU_ADDRSEL0 |= EBU_ADDRSELx_ALTENAB | EBU_ADDRSELx_REGENAB;
	*EBU_SDRMCON = (0 << 31) | (2 << 22) | (1 << 19) | (5 << 16) | (1 << 14) | (1 << 12) | (1 << 10) | (0 << 8) | (10 << 4) | (3 << 0);
	*EBU_SDRMOD = EBU_SDRMOD_COLDSTART | (2 << 4) | (0 << 0);
	*EBU_SDRMREF = (7 << 25) | EBU_SDRMREF_ARFSH | (0xff << 16) | EBU_SDRMREF_AUTOSELFR | (1 << 6) | (63 << 0);
}
#endif

int main(void)
{
#ifdef SDRAM_BOARD
	const int led1_port = 5, led1_pin = 2;
	const int led2_port = 1, led2_pin = 1;
	volatile uint32_t *PORTS_P1_OMR   = (void *)(0x48028004 + led2_port * 0x100);
	volatile uint32_t *PORTS_P5_OMR   = (void *)(0x48028004 + led1_port * 0x100);
	volatile uint32_t *sdram32 = (void *)(0x60000000);
	//volatile uint16_t *sdram16 = (void *)(0x60000000);
	volatile uint8_t *sdram8  = (void *)(0x60000000);
#else
	const int led_port = 3, led_pin = 9;
	volatile uint32_t *PORTS_P3_OMR   = (void *)(0x48028004 + led_port * 0x100);
#endif
	int i;

	clock_setup();
	usic_setup();

#ifdef SDRAM_BOARD
	ports_set_iocr(led1_port, led1_pin, PORTS_IOCRn_PCx_OUT_PP_GP);
	ports_set_pdr(led1_port, led1_pin, 0);
	ports_set_hwsel(led1_port, led1_pin, PORTS_HWSEL_HWx_SW);

	ports_set_iocr(led2_port, led2_pin, PORTS_IOCRn_PCx_OUT_PP_GP);
	ports_set_pdr(led2_port, led2_pin, 0);
	ports_set_hwsel(led2_port, led2_pin, PORTS_HWSEL_HWx_SW);
#else
	// P3.9 -> GPO
	ports_set_iocr(led_port, led_pin, PORTS_IOCRn_PCx_OUT_PP_GP);
	// P3.9 -> strong
	ports_set_pdr(led_port, led_pin, 0);
	ports_set_hwsel(led_port, led_pin, PORTS_HWSEL_HWx_SW);
#endif

	for (i = 0; i < 1; i++) {
		usic_putch('x');
	}

#ifdef SDRAM_BOARD
	ebu_setup();
	//sdram16[0] = 0xdead;
	//sdram16[1] = 0xbeef;
	*sdram32 = 0xdeadbeef;
	delay(10000);
	for (i = 0; i < 4; i++) {
		uint8_t val = sdram8[i];
		usic_putch(((val >> 4) > 9) ? 'A' + (val >> 4) - 0xA : '0' + (val >> 4));
		usic_putch(((val & 0xf) > 9) ? 'A' + (val & 0xf) - 0xA : '0' + (val & 0xf));
	}
#endif

	while (1) {
#ifdef SDRAM_BOARD
		*PORTS_P1_OMR = (1 << (16 + led2_pin)) | (1 << led2_pin);
		*PORTS_P5_OMR = (1 << (16 + led1_pin)) | (1 << led1_pin);
#else
		*PORTS_P3_OMR = (1 << (16 + led_pin)) | (1 << led_pin);
#endif
		delay(1000000);
	}

	return 0;
}

static void noop(void)
{
	usic_putch('E');
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
