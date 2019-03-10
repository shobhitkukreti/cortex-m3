#include "sys.h"
#include "reg.h"


unsigned int k_up_time=0;

// Setup Timer and start user application
int c_entry() {
	SVC_PRIO(0x06);
	main();
	return 0;
}


void setup_timer ()
{
	STRELOAD = 0x7A120; // 10 msec tick @ 50MHz
	TICK_PRIO(0x07);
	STCTRL = 0x7; // Enables the timer/interrupt after loading the value
}


void ms_delay(unsigned int msec)
{
	unsigned int delay = (msec/10);
	int val = k_up_time;
	if(delay>0) {
		while(k_up_time < (val + delay));
	}
}

