#include "sys.h"
#include "reg.h"


// Kernel TCB

int task_create(void *setup_ptr)
{
int i=0,n=0;
int *ptr = setup_ptr;
int r0 = *ptr;
int numOftask = *(setup_ptr+1);

TASK_STRUCT task[numOftask];



for(i=0;i<numOftask;i++)
{
task[i] = *(r0+i);
}

	for (n=0;n<numOftask;n++){
		create_priority_table(task[i].priority);
	}
	allocate_task(&task,numOftask);

	dispatch_init();
}

/*
void create_priority_table(unsigned int priority)
{
	int table_index = priority/8;
	int bit_index = priority%8;
	table[table_index]| = 1<<bit_index
		run_bit|= 1<<bit_index;
}
*/



void idle_task()
{
	while(1) 
	{
		enable_interrupts();
	}

}


/* Start with idle_task */

void dispatch_init()
{


		tcb[IDLE_PRIO].priority = IDLE_PRIO;
                tcb[IDLE_PRIO].C = 1;
                tcb[IDLE_PRIO].T = 1;
                tcb[IDLE_PRIO].e = 0;
                tcb[IDLE_PRIO].t = 0;
                tcb[IDLE_PRIO].sched_context.lr= &idle_task
                tcb[IDLE_PRIO].sched_context.sp=KSTACK; // Will not be used
                tcb[IDLE_PRIO].sched_context.r4=0;
                tcb[IDLE_PRIO].sched_context.r5=0;
                tcb[IDLE_PRIO].sched_context.r6=0;
                tcb[IDLE_PRIO].sched_context.r7=0;
                tcb[IDLE_PRIO].sched_context.r8=0;
                tcb[IDLE_PRIO].sched_context.r9=0;
                tcb[IDLE_PRIO].sched_context.r10=0;
                tcb[IDLE_PRIO].sched_context.r11=0;
		create_priority_table(IDLE_PRIO); // Set up idle task

		cur_tcb = tcb[IDLE_PRIO];	
		context_switch_half(&idle_task);


}


void dispatch()
{

TCB *tcb;

}


void enable_interrupts()
{
	asm volatile ( "CPSIE i");
}

void disable_interrupts()
{
	asm volatile ("CPSID i");
}


void allocate_task(int *task, int num)
{
	TCB *tcb = OS_TCB;

	int i =0;
	for(i=0;i<num;i++)
	{
		tcb[i].priority = task[i].priority;
		tcb[i].C = task[i].C;
		tcb[i].T = task[i].T;
		tcb[i].e = 0;
		tcb[i].t = 0;
		tcb[i].sched_context.lr=task[i].func;
		tcb[i].sched_context.sp=task[i].stack_ptr
		tcb[i].sched_context.r4=0;
		tcb[i].sched_context.r5=0;
		tcb[i].sched_context.r6=0;
		tcb[i].sched_context.r7=0;
		tcb[i].sched_context.r8=0;
		tcb[i].sched_context.r9=0;
		tcb[i].sched_context.r10=0;
		tcb[i].sched_context.r11=0;
	}
}
