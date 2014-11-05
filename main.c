#include "sys.h"
#include <string.h>

extern int write(char *,int);

void set2zero(char *ptr,int len);

void main()
{
while(1) {
int len = 0;
char str[255];
set2zero(str,255);
char *tmp = "INPUT STR::\t";
write(tmp,stringlen(tmp));
len = read(str,255);
write(str,len);
ms_delay(300);
}
}

void set2zero(char *ptr, int len) {
int i=0;
for(i=0;i<len;i++)
ptr[i]='\0';
}
