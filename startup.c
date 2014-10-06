#include<stdio.h>
#include <stdint.h>

extern unsigned int vTopOfRam;

extern int main(void);


void ResetISR(void);

__attribute__((section(".isrvectors")))
void *vecTable[] =
{
    &vTopOfRam,
    ResetISR
};

void ResetISR(void)
{
main();
while(1);
}
