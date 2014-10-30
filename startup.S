.thumb
.syntax unified
.section .isrvectors
 .word  vTopRam                 /* Top of Stack                 */
 .word  Reset_Handler+1               /* Reset Handler                */
 .word  NMI_Handler+1                 /* NMI Handler                  */
 .word  HardFault_Handler+1           /* Hard Fault Handler           */
 .word  MemManage_Handler+1           /* MPU Fault Handler            */
 .word  BusFault_Handler+1            /* Bus Fault Handler            */
 .word  UsageFault_Handler+1          /* Usage Fault Handler          */
 .word  0                           /* Reserved                     */
 .word  0                           /* Reserved                     */
 .word  0                           /* Reserved                     */
 .word  0                           /* Reserved                     */
 .word  SVC_Handler+1                 /* SVCall Handler               */
 .word  DebugMon_Handler+1            /* Debug Monitor Handler        */
 .word  0                           /* Reserved                     */
 .word  PendSV_Handler+1              /* PendSV Handler               */
 .word  SysTick_Handler+1             /* SysTick Handler              */


.section .text

;.global __cs3_reset
.global Reset_Handler
.thumb_func
Reset_Handler:
  LDR R0, =__cs3_start_asm
  BX R0
 
.thumb_func
__cs3_start_asm:
  # add assembly initializations here
  LDR r0, =c_entry
  BX r0

.weak NMI_Handler
.thumb_func

NMI_Handler:
B	.

.weak HardFault_Handler
.thumb_func
HardFault_Handler:
B 	.


.weak MemManage_Handler
.thumb_func
MemManage_Handler:
B	.

.thumb_func
.weak BusFault_Handler
BusFault_Handler:
B	.

.thumb_func
.weak UsageFault_Handler
UsageFault_Handler:
B	.

.thumb_func:
.weak SVC_Handler
SVC_Handler:
stmfd sp!,{lr}
BL SVC_WRITE
ldmfd sp!,{lr}
MOV PC,LR


.thumb_func
.weak DebugMon_Handler
DebugMon_Handler:
B	.

.thumb_func
.weak PendSV_Handler
PendSV_Handler:
B	.


.thumb_func
.weak SYSTick_Handler
SysTick_Handler:
STMFD sp!,{lr}
BL SYSTICK 
LDMFD sp!,{lr}
mov PC,LR
.end
