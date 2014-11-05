#ifndef SCHED_H_
#define SCHED_H_



typedef volatile struct _reg_context {
				unsigned int r4,r5,r6,r7,r8,r9,r10,r11,sp,lr;

}CONTEXT


typedef volatile struct _systcb_{
				unsigned int priority;
				CONTEXT sched_context;
				
}TCB;



typedef struct _task_struct {
				unsigned int priority;
				void *func;
				unsigned int C;
				unsigned int T;
				void *stack_ptr;
				
}TASK_STRUCT;





