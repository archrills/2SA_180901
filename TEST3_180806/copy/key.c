#include "header.h"
#include "variable.h"
#include "timer.h"
#include "adc.h"
#include "stm32f10x.h"
#include "led.h"
 
 void KEY_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	
	
 //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15|GPIO_Pin_14|GPIO_Pin_3;
 //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				 
 //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 		 
 //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 //GPIO_Init(GPIOC, &GPIO_InitStructure);

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_6;				
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOB, &GPIO_InitStructure);

  
 }

void key_scan_process(void)

{	      
	           
	   
				
						 if(KEY_ENTER)
						{
						
						if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
						{
						   	  
							  Timer4_Init();   //定时器4是按键 记时
							  back_light_on;
						   	  key_enter_used=1;
						}
						}
						 
						 else if(KEY_TOGGLE)
						           {
								   
								  if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
										   {
											   	  
												  Timer4_Init();
												  back_light_on;
												  key_toggle_used=1;
											   	  
										   }
								  }
						 
						 else if(KEY_UP)
						         {
								  
								  if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
										   {
											   	  ad_previous=Get_Adc(ADC_Channel_12);
												  Timer4_Init();
												  back_light_on;
											   	  key_up_used=1;
										   }
								  }
						 
						 else if(KEY_DOWN)
						          {
								   
								  if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
										   {
											   	  ad_previous=Get_Adc(ADC_Channel_12);
												  Timer4_Init();
												  
											   	  back_light_on;
												  key_down_used=1;
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
					  
					  }
					 else if(key_enter_used==1)
					  {
					  key_longtime_register=2;
					  long_quit_sign=1;
					
					  }
					 else if(key_up_used==1)
					  {
					  key_longtime_register=3;
					  timer0_count_enough=1;
					  
					  }
			  		 else if(key_down_used==1)
					  {
					  key_longtime_register=4;
					  timer0_count_enough=1;

					  }
				   
				   	 
				      timer0_reset();
			          key_toggle_used=0;
			          key_enter_used=0;
					  
					  
			 
			 } 
		  	  
			  
			
		   
}			  

void key_scan_process1(void)

{	      
	           
			   if(KEY_ENTER)
						          {
								   
								  if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
								{
											   	  
												  Timer4_Init();   //定时器4是按键 记时
												 
												  back_light_on;
											   	  key_enter_used=1;
										   }
								  }
						 
						 else if(KEY_TOGGLE)
						           {
								  
								  if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
										   {
											   	  
												  Timer4_Init();
												 
												  back_light_on;
												  key_toggle_used=1;
											   	  
										   }
								  }
						 
						 else if(KEY_UP)
						         {
								   
								  if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
										   {
											   	  ad_previous=Get_Adc(ADC_Channel_12);
												  Timer4_Init();
												  
												  back_light_on;
											   	  key_up_used=1;
										   }
								  }
						 
						 else if(KEY_DOWN)
						          {
								   
								  if((key_toggle_used==0)&&(key_enter_used==0)&&(key_up_used==0)&&(key_down_used==0))
										   {
											   	  ad_previous=Get_Adc(ADC_Channel_12);
												  Timer4_Init();
												 
											   	   back_light_on;
												  key_down_used=1;
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
					  
					  }
					 else if(key_enter_used==1)
					  {
					  key_longtime_register=2;
					  long_quit_sign=1;
					
					  }
					 else if(key_up_used==1)
					  {
					  key_longtime_register=3;
					  timer0_count_enough=1;
					  
					  }
			  		 else if(key_down_used==1)
					  {
					  key_longtime_register=4;
					  timer0_count_enough=1;

					  }
				   
				   	 
				      timer0_reset();
			          key_toggle_used=0;
			          key_enter_used=0;
					  
					  
			 
			 } 


			  if(timer2_count>800)	//定时器2是背光
			{
			
		     	timer2_reset();
		
		    }

		  	  			
		

}			  





			 
void go_up_derection_detect(void)
{  
 
            key_scan_process1();  //
                 if(key_up_short_press)
					{
					    key_register_reset;
						ad_next=Get_Adc(ADC_Channel_12);
						
						if(ad_next>ad_previous)
						{
    						 if((ad_next-ad_previous)>5)
    						 go_up_ad=255;
						}
						else
						{
						    if((ad_previous-ad_next)>5)
							go_up_ad=0;
						}
						
						
						
						
						
				}
					
					if(key_down_short_press)
					{
					    key_register_reset;
						ad_next=Get_Adc(ADC_Channel_12);
						if(ad_next>ad_previous)
						{
						   if((ad_next-ad_previous)>2)
						   go_up_ad=0;
						}
						else
						{
						  if((ad_previous-ad_next)>2)
						  go_up_ad=255;
						}
						
					
					}
					
}
		 	
void key_toggle_long_process(void)
{
        unsigned char a;

                 key_register_reset;
				 //STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				 //a=TEXT_Buffer[eeprom_write_local_remote_sign];
						 
                  display_select=0;
				  current_data=0;
				  
        		  initlcm();
        		  if(language_register==0)
        		{
        		    display_chinese_letter(0x81,"返回工作状态");
        		} 
        		 else
        		{
        		display_chinese_letter(0x80,"  go to local");
        		display_chinese_letter(0x90,"control");
        		}
        		while(!KEY_IDLE);

        		function_point=local_process;

			    register_initial();

			   // switch_mode_sign=0;
                 
}
	

void key_toggle_long_process1(void)
{
     

                 key_register_reset;
			     display_select=0;
				 current_data=0;
				  shen1=3; 		  //触发
        		  initlcm();
        		  if(language_register==0)
        		{
        		    display_chinese_letter(0x81,"返回工作状态");
        		} 
        		 else
        		{
        		display_chinese_letter(0x80,"  go to local");
        		display_chinese_letter(0x90,"control");
        		}
				    
				menu_point=menu0;
															 
				menu_position=0;
				order_point=0;
				menu0_position=0;										
				menu1_position=0;										
				menu2_position=0;											
													
				
        		while(!KEY_IDLE);
			    function_point=local_process;
				(*function_point)();
                 
                register_initial();
				
 }




		  
void key_toggle_short_process(void) 
{
 		                              initlcm();
									  shen1=2; 
			        				  menu_position-=1;
							          if(menu_position<(-1))
									{
									    menu_position=(-1);
									}   
										
										 if(menu_position>=0)
										 {
												  if(menu_position==0)
												 {
												 order_point=menu0_position;
												 }
												 else if(menu_position==1)
												 {
												 order_point=menu1_position;
												 }
												 else if(menu_position==2)
												 {
												 order_point=menu2_position;
												 }
										 
										 }
										 else
										 {
										   
										 
										 }
						 
								        

 
 }	 				    


