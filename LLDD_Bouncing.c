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

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

void Water_Fall(int);         
void func(unsigned char);
void Reverse_Water_Fall(int );
void bouncing(void);
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
unsigned int o;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
 
  /* Write your code here */
  /* For example: for(;;) { } */
  while(1)
  {
   	 
	bouncing();
  
      for(o=0;o<0x1ffff;o++);
	
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

void bouncing()
{ 
	int g;
    int k;
	for(g=0x01;g<=0x80;g=g<<1)
	{
		Water_Fall(g);
		for(k=0;k<0x1ffff;k++);
		Reverse_Water_Fall(g);
	}
}
void Water_Fall(int p)
{
	int i;
	unsigned int j;
	for(i=p;i>=0x01;i=i>>1){
		func(i);
		for(j=0;j<0x1ffff;j++);
	}
		
}
	
void Reverse_Water_Fall(int p)
{
	int i;
	int j;
	for(i=0x01;i<=p;i=i<<1)
	{
		func(i);
		for(j=0;j<0x1ffff;j++);
	}
		
}
void func(unsigned char h)
{
	unsigned char a,c;
	a=h;
	a=~ a;
	a=a&0xf0;
	
	c=h&0x0f;
	h=a|c;
	Bits1_PutVal(h);
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