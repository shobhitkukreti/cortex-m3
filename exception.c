#include <stdarg.h>
#include "sched.h"
#include "sys.h"

extern unsigned k_up_time;
extern void setup_timer();
extern TCB *RUNQ;

void Scheduler(void) { RUNQ = RUNQ->next; }

void SYSTICK() {
  k_up_time++;
  Scheduler();
}

int C_SVC_Hndlr(void *ptr, int svc_num) {
  int ret = 0, len = 0;
  void *stck_loc = ptr;

  char *data = *(unsigned int *)(stck_loc);  // R0 on stack

  len = *(unsigned int *)(stck_loc + 1);  // R1 on stack

  switch (svc_num) {
    case 2:
      put(data, len);
      break;

    case 3:
      ret = get(data, len);
      *(int *)ptr = ret; /* Return value stored in r0 location in stack.
                    * It will be popped from stack and placed in RO after
                    * executing mov pc,lr
                    */
      break;

    case 4:
      ms_delay(*data);  // msdelay. Will cause problem since SYStick is not
                        // premepted by SVC and msdelay will never work for the
                        // time being.
      break;

    case 31:
      task_create((void *)stck_loc);
      setup_timer();
      break;

    default:
      ret = -1;
  }
  return ret;
}
