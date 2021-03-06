#include "reg.h"
#include "sys.h"

/*********
*** Stack View During Interrupt ***

SP+1C PSR
SP+18 PC
SP+14 LR
SP+10 R12
SP+C R3
SP+8 R2
SP+4 R1
SP   R0 -- > Stack Pointer Location
**********/

// Kernel TCB

volatile TCB *RUNQ;
int task_create(void *setup_ptr) {
  int32_t i = 0, n = 0;
  int32_t *ptr = (int32_t *)setup_ptr;
  TASK_STRUCT *task = (TASK_STRUCT *)(*ptr);        // register r0
  int32_t numOftask = *((int32_t *)setup_ptr + 1);  // register r1
  // TASK_STRUCT task;
  TCB *TCBList = &OS_TCB[0];

  for (i = 0; i < numOftask; i++) {
    SetInitialStack(i);
    // save func value in both PC and LR Registers Initially
    STACK[i][STACK_SIZE - 2] = (int32_t)((task[i].func));
    STACK[i][STACK_SIZE - 3] = (int32_t)((task[i].func));
    TCBList[i].priority = task[i].priority;
    TCBList[i].C = task[i].C;
    TCBList[i].T = task[i].T;
    TCBList[i].next = &TCBList[i + 1];
  }
  RUNQ = &TCBList[0];
  // make run queue circular by going to last
  // valid task block and setting next to RUNQ
  TCBList[i - 1].next = RUNQ;
  return 0;
}

void SetInitialStack(uint8_t i) {
  TCB *TCBList = &OS_TCB[0];
  TCBList[i].sp = (int32_t *)&(STACK[i][STACK_SIZE - 16]);
  STACK[i][STACK_SIZE - 1] = 0x01000000;  // set thumb bit xpsr
  // r15 is program counter and is loaded with PC

  // Caller Saved
  // STACK[i][STACK_SIZE-3] = 0x3; // r14 //link register
  STACK[i][STACK_SIZE - 4] = 0x4;  // r12
  STACK[i][STACK_SIZE - 5] = 0x5;  // r3
  STACK[i][STACK_SIZE - 6] = 0x6;  // r2
  STACK[i][STACK_SIZE - 7] = 0x7;  // r1
  STACK[i][STACK_SIZE - 8] = 0x8;  // r0

  // Callee Saved
  STACK[i][STACK_SIZE - 9] = 0x9;    // r11
  STACK[i][STACK_SIZE - 10] = 0x10;  // r10
  STACK[i][STACK_SIZE - 11] = 0x11;  // r9
  STACK[i][STACK_SIZE - 12] = 0x12;  // r8
  STACK[i][STACK_SIZE - 13] = 0x13;  // r7
  STACK[i][STACK_SIZE - 14] = 0x14;  // r6
  STACK[i][STACK_SIZE - 15] = 0x15;  // r5
  STACK[i][STACK_SIZE - 16] = 0x16;  // r4
}

void idle_task() {
  while (1) {
    enable_interrupts();
  }
}

TCB *cur_tcb = 0;
TCB *next_tcb = 0;

inline TCB *get_cur_tcb()
{
  return cur_tcb;
}


/* Start with idle_task */
// [TODO]
void dispatch_init()
{}

// [TODO]
void dispatch()
{}

inline void enable_interrupts()
{ 
  asm volatile("CPSIE i");
}

inline void disable_interrupts(){
  asm volatile("CPSID i");
}

// [TODO]
void allocate_task(int *task, int num)
{}
