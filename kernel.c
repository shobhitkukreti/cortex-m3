#include "sys.h"
#include "reg.h"


unsigned int k_up_time=0;
void setup_timer();


// Setup Timer and start user application
int c_entry() {
k_up_time=0;

unsigned mask = 0x1FFFFFFF;
unsigned read=0;
read = SYSPRI2;
read &=mask;
mask = (0x06)<<28;
read |=mask;
SYSPRI2 = read;
setup_timer();
main();
return 0;
}


void setup_timer ()
{
STRELOAD = 0x7A120; // 10 msec tick @ 50MHz

unsigned int mask = 0x1FFFFFFF;
unsigned int read=0;
read = SYSPRI3;
read &=mask;
mask = (0x07)<<28;
read |=mask;
SYSPRI3=read;
STRELOAD = 0xFFFF;
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

