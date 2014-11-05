#include "sys.h"
#include <stdarg.h>
extern unsigned k_up_time;
extern void setup_timer();
void SYSTICK()
{
k_up_time++;
}


int SVC_WRITE(int *ptr, int svc_num)
{
int ret=0,len=0;
char *data= (char*)*(ptr);
len= *(ptr+1);
//putch(48+len);

switch(svc_num) {
case 2: put(data,len);break;

case 3: ret=get(data,len);
	*ptr = ret; /* Return value stored in r0 location in stack.
		     * It will be popped from stack and placed in RO after
		     * executing mov pc,lr
		     */
	break;

case 4: ms_delay((unsigned int) data);
	break;

default: ret=-1;
}
return ret;
}

