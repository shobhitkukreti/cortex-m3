.thumb
.syntax unified
.type write, %function

.equ WRITE_SWI,0x03
.align 2
.section .text

.global write
.thumb_func
write:
	stmfd sp!,{lr} @ Caller Saved Registers
	svc #WRITE_SWI
	ldmfd sp!,{lr}
	ldr r0, =0xDEADBEEF
	mov pc,lr
