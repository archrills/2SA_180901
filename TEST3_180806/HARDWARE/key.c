#include "stm32f10x.h"
#include "led.h"
#include "key.h" 
#include "timer.h"
#include "delay.h"
#include "usart.h"
#include "stm32f10x_pwr.h"
#include "stm32f10x_tim.h"

extern unsigned int  key_flag;
extern unsigned char timer0_count_enough;
extern unsigned char long_quit_sign;
extern void timer0_reset(void);
extern signed long int turns,all_angle,angle;
extern signed long int ad_previous,ad_next,encoder_previous;
extern unsigned char uart5_count_array[36];
extern unsigned char key_allowed;
extern unsigned char receive_arrange;
void KEY_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);   //122  PD6切换
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;
 //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPD;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOD, &GPIO_InitStructure);
 
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);  //123  PD7确定
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;
 //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPD;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOD, &GPIO_InitStructure);
 
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);  //124  PG9关
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;
 //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPD;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOG, &GPIO_InitStructure);
 
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);  //125  PG10开
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10;
 //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPD;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOG, &GPIO_InitStructure);

}



/*
void key_scan(void)

{	      
  if(KEY_ENTER)
   {
		 
	 //if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
	 {
		Timer4_Init();   
		//key_enter_used=1;
		key_short_register=2;
		key_flag=0; 
		
	 }
	}
	  else if(KEY_TOGGLE)
	{
	  //if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
	  {
		Timer4_Init();
		//key_toggle_used=1;
		key_short_register=1;
		key_flag=0; 
		}
	}
	  else if(KEY_UP)
	  {
		//if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
		{
		 
		 Timer4_Init();
		 //key_up_used=1;
		 key_short_register=3;
		 key_flag=0; 
		}
	  }
	 else if(KEY_DOWN)
	 {
		//if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
		{
		  
		   Timer4_Init();
		  // key_down_used=1;
		   key_short_register=4;
		   key_flag=0; 
		 }
	 }
	 
	 
	 
    else 
		{
		  
		  if(timer0_count>0)
		  {
		  timer4_reset();
		  //key_toggle_used=0;
		  //key_enter_used=0;
		  //key_up_used=0;
		  //key_down_used=0;
		  key_short_register=0;
		  key_longtime_register=0;
      key_flag=1; 
		  }
		}
        
		if(timer0_count>80)
		
		{
      key_flag=0; 
			key_short_register=0;
			 if(KEY_TOGGLE)
			{			    
			  key_longtime_register=1;
       while(1);
			}
			else if(KEY_ENTER)
			{
			  key_longtime_register=2;
			
					   
			}
			else if(KEY_UP)
			{
			  key_longtime_register=3;
			  
			}
			else if(KEY_DOWN)
			{
		     key_longtime_register=4;
			 
      }
     }
		 
}
*/			
			
void key_scan(void)

{	      
	

	     
	       
						 if(KEY_ENTER)
						     {
								   
								      if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
								      {
											   	  
												  Timer4_Init();   //定时器4是按键 记时
												  key_enter_used=1;
										   }
											 
											 
											 
								 }
						 
						 else if(KEY_TOGGLE)
						           {
								  
								        if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
										   {
											   	Timer4_Init();
												  key_toggle_used=1;
											   	  
										   }
								  }
						 
						 else if(KEY_UP)
						         {
								  
								  if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
										   {
											   	  //ad_previous=Get_Adc(ADC_Channel_12);
												    Timer4_Init();
												    key_up_used=1;
												    ad_previous=all_angle;
										   }
								  }
						 
						 else if(KEY_DOWN)
						          {
								  
								  if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
										   {
											   	  //ad_previous=Get_Adc(ADC_Channel_12);
												    Timer4_Init();
												    key_down_used=1;
												    ad_previous=all_angle;
										   }
								  }
				
					     else
						          {
								     
											 if((timer0_count>0)||(timer0_count_enough==1))
									       {
									  		  if(key_toggle_used==1)
											  {
											  key_short_register=1;
						                      }
											  else if(key_enter_used==1)
											  {
											  key_short_register=2;
						                      }
						
											  else if(key_up_used==1)
											  {
											  key_short_register=3;
						                     
											  }
						
									  		  else if(key_down_used==1)
											  {
											  key_short_register=4;
						                      
											  }
									      	  
											  
											  timer0_reset();
											  timer0_count_enough=0;
									          key_toggle_used=0;
									          key_enter_used=0;
											      key_up_used=0;
									          key_down_used=0;
											  
											  
										  	  
										   }
										   
										     
										   
								  }
				
				



			    if(timer0_count>80)
			 {
			     
					  if(key_toggle_used==1)
					  {
					  key_longtime_register=1;
					  //while(!KEY_IDLE);
					  }
					 else if(key_enter_used==1)
					  {
					  key_longtime_register=2;
					  long_quit_sign=1;
					  //while(!KEY_IDLE);
					  }
					 else if(key_up_used==1)
					  {
					  key_longtime_register=3;
					  timer0_count_enough=1;
						//while(!KEY_IDLE);
					  
					  }
			  		 else if(key_down_used==1)
					  {
					  key_longtime_register=4;
					  timer0_count_enough=1;
						//while(!KEY_IDLE);

					  }
				   
				   	 
				      timer0_reset();
			          key_toggle_used=0;
			          key_enter_used=0;
					  
					  
			 
			 } 
		  	  
			  
			 			
	
		   
}			  























