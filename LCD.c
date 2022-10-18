/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-13, 09:42, # CodeGen: 0
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
#include "LCD_DATA_CMD_PINS.h"
#include "BitsIoLdd1.h"
#include "LCD_REG_SELECT.h"
#include "BitIoLdd1.h"
#include "LCD_READ_WRITE.h"
#include "BitIoLdd2.h"
#include "LCD_ENABLE.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

void LCD_DELAY(unsigned char ms);
void LCD_COMMAND(unsigned char command);
void LCD_DATA(unsigned char ASCII);
void LCD_puts(unsigned char *lcd_string);
void LCD_INIT();
void LCD_TESTINGAPP();
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  LCD_TESTINGAPP();
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
void LCD_DELAY(unsigned char ms)
{
	unsigned char n;
	unsigned int i;
	for(n=0;n<ms;n++)
		for(i=0;i<0x7fff;i++);
}

void LCD_COMMAND(unsigned char command)
{
	LCD_DATA_CMD_PINS_PutVal(command);
	LCD_REG_SELECT_PutVal(0);
	LCD_READ_WRITE_PutVal(0);
	LCD_ENABLE_PutVal(1);
	LCD_DELAY(1);
	LCD_ENABLE_PutVal(0);
}

void LCD_DATA(unsigned char ASCII)
{
	LCD_DATA_CMD_PINS_PutVal(ASCII);
	LCD_REG_SELECT_PutVal(1);
	LCD_READ_WRITE_PutVal(0);
	LCD_ENABLE_PutVal(1);
	LCD_DELAY(1);
	LCD_ENABLE_PutVal(0);
}
void LCD_puts(unsigned char *lcd_string)
{
	int k=0;
	while(*lcd_string)
	{  
		k++;
		LCD_DATA(*lcd_string++);
		if(k==16)
		{
			LCD_COMMAND(0xc0);
		}
		
	}
}

void LCD_INIT()
{
	LCD_COMMAND(0x38);
	LCD_COMMAND(0x0f);
	LCD_COMMAND(0x06);
	LCD_COMMAND(0x01);
	LCD_COMMAND(0x80);
	LCD_DELAY(1);
}

void LCD_TESTINGAPP()
{
	LCD_INIT();
	//LCD_DATA(75);
	LCD_puts("Modi");
	LCD_DATA(' ');
	LCD_puts("Jai");
	LCD_COMMAND(0x06);
	LCD_COMMAND(0xc0);
	LCD_COMMAND(0xc);
	LCD_puts("NAMO For 24");
	while(1);
}
