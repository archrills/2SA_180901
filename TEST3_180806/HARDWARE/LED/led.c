#include "led.h"



void LED_Init(void)
{
 
  GPIO_InitTypeDef  GPIO_InitStructure;


  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//关闭jtag，保留swd。
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_ResetBits(GPIOA,GPIO_Pin_15);	

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_AFIO,ENABLE);	//117   PD3  力矩    4	118   PD4  模式    3  119   PD5   全关    2		//PD0  蓝牙接口
  GPIO_PinRemapConfig(GPIO_Remap_PD01,ENABLE);								//复用映射
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;				 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);  //126  PG11  MCU_POWER
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
	

}



