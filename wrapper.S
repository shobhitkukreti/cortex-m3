.thumb
.syntax unified
.type write, %function

.equ WRITE_SWI,0x03
.align 2
.section .text

.global write
.thumb_func
write:
	stmfd sp!,{r1-r3,lr} @ Caller Saved Registers
	svc #WRITE_SWI
	ldmfd sp!,{r1-r3,lr}
	mov pc,lr
