/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MemoryMap.h
 *       Module:  MemoryMap
 *
 *  Description:  header file for TM4C123GH6PM Registers definition
 *
 *********************************************************************************************************************/
#ifndef MEMORYMAP_H
#define MEMORYMAP_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

// type of each register
#define RW__ volatile
#define RO__ volatile
#define WO__ volatile
#define RWC__ volatile
#define RW1C__ volatile
#define W1C__ volatile

//___________________________________
// NVIC registers
typedef struct
{
    RW__ uint32 EN[5];
    vuint32 reserved1[27];
    RW__ uint32 DIS[5];
    vuint32 reserved2[27];
    RW__ uint32 PEND[5];
    vuint32 reserved3[27];
    RW__ uint32 UNPEND[5];
    vuint32 reserved4[27];
    RO__ uint32 ACTIV[5];
    vuint32 reserved5[59];
    RW__ uint32 PRI[35];
    vuint32 reserved6[669];
    WO__ uint32 SWTRIG;
} NVIC_Type;

//___________________________________
// SCB registers
typedef struct
{
    RO__ uint32 CPUID;
    RW__ uint32 INTCTRL;
    RW__ uint32 VTABLE;
    RW__ uint32 APINT;
    RW__ uint32 SYSCTRL;
    RW__ uint32 CFGCTRL;
    RW__ uint32 SYSPRI1;
    RW__ uint32 SYSPRI2;
    RW__ uint32 SYSPRI3;
    RW__ uint32 SYSHNDCTRL;
    RW1C__ uint32 FAULTSTAT;
    RW1C__ uint32 HFAULTSTAT;
    vuint32 reserved2;
    RW__ uint32 MMADDR;
    RW__ uint32 FAULTADDR;
} SCB_Type;
//___________________________________
// GPIO registers
typedef struct
{
    RW__ uint32 GPIODATA[256];
    RW__ uint32 GPIODIR;
    RW__ uint32 GPIOIS;
    RW__ uint32 GPIOIBE;
    RW__ uint32 GPIOIEV;
    RW__ uint32 GPIOIM;
    RO__ uint32 GPIORIS;
    RO__ uint32 GPIOMIS;
    W1C__ uint32 GPIOICR;
    RW__ uint32 GPIOAFSEL;
    vuint32 reserved2[55];
    RW__ uint32 GPIODR2R;
    RW__ uint32 GPIODR4R;
    RW__ uint32 GPIODR8R;
    RW__ uint32 GPIOODR;
    RW__ uint32 GPIOPUR;
    RW__ uint32 GPIOPDR;
    RW__ uint32 GPIOSLR;
    RW__ uint32 GPIODEN;
    RW__ uint32 GPIOLOCK;
    vuint32 GPIOCR;
    RW__ uint32 GPIOAMSEL;
    RW__ uint32 GPIOPCTL;
    RW__ uint32 GPIOADCCTL;
    RW__ uint32 GPIODMACTL;
    vuint32 reserved3[678];
    RO__ uint32 GPIOPeriphID4;
    RO__ uint32 GPIOPeriphID5;
    RO__ uint32 GPIOPeriphID6;
    RO__ uint32 GPIOPeriphID7;
    RO__ uint32 GPIOPeriphID0;
    RO__ uint32 GPIOPeriphID1;
    RO__ uint32 GPIOPeriphID2;
    RO__ uint32 GPIOPeriphID3;
    RO__ uint32 GPIOPCellID0;
    RO__ uint32 GPIOPCellID1;
    RO__ uint32 GPIOPCellID2;
    RO__ uint32 GPIOPCellID3;
} GPIO_Type;

//___________________________________
// SysCtrl registers
// ONLY required REGISTERES IS IMPLEMENTED
typedef struct
{
    vuint32 reserved[383];
    RW__ uint32 RCGCWD;
    RW__ uint32 RCGCTIMER;
    RW__ uint32 RCGCGPIO;
    RW__ uint32 RCGCDMA;
    vuint32 reserved1;
    RW__ uint32 RCGCHIB;
    RW__ uint32 RCGCUART;
    RW__ uint32 RCGCSSI;
    RW__ uint32 RCGCI2C;
    vuint32 reserved2;
    RW__ uint32 RCGCUSB;
    vuint32 reserved3[2];
    RW__ uint32 RCGCCAN;
    RW__ uint32 RCGCADC;
    RW__ uint32 RCGCACMP;
    RW__ uint32 RCGCPWM;
    RW__ uint32 RCGCQEI;
    vuint32 reserved4[4];
    RW__ uint32 RCGCEEPROM;
    RW__ uint32 RCGCWTIMER;
    vuint32 reserve[232];
    RO__ uint32 PRWD;
    RO__ uint32 PRTIMER;
    RO__ uint32 PRGPIO;
    RO__ uint32 PRDMA;
    vuint32 reserved5;
    RO__ uint32 PRHIB;
    RO__ uint32 PRUART;
    RO__ uint32 PRSSI;
    RO__ uint32 PRI2C;
    vuint32 reserved6;
    RO__ uint32 PRUSB;
    vuint32 reserved7[2];
    RO__ uint32 PRCAN;
    RO__ uint32 PRADC;
    RO__ uint32 PRACMP;
    RO__ uint32 PRPWM;
    RO__ uint32 PRQEI;
    vuint32 reserved8[4];
    RO__ uint32 PREEPROM;
    RO__ uint32 PRWTIMER;
} SysCTRL_Type;
//___________________________________
// General Prpose Timers registers
typedef struct
{
    RW__ uint32 GPTMCFG;
    RW__ uint32 GPTMTAMR;
    RW__ uint32 GPTMTBMR;
    RW__ uint32 GPTMCTL;
    RW__ uint32 GPTMSYNC;
    RW__ uint32 reserved1;
    RW__ uint32 GPTMIMR;
    RO__ uint32 GPTMRIS;
    RO__ uint32 GPTMMIS;
    W1C__ uint32 GPTMICR;
    RW__ uint32 GPTMTAILR;
    RW__ uint32 GPTMTBILR;
    RW__ uint32 GPTMTAMATCHR;
    RW__ uint32 GPTMTAMBTCHR;
    RW__ uint32 GPTMTAPR;
    RW__ uint32 GPTMTBPR;
    RW__ uint32 GPTMTAPMR;
    RW__ uint32 GPTMTBPMR;
    RO__ uint32 GPTMTAR;
    RO__ uint32 GPTMTBR;
    RW__ uint32 GPTMTAV;
    RW__ uint32 GPTMTBV;
    RO__ uint32 GPTMTCPD;
    RO__ uint32 GPTMTAPS;
    RO__ uint32 GPTMTBPS;
    RO__ uint32 GPTMTAPV;
    RO__ uint32 GPTMTBPV;
    RW__ uint32 reserved2[918];
    RO__ uint32 GPTMPP;
} Gpt_Type;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// private peripherals addresses
#define CORTEXM4_CORE_PERIPHERALS_BASE 0xE000E000u
#define NVIC_OFFSET 0x100u
#define SCB_OFFSET 0xD00u

// GPIO APB Base addresses
#define GPIOA_BASE 0x40004000u
#define GPIOB_BASE 0x40005000u
#define GPIOC_BASE 0x40006000u
#define GPIOD_BASE 0x40007000u
#define GPIOE_BASE 0x40024000u
#define GPIOF_BASE 0x40025000u

// SysCtrl Base addresses
#define SysCtrl_BASE 0x400FE000u

// GPT Base addresses
#define Timer0_BASE 0x40030000u
#define Timer1_BASE 0x40031000u
#define Timer2_BASE 0x40032000u
#define Timer3_BASE 0x40033000u
#define Timer4_BASE 0x40035000u
#define Timer5_BASE 0x40035000u
#define WTimer0_BASE 0x40036000u
#define WTimer1_BASE 0x40037000u
#define WTimer2_BASE 0x4004C000u
#define WTimer3_BASE 0x4004D000u
#define WTimer4_BASE 0x4004E000u
#define WTimer5_BASE 0x4004F000u

//___________________________________
// module instances

//Nvic and System Control bBock
#define NVIC ((NVIC_Type *)(CORTEXM4_CORE_PERIPHERALS_BASE + NVIC_OFFSET))
#define SCB ((SCB_Type *)(CORTEXM4_CORE_PERIPHERALS_BASE + SCB_OFFSET))

//GPIO
#define GPIOA ((GPIO_Type *)(GPIOA_BASE))
#define GPIOB ((GPIO_Type *)(GPIOB_BASE))
#define GPIOC ((GPIO_Type *)(GPIOC_BASE))
#define GPIOD ((GPIO_Type *)(GPIOD_BASE))
#define GPIOE ((GPIO_Type *)(GPIOE_BASE))
#define GPIOF ((GPIO_Type *)(GPIOF_BASE))

#define GPIO(GPIO_BASE) ((GPIO_Type *)(GPIO_BASE))

//System Control
#define SysCtrl ((SysCTRL_Type *)(SysCtrl_BASE))

//General Purpose Timers
#define Timer0 ((Gpt_Type *)(Timer0_BASE))
#define Timer1 ((Gpt_Type *)(Timer1_BASE))
#define Timer2 ((Gpt_Type *)(Timer2_BASE))
#define Timer3 ((Gpt_Type *)(Timer3_BASE))
#define Timer4 ((Gpt_Type *)(Timer4_BASE))
#define Timer5 ((Gpt_Type *)(Timer5_BASE))

#define Timer(TIMER_BASE) ((Gpt_Type *)(TIMER_BASE))

#define WTimer0 ((Gpt_Type *)(WTimer0_BASE))
#define WTimer1 ((Gpt_Type *)(WTimer1_BASE))
#define WTimer2 ((Gpt_Type *)(WTimer2_BASE))
#define WTimer3 ((Gpt_Type *)(WTimer3_BASE))
#define WTimer4 ((Gpt_Type *)(WTimer4_BASE))
#define WTimer5 ((Gpt_Type *)(WTimer5_BASE))

#define WTimer(WTIMER_BASE) ((Gpt_Type *)(WTIMER_BASE))

#endif /* MEMORYMAP_H */

/**********************************************************************************************************************
 *  END OF FILE: MemoryMap.h
 *********************************************************************************************************************/
