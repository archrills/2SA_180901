#include "header.h"
#include "variable.h"
#include "timer.h"
#include "adc.h"
#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include <stdio.h>


#define	 Null 0
#define uchar unsigned char
#define uint  unsigned int
void language_set(void);
//extern struct MenuItem *menu_point;
extern struct MenuItem *getmenu(uint id);
extern unsigned char uart5_count_array[36];

extern unsigned char TEXT_Buffer[262];

extern unsigned char   sensitive_register,move_direction_register,emergency_position_register,move_direction_register_temporary,move_direction_register_temporary1,
                       motor_protect_register,normal_speed_register,language_register,speed_register;
extern  unsigned char  torque_select;
extern float sen_temp;
extern void GpuSend4(char *buf2);
extern char buf[128];	
extern unsigned char  timer_ov;
extern unsigned char  torque_select;
extern unsigned char  motor_protect_sign;
extern unsigned int   speed_fall_position_register,speed_fall_position_register_count;
extern unsigned char  speed_select;
extern unsigned char  go_up_direction;
extern unsigned char  reaction_direction; 
extern unsigned long  switch_number;
extern unsigned char  torque_over_times;
extern unsigned char relay1_state,relay2_state,relay3_state,relay4_state,relay5_state;
extern unsigned char speed_rpm_select;
extern unsigned char signal_emergency_position_register;
extern unsigned char switch_operation_close_mode;
extern unsigned char switch_mode_select_variable;	
extern unsigned char analog_limit_sign;
extern unsigned char quit_sign;
extern signed char start_point_ad_h_register,end_point_ad_h_register,start_angle_register_h,end_angle_register_h;
extern signed char start_point_ad_l_register,start_angle_register_l,end_angle_register_l,end_point_ad_l_register;
extern signed long int turns,all_angle,angle;
extern signed long int start_point_ad,end_point_ad,all_distance;
extern unsigned char go_up_ad;
extern signed char pass_border_sign;
extern unsigned char key_keep_register;
extern unsigned char torque_over_sign;
extern unsigned char direction_judge_complete_sign;
extern int zero_mA_ad,full_mA_ad,all_mA_ad;
extern int zero_mA_ad_h_register,full_mA_ad_h_register;
extern void (*function_point)();//非常重要 程序指针
extern char pwm_value_zero_l_register,pwm_value_full_l_register,zero_mA_ad_l_register,full_mA_ad_l_register;
extern  void slow_speed_off(void);
extern  void slow_speed_on(void);
extern unsigned char switch_mode_sign;

extern unsigned int all_pwm_value_register,zero_pwm_value_register,full_pwm_value_register,pwm_value_zero_h_register,pwm_value_full_h_register;

extern void (*function_point)();//非常重要 程序指针
extern struct MenuItem  Menu_main[];
extern unsigned int address,standard_torque;
extern void phase_lack_check(void);
extern unsigned char timer0_count_enough;
extern void write_modbus_data(unsigned char address_hundred,unsigned char address_ten_bit,unsigned char value_ten,unsigned char value_bit);
extern unsigned char mode_toggle,flag_test,stop_flag,stop_flag1;
extern unsigned char display_select;

extern unsigned int	current_data;
extern unsigned char key_allowed;
extern unsigned char array_test[36];
extern signed char app_volt,app_speed,app_year,app_torque,app_number1,app_number2;

extern void product_id_set(void);

extern int operate_bus_voltage_data,operate_voltage_data,operate_freq_data,operate_hour_data,operate_module_temperature_data,operate_motor_speed_data,operate_inverter_code_data,fault_module_temperature_data,
operate_set_freq_data,fault_first_record_data,fault_second_record_data,fault_third_record_data,fault_out_freq_data,fault_set_freq_data,fault_out_current_data,fault_out_voltage_data,fault_bus_voltage_data,
operate_current_data;
int all_run_time_data;

extern unsigned char local_register;
extern unsigned char bluetooth_sign;


void relay_define_display(int a)
{
	switch(a)
    {
                 case 0:{
                 if(language_register==0)
                 {
                    GpuSend4("DS48(280,0,'全关',0,0);\r\n");
					delay_ms(18);
																														 
                 } 
                 else
                 {
                    GpuSend4("DS48(280,0,'alloff',0,0);\r\n");
					delay_ms(18);
					
                 };
                };break;
            						    
               case 1:{
                if(language_register==0)
                {
                   GpuSend4("DS48(280,0,'全开',0,0);\r\n");
				   delay_ms(18);
					
                } 
                else
                {
                    GpuSend4("DS48(280,0,'allopen',0,0);\r\n");
					delay_ms(18);
                 };
            	};break;
            							
                case 2:{
                 if(language_register==0)
                {
                    GpuSend4("DS48(280,0,'远控',0,0);\r\n");
				    delay_ms(18);
					
                } 
                else
                 {
                   GpuSend4("DS48(280,0,'remote',0,0);\r\n");
				   delay_ms(18);
                 };
            	};break;	  
				   
		       case 3:{
                if(language_register==0)
                {
                   GpuSend4("DS48(280,0,'现场',0,0);\r\n");
				    delay_ms(18);
	            } 
                else
                {
                   GpuSend4("DS48(280,0,'local',0,0);\r\n");
				   delay_ms(18);
					
                };
               };break;	
											   
											   
		       case 4:{
                if(language_register==0)
                {
                    GpuSend4("DS48(280,0,'过热',0,0);\r\n");
				    delay_ms(18);

                } 
                else
                {
                    GpuSend4("DS48(280,0,'toohot',0,0);\r\n");
				    delay_ms(18);
					
                };
            	};break;
											   
		       case 5:{
                if(language_register==0)
                {
                   GpuSend4("DS48(280,0,'过压',0,0);\r\n");
				   delay_ms(18);
									  
                } 
                else
                {
                   
				   GpuSend4("DS48(280,0,'vol.fau.',0,0);\r\n");
				   delay_ms(18);

					
                 };
            	};break;
											   
											   
		       case 6:{
                if(language_register==0)
                {
                 
                 GpuSend4("DS48(280,0,'开过力矩',0,0);\r\n");
				 delay_ms(18); 
				  
                } 
                else
                {
                  
				  GpuSend4("DS48(280,0,'torque 1',0,0);\r\n");
				  delay_ms(18);
				  
                };
            	};break;	 	 	    
											       
	          	case 7:{
                if(language_register==0)
                {
                  GpuSend4("DS48(280,0,'关过力矩',0,0);\r\n");
				  delay_ms(18); 
				                    				  
                } 
                else
                {
                  GpuSend4("DS48(280,0,'torque 2',0,0);\r\n");
				  delay_ms(8);
                };
            	};break;	 		   
	          	case 8:{
                if(language_register==0)
                   {
                    GpuSend4("DS48(280,0,'总故障',0,0);\r\n");
				    delay_ms(18); 
                    } 
                     else
                    {
                     GpuSend4("DS48(280,0,'fault',0,0);\r\n");
				     delay_ms(18); 
                    };
            		};break;	    
            						
    }
}




void language_set(void)
 {
   unsigned char language_register_temporary;
   STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
   language_register=TEXT_Buffer[eeprom_write_language];
   language_register_temporary=language_register&0x01;
   GpuSend4("CLS(15);");
   delay_ms(18);
	 
    if((language_register_temporary!=1)&&(language_register_temporary!=0))
    {
	    language_register_temporary=0;
	  }
	

    while(1)
	{
	              
	if(language_register_temporary==0)
	{
		
	  GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	  delay_ms(20);
	  GpuSend4("DS48(0,0,'中文',0,0);PIC(0,80,160);\r\n");
	  delay_ms(20);
	  GpuSend4("PIC(327,0,21);\r\n");
	  delay_ms(20);
		
	}
	else
	{
	
	  GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	  delay_ms(30);
	  GpuSend4("DS48(0,0,'ENGLISH',0,0);PIC(0,80,159);\r\n");
	  delay_ms(30);
	  GpuSend4("PIC(327,0,22);\r\n");
	  delay_ms(30);

	}
	 			
	key_scan();
	
	if((key_up_short_press)||(key_down_short_press))
	 {
	     
		 key_register_reset;
		 GpuSend4("CLS(15);");
		 delay_ms(25);
	     language_register_temporary=(~language_register_temporary);
		 language_register_temporary=language_register_temporary&0x01;
	
	 }
		
			   	if(key_enter_long_press)
				 {
				    key_register_reset;
				    GpuSend4("CLS(15);");
					delay_ms(18);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(200);
					//while(KEY_IN);
					//GpuSend4("CLS(15);");
					language_register=language_register_temporary;
					TEXT_Buffer[eeprom_write_language]=(language_register_temporary);
					STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
					while(!KEY_IDLE);
					GpuSend4("CLS(15);");
					delay_ms(18);
					break;
				 } 
				  if(key_toggle_short_press)
				 {
				  
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(18);
					while(!KEY_IDLE);   //松开按键生效
					//key_toggle_short_process();
					break;
				 }

	      }
 }



 void sensitive_set(void)
  {
		unsigned int a,b;
		//float a;
		unsigned char sensitive_register_temporary;
		STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
		sensitive_register=TEXT_Buffer[eeprom_write_sensitive];
		sensitive_register_temporary=sensitive_register;	
		
		if((sensitive_register_temporary>50)||(sensitive_register_temporary<3))
		{
		   sensitive_register_temporary=3;
		}
		
		GpuSend4("CLS(15);");
		delay_ms(18);
		a=sensitive_register_temporary/10;
		b=sensitive_register_temporary%10;
		sprintf(buf,"DS48(340,0,'%d.%d',0);",a,b);
		
		GpuSend4(buf); 
		delay_ms(18);
		GpuSend4("DS48(420,0,'%',0,0);\r\n");
		delay_ms(18);


	   while(1)
	   {
	       key_scan();

			if(language_register==1)
			{
			
			    GpuSend4("PIC(0,80,159);\r\n");
			    delay_ms(18);
			
			}
			else
			{
			
			   GpuSend4("PIC(0,80,160);\r\n");
			   delay_ms(18);
			}



		     if(language_register==0)
        {
              
			GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
			delay_ms(18);
			GpuSend4("DS48(0,0,'死区大小',0,0);\r\n");
			delay_ms(18);
					
        }
        else
        {    
			GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
			delay_ms(38);
			GpuSend4("DS48(0,0,'DEAD ZONE',0,0);\r\n");
			delay_ms(18);
					
					
        }	
				
		  a=sensitive_register_temporary/10;
		  b=sensitive_register_temporary%10;
	      sprintf(buf,"DS48(340,0,'%d.%d',0);",a,b);
		  GpuSend4(buf); 
		  delay_ms(18);
		  GpuSend4("DS48(420,0,'%',0,0);\r\n");
          delay_ms(18);
	 
		if(key_down_short_press)
		{
		   key_register_reset;
		   sensitive_register_temporary--;
		if(sensitive_register_temporary<3)
		{
		   sensitive_register_temporary=3;
		}
		
		}
		
		if(key_up_short_press)
		{
		key_register_reset;
		sensitive_register_temporary++;
		if(sensitive_register_temporary>50)
		{
		  sensitive_register_temporary=50;
		}
		
		}
                  key_scan();
			   	 if(key_enter_long_press)
				 {
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(200);
					sensitive_register=sensitive_register_temporary;
					TEXT_Buffer[eeprom_write_sensitive]=(sensitive_register);
					STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
					register_initial();
					while(!KEY_IDLE);
					break;
					//function_point=signal_off_set;
				
				 }
				 if(key_toggle_short_press)
				 {
				  
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);	  
					break;
				 }
			   	
				 if(key_toggle_long_press)
				 {
				  key_register_reset;
				  while(!KEY_IDLE);
				  break;
				 }
			  
	   }
   
  }

	
	
 void torque_set(void)
 {
   	
	//unsigned char a,b,c,d,h,l;
	//unsigned int instead;
	unsigned int h,l;
    unsigned int p,middle;
	//unsigned int torque_register_temporary;
	 
	STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
    torque_register=(TEXT_Buffer[eeprom_write_torque_h]*256)+TEXT_Buffer[eeprom_write_torque];
	GpuSend4("CLS(15);");
	delay_ms(8);
	//torque_select=0;     //注意：调试用 后期请去掉该句
	//torque_register=10;  //注意：调试用 后期请去掉该句
	 
	middle=torque_register;
    
    if( torque_select==0)
		{
			p=middle/3;
		}
		else if( torque_select==1)
		{
			p=middle/6;
		}
		else if( torque_select==2)
		{
			p=(middle*10+5)/125;
		}
        else if( torque_select==3)
		{
			 p=middle/25;
		}
        else if( torque_select==4)
		{
			 p=middle/50;
		}
        else if( torque_select==5)
		{
			p=middle/100;
		}
   
   
   while(1)
{
	   	
				if(language_register==0)
				{
				    GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
				    delay_ms(18);
			     	GpuSend4("DS48(0,0,'关断力矩设定',0,0);\r\n");
				    delay_ms(18);
				} 
				else
				{
				    GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
				    delay_ms(38);
				    GpuSend4("DS48(0,0,'torque set',0,0);\r\n");
				    delay_ms(18);
				} 


			    key_scan();
                sprintf(buf,"DS48(320,0,'%4d',0);",middle);
				GpuSend4(buf); 
			    delay_ms(18);
				GpuSend4("DS48(420,0,'NM',0,0);\r\n");
                delay_ms(18);

					 
				   if(key_down_short_press)
					 {
					     key_register_reset;
					     p--;
						 if(p<3)
						 p=3;
						 if(torque_select==0)	    //	   30
						 {
						   middle=3*p;
						 }
						 else if(torque_select==1)	//	   60
						 {
						   middle=6*p;
						 }
						 else if(torque_select==2)	//	   125
						 {
						   middle=125*p/10;
						 }
						 else if(torque_select==3)	 //	   250
						 {
						   middle=25*p;
						 }
						 else if( torque_select==4)	 //	   500
						 {
						   middle=50*p;
						 }
						 else if(torque_select==5)	 //	 1000
						 {
						   middle=100*p;
						 } 
						
					 }
		
					 if(key_up_short_press)
					 {
					     key_register_reset;
						 p++;
						 if(p>10)
						 p=10;
						 if(torque_select==0)
						 {
						   middle=3*p;
						 }
						 else if(torque_select==1)
						 {
						   middle=6*p;
						 }
						 else if(torque_select==2)
						 {
						   middle=125*p/10;
						 }
						 else if(torque_select==3)
						 {
						   middle=25*p;
						 }
						 else if(torque_select==4)
						 {
						   middle=50*p;
						 }
						 else if(torque_select==5)
						 {
						   middle=100*p;
						 }
						
					 }

		          key_scan();

				 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



			   	 if(key_enter_long_press)
				 {
				  
				  key_register_reset;
				  h=middle/256;
				  l=middle%256;
				  TEXT_Buffer[eeprom_write_torque]=(l);
				  TEXT_Buffer[eeprom_write_torque_h]=(h);
				  TEXT_Buffer[eeprom_write_torque_percent]=(p);
				  
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  torque_register=middle;
			    standard_torque=((float)TEXT_Buffer[eeprom_write_torque_compensate_h]*256+
				  TEXT_Buffer[eeprom_write_torque_compensate]-TEXT_Buffer[eeprom_write_torque_compensate_low])*
				  (TEXT_Buffer[eeprom_write_torque_percent]-3)/7.0+TEXT_Buffer[eeprom_write_torque_compensate_low]+0.5;	  
					
					GpuSend4("CLS(15);");
					delay_ms(18);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(20);
					register_initial();
					while(!KEY_IDLE);
				    break;
				 }
					
			      
				  if(key_toggle_short_press)
				 {
				    key_register_reset;
				    GpuSend4("CLS(15);");
					delay_ms(20);
				    break;
				 }
				 
				  if(key_toggle_long_press)
				 {
				  key_register_reset;
			      while(!KEY_IDLE);
				  break;
					 
				 }
				 
				 
				 
				 
	   }
  }
	
	
	

void motor_temperature_protect(void)
 {
	  unsigned char a;
	  STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	  a=TEXT_Buffer[eeprom_write_motor_protect];
	  a=a&0x01;
	  if((a!=1)&&(a!=0))
    {
      a=0;
    }			
	  
	  GpuSend4("CLS(15);");
		delay_ms(18);
	 
		while(1)
		{
				   
			if(language_register==0)
      {
        
				GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	      delay_ms(38);
		    GpuSend4("DS48(0,0,'电机温度保护',0,0);\r\n");
			  delay_ms(18);
				if(a==0)
				{
          GpuSend4("DS48(382,0,'开启',0,0);\r\n");
			    delay_ms(18);
        }
        else
				{
					GpuSend4("DS48(382,0,'关闭',0,0);\r\n");
			    delay_ms(18);
        }					
				
				
       }
       else
       {
        
				 GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	             delay_ms(38);
		         GpuSend4("DS48(0,0,'motor pro.',0,0);\r\n");
				 delay_ms(18);
				 if(a==0)
				 {
                   GpuSend4("DS48(311,0,'enable ',0,0);\r\n");
			       delay_ms(18);
                 }
        else
				{
				   GpuSend4("DS48(311,0,'disable',0,0);\r\n");
			       delay_ms(18);
                 }				
				 
				 
       }
						
			 key_scan();

				if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			

					  
    					   if((key_up_short_press)||(key_down_short_press))
    					 {
    					   key_register_reset;
    					   a=~a;
						     a=a&0x01;
						  
    					 }
					 
					      if(key_toggle_short_press)
        				{
        				  key_register_reset;
        				 GpuSend4("CLS(15);");
                         delay_ms(20);
                         while(!KEY_IDLE);
        				  //key_toggle_short_process();
						      break;
        				 }
        				
				if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
						
						
						
						
							
        			   if(key_enter_long_press)
        				 {
							key_register_reset;
							GpuSend4("CLS(15);");
							delay_ms(8);
							GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
							delay_ms(200);
							//while(KEY_IN);
							GpuSend4("CLS(15);");
							motor_protect_sign=a;
							TEXT_Buffer[eeprom_write_motor_protect]=(a);
							STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
							register_initial();
							while(!KEY_IDLE);
							//function_point=relay1_define;
							break;
					     } 
					}
 
}
	

void speed_fall_position_set(void)
{
    int temporary;
	  STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
    temporary=TEXT_Buffer[eeprom_write_speed_fall_position];
	  if((temporary>30)||(temporary<0))
    {
      temporary=0;
    }	
	
	
	  GpuSend4("CLS(15);");
	  delay_ms(8);
    temporary =speed_fall_position_register;
				  
	  while(1)
    {
		if(language_register==0)
		{
		
			GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
			delay_ms(18);
			GpuSend4("DS48(0,0,'减速位置设定',0,0);\r\n");
			delay_ms(18);
		}
		else
		{
		 
			GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
			delay_ms(38);
			GpuSend4("DS48(0,0,'speed.dec.pos.',0,0);\r\n");
			delay_ms(18);
		 
		}
		 
		//display_percent_count_every_bit(0x91,temporary);
		//display_address(0x93);
		sprintf(buf,"DS48(350,0,'%2d',0);",temporary);
		GpuSend4(buf); 
		delay_ms(18);
		GpuSend4("DS48(420,0,'%',0,0);\r\n");
		delay_ms(18);
		key_scan();
					
		if(key_down_short_press)
		{
		 key_register_reset;
		 
		if(temporary>0)
		{
		 temporary--;
			
			
	  }
	   else
	  {
	   temporary=0;
    } 
		
	  }
		
		if(key_up_short_press)
		{
		key_register_reset;
	    if(temporary>30)
		{
		 temporary=30;
		}
		else
		{
		 temporary++;	
		}
 
		}
        
		if(key_enter_long_press)
		{
			key_register_reset;
			GpuSend4("CLS(15);");
			delay_ms(18);
			GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
			delay_ms(20);
			
			speed_fall_position_register=temporary;
			speed_fall_position_register_count=speed_fall_position_register*10;
			TEXT_Buffer[eeprom_write_speed_fall_position]=(temporary);
			STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
			register_initial();
			while(!KEY_IDLE);
			break;
		}


				if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}






		if(key_toggle_short_press)
		{
			key_register_reset;
			GpuSend4("CLS(15);");
			delay_ms(20);
			while(!KEY_IDLE);
			break;
		}

	}
 }
  
void normal_speed_set(void)
  {
    unsigned char middle,display_number_1;
	  unsigned int instead;
	
    GpuSend4("CLS(15);");
	  delay_ms(20);
    STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
    middle= TEXT_Buffer[eeprom_write_speed];                                    
    speed_select=TEXT_Buffer[eeprom_write_speed_rpm_select];	
	
		
		if((middle>40)||(middle<5))  //数据异常处理
		{
      middle=5;
    }
	   while(1)
	   {
	   	
		 if(language_register==0)
     {
       
			 GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	     delay_ms(18);
		   GpuSend4("DS48(0,0,'运行速度设定',0,0);\r\n");
		   delay_ms(18);
			 
     }
    else
     {
       
			 GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	     delay_ms(38);
		   GpuSend4("DS48(0,0,'speed set',0,0);\r\n");
	     delay_ms(18);
			 
     }
			     key_scan();

				 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



		       if(speed_select==0)
				   {
				   display_number_1=middle;
				   }
				   if(speed_select==1)
				   {
				   display_number_1=middle*2;
				   }
				   if(speed_select==2)
				   {
				   display_number_1=middle*4;
				   }
				   
                    sprintf(buf,"DS48(320,0,'%3d',0);",display_number_1);
				    GpuSend4(buf); 
			        delay_ms(18);
				    GpuSend4("DS48(400,0,'rpm',0,0);\r\n");
                    delay_ms(18);
			
					 if(key_down_short_press)
					 {
					  key_register_reset;
					  middle--;
					  if(middle<5)
						{
						  middle=5;
						}
						 
					 }
		
					 if(key_up_short_press)
					 {
					  key_register_reset;
					  middle++;
					  if(middle>40)
						{
						  middle=40;
						}
						
					 }

          if(key_enter_long_press)
				 {
				  key_register_reset;
				  GpuSend4("CLS(15);");
			      delay_ms(18);
			      GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
			      delay_ms(20);
			   
				  TEXT_Buffer[eeprom_write_speed]=(middle);
 				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  speed_register=middle;
				  instead=speed_register;
                  if(instead<10)
				  {instead=10;}	 
				  register_initial();
				  while(!KEY_IDLE);
			      break;
				 }																	    
					 
			      
				  if(key_toggle_short_press)
				 {
						key_register_reset;
						GpuSend4("CLS(15);");
						delay_ms(20);
						while(!KEY_IDLE);
						break;
				 }
			   	 
			
	   }
   
  }
 

	
	void  relay1_define(void)
	{
	  int relay_define_display_number;
    GpuSend4("CLS(15);");
	  delay_ms(18);
		STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	  relay_define_display_number=TEXT_Buffer[eeprom_write_relay1];
    if((relay_define_display_number>8)||(relay_define_display_number<0))
		{
		  relay_define_display_number=0;
		}
		
     while(1)
      {
                    if(language_register==0)
                   {
                     GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                   delay_ms(18);
		                 GpuSend4("DS48(0,0,'继电器1定义',0,0);\r\n");
		                 delay_ms(18);
				   }
                   else
                   {
                 
						GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                    delay_ms(18);
		                GpuSend4("DS48(0,0,'relay1',0,0);\r\n");
	                    delay_ms(18);
										 
										 
                   }

            	   	   relay_define_display(relay_define_display_number);
            				  key_scan();
            					
            					if(key_up_short_press)
            					 {

            					  key_register_reset;
								        GpuSend4("CLS(15);");
	                      delay_ms(8);
            					  relay_define_display_number++;
            					  if(relay_define_display_number>8)
            						 {
            						   	relay_define_display_number=0;
            							
            						 }
            					 }
            		
            					 if(key_down_short_press)
            					 {
            					  key_register_reset;
								        GpuSend4("CLS(15);");
	                      delay_ms(8);
            					  relay_define_display_number--;
            					      if(relay_define_display_number==255)
            						   {
            						   	relay_define_display_number=8;
            						   }
            					 }
            
                              if(key_enter_long_press)
            				 {
            				  key_register_reset;
											 
											 GpuSend4("CLS(15);");
			                 delay_ms(18);
			                 GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
			                 delay_ms(20);
			                
											
            				   TEXT_Buffer[eeprom_write_relay1]=(relay_define_display_number);
            			       STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
							   register_initial();
            				   while(!KEY_IDLE);
            				   break;
            				 }
            				
							 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
							
								 
            			      
            				  if(key_toggle_short_press)
            				 {
            				  
								
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(20);
								while(!KEY_IDLE);
								break;
            				 }
            			 
            
           }
	
	
	}
	
		void  relay2_define(void)
	{
	  int relay_define_display_number;
    GpuSend4("CLS(15);");
	  delay_ms(18);
		STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	  relay_define_display_number=TEXT_Buffer[eeprom_write_relay2];
    if((relay_define_display_number>8)||(relay_define_display_number<0))
		{
		  relay_define_display_number=0;
		}
		
     while(1)
      {
                    if(language_register==0)
                   {
                     GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                   delay_ms(18);
		                 GpuSend4("DS48(0,0,'继电器2定义',0,0);\r\n");
		                 delay_ms(18);
										}
                   else
                   {
                  // display_chinese_letter(0x80,"relay1define");
                   //display_chinese_letter(0x95,"Enter");
										  GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                    delay_ms(18);
		                  GpuSend4("DS48(0,0,'relay2',0,0);\r\n");
	                    delay_ms(18);
										 
										 
                   }

            	   	   relay_define_display(relay_define_display_number);
            				  key_scan();
            					
            					if(key_up_short_press)
            					 {

            					  key_register_reset;
								        GpuSend4("CLS(15);");
	                      delay_ms(8);
            					  relay_define_display_number++;
            					  if(relay_define_display_number>8)
            						 {
            						   	relay_define_display_number=0;
            							
            						 }
            					 }
            		
            					 if(key_down_short_press)
            					 {
            					  key_register_reset;
								  GpuSend4("CLS(15);");
	                              delay_ms(18);
            					  relay_define_display_number--;
            					      if(relay_define_display_number==255)
            						   {
            						   	relay_define_display_number=8;
            						   }
            					 }
            
                              if(key_enter_long_press)
            				 {
            				 
							 key_register_reset;
							 GpuSend4("CLS(15);");
			                 delay_ms(18);
			                 GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
			                 delay_ms(20);
			                 GpuSend4("CLS(15);");
											
            				   TEXT_Buffer[eeprom_write_relay2]=(relay_define_display_number);
            			     STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
							 register_initial();
            				  while(!KEY_IDLE);
            				  break;
            				 }
            				
							 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
							
								 
            			      
            				  if(key_toggle_short_press)
            				 {
            				  
            
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(20);
								while(!KEY_IDLE);
								break;
            				 }
            			 
            
           }
	
	
	}
	
		void  relay3_define(void)
	{
	  int relay_define_display_number;
    GpuSend4("CLS(15);");
	  delay_ms(18);
		STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	  relay_define_display_number=TEXT_Buffer[eeprom_write_relay3];
    if((relay_define_display_number>8)||(relay_define_display_number<0))
		{
		  relay_define_display_number=0;
		}
		
     while(1)
      {
                    if(language_register==0)
                   {
                     GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                   delay_ms(18);
		                 GpuSend4("DS48(0,0,'继电器3定义',0,0);\r\n");
		                 delay_ms(18);
										}
                   else
                   {
                 
										  GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                    delay_ms(38);
		                  GpuSend4("DS48(0,0,'relay3',0,0);\r\n");
	                    delay_ms(18);
										 
										 
                   }

            	   	   relay_define_display(relay_define_display_number);
            				  key_scan();
            					
            					if(key_up_short_press)
            					 {

            					  key_register_reset;
								        GpuSend4("CLS(15);");
	                      delay_ms(18);
            					  relay_define_display_number++;
            					  if(relay_define_display_number>8)
            						 {
            						   	relay_define_display_number=0;
            							
            						 }
            					 }
            		
            					 if(key_down_short_press)
            					 {
            					  key_register_reset;
								        GpuSend4("CLS(15);");
	                      delay_ms(18);
            					  relay_define_display_number--;
            					      if(relay_define_display_number==255)
            						   {
            						   	relay_define_display_number=8;
            						   }
            					 }
            
                              if(key_enter_long_press)
            				 {
            				  key_register_reset;
											 
											 GpuSend4("CLS(15);");
			                 delay_ms(18);
			                 GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
			                 delay_ms(20);
			                 GpuSend4("CLS(15);");
											
            				   TEXT_Buffer[eeprom_write_relay3]=(relay_define_display_number);
            			     STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
							 register_initial();
            				  while(!KEY_IDLE);
            				  
            				 
            				  break;
            				 }
            				
							 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
							
								 
            			      
            				  if(key_toggle_short_press)
            				 {
            				  
            
            				  key_register_reset;
            				 GpuSend4("CLS(15);");
delay_ms(20);
 while(!KEY_IDLE);
							        break;
            				 }
            			 
            
           }
	
	
	}
	
		void  relay4_define(void)
	{
	  int relay_define_display_number;
    GpuSend4("CLS(15);");
	  delay_ms(18);
		STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	  relay_define_display_number=TEXT_Buffer[eeprom_write_relay4];
    if((relay_define_display_number>8)||(relay_define_display_number<0))
		{
		  relay_define_display_number=0;
		}
		
     while(1)
      {
                    if(language_register==0)
                   {
                     GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                   delay_ms(18);
		                 GpuSend4("DS48(0,0,'继电器4定义',0,0);\r\n");
		                 delay_ms(18);
										}
                   else
                   {
                  // display_chinese_letter(0x80,"relay1define");
                   //display_chinese_letter(0x95,"Enter");
					GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
					delay_ms(38);
					GpuSend4("DS48(0,0,'relay4',0,0);\r\n");
					delay_ms(18);

										 
                   }

            	   	   relay_define_display(relay_define_display_number);
            				  key_scan();
            					
            					if(key_up_short_press)
            					 {

									key_register_reset;
									GpuSend4("CLS(15);");
									delay_ms(18);
									relay_define_display_number++;
            					  if(relay_define_display_number>8)
            						 {
            						   	relay_define_display_number=0;
            							
            						 }
            					 }
            		
            					 if(key_down_short_press)
            					 {
            					  key_register_reset;
								        GpuSend4("CLS(15);");
	                      delay_ms(18);
            					  relay_define_display_number--;
            					      if(relay_define_display_number==255)
            						   {
            						   	relay_define_display_number=8;
            						   }
            					 }
            
                              if(key_enter_long_press)
            				 {
            				  key_register_reset;
											 
											 GpuSend4("CLS(15);");
			                 delay_ms(18);
			                 GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
			                 delay_ms(20);
			                 GpuSend4("CLS(15);");
											
            				   TEXT_Buffer[eeprom_write_relay4]=(relay_define_display_number);
            			     STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
							 register_initial();
            				  while(!KEY_IDLE);
            				  
            				 
            				  
            				  break;
            				 }
            				
							 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
							
							
								 
            			      
            				  if(key_toggle_short_press)
            				 {
            				  
            
            				  key_register_reset;
							
							GpuSend4("CLS(15);");
							delay_ms(20);
							while(!KEY_IDLE);
							break;
            				 }
            			 
            
           }
	
	
	}
	
		void  relay5_define(void)
	{
	  int relay_define_display_number;
    GpuSend4("CLS(15);");
	  delay_ms(18);
		STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	  relay_define_display_number=TEXT_Buffer[eeprom_write_relay5];
    if((relay_define_display_number>8)||(relay_define_display_number<0))
		{
		  relay_define_display_number=0;
		}
		
     while(1)
      {
                    if(language_register==0)
                   {
                     GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                   delay_ms(18);
		                 GpuSend4("DS48(0,0,'继电器5定义',0,0);\r\n");
		                 delay_ms(18);
										}
                   else
                   {
                  // display_chinese_letter(0x80,"relay1define");
                   //display_chinese_letter(0x95,"Enter");
										  GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                    delay_ms(38);
		                  GpuSend4("DS48(0,0,'relay5',0,0);\r\n");
	                    delay_ms(18);
										 
										 
                   }

            	   	   relay_define_display(relay_define_display_number);
            				  key_scan();
            					
            					if(key_up_short_press)
            					 {

            					  key_register_reset;
								        GpuSend4("CLS(15);");
	                      delay_ms(18);
            					  relay_define_display_number++;
            					  if(relay_define_display_number>8)
            						 {
            						   	relay_define_display_number=0;
            							
            						 }
            					 }
            		
            					 if(key_down_short_press)
            					 {
									key_register_reset;
									GpuSend4("CLS(15);");
									delay_ms(18);
									relay_define_display_number--;
            					      if(relay_define_display_number==255)
            						   {
            						   	relay_define_display_number=8;
            						   }
            					 }
            
                              if(key_enter_long_press)
            				 {
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(18);
								GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
								delay_ms(20);
								GpuSend4("CLS(15);");
								TEXT_Buffer[eeprom_write_relay5]=(relay_define_display_number);
								STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
								register_initial();
								while(!KEY_IDLE);
                                break;
            				 }
            					 
            			      	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			





            				  if(key_toggle_short_press)
            				 {
            				  
							
							key_register_reset;
							GpuSend4("CLS(15);");
							delay_ms(20);
							while(!KEY_IDLE);
							break;
            				 }
            			 
            
           }
	
	
	}


void reaction_direction_set(void)
{
     unsigned char move_direction_register_temporary;
	   unsigned char move_direction_register_temporary_previous;
     GpuSend4("CLS(15);");
		 delay_ms(15);
	   move_direction_register_temporary_previous=TEXT_Buffer[eeprom_write_reaction_direction];
     move_direction_register_temporary=TEXT_Buffer[eeprom_write_reaction_direction];
	   move_direction_register_temporary_previous=move_direction_register_temporary_previous&0x01;
	   move_direction_register_temporary = move_direction_register_temporary&0x01;
		 if((move_direction_register_temporary!=1)&&(move_direction_register_temporary!=0))
			{
				move_direction_register_temporary=0;
			}
     //timer0_reset();
		 //timer0_count_enough=0;
		 key_toggle_used=0;
		 key_enter_used=0;
		 key_up_used=0;
		 key_down_used=0;
 
	   while(1)
	   {
	   	
		 		    if(language_register==0)
				  {
				    GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	          delay_ms(18);
		        GpuSend4("DS48(0,0,'作用方向设定',0,0);\r\n");
		        delay_ms(18);
						
				  }
				  else
				  {
				    GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	          delay_ms(18);
		        GpuSend4("DS48(0,0,'direction',0,0);\r\n");
	          delay_ms(18);
					}
			   	key_scan();
					if(move_direction_register_temporary==0)
					{
    					 if(language_register==0)
    					{
						    GpuSend4("DS48(340,0,'正作用',0,0);\r\n");
			          delay_ms(18);
							}
						else
						{   
    					GpuSend4("DS48(287,0,'positive',0,0);\r\n");
			        delay_ms(18);
						}
						
					}
				  	else
					{
					
					    if(language_register==0)
    					{
						    GpuSend4("DS48(340,0,'反作用',0,0);\r\n");
			          delay_ms(18);
								}
						else
						{   
    						GpuSend4("DS48(287,0,'reverse',0,0);\r\n");
			          delay_ms(18);
						}
					}
					
					
					
					if((key_up_short_press)||(key_down_short_press))
					 {
					      key_register_reset;
						    GpuSend4("CLS(15);");
		            delay_ms(8);
					  	  move_direction_register_temporary=(~move_direction_register_temporary);
						    move_direction_register_temporary = move_direction_register_temporary&0x01;
					 }
		
					

		 
			   	 if(key_enter_long_press)
				 {
				  key_register_reset;
				  //initlcm();
				  //display_chinese_letter(0x83,"ok");  
					 GpuSend4("CLS(15);");
			     delay_ms(18);
			     GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
			     delay_ms(20);
			    
					 TEXT_Buffer[eeprom_write_reaction_direction]=(move_direction_register_temporary);
				   reaction_direction=move_direction_register_temporary;	
				  		
				  if(reaction_direction!=move_direction_register_temporary_previous)
           {
             if(go_up_direction==100)
					  {
					  go_up_direction=0;
					  }
					  else
					  {
					  go_up_direction=100;
					  }
					 TEXT_Buffer[eeprom_write_move_direction]=(go_up_direction);	 
           }
				  
			       STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  while(!KEY_IDLE);
				  break;
				 }
				
				  	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
				
				
				
				
				
				
					 
			      
				  if(key_toggle_short_press)
				 {
				  
           key_register_reset;
				   GpuSend4("CLS(15);");
			     delay_ms(18);
				 register_initial();
				 while(!KEY_IDLE);
				   break;
				 }
			   	 
			
	   }
   
  }
  

void read_bus_voltage(void)
{
	
	//int a,t=5;
   operate_bus_voltage_data=0;
  	
  
   while(1)
	{
		key_scan();
		operate_bus_voltage_data=read_modbus_data(33,5);
		delay_ms(20);
		if(language_register==0)
      {
			GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
			delay_ms(20);
			GpuSend4("DS48(0,0,'直流母线电压',1,0);\r\n");
			delay_ms(20);
				
       }
     else
       {
			GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
			delay_ms(20);
			GpuSend4("DS48(0,0,'DC bus voltage',1,0);\r\n");
			delay_ms(20);
				         
       }
			if(operate_bus_voltage_data>1000)
			{operate_bus_voltage_data=operate_bus_voltage_data/10;}
			
			GpuSend4("DS48(440,0,'V',0,0);\r\n");
	        delay_ms(20);
			sprintf(buf,"DS48(360,0,'%3d',0);",operate_bus_voltage_data);
			GpuSend4(buf);
			delay_ms(20);

				if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



				   if(key_toggle_short_press)
           {
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					break;
            }

	  }
}



void	 read_frequency_set(void)
{
       int b,c;
	    
	   operate_set_freq_data=0;
	   delay_ms(200);
	   while(1)
			{
			    key_scan();
				operate_set_freq_data=read_modbus_data(33,2);
	            b=operate_set_freq_data/100;
	            c=operate_set_freq_data%100;
				delay_ms(20);
			    if(language_register==0)
            {
                  
					GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
					delay_ms(20);
					GpuSend4("DS48(0,0,'设定频率',1,0);\r\n");
					delay_ms(20);

             }
           else
            {
             
							
					GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
					delay_ms(38);
					GpuSend4("DS48(0,0,'Fre.Set',1,0);\r\n");
					delay_ms(20);
                   
            }

				   
				GpuSend4("DS48(430,0,'HZ',0,0);\r\n");
				delay_ms(20);
				sprintf(buf,"DS48(284,0,'%3d.%2d',0);",b,c);
				GpuSend4(buf);
				delay_ms(20);

			   	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
					if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			

						
				   if(key_toggle_short_press)
           {
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					//key_toggle_short_process();
					break;
            }

			}


}

void	 read_pm_temperature(void)
{
     int a,d,e;
	 //operate_module_temperature_data=read_modbus_data(33,8);
	  

		  while(1)
			{
			    key_scan();
				a=read_modbus_data(33,8);
				delay_ms(20);
			       
				   if(language_register==0)
                   {
                   
					GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);DS48(0,0,'功率模块温度',1,0);\r\n");
					delay_ms(20);
				
										 
										 

                   }
                   else
                   {
                   
					GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);DS48(0,0,'PM temp.',1,0);\r\n");
					delay_ms(20);
				
                   
										 
                   
                   }
					
					d=a/10;
					e=a%10;
					GpuSend4("DS48(420,0,'℃',0,0);\r\n");
					delay_ms(20);
					sprintf(buf,"DS48(320,0,'%2d.%d',0);",d,e);
					GpuSend4(buf);
					delay_ms(20);
					
							if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
					
					
									 
									 

				 
				   if(key_toggle_short_press)
            				 {
            				    key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(20);
								while(!KEY_IDLE);
							    break;
            				 }

			}

}

void	 read_operate_time(void)
{
    int a;
   operate_hour_data=read_modbus_data(3,40);
	 
	  while(1)
		{
		  
			key_scan();
			a=read_modbus_data(3,40);
			 delay_ms(20);
			if(language_register==0)
      {
                  
				GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	      delay_ms(20);
		    GpuSend4("DS48(0,0,'运行时间',1,0);\r\n");
		    delay_ms(20); 
			}
       else
       {
         GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	       delay_ms(20);
		     GpuSend4("DS48(0,0,'PM time',1,0);\r\n");
	       delay_ms(20);
       }
									
					GpuSend4("DS48(420,0,'H',0,0);\r\n");
	        delay_ms(20);
				  sprintf(buf,"DS48(340,0,'%3d',0);",a);
				  GpuSend4(buf);
			    delay_ms(20);

			   	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			

								
				if(key_toggle_short_press)
         {
				key_register_reset;
				GpuSend4("CLS(15);");
				delay_ms(20);
				while(!KEY_IDLE);
				break;
          }

		}

}


void soft_version(void)
{
		GpuSend4("CLS(15);");
		delay_ms(20);
	            
				   while(1)
				   {				  
				   

				    if(language_register==0)
                   {
                 
					GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
					delay_ms(18);
					GpuSend4("DS48(0,0,'软件版本号',1,0);\r\n");
					delay_ms(18);  
										 
										 
										 
                   }
                   else
                   {
         
					GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
					delay_ms(18);
					GpuSend4("DS48(0,0,'softversion',1,0);\r\n");
					delay_ms(18);
					}
	               
				          key_scan();
										
					   GpuSend4("DS48(0,50,'2SA1830_V2.0',0,0);\r\n");
	                    delay_ms(18);
										
					
					   	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,100,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,100,160);\r\n");
				    delay_ms(18);
				}
			
					
										
					   
					  if(key_toggle_short_press)
        				 {
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(20);
								while(!KEY_IDLE);
								break;

        				 }
        			
					}

}

void handware(void)
{
	   char b,c;
	   STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
       app_torque=TEXT_Buffer[eeprom_write_torque1];
	   app_speed =TEXT_Buffer[eeprom_write_speed1];
	   app_volt=TEXT_Buffer[eeprom_write_volt];
	   GpuSend4("CLS(15);");
	   delay_ms(18);

	   	 switch(app_speed)				   
	   {
	   case 10: b='A'; break;
	   case 11: b='B'; break;
	   case 12: b='C'; break;			   
	   case 13: b='D'; break;
	   case 14: b='E'; break;
	   
	   }

	    switch(app_volt)
	   {
	   
	   case 13: c='D'; break;
	   case 14: c='E'; break;
	   
	   }


    while(1)
	{
		
	

				if(language_register==0)
				{
				        GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
			        	delay_ms(38);
				        GpuSend4("DS48(0,0,'硬件型号',1,0);PIC(0,100,160);\r\n");
				        delay_ms(28);
				
				}
				else
				{
				
				       GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
				       delay_ms(38);
			           GpuSend4("DS48(0,0,'handware',1,0);PIC(0,100,159);\r\n");
			           delay_ms(28);
					 
				}
					 
					  
					  sprintf(buf,"DS48(124,50,'%d',1);",app_torque);
					  GpuSend4(buf);
					  delay_ms(38);
					  
					  key_scan();
					   

				  	  GpuSend4("DS48(0,50,'2SA85',1);DS48(153,50,'*-*',1);");
	                  delay_ms(38);
	               	  	 
					  key_scan();


					  
					  sprintf(buf,"DS48(230,50,'%c',1);",b);
					  GpuSend4(buf);
					  delay_ms(18);
					  sprintf(buf,"DS48(260,50,'%c',1);",c);
					  GpuSend4(buf);
					  delay_ms(18);
					  



					
					    if(key_toggle_short_press)
        				 {
        				  key_register_reset;
        				  GpuSend4("CLS(15);");
	                      delay_ms(28);
						  while(!KEY_IDLE);
                          break;
        				 }
        		                             
	}

}



void all_run_time(void)
{
   //int a;
	  all_run_time_data=read_modbus_data(13,15);
	
  while(1)
{
				
				key_scan();
				all_run_time_data=read_modbus_data(13,15);
				delay_ms(18);

				   if(language_register==0)
           {
				
				GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
				delay_ms(20);
				GpuSend4("DS48(0,0,'通电总时间',1,0);\r\n");
				delay_ms(20); 

            }
             else
            {
                   
				GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
				delay_ms(20);
				GpuSend4("DS48(0,0,'Runingtime',1,0);\r\n");
				delay_ms(20);
                   
             }
						 
				GpuSend4("DS48(420,0,'H',0,0);\r\n");
				delay_ms(20);
				sprintf(buf,"DS48(340,0,'%d',0);",all_run_time_data);
				GpuSend4(buf);
				delay_ms(20);
									 
				 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			


				   //display_every_bit(0x91,read_modbus_data(13,15));
				   if(key_toggle_short_press)
            {
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					break;
            }

			}

}

void switch_num(void)
{
	unsigned int num1,num2,num3,num4; 
	GpuSend4("CLS(15);");
	delay_ms(20); 
	STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
    num1=TEXT_Buffer[switch_num1];
	num2=TEXT_Buffer[switch_num2];
	num3=TEXT_Buffer[switch_num3];
	num4=TEXT_Buffer[switch_num4];
	switch_number=((num4<<24)+(num3<<16)+(num2*256)+num1);
	while(1)
	{
				   

				    if(language_register==0)
                   {
                 
					GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
					delay_ms(80);
					GpuSend4("DS48(0,0,'开关总次数',1,0);\r\n");
					delay_ms(80); 
                  }
                   else
                   {
						
						GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
						delay_ms(80);
						GpuSend4("DS48(0,0,'switch_num',1,0);\r\n");
						delay_ms(80); 
				  }
						sprintf(buf,"DS48(340,0,'%d',0);",switch_number);
						GpuSend4(buf);
						delay_ms(80);

										
										
										
	               
				     key_scan();
					   
					  if(key_toggle_short_press)
        		{
						key_register_reset;
						GpuSend4("CLS(15);");
						delay_ms(20);
						while(!KEY_IDLE);
						break;
                }

					   	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			

						 if(key_enter_long_press)
        				 {
							key_register_reset;
							switch_number=0;
							TEXT_Buffer[switch_num1]=(0);
							TEXT_Buffer[switch_num2]=(0);
							TEXT_Buffer[switch_num3]=(0);
							TEXT_Buffer[switch_num4]=(0);
							STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE); 
							GpuSend4("CLS(15);");
					     	delay_ms(20);
						    while(!KEY_IDLE);
							break;
							  
        				 } 
        			
		}

}


void torque_over_times_display(void)
 {
    GpuSend4("CLS(15);");
	  delay_ms(20); 
	  STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	  (torque_over_times)=TEXT_Buffer[eeprom_write_torque_over_times];
		while(1)
	 {
	      if(language_register==0)
    		{
						  
				GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
				delay_ms(80);
				GpuSend4("DS48(0,0,'过力矩次数',0,0);\r\n");
				delay_ms(80); 
					
				}
			  else
				{   
    			  	
				GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
				delay_ms(80);
				GpuSend4("DS48(0,0,'torque.ov times',0,0);\r\n");
				delay_ms(80);

				}

				
				key_scan();
				sprintf(buf,"DS48(380,0,'%d',0);",torque_over_times);
				GpuSend4(buf);
				delay_ms(80);

		 
		     if(key_toggle_short_press)
				 {
						key_register_reset;
						GpuSend4("CLS(15);");
						delay_ms(20);
						while(!KEY_IDLE);
						break;
				 }
				 
				 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



				 if(key_enter_long_press)
				 {
				  key_register_reset;
				  torque_over_times=0;
			      TEXT_Buffer[eeprom_write_torque_over_times]=(torque_over_times);
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE); 
				  GpuSend4("CLS(15);");
	              delay_ms(20); 
				  while(!KEY_IDLE);
						break;
				 }
				 
	    
	 }
  
  }



void	 read_fault_current(void)
{
			int a,b,c;
			a=read_modbus_data(6,3);
			b=a/10;
			c=a%10;	
			GpuSend4("CLS(15);");
			delay_ms(20);
	

			   	




  while(1)
 {

				GpuSend4("DS48(420,0,'A',0,0);\r\n");
				delay_ms(20);
			    sprintf(buf,"DS48(320,0,'%d.%d',0);",b,c);
				GpuSend4(buf);
				delay_ms(20);

				 a=read_modbus_data(6,3);
			b=a/10;
			c=a%10;






				key_scan();
				a=read_modbus_data(6,3);
				delay_ms(20);
				if(language_register==0)
				{
				
				
				GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);DS48(0,0,'故障输出电流',0,0);\r\n");
				delay_ms(20);
				
				
				
				
				}
				else
				{
				GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);DS48(0,0,'fault current',0,0);\r\n");
				delay_ms(20);
				
				
				}

				 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			




						GpuSend4("DS48(420,0,'A',0,0);\r\n");
						delay_ms(20);
						sprintf(buf,"DS48(320,0,'%d.%d',0);",b,c);
						GpuSend4(buf);
						delay_ms(20);


					if(key_toggle_short_press)
					{
						key_register_reset;
						GpuSend4("CLS(15);");
						delay_ms(20);
						while(!KEY_IDLE);
					
						break;
					
					}

}


}




void	 read_fault_voltage(void)
{
	
	  int a;
	  a=read_modbus_data(6,4);
	  
	  GpuSend4("CLS(15);");
	  delay_ms(20);
	 
	
	

	 while(1)
			{
					key_scan();
				    a=read_modbus_data(6,4);
			         delay_ms(20);
				   if(language_register==0)
            {
                  
					GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
					delay_ms(80);
					GpuSend4("DS48(0,0,'故障输出电压',0,0);\r\n");
					delay_ms(80); 


             }
                   else
                   {
					
					GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
					delay_ms(80);
					GpuSend4("DS48(0,0,'fault voltage',0,0);\r\n");
					delay_ms(80);
										 
                   
                   }

					   	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



				   
							GpuSend4("DS48(420,0,'V',0,0);\r\n");
							delay_ms(20);
							sprintf(buf,"DS48(340,0,'%d',0);",a);
							GpuSend4(buf);
							delay_ms(20);
									 
									 
				           if(key_toggle_short_press)
            				 {
							key_register_reset;
							GpuSend4("CLS(15);");
							delay_ms(20);
							while(!KEY_IDLE);
							break;
            				 }

			}

}


void	 read_fault_frequency(void)
{
	
	  int a,b;
	  a=read_modbus_data(6,1);
	  b=a/100;
	 
	  GpuSend4("CLS(15);");
	  delay_ms(20);
	
	  while(1)
			{
			  key_scan();
				
				a=read_modbus_data(6,1);
				b=a/100;
				
	      
				delay_ms(20);
			     if(language_register==0)
                   {
                   //display_chinese_letter(0x80,"故障输出频率");
                   //display_chinese_letter(0x95,"HZ");
										 GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                   delay_ms(20);
		                 GpuSend4("DS48(0,0,'故障输出频率',0,0);\r\n");
		                 delay_ms(20); 
										}
                   else
                   {
                   //display_chinese_letter(0x80,"frequency set");
                   //display_chinese_letter(0x95,"HZ");
                   GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                 delay_ms(20);
		               GpuSend4("DS48(0,0,'faultfrequency',0,0);\r\n");
	                 delay_ms(20);
										}
										
									 GpuSend4("DS48(420,0,'HZ',0,0);\r\n");
	                 delay_ms(20);
				           sprintf(buf,"DS48(340,0,'%d',0);",b);
				           GpuSend4(buf);
			             delay_ms(20);
						
							if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
						
						
									 
									 

				   //display_every_bit_2_point(0x91,read_modbus_data(6,1));
				   if(key_toggle_short_press)
					{
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					
					break;
                   }

			}

}

void	 read_fault_set_frequency(void)
{
    int a,b;
	  a=read_modbus_data(6,2);
	  b=a/100;
	 
	  GpuSend4("CLS(15);");
	  delay_ms(20);
    while(1)
			{
					key_scan();
				 a=read_modbus_data(6,2);
	              b=a/100;
	       
				  delay_ms(20);
			       
				   if(language_register==0)
                   {
                     //display_chinese_letter(0x80,"故障设定频率");
                     //display_chinese_letter(0x95,"HZ");
										 GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                   delay_ms(20);
		                 GpuSend4("DS48(0,0,'故障设定频率',0,0);\r\n");
		                 delay_ms(20); 

                   }
                   else
                   {
                   //display_chinese_letter(0x80,"frequency set");
                   //display_chinese_letter(0x95,"HZ");
									 GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                 delay_ms(20);
		               GpuSend4("DS48(0,0,'fault_set_fre',0,0);\r\n");
	                 delay_ms(20); 
										 
                   
                   }
					 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
				  
									 
									 GpuSend4("DS48(420,0,'HZ',0,0);\r\n");
	                 delay_ms(20);
				           sprintf(buf,"DS48(340,0,'%d',0);",b);
				           GpuSend4(buf);
			             delay_ms(20);
									 
				            if(key_toggle_short_press)
            				 {
            				  key_register_reset;
											GpuSend4("CLS(15);");
	                    delay_ms(20);
            				  while(!KEY_IDLE);
            				  //key_toggle_short_process();
									    break;
            				 }

			}

}






void	 read_fault_bus_voltage(void)
{
	
	  int a;
	  a=read_modbus_data(6,5);
	  
	  GpuSend4("CLS(15);");
	  delay_ms(20);
	
	

		    while(1)
			{
					key_scan();
				 a=read_modbus_data(6,5);
				 delay_ms(20);
			     if(language_register==0)
                   {
                   //display_chinese_letter(0x80,"故障母线电压 ");
                   //display_chinese_letter(0x95,"V ");
										  GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                   delay_ms(20);
		                 GpuSend4("DS48(0,0,'故障母线电压',0,0);\r\n");
		                 delay_ms(20); 

                   }
                   else
                   {
                   //display_chinese_letter(0x80,"DC bus voltage");
                   //display_chinese_letter(0x95,"V ");
                   GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                 delay_ms(20);
		               GpuSend4("DS48(0,0,'fault_volt',0,0);\r\n");
	                 delay_ms(20);
										 
										 
                   }
					
				  
				    //display_every_bit(0x91,read_modbus_data(6,5));
				          GpuSend4("DS48(420,0,'V',0,0);\r\n");
	                 delay_ms(20);
				           sprintf(buf,"DS48(340,0,'%3d',0);",a);
				           GpuSend4(buf);
			             delay_ms(20);
							if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
						
									 

				   if(key_toggle_short_press)
            {
            				  
							key_register_reset;
							GpuSend4("CLS(15);");
	            delay_ms(20);	 
						  while(!KEY_IDLE);
            	//key_toggle_short_process();
							break;
           }

			}




}
void	 read_fault_pm_temperature(void)
{
    int a;
	  a=read_modbus_data(6,6);
	 
	  GpuSend4("CLS(15);");
	  delay_ms(20);
	
	
	
	
    while(1)
			{
					key_scan();
				  a=read_modbus_data(6,6);
			       delay_ms(20);
			     
				   if(language_register==0)
                   {
                   
						GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
						delay_ms(20);
						GpuSend4("DS48(0,0,'故障模块温度',0,0);\r\n");
						delay_ms(20); 
										 

                   }
                   else
                   {
                  
						GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
						delay_ms(20);
						GpuSend4("DS48(0,0,'fault_temp',0,0);\r\n");
						delay_ms(20);
										 
                   }

				   //display_every_bit(0x91,read_modbus_data(6,6));
						GpuSend4("DS48(420,0,'℃',0,0);\r\n");
						delay_ms(20);
						sprintf(buf,"DS48(340,0,'%d',0);",a);
						GpuSend4(buf);
						delay_ms(20);
							if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
						 
									 
									 
				        if(key_toggle_short_press)
            		{
            			key_register_reset;
						GpuSend4("CLS(15);");
						delay_ms(20);
						while(!KEY_IDLE);
						//key_toggle_short_process();
						break;
            		}

			}

}






void	 read_first_fault(void)
{
			unsigned char a;
		    a=read_modbus_data(6,0);
			GpuSend4("CLS(15);");
			delay_ms(20);
			
	while(1)
	{
		           
				   a=read_modbus_data(6,0);
				   
				   	delay_ms(20);

				   if(language_register==0)
					{
					   GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                   delay_ms(20);

					   sprintf(buf,"DS48(0,200,'故障代码:%2d  ',0,0);\r\n",a);
                       GpuSend4(buf);
	                   delay_ms(30);

					   

						
					 if((a==1)||(a==2)||(a==3)||(a==9)||(a==21)||(a==22)||(a==23))
					{
					 
					  GpuSend4("DS48(340,0,'过流',0,0);\r\n");
	                  delay_ms(20);
					}
					if((a==11))
					{
					
					  GpuSend4("DS48(340,0,'欠压',0,0);\r\n");
	                  delay_ms(20);
					
					}
					if((a==4)||(a==5)||(a==6)||(a==7)||(a==34)||(a==35)||(a==36))
					{
					 
						GpuSend4("DS48(340,0,'过压',0,0);\r\n");
	                    delay_ms(20);
					
					}

					if((a==26))
					{
					
						GpuSend4("DS48(340,0,'U 缺相',0,0);\r\n");
	                    delay_ms(20);
					
					
					}

					if((a==27))
					{
					
						GpuSend4("DS48(340,0,'V 缺相',0,0);\r\n");
	                    delay_ms(20);
						
					
					}

					if((a==28))
					{
				
						GpuSend4("DS48(340,0,'W 缺相',0,0);\r\n");
	                    delay_ms(20);
						
					
					}


					 
					}
				  	else
					{
						GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                    delay_ms(20);
						sprintf(buf,"DS48(0,220,'Fault code:%2d',0,0);\r\n",a);
                         GpuSend4(buf);
	                     delay_ms(30);




						
					 if((a==1)||(a==2)||(a==3)||(a==9)||(a==21)||(a==22)||(a==23))
					{
					 
						GpuSend4("DS48(340,0,'Overcur',0,0);\r\n");
	                    delay_ms(20);
						
					
					}
					if((a==11))
					{
					 
						
						GpuSend4("DS48(340,0,'Undervolt',0,0);\r\n");
	                     delay_ms(20);
					
					}
					if((a==4)||(a==5)||(a==6)||(a==7)||(a==34)||(a==35)||(a==36))
					{
					
						GpuSend4("DS48(340,0,'Overvolt',0,0);\r\n");
	                   delay_ms(20);
						
					
					}

					if((a==26))
					{
					 
						GpuSend4("DS48(340,0,'UPhase',0,0);\r\n");
	                    delay_ms(20);
					  
					}

					if((a==27))
					{
				
						GpuSend4("DS48(340,0,'VPhase',0,0);\r\n");
	                       delay_ms(20);
					
					}

					if((a==28))
					{
					 
						GpuSend4("DS48(340,0,'WPhase',0,0);\r\n");
	                    delay_ms(20);
					
					}


					}
					key_scan();

				  
						if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			

			       
				   if(language_register==0)
                   {
                   
                    GpuSend4("DS48(0,0,'前一次故障',0,0);\r\n");
	                delay_ms(20);
					
                    
                   }
                   else
                   {
                 
                   GpuSend4("DS48(0,0,'fault1',0,0);\r\n");
	               delay_ms(20);
				   }

				  
				   if(key_toggle_short_press)
                  {
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					break;
                  }

		}

}








void	 read_second_fault(void)
{
	unsigned char a;
  a=read_modbus_data(6,7);
	//a=1; //调试用
	
	GpuSend4("CLS(15);");
	  delay_ms(20);
	
	while(1)
	{
				 
				   
				  a=read_modbus_data(6,7);
				  	delay_ms(20);
				 if(language_register==0)
					{
						 GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                     delay_ms(20);
						
						   sprintf(buf,"DS48(0,200,'故障代码:%2d  ',0,0);\r\n",a);
                       GpuSend4(buf);
	                   delay_ms(20);

						
						
					 if((a==1)||(a==2)||(a==3)||(a==9)||(a==21)||(a==22)||(a==23))
					{
					 //display_chinese_letter(0x94,"过流  ");
					GpuSend4("DS48(340,0,'过流',0,0);\r\n");
	                delay_ms(20);
					}
					if((a==11))
					{
					 //display_chinese_letter(0x94,"欠压  ");
					GpuSend4("DS48(340,0,'欠压',0,0);\r\n");
	                delay_ms(20);
					
					}
					if((a==4)||(a==5)||(a==6)||(a==7)||(a==34)||(a==35)||(a==36))
					{
					 //display_chinese_letter(0x94,"过压  ");
						GpuSend4("DS48(340,0,'过压',0,0);\r\n");
	                    delay_ms(20);
					
					}

					if((a==26))
					{
					 //display_chinese_letter(0x94,"U 缺相");
						GpuSend4("DS48(340,0,'U缺相',0,0);\r\n");
	                    delay_ms(20);
					
					
					}

					if((a==27))
					{
					 
							GpuSend4("DS48(340,0,'V缺相',0,0);\r\n");
	                        delay_ms(20);
						
					
					}

					if((a==28))
					{
					
						GpuSend4("DS48(340,0,'W缺相',0,0);\r\n");
	                    delay_ms(20);
						
					
					}


					 
					}
				  	else
					{
						GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                   delay_ms(20);
					sprintf(buf,"DS48(0,220,'Fault code:%2d',0,0);\r\n",a);
                       GpuSend4(buf);
	                   delay_ms(30);
	
						
					 if((a==1)||(a==2)||(a==3)||(a==9)||(a==21)||(a==22)||(a==23))
					{
					 //display_chinese_letter(0x93,"Overcur");
						GpuSend4("DS48(340,0,'Overcur',0,0);\r\n");
	                   delay_ms(80);
						
					
					}
					if((a==11))
					{
					 //display_chinese_letter(0x93,"Undervolt");
						
						GpuSend4("DS48(340,0,'Undervolt',0,0);\r\n");
	                      delay_ms(20);
					
					}
					if((a==4)||(a==5)||(a==6)||(a==7)||(a==34)||(a==35)||(a==36))
					{
					 //display_chinese_letter(0x93,"Overvolt");
						GpuSend4("DS48(340,0,'Overvolt',0,0);\r\n");
	                   delay_ms(20);
						
					
					}

					if((a==26))
					{
					 //display_chinese_letter(0x93,"UPhase");
						GpuSend4("DS48(340,0,'UPhase',0,0);\r\n");
	                  delay_ms(20);
					  
					}

					if((a==27))
					{
					 //display_chinese_letter(0x93,"VPhase");
						GpuSend4("DS48(340,0,'VPhase',0,0);\r\n");
	                    delay_ms(20);
					
					}

					if((a==28))
					{
					 //display_chinese_letter(0x93,"WPhase");
						GpuSend4("DS48(340,0,'WPhase',0,0);\r\n");
	                  delay_ms(20);
					
					}


					}
					key_scan();
			       
				   if(language_register==0)
                   {
                   //display_chinese_letter(0x80,"前一次故障记录");
                   GpuSend4("DS48(0,0,'前二次故障',0,0);\r\n");
	                 delay_ms(20);
					
                    
                   }
                   else
                   {
                  // display_chinese_letter(0x80,"fault record 1");
                   GpuSend4("DS48(0,0,'fault2',0,0);\r\n");
	                 delay_ms(20);
					 

                  }

				  	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			










				   //display_every_bit(0x90,read_modbus_data(6,0));
				   if(key_toggle_short_press)
           {
            	key_register_reset;
						  GpuSend4("CLS(15);");
	            delay_ms(20);
	             while(!KEY_IDLE);
            	//key_toggle_short_process();
							break;
           }

		}

}


void	 read_Third_fault(void)
{
	unsigned char a;
  a=read_modbus_data(6,8);
	//a=1; //调试用
	
	GpuSend4("CLS(15);");
	  delay_ms(20);
	
	while(1)
	{
			    a=read_modbus_data(6,8);
					delay_ms(20);

				 if(language_register==0)
					{
						 GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                     delay_ms(20);
						  sprintf(buf,"DS48(0,200,'故障代码:%2d  ',0,0);\r\n",a);
                       GpuSend4(buf);
	                   delay_ms(30);





					 if((a==1)||(a==2)||(a==3)||(a==9)||(a==21)||(a==22)||(a==23))
					{
					 //display_chinese_letter(0x94,"过流  ");
					GpuSend4("DS48(340,0,'过流',0,0);\r\n");
	                  delay_ms(20);
					}
					if((a==11))
					{
					 //display_chinese_letter(0x94,"欠压  ");
					GpuSend4("DS48(340,0,'欠压',0,0);\r\n");
	                     delay_ms(20);
					
					}
					if((a==4)||(a==5)||(a==6)||(a==7)||(a==34)||(a==35)||(a==36))
					{
					 //display_chinese_letter(0x94,"过压  ");
						GpuSend4("DS48(340,0,'过压',0,0);\r\n");
	                  delay_ms(20);
					
					}

					if((a==26))
					{
					 //display_chinese_letter(0x94,"U 缺相");
						GpuSend4("DS48(340,0,'U缺相',0,0);\r\n");
	                  delay_ms(20);
					
					
					}

					if((a==27))
					{
					 //display_chinese_letter(0x94,"V 缺相");
							GpuSend4("DS48(340,0,'V缺相',0,0);\r\n");
	                     delay_ms(20);
						
					
					}

					if((a==28))
					{
					// display_chinese_letter(0x94,"W 缺相");
						GpuSend4("DS48(340,0,'W缺相',0,0);\r\n");
	                   delay_ms(20);
						
					
					}


					 
					}
				  	else
					{
						GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                    delay_ms(20);
						sprintf(buf,"DS48(0,220,'Fault code:%2d',0,0);\r\n",a);
                       GpuSend4(buf);
	                   delay_ms(30);

						
					 if((a==1)||(a==2)||(a==3)||(a==9)||(a==21)||(a==22)||(a==23))
					{
					 //display_chinese_letter(0x93,"Overcur");
						GpuSend4("DS48(340,0,'Overcur',0,0);\r\n");
	                      delay_ms(20);
						
					
					}
					if((a==11))
					{
					
						
						GpuSend4("DS48(340,0,'Undervolt',0,0);\r\n");
	                    delay_ms(20);
					
					}
					if((a==4)||(a==5)||(a==6)||(a==7)||(a==34)||(a==35)||(a==36))
					{
					 
						GpuSend4("DS48(340,0,'Overvolt',0,0);\r\n");
	                    delay_ms(20);
						
					
					}

					if((a==26))
					{
					
						GpuSend4("DS48(340,0,'UPhase',0,0);\r\n");
	                     delay_ms(20);
					  
					}

					if((a==27))
					{
					 
						GpuSend4("DS48(340,0,'VPhase',0,0);\r\n");
	                     delay_ms(20);
					
					}

					if((a==28))
					{
					
						GpuSend4("DS48(340,0,'WPhase',0,0);\r\n");
	                    delay_ms(20);
					
					}


					}
					key_scan();
			       
				   if(language_register==0)
                   {
                   //display_chinese_letter(0x80,"前一次故障记录");
                   GpuSend4("DS48(0,0,'前三次故障',0,0);\r\n");
	               delay_ms(20);
					
                    
                   }
                   else
                   {
                  // display_chinese_letter(0x80,"fault record 1");
                   GpuSend4("DS48(0,0,'fault3',0,0);\r\n");
	                 delay_ms(20);
				  }

				   	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			








				   //display_every_bit(0x90,read_modbus_data(6,0));
				   if(key_toggle_short_press)
           {
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					//key_toggle_short_process();
					break;
           }

		}

}




	void relay1_open_close_set(void)
	{
	   unsigned char a;
		 GpuSend4("CLS(15);");
	   delay_ms(18);
				
	   a=TEXT_Buffer[eeprom_write_relay1_state];
		 a=a&0x01;
		 if((a!=1)&&(a!=0))
    {
      a=0;
    }			
		
		
	   while(1)
	   {
	     key_scan();

		    GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	   delay_ms(18);
		 GpuSend4("DS48(0,0,'继电器1状态',0,0);\r\n");
	   delay_ms(18);	



	     if(a==0)
			{
			
			GpuSend4("DS48(382,0,'正向',0,0);\r\n");
	    delay_ms(18);
				
			}
	      else
			{
			
				GpuSend4("DS48(382,0,'反向',0,0);\r\n");
	      delay_ms(18);
				
				
			}
	   		if((key_up_short_press)||(key_down_short_press))
				{
					 key_register_reset;
					 GpuSend4("CLS(15);");
	         delay_ms(18);
					 a=~a;
				}
	        
			if(key_enter_long_press)
				 {
				  key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(8);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(200); 
					 
				 
				  relay1_state=a;
          TEXT_Buffer[eeprom_write_relay1_state]=(a);	
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  while(!KEY_IDLE);
				  //function_point=relay2_define;
				  break;
				 }

				 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



			if(key_toggle_short_press)
        	{
				key_register_reset;
				GpuSend4("CLS(15);");
				delay_ms(20); 
				//initlcm();
				register_initial();
				while(!KEY_IDLE);

				//key_toggle_short_process();
				break;
        	}	
				       
	   }
	
	}
void relay2_open_close_set(void)
	{
	   unsigned char a;
		 GpuSend4("CLS(15);");
	   delay_ms(18);
				
	   a=TEXT_Buffer[eeprom_write_relay2_state];
		 a=a&0x01;
		 if((a!=1)&&(a!=0))
    {
      a=0;
    }			
		
		
	   while(1)
	   {
	     key_scan();

		   GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	   delay_ms(18);
		 GpuSend4("DS48(0,0,'继电器2状态',0,0);\r\n");
	   delay_ms(18);	

	     if(a==0)
			{
			
			GpuSend4("DS48(382,0,'正向',0,0);\r\n");
	    delay_ms(8);
				
			}
	      else
			{
			
				GpuSend4("DS48(382,0,'反向',0,0);\r\n");
	      delay_ms(8);
				
				
			}
	   		if((key_up_short_press)||(key_down_short_press))
				{
					 key_register_reset;
					 GpuSend4("CLS(15);");
	         delay_ms(8);
					 a=~a;
				}
	        
			if(key_enter_long_press)
				 {
				  key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(8);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(200); 
					 
				 
				  relay1_state=a;
          TEXT_Buffer[eeprom_write_relay2_state]=(a);	
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  while(!KEY_IDLE);
				  //function_point=relay2_define;
				  break;
				 }

				  	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



			if(key_toggle_short_press)
		    {
				key_register_reset;
				GpuSend4("CLS(15);");
				delay_ms(18); 
				//initlcm();
				register_initial();
				while(!KEY_IDLE);
				//key_toggle_short_process();
				break;
        	}	
				       
	   }
	
	}



	void relay3_open_close_set(void)
	{
	   unsigned char a;
		 GpuSend4("CLS(15);");
	   delay_ms(18);
					
	   a=TEXT_Buffer[eeprom_write_relay3_state];
		 a=a&0x01;
		 if((a!=1)&&(a!=0))
    {
      a=0;
    }			
		
		
	   while(1)
	   {
	     key_scan();


			 
			


		   	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



	    GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	   delay_ms(38);
		 GpuSend4("DS48(0,0,'继电器3状态',0,0);\r\n");
	   delay_ms(18);

	     if(a==0)
			{
			
			GpuSend4("DS48(382,0,'正向',0,0);\r\n");
	    delay_ms(8);
				
			}
	      else
			{
			
				GpuSend4("DS48(382,0,'反向',0,0);\r\n");
	      delay_ms(8);
				
				
			}
	   		if((key_up_short_press)||(key_down_short_press))
				{
					 key_register_reset;
					 GpuSend4("CLS(15);");
	         delay_ms(8);
					 a=~a;
				}
	        
			if(key_enter_long_press)
				 {
				  key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(8);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(200); 
					 
				 
				  relay1_state=a;
          TEXT_Buffer[eeprom_write_relay3_state]=(a);	
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  while(!KEY_IDLE);
				  //function_point=relay2_define;
				  break;
				 }
			if(key_toggle_short_press)
        	{
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(18); 
					register_initial();
					while(!KEY_IDLE);
				
					break;
        	}	
				       
	   }
	
	}


void relay4_open_close_set(void)
	{
	   unsigned char a;
		 GpuSend4("CLS(15);");
	   delay_ms(18);
		 			
	   a=TEXT_Buffer[eeprom_write_relay4_state];
		 a=a&0x01;
		 if((a!=1)&&(a!=0))
    {
      a=0;
    }			
		
		
	   while(1)
	   {
	     key_scan();

			 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



		  GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	   delay_ms(38);
		 GpuSend4("DS48(0,0,'继电器4状态',0,0);\r\n");
	   delay_ms(18);




	     if(a==0)
			{
			
			GpuSend4("DS48(382,0,'正向',0,0);\r\n");
	    delay_ms(8);
				
			}
	      else
			{
			
				GpuSend4("DS48(382,0,'反向',0,0);\r\n");
	      delay_ms(8);
				
				
			}
	   		if((key_up_short_press)||(key_down_short_press))
				{
					 key_register_reset;
					 GpuSend4("CLS(15);");
	         delay_ms(8);
					 a=~a;
				}
	        
			if(key_enter_long_press)
				 {
				  key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(8);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(200); 
					 
				 
				  relay1_state=a;
          TEXT_Buffer[eeprom_write_relay4_state]=(a);	
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  while(!KEY_IDLE);
				  //function_point=relay2_define;
				  break;
				 }
			if(key_toggle_short_press)
        	{
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(18); 
					//initlcm();
					register_initial();
					while(!KEY_IDLE);
					//key_toggle_short_process();
					break;
        	}	
				       
	   }
	
	}



	void relay5_open_close_set(void)
	{
	   unsigned char a;
		 GpuSend4("CLS(15);");
	   delay_ms(18);
				
	   a=TEXT_Buffer[eeprom_write_relay5_state];
		 a=a&0x01;
		 if((a!=1)&&(a!=0))
    {
      a=0;
    }			
		
		
	   while(1)
	   {
	     key_scan();

		  	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			


		 GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	   delay_ms(38);
		 GpuSend4("DS48(0,0,'继电器5状态',0,0);\r\n");
	   delay_ms(18);	




	     if(a==0)
			{
			
			GpuSend4("DS48(382,0,'正向',0,0);\r\n");
	    delay_ms(18);
				
			}
	      else
			{
			
				GpuSend4("DS48(382,0,'反向',0,0);\r\n");
	      delay_ms(18);
				
				
			}
	   		if((key_up_short_press)||(key_down_short_press))
				{
					 key_register_reset;
					 GpuSend4("CLS(15);");
	         delay_ms(8);
					 a=~a;
				}
	        
			if(key_enter_long_press)
				 {
				  key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(8);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(20); 
					 
				 
				  relay1_state=a;
          TEXT_Buffer[eeprom_write_relay5_state]=(a);	
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  while(!KEY_IDLE);
				  //function_point=relay2_define;
				  break;
				 }
			if(key_toggle_short_press)
        	{
        				  key_register_reset;
									GpuSend4("CLS(15);");
	                delay_ms(18); 
									//initlcm();
									register_initial();
        				  while(!KEY_IDLE);
        				  //key_toggle_short_process();
									break;
        	}	
				       
	   }
	
	}

void torque_select_process(void)
  {
  
        unsigned  char middle;
        //initlcm();
		    GpuSend4("CLS(15);");
	      delay_ms(20);
		   
		    STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
		    (torque_select)=TEXT_Buffer[eeprom_write_torque_select];
		    middle=torque_select;
			  timer0_reset();
			  timer0_count_enough=0;
				key_toggle_used=0;
				key_enter_used=0;
				key_up_used=0;
				key_down_used=0;
			  
			  
			 while(1)
			 { 
			    key_scan();

				  GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	      delay_ms(38);
		    GpuSend4("DS48(0,0,'力矩选择',0,0);\r\n");
	      delay_ms(20);	








		 
					if(middle==0)
					{
					
						GpuSend4("DS48(340,0,'  30',0,0);\r\n");
	          delay_ms(80);	
						
					}
					else if(middle==1)
					{
					
						GpuSend4("DS48(340,0,'  60',0,0);\r\n");
	          delay_ms(80);	
						
					}
					else if(middle==2)
					{
					
						GpuSend4("DS48(340,0,' 125',0,0);\r\n");
	          delay_ms(80);	
						
					}
					else if(middle==3)
					{
					 
						GpuSend4("DS48(340,0,' 250',0,0);\r\n");
	          delay_ms(80);	
						
					}
					else if(middle==4)
					{
					 
						GpuSend4("DS48(340,0,' 500',0,0);\r\n");
	          delay_ms(80);	
						
					}
					else if(middle==5)
					{
				
						GpuSend4("DS48(340,0,'1000',0,0);\r\n");
	          delay_ms(80);	
						
					}
					
					if(key_toggle_short_press)
				 {
				  
					
					key_register_reset;
					
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					
					break;
				 }
					
						if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			


						if(key_up_short_press)
					 {
					  key_register_reset;
					  middle++;
					     if(middle>5)
						   {
						   	middle=5;
						   }
							 //GpuSend4("CLS(15);");
	                         //delay_ms(20);
							 
							 
					 }
		
					 if(key_down_short_press)
					 {
					  key_register_reset;
					  
					      if(middle>=1)
						   {
						   	middle--;
							}
					       else
						   {
						   middle=0;
						   }
					    //GpuSend4("CLS(15);");
	            //delay_ms(20);
					 
					 }


			   	 if(key_enter_long_press)
				 {
				  key_register_reset;
					 
					GpuSend4("CLS(15);");
					delay_ms(20);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(20); 
				   torque_select=middle;
				   TEXT_Buffer[eeprom_write_torque_select]=(torque_select);
				   STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				   register_initial();
				   while(!KEY_IDLE);
				  //function_point=signal_off_set;
				   break;
				 }
					 

			} 
			  
			  
  
  }
  

void simens_add_speed_choice(void)
  {
				int middle;
				GpuSend4("CLS(15);");
				delay_ms(18);
					
				STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				middle=TEXT_Buffer[eeprom_write_speed_rpm_select]; 

			    if((middle<0)||(middle>2))
				{middle=0;}




            while(1)  
			{  
				GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
				delay_ms(38);
				GpuSend4("DS48(0,0,'速度选择',0,0);\r\n");
				delay_ms(18);
                	

			   
				if(middle==0)
				{
				
				GpuSend4("DS48(327,0,' 40',0,0);\r\n");
				delay_ms(18);	
				
				}
				if(middle==1)
				{
			
				
				GpuSend4("DS48(327,0,' 80',0,0);\r\n");
				delay_ms(18);	
				}
				if(middle==2)
				{
			
				GpuSend4("DS48(327,0,'160',0,0);\r\n");
				delay_ms(18);	
				
				}
			
				
				GpuSend4("DS48(407,0,'rpm',0,0);\r\n");
				delay_ms(18);
				 		

           if(key_toggle_short_press)
		   {
				  

				key_register_reset;
				GpuSend4("CLS(15);");
				delay_ms(20);
				while(!KEY_IDLE); 
				break;

	      }
	  
	        key_scan();
	  
				if(key_down_short_press)
				{
				key_register_reset;
				middle++;
				if(middle>2)
				{
				middle=0;
				}
				
				 
				
				}
				
				if(key_up_short_press)
				{
				key_register_reset;
				middle--;
				if(middle<0)
				{
				middle=2;
				}
			
						
			    }


					if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			



			   	 if(key_enter_long_press)
				 {
				  key_register_reset;
					 
					GpuSend4("CLS(15);");
					delay_ms(20);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(20); 
				   TEXT_Buffer[eeprom_write_speed_rpm_select]=(middle);
				speed_select=TEXT_Buffer[eeprom_write_speed_rpm_select];
				STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				register_initial();
				   while(!KEY_IDLE);
				 
				   break;
				 }

			  	if(key_toggle_short_press)
				 {
				  

					key_register_reset;
					
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					
					break;
				 }
				

	  
		
			}
	  
  }
  
  
 void analog_mode_enable(void)
 {
    unsigned char a;
	STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	switch_mode_sign=TEXT_Buffer[eeprom_write_local_remote_sign];
	a=switch_mode_sign&0x01;
         
    if((a!=1)&&(a!=0))
		{
		  a=0;
		}	 
    GpuSend4("CLS(15);");
	  delay_ms(20);
		
		while(1)
	  {
				     
    	if(language_register==0)
       {
          
					GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
					delay_ms(18);
					GpuSend4("DS48(0,0,'模拟量控制',0,0);\r\n");
					delay_ms(18);	
				}
       else
        {
            
					
					
					GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
					delay_ms(18);
					GpuSend4("DS48(0,0,'analog mode',0,0);\r\n");
					delay_ms(18);	
					
         }	
						
						 if(language_register==0)
             {
               if(a==0x01)
						  {
						  //display_chinese_letter(0x91,"关闭");
						  //display_address(0x93);
								GpuSend4("DS48(382,0,'关闭',0,0);\r\n");
					      delay_ms(18);	
								
								
               }
						  else
						  {
						  //display_chinese_letter(0x91,"开启");
						  //display_address(0x93);
								GpuSend4("DS48(382,0,'开启',0,0);\r\n");
					      delay_ms(18);	
								
						  }
             }
             else
             {
                          
						  if(a==0x01)
						  {
						  //display_chinese_letter(0x90,"disable");
						  //display_address(0x94);
								GpuSend4("DS48(311,0,'disable',0,0);\r\n");
					      delay_ms(18);
								
								
               }
						  else
						  {
						  //display_chinese_letter(0x90,"enable ");
						 // display_address(0x94);
								
								GpuSend4("DS48(311,0,'enable ',0,0);\r\n");
					      delay_ms(18);
								
               }
					   }
					
				      	key_scan();
					
					
			          if((key_up_short_press)||(key_down_short_press))
    					 {
    					    key_register_reset;
    					    a=~a;
						      a=a&0x01;
    					 }
					 
					 
        					 if(key_toggle_short_press)
        				 {
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(20);
								while(!KEY_IDLE);
								break;
        				 }

					if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			









        					 if(key_enter_long_press)
        				 {
            				key_register_reset;
            				GpuSend4("CLS(15);");
							delay_ms(18);
							GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
							delay_ms(20); 
							TEXT_Buffer[eeprom_write_local_remote_sign]=(a);
							STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
							register_initial();
							while(!KEY_IDLE);
							break;
			 
                } 
			                                
		}

 }
  
  
void signal_off_set(void)
  {
   
   unsigned char a;
   
   
		GpuSend4("CLS(15);");
		delay_ms(8);
		STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
    a=TEXT_Buffer[eeprom_write_emergency_position]; 
    a=a&0x01;  
    if((a!=1)&&(a!=0))
		 {
			a=0;
		 }	

		
   
     while(1)
	   {
	   	          
				     if(language_register==0)
    				{
					    
							GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	            delay_ms(18);
		          GpuSend4("DS48(0,0,'原位置保持设定',0,0);\r\n");
	            delay_ms(18);	
							
							
							
				    } 
					else
					{
					    
					 GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	         delay_ms(18);
	         GpuSend4("DS48(0,0,'keep pos.',0,0);\r\n");
					 delay_ms(18);	
					
					}
				   
          key_scan();
					 
					if((key_up_short_press)||(key_down_short_press))
					 {
					     key_register_reset;
					  	 a=~a;
						   a=a&0x01;
					 }
		      if(language_register==0)
             {
               if(a==0)
							 {
								 
								
								 GpuSend4("DS48(382,0,'关闭',0,0);\r\n");
					       delay_ms(18);	
								
								 }
                else
								{
								
									GpuSend4("DS48(382,0,'开启',0,0);\r\n");
					        delay_ms(18);	
								
									}
               }
              else
              {
                          
						  if(a==0)
						  {
							
								GpuSend4("DS48(311,0,'disable',0,0);\r\n");
					      delay_ms(18);	
								
								
							}
              else
						  {
								
							
								GpuSend4("DS48(311,0,'enable ',0,0);\r\n");
					      delay_ms(18);	
								
								
               }
								
               }
					 

		 
			   	if(key_enter_long_press)
				 {
				   key_register_reset;
					 GpuSend4("CLS(15);");
					 delay_ms(8);
					 GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					 delay_ms(20); 
					
				  TEXT_Buffer[eeprom_write_emergency_position]=(a);
				  TEXT_Buffer[emergency_position_register]=(a); 
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);


				  STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
                  emergency_position_register=TEXT_Buffer[eeprom_write_emergency_position];   



			      while(!KEY_IDLE);
				 
				  
				  break;
				 }
					 
			      
				  	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			







				  if(key_toggle_short_press)
				 {
				  
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					
					break;
				 }
			   	 					 
		
	   }
  
  }


void emergency_set(void)
{
 int temporary;
 GpuSend4("CLS(15);");
 delay_ms(18);
 STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
 signal_emergency_position_register=TEXT_Buffer[eeprom_write_signal_emergency_position];
 temporary=signal_emergency_position_register;
 if((temporary<0)||(temporary>100))
 {
   temporary=0;
 }
	
 while(1)
 {
				    
		 			  if(language_register==0)
				  {
				    GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	          delay_ms(18);
		        GpuSend4("DS48(0,0,'紧急位置设定',0,0);\r\n");
	          delay_ms(18);	
						
				  }
				  else
				  {
				     GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	           delay_ms(38);
	           GpuSend4("DS48(0,0,'emergency pos.',0,0);\r\n");
					   delay_ms(18);	
					}
					//display_percent_count_every_bit(0x91,temporary);
					//display_address(0x93);
					
					sprintf(buf,"DS48(350,0,'%3d',0);",temporary);
		      GpuSend4(buf); 
		      delay_ms(18);
		      GpuSend4("DS48(420,0,'%',0,0);\r\n");
          delay_ms(18);
					
					
          key_scan();
					
						if(key_up_short_press)
					 {
					  key_register_reset;
					  temporary++;
					  if(temporary>100)
						{
						   	temporary=100;
						}
					 }
		
					 if(key_down_short_press)
					 {
					  key_register_reset;
					  if(temporary>0)
						{
						   temporary--;
						 }
						  else
						  {
						  	temporary=0;

						  } 
						  
					 }

						if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			









			   	if(key_enter_long_press)
				 {
				  key_register_reset;
				 
					GpuSend4("CLS(15);");
					delay_ms(18);
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(20); 
					signal_emergency_position_register=temporary;
				    TEXT_Buffer[eeprom_write_signal_emergency_position]=(temporary);
				    STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  
				    STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
                    signal_emergency_position_register=TEXT_Buffer[eeprom_write_signal_emergency_position];
			       
				    while(!KEY_IDLE);
				    break;
				 }
					  if(key_toggle_short_press)
				 {
						key_register_reset;
						GpuSend4("CLS(15);");
						delay_ms(20);
						while(!KEY_IDLE);
						break;
				 }
			   	 
			}
  }

void switch_close_mode_select(void)
	{
     unsigned char a;
	   GpuSend4("CLS(15);");
     delay_ms(18);
	 	 STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	   a=TEXT_Buffer[eeprom_write_switch_operation_close_mode];
	   a=a&0x01;
		 if((a!=1)&&(a!=0))
		{
			a=0;
		}
		
     while(1)
		{
				   		  if(language_register==0)
                   {
                   //display_chinese_letter(0x81,"关断模式");
                   //display_chinese_letter(0x95,"确定");
						GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
						delay_ms(18);
						GpuSend4("DS48(0,0,'关断模式',0,0);\r\n");
						delay_ms(18);	 

                   }
                   else
                   {
                   //display_chinese_letter(0x80,"close mode");
                   //display_chinese_letter(0x95,"Enter");
					GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
					delay_ms(38);
					GpuSend4("DS48(0,0,'close mode',0,0);\r\n");
					delay_ms(18);	 
										 
                   }
				      
    					 if(language_register==0)
                {
                   if(a==0)
						        { 
                      //display_chinese_letter(0x91,"行程");
								GpuSend4("DS48(382,0,'行程',0,0);\r\n");
								delay_ms(18);
											
                     }
                    else
						         {
                     //display_chinese_letter(0x91,"力矩");
											 GpuSend4("DS48(382,0,'力矩',0,0);\r\n");
                       delay_ms(18);
											
                      }
						  
                 }
                  else
                     {
                      if(a==0)
						          { 
                         //display_chinese_letter(0x91,"POS.   ");
												 GpuSend4("DS48(382,0,'POS.',0,0);\r\n");
                        delay_ms(18);
											
												
                      }
                      else
						         { 
                          //display_chinese_letter(0x91,"torque ");
											 GpuSend4("DS48(335,0,'torque',0,0);\r\n");
                       delay_ms(18);
											
                      }
						 
                       }
					 
					  
					   key_scan();
					   
    					  if((key_up_short_press)||(key_down_short_press))
    					 {
    					   key_register_reset;
								  GpuSend4("CLS(15);");
                 delay_ms(8);
    					   a=~a;
						     a=a&0x01;
    					 }
					 
					 
					 
        				if(key_toggle_short_press)
        				 {
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(18);
								//initlcm();
								while(!KEY_IDLE);
								//key_toggle_short_process();
								break;
        				 }
        					 

							 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			




        					
        				  if(key_enter_long_press)
        				 {
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(18);
								GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
								delay_ms(20); 
								
								switch_operation_close_mode=a;
								TEXT_Buffer[eeprom_write_switch_operation_close_mode]=(a); 		                      
								STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
								register_initial();
								while(!KEY_IDLE);
								break;
							  
        				 } 
					 
					 
					                                
				}
 			
				               
	}	
	
	
 void switch_mode_select(void)
{
     unsigned char a;
	 
     GpuSend4("CLS(15);");
     delay_ms(8);
	 STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	 a=TEXT_Buffer[eeprom_write_switch_mode];
      
	 if((a!=1)&&(a!=0)&&(a!=2))
     {
			a=0;
     }


	
	   while(1)
		{
				   
				        if(language_register==0)
                   {
                   
					  GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                  delay_ms(18);
		              GpuSend4("DS48(0,0,'触发模式',0,0);\r\n");
	                  delay_ms(18);	 
										 
										 
                   }
                   else
                   {
					  GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                  delay_ms(38);
	                  GpuSend4("DS48(0,0,'Trigger',0,0);\r\n");
					  delay_ms(18);	 
										 	 
									
                   }       
									 
								if(language_register==0)
								{
								if(a==0)
								{


								GpuSend4("DS48(340,0,'点动',0,0);\r\n");
								delay_ms(8);




								}
								else  if(a==1)
								{

								GpuSend4("DS48(340,0,'自保持',0,0);\r\n");
								delay_ms(18);


								}

								else
								{
								
								 	GpuSend4("DS48(340,0,'两线制',0,0);\r\n");
								    delay_ms(18);
								
								}




								}
								else
								{

								if(a==0)
								{

								GpuSend4("DS48(340,0,'JOG',0,0);\r\n");
								delay_ms(18);


								}
								else if(a==1)
								{

								GpuSend4("DS48(264,0,'self-hold',0,0);\r\n");
								delay_ms(18);

								}

							     else 
								{

								GpuSend4("DS48(264,0,'Two-line',0,0);\r\n");
								delay_ms(18);

								}

								}


					    
					      key_scan();
					   
    					   if((key_up_short_press))
    					 {
    					  key_register_reset;
						  GpuSend4("CLS(15);");
                          delay_ms(18);
    					  a++;
						  if(a>2)
						  {a=0;}
    					 }
					 
						   if((key_down_short_press))
    					 {
    					  key_register_reset;
						  GpuSend4("CLS(15);");
                          delay_ms(18);
    					  a--;

						  if(a<0)
						  {a=2;}

    					 }



					     
					 
					 
        					 if(key_toggle_short_press)
        				 {
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(20);
								while(!KEY_IDLE);
								//key_toggle_short_process();
								break;
			           
        				 }
        					 
				  if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			







        					
        					   if(key_enter_long_press)
        				 {
            				    key_register_reset;
            				    GpuSend4("CLS(15);");
					            delay_ms(18);
					            GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					            delay_ms(20); 
								switch_mode_select_variable=a; 
								TEXT_Buffer[eeprom_write_switch_mode]=(a);
				                STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
							    register_initial();
								while(!KEY_IDLE);
							    break;
							  
        				 } 
					                              
				  }
               
	}
	
	
 void switch_mode_enable(void)
  {
          unsigned char a;
		  GpuSend4("CLS(15);");
		  delay_ms(18);
		  STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
          a=TEXT_Buffer[eeprom_write_local_remote_sign];
		  a=a&0x01;
          if((a!=1)&&(a!=0))
			{
					a=0;
			}   
			
          while(1)
{
			if(language_register==0)
			{
			
			   GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
			   delay_ms(18);
			   GpuSend4("DS48(0,0,'开关量控制',0,0);\r\n");
			   delay_ms(18);	  
			}
			else
			{
			
			   GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
			   delay_ms(18);
			   GpuSend4("DS48(0,0,'switch',0,0);\r\n");
			   delay_ms(18);	  
			}
    				if(analog_limit_sign==0)
					{	
						
						 if(language_register==0)
               {
              if(a==0)
						  {
						 
							 GpuSend4("DS48(360,0,'关闭',0,0);\r\n");
			         delay_ms(18);	
								
              }
						  else
						  {
						
							 GpuSend4("DS48(360,0,'开启',0,0);\r\n");
			         delay_ms(18);
								
								
								
						  }
             }
            else
             {
                          
						  if(a==0)
						  {
						  
								GpuSend4("DS48(311,0,'disable',0,0);\r\n");
			                    delay_ms(18);
								
                          }
						  else
						  {
						  
								GpuSend4("DS48(311,0,'enable ',0,0);\r\n");
			                     delay_ms(18);
								
                            }
			}
					}
					else
					{
					
					
					
					    if(language_register==0)
                      {
                              GpuSend4("DS48(360,0,'关闭',0,0);\r\n");
			                  delay_ms(18);	
												
                      }
                       else
                       {
                              GpuSend4("DS48(360,0,'disable',0,0);\r\n");
			                  delay_ms(18);	 
												 
                       }
					
					} 
					  
					     
						 key_scan();


				 if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
						 
			           if((key_up_short_press)||(key_down_short_press))
    					 {
    					  key_register_reset;
    					  a=~a;
						  a=a&0x01;  
    					 }
					 
					    
					 
					 
        				if(key_toggle_short_press)
        				 {
        				  
        
						key_register_reset;
						GpuSend4("CLS(15);");
						delay_ms(18);
						
						while(!KEY_IDLE);
						
					
						break;
        				 }
        					 if(key_enter_long_press)
        				 {
            				       
								   
									   key_register_reset;
            				          
							  
        							 // initlcm();
                    				 // display_chinese_letter(0x83,"ok");
									   GpuSend4("CLS(15);");
					            delay_ms(18);
					            GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					            delay_ms(20); 
									 
                                      if(analog_limit_sign==0)
									  {
        									 
        								TEXT_Buffer[eeprom_write_local_remote_sign]=(a);
        								
									  }
									  else
									  {
									    TEXT_Buffer[eeprom_write_local_remote_sign]=(1);
									  }
									  
									  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
									  register_initial();
										while(!KEY_IDLE);
                    break;
			 
        				 } 
	                               
				  }
 
  }	
	
	


void start_point_set(void)
{
  unsigned char  long_press_up_sign=0;
  unsigned char  long_press_down_sign=0;
  
  zero_pozition_relay_off();
  full_pozition_relay_off();
  slow_speed_off();
  slow_speed_off();
  direction_judge_complete_sign=0;
  GpuSend4("CLS(15);\r\n");
  delay_ms(18); 
  
  
while(1)
{         
	      
				if(language_register==0)
			{
			   
			  GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
			  delay_ms(20);
			  GpuSend4("DS48(0,0,'关末端设定',0,0);\r\n");
			  delay_ms(20);
			}
			else
			{
			  
			  GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
			  delay_ms(30);
			  GpuSend4("DS48(0,0,'close.p set',0,0);\r\n");
			  delay_ms(20);
			}
		 
  
		     slow_speed_off();   							  
            
		     delay_short(8000);
		     check_motor_current();

		         if(quit_sign==1)
				 {
				  quit_sign=0;
            	  break;    
				 
				 }  
			   	
				  key_scan();
				  encoder_act();
				  if(key_enter_long_press)
				 { 
				      key_register_reset;
				  	  start_point_ad_h_register=turns/128;
						  start_point_ad_l_register=turns%128;
						  start_angle_register_h=angle/128;
						  start_angle_register_l=angle%128;
						  start_point_ad=all_angle;
						  all_distance=end_point_ad-start_point_ad;
						 
							if(start_point_ad<end_point_ad)  //
							{
							if(go_up_ad==255)
							{
							   go_up_direction=100;
							}
							else
							{
							   go_up_direction=0;
							}
							}
							else
							{

							if(go_up_ad==255)
							{
							   go_up_direction=0;
							}
							else
							{
							   go_up_direction=100;
							}

							}

							TEXT_Buffer[eeprom_write_start_point_ad_h]=(start_point_ad_h_register);
							TEXT_Buffer[eeprom_write_start_point_ad_l]=(start_point_ad_l_register);
							TEXT_Buffer[eeprom_write_start_angle_h]=(start_angle_register_h);
							TEXT_Buffer[eeprom_write_start_angle_l]=(start_angle_register_l);
							TEXT_Buffer[eeprom_write_move_direction]=(go_up_direction);
							TEXT_Buffer[eeprom_write_pass_border_sign]=(pass_border_sign);
							STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
							GpuSend4("CLS(15);\r\n");
							delay_ms(18); 
							GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
							delay_ms(200);	// OK 
							while(!KEY_IDLE);	
							
							function_point=end_point_set;
							 menu_point=getmenu(111);
						    (*function_point)();
							

						    break;		
							
				 }
				      
					  

							sprintf(buf,"DS48(340,0,'%ld',0);\r\n",turns);
							GpuSend4(buf); 
							delay_ms(20);
                     
	
				   if(direction_judge_complete_sign==0)
				   {
					      go_up_derection_detect();
				   }
			      
				 if(key_toggle_short_press)
				 {
						key_register_reset;
						GpuSend4("CLS(15);\r\n");
						delay_ms(18); 
						while(!KEY_IDLE);
						break;
				 } 
			   	 
				  	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
				 
				  if(key_toggle_long_press)
				 {
				 
				  break;
				 }
			     
				    if(key_up_long_press)
					{
					  key_register_reset;
					  if(local_register!=0)
					  { 
					     long_press_up_sign=1;
					     long_press_down_sign=0;
					  }
					}
					else if(key_down_long_press)
					{
					  key_register_reset;
					   if(local_register!=0)
					   {
						 long_press_up_sign=0;
					     long_press_down_sign=1;
					   }
					}
					
					
					if((KEY_ENTER)||(KEY_TOGGLE))
					{
					  long_press_up_sign=0;
					  long_press_down_sign=0;
					}
					
				    
				     
				    if(long_press_up_sign==1)
					{
					    if(KEY_DOWN)
						{
						long_press_up_sign=0;
					    long_press_down_sign=0;
						}
					} 
				    if(long_press_down_sign==1)
					{
					    if(KEY_UP)
						{
						long_press_up_sign=0;
					    long_press_down_sign=0;
						}
					} 
				  
				    if((KEY_UP)||(long_press_up_sign==1))
					{
					      if(torque_over_sign==0)
						  {
						  //torque_led_on;
						  go_up_on();
						  }
						  
					}
					else if((KEY_DOWN)||(long_press_down_sign==1))
					{
					     if(torque_over_sign==0)
						 {
						 //torque_led_on;
						 go_down_on();
					     }
						  
					}
                    else
					{
					    stop();
					    LED_ZERO=1;
					    LED_FULL=1;
                	}
				  
				  
				   
	           
	   }
  }




void end_point_set(void)
{
  
		unsigned char  long_press_up_sign=0;
		unsigned char  long_press_down_sign=0;
	    
		slow_speed_off();
        slow_speed_off();
		direction_judge_complete_sign=0;
        zero_pozition_relay_off();
	    full_pozition_relay_off();
        GpuSend4("CLS(15);\r\n");
        delay_ms(18); 

        while(1)
	   {
	            
			if(language_register==0)
			{
			
			GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
			delay_ms(18);
			GpuSend4("DS48(0,0,'开末端设定',1,0);\r\n");
			delay_ms(18);
			}
			else
			{
			
			GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
			delay_ms(18);
			GpuSend4("DS48(0,0,'open.p set',1,0);\r\n");
			delay_ms(18);
			}
			    
				delay_short(8000);
			    check_motor_current(); 
				delay_ms(10);
				
				 
			 		if(language_register==1)
				{
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
			 
			 
		         if(quit_sign==1)
				 {
				  quit_sign=0;
            	  break;    
				 
				 }  
			   	
				  
				  key_scan();
				  encoder_act();
				  sprintf(buf,"DS48(340,0,'%ld',0);\r\n",turns);
		          GpuSend4(buf); 
		          delay_ms(18);
				 
				 if(direction_judge_complete_sign==0)
				   {
					go_up_derection_detect();
				  }
				 
				
				  if(key_enter_long_press)
				 { 
				        key_register_reset;
				  	    
						 
						  end_point_ad_h_register=turns/128;
						  end_point_ad_l_register=turns%128;
						  end_angle_register_h=angle/128;
						  end_angle_register_l=angle%128;
						  end_point_ad=all_angle;
						  all_distance=end_point_ad-start_point_ad;
					 
                					if(direction_judge_complete_sign==1)
                					{ 
                						 				
										  if(start_point_ad<end_point_ad)
                						  {
                						      if(go_up_ad==255)
                							  {
                							   go_up_direction=100;
                							  }
                							  else
                							  {
                							   go_up_direction=0;
                							  }
                						  }
                						  else
                						  {
                						  
                						     if(go_up_ad==255)
                							  {
                							   go_up_direction=0;
                							  }
                							  else
                							  {
                							   go_up_direction=100;
                							  }
                						  
                						  }
														
										
									TEXT_Buffer[eeprom_write_end_point_ad_h]=(end_point_ad_h_register);
									TEXT_Buffer[eeprom_write_end_point_ad_l]=(end_point_ad_l_register);
									TEXT_Buffer[eeprom_write_end_angle_h]=(end_angle_register_h);
									TEXT_Buffer[eeprom_write_end_angle_l]=(end_angle_register_l);
									TEXT_Buffer[eeprom_write_move_direction]=(go_up_direction);
									TEXT_Buffer[eeprom_write_pass_border_sign]=(pass_border_sign);
									STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
                                    GpuSend4("CLS(15);\r\n");
	                                delay_ms(10); 
					                GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					                delay_ms(200);	
                      	            while(!KEY_IDLE);	
                    		        break;
            				         }
								    else
									{
								       GpuSend4("CLS(15);\r\n");
									   delay_ms(8); 
									   GpuSend4("DS48(0,0,'fault!',0,0);\r\n");
									   delay_ms(200);	
									   while(!KEY_IDLE);
                                       break;
									}
				 } 
				  
				   
		

			 
				 if(key_toggle_short_press)
				 {
				        key_register_reset;
						GpuSend4("CLS(15);");
						delay_ms(20);
						while(!KEY_IDLE);
						break;
				 } 
			   	 
				  if(key_toggle_long_press)
				 {
				
				  break;
				 }
			  
			  
			       if(key_up_long_press)
					{
					  key_register_reset;
					  if(local_register!=0)
					  {
					  long_press_up_sign=1;
					  long_press_down_sign=0;
					  }
					}
					else if(key_down_long_press)
					{
					  key_register_reset;
					  if(local_register!=0)
					  {
					  long_press_up_sign=0;
					  long_press_down_sign=1;
					  }
					}
					
					
					if((KEY_ENTER)||(KEY_TOGGLE))
					{
					  long_press_up_sign=0;
					  long_press_down_sign=0;
					}
					
				  
				     if(long_press_up_sign==1)
					{
					    if(KEY_DOWN)
						{
						long_press_up_sign=0;
					    long_press_down_sign=0;
						}
					} 
				    if(long_press_down_sign==1)
					{
					    if(KEY_UP)
						{
						long_press_up_sign=0;
					    long_press_down_sign=0;
						}
					} 
				  
				    if((KEY_UP)||(long_press_up_sign==1))
					{
					      if(torque_over_sign==0)
						  {
						  
						  go_up_on();
						  }
						  
					}
					else if((KEY_DOWN)||(long_press_down_sign==1))
					{
					     if(torque_over_sign==0)
						 {
						 
						 go_down_on();
					     }
						  
					}
                 else
					{
					   stop();
					   LED_ZERO=1;
					   LED_FULL=1;

					}

	   
	   }
  } 
  



 





  void zero_current_set(void)
  {		   
          
		  
  		  unsigned int middle;
		  GpuSend4("CLS(15);\r\n");
		  delay_ms(18);
	      GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	      delay_ms(18);
	      GpuSend4("DS48(0,0,'输入4mA电流AD',0,0);\r\n");
		  //while(!KEY_IDLE);
		   while(1)
		   {								  
		        key_scan();
		   	    middle=Get_Adc(10);
		        GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	            delay_ms(38);
	            GpuSend4("DS48(0,0,'输入4mA电流AD',0,0);\r\n");
				delay_ms(18);
				sprintf(buf,"DS48(340,0,'%4d',0);\r\n",middle);
		        GpuSend4(buf); 
			    delay_ms(20); 
			   
			
			    if(key_enter_long_press)
				 {
				  key_register_reset;
				 
				  zero_mA_ad=middle;
				  zero_mA_ad_h_register=middle/256;
				  zero_mA_ad_l_register=middle%256;
				  TEXT_Buffer[eeprom_write_zero_mA_ad_h]=zero_mA_ad_h_register;
				  TEXT_Buffer[eeprom_write_zero_mA_ad_l]=zero_mA_ad_l_register;
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  GpuSend4("CLS(15);\r\n");
	              delay_ms(10); 
				  GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
				  delay_ms(200);	
				
				  function_point=full_current_set;
				  (*function_point)();
				  break;
				 }
			    
				 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			


          if(key_toggle_short_press)
			{
					  
				key_register_reset;
				GpuSend4("CLS(15);");
				delay_ms(20);
				while(!KEY_IDLE);
				break;
							 
			  
             
		   }
			 
		 }
  }

 


  void full_current_set(void)
  {     
  	    
		  unsigned int middle;
		  GpuSend4("CLS(15);\r\n");
		  delay_ms(18);
	      GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	      delay_ms(38);
	      GpuSend4("DS48(0,0,'输入20mA电流AD',0,0);\r\n");
		  delay_ms(18);
		   //while(!KEY_IDLE);
		   while(1)
		   {
		   	      if(key_toggle_short_press)
				 {
							  

						key_register_reset;
						GpuSend4("CLS(15);");
						delay_ms(20);
						while(!KEY_IDLE);
						break;
				}
				 
				key_scan();
			    middle=Get_Adc(current_ad_channel);
				GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	            delay_ms(18);
	            GpuSend4("DS48(0,0,'输入20mA电流AD',0,0);\r\n");
				delay_ms(18);			 
							 
					if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
						 
							 
								 
			    sprintf(buf,"DS48(340,0,'%4d',0);\r\n",middle);
			    GpuSend4(buf); 			 
				if(key_enter_long_press)
				 {
				  key_register_reset;
				  GpuSend4("CLS(15);\r\n");
	              delay_ms(18); 
				  GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
				  delay_ms(200);	// OK ??0.2?
				  full_mA_ad=middle;
				  all_mA_ad=full_mA_ad-zero_mA_ad;
                  full_mA_ad_h_register=full_mA_ad/256;
				  full_mA_ad_l_register=full_mA_ad%256;
				  
				  TEXT_Buffer[eeprom_write_full_mA_ad_h]=full_mA_ad_h_register;
				  TEXT_Buffer[eeprom_write_full_mA_ad_l]=full_mA_ad_l_register;
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
				  while(!KEY_IDLE);
				 
				  break;
				 }
			   
		   }
  
  
  }
  


void zero_feedback_adjust(void)
 {
   unsigned int middle;
   
	GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	delay_ms(18);
	GpuSend4("DS48(0,0,'输出4mA电流',0,0);\r\n");
	delay_ms(18);			 
	
    STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	pwm_value_zero_h_register= TEXT_Buffer[eeprom_write_pwm_value_zero_h];
    pwm_value_zero_l_register= TEXT_Buffer[eeprom_write_pwm_value_zero_l];
	zero_pwm_value_register=pwm_value_zero_h_register*256+pwm_value_zero_l_register;
	middle=zero_pwm_value_register;
	 //middle=6700;
	//middle=6236;

	 while(1)
	  {
	                  
					
					
		   GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	       delay_ms(38);
	       GpuSend4("DS48(0,0,'输出4mA电流',0,0);\r\n");
	       delay_ms(18);			 
	       sprintf(buf,"DS48(340,0,'%4d',0);\r\n",middle);
		   GpuSend4(buf); 
           delay_ms(18);			
			   PWM(middle);
					
					key_scan();
					
					 if(key_up_short_press)
					 {
					  key_register_reset;
					  middle++;
					 }
		
					 if(key_down_short_press)
					 {
					  key_register_reset;
					  middle--;
					 }
					 
					 if(key_up_long_press)  //  nice!
					 {
					  
					  middle++;
					  delay_ms(20);
					 }
		
					 if(key_down_long_press)
					 {
					  
					  middle--;
						delay_ms(20);
					 }


					if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			

    				  if(key_enter_long_press)
    				 {
						key_register_reset;
						GpuSend4("CLS(15);\r\n");
						delay_ms(8); 
						GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
						delay_ms(200);
						zero_pwm_value_register=middle;
						pwm_value_zero_h_register=zero_pwm_value_register/256;
						pwm_value_zero_l_register=zero_pwm_value_register%256;
						TEXT_Buffer[eeprom_write_pwm_value_zero_h]=pwm_value_zero_h_register;
						TEXT_Buffer[eeprom_write_pwm_value_zero_l]=pwm_value_zero_l_register; 
						STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
						while(!KEY_IDLE);
    				  
    				  
    				  break;
    				 }
    			     
					  if(key_toggle_short_press)
							 {
							  key_register_reset;
							  GpuSend4("CLS(15);");
                              delay_ms(20);
                              while(!KEY_IDLE); 
			                  break;
							 }

		   			 if(KEY_IDLE)
					 {
					  key_register_reset;
					  
					 }
		
					 
					 
	  }
 }
  
 void full_feedback_adjust(void)
 {
 
     
	 unsigned int middle;
	 
     //display_chinese_letter(0x81,"输出20mA电流");
	// display_chinese_letter(0x95,"确定");

	 GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	 delay_ms(18);
	 GpuSend4("DS48(0,0,'输出20mA电流',0,0);\r\n");
	 delay_ms(18);
	 STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	 pwm_value_full_h_register= TEXT_Buffer[eeprom_write_pwm_value_full_h];
   pwm_value_full_l_register= TEXT_Buffer[eeprom_write_pwm_value_full_l];
	 full_pwm_value_register=pwm_value_full_h_register*256+pwm_value_full_l_register;

	 middle=full_pwm_value_register;
	//middle=35479;
    //middle=34480;	 
	 while(1)
	  {
					
			GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
			delay_ms(38);
			GpuSend4("DS48(0,0,'输出20mA电流',0,0);\r\n");
			delay_ms(18);
			sprintf(buf,"DS48(340,0,'%4d',0);\r\n",middle);
			GpuSend4(buf); 
			delay_ms(18);
			PWM(middle);
			key_scan();
					
					if(key_up_short_press)
					 {
					  key_register_reset;
					  middle++;
					 }
		
					 if(key_down_short_press)
					 {
					  key_register_reset;
					  middle--;
					 }
					 
					 if(key_up_long_press)
					 {
					  
					  middle++;
					  delay_ms(20);
					 }
		
					 if(key_down_long_press)
					 {
					  
					  middle--;
						 delay_ms(20);
					 }


    			      if(key_enter_long_press)
    				 {
						key_register_reset;
						GpuSend4("CLS(15);\r\n");
						delay_ms(10); 
						GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
						delay_ms(200);
						full_pwm_value_register=middle;
						pwm_value_full_h_register=full_pwm_value_register/256;
						pwm_value_full_l_register=full_pwm_value_register%256;
						all_pwm_value_register=full_pwm_value_register-zero_pwm_value_register;
						TEXT_Buffer[eeprom_write_pwm_value_full_h]=pwm_value_full_h_register;
						TEXT_Buffer[eeprom_write_pwm_value_full_l]=pwm_value_full_l_register; 
						STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
						while(!KEY_IDLE);
						function_point=sensitive_set;
						break;
    				 }

					 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			








    			  	 
	               if(key_toggle_short_press)
							 {
							key_register_reset;
							
							GpuSend4("CLS(15);");
							delay_ms(20);
							while(!KEY_IDLE);
							break;
							 } 

						   if(KEY_IDLE)
					 {
					  key_register_reset;
					  
					 }
					 
	  }
 }
 

void torque_compensate_adjust(void)
 {
  
	//unsigned int middle,count;

	unsigned int middle;
	signed int a,b,c;
	unsigned char point;
	 
	GpuSend4("CLS(15);\r\n");
	delay_ms(18); 

	 
	point=0;
//	count=0;
	middle=(unsigned int)TEXT_Buffer[eeprom_write_torque_compensate_h]*256+
	TEXT_Buffer[eeprom_write_torque_compensate];
	
	 
	a=middle/100;
	b=middle%100/10;
	c=middle%10;

	delay_long(20);
	key_register_reset;
	timer0_reset();
			
	timer0_count_enough=0;
	key_toggle_used=0;
	key_enter_used=0;
	key_up_used=0;
	key_down_used=0;
	while(1)
	{ 
		key_scan();
		GpuSend4("DS48(0,0,'上力矩补偿值',0,0);\r\n");
		delay_ms(18);
	   	GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	    delay_ms(38);


		 switch(point)
     {
	    
		case 0:sprintf(buf,"DS48(380,0,'%d',1);DS48(405,0,'%d',0);DS48(455,0,'%d',0);",a,b,c);GpuSend4(buf);delay_ms(18);break;
        case 1:sprintf(buf,"DS48(405,0,'%d',1);DS48(380,0,'%d',0);DS48(455,0,'%d',0);",b,a,c);GpuSend4(buf);delay_ms(18);break;
        case 2:sprintf(buf,"DS48(455,0,'%d',1);DS48(380,0,'%d',0);DS48(405,0,'%d',0);",c,a,b);GpuSend4(buf);delay_ms(18);break;
		
													
     }


	  if(key_down_short_press)
    {
      key_register_reset;
      switch(point)
      {
        case 0:a+=1;break;
        case 1:b+=1;break;
        case 2:c+=1;break;
      }
									
   }
					           
		if(key_up_short_press)
       {
        key_register_reset;
        switch(point)
        {
          case 0:a-=1;break;
          case 1:b-=1;break;
          case 2:c-=1;break;
         }
									
	   }


           if(a>9)
		   {
		   a=0;
		   }
           if(b>9)
		   {
		   b=0;
		   }
		   if(c>9)
		   {
		   c=0;
		   }
		   
		   if(a<0)
		   {
		   a=9;
		   }
		   
		   if(b<0)
		   {
		   b=9;
		   }
		   
		   if(c<0)
		   {
		   c=9;
		   }
		     

		 	 GpuSend4("DS48(430,0,'.',0,0);");
             delay_ms(20);

	 	   	     if(key_enter_long_press)
				 {
				  key_register_reset;
				  
					GpuSend4("CLS(15);\r\n");
	                delay_ms(10); 
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(20); 
					 
				    middle=a*100+b*10+c;
				    TEXT_Buffer[eeprom_write_torque_compensate]=(middle%256);
				    TEXT_Buffer[eeprom_write_torque_compensate_h]=(middle/256);
				    standard_torque=((float)(TEXT_Buffer[eeprom_write_torque_compensate_h]*256+
				    TEXT_Buffer[eeprom_write_torque_compensate]-TEXT_Buffer[eeprom_write_torque_compensate_low])*
					(TEXT_Buffer[eeprom_write_torque_percent]-3)/7.0+TEXT_Buffer[eeprom_write_torque_compensate_low]+0.5);
           
					STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
					write_modbus_data(12,9,(unsigned int)(middle*1.5)/256,(unsigned int)(middle*1.5)%256);
				  //function_point=torque_compensate_low_adjust;
				    while(!KEY_IDLE);
				    break;
				 }
					 
					 if(key_enter_short_press)
				 {
				  
				    key_register_reset;
				    point+=1;
					if(point>2)
					{
					  point=0;
					}

				 }
			   	 

				 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			





				  GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
		          delay_ms(18);

				  if(key_toggle_short_press)
				 {
				    key_register_reset;
				   	 GpuSend4("CLS(15);");
delay_ms(20);
register_initial();
 while(!KEY_IDLE);
                    break;
				 }
				
			} 

   } 







void torque_compensate_low_adjust(void)
 {
   // unsigned int middle,count;
	unsigned int middle;
	  signed int a,b,c;
	  unsigned char point;
	
         GpuSend4("CLS(15);\r\n");
	       delay_ms(10); 
	       GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	       delay_ms(20);
	       GpuSend4("DS48(0,0,'下力矩补偿值',0,0);\r\n");
	       delay_ms(20);
			   point=0;
			   //count=0;
			  
			   middle=TEXT_Buffer[eeprom_write_torque_compensate_low];	
	       
			   a=middle/100;
				 b=middle%100/10;
				 c=middle%10;
					
			  //while(!KEY_IDLE);
			  delay_long(10);
			  timer0_reset();
			  timer0_count_enough=0;
			  key_toggle_used=0;
			  key_enter_used=0;
			  key_up_used=0;
			  key_down_used=0;
			 while(1)
			 { 
			        key_scan();
					
					GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
					delay_ms(20);
					GpuSend4("DS48(0,0,'下力矩补偿值',0,0);\r\n");
					delay_ms(20);


				 
				     switch(point)
               {
            						   
					case 0:sprintf(buf,"DS48(380,0,'%d',1);DS48(405,0,'%d',0);DS48(455,0,'%d',0);",a,b,c);GpuSend4(buf);delay_ms(18);break;
                   case 1:sprintf(buf,"DS48(405,0,'%d',1);DS48(380,0,'%d',0);DS48(455,0,'%d',0);",b,a,c);GpuSend4(buf);delay_ms(18);break;
                  case 2:sprintf(buf,"DS48(455,0,'%d',1);DS48(380,0,'%d',0);DS48(405,0,'%d',0);",c,a,b);GpuSend4(buf);delay_ms(18);break;
													
               }
		          if(key_down_short_press)
            		{
            					 key_register_reset;
            					 switch(point)
            						{
            						   case 0:a+=1;break;
            						   case 1:b+=1;break;
            						   case 2:c+=1;break;
            						}
									
								}
					           
							   if(key_up_short_press)
            					 {
            					   key_register_reset;
            					 
            					    switch(point)
            						{
            						   case 1:b-=1;break;
            						   case 0:a-=1;break;
            						   case 2:c-=1;break;
            						}
									
								 }
					 
					        if(a>9)
							   {
							   a=0;
							   }
					        if(b>9)
							   {
							   b=0;								  
							   }
							   if(c>9)
							   {
							   c=0;
							   }
							   
							   if(a<0)
							   {
							   a=9;
							   }
							   
							   if(b<0)
							   {
							   b=9;
							   }
							   
							   if(c<0)
							   {
							   c=9;
							   }
							     
					         
            					 
					   
			   	 if(key_enter_long_press)
				 {
				  key_register_reset;
				 
					GpuSend4("CLS(15);\r\n");
	               delay_ms(10); 
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(200);
					middle=a*100+b*10+c;
				    TEXT_Buffer[eeprom_write_torque_compensate_low]=(middle);
				    standard_torque=((float)TEXT_Buffer[eeprom_write_torque_compensate_h]*256+
				    TEXT_Buffer[eeprom_write_torque_compensate]-TEXT_Buffer[eeprom_write_torque_compensate_low])*
					(TEXT_Buffer[eeprom_write_torque_percent]-3)/7.0+TEXT_Buffer[eeprom_write_torque_compensate_low]+0.5;
					STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);           
				    while(!KEY_IDLE);
				  	register_initial();
				
				  break;
				 }
					 
					  if(key_enter_short_press)
				 {
				  
				    key_register_reset;
				    point+=1;
					if(point>2)
					{
					point=0;
					}

				 }
			   	 
				  GpuSend4("DS48(430,0,'.',0,0);");
                  delay_ms(20);

				  	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			

				  if(key_toggle_short_press)
				 {
				  

				  key_register_reset;
				   	GpuSend4("CLS(15);\r\n");
	               delay_ms(10);

				 
        		while(!KEY_IDLE);
				  //key_toggle_short_process();
        		break;
				 }
				 
			} 
	
 }
 
/*
void dec_speed_set(void)
  {

   //unsigned int a,b,c,decspeed;
	 unsigned int decspeed;	
		
   //initlcm();
   GpuSend4("CLS(15);\r\n");
	 delay_ms(18); 
   decspeed=TEXT_Buffer[eeprom_write_decspeed];
	 if((decspeed<2)||(decspeed>50))
	 {
		 decspeed=30;
	 }
		
   //decspeed=30;

	   while(1)
	   {
	   if(language_register==0)
   {
   //display_chinese_letter(0x81,"减速速度设定");
   //display_chinese_letter(0x95,"确定");
		GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	  delay_ms(18);
	  GpuSend4("DS48(0,0,'减速速度设定',0,0);\r\n");
	  delay_ms(18); 
		 
		 
		 
   }
   else
   {
   //display_chinese_letter(0x82,"dec.speed set");
   //display_chinese_letter(0x95,"Enter");
	 GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	 delay_ms(18);
 	 GpuSend4("DS48(0,0,'dec.speed set',0,0);\r\n");
	 delay_ms(18); 
		
   }

			     key_scan();
				   GpuSend4("DS48(430,0,'HZ',0,0);\r\n");
	        sprintf(buf,"DS48(350,0,'%2d',1);\r\n",decspeed);
	        GpuSend4(buf);
	        delay_ms(18); 
	       
	 
	 
	 
	 
	 
	 
            if(key_up_short_press)
					 {
					  key_register_reset;
					  decspeed++;
					     if(decspeed>50)
						   {
						   	decspeed=50;
						   }
					 }
		
					 if(key_down_short_press)
					 {
					  key_register_reset;
					  decspeed--;
					      if(decspeed<2)
						   {
						   	decspeed=2;
						   }
					 }



		 
			   	 if(key_enter_long_press)
				 {
					key_register_reset;
					GpuSend4("CLS(15);\r\n");
					delay_ms(18); 
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(20); 
					TEXT_Buffer[eeprom_write_decspeed]=(decspeed);
					STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
					while(!KEY_IDLE);
				    break;
				 }
                 
				 if(key_toggle_short_press)
				 {
		          key_register_reset;
				  GpuSend4("CLS(15);");
                  delay_ms(20);
                  while(!KEY_IDLE);
                  break;
				 }
			   

	   }
   
  }
	
*/
 void dec_speed_set(void)
  {

   
	// unsigned int decspeed;	
	 unsigned char middle,display_number_1;
	// unsigned int instead;	
   
     GpuSend4("CLS(15);\r\n");
	 delay_ms(18); 
	 STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
     //decspeed=TEXT_Buffer[eeprom_write_decspeed];
	 middle=TEXT_Buffer[eeprom_write_decspeed];
	 speed_select=TEXT_Buffer[eeprom_write_speed_rpm_select];	
	 if((middle<2)||(middle>50))
	 {
		 middle=10;
	 }
		
   

	   while(1)
	 {
	   if(language_register==0)
   {
 
		GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	    delay_ms(18);
	    GpuSend4("DS48(0,0,'减速速度设定',0,0);\r\n");
	    delay_ms(18); 
		 
		 
		 
   }
   else
   {

	 GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	 delay_ms(38);
 	 GpuSend4("DS48(0,0,'dec.speed set',0,0);\r\n");
	 delay_ms(18); 
		
   }

			 key_scan();
			 
			 if(speed_select==0)
		     {
				display_number_1=middle;
			  }
			 if(speed_select==1)
			{
				display_number_1=middle*2;
		     }
			 if(speed_select==2)
			{
				display_number_1=middle*4;
		    }
				   
			 
			sprintf(buf,"DS48(320,0,'%3d',0);",display_number_1);
			GpuSend4(buf); 
			delay_ms(18);
			GpuSend4("DS48(400,0,'rpm',0,0);\r\n");
            delay_ms(18);
			 
			
   	                if(key_down_short_press)
					 {
					  key_register_reset;
					  middle--;
					  if(middle<5)
						{
						  middle=5;
						}
						 
					 }
		
					 if(key_up_short_press)
					 {
					  key_register_reset;
					  middle++;
					  if(middle>50)
						{
						  middle=50;
						}
						
					 }

				   	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			

		 
			   	 if(key_enter_long_press)
				 {
					key_register_reset;
					GpuSend4("CLS(15);\r\n");
					delay_ms(18); 
					GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(20); 
					TEXT_Buffer[eeprom_write_decspeed]=(middle);
					STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
					register_initial();
					while(!KEY_IDLE);
				    break;
				 }
                 
				 if(key_toggle_short_press)
				 {
		          key_register_reset;
				  GpuSend4("CLS(15);");
                  delay_ms(20);
                  while(!KEY_IDLE);
                  break;
				 }
			   

	   }
   
  }
	
	



void switch_mode_process(void)
{
      
	  
	   switch_operation_close_mode=TEXT_Buffer[eeprom_write_switch_operation_close_mode];	
     switch_mode_sign=1;
	
	  mode_toggle=1;
		GpuSend4("CLS(15);\r\n");
	  delay_ms(10); 
		 
			//initlcm();
			
		               if(display_select==0)
						{
						      if(language_register==0)
                               {
                    			
									GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
									delay_ms(8);
									GpuSend4("DS48(0,0,'阀位',0,0);\r\n");
									delay_ms(8); 
									GpuSend4("DS48(0,200,'                      ',0,0);\r\n");
									delay_ms(8); 
																 
																  
																 
																 
																 
                    		   }
                    		   else
                    		   {
                    		  
								GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
								delay_ms(18);
								GpuSend4("DS48(0,0,'open',0,0);\r\n");
								delay_ms(18); 
								GpuSend4("DS48(0,200,'                         ',0,0);\r\n");
								delay_ms(18);	

                    		   }
						}
						else
						{
						//display_chinese_letter(0x81,"电流");
							
							      if(language_register==0)
                               {
									GpuSend4("DS48(0,200,'电流',0,0);\r\n");
									delay_ms(18);	 
									//current_data 
									sprintf(buf,"DS48(350,200,'%d',0);\r\n",current_data);
									GpuSend4(buf); 
									delay_ms(18);  
									GpuSend4("DS48(454,200,'A',0,0);\r\n");
									delay_ms(18);		 
																 
                    		   }
                    		   else
                    		   {
                    		   
									GpuSend4("DS48(0,200,'cur.',0,0);\r\n");
									delay_ms(18);	
									sprintf(buf,"DS48(350,200,'%d',0);\r\n",current_data);
									GpuSend4(buf); 
									delay_ms(18);  
									GpuSend4("DS48(454,200,'A',0,0);\r\n");
									delay_ms(18);		 
														 
														 
                    		   }
							
							
							
							
							
						}	
         
		  TEXT_Buffer[eeprom_write_local_remote]=(2);
		  
		  remote_ready_relay_on();
		  local_ready_relay_off();
   
          if(switch_mode_select_variable==0)
		  {
		 // operate_mode=2;
		 switch_realtime_process();	
		  
		  }
          else if(switch_mode_select_variable==1)
		  {
		  //operate_mode=1;
		  switch_pulse_process();
		  }
		  else
		  {
		  	two_line_process();
		  
		  }

		  
   
}



void product_id_set(void)
{
	
    char b,c;
	signed char row;
   
	row=0;
	
    STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
    app_torque=TEXT_Buffer[eeprom_write_torque1];
	app_speed =TEXT_Buffer[eeprom_write_speed1];
	app_volt=TEXT_Buffer[eeprom_write_volt];
	app_year=TEXT_Buffer[eeprom_write_year];
	app_number1=TEXT_Buffer[eeprom_write_number1];
	app_number2=TEXT_Buffer[eeprom_write_number2];
	

	if((app_torque<1)||(app_torque>8))
	{app_torque=1;}
	if((app_speed<10)||(app_speed>14))
	{app_speed=10;}
	if((app_volt<13)||(app_volt>14))
	{app_volt=13;}
	if((app_year<18)||(app_year>99))
	{app_year=18;}
	if((app_number1<0)||(app_number1>99))
	{app_number1=0;}
	if((app_number2<0)||(app_number2>99))
	{app_number2=0;}

 
	GpuSend4("CLS(15);");
	delay_ms(18);
	
	          
    while(1)
    {
	  
		 switch(app_speed)				   
	   {
	   case 10: b='A'; break;
	   case 11: b='B'; break;
	   case 12: b='C'; break;
	   case 13: b='D'; break;
	   case 14: b='E'; break;
	   
	   }

	    switch(app_volt)
	   {
	   
	   case 13: c='D'; break;
	   case 14: c='E'; break;
	   
	   }


	   	GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
		    delay_ms(48);
		    GpuSend4("DS48(0,0,'产品型号配置',0,0);\r\n");
		    delay_ms(28);





	 
		
		key_scan();


	



		GpuSend4("DS48(0,50,'2SA85',0);DS48(153,50,'*-*',0);DS48(288,50,'-',0);");
	    delay_ms(18);
		  
		switch(row)
     {
	    
			case 0:sprintf(buf,"DS48(124,50,'%d',1);DS48(230,50,'%c',0);DS48(260,50,'%c',0);DS48(314,50,'%2d',0);DS48(366,50,'%2d',0);DS48(418,50,'%2d',0);",app_torque,b,c,app_year,app_number1,app_number2);GpuSend4(buf);delay_ms(18);break;
			case 1:sprintf(buf,"DS48(124,50,'%d',0);DS48(230,50,'%c',1);DS48(260,50,'%c',0);DS48(314,50,'%2d',0);DS48(366,50,'%2d',0);DS48(418,50,'%2d',0);",app_torque,b,c,app_year,app_number1,app_number2);GpuSend4(buf);delay_ms(18);break;
			case 2:sprintf(buf,"DS48(124,50,'%d',0);DS48(230,50,'%c',0);DS48(260,50,'%c',1);DS48(314,50,'%2d',0);DS48(366,50,'%2d',0);DS48(418,50,'%2d',0);",app_torque,b,c,app_year,app_number1,app_number2);GpuSend4(buf);delay_ms(18);break;
			case 3:sprintf(buf,"DS48(124,50,'%d',0);DS48(230,50,'%c',0);DS48(260,50,'%c',0);DS48(314,50,'%2d',1);DS48(366,50,'%2d',0);DS48(418,50,'%2d',0);",app_torque,b,c,app_year,app_number1,app_number2);GpuSend4(buf);delay_ms(18);break;	
			case 4:sprintf(buf,"DS48(124,50,'%d',0);DS48(230,50,'%c',0);DS48(260,50,'%c',0);DS48(314,50,'%2d',0);DS48(366,50,'%2d',1);DS48(418,50,'%2d',0);",app_torque,b,c,app_year,app_number1,app_number2);GpuSend4(buf);delay_ms(18);break;
			case 5:sprintf(buf,"DS48(124,50,'%d',0);DS48(230,50,'%c',0);DS48(260,50,'%c',0);DS48(314,50,'%2d',0);DS48(366,50,'%2d',0);DS48(418,50,'%2d',1);",app_torque,b,c,app_year,app_number1,app_number2);GpuSend4(buf);delay_ms(18);break;
		
										
     }

	 	switch(row)
     {
	   case 0: GpuSend4("DS32(0,100,'tips:1-8分别对应不同的力矩！  ',1,0);");delay_ms(18);break;
       case 1: GpuSend4("DS32(0,100,'tips:A-E分别对应不同的转速！  ',1,0);");delay_ms(18);break;
	   case 2: GpuSend4("DS32(0,100,'tips:D:220V;        E:380V！  ',1,0);");delay_ms(18);break;
	   case 3: GpuSend4("DS32(0,100,'tips:0-99对应出厂年份！       ',1,0);");delay_ms(18);break;
	   case 4: GpuSend4("DS32(0,100,'tips:0-99对应出厂编号1！      ',1,0);");delay_ms(18);break;
	   case 5: GpuSend4("DS32(0,100,'tips:0-99对应出厂编号2！      ',1,0);");delay_ms(18);break;
	 }  
	   
		   if(key_up_short_press)
			 {
				key_register_reset;
					if(row==0)
					{
					  app_torque++;
					  if(app_torque>8)
					  app_torque=1;
					}
					else if(row==1)
					{
					  app_speed++;
					  if(app_speed>14)
					  app_speed=10;
					}
					else if(row==2)
					{
					  app_volt++;
					  if(app_volt>14)
					  app_volt=13;
					}
					else if(row==3)
					{
					  app_year++;
					  if(app_year>99)
					  app_year=0;
					}
					else if(row==4)
					{
					  app_number1++;
					  if(app_number1>99)
					  app_number1=0;
					}

				   	else if(row==5)
					{
					  app_number2++;
					  if(app_number2>99)
					  app_number2=0;
					}

			 }
		
		     if(key_down_short_press)
		    {
			    key_register_reset;
				if(row==0)
				{
				 app_torque--;
				 if(app_torque<1)
				 app_torque=8;
				}
				else if(row==1)
				{
				  app_speed--;
				  if(app_speed<10)
				  app_speed=14;
				}
				else if(row==2)
				{
				 app_volt--;
				 if(app_volt<13)
				 app_volt=14;
				}
				else if(row==3)
				{
				  app_year--;					     
				  if(app_year<0)
				  app_year=99;
				}
				else if(row==4)
				{
				 app_number1--;
				 if(app_number1<0)
				 app_number1=99;
				}

				else if(row==5)
			   {
				app_number2--;
			    if(app_number2<0)
				app_number2=99;
			   }



			}
		
		   if(key_enter_short_press)
		   {
			    key_register_reset;
				row++;
				if(row>5)
				{
				  row=0;
				}
			   
		   }
		
		    if(key_enter_long_press)
		   {
			    key_register_reset;
			
			    
                TEXT_Buffer[eeprom_write_torque1]=(app_torque);
			    TEXT_Buffer[eeprom_write_speed1]=(app_speed);
	            TEXT_Buffer[eeprom_write_volt]=(app_volt);
                TEXT_Buffer[eeprom_write_year]=(app_year);            
                TEXT_Buffer[eeprom_write_number1]=(app_number1);
	            TEXT_Buffer[eeprom_write_number2]=(app_number2);
                STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE); 

			    GpuSend4("CLS(15);");
	            delay_ms(18);
				 GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
					delay_ms(20); 
					 
				register_initial();
	            while(!KEY_IDLE); 
				break;

				
				
		   }
		
		

		     	if(key_toggle_short_press)
				 {
				  

					key_register_reset;
					
					GpuSend4("CLS(15);\r\n");
					delay_ms(50);

				    
					while(!KEY_IDLE);
					
					break;
				 }


		
	}
	
}



void local_set(void)
{
     unsigned char a;
	 GpuSend4("CLS(15);");
     delay_ms(8);
	 STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	 a=TEXT_Buffer[eeprom_write_local_register];
     a=a&0x01;

		 if((a!=1)&&(a!=0))
		{
			a=0;
		}


	
	   while(1)
		{
				   
				        if(language_register==0)
                   {
                   
					  GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                  delay_ms(18);
		              GpuSend4("DS48(0,0,'现场动作',0,0);\r\n");
	                  delay_ms(18);	 
										 
										 
                   }
                   else
                   {
					  GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                  delay_ms(18);
	                  GpuSend4("DS48(0,0,'local act',0,0);\r\n");
					  delay_ms(18);	 
										 	 
									
                   }       
									 
								if(language_register==0)
								{
								if(a==0)
								{

								GpuSend4("DS48(340,0,'点动',0,0);\r\n");
								delay_ms(8);

								}
								else
								{

								GpuSend4("DS48(340,0,'自保持',0,0);\r\n");
								delay_ms(18);


								}

								}
								else
								{

								if(a==0)
								{

								GpuSend4("DS48(340,0,'JOG',0,0);\r\n");
								delay_ms(18);


								}
								else
								{

								GpuSend4("DS48(264,0,'selfhold',0,0);\r\n");
								delay_ms(18);

								}
								}



					       key_scan();

						 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			




					   
    					   if((key_up_short_press)||(key_down_short_press))
    					 {
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(18);
								a=~a;
								a=a&0x01;
    					 }
					 
					     
					 
					 
        					 if(key_toggle_short_press)
        				 {
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(20);
								while(!KEY_IDLE);
								break;
			           
        				 }
        					 
        					
        					if(key_enter_long_press)
        				 {
								key_register_reset;
								GpuSend4("CLS(15);");
								delay_ms(18);
								GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
								delay_ms(20); 
								
								TEXT_Buffer[eeprom_write_local_register]=(a);
								STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
								STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	                            local_register=TEXT_Buffer[eeprom_write_local_register];
								while(!KEY_IDLE);
								break;
							  
        				 } 
					                              
				  }
               
	}


 void BT_set(void)

{
   
        //unsigned char a;
        GpuSend4("CLS(15);");
		delay_ms(8);
		STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
        bluetooth_sign=TEXT_Buffer[eeprom_write_bluetooth]; 
        bluetooth_sign=bluetooth_sign&0x01;  

        if((bluetooth_sign!=1)&&(bluetooth_sign!=0))
		 {
			bluetooth_sign=0;
		 }	

while(1)

{
	   	          
				     if(language_register==0)
    				{
					    
							GpuSend4("DS48(0,270,'返回',0,0);DS48(382,270,'确定',0,0);\r\n");
	                        delay_ms(18);
		                    GpuSend4("DS48(0,0,'蓝牙通信',0,0);\r\n");
	                        delay_ms(18);	
							
				    } 
					else
					{
					    
					     GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                     delay_ms(18);
	                     GpuSend4("DS48(0,0,'Bluetooth',0,0);\r\n");
					     delay_ms(18);	
					
					}
				   
                   key_scan();
					 
					if((key_up_short_press)||(key_down_short_press))
					 {
					     key_register_reset;
					  	 bluetooth_sign=~bluetooth_sign;
						   bluetooth_sign=bluetooth_sign&0x01;
					 }
		      if(language_register==0)
             {
               if(bluetooth_sign==0)
							 {
								 
								
								 GpuSend4("DS48(382,0,'关闭',0,0);\r\n");
					       delay_ms(18);
						    blue_power_off;	
								
								 }
                else
								{
								
									GpuSend4("DS48(382,0,'开启',0,0);\r\n");
					                delay_ms(18);
							        blue_power_on;	
								
									}
               }
              else
              {
                          
						  if(bluetooth_sign==0)
						  {
								GpuSend4("DS48(311,0,'disable',0,0);\r\n");
					            delay_ms(18);
								blue_power_off;		
							}
              else
						  {
								 GpuSend4("DS48(311,0,'enable ',0,0);\r\n");
					             delay_ms(18);
								 blue_power_on;	
								
                         }
								
               }
					 

		 
			   	if(key_enter_long_press)
				 {
				  
				  key_register_reset;
				  GpuSend4("CLS(15);");
				  delay_ms(8);
				  GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
				  delay_ms(20); 
				  TEXT_Buffer[eeprom_write_bluetooth]=(bluetooth_sign);
				  STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
                  STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
                  bluetooth_sign=TEXT_Buffer[eeprom_write_bluetooth];   
                  while(!KEY_IDLE);
				  break;

				 }
				
				
				 	if(language_register==1)
				{
				
				    GpuSend4("PIC(0,80,159);\r\n");
				    delay_ms(18);
				
				}
				else
				{
				
				    GpuSend4("PIC(0,80,160);\r\n");
				    delay_ms(18);
				}
			
				 
			      
				  if(key_toggle_short_press)
				 {
				  
					key_register_reset;
					GpuSend4("CLS(15);");
					delay_ms(20);
					while(!KEY_IDLE);
					break;
				 }
			   	 					 
		
	   }
  
  }























