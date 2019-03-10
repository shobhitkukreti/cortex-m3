#include "sys.h"
#include "reg.h"


// Kernel TCB

TCB *RUNQ=&OS_TCB[0];

int task_create(void *setup_ptr)
{
	int32_t i=0,n=0;
	int32_t *ptr = (int32_t*)setup_ptr;
	TASK_STRUCT *task = (TASK_STRUCT*)(*ptr); // register r0
	int32_t numOftask = *((int32_t*)setup_ptr+1); // register r1
	//TASK_STRUCT task;
	TCB *TCBList = &OS_TCB[0];
	
//	for(i=0;i<numOftask;i++)
	{
	SetInitialStack(0);
	STACK[0][STACK_SIZE-2] = (int32_t)((task[0].func));
	TCBList[0].priority = task[0].priority;
	TCBList[0].C = task[0].C;
	TCBList[0].T = task[0].T;
	TCBList[0].next = &TCBList[1];
	SetInitialStack(1);
	STACK[1][STACK_SIZE-2] = (int32_t)((task[1].func));
	TCBList[1].priority = task[1].priority;
	TCBList[1].C = task[1].C;
	TCBList[1].T = task[1].T;
	TCBList[1].next = &TCBList[0];
		
	}
	

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
	TCBList[i].sp = (int32_t*)(STACK[i][STACK_SIZE-16]);
	asm("nop");
	int stackp = (int32_t)TCBList[i].sp;
	asm("nop");
	STACK[i][STACK_SIZE-1] = 0x1; // thumb bit
	// r15 is program counter and is loaded with PC
	
	//Caller Saved
	STACK[i][STACK_SIZE-3] = 0x3; // r14 
	STACK[i][STACK_SIZE-4] = 0x4; // r12
	STACK[i][STACK_SIZE-5] = 0x5; // r3
	STACK[i][STACK_SIZE-6] = 0x6; // r2 
	STACK[i][STACK_SIZE-7] = 0x7; // r1
	STACK[i][STACK_SIZE-8] = 0x8; // r0

	//Callee Saved
	STACK[i][STACK_SIZE-9] = 0x9; // r11
	STACK[i][STACK_SIZE-10] = 0x10; // r10  
	STACK[i][STACK_SIZE-11] = 0x11; // r9
	STACK[i][STACK_SIZE-12] = 0x12; // r8
	STACK[i][STACK_SIZE-13] = 0x13; // r7
	STACK[i][STACK_SIZE-14] = 0x14; // r6
	STACK[i][STACK_SIZE-15] = 0x15; // r5
	STACK[i][STACK_SIZE-16] = 0x16; // r4

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
