#include "sys.h"
#include <string.h>


#define TSTACK1 0x20007FFF

#define TSTACK2 0x20006FFF

/*
void set2zero(char *ptr,int len);
void main()
{
	while(1) {
		int len = 0;
		char str[255];
		set2zero(str,255);
		char *tmp = "INPUT STR::\t";
		write(tmp,stringlen(tmp));
		len = read(str,255);
		write(str,len);
		ms_delay(300);
	}
}

void set2zero(char *ptr, int len) {
	int i=0;
	for(i=0;i<len;i++)
		ptr[i]='\0';
}
*/


void task1()
{
while(1)
putch('a');
}


void task2()
{
while(1)
putch('0');
}


void main()
{
TASK_STRUCT task[2];
task[0].priority=3;
task[0].func = &task1;
task[0].C=1;
task[0].T=10;
task[0].stack_ptr = (void *) TSTACK1;

task[1].priority=5;
task[1].func = &task2;
task[1].C=2;
task[1].T=10;
task[1].stack_ptr=(void *) TSTACK2;

create_task(&task,2);


/* It should not print DEADBEEF*/
while(1) {
put("DEADBEAF\n",10);
}
}
