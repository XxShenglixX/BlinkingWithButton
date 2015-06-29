  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global  testFunc
  .global taskswitch
  .global SysTick_Handler
  .extern dummy

.equ TCB_NAME,0
.equ TCB_SP,4

/*
  .section  .text.testFunc
  .type  testFunc, %function
testFunc: 
  movs r0,#0x12 //move 0x12 to r0
  movs r1,#0x34
  movs r2,#0x56
  ldr  r3, = #0x1234face
  push {r1,r0}
  stmdb sp!,{r1,r2,r3}
  pop  {r0,r1}
  ldmia sp!,{r1,r2,r3}
  movw.w r4,0x1234
  movt.w r4,0xface
  push {lr} //backup link register
  movs r0,#12 // pass in 12 to dummmy(value)
  bl dummy
  pop {lr}


  bx  lr
 */
     .section  .text.taskswitch
  .type  taskswitch, %function
taskswitch:
	ldr r0,		=#0x11111111
	ldr r1,		=#0x22222222
	ldr r2,		=#0x33333333
	ldr r3,		=#0x44444444
	ldr r4,		=#0x55555555
	ldr r5,		=#0x66666666
	ldr r6,		=#0x77777777
	ldr r7,		=#0x88888888
	ldr r8,		=#0x99999999
	ldr r9,		=#0xAAAAAAAA
	ldr r10,	=#0xBBBBBBBB
	ldr r11,	=#0xCCCCCCCC
	ldr r12,	=#0xDDDDDDDD
	ldr lr,		=#0xABCDEFFF
	push {r0}

	b		.

	.align 8
	.type SysTick_Handler, %function
SysTick_Handler:

/*Task switching mechanism*/



// 1) Push the rest of register
// 2) Let R0 points to mainTCB
// 3) Store the current SP into mainTcb.sp (through R0) //str r1[r0,#TCB_SP] or ldr r1,[r0,#8]
// 4) Let R0 points to taskOneTcb
// 5) Load taskOneTcb(throught R0) into current SP
// 6) return from interrupt

	stmdb sp!, {r4-r11}
//	push {r7, lr}
//	add r7, sp, #0
//	bl HAL_IncTick
//	pop {r7,pc}


 	b	.
   
   
