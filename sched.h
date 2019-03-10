#ifndef SCHED_H_
#define SCHED_H_


#include<stdint.h>

#define KSTACK 0x2000FFFF
#define MAX_TASK 63
#define IDLE_PRIO 63
//#define NULL '\0'
#define STACK_SIZE 100

void SetInitialStack(uint8_t threadID);

typedef volatile struct _systcb_{
				int32_t *sp;
				unsigned int priority;
				unsigned int C,T,e,t;
				struct _systcb_ *next;
	
}TCB;

int32_t STACK[MAX_TASK+1][STACK_SIZE];

typedef struct _task_struct {
				void *func;
				unsigned int priority;
				unsigned int C;
				unsigned int T;

}TASK_STRUCT;


TCB OS_TCB[MAX_TASK];
TCB *run_list[MAX_TASK];
TCB *sleep_list[MAX_TASK];


void context_switch_full(TCB *prev, TCB *next);
void context_switch_half(TCB *tcb);
uint8_t next_highest_priority();
int task_create(void *setup_ptr);

#endif


