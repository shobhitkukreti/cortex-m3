/** Wrapper Class for Read and Write SysCalls.
** Calls SVC 
**/



.thumb
.syntax unified


.equ WRITE_SWI,0x03

.section text
.global write
.thumb_func

write:
	stmfd sp!,{r1-r3} @ Caller Saved Registers
	svc WRITE_SWI
	ldmfd sp!,{r1-r3}
	mov pc,lr
