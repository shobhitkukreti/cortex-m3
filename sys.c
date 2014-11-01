#include "sys.h"
#include <stdarg.h>
#include <string.h>

int int2ascii(int num, char str[])
{
	int tmp=0, len=0;
	if(str!=NULL)
	{
		while(num!=0) {
			tmp=num%10;
			*str = 48+tmp;
			num=num/10;
		str++;
		len++;
		}
		str++;
		len++;
		*str = '\0';
	}
	return len;
}


void putch(char ch)
{
UART_DR(UART0_ADDR)=ch;
}

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





/*
void print(char *fmt,...)
{
	char num[256],len=0;
	va_list args;
	va_start(args,fmt);
	while(fmt!=NULL) {
		if(*fmt!='%'){
			putc(*fmt);
		}
		else{
			fmt++;
			switch(*fmt) {

				case 'd': len = int2ascii(va_arg(args,int),num);
					  put(num,len); break;

				case 'c': putc(va_arg(args,char)); break;
				case 's': put(va_arg(args,char*),strlen(va_arg(args,char *))); break;


			}

		}


	}
	va_end(args);
}
*/
