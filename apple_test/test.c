#include<stdio.h>
#include<stdarg.h>
#include <stdint.h>

void main()
{
uint16_t buf=0x3,tmp=0x01;

int tmp1[50]={-1};

buf=buf<<8;
tmp|=buf;
printf("%x\n",tmp);
int i=0;

for(i=0;i<50;i++)
printf("%d\n",tmp1[i]);


}
