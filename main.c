#include "print.h"
#include "reg.h"

#define	MS_TO_CNT(ms) 120000*ms

void ms_delay(unsigned int msec);
int c_entry() {

while(1)
{
put("SYSTICK DEMO\n",14);
ms_delay(500); // runs slower on emulator
put("HELLO\n",7);
ms_delay(500);
put("NONE\n",6);
}
return 0;
}


void setup_timer (int val)
{
*STRELOAD = val;
*STCTRL = 0x5; // Enables the timer after loading the value
}


void ms_delay(unsigned int msec)
{
	int flag=1;
	unsigned int val = MS_TO_CNT(msec);
	setup_timer(val);
	while(flag) {
/* Read the count bit to check if STCURRENT hit zero before getting reloaded.
 * Certainly not accurate, but should be close enough
*/
	if((*STCTRL) & 0x10000) // Cannot bitshift while reading a register.
		{
			*STCURRENT=0x00; 
			*STCTRL=0x00; // Disable Timer
			flag=0;
		}
	}
}
