#include <W78E052.H>
#define TIMER0_VALUE_10mSec 0xd00
#define TIMER0_H ((TIMER0_VALUE_10mSec & 0xff00)>>8)
#define TIMER0_L (TIMER0_VALUE_10mSec & 0xff00)

#define LED P10
void timer_interrupt () interrupt 1
{
	static int i=0;
	static short spos=0x01;	
	TL0 = TIMER0_L;
	TH0 = TIMER0_H;
	/*loop for 100*10msec=1000msec/1sec */
	if(i>=300 &&  spos<= 0x80)
	{
	   //LED = ~LED;
		 //for(; spos<= 0x80; spos=spos<<1)
		    
			P0=spos;
			//for(i=0; i<0x7ff; i++)
		   //for(j=0; j<0x7ff; j++);
	     //}
		  spos=spos<<1;
		  i=0;
	  if(spos>0x80)
		{
			spos=0x01;
		}
			
	}
	else
	{
		i++;
	//	spos=spos<<1;
	}
	
  
}
void timer1_interrupt () interrupt 3
{
	static int i=0;
	static short spos=0x01;	
	TL1 = TIMER0_L;
	TH1 = TIMER0_H;
	/*loop for 100*10msec=1000msec/1sec */
	if(i>=450 &&  spos<= 0x80)
	{
	   //LED = ~LED;
		 //for(; spos<= 0x80; spos=spos<<1)
		    
			P1=spos;
			//for(i=0; i<0x7ff; i++)
		   //for(j=0; j<0x7ff; j++);
	     //}
		  spos=spos<<1;
		  i=0;
	  if(spos>0x80)
		{
			spos=0x01;
		}
			
	}
	else
	{
		i++;
	//	spos=spos<<1;
	}
	
  
}

void main()
{
	int i , j;
  short spos;	
	TMOD= 0X01;
	EA=1;
	TH0= TIMER0_H;
	TL0 = TIMER0_L;
	ET0= 1;
	TR0 = 1;
	TH1= TIMER0_H;
	TL1 = TIMER0_L;
	ET1= 1;
	TR1 = 1;
	while(1)
	{
		 for(spos=0x01; spos<= 0x80; spos=spos<<1)
		{
			P2=spos;
			for(i=0; i<0x7ff; i++)
 		   for(j=0; j<0x7ff; j++);
	  }
      
  }
}