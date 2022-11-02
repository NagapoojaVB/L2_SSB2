#include<W87E052.h>

#define BAUD_RATE_9600 0xFD


void SerialInitialize(void);
void SendByteSerially(unsigned char ascii);
unsigned char RecieveByteSerially(void);

void main(void)
{
	unsigned char serialdata;
	SerialInitialize();

	for(;;)
	{
		serialdata = RecieveByteSerially();
		SendByteSerially(serialdata);
	}
}

void SerialInitialize(void)
{
TMOD = ((TMOD & 0x0F) | 0x20);
SCON = 0x50;
TH1= BAUD_RATE_9600;
TR1 = 1;
}

void SendByteSerially(unsigned char serialdata)
{
SBUF = serialdata;
while(TI == 0);
TI = 0;
}

unsigned char RecieveByteSerially(void)
{
while(RI ==0);
RI = 0;
return SBUF;
}