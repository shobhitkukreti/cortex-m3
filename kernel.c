#include "sys.h"
#include "reg.h"


unsigned k_up_time=0;
void setup_timer();


// Setup Timer and start user application
int c_entry() {
setup_timer();

main();
return 0;
}


void setup_timer ()
{
//STRELOAD = 0x7A120; // 10 msec tick @ 50MHz
STRELOAD = 0xFFFF;
STCTRL = 0x7; // Enables the timer/interrupt after loading the value
}


void ms_delay(unsigned int msec)
{
unsigned int delay = (msec/10);
while(k_up_time < (k_up_time + delay));
}
