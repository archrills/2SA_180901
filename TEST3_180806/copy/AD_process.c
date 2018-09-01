#include "header.h"




unsigned int AD_convert(unsigned char channel)
{
   	
	
    unsigned  int ad_result;
	unsigned  int ad_h,ad_l;
  
  NOP();
  NOP();
  ADCSRA=(1<<ADEN)|(1<<ADIF)|(1<<ADPS1)|(1<<ADPS2);
  
  
  
  ADMUX=0Xc0;
  ADMUX|=channel;
  ADCSRA|=(1<<ADSC);
 
 while(!(ADCSRA&(1<<ADIF)));
 ADCSRA|=(1<<ADIF);
	
	
	ad_l=ADCL;
	ad_h=ADCH;

	ad_result=ad_h*256+ad_l;
	
	return ad_result;
	
}


 