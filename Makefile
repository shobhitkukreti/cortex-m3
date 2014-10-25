LD=arm-none-eabi-gcc -g -T linker.ld
CC=arm-none-eabi-gcc -g -mcpu=cortex-m3 -mthumb -mfix-cortex-m3-ldrd
OBJCOPY=arm-none-eabi-objcopy

CCFLAG=-mthumb -march=armv7 -mfix-cortex-m3-ldrd -T lm3s6965.ld
IFLAGS=-I../CMSIS/Include/
BCFLAG = $(LD)

all: test

output:main.o syscalls.o reset.o
	$(CC) $(CCFLAG) main.o syscalls.o reset.o -o main

main.o:main.c
	$(CC) -c main.c -o main.o

syscalls.o:syscalls.c
	$(CC) -c syscalls.c

reset.o:reset.S
	$(CC) -c reset.S

bin:
	$(OBJCOPY) -O binary main main.bin

startup.o:startup.S
	$(CC) -c startup.S -o startup.o

test:startup.o main.o
	$(LD) startup.o main.o -o main


clean: 
	rm -rf *o main *bin
