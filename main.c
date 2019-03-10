#include <string.h>
#include "sched.h"
#include "sys.h"

#define TSTACK1 0x20007FFF
#define TSTACK2 0x20006FFF
void set2zero(char *ptr, int len);

void notmain() {
  while (1) {
    int len = 0;
    char str[255];
    set2zero(str, 255);
    char *tmp = "INPUT STR::\t";
    write("Hello\n\n\0", 7);
    write(tmp, stringlen(tmp));
    len = read(str, 255);
    write(str, len);
    ms_delay(300);
  }
}

void set2zero(char *ptr, int len) {
  int i = 0;
  for (i = 0; i < len; i++) ptr[i] = '\0';
}

void task1() {
  while (1) write("A ", 2);
}

void task2() {
  while (1) write("B ", 2);
}

void task3() {
  while (1) write("CD ", 2);
}

void main() {
  write("Hello RTOS\n\0", 14);
  TASK_STRUCT task[3];

  task[0].priority = 3;
  task[0].func = &task1;
  task[0].C = 1;
  task[0].T = 10;

  task[1].priority = 5;
  task[1].func = &task2;
  task[1].C = 2;
  task[1].T = 10;

  task[2].priority = 10;
  task[2].func = &task3;
  task[2].C = 5;
  task[2].T = 20;

  create_task(&task, 3);
  StartOS();

  /* It should not print DEADBEEF*/
  while (1) {
    write("DEADBEEF\0", 10);
  }
}
