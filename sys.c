#include "sys.h"

int put(char *ptr, int len) {
  int todo;
  for (todo = 0; todo < len; todo++) {
    UART_DR(UART0_ADDR) = *ptr++;
  }
  return len;
}


int get(char *ptr, int len) {
  int ret;
  if(len == 0)
    return 0;
  while(UART_FR(UART0_ADDR) & UART_FR_RXFE);
  *ptr++ = UART_DR(UART0_ADDR);
  for(ret = 1; ret < len; ret++) {
    if(UART_FR(UART0_ADDR) & UART_FR_RXFE) { break; }
    *ptr++ = UART_DR(UART0_ADDR);
  }
  return ret;
}

