#ifndef SYS_H_
#define SYS_H_

#include "sched.h"
#include "reg.h"


int stringlen(char *ptr);
int put(char *ptr, int len);
void putch(char ch);
int int2ascii(int num, char*str);
int get(char *ptr, int len);
void ms_delay(unsigned int msec);
void setup_timer();
void getch(char ch);

void enable_interrupts();
void disable_interrupts();


#endif
