enum {
  UART_FR_RXFE = 0x10,
  UART_FR_TXFF = 0x20,
  UART0_ADDR = 0x4000C000,
};

#define UART_DR(baseaddr) (*(unsigned int *)(baseaddr))
#define UART_FR(baseaddr) (*(((unsigned int *)(baseaddr))+6))


int put(char *ptr, int len) {
  int todo;
  for (todo = 0; todo < len; todo++) {
    UART_DR(UART0_ADDR) = 'H';
  }
  return len;
}

