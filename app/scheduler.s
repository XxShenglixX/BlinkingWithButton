  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global taskswitch
  .global SysTick_Handler

    .section  .text.Dummy
  .type  taskswitch, %function
taskswitch:
	ldr r0,		=#0x11111111
	ldr r1,		=#0x22222222
	ldr r2,		=#0x33333333
	ldr r3,		=#0x44444444
	ldr r4,		=#0x55555555
	ldr r5,		=#0x66666666
	ldr lr,		=#0xABCDEFFF
	ldr r12,	=#0xCCCCCCCC

	b		.

	.align 8
	.type SysTick_Handler, %function
SysTick_Handler:
	push {r7, lr}
	add r7, sp, #0
	bl HAL_IncTick
	pop {r7,pc}
