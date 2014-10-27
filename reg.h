#ifndef REG_H_
#define REG_H_


#define STCTRL (volatile unsigned int *)0xE000E010
#define STRELOAD (volatile unsigned int *)0xE000E014
#define STCURRENT (volatile unsigned int *) 0xE000E018
#define EN0_31	(volatile unsigned int *)0xE000E100
#define EN32_63 (volatile unsigned int *)0xE000E104
#define DIS0_31 (volatile unsigned int *)0XE000E180
#define DIS32_63 (volatile unsigned int *)0XE000184

#endif
