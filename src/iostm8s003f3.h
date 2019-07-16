#ifndef IOSTM8S003K3_H
#define IOSTM8S003K3_H


//Generated from IAR's iostm8s003k3.h


typedef struct
{
  unsigned char ODR0        : 1;
  unsigned char ODR1        : 1;
  unsigned char ODR2        : 1;
  unsigned char ODR3        : 1;
  unsigned char ODR4        : 1;
  unsigned char ODR5        : 1;
  unsigned char ODR6        : 1;
  unsigned char ODR7        : 1;
} __BITS_PA_ODR;
volatile __BITS_PA_ODR  PA_ODR_bits					@0x5000;
volatile char PA_ODR					@0x5000;

typedef struct
{
  unsigned char IDR0        : 1;
  unsigned char IDR1        : 1;
  unsigned char IDR2        : 1;
  unsigned char IDR3        : 1;
  unsigned char IDR4        : 1;
  unsigned char IDR5        : 1;
  unsigned char IDR6        : 1;
  unsigned char IDR7        : 1;
} __BITS_PA_IDR;
volatile __BITS_PA_IDR  PA_IDR_bits					@0x5001;
volatile char PA_IDR					@0x5001;

typedef struct
{
  unsigned char DDR0        : 1;
  unsigned char DDR1        : 1;
  unsigned char DDR2        : 1;
  unsigned char DDR3        : 1;
  unsigned char DDR4        : 1;
  unsigned char DDR5        : 1;
  unsigned char DDR6        : 1;
  unsigned char DDR7        : 1;
} __BITS_PA_DDR;
volatile __BITS_PA_DDR  PA_DDR_bits					@0x5002;
volatile char PA_DDR					@0x5002;

typedef struct
{
  unsigned char C10         : 1;
  unsigned char C11         : 1;
  unsigned char C12         : 1;
  unsigned char C13         : 1;
  unsigned char C14         : 1;
  unsigned char C15         : 1;
  unsigned char C16         : 1;
  unsigned char C17         : 1;
} __BITS_PA_CR1;
volatile __BITS_PA_CR1  PA_CR1_bits					@0x5003;
volatile char PA_CR1					@0x5003;

typedef struct
{
  unsigned char C20         : 1;
  unsigned char C21         : 1;
  unsigned char C22         : 1;
  unsigned char C23         : 1;
  unsigned char C24         : 1;
  unsigned char C25         : 1;
  unsigned char C26         : 1;
  unsigned char C27         : 1;
} __BITS_PA_CR2;
volatile __BITS_PA_CR2  PA_CR2_bits					@0x5004;
volatile char PA_CR2					@0x5004;

typedef struct
{
  unsigned char ODR0        : 1;
  unsigned char ODR1        : 1;
  unsigned char ODR2        : 1;
  unsigned char ODR3        : 1;
  unsigned char ODR4        : 1;
  unsigned char ODR5        : 1;
  unsigned char ODR6        : 1;
  unsigned char ODR7        : 1;
} __BITS_PB_ODR;
volatile __BITS_PB_ODR  PB_ODR_bits					@0x5005;
volatile char PB_ODR					@0x5005;

typedef struct
{
  unsigned char IDR0        : 1;
  unsigned char IDR1        : 1;
  unsigned char IDR2        : 1;
  unsigned char IDR3        : 1;
  unsigned char IDR4        : 1;
  unsigned char IDR5        : 1;
  unsigned char IDR6        : 1;
  unsigned char IDR7        : 1;
} __BITS_PB_IDR;
volatile __BITS_PB_IDR  PB_IDR_bits					@0x5006;
volatile char PB_IDR					@0x5006;

typedef struct
{
  unsigned char DDR0        : 1;
  unsigned char DDR1        : 1;
  unsigned char DDR2        : 1;
  unsigned char DDR3        : 1;
  unsigned char DDR4        : 1;
  unsigned char DDR5        : 1;
  unsigned char DDR6        : 1;
  unsigned char DDR7        : 1;
} __BITS_PB_DDR;
volatile __BITS_PB_DDR  PB_DDR_bits					@0x5007;
volatile char PB_DDR					@0x5007;

typedef struct
{
  unsigned char C10         : 1;
  unsigned char C11         : 1;
  unsigned char C12         : 1;
  unsigned char C13         : 1;
  unsigned char C14         : 1;
  unsigned char C15         : 1;
  unsigned char C16         : 1;
  unsigned char C17         : 1;
} __BITS_PB_CR1;
volatile __BITS_PB_CR1  PB_CR1_bits					@0x5008;
volatile char PB_CR1					@0x5008;

typedef struct
{
  unsigned char C20         : 1;
  unsigned char C21         : 1;
  unsigned char C22         : 1;
  unsigned char C23         : 1;
  unsigned char C24         : 1;
  unsigned char C25         : 1;
  unsigned char C26         : 1;
  unsigned char C27         : 1;
} __BITS_PB_CR2;
volatile __BITS_PB_CR2  PB_CR2_bits					@0x5009;
volatile char PB_CR2					@0x5009;

typedef struct
{
  unsigned char ODR0        : 1;
  unsigned char ODR1        : 1;
  unsigned char ODR2        : 1;
  unsigned char ODR3        : 1;
  unsigned char ODR4        : 1;
  unsigned char ODR5        : 1;
  unsigned char ODR6        : 1;
  unsigned char ODR7        : 1;
} __BITS_PC_ODR;
volatile __BITS_PC_ODR  PC_ODR_bits					@0x500A;
volatile char PC_ODR					@0x500A;

typedef struct
{
  unsigned char IDR0        : 1;
  unsigned char IDR1        : 1;
  unsigned char IDR2        : 1;
  unsigned char IDR3        : 1;
  unsigned char IDR4        : 1;
  unsigned char IDR5        : 1;
  unsigned char IDR6        : 1;
  unsigned char IDR7        : 1;
} __BITS_PC_IDR;
volatile __BITS_PC_IDR  PC_IDR_bits					@0x500B;
volatile char PC_IDR					@0x500B;

typedef struct
{
  unsigned char DDR0        : 1;
  unsigned char DDR1        : 1;
  unsigned char DDR2        : 1;
  unsigned char DDR3        : 1;
  unsigned char DDR4        : 1;
  unsigned char DDR5        : 1;
  unsigned char DDR6        : 1;
  unsigned char DDR7        : 1;
} __BITS_PC_DDR;
volatile __BITS_PC_DDR  PC_DDR_bits					@0x500C;
volatile char PC_DDR					@0x500C;

typedef struct
{
  unsigned char C10         : 1;
  unsigned char C11         : 1;
  unsigned char C12         : 1;
  unsigned char C13         : 1;
  unsigned char C14         : 1;
  unsigned char C15         : 1;
  unsigned char C16         : 1;
  unsigned char C17         : 1;
} __BITS_PC_CR1;
volatile __BITS_PC_CR1  PC_CR1_bits					@0x500D;
volatile char PC_CR1					@0x500D;

typedef struct
{
  unsigned char C20         : 1;
  unsigned char C21         : 1;
  unsigned char C22         : 1;
  unsigned char C23         : 1;
  unsigned char C24         : 1;
  unsigned char C25         : 1;
  unsigned char C26         : 1;
  unsigned char C27         : 1;
} __BITS_PC_CR2;
volatile __BITS_PC_CR2  PC_CR2_bits					@0x500E;
volatile char PC_CR2					@0x500E;

typedef struct
{
  unsigned char ODR0        : 1;
  unsigned char ODR1        : 1;
  unsigned char ODR2        : 1;
  unsigned char ODR3        : 1;
  unsigned char ODR4        : 1;
  unsigned char ODR5        : 1;
  unsigned char ODR6        : 1;
  unsigned char ODR7        : 1;
} __BITS_PD_ODR;
volatile __BITS_PD_ODR  PD_ODR_bits					@0x500F;
volatile char PD_ODR					@0x500F;

typedef struct
{
  unsigned char IDR0        : 1;
  unsigned char IDR1        : 1;
  unsigned char IDR2        : 1;
  unsigned char IDR3        : 1;
  unsigned char IDR4        : 1;
  unsigned char IDR5        : 1;
  unsigned char IDR6        : 1;
  unsigned char IDR7        : 1;
} __BITS_PD_IDR;
volatile __BITS_PD_IDR  PD_IDR_bits					@0x5010;
volatile char PD_IDR					@0x5010;

typedef struct
{
  unsigned char DDR0        : 1;
  unsigned char DDR1        : 1;
  unsigned char DDR2        : 1;
  unsigned char DDR3        : 1;
  unsigned char DDR4        : 1;
  unsigned char DDR5        : 1;
  unsigned char DDR6        : 1;
  unsigned char DDR7        : 1;
} __BITS_PD_DDR;
volatile __BITS_PD_DDR  PD_DDR_bits					@0x5011;
volatile char PD_DDR					@0x5011;

typedef struct
{
  unsigned char C10         : 1;
  unsigned char C11         : 1;
  unsigned char C12         : 1;
  unsigned char C13         : 1;
  unsigned char C14         : 1;
  unsigned char C15         : 1;
  unsigned char C16         : 1;
  unsigned char C17         : 1;
} __BITS_PD_CR1;
volatile __BITS_PD_CR1  PD_CR1_bits					@0x5012;
volatile char PD_CR1					@0x5012;

typedef struct
{
  unsigned char C20         : 1;
  unsigned char C21         : 1;
  unsigned char C22         : 1;
  unsigned char C23         : 1;
  unsigned char C24         : 1;
  unsigned char C25         : 1;
  unsigned char C26         : 1;
  unsigned char C27         : 1;
} __BITS_PD_CR2;
volatile __BITS_PD_CR2  PD_CR2_bits					@0x5013;
volatile char PD_CR2					@0x5013;

typedef struct
{
  unsigned char ODR0        : 1;
  unsigned char ODR1        : 1;
  unsigned char ODR2        : 1;
  unsigned char ODR3        : 1;
  unsigned char ODR4        : 1;
  unsigned char ODR5        : 1;
  unsigned char ODR6        : 1;
  unsigned char ODR7        : 1;
} __BITS_PE_ODR;
volatile __BITS_PE_ODR  PE_ODR_bits					@0x5014;
volatile char PE_ODR					@0x5014;

typedef struct
{
  unsigned char IDR0        : 1;
  unsigned char IDR1        : 1;
  unsigned char IDR2        : 1;
  unsigned char IDR3        : 1;
  unsigned char IDR4        : 1;
  unsigned char IDR5        : 1;
  unsigned char IDR6        : 1;
  unsigned char IDR7        : 1;
} __BITS_PE_IDR;
volatile __BITS_PE_IDR  PE_IDR_bits					@0x5015;
volatile char PE_IDR					@0x5015;

typedef struct
{
  unsigned char DDR0        : 1;
  unsigned char DDR1        : 1;
  unsigned char DDR2        : 1;
  unsigned char DDR3        : 1;
  unsigned char DDR4        : 1;
  unsigned char DDR5        : 1;
  unsigned char DDR6        : 1;
  unsigned char DDR7        : 1;
} __BITS_PE_DDR;
volatile __BITS_PE_DDR  PE_DDR_bits					@0x5016;
volatile char PE_DDR					@0x5016;

typedef struct
{
  unsigned char C10         : 1;
  unsigned char C11         : 1;
  unsigned char C12         : 1;
  unsigned char C13         : 1;
  unsigned char C14         : 1;
  unsigned char C15         : 1;
  unsigned char C16         : 1;
  unsigned char C17         : 1;
} __BITS_PE_CR1;
volatile __BITS_PE_CR1  PE_CR1_bits					@0x5017;
volatile char PE_CR1					@0x5017;

typedef struct
{
  unsigned char C20         : 1;
  unsigned char C21         : 1;
  unsigned char C22         : 1;
  unsigned char C23         : 1;
  unsigned char C24         : 1;
  unsigned char C25         : 1;
  unsigned char C26         : 1;
  unsigned char C27         : 1;
} __BITS_PE_CR2;
volatile __BITS_PE_CR2  PE_CR2_bits					@0x5018;
volatile char PE_CR2					@0x5018;

typedef struct
{
  unsigned char ODR0        : 1;
  unsigned char ODR1        : 1;
  unsigned char ODR2        : 1;
  unsigned char ODR3        : 1;
  unsigned char ODR4        : 1;
  unsigned char ODR5        : 1;
  unsigned char ODR6        : 1;
  unsigned char ODR7        : 1;
} __BITS_PF_ODR;
volatile __BITS_PF_ODR  PF_ODR_bits					@0x5019;
volatile char PF_ODR					@0x5019;

typedef struct
{
  unsigned char IDR0        : 1;
  unsigned char IDR1        : 1;
  unsigned char IDR2        : 1;
  unsigned char IDR3        : 1;
  unsigned char IDR4        : 1;
  unsigned char IDR5        : 1;
  unsigned char IDR6        : 1;
  unsigned char IDR7        : 1;
} __BITS_PF_IDR;
volatile __BITS_PF_IDR  PF_IDR_bits					@0x501A;
volatile char PF_IDR					@0x501A;

typedef struct
{
  unsigned char DDR0        : 1;
  unsigned char DDR1        : 1;
  unsigned char DDR2        : 1;
  unsigned char DDR3        : 1;
  unsigned char DDR4        : 1;
  unsigned char DDR5        : 1;
  unsigned char DDR6        : 1;
  unsigned char DDR7        : 1;
} __BITS_PF_DDR;
volatile __BITS_PF_DDR  PF_DDR_bits					@0x501B;
volatile char PF_DDR					@0x501B;

typedef struct
{
  unsigned char C10         : 1;
  unsigned char C11         : 1;
  unsigned char C12         : 1;
  unsigned char C13         : 1;
  unsigned char C14         : 1;
  unsigned char C15         : 1;
  unsigned char C16         : 1;
  unsigned char C17         : 1;
} __BITS_PF_CR1;
volatile __BITS_PF_CR1  PF_CR1_bits					@0x501C;
volatile char PF_CR1					@0x501C;

typedef struct
{
  unsigned char C20         : 1;
  unsigned char C21         : 1;
  unsigned char C22         : 1;
  unsigned char C23         : 1;
  unsigned char C24         : 1;
  unsigned char C25         : 1;
  unsigned char C26         : 1;
  unsigned char C27         : 1;
} __BITS_PF_CR2;
volatile __BITS_PF_CR2  PF_CR2_bits					@0x501D;
volatile char PF_CR2					@0x501D;

typedef struct
{
  unsigned char FIX         : 1;
  unsigned char IE          : 1;
  unsigned char AHALT       : 1;
  unsigned char HALT        : 1;
} __BITS_FLASH_CR1;
volatile __BITS_FLASH_CR1  FLASH_CR1_bits					@0x505A;
volatile char FLASH_CR1					@0x505A;

typedef struct
{
  unsigned char PRG         : 1;
  unsigned char             : 3;
  unsigned char FPRG        : 1;
  unsigned char ERASE       : 1;
  unsigned char WPRG        : 1;
//  unsigned char OPT         : 1;
} __BITS_FLASH_CR2;
volatile __BITS_FLASH_CR2  FLASH_CR2_bits					@0x505B;
volatile char FLASH_CR2					@0x505B;

typedef struct
{
  unsigned char NPRG        : 1;
  unsigned char             : 3;
  unsigned char NFPRG       : 1;
  unsigned char NERASE      : 1;
  unsigned char NWPRG       : 1;
  unsigned char NOPT        : 1;
} __BITS_FLASH_NCR2;
volatile __BITS_FLASH_NCR2  FLASH_NCR2_bits					@0x505C;
volatile char FLASH_NCR2					@0x505C;

typedef struct
{
  unsigned char WPB0        : 1;
  unsigned char WPB1        : 1;
  unsigned char WPB2        : 1;
  unsigned char WPB3        : 1;
  unsigned char WPB4        : 1;
  unsigned char WPB5        : 1;
} __BITS_FLASH_FPR;
volatile __BITS_FLASH_FPR  FLASH_FPR_bits					@0x505D;
volatile char FLASH_FPR					@0x505D;

typedef struct
{
  unsigned char NWPB0       : 1;
  unsigned char NWPB1       : 1;
  unsigned char NWPB2       : 1;
  unsigned char NWPB3       : 1;
  unsigned char NWPB4       : 1;
  unsigned char NWPB5       : 1;
} __BITS_FLASH_NFPR;
volatile __BITS_FLASH_NFPR  FLASH_NFPR_bits					@0x505E;
volatile char FLASH_NFPR					@0x505E;

typedef struct
{
  unsigned char WR_PG_DIS   : 1;
  unsigned char PUL         : 1;
  unsigned char EOP         : 1;
  unsigned char DUL         : 1;
  unsigned char             : 2;
  unsigned char HVOFF       : 1;
} __BITS_FLASH_IAPSR;
volatile __BITS_FLASH_IAPSR  FLASH_IAPSR_bits					@0x505F;
volatile char FLASH_IAPSR					@0x505F;

volatile char  FLASH_PUKR					@0x5062;
volatile char  FLASH_DUKR					@0x5064;
typedef struct
{
  unsigned char PAIS        : 2;
  unsigned char PBIS        : 2;
  unsigned char PCIS        : 2;
  unsigned char PDIS        : 2;
} __BITS_EXTI_CR1;
volatile __BITS_EXTI_CR1  EXTI_CR1_bits					@0x50A0;
volatile char EXTI_CR1					@0x50A0;

typedef struct
{
  unsigned char PEIS        : 2;
  unsigned char TLIS        : 1;
} __BITS_EXTI_CR2;
volatile __BITS_EXTI_CR2  EXTI_CR2_bits					@0x50A1;
volatile char EXTI_CR2					@0x50A1;

typedef struct
{
  unsigned char WWDGF       : 1;
  unsigned char IWDGF       : 1;
  unsigned char ILLOPF      : 1;
  unsigned char SWIMF       : 1;
  unsigned char EMCF        : 1;
} __BITS_RST_SR;
volatile __BITS_RST_SR  RST_SR_bits					@0x50B3;
volatile char RST_SR					@0x50B3;

typedef struct
{
  unsigned char VECT0SPR    : 2;
  unsigned char VECT1SPR    : 2;
  unsigned char VECT2SPR    : 2;
  unsigned char VECT3SPR    : 2;
} __BITS_ITC_SPR1;
volatile __BITS_ITC_SPR1  ITC_SPR1_bits					@0x7F70;
volatile char ITC_SPR1					@0x7F70;

typedef struct
{
  unsigned char VECT4SPR    : 2;
  unsigned char VECT5SPR    : 2;
  unsigned char VECT6SPR    : 2;
  unsigned char VECT7SPR    : 2;
} __BITS_ITC_SPR2;
volatile __BITS_ITC_SPR2  ITC_SPR2_bits					@0x7F71;
volatile char ITC_SPR2					@0x7F71;

typedef struct
{
  unsigned char VECT8SPR    : 2;
  unsigned char VECT9SPR    : 2;
  unsigned char VECT10SPR   : 2;
  unsigned char VECT11SPR   : 2;
} __BITS_ITC_SPR3;
volatile __BITS_ITC_SPR3  ITC_SPR3_bits					@0x7F72;
volatile char ITC_SPR3					@0x7F72;

typedef struct
{
  unsigned char VECT12SPR   : 2;
  unsigned char VECT13SPR   : 2;
  unsigned char VECT14SPR   : 2;
  unsigned char VECT15SPR   : 2;
} __BITS_ITC_SPR4;
volatile __BITS_ITC_SPR4  ITC_SPR4_bits					@0x7F73;
volatile char ITC_SPR4					@0x7F73;

typedef struct
{
  unsigned char VECT16SPR   : 2;
  unsigned char VECT17SPR   : 2;
  unsigned char VECT18SPR   : 2;
  unsigned char VECT19SPR   : 2;
} __BITS_ITC_SPR5;
volatile __BITS_ITC_SPR5  ITC_SPR5_bits					@0x7F74;
volatile char ITC_SPR5					@0x7F74;

typedef struct
{
  unsigned char VECT20SPR   : 2;
  unsigned char VECT21SPR   : 2;
  unsigned char VECT22SPR   : 2;
  unsigned char VECT23SPR   : 2;
} __BITS_ITC_SPR6;
volatile __BITS_ITC_SPR6  ITC_SPR6_bits					@0x7F75;
volatile char ITC_SPR6					@0x7F75;

typedef struct
{
  unsigned char VECT24SPR   : 2;
  unsigned char VECT25SPR   : 2;
  unsigned char VECT26SPR   : 2;
  unsigned char VECT27SPR   : 2;
} __BITS_ITC_SPR7;
volatile __BITS_ITC_SPR7  ITC_SPR7_bits					@0x7F76;
volatile char ITC_SPR7					@0x7F76;

typedef struct
{
  unsigned char VECT28SPR   : 2;
  unsigned char VECT29SPR   : 2;
} __BITS_ITC_SPR8;
volatile __BITS_ITC_SPR8  ITC_SPR8_bits					@0x7F77;
volatile char ITC_SPR8					@0x7F77;

typedef struct
{
  unsigned char HSIEN       : 1;
  unsigned char HSIRDY      : 1;
  unsigned char FHW         : 1;
  unsigned char LSIEN       : 1;
  unsigned char LSIRDY      : 1;
  unsigned char REGAH       : 1;
} __BITS_CLK_ICKR;
volatile __BITS_CLK_ICKR  CLK_ICKR_bits					@0x50C0;
volatile char CLK_ICKR					@0x50C0;

typedef struct
{
  unsigned char HSEEN       : 1;
  unsigned char HSERDY      : 1;
} __BITS_CLK_ECKR;
volatile __BITS_CLK_ECKR  CLK_ECKR_bits					@0x50C1;
volatile char CLK_ECKR					@0x50C1;

volatile char  CLK_CMSR					@0x50C3;
volatile char  CLK_SWR					@0x50C4;
typedef struct
{
  unsigned char SWBSY       : 1;
  unsigned char SWEN        : 1;
  unsigned char SWIEN       : 1;
  unsigned char SWIF        : 1;
} __BITS_CLK_SWCR;
volatile __BITS_CLK_SWCR  CLK_SWCR_bits					@0x50C5;
volatile char CLK_SWCR					@0x50C5;

typedef struct
{
  unsigned char CPUDIV      : 3;
  unsigned char HSIDIV      : 2;
} __BITS_CLK_CKDIVR;
volatile __BITS_CLK_CKDIVR  CLK_CKDIVR_bits					@0x50C6;
volatile char CLK_CKDIVR					@0x50C6;

volatile char  CLK_PCKENR1					@0x50C7;
typedef struct
{
  unsigned char CSSEN       : 1;
  unsigned char AUX         : 1;
  unsigned char CSSDIE      : 1;
  unsigned char CSSD        : 1;
} __BITS_CLK_CSSR;
volatile __BITS_CLK_CSSR  CLK_CSSR_bits					@0x50C8;
volatile char CLK_CSSR					@0x50C8;

typedef struct
{
  unsigned char CCOEN       : 1;
  unsigned char CCOSEL      : 4;
  unsigned char CCORDY      : 1;
  unsigned char CC0BSY      : 1;
} __BITS_CLK_CCOR;
volatile __BITS_CLK_CCOR  CLK_CCOR_bits					@0x50C9;
volatile char CLK_CCOR					@0x50C9;

volatile char  CLK_PCKENR2					@0x50CA;
typedef struct
{
  signed char HSITRIM     : 4;
} __BITS_CLK_HSITRIMR;
volatile __BITS_CLK_HSITRIMR  CLK_HSITRIMR_bits					@0x50CC;

typedef struct
{
  unsigned char SWIMCLK     : 1;
} __BITS_CLK_SWIMCCR;
volatile __BITS_CLK_SWIMCCR  CLK_SWIMCCR_bits					@0x50CD;
volatile char CLK_SWIMCCR					@0x50CD;

typedef struct
{
  unsigned char T0          : 1;
  unsigned char T1          : 1;
  unsigned char T2          : 1;
  unsigned char T3          : 1;
  unsigned char T4          : 1;
  unsigned char T5          : 1;
  unsigned char T6          : 1;
  unsigned char WDGA        : 1;
} __BITS_WWDG_CR;
volatile __BITS_WWDG_CR  WWDG_CR_bits					@0x50D1;
volatile char WWDG_CR					@0x50D1;

typedef struct
{
  unsigned char W0          : 1;
  unsigned char W1          : 1;
  unsigned char W2          : 1;
  unsigned char W3          : 1;
  unsigned char W4          : 1;
  unsigned char W5          : 1;
  unsigned char W6          : 1;
} __BITS_WWDG_WR;
volatile __BITS_WWDG_WR  WWDG_WR_bits					@0x50D2;
volatile char WWDG_WR					@0x50D2;

volatile char  IWDG_KR					@0x50E0;
typedef struct
{
  unsigned char PR          : 3;
} __BITS_IWDG_PR;
volatile __BITS_IWDG_PR  IWDG_PR_bits					@0x50E1;
volatile char IWDG_PR					@0x50E1;

volatile char  IWDG_RLR					@0x50E2;
typedef struct
{
  unsigned char MSR         : 1;
  unsigned char             : 3;
  unsigned char AWUEN       : 1;
  unsigned char AWUF        : 1;
} __BITS_AWU_CSR1;
volatile __BITS_AWU_CSR1  AWU_CSR1_bits					@0x50F0;
volatile char AWU_CSR1					@0x50F0;

typedef struct
{
  unsigned char APR         : 6;
} __BITS_AWU_APR;
volatile __BITS_AWU_APR  AWU_APR_bits					@0x50F1;
volatile char AWU_APR					@0x50F1;

typedef struct
{
  unsigned char AWUTB       : 4;
} __BITS_AWU_TBR;
volatile __BITS_AWU_TBR  AWU_TBR_bits					@0x50F2;
volatile char AWU_TBR					@0x50F2;

typedef struct
{
  unsigned char BEEPDIV     : 5;
  unsigned char BEEPEN      : 1;
  unsigned char BEEPSEL     : 2;
} __BITS_BEEP_CSR;
volatile __BITS_BEEP_CSR  BEEP_CSR_bits					@0x50F3;
volatile char BEEP_CSR					@0x50F3;

typedef struct
{
  unsigned char CPHA        : 1;
  unsigned char CPOL        : 1;
  unsigned char MSTR        : 1;
  unsigned char BR          : 3;
  unsigned char SPE         : 1;
  unsigned char LSBFIRST    : 1;
} __BITS_SPI_CR1;
volatile __BITS_SPI_CR1  SPI_CR1_bits					@0x5200;
volatile char SPI_CR1					@0x5200;

typedef struct
{
  unsigned char SSI         : 1;
  unsigned char SSM         : 1;
  unsigned char RXONLY      : 1;
  unsigned char             : 1;
  unsigned char CRCNEXT     : 1;
  unsigned char CECEN       : 1;
  unsigned char BDOE        : 1;
  unsigned char BDM         : 1;
} __BITS_SPI_CR2;
volatile __BITS_SPI_CR2  SPI_CR2_bits					@0x5201;
volatile char SPI_CR2					@0x5201;

typedef struct
{
  unsigned char             : 4;
  unsigned char WKIE        : 1;
  unsigned char ERRIE       : 1;
  unsigned char RXIE        : 1;
  unsigned char TXIE        : 1;
} __BITS_SPI_ICR;
volatile __BITS_SPI_ICR  SPI_ICR_bits					@0x5202;
volatile char SPI_ICR					@0x5202;

typedef struct
{
  unsigned char RXNE        : 1;
  unsigned char TXE         : 1;
  unsigned char             : 1;
  unsigned char WKUP        : 1;
  unsigned char CRCERR      : 1;
  unsigned char MODF        : 1;
  unsigned char OVR         : 1;
  unsigned char BSY         : 1;
} __BITS_SPI_SR;
volatile __BITS_SPI_SR  SPI_SR_bits					@0x5203;
volatile char SPI_SR					@0x5203;

volatile char  SPI_DR					@0x5204;
volatile char  SPI_CRCPR					@0x5205;
volatile char  SPI_RXCRCR					@0x5206;
volatile char  SPI_TXCRCR					@0x5207;
typedef struct
{
  unsigned char PE          : 1;
  unsigned char             : 5;
  unsigned char ENGC        : 1;
  unsigned char NOSTRETCH   : 1;
} __BITS_I2C_CR1;
volatile __BITS_I2C_CR1  I2C_CR1_bits					@0x5210;
volatile char I2C_CR1					@0x5210;

typedef struct
{
  unsigned char START       : 1;
  unsigned char STOP        : 1;
  unsigned char ACK         : 1;
  unsigned char POS         : 1;
  unsigned char             : 3;
  unsigned char SWRST       : 1;
} __BITS_I2C_CR2;
volatile __BITS_I2C_CR2  I2C_CR2_bits					@0x5211;
volatile char I2C_CR2					@0x5211;

typedef struct
{
  unsigned char FREQ        : 6;
} __BITS_I2C_FREQR;
volatile __BITS_I2C_FREQR  I2C_FREQR_bits					@0x5212;
volatile char I2C_FREQR					@0x5212;

typedef struct
{
  unsigned char ADD0        : 1;
  unsigned char ADD         : 7;
} __BITS_I2C_OARL;
volatile __BITS_I2C_OARL  I2C_OARL_bits					@0x5213;
volatile char I2C_OARL					@0x5213;

typedef struct
{
  unsigned char             : 1;
  unsigned char ADD         : 2;
  unsigned char             : 3;
  unsigned char ADDCONF     : 1;
  unsigned char ADDMODE     : 1;
} __BITS_I2C_OARH;
volatile __BITS_I2C_OARH  I2C_OARH_bits					@0x5214;
volatile char I2C_OARH					@0x5214;

volatile char  I2C_DR					@0x5216;
typedef struct
{
  unsigned char SB          : 1;
  unsigned char ADDR        : 1;
  unsigned char BTF         : 1;
  unsigned char ADD10       : 1;
  unsigned char STOPF       : 1;
  unsigned char             : 1;
  unsigned char RXNE        : 1;
  unsigned char TXE         : 1;
} __BITS_I2C_SR1;
volatile __BITS_I2C_SR1  I2C_SR1_bits					@0x5217;
volatile char I2C_SR1					@0x5217;

typedef struct
{
  unsigned char BERR        : 1;
  unsigned char ARLO        : 1;
  unsigned char AF          : 1;
  unsigned char OVR         : 1;
  unsigned char             : 1;
  unsigned char WUFH        : 1;
} __BITS_I2C_SR2;
volatile __BITS_I2C_SR2  I2C_SR2_bits					@0x5218;
volatile char I2C_SR2					@0x5218;

typedef struct
{
  unsigned char MSL         : 1;
  unsigned char BUSY        : 1;
  unsigned char TRA         : 1;
  unsigned char             : 1;
  unsigned char GENCALL     : 1;
} __BITS_I2C_SR3;
volatile __BITS_I2C_SR3  I2C_SR3_bits					@0x5219;
volatile char I2C_SR3					@0x5219;

typedef struct
{
  unsigned char ITERREN     : 1;
  unsigned char ITEVTEN     : 1;
  unsigned char ITBUFEN     : 1;
} __BITS_I2C_ITR;
volatile __BITS_I2C_ITR  I2C_ITR_bits					@0x521A;
volatile char I2C_ITR					@0x521A;

volatile char  I2C_CCRL					@0x521B;
typedef struct
{
  unsigned char CCR         : 4;
  unsigned char             : 2;
  unsigned char DUTY        : 1;
  unsigned char F_S         : 1;
} __BITS_I2C_CCRH;
volatile __BITS_I2C_CCRH  I2C_CCRH_bits					@0x521C;
volatile char I2C_CCRH					@0x521C;

typedef struct
{
  unsigned char TRISE       : 6;
} __BITS_I2C_TRISER;
volatile __BITS_I2C_TRISER  I2C_TRISER_bits					@0x521D;
volatile char I2C_TRISER					@0x521D;

volatile char  I2C_PECR					@0x521E;
typedef struct
{
  unsigned char PE          : 1;
  unsigned char FE          : 1;
  unsigned char NF          : 1;
  unsigned char OR_LHE      : 1;
  unsigned char IDLE        : 1;
  unsigned char RXNE        : 1;
  unsigned char TC          : 1;
  unsigned char TXE         : 1;
} __BITS_UART1_SR;
volatile __BITS_UART1_SR  UART1_SR_bits					@0x5230;
volatile char UART1_SR					@0x5230;

volatile char  UART1_DR					@0x5231;
volatile char  UART1_BRR1					@0x5232;
volatile char  UART1_BRR2					@0x5233;
typedef struct
{
  unsigned char PIEN        : 1;
  unsigned char PS          : 1;
  unsigned char PCEN        : 1;
  unsigned char WAKE        : 1;
  unsigned char M           : 1;
  unsigned char UART0       : 1;
  unsigned char T8          : 1;
  unsigned char R8          : 1;
} __BITS_UART1_CR1;
volatile __BITS_UART1_CR1  UART1_CR1_bits					@0x5234;
volatile char UART1_CR1					@0x5234;

typedef struct
{
  unsigned char SBK         : 1;
  unsigned char RWU         : 1;
  unsigned char REN         : 1;
  unsigned char TEN         : 1;
  unsigned char ILIEN       : 1;
  unsigned char RIEN        : 1;
  unsigned char TCIEN       : 1;
  unsigned char TIEN        : 1;
} __BITS_UART1_CR2;
volatile __BITS_UART1_CR2  UART1_CR2_bits					@0x5235;
volatile char UART1_CR2					@0x5235;

typedef struct
{
  unsigned char LBCL        : 1;
  unsigned char CPHA        : 1;
  unsigned char CPOL        : 1;
  unsigned char CKEN        : 1;
  unsigned char STOP        : 2;
  unsigned char             : 1;
  unsigned char LINEN       : 1;
} __BITS_UART1_CR3;
volatile __BITS_UART1_CR3  UART1_CR3_bits					@0x5236;
volatile char UART1_CR3					@0x5236;

typedef struct
{
  unsigned char ADD         : 4;
  unsigned char LBDF        : 1;
  unsigned char LBDL        : 1;
  unsigned char LBDIEN      : 1;
} __BITS_UART1_CR4;
volatile __BITS_UART1_CR4  UART1_CR4_bits					@0x5237;
volatile char UART1_CR4					@0x5237;

typedef struct
{
  unsigned char             : 1;
  unsigned char IREN        : 1;
  unsigned char IRLP        : 1;
  unsigned char HDSEL       : 1;
  unsigned char NACK        : 1;
  unsigned char SCEN        : 1;
} __BITS_UART1_CR5;
volatile __BITS_UART1_CR5  UART1_CR5_bits					@0x5238;
volatile char UART1_CR5					@0x5238;

volatile char  UART1_GTR					@0x5239;
volatile char  UART1_PSCR					@0x523A;
typedef struct
{
  unsigned char CEN         : 1;
  unsigned char UDIS        : 1;
  unsigned char URS         : 1;
  unsigned char OPM         : 1;
  unsigned char DIR         : 1;
  unsigned char CMS         : 2;
  unsigned char ARPE        : 1;
} __BITS_TIM1_CR1;
volatile __BITS_TIM1_CR1  TIM1_CR1_bits					@0x5250;
volatile char TIM1_CR1					@0x5250;

typedef struct
{
  unsigned char CCPG        : 1;
  unsigned char             : 1;
  unsigned char COMS        : 1;
  unsigned char             : 1;
  unsigned char MMS         : 3;
} __BITS_TIM1_CR2;
volatile __BITS_TIM1_CR2  TIM1_CR2_bits					@0x5251;
volatile char TIM1_CR2					@0x5251;

typedef struct
{
  unsigned char SMS         : 3;
  unsigned char             : 1;
  unsigned char TS          : 3;
  unsigned char MSM         : 1;
} __BITS_TIM1_SMCR;
volatile __BITS_TIM1_SMCR  TIM1_SMCR_bits					@0x5252;
volatile char TIM1_SMCR					@0x5252;

typedef struct
{
  unsigned char ETF         : 4;
  unsigned char ETPS        : 2;
  unsigned char ECE         : 1;
  unsigned char ETP         : 1;
} __BITS_TIM1_ETR;
volatile __BITS_TIM1_ETR  TIM1_ETR_bits					@0x5253;
volatile char TIM1_ETR					@0x5253;

typedef struct
{
  unsigned char UIE         : 1;
  unsigned char CC1IE       : 1;
  unsigned char CC2IE       : 1;
  unsigned char CC3IE       : 1;
  unsigned char CC4IE       : 1;
  unsigned char COMIE       : 1;
  unsigned char TIE         : 1;
  unsigned char BIE         : 1;
} __BITS_TIM1_IER;
volatile __BITS_TIM1_IER  TIM1_IER_bits					@0x5254;
volatile char TIM1_IER					@0x5254;

typedef struct
{
  unsigned char UIF         : 1;
  unsigned char CC1IF       : 1;
  unsigned char CC2IF       : 1;
  unsigned char CC3IF       : 1;
  unsigned char CC4IF       : 1;
  unsigned char COMIF       : 1;
  unsigned char TIF         : 1;
  unsigned char BIF         : 1;
} __BITS_TIM1_SR1;
volatile __BITS_TIM1_SR1  TIM1_SR1_bits					@0x5255;
volatile char TIM1_SR1					@0x5255;

typedef struct
{
  unsigned char             : 1;
  unsigned char CC1OF       : 1;
  unsigned char CC2OF       : 1;
  unsigned char CC3OF       : 1;
  unsigned char CC4OF       : 1;
} __BITS_TIM1_SR2;
volatile __BITS_TIM1_SR2  TIM1_SR2_bits					@0x5256;
volatile char TIM1_SR2					@0x5256;

typedef struct
{
  unsigned char UG          : 1;
  unsigned char CC1G        : 1;
  unsigned char CC2G        : 1;
  unsigned char CC3G        : 1;
  unsigned char CC4G        : 1;
  unsigned char COMG        : 1;
  unsigned char TG          : 1;
  unsigned char BG          : 1;
} __BITS_TIM1_EGR;
volatile __BITS_TIM1_EGR  TIM1_EGR_bits					@0x5257;
volatile char TIM1_EGR					@0x5257;

typedef struct
{
  unsigned char CC1S        : 2;
  unsigned char OC1FE       : 1;
  unsigned char OC1PE       : 1;
  unsigned char OC1M        : 3;
  unsigned char OC1CE       : 1;
} __BITS_TIM1_CCMR1;
volatile __BITS_TIM1_CCMR1  TIM1_CCMR1_bits					@0x5258;
volatile char TIM1_CCMR1					@0x5258;

typedef struct
{
  unsigned char CC2S        : 2;
  unsigned char OC2FE       : 1;
  unsigned char OC2PE       : 1;
  unsigned char OC2M        : 3;
  unsigned char OC2CE       : 1;
} __BITS_TIM1_CCMR2;
volatile __BITS_TIM1_CCMR2  TIM1_CCMR2_bits					@0x5259;
volatile char TIM1_CCMR2					@0x5259;

typedef struct
{
  unsigned char CC3S        : 2;
  unsigned char OC3FE       : 1;
  unsigned char OC3PE       : 1;
  unsigned char OC3M        : 3;
  unsigned char OC3CE       : 1;
} __BITS_TIM1_CCMR3;
volatile __BITS_TIM1_CCMR3  TIM1_CCMR3_bits					@0x525A;
volatile char TIM1_CCMR3					@0x525A;

typedef struct
{
  unsigned char CC4S        : 2;
  unsigned char OC4FE       : 1;
  unsigned char OC4PE       : 1;
  unsigned char OC4M        : 3;
  unsigned char OC4CE       : 1;
} __BITS_TIM1_CCMR4;
volatile __BITS_TIM1_CCMR4  TIM1_CCMR4_bits					@0x525B;
volatile char TIM1_CCMR4					@0x525B;

typedef struct
{
  unsigned char CC1E        : 1;
  unsigned char CC1P        : 1;
  unsigned char CC1NE       : 1;
  unsigned char CC1NP       : 1;
  unsigned char CC2E        : 1;
  unsigned char CC2P        : 1;
  unsigned char CC2NE       : 1;
  unsigned char CC2NP       : 1;
} __BITS_TIM1_CCER1;
volatile __BITS_TIM1_CCER1  TIM1_CCER1_bits					@0x525C;
volatile char TIM1_CCER1					@0x525C;

typedef struct
{
  unsigned char CC3E        : 1;
  unsigned char CC3P        : 1;
  unsigned char CC3NE       : 1;
  unsigned char CC3NP       : 1;
  unsigned char CC4E        : 1;
  unsigned char CC4P        : 1;
} __BITS_TIM1_CCER2;
volatile __BITS_TIM1_CCER2  TIM1_CCER2_bits					@0x525D;
volatile char TIM1_CCER2					@0x525D;

volatile char  TIM1_CNTRH					@0x525E;
volatile char  TIM1_CNTRL					@0x525F;
volatile char  TIM1_PSCRH					@0x5260;
volatile char  TIM1_PSCRL					@0x5261;
volatile char  TIM1_ARRH					@0x5262;
volatile char  TIM1_ARRL					@0x5263;
volatile char  TIM1_RCR					@0x5264;
volatile char  TIM1_CCR1H					@0x5265;
volatile char  TIM1_CCR1L					@0x5266;
volatile char  TIM1_CCR2H					@0x5267;
volatile char  TIM1_CCR2L					@0x5268;
volatile char  TIM1_CCR3H					@0x5269;
volatile char  TIM1_CCR3L					@0x526A;
volatile char  TIM1_CCR4H					@0x526B;
volatile char  TIM1_CCR4L					@0x526C;
typedef struct
{
  unsigned char LOCK        : 2;
  unsigned char OSSI        : 1;
  unsigned char OSSR        : 1;
  unsigned char BKE         : 1;
  unsigned char BKP         : 1;
  unsigned char AOE         : 1;
  unsigned char MOE         : 1;
} __BITS_TIM1_BKR;
volatile __BITS_TIM1_BKR  TIM1_BKR_bits					@0x526D;
volatile char TIM1_BKR					@0x526D;

volatile char  TIM1_DTR					@0x526E;
typedef struct
{
  unsigned char OIS1        : 1;
  unsigned char OIS1N       : 1;
  unsigned char OIS2        : 1;
  unsigned char OIS2N       : 1;
  unsigned char OIS3        : 1;
  unsigned char OIS3N       : 1;
  unsigned char OIS4        : 1;
} __BITS_TIM1_OISR;
volatile __BITS_TIM1_OISR  TIM1_OISR_bits					@0x526F;
volatile char TIM1_OISR					@0x526F;

typedef struct
{
  unsigned char CEN         : 1;
  unsigned char UDIS        : 1;
  unsigned char URS         : 1;
  unsigned char OPM         : 1;
  unsigned char             : 3;
  unsigned char ARPE        : 1;
} __BITS_TIM2_CR1;
volatile __BITS_TIM2_CR1  TIM2_CR1_bits					@0x5300;
volatile char TIM2_CR1					@0x5300;

typedef struct
{
  unsigned char UIE         : 1;
  unsigned char CC1IE       : 1;
  unsigned char CC2IE       : 1;
  unsigned char CC3IE       : 1;
  unsigned char             : 2;
  unsigned char TIE         : 1;
} __BITS_TIM2_IER;
volatile __BITS_TIM2_IER  TIM2_IER_bits					@0x5303;
volatile char TIM2_IER					@0x5303;

typedef struct
{
  unsigned char UIF         : 1;
  unsigned char CC1IF       : 1;
  unsigned char CC2IF       : 1;
  unsigned char CC3IF       : 1;
  unsigned char             : 2;
  unsigned char TIF         : 1;
} __BITS_TIM2_SR1;
volatile __BITS_TIM2_SR1  TIM2_SR1_bits					@0x5304;
volatile char TIM2_SR1					@0x5304;

typedef struct
{
  unsigned char             : 1;
  unsigned char CC1OF       : 1;
  unsigned char CC2OF       : 1;
  unsigned char CC3OF       : 1;
} __BITS_TIM2_SR2;
volatile __BITS_TIM2_SR2  TIM2_SR2_bits					@0x5305;
volatile char TIM2_SR2					@0x5305;

typedef struct
{
  unsigned char UG          : 1;
  unsigned char CC1G        : 1;
  unsigned char CC2G        : 1;
  unsigned char CC3G        : 1;
  unsigned char             : 2;
  unsigned char TG          : 1;
} __BITS_TIM2_EGR;
volatile __BITS_TIM2_EGR  TIM2_EGR_bits					@0x5306;
volatile char TIM2_EGR					@0x5306;

typedef struct
{
  unsigned char CC1S        : 2;
  unsigned char             : 1;
  unsigned char OC1PE       : 1;
  unsigned char OC1M        : 3;
} __BITS_TIM2_CCMR1;
volatile __BITS_TIM2_CCMR1  TIM2_CCMR1_bits					@0x5307;
volatile char TIM2_CCMR1					@0x5307;

typedef struct
{
  unsigned char CC2S        : 2;
  unsigned char             : 1;
  unsigned char OC2PE       : 1;
  unsigned char OC2M        : 3;
} __BITS_TIM2_CCMR2;
volatile __BITS_TIM2_CCMR2  TIM2_CCMR2_bits					@0x5308;
volatile char TIM2_CCMR2					@0x5308;

typedef struct
{
  unsigned char CC3S        : 2;
  unsigned char             : 1;
  unsigned char OC3PE       : 1;
  unsigned char OC3M        : 3;
} __BITS_TIM2_CCMR3;
volatile __BITS_TIM2_CCMR3  TIM2_CCMR3_bits					@0x5309;
volatile char TIM2_CCMR3					@0x5309;

typedef struct
{
  unsigned char CC1E        : 1;
  unsigned char CC1P        : 1;
  unsigned char             : 2;
  unsigned char CC2E        : 1;
  unsigned char CC2P        : 1;
} __BITS_TIM2_CCER1;
volatile __BITS_TIM2_CCER1  TIM2_CCER1_bits					@0x530A;
volatile char TIM2_CCER1					@0x530A;

typedef struct
{
  unsigned char CC3E        : 1;
  unsigned char CC3P        : 1;
} __BITS_TIM2_CCER2;
volatile __BITS_TIM2_CCER2  TIM2_CCER2_bits					@0x530B;
volatile char TIM2_CCER2					@0x530B;

volatile char  TIM2_CNTRH					@0x530C;
volatile char  TIM2_CNTRL					@0x530D;
typedef struct
{
  unsigned char PSC         : 4;
} __BITS_TIM2_PSCR;
volatile __BITS_TIM2_PSCR  TIM2_PSCR_bits					@0x530E;
volatile char TIM2_PSCR					@0x530E;

volatile char  TIM2_ARRH					@0x530F;
volatile char  TIM2_ARRL					@0x5310;
volatile char  TIM2_CCR1H					@0x5311;
volatile char  TIM2_CCR1L					@0x5312;
volatile char  TIM2_CCR2H					@0x5313;
volatile char  TIM2_CCR2L					@0x5314;
volatile char  TIM2_CCR3H					@0x5315;
volatile char  TIM2_CCR3L					@0x5316;
typedef struct
{
  unsigned char CEN         : 1;
  unsigned char UDIS        : 1;
  unsigned char URS         : 1;
  unsigned char OPM         : 1;
  unsigned char             : 3;
  unsigned char ARPE        : 1;
} __BITS_TIM4_CR1;
volatile __BITS_TIM4_CR1  TIM4_CR1_bits					@0x5340;
volatile char TIM4_CR1					@0x5340;

typedef struct
{
  unsigned char UIE         : 1;
  unsigned char             : 5;
  unsigned char TIE         : 1;
} __BITS_TIM4_IER;
volatile __BITS_TIM4_IER  TIM4_IER_bits					@0x5343;
volatile char TIM4_IER					@0x5343;

typedef struct
{
  unsigned char UIF         : 1;
  unsigned char             : 5;
  unsigned char TIF         : 1;
} __BITS_TIM4_SR;
volatile __BITS_TIM4_SR  TIM4_SR_bits					@0x5344;
volatile char TIM4_SR					@0x5344;

typedef struct
{
  unsigned char UG          : 1;
  unsigned char             : 5;
  unsigned char TG          : 1;
} __BITS_TIM4_EGR;
volatile __BITS_TIM4_EGR  TIM4_EGR_bits					@0x5345;
volatile char TIM4_EGR					@0x5345;

volatile char  TIM4_CNTR					@0x5346;
typedef struct
{
  unsigned char PSC         : 3;
} __BITS_TIM4_PSCR;
volatile __BITS_TIM4_PSCR  TIM4_PSCR_bits					@0x5347;
volatile char TIM4_PSCR					@0x5347;

volatile char  TIM4_ARR					@0x5348;
volatile char  ADC_DB0RH					@0x53E0;
volatile char  ADC_DB0RL					@0x53E1;
volatile char  ADC_DB1RH					@0x53E2;
volatile char  ADC_DB1RL					@0x53E3;
volatile char  ADC_DB2RH					@0x53E4;
volatile char  ADC_DB2RL					@0x53E5;
volatile char  ADC_DB3RH					@0x53E6;
volatile char  ADC_DB3RL					@0x53E7;
volatile char  ADC_DB4RH					@0x53E8;
volatile char  ADC_DB4RL					@0x53E9;
volatile char  ADC_DB5RH					@0x53EA;
volatile char  ADC_DB5RL					@0x53EB;
volatile char  ADC_DB6RH					@0x53EC;
volatile char  ADC_DB6RL					@0x53ED;
volatile char  ADC_DB7RH					@0x53EE;
volatile char  ADC_DB7RL					@0x53EF;
volatile char  ADC_DB8RH					@0x53F0;
volatile char  ADC_DB8RL					@0x53F1;
volatile char  ADC_DB9RH					@0x53F2;
volatile char  ADC_DB9RL					@0x53F3;
typedef struct
{
  unsigned char CH          : 4;
  unsigned char AWDIE       : 1;
  unsigned char EOCIE       : 1;
  unsigned char AWD         : 1;
  unsigned char EOC         : 1;
} __BITS_ADC_CSR;
volatile __BITS_ADC_CSR  ADC_CSR_bits					@0x5400;
volatile char ADC_CSR					@0x5400;

typedef struct
{
  unsigned char ADON        : 1;
  unsigned char CONT        : 1;
  unsigned char             : 2;
  unsigned char SPSEL       : 3;
} __BITS_ADC_CR1;
volatile __BITS_ADC_CR1  ADC_CR1_bits					@0x5401;
volatile char ADC_CR1					@0x5401;

typedef struct
{
  unsigned char             : 1;
  unsigned char SCAN        : 1;
  unsigned char             : 1;
  unsigned char ALIGN       : 1;
  unsigned char EXTSEL      : 2;
  unsigned char EXTTRIG     : 1;
} __BITS_ADC_CR2;
volatile __BITS_ADC_CR2  ADC_CR2_bits					@0x5402;
volatile char ADC_CR2					@0x5402;

typedef struct
{
  unsigned char             : 6;
  unsigned char OVR         : 1;
  unsigned char DBUF        : 1;
} __BITS_ADC_CR3;
volatile __BITS_ADC_CR3  ADC_CR3_bits					@0x5403;
volatile char ADC_CR3					@0x5403;

volatile char  ADC_DRH					@0x5404;
volatile char  ADC_DRL					@0x5405;
volatile char  ADC_TDRH					@0x5406;
volatile char  ADC_TDRL					@0x5407;
volatile char  ADC_HTRH					@0x5408;
typedef struct
{
  unsigned char HT          : 2;
} __BITS_ADC_HTRL;
volatile __BITS_ADC_HTRL  ADC_HTRL_bits					@0x5409;
volatile char ADC_HTRL					@0x5409;

volatile char  ADC_LTRH					@0x540A;
typedef struct
{
  unsigned char LT          : 2;
} __BITS_ADC_LTRL;
volatile __BITS_ADC_LTRL  ADC_LTRL_bits					@0x540B;
volatile char ADC_LTRL					@0x540B;

typedef struct
{
  unsigned char AWS8        : 1;
  unsigned char AWS9        : 1;
} __BITS_ADC_AWSRH;
volatile __BITS_ADC_AWSRH  ADC_AWSRH_bits					@0x540C;
volatile char ADC_AWSRH					@0x540C;

typedef struct
{
  unsigned char AWS0        : 1;
  unsigned char AWS1        : 1;
  unsigned char AWS2        : 1;
  unsigned char AWS3        : 1;
  unsigned char AWS4        : 1;
  unsigned char AWS5        : 1;
  unsigned char AWS6        : 1;
  unsigned char AWS7        : 1;
} __BITS_ADC_AWSRL;
volatile __BITS_ADC_AWSRL  ADC_AWSRL_bits					@0x540D;
volatile char ADC_AWSRL					@0x540D;

typedef struct
{
  unsigned char AWEN8       : 1;
  unsigned char AWEN9       : 1;
} __BITS_ADC_AWCRH;
volatile __BITS_ADC_AWCRH  ADC_AWCRH_bits					@0x540E;
volatile char ADC_AWCRH					@0x540E;

typedef struct
{
  unsigned char AWEN0       : 1;
  unsigned char AWEN1       : 1;
  unsigned char AWEN2       : 1;
  unsigned char AWEN3       : 1;
  unsigned char AWEN4       : 1;
  unsigned char AWEN5       : 1;
  unsigned char AWEN6       : 1;
  unsigned char AWEN7       : 1;
} __BITS_ADC_AWCRL;
volatile __BITS_ADC_AWCRL  ADC_AWCRL_bits					@0x540F;
volatile char ADC_AWCRL					@0x540F;

volatile char  CPU_A					@0x7F00;
volatile char  CPU_PCE					@0x7F01;
volatile char  CPU_PCH					@0x7F02;
volatile char  CPU_PCL					@0x7F03;
volatile char  CPU_XH					@0x7F04;
volatile char  CPU_XL					@0x7F05;
volatile char  CPU_YH					@0x7F06;
volatile char  CPU_YL					@0x7F07;
volatile char  CPU_SPH					@0x7F08;
volatile char  CPU_SPL					@0x7F09;
typedef struct
{
  unsigned char C           : 1;
  unsigned char Z           : 1;
  unsigned char NF          : 1;
  unsigned char I0          : 1;
  unsigned char H           : 1;
  unsigned char I1          : 1;
  unsigned char             : 1;
  unsigned char V           : 1;
} __BITS_CPU_CCR;
volatile __BITS_CPU_CCR  CPU_CCR_bits					@0x7F0A;
volatile char CPU_CCR					@0x7F0A;

typedef struct
{
  unsigned char SWO         : 1;
  unsigned char AL          : 1;
} __BITS_CPU_CFG_GCR;
volatile __BITS_CPU_CFG_GCR  CPU_CFG_GCR_bits					@0x7F60;
volatile char CPU_CFG_GCR					@0x7F60;

volatile char  SWIM_CSR					@0x7F80;
volatile char  DM_BK1RE					@0x7F90;
volatile char  DM_BK1RH					@0x7F91;
volatile char  DM_BK1RL					@0x7F92;
volatile char  DM_BK2RE					@0x7F93;
volatile char  DM_BK2RH					@0x7F94;
volatile char  DM_BK2RL					@0x7F95;
volatile char  DM_CR1					@0x7F96;
volatile char  DM_CR2					@0x7F97;
volatile char  DM_CSR1					@0x7F98;
volatile char  DM_CSR2					@0x7F99;
volatile char  DM_ENFCTR					@0x7F9A;
#endif // #ifdef IOSTM8S003K3_H
