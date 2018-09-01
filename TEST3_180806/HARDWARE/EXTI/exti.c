#include "exti.h"
#include "led.h"

#include "delay.h"
#include "usart.h"
#include "header.h"
#include "variable.h"
#include "key.h"


extern unsigned char alarm_sign;
extern unsigned char   sensitive_register,move_direction_register,emergency_position_register,move_direction_register_temporary,move_direction_register_temporary1,
                       motor_protect_register,normal_speed_register,language_register,speed_register;

extern unsigned char first_fault_record;	
extern unsigned char current_data_over_sign;
extern unsigned char quit_sign;
extern void (*function_point)();//�ǳ���Ҫ ����ָ��
extern unsigned int current_data,AD_register;
extern unsigned char display_select;
extern void communicate(void);
extern char buf[128];
extern unsigned int	fault_first_record_data;
	
void EXTIX_Init(void)
{
  	   GPIO_InitTypeDef GPIO_InitStructure;
 	  EXTI_InitTypeDef EXTI_InitStructure;
 	  NVIC_InitTypeDef NVIC_InitStructure;
    
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	//�ر�jtag
    
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);
  	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  	GPIO_Init(GPIOB, &GPIO_InitStructure);
    
	  //GPIOA.13 �ж����Լ��жϳ�ʼ������
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource12);
    EXTI_InitStructure.EXTI_Line=EXTI_Line12;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

  	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			      //ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	  //��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					  //�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								  //ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure); 
  
  		  
}

 
void EXTI15_10_IRQHandler(void)
{
	// EXTI_InitTypeDef EXTI_InitStructure;

    delay_ms(10);    //����
  	if(EXTI_GetITStatus(EXTI_Line12) != RESET)	  //���ָ����EXTI0��·�������������
	{	  
		//LED0=0;
		//LED1=0;	
	}
	EXTI_ClearITPendingBit(EXTI_Line12);  //���EXTI0��·����λ
	EXTI_ClearFlag(EXTI_Line12);
  alarm_sign=1;
 // error_led_on;


}
 

void alarm_process(void)
 {
   
	 									
					//if(function_point!=parameter_first)	
					//{	
						if((first_fault_record==1)||(first_fault_record==2)||(first_fault_record==3)||(first_fault_record==9)||(first_fault_record==12)||(first_fault_record==1)
						||(first_fault_record==21)||(first_fault_record==22)||(first_fault_record==23))
						{
									   if(language_register==0)
								
								 {
								 	 GpuSend4("PIC(338,182,47);DS32(338,268,'�������',0,0);\r\n");  
			                     }
								  else
								 
								 {
								 	GpuSend4("PIC(338,182,47);DS32(338,268,'current over',0,0);\r\n");  
			                     }
						
						}

					   else	if((first_fault_record==4)||(first_fault_record==5)||(first_fault_record==6)||(first_fault_record==7)||(first_fault_record==34)
						||(first_fault_record==35)||(first_fault_record==36))
						{
								 voltage_fault_relay_on();
								
									   if(language_register==0)
								
								 {
								 	GpuSend4("PIC(338,182,49);DS32(338,268,'��Դ��ѹ',0,0);\r\n"); 
			                     }
								  else
								 
								 {
								 	GpuSend4("PIC(338,182,49);DS32(338,268,'voltage over',0,0);\r\n");  
			                     }
						
						}
						

					   else	if((first_fault_record==11))	
						{
						
							  voltage_fault_relay_on();
							   if(language_register==0)
								
								 {
								 	GpuSend4("PIC(338,182,49);DS32(338,268,'��ԴǷѹ',0,0);\r\n");
			                     }
								  else
								 
								 {
								 	 GpuSend4("PIC(338,182,44);DS32(338,268,'power low   ',0,0);\r\n");   
			                     }
						
						}



					   else if((first_fault_record==26)||(first_fault_record==27)||(first_fault_record==28))	
						{
						
							   if(language_register==0)
								
								 {
								 	GpuSend4("PIC(338,182,49);DS32(338,268,'���ȱ��',0,0);\r\n"); 
			                     }
								  else
								 
								 {
								 	GpuSend4("PIC(338,182,50);DS32(338,268,'phase lack ',0,0);\r\n"); 
			                     }
						
						}

					else if((first_fault_record==30))	
						{
						
							   if(language_register==0)
								
								 {
								 	GpuSend4("PIC(338,182,44);DS32(338,268,'ģ�����',0,0);\r\n");  
			                     }
								  else
								 
								 {
								 	 GpuSend4("PIC(338,182,44);DS32(338,268,'power fault ',0,0);\r\n");  
			                     }
						
						}
					

					   else if((first_fault_record==8))	
						{
						
						     	temperature_relay_on();
							   if(language_register==0)
								
								 {
								 	GpuSend4("PIC(338,182,44);DS32(338,268,'ģ�����',0,0);\r\n");   
			                     }
								  else
								 
								 {
								 	 GpuSend4("PIC(338,182,44);DS32(338,268,'module hot ',0,0);\r\n");  
									 
			                     }
						
						}

					   else
					   {
					   
					   		 if(language_register==0)
								
								 {
								 	GpuSend4("PIC(338,182,52);DS32(338,268,'�ܹ��� ',0,0);\r\n");  // ����ͼƬ  
			                     }
								  else
								 
								 {
								 	 GpuSend4("PIC(338,182,52);DS32(338,268,'Total fail',0,0);\r\n");  
			                     }
					   
					   	
					   }

					                
				//}	
         
 
 
 }



void reset_alarm(void)
{
  PDout(12)=1;   
  delay_ms(100);
  alarm_sign=0;
  PDout(12)=0;
	
}
