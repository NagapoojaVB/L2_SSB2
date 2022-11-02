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
#include "Byte1.h"
#include "BitsIoLdd1.h"
#include "Bit1.h"
#include "BitIoLdd1.h"
#include "Bit2.h"
#include "BitIoLdd2.h"
#include "Bit3.h"
#include "BitIoLdd3.h"
#include "Bit4.h"
#include "BitIoLdd4.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

void LLDD_Digital_Clock(void);
void LLDD(int a, int b, int c,int i);
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	
   
   
   //char ca[]={0xf9,0xa4,0xb0,0x99};
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
 
  /* Write your code here */
  /* For example: for(;;) { } */

  while(1)
  {
	  LLDD_Digital_Clock();
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

void LLDD_Digital_Clock()
{
	int i,a=0,b=0,c=0;
	
	for(a=0;a<6;a++)
	  {
		  
	   for(b=0;b<=9;b++)
	   {
		   
	    for(c=0;c<6;c++)
	    {
	      for(i=0;i<=9;i++)
	      {
	    	  LLDD(a,b,c,i);
	      	 }
	      
	    	}
	   	   }
	  	  }
}

void LLDD(int a, int b, int c,int i)
{
	int j,k;
	char ca[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	for(k=0;k<50;k++)
		{
		   Byte1_PutVal(ca[a]);
		   Bit1_ClrVal();
		   for(j=0;j<0xfff;j++);
		   Bit1_SetVal();
			 
		   Byte1_PutVal(ca[b]);
		   Bit2_ClrVal();
		   for(j=0;j<0xfff;j++);
		   Bit2_SetVal();
			
		   Byte1_PutVal(ca[c]);
		   Bit3_ClrVal();
		   for(j=0;j<0xfff;j++);
		   Bit3_SetVal();
			 
		   Byte1_PutVal(ca[i]);
		   Bit4_ClrVal();
		   for(j=0;j<0xfff;j++);
		   Bit4_SetVal();
			   
		    	  }
}


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
