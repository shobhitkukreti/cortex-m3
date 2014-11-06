#ifndef SYS_H_
#define SYS_H_

#include "sched.h"


enum {
  UART_FR_RXFE = 0x10,
  UART_FR_TXFF = 0x20,
  UART_FR_RXFF = 0x40,
  UART_RF_TXFE = 0x80,
  UART0_ADDR = 0x4000C000,
};

#define UART_DR(baseaddr) (*(volatile unsigned int *)(baseaddr))
#define UART_FR(baseaddr) (*(((volatile unsigned int *)(baseaddr))+6))

int stringlen(char *ptr);
int put(char *ptr, int len);
void putch(char ch);
int int2ascii(int num, char*str);
int get(char *ptr, int len);
void ms_delay(unsigned int msec);
void setup_timer();
void getch(char ch);

#endif
