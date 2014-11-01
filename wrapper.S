.thumb
.syntax unified
.type write, %function

.equ WRITE_SWI,0x02
.equ READ_SWI,0x03
.equ EXIT,0x01
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
	
