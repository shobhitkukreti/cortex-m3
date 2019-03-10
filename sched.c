#include "sys.h"
#include "reg.h"


// Kernel TCB

TCB *RUNQ;

int task_create(void *setup_ptr)
{
	int32_t i=0,n=0;
	int32_t *ptr = setup_ptr;
	int32_t r0 = *ptr; // register r0
	int32_t numOftask = *((int32_t*)setup_ptr+1); // register r1
	TASK_STRUCT task[numOftask];
	TCB *TCBList = &OS_TCB[0];
	TCB* tmp=RUNQ;
	for(i=0;i<numOftask;i++)
	{
		task[i] = *(TASK_STRUCT*)(r0+i);
		SetInitialStack(i);
		STACK[i][STACK_SIZE-2] = (int32_t)task[i].func;
		if(RUNQ==0){
			RUNQ = &TCBList[i];
			tmp = RUNQ;
		}
		tmp->next = &TCBList[i];
		tmp = tmp->next;
	}
	tmp->next=RUNQ;

	/*
		allocate_task(&task,numOftask);
		dispatch_init();
	*/
	return 0;
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

void SetInitialStack(uint8_t threadID){
	int i = threadID;
	TCB *TCBList = &OS_TCB[0];
	TCBList[i].sp = STACK[i][STACK_SIZE-16];
	STACK[i][STACK_SIZE-1] = 0; // thumb bit
	// r15 is program counter and is loaded with PC
	
	//Caller Saved
	STACK[i][STACK_SIZE-3] = 0; // r14 
	STACK[i][STACK_SIZE-4] = 0; // r12
	STACK[i][STACK_SIZE-5] = 0; // r3
	STACK[i][STACK_SIZE-6] = 0; // r2 
	STACK[i][STACK_SIZE-7] = 0; // r1
	STACK[i][STACK_SIZE-8] = 0; // r0

	//Callee Saved
	STACK[i][STACK_SIZE-9] = 0; // r11
	STACK[i][STACK_SIZE-10] = 0; // r10  
	STACK[i][STACK_SIZE-11] = 0; // r9
	STACK[i][STACK_SIZE-12] = 0; // r8
	STACK[i][STACK_SIZE-13] = 0; // r7
	STACK[i][STACK_SIZE-14] = 0; // r6
	STACK[i][STACK_SIZE-15] = 0; // r5
	STACK[i][STACK_SIZE-16] = 0; // r4

}

void idle_task()
{
	while(1) 
	{
		enable_interrupts();
	}

}


TCB *cur_tcb=0;
TCB *next_tcb=0;

inline TCB * get_cur_tcb() {
return cur_tcb;
}


/* Start with idle_task */

void dispatch_init()
{
	/*
		TCB *tcb = &OS_TCB;
		tcb[IDLE_PRIO].priority = IDLE_PRIO;
        tcb[IDLE_PRIO].C = 1;
        tcb[IDLE_PRIO].T = 1;
        tcb[IDLE_PRIO].e = 0;
        tcb[IDLE_PRIO].t = 0;
        tcb[IDLE_PRIO].sched_context.lr= &idle_task;
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

		cur_tcb = &tcb[IDLE_PRIO];	
		context_switch_half(&idle_task);
		*/
}




void dispatch()
{
/*
	uint8_t prio = next_highest_prio();
	TCB *prev = get_cur_tcb();
	TCB *next = &OS_TCB[prio];

	if(prio< tcb->prio) {
		remove_run_queue(next,prio);
		context_switch_full(prev,next)

	}
	*/
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
/*
	TCB *tcb = &OS_TCB;

	int i =0;
	for(i=0;i<num;i++)
	{
		pos = task[i].priority;
		tcb[pos].priority = task[i].priority;
		tcb[pos].C = task[i].C;
		tcb[pos].T = task[i].T;
		tcb[pos].e = 0;
		tcb[pos].t = 0;
		tcb[pos].sched_context.lr=task[i].func;
		tcb[pos].sched_context.sp=task[i].stack_ptr
		tcb[pos].sched_context.r4=0;
		tcb[pos].sched_context.r5=0;
		tcb[pos].sched_context.r6=0;
		tcb[pos].sched_context.r7=0;
		tcb[pos].sched_context.r8=0;
		tcb[pos].sched_context.r9=0;
		tcb[pos].sched_context.r10=0;
		tcb[pos].sched_context.r11=0;
		create_priority_table(&tcb[pos],tcb[pos].priority);
	}
*/
}
