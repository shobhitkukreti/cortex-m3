.thumb
.syntax unified
.section .isrvectors
 .word  vTopRam                 /* Top of Stack                 */
 .word  Reset_Handler+1               /* Reset Handler                */
 .word  NMI_Handler+1                 /* NMI Handler                  */
 .word  HardFault_Handler+1           /* Hard Fault Handler           */
 .word  MemManage_Handler+1           /* MPU Fault Handler            */
 .word  BusFault_Handler            /* Bus Fault Handler            */
 .word  UsageFault_Handler          /* Usage Fault Handler          */
 .word  0                           /* Reserved                     */
 .word  0                           /* Reserved                     */
 .word  0                           /* Reserved                     */
 .word  0                           /* Reserved                     */
 .word  SVC_Handler                 /* SVCall Handler               */
 .word  DebugMon_Handler            /* Debug Monitor Handler        */
 .word  0                           /* Reserved                     */
 .word  PendSV_Handler              /* PendSV Handler               */
 .word  SysTick_Handler             /* SysTick Handler              */


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
B	.

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
SUB SP,SP,#4
STR LR,[SP]
mov R12,SP
BL SYSTICK 
LDR LR,[SP]
ADD SP,SP,#4;
movs PC,LR
.end
