#include "adc.h"
#include "delay.h"

void  Adc_Init(void)
{ 	
	ADC_InitTypeDef ADC_InitStructure; 
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1,ENABLE );	  //使能ADC1通道时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE );
		
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //72M/6=12,ADC最大时间不能超过14M
	//PA0/1/2/3 作为模拟通道输入引脚                         
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;     //PIN26   PIN27   //电机温度 4-20MA信号AD输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//模拟输入引脚
	GPIO_Init(GPIOC, &GPIO_InitStructure);	

	ADC_DeInit(ADC1);  //将外设 ADC1 的全部寄存器重设为缺省值

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC1工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//模数转换工作在单通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
	ADC_Init(ADC1, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器   
    
	ADC_Cmd(ADC1, ENABLE);	//使能指定的ADC1
	ADC_ResetCalibration(ADC1);	//重置指定的ADC1的校准寄存器
	while(ADC_GetResetCalibrationStatus(ADC1));	//获取ADC1重置校准寄存器的状态,设置状态则等待
	ADC_StartCalibration(ADC1);		//开始指定ADC1的校准状态
  while(ADC_GetCalibrationStatus(ADC1));		//获取指定ADC1的校准程序,设置状态则等待
  //ADC_SoftwareStartConvCmd(ADC1,ENABLE);		//使能指定的ADC1的软件转换启动功能

}		




u16 Get_Adc(u8 ch)   
{
  	
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	
  ADC_SoftwareStartConvCmd(ADC1, ENABLE);		
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));
  return ADC_GetConversionValue(ADC1);	
}

u16 Get_Adc_Average(u8 ch,u8 times)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Adc(ch);
		delay_ms(5);
	}
	return temp_val/times;
}




