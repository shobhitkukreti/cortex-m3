#include "sys.h"

extern unsigned k_up_time;
extern void setup_timer();
void SYSTICK()
{
k_up_time++;
}


int SVC_WRITE(char *ptr, int len)
{
int ret=0;
if(len==3)
	put("3\n",3);
else
	ret = put(ptr,len);
return ret;
}

