  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global  testFunc
  .extern dummy



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
 

 
   
   
