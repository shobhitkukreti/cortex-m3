#ifndef SCHED_H_
#define SCHED_H_


#define KSTACK 0x2000FFFF
#define MAX_TASK 62
#define IDLE_PRIO 63


TCB * get_cur_tcb() {
return cur_tcb;

}

typedef volatile struct _reg_context {
				unsigned int r4,r5,r6,r7,r8,r9,r10,r11,sp,lr;

}CONTEXT;


typedef volatile struct _systcb_{
				unsigned int priority;
				CONTEXT sched_context;
				unsigned int C,T,e,t;
	
}TCB;

typedef struct _task_struct {
				unsigned int priority;
				void *func;
				unsigned int C;
				unsigned int T;
				void *stack_ptr;
				
}TASK_STRUCT;


unsigned char table[8]={0,0,0,0,0,0,0,0};
unsigned char run_bit=0;
TCB OS_TCB[MAX_TASK];

TCB *cur_tcb=NULL;
TCB *next_tcb=NULL;

#endif


