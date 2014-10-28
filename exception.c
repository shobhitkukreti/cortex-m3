#include "sys.h"

extern unsigned k_up_time;
extern void setup_timer();
void SYSTICK()
{
//put("ST ",4);
k_up_time++;
setup_timer();
}


int SVC_WRITE(char *ptr, int len)
{

int ret = put(ptr,len);
return ret;
}

