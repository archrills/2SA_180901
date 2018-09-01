#include "header.h"
 
 
 





 void sendBYTE(unsigned char dat)/*?????????*/
{      
      unsigned char i;
	  
	  
	  for (i=0;i<8;i++)
      {
         

          clock_off; 
		  delay_short(20);
		  if ((dat & 0x80)!=0)
          data_h;
          else 
          data_l;
          clock_on;
		  delay_short(20);
		  dat = dat<<1;
      }
     
     
}





void sendCMD(unsigned char dat)/*?????*/
{
      
      sendBYTE(0xf8);       //??????:???
      
	  sendBYTE(dat & 0xf0);     //??????
      
	  sendBYTE((dat<<4)&0xf0);  //??????
      
}



void sendDAT(unsigned char dat)/*?????;???????????*/
{
      
      sendBYTE(0xfa);   //??????:?????
      
	  sendBYTE(dat & 0xf0);  //??????
      
	  sendBYTE((dat<<4)&0xf0); //??????
      
}


void display_alarm(void)
{


}


  void display_chinese_letter(unsigned char x_add,unsigned char *p)
/*????LCD?????*/
/*x_add ??RAM??*/
/*dat/dat1 ??????*/
{                                                                                                                                                                                                                                                           
      sendCMD(x_add);
      
	  
	  
      while(*p!=0)
	 {
	  sendDAT(*(p++));
     } 
	  
}


void display_address(unsigned char x_add)
 {
   if(language_register==0)
   { 
	sendCMD(x_add);
	sendDAT(0x18);
	sendDAT(0x19);
   }
 }


 void display_percent_point(unsigned char x_add,unsigned char bit1,unsigned char point)
 {
    sendCMD(x_add);
	sendDAT(bit1+0x30);
	sendDAT(0x2e);
	sendDAT(point+0x30);
	sendDAT(0x25);
 
 }

 void display_percent_count_every_bit(unsigned char x_add,unsigned int data)
 {
    unsigned char a,b,c;
	 a=data%1000/100;
	 b=data%100/10;
	 c=data%10;
     display_percent(x_add,a,b,c);
	 
 }
 
 void display_every_bit_current(unsigned char x_add,unsigned int data)
 {
    
	   unsigned char a,b,c,d,e;
	 
	 b=data/1000;
	 c=data%1000/100;
	 d=data%100/10;
	 e=data%10;
	    sendCMD(x_add);
		sendDAT(0x20);
		sendDAT(0x20);
    	if(b==0)
		sendDAT(0x20);
		else
		sendDAT(b+0x30);
		
		if(c==0)
		sendDAT(0x20);
		else
		sendDAT(c+0x30);
		
    	sendDAT(d+0x30);
		sendDAT(0x2e);
    	sendDAT(e+0x30);
        sendDAT('A');
	 
 }
 
 
 void display_every_bit(unsigned char x_add,unsigned int data)
 {
    
	   unsigned char a,b,c,d,e;
	 a=data/10000;
	 b=data%10000/1000;
	 c=data%1000/100;
	 d=data%100/10;
	 e=data%10;
	    sendCMD(x_add);
    	sendDAT(a+0x30);
    	sendDAT(b+0x30);
    	sendDAT(c+0x30);
    	sendDAT(d+0x30);
    	sendDAT(e+0x30);
        sendDAT(0x20);
	 
 }

 void display_four_bit(unsigned char x_add,unsigned int data)
 {
    
	   unsigned char a,b,c,d,e;
	 
	 b=data/1000;
	 c=data%1000/100;
	 d=data%100/10;
	 e=data%10;
	    sendCMD(x_add);
    	sendDAT(b+0x30);
    	sendDAT(c+0x30);
    	sendDAT(d+0x30);
    	sendDAT(e+0x30);
     
	 
 }
 
 void display_three_bit(unsigned char x_add,unsigned int data)
 {
    
	   unsigned char a,b,c;
	 
	 
	 a=data/100;
	 b=data%100/10;
	 c=data%10;
	    sendCMD(x_add);
    	sendDAT(a+0x30);
    	sendDAT(b+0x30);
    	sendDAT(c+0x30);
    	
     
	 
 }
 
  void display_two_bit(unsigned char x_add,unsigned char data)
 {
    
	   unsigned char a,b,c,d,e;
	 
	 b=data/10;
	 e=data%10;
	    sendCMD(x_add);
    	sendDAT(b+0x30);
    	sendDAT(e+0x30);
    	
     
	 
 }
 
 
 void display_percent_small(unsigned char x_add,unsigned char hun,unsigned char ten,unsigned char bit1,unsigned char small)
 {
 	sendCMD(x_add);
	sendDAT(hun+0x30);
	sendDAT(ten+0x30);
	sendDAT(bit1+0x30);
	sendDAT(0x2e);
	sendDAT(small+0x30);
	sendDAT(0x25);
 
 
 }
 

 
  void display_percent(unsigned char x_add,unsigned char hun,unsigned char ten,unsigned char bit1)
 {
 	sendCMD(x_add);
	sendDAT(hun+0x30);
	sendDAT(ten+0x30);
	sendDAT(bit1+0x30);
	sendDAT(0x25);
 
 
 }

 void display_number_3_new(unsigned char x_add,unsigned char num0,unsigned char num1,unsigned char num2)
{
   sendCMD(x_add);
   sendDAT(num0+0x30);
   sendDAT(num1+0x30);
   sendDAT('.');
   sendDAT(num2+0x30);
   
} 
 
 
void display_number_3(unsigned char x_add,unsigned char num0,unsigned char num1,unsigned char num2)
{
   sendCMD(x_add);
   sendDAT(num0+0x30);
   sendDAT(num1+0x30);
   sendDAT(num2+0x30);
   
} 

void display_number_4(unsigned char x_add,unsigned char num0,unsigned char num1,unsigned char num2,unsigned char num3)
{
   sendCMD(x_add);
   sendDAT(num0+0x30);
   sendDAT(num1+0x30);
   sendDAT(num2+0x30);
   sendDAT(num3+0x30);
} 

void display_number(unsigned char x_add,unsigned char num1,unsigned char num2)
{
   sendCMD(x_add);
   sendDAT(num1+0x30);
   sendDAT(num2+0x30);

} 

void initlcm(void)/*???LCM*/
{     
      sendCMD(0x30);/*????:???8???,?????*/
      
	  sendCMD(0x06);/*???:????/????????,DDRAM????*/
      
	  sendCMD(0x0c);/*????:???,?????,??????????*/
      
	  sendCMD(0x01);/*?DDRAM*/
      
	  sendCMD(0x02);/*DDRAM????*/
	  
	  
	  
	  delay_short(5000);
      
	 
	  sendCMD(0x80);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
      sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
      
	  sendCMD(0x90);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
      sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);


}

void initlcm_reverse(void)/*???LCM*/
{     
      sendCMD(0x30);/*????:???8???,?????*/
      
	  sendCMD(0x05);/*???:????/????????,DDRAM????*/
      
	  
	  
	  sendCMD(0x0f);/*????:???,?????,??????????*/
      
	  sendCMD(0x14);
	  
	  sendCMD(0x01);/*?DDRAM*/
      
	  sendCMD(0x02);/*DDRAM????*/
	  
	  delay_short(5000);
      
	 
	  sendCMD(0x80);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
      sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
      
	  sendCMD(0x90);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
      sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);
	  sendDAT(0x20);


}

