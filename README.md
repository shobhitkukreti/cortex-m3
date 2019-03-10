## Round Robin Scheduler OS for ARM Cortex-M3
======================================================================
### [Update] 10th March 2019
Finally got around to add some more code here. 

It is now a Bare Metal Round Robin Scheduler with a System Tick of 10 Msecs.

The Code Implements the following System Calls
1. Read
2. Write
3. Create Tasks

The created tasks use the system calls to read or write to the UART device.
In the current example there are two tasks where both print to console. 
At each system tick, the task pointer called RUNQ moves forward and next task is swapped in and it starts executing. 

Registers Saved in Stack When an Exception occurs

**Stack View During Interrupt**

SP+1C PSR
SP+18 PC
SP+14 LR
SP+10 R12
SP+C R3
SP+8 R2
SP+4 R1
SP   R0 -- > **Stack Pointer Location**

Further Work : Adding more scheduling policies. adding locks, etc. 

** This code is tested in December 2015, but is not a full RTOS system **

Implemented Startup Code, SVC Handler, SYSTICK Handler, Read/Write/Sleep System calls, Linker Script and it uses Qemu Serial terminal for I/O. It does not use any system library ( no newlib, linker has a config option -specs=nosys.spec), therefore no handy print statements are available :P ( welcome to bare metal code )



Unfortunately, I have not implemented kernel context switch or schedule, but the skeleton framework is there. 

Fixed some compilation issues in December 2015 which had escaped the compiler warnings/errors last year when I first started coding to explore SW on ARM Cortex M3 devices.


For GDB debugging:

append -s -S to qemu-system-arm in qemu.sh

execute arm-none-eabi-gdb
--> target remote localhost:1234
--> file main
