/*#include<W78E052.H>

void myISR_Ex0() interrupt 0
{
	int i;
	P0=!P0;
}
void myISR_Exl() interrupt 2
{
	int i;
	P1=!P1;
}
void main()
{
	int i;
	EX0=1;
	IT0=1;
	EX1=1;
	IT1=1;
	EA=1;
	while(1)
	{
		P2=0xf0;
		for(i=0;i<0x7fff;i++);
		P2=0x0f;
		for(i=0;i<0x7fff;i++);
	}
}	*/

#include<W78E052.H>
void myIsr_Ex0(void) interrupt 0
{
int i,j;
short sBitPosition;
for(sBitPosition=0x1; sBitPosition<=0x80; sBitPosition=sBitPosition<<1)
{
P0= sBitPosition ;
for(i=0; i<0x7FF; i++)
for(j=0; j<0x7FF; j++);
}


}
void myIsr_Exl(void) interrupt 2
{
int i,j;
short sBitPosition;
for(sBitPosition=0x1; sBitPosition<=0x80; sBitPosition=sBitPosition<<1)
{
P1= sBitPosition ;
for(i=0; i<0x7FF; i++)
for(j=0; j<0x7FF; j++);
}

}

void main()
{
int i;
EX0 = 1;
IT0 = 1;
EX1 = 1;
IT1 = 1;
PX1= 1;
EA = 1;

while(1)
{
P2= 0xF0;
for(i=0;i<0x7FFF;i++);
for(i=0;i<0x7FFF;i++);
P2=0x0F;
for(i=0;i<0x7FFF;i++);
for(i=0;i<0x7FFF;i++);
}
}
