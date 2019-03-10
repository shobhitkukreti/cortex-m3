LD=arm-none-eabi-gcc -g -T linker.ld
CC=arm-none-eabi-gcc -g3 -mcpu=cortex-m3 -mthumb -mfix-cortex-m3-ldrd
OBJCOPY=arm-none-eabi-objcopy

CCFLAG=-mthumb -march=armv7 -mfix-cortex-m3-ldrd -T lm3s6965.ld
IFLAGS=-I../CMSIS/Include/
BCFLAG = $(LD)

all: bin

main.o:main.c
	$(CC) -c main.c -o main.o

sys.o:sys.c exception.c
	$(CC) -c sys.c exception.c

bin: test
	$(OBJCOPY) -O binary main main.bin

kernel.o:kernel.c
	$(CC) -c kernel.c

wrapper.o:wrapper.S
	$(CC) -c -g wrapper.S

startup.o:startup.S
	$(CC) -c startup.S

sched.o:sched.c runqueue.c context_switch.c
	$(CC) -c sched.c runqueue.c context_switch.c

test:startup.o main.o sys.o wrapper.o kernel.o sched.o
	$(LD) sched.o sys.o exception.o startup.o wrapper.o kernel.o main.o -o main -specs=nosys.specs

clean: 
	rm -rf *o main *bin
