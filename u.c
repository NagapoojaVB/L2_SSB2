#include<W78E052.h>

#define BAUD_RATE_9600 0xFD

void main(void);
void SerialInitialize(void);

void RecieveByteSerially(void) interrupt 4
{
	if(TI==1)
	{
		
		TI=0;
	}
	if(RI==1)
	{
		
	  RI = 0;
		SBUF='e';
	}
	
}

void main(void)
{
	EA = 1;
  ES=1;
	SerialInitialize();
	

	for(;;)
	{
	   ;
	}
}

void SerialInitialize(void)
{
TMOD = ((TMOD & 0x0F) | 0x20);
SCON = 0x50;
TH1= BAUD_RATE_9600;
TR1 = 1;
}

