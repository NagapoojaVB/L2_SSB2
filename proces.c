#include <W78E052.H>
void myItsr_Ex0(void) interrupt 0
{
	int i,j;
	short sPos;
	for(sPos = 0x1; sPos <= 0x80; sPos=sPos<<1)
	{
	P0 = sPos;
	for(i=0; i<0x7ff; i++)
	for(j=0; j<0x7ff; j++);	
		
	}IE0=0;
}
void myItsr_Ex1(void) interrupt 2
{
	int i,j;
	short sPos;
	for(sPos = 0x1; sPos <= 0x80; sPos=sPos<<1)
	{
	P1 = sPos;
	for(i=0; i<0x7ff; i++)
	for(j=0; j<0x7ff; j++);	
	}
	
}

void main()
{
	short sPos=0x1;
	unsigned int i,j;
	EX0 = 1;  // enable external interrupt 1. p3.2
	IT0 = 1;
	EX1 = 1;  // enable external interrupt 1. p3.3
	IT1 = 1;   // 1: falling edge. 0: level edge
	EA = 1;    // enable all. to check the interrupt if available
	
	while(1)
	{
		P2 = sPos;
		
		for(i=0; i<0x7ff; i++)
		for(j=0; j<0x7ff; j++);
		P2 = ~sPos;
		for(i=0; i<0x7ff; i++)
		for(j=0; j<0x7ff;j++);
	}
}