cortex-m3
=========

** This code is tested in December 2015, but is not a full RTOS system **

Implemented Startup Code, SVC Handler, SYSTICK Handler, Read/Write/Sleep System calls, Linker Script and it uses Qemu Serial terminal for I/O. It does not use any system library ( no newlib, linker has a config option -specs=nosys.spec), therefore no handy print statements are available :P ( welcome to bare metal code )

Unfortunately, I have not implemented kernel context switch or schedule, but the skeleton framework is there. 

Fixed some compilation issues in December 2015 which had escaped the compiler warnings/errors last year when I first started coding to explore SW on ARM Cortex M3 devices.


For GDB debugging:

append -s -S to qemu-system-arm in qemu.sh

execute arm-none-eabi-gdb
--> target remote localhost:1234
--> file main
