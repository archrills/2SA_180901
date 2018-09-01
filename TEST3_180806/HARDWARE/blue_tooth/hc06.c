#include "delay.h" 			 
#include "usart.h" 			 
#include "led.h" 
#include "string.h"	 
#include "math.h"
#include "header.h"
#include "variable.h"

extern unsigned char TEXT_Buffer[262];
extern unsigned int at1_array[40];
extern unsigned char at_array[2];	
extern unsigned char Bluetooth_AT,Bluetooth_NAME;
extern unsigned char temp1,temp2;
char retry4=5,retry3=3;
extern u32 ChipUniqueID[3];
void Get_ChipID(void)
{
    //u32 ChipUniqueID[3];
    ChipUniqueID[2] = *(__IO u32*)(0X1FFFF7E8);  
    ChipUniqueID[1] = *(__IO u32 *)(0X1FFFF7EC); 
    ChipUniqueID[0] = *(__IO u32 *)(0X1FFFF7F0); 
}



void HC06_AT(void)
{

  u8 i;
  //u8 retry=0X0F;
 	
	
  temp1=1;
  
	GpuSend4("DS48(0,0,'³õÊ¼»¯£¬ÇëµÈ´ý£¡',0,0);\r\n");
	
	 at_array[0]='A';
   at_array[1]='T';
	
  while(retry3--)
  {
    for(i=0;i<=1;i++)
	{
	  while((UART5->SR&0X40)==0);
		UART5->DR=at_array[i];
	  
	}
	delay_ms(1000);		   

  }
 

}


void HC06_changename(void)
{
  
  u8 i;
   
	Get_ChipID();
  GpuSend4("DS48(0,50,'please waiting£¡',0,0);\r\n");
   
   at1_array[0]='A';
   at1_array[1]='T';
   at1_array[2]='+'; 
   at1_array[3]='N';
   at1_array[4]='A';
   at1_array[5]='M';
   at1_array[6]='E';

   at1_array[7]='S';
   at1_array[8]='U';
   at1_array[9]='R';
   at1_array[10]='P';
   at1_array[11]='A';
   at1_array[12]='S';
   at1_array[13]='S';
   at1_array[14]='_';
	 
   at1_array[15]=ChipUniqueID[0]%256;
   at1_array[16]=ChipUniqueID[0]/256;
   at1_array[17]=ChipUniqueID[1]%256;
   at1_array[18]=ChipUniqueID[1]/256;
   at1_array[19]=ChipUniqueID[2]%256;
   at1_array[20]=ChipUniqueID[2]/256;

  while(retry4--)
  {
  
							for(i=0;i<=20;i++)
						{
							
							
							while((UART5->SR&0X40)==0);
							UART5->DR=at1_array[i];
						}
						delay_ms(1000);	
	          
 
 }
}


 void bluetooth_Init(void)
{
 HC06_AT();
 HC06_changename();

}




