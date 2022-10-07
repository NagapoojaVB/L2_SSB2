/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-09-27, 16:45, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bits1.h"
#include "BitsIoLdd1.h"
#include "Bits2.h"
#include "BitsIoLdd2.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
void LLDD_CC_LED(unsigned char d);
void LLDD_CA_LED(unsigned char d);
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
   int j;
   unsigned char i,h;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
 
  /* Write your code here */
  /* For example: for(;;) { } */
  while(1)
  {
	  for(i=0x1;i<0xf;i=i<<1)
	  {
		  LLDD_CC_LED(i);
		  for(j=0;j<0x1ffff;j++); 
	  }
	  for(h=0x8;h>0;h=h>>1)
	  	  {
	  		  LLDD_CA_LED(h);
	  		  for(j=0;j<0x1ffff;j++);
	  		  
	  		  
	  	  }
	 
  }
 
 
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
void LLDD_CC_LED(unsigned char d)
{
	Bits1_PutVal(d);
}
void LLDD_CA_LED(unsigned char d)
{
	d=~d;
	Bits2_PutVal(d);
}
/*void Water_Fall(int n){
	int i,k;
	char arr[8]={0xf1,0xf2,0xf4,0xf8,0xe0,0xd0,0xb0,0x70};
	for(k=0;k<n;k++){
	Bits1_PutVal(arr[k]);
	for(i=0;i<0x1ffff;i++);
	}
}
	

void Reverse_Water_Fall(int n){
	int i,k;
   
	char a[8]={0x70,0xb0,0xd0,0xe0,0xf8,0xf4,0xf2,0xf1};
	for(k=8-n;k<8;k++){
		Bits1_PutVal(a[k]);
		for(i=0;i<0x1ffff;i++);
	}

	
}
*/
/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
