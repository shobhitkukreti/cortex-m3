#ifndef REG_H_
#define REG_H_


#define STCTRL (*((volatile unsigned int *)0xE000E010))
#define STRELOAD (*((volatile unsigned int *)0xE000E014))
#define STCURRENT (*((volatile unsigned int *) 0xE000E018))
#define EN0_31	(*((volatile unsigned int *)0xE000E100))
#define EN32_63 (*((volatile unsigned int *)0xE000E104))
#define DIS0_31 (*((volatile unsigned int *)0XE000E180))
#define DIS32_63 (*((volatile unsigned int *)0XE000184))
#define SYSPRI2 (*((volatile unsigned int *)0XE000ED1C))
#define SYSPRI3 (*((volatile unsigned int *)0xE000ED20))
#define SYSHNDCTRL (*((volatile unsigned int *)0xE000ED24))
#define SVC_PEND() ((SYSHNDCTRL & 0x8000)?1:0)
#define TICK_PEND() ((SYSHNDCTRL & 0x800)?1:0)




#define TICK_PRIO(prio) {SYSPRI3 &=0x1FFFFFFF; \
			 SYSPRI3 |=(prio<<28); \
			}


#define SVC_PRIO(prio) {SYSPRI2 &=0x1FFFFFFF;   \
			SYSPRI2 |=(prio<<28);	\
			}



#endif
