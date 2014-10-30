#include "sys.h"

extern int write(char *,int);

void main()
{
while(1) {
write("AAA\n",5);
ms_delay(1000);
}
}
