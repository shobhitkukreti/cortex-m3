.thumb
.syntax unified
.type write, %function

.equ WRITE_SWI,0x02
.equ READ_SWI,0x03
.equ EXIT,0x01
.equ SLEEP, 0x04
.equ TASK_CREATE, 0x1F

.align 2
.section .text

.global write
.thumb_func
write:
	stmfd sp!,{lr} @ Caller Saved Registers
	svc #WRITE_SWI
	ldmfd sp!,{lr}
	mov pc,lr

.global read
.thumb_func
read:
	stmfd sp!,{lr}
	SVC #READ_SWI
	ldmfd sp!,{lr}
	mov pc,lr

.global sleep
.thumb_func
sleep:
	stmfd sp!,{lr}
	SVC #SLEEP
	ldmfd sp!,{lr}
	mov pc,lr

.global create_task
.thumb_func

create_task:
	SVC #TASK_CREATE
	
