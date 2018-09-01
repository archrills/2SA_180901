#include "stm32f10x.h"
#include "led.h"


extern long  switch_number;
//extern unsigned char  run_flag; 

void phase_check_Init(void)
{
  
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

} 


void go_switch_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);	 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);
 
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

}
 
 
 void go_up_on(void)
 {
  

 go_forward_simple;
 
 }
 
 void go_down_on(void)
 {

 go_reverse_simple;

 }
 
 void stop(void)
 {
	 
 stop_forward_simple;

 }


 


