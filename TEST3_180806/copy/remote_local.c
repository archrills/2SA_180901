#include "header.h"
#include "variable.h"
#include "led.h"
#include "header.h"
#include "adc.h"
#include "math.h"
#include "stm32f10x.h"
#include "timer.h"
#include "key.h"
#include "usart.h"
#include "stmflash.h"
#include <math.h>
#define	fault_torque_over_position  	   7
																																						     
#define switch_mode_detect (0)
extern unsigned char fail_times;
extern unsigned char uart1_count;
extern unsigned char first_uart;
extern unsigned char receive_complete;
extern unsigned char remote_sign;
extern signed   char   pass_border_sign;
extern unsigned char crc_h_register,crc_l_register;
extern unsigned char important_data_array[47];
extern unsigned char fault_register;
extern unsigned char sensitive_register,move_direction_register,emergency_position_register,move_direction_register_temporary,move_direction_register_temporary1,
                      motor_protect_register,normal_speed_register,language_register,speed_register;
extern unsigned char quit_sign;
extern unsigned char encoder_error_sign;
extern signed long int    start_point_ad,end_point_ad,all_distance;
extern signed long int turns,all_angle,angle;
extern int percent_now,percent_set;
extern unsigned char fault_check[];
extern unsigned char reaction_direction;  
extern unsigned char  stop_sign;
extern unsigned char timer_delay_count;
extern unsigned char timer_delay_sign;
extern unsigned int AD_temperature_register;
extern unsigned char motor_protect_sign;
extern unsigned int timer_AD_delay;
extern unsigned int current_data,AD_register;
extern unsigned char pulse_mode_quit_sign;
extern signed char pass_border_sign;
extern signed long int turns,all_angle,angle;
extern unsigned char torque_over_sign;
extern unsigned char  go_up_direction;
extern unsigned char switch_operation_close_mode;
extern unsigned int   speed_fall_position_register,speed_fall_position_register_count;
extern unsigned char key_keep_register;
extern unsigned char display_select;
extern unsigned char switch_mode_sign;
extern float percent_dispaly,percent_dispaly1,percent_dispaly2;
extern unsigned char operating_check[20];

extern unsigned int current_ad_now0,current_ad_now1,current_ad_now2,current_ad_now3,current_ad_now4,
                    current_ad_now5,current_ad_now6,current_ad_now7,current_ad_now8,current_ad_now9,
			        current_ad_now10,current_ad_now11,current_ad_now12,current_ad_now13,current_ad_now14,
			        current_ad_now15,current_ad_now16,current_ad_now17,current_ad_now18,current_ad_now19,
					current_ad_now20;

extern unsigned char ad_sample_number;
extern unsigned  int ad_now_input;
extern int zero_mA_ad;

extern int full_mA_ad,all_mA_ad;
extern unsigned char signal_emergency_position_register;
extern unsigned char operate_mode,mode_flag;
extern unsigned char remote_direction;
extern unsigned char mode_toggle,flag_test,stop_flag,stop_flag1;
extern char buf[128];	
int buf3[2]={0xa0,0xa0};
extern void (*function_point)();//非常重要 程序指针
extern unsigned char TEXT_Buffer[262];
extern signed char start_point_ad_h_register,start_angle_register_h,end_angle_register_h,end_point_ad_h_register;
extern signed char start_point_ad_l_register,start_angle_register_l,end_angle_register_l,end_point_ad_l_register;

extern signed long int ad_previous,ad_next,encoder_previous;
extern unsigned char  direction_judge_complete_sign;
extern unsigned char go_up_ad;

extern unsigned char start_speed_test;
extern unsigned int  speed_judge_period_count;
extern unsigned char switch_position_sign;
extern unsigned char timer_ov;
extern unsigned char read_write_sign;

extern unsigned char read_current_array[];
extern unsigned char first_start_sign;	
extern unsigned int address,standard_torque;
extern unsigned char torque_over_number;	
extern unsigned char  torque_over_times;
extern unsigned char current_data_over_sign;
extern unsigned int	operate_current_data;
extern long int   count_number,count_number1;
void move_state_judge(void);
extern unsigned char uart5_count_array[36];
extern unsigned char key_allowed;


extern void Usart5Close(void);
extern void Usart5Open(void);
extern unsigned char run_direction;  
unsigned char  speed_fast_sign;
extern unsigned char array_test[36];
unsigned char write_first=0;
extern unsigned char send_queue;
extern void GpuSend5(char *buf2);
 unsigned char encoder_ready=1;
 unsigned char display_classification=0;
 unsigned char display_number_change=0;
 extern unsigned char display_queue;
 unsigned char control_mode_register=0;
 char *control_mode_point_precious;
 unsigned char timer5_count=0;
 extern unsigned char timer7_count;
 extern void  Timer5_Init(void);  
 extern unsigned char alarm_sign;  
 extern unsigned char speed_select;
extern unsigned char local_register;				   
extern unsigned char  switch_flag;
extern unsigned long  switch_number;
				   
   char local_mode[]={"DS48(70,0,'阀位',0,0);DS32(42,268,'现场点动  ',0,0);\r\n"};
  char local_mode2[]={"DS48(70,0,'阀位',0,0);DS32(42,268,'现场自保持',0,0);\r\n"};
  char local_mode1[]={"DS48(70,0,'V.P ',0,0);DS32(42,268,'local JOG ',0,0);\r\n"};
  char local_mode3[]={"DS48(70,0,'V.P ',0,0);DS32(42,268,'local SH  ',0,0);\r\n"};

  char remote_normal_mode[]={"DS48(70,0,'阀位',0,0);DS32(42,268,'模拟量    ',0,0);\r\n"};
 char remote_normal_mode1[]={"DS48(70,0,'V.P ',0,0);DS32(42,268,'Analog    ',0,0);\r\n"};
 char remote_off_mode[]={"DS48(70,0,'阀位',0,0);DS32(42,268,'模拟量断信',0,0);P\r\n"};
char remote_off_mode1[]={"DS48(70,0,'V.P ,0,0);DS32(42,268,'Analog off',0,0);\r\n"};
 char switch_realtime_mode[]={"DS48(70,0,'阀位',0,0);DS32(42,268,'开关量点动',0,0);\r\n"};
char switch_realtime_mode1[]={"DS48(70,0,'V.P ',0,0);DS32(42,268,'switch JOG',0,0);\r\n"};
 char switch_pulse_mode[]={"DS48(70,0,'阀位',0,0);DS32(42,268,'开关量自保持',0,0);\r\n"};
char switch_pulse_mode1[]={"DS48(70,0,'V.P ',0,0);DS32(42,268,'switch hold ',0,0);\r\n"};
 char two_line_mode[]={"DS48(70,0,'阀位',0,0);DS32(42,268,'开关量两线制',0,0);\r\n"};
    char two_line_mode1[]={"DS48(70,0,'V.P ',0,0);DS32(42,268,'two-line    ',0,0);\r\n"};

 char normal[]={"DS32(338,268,'正常    ',0,0);PIC(338,182,51);\r\n"};
char normal1[]={"DS32(338,268,'normal  ',0,0);PIC(338,182,51);\r\n"};
 char torque_over[]={"DS32(338,268,'过力矩   ',0,0);PIC(338,182,48);\r\n"};
char torque_over1[]={"DS32(338,268,'OV.turque',0,0);PIC(338,182,48);\r\n"};


void go_up_on(void)
 {
  

 stop_reverse_simple;
 go_forward_simple;
 stop_sign=1;
	if(go_up_direction==100) 
	{
    run_direction=1;
		LED_ZERO=1;
		
  }	
	else
	{
    run_direction=2;
		LED_FULL=1;
  }
	 

 switch_flag=1;
 }
 
 void go_down_on(void)
 {

 stop_forward_simple;
 go_reverse_simple;
 stop_sign=1;
 
 switch_flag=1;
if(go_up_direction==100) 
{
   run_direction=2;
   LED_FULL=1;
}	
else
{
   run_direction=1;
   LED_ZERO=1;
} 
	 
 }
 
 void stop(void)
 {
 stop_forward_simple;
 stop_reverse_simple;
 stop_sign=0;

 torque_over_number=0;
 speed_fast_sign=5;
 run_direction=0;
      if(receive_complete==1)
	  {
		   write_first=0; 
      }


	 if( switch_flag==1)
	 {
	  switch_number=switch_number+1;
      TEXT_Buffer[switch_num1]=(switch_number%256);
      TEXT_Buffer[switch_num2]=(switch_number>>8);
      TEXT_Buffer[switch_num3]=(switch_number>>16);
      TEXT_Buffer[switch_num4]=(switch_number>>24);
      STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE); 
	  switch_flag=0;
	 
	 }

}

void  local_long_press_key_up(void)
{
    
	

while(1)
{
if(go_up_direction==100)
       {
   
   
	                if((torque_over_sign==0)&&(hand_wheel_disable))     
		          {
			  
			  
					      if(percent_now>5)
  						    {
  						      go_down_on();
  					        }
					        if(percent_now<2)
                		    {
                        	   stop();
                        	}
			            
					   
		   
					   if(percent_now<(int)speed_fall_position_register_count)
    					{
    					   slow_speed_on();
    					}
    					else
    					{
    					  slow_speed_off();
    					}
	   
	   
	               }
   
            }
   

 else
 {

		       if((torque_over_sign==0)&&(hand_wheel_disable)) 
			    {
					
				   if(percent_now>5)
			       {
				       go_up_on();
			       }
				   if(percent_now<2)
        		    {
            	        stop();
					}
			    
					
				    if(percent_now<(int)speed_fall_position_register_count)
					{
					     slow_speed_on();
					}
					else
					{
					    slow_speed_off();
					}
				  
			   }
  
 }


	            if(KEY_UP||KEY_ENTER||hand_wheel_enable||KEY_TOGGLE) 
				{
				   delay_short(10000);
				   if(KEY_UP||KEY_ENTER||hand_wheel_enable||KEY_TOGGLE) 
				     {
					    delay_short(10000);
						if(KEY_UP||KEY_ENTER||hand_wheel_enable||KEY_TOGGLE) 
						{
						 stop();
						 break;
						}
					 
					 }
				
				}
			
    			        if(quit_sign==1)
    				 {
    				   quit_sign=0;
					   GpuSend4("CLS(15);");
                       delay_ms(18);
                	   break;    
    				 
    				 }
            		pwm_excute();
			        percent_now_count();
	
	
	   }	
		
		
		
} 
 
void  local_long_press_key_down(void)
{
      
while(1)
	{
	
            	              if(go_up_direction==100)
            					{
					                  if((torque_over_sign==0)&&(hand_wheel_disable))     
							          {
    							        if(percent_now<995)
										{
										   go_up_on();
										}
										if(percent_now>998)
										{
										   stop();
										}
										
										if(percent_now>(int)(1000-speed_fall_position_register_count))
										{
										   slow_speed_on();
										}
										else
										{
										   slow_speed_off();
										}
						   
						   
						             }
					   
					            }
					   
					
			    	else
					
					{
					
        					       if((torque_over_sign==0)&&(hand_wheel_disable)) 
            					    {
                						
    									   if(percent_now<995)
                					       {

                						     go_down_on();
                					       
            							   }
                						   if(percent_now>998)
                                		    {
                                    	      stop();
                							}
        							    
        								
        							       if(percent_now>(int)(1000-speed_fall_position_register_count))
                        					{
                        					    slow_speed_on();
                        					}
                        					else
                        					{
                        				     	slow_speed_off();
                        					}
        							  
        						   }
					  
				 }
	
	            if(KEY_DOWN||KEY_ENTER||hand_wheel_enable||KEY_TOGGLE) 
				{
				   delay_short(10000);
				   if(KEY_DOWN||KEY_ENTER||hand_wheel_enable||KEY_TOGGLE) 
				     {
					    delay_short(10000);
						if(KEY_DOWN||KEY_ENTER||hand_wheel_enable||KEY_TOGGLE) 
						{
						 stop();
						 break;
						}
					 
					 }
				
				}
				
    			        if(quit_sign==1)
    				 {
    				     quit_sign=0;
					     GpuSend4("CLS(15);");
                         delay_ms(18);
                         break;    
    				 }
            		pwm_excute();
			        percent_now_count();
        		
	   }	
} 

void phase_lack_check(void)
{
     if(phase_lack_enable)
	 { 
	     delay_short(20);
		 
		 if(phase_lack_enable)
		  {
	            delay_short(20);
				    {
                	                    
								if(phase_lack_enable)		
						  {		
										  stop();
                    					  
                    					        voltage_fault_relay_on();
										        general_fault_relay_on();
										        if(language_register==0)
                    				      {
                    					        GpuSend4("DS48(0,100,'缺相',0,0);\r\n");
	                                            delay_ms(80);
										   }
                    					  else
                    					  {
                    					  
										      GpuSend4("DS48(0,100,'power pha.fault',0,0);\r\n");
	                                          delay_ms(80);
																	
                    					  }
                						  
                						while(1)		//
                				      {		 
                						       key_scan();
										       if(key_toggle_long_press)
                							 {
                							   key_register_reset;
                							   quit_sign=1;
                							   function_point=parameter_first;
                							   break;
                							 } 
        									  if(phase_lack_disable)
										   {
										        delay_short(50000);
												if(phase_lack_disable)
												{
												     delay_short(50000);
												     if(phase_lack_disable)
												     {
													    delay_short(50000);
												        if(phase_lack_disable)
													      {
													          delay_short(50000);
												              if(phase_lack_disable)
													           {
															        delay_short(50000);
												                   if(phase_lack_disable)
													               {
															          delay_short(50000);
												                      if(phase_lack_disable)
													                   {
															              delay_short(50000);
												                          if(phase_lack_disable)
													                      { 
																		      delay_short(50000);
												                              if(phase_lack_disable) 
																			   {
																			      delay_short(50000);
												                                  if(phase_lack_disable) 
																			      {
																			       voltage_fault_relay_off();
																				  // error_led_off;
																				   pulse_mode_quit_sign=1;
																				   break;
													                              }                     
																			   }
																		  }
																	   }
																   
																   }
																    
															   }
														   }
													 
													 }
												
												
												}
												
										  
										  }
										  
										  
										  key_scan();
                						  
                						  if(key_enter_long_press)
                            				 {
                            				            key_register_reset;
                							            if(language_register==0)
                                            		    {
                                            			    GpuSend4("DS48(0,5100,'复位,0,0);\r\n");
	                                                        delay_ms(20);	
                                            			}
                                            		    else
                                            		    {
                                            		       GpuSend4("DS48(0,100,'reset',0,0);\r\n");
	                                                       delay_ms(20);	
																											
                                            			}
                										
														
        												if(language_register==0)
                                            		    {
                                            		
														   GpuSend4("DS48(0,0,'阀位',0,0);\r\n");
	                                                       delay_ms(20);	
																											
																											
                                            			}
                                            		    else
                                            		    {
                                            		  
														   GpuSend4("DS48(0,50,'open',0,0);\r\n");
	                                                       delay_ms(20);
																											
                                            			}
        											
														pulse_mode_quit_sign=1;
														voltage_fault_relay_off();
														while(KEY_ENTER);
                                                        break;
                							 }
                            					
                			   }
	                 }
				 
			 }
	     }
	 }
  
}


 void encoder_act(void)
{
     	     
                uart1_count=0;
           	   if(uart1_count>5)
					     {
					  
					      fail_times=fail_times+1;
    					  if(fail_times>10)
    					  {
						      fail_times=10;
    					  }
        			  }
					   
                  if(encoder_ready==1)
				  {   
					  first_uart=0;
					  //if(first_uart==0)
        			  {
        			         first_uart=first_uart+1;
					        if(USART_GetFlagStatus(USART2,USART_FLAG_TXE) !=RESET)
                            { 
							 USART_SendData(USART2,0xA0); 
							 uart1_count=0; //注意50MS 累加一次
							 encoder_ready=0;
        			  	    }
					  }
               	  }	 			

 }

void  operate_initial_dispaly(void)
{
		//int ad_now;
	    //unsigned char a;
		//unsigned long int middle_varible;
		int c,b;



	     	if(control_mode_register==1)
			{
			            
				 
					if(language_register==0)
					{
					   
					   
					   if(local_register==1)
					   {GpuSend4(local_mode2);}
					   else
					   {GpuSend4(local_mode);}
								
					
					} 
					else
					{
					   if(local_register==1)
					   {GpuSend4(local_mode3);}
					   else
					   {GpuSend4(local_mode1);}
					
					}

			}

			else if(control_mode_register==2)
			{
			  
					if(language_register==0)
					{
					    GpuSend4(remote_off_mode);
					
					} 
					else
					{
					   GpuSend4(remote_off_mode1);
					
					}

			}
			else if(control_mode_register==3)
			{
			  	     if(language_register==0)
					{
					    GpuSend4(remote_normal_mode);
					
					} 
					else
					{
					   GpuSend4(remote_normal_mode1);
					
					}

			}
			else if(control_mode_register==4)
			{
			 
					if(language_register==0)
					{
					    GpuSend4(switch_realtime_mode);
					
					} 
					else
					{
					   GpuSend4(switch_realtime_mode1);
					
					}


			
			}
			else if(control_mode_register==5)
			{
			
					if(language_register==0)
					{
					    GpuSend4(switch_pulse_mode);
					
					} 
					else
					{
					   GpuSend4(switch_pulse_mode1);
					
					}

			
			}

			   else if(control_mode_register==6)
			{
			 
					if(language_register==0)
					{
					    GpuSend4(two_line_mode);
					
					} 
					else
					{
					   GpuSend4(two_line_mode1);
					
					}


			
			}


                    delay_ms(50);
                    c=percent_now/10;
					if((percent_now%10)>=5)
					{c=c+1;}
					
					
					b=(c+55);
					if(b<55)
					{b=55;}
					if(b>155)
					{b=155;}						 
				    sprintf(buf,"PIC(38,74,%d);\r\n",b); 
				    GpuSend4(buf);
			        delay_ms(30); 
				
				    if(alarm_sign==0)
					  {
								   if(torque_over_sign==0)
								   {
									      
									         if(language_register==0)
											{
											   
											 GpuSend4(normal);
											} 
											else
											{
											 GpuSend4(normal1);  
											}

									
							             reverse_torque_relay_off();
										 forward_torque_relay_off();
						
								   }
								   else
								   {
								   	              
									    GpuSend4(torque_over);
											
								   }

					  }
					  else
					  {
					  
						alarm_process();
											
					  
					  }

						 delay_ms(50);

}


void percent_now_count(void)
 {
	int ad_now;
	unsigned char a;
	int c,b;
	unsigned long int middle_varible;

			
	  if(PBin(12)==0)
	  {
	  	 alarm_sign=1;
	  }		     
        
	 			if(timer5_count==1)
				{
				   timer5_count=0;
				   PCout(11)=1;
				   delay_short(2000);
				   PCout(11)=0;

	 
									  if(display_classification==0)
									  {
								
											if(control_mode_register==1)
											{
											   	  
												if(hand_wheel_disable)		
													{
													        if(language_register==0)
															{
															   
															   GpuSend4("PIC(324,48,41);DS32(311,10,'现场模式 ',0,0);");
															   if(local_register==1)
															   {GpuSend4(local_mode2);}
															   else
															   {GpuSend4(local_mode);}
															  
														   	    		
													
															} 
															else
															{
															   
															   GpuSend4("DS32(311,10,'  local  ',0,0);PIC(324,48,41);");
															   if(local_register==1)
															   {GpuSend4(local_mode3);}
															   else
															   {GpuSend4(local_mode1);}
															   
															}
													}
													else
													{
														   stop();
														   if(language_register==0)
															{
															   
															   GpuSend4("DS32(311,10,'手轮控制 ',0,0);PIC(324,48,53);");


															    if(local_register==1)

															   { GpuSend4(local_mode2);}
															   else
															   { GpuSend4(local_mode);}
													
															} 
															else
															{
															   GpuSend4(local_mode1);
															   GpuSend4("DS32(311,10,'handwheel',0,0);");
															   delay_ms(20);
                                                               GpuSend4("PIC(324,48,53);");
															   delay_ms(20);
															}
													
													}

											}
											else if(control_mode_register==2)
											{
											  
											if(hand_wheel_disable)		
											{
											        if(language_register==0)
													{
													   GpuSend4(remote_off_mode);
													   GpuSend4("DS32(311,10,'远控模式',0,0);PIC(324,48,40);");
															
											
													} 
													else
													{
													   GpuSend4(remote_off_mode1);
													   GpuSend4("DS32(311,10,'remote  ',0,0);PIC(324,48,40);");
													}
											}
											else
											{
												   stop();
												   if(language_register==0)
													{
													   GpuSend4(remote_off_mode);
													   GpuSend4("DS32(311,10,'手轮控制 ',0,0);PIC(324,48,53);");
													} 
													else
													{
													   GpuSend4(remote_off_mode1);
													   GpuSend4("DS32(311,10,'handwheel',0,0);PIC(324,48,53);");
													}
											
											}
	
											}
											else if(control_mode_register==3)
											{
											  
											   
											 if(hand_wheel_disable)		
												{
												        if(language_register==0)
														{
														   GpuSend4(remote_normal_mode);
														   GpuSend4("DS32(311,10,'远控模式',0,0);PIC(324,48,40);");
																
												
														} 
														else
														{
														   GpuSend4(remote_normal_mode1);
														   GpuSend4("DS32(311,10,'remote  ',0,0);PIC(324,48,40);");
														}
												}
												else
												{
													   stop();
													   if(language_register==0)
														{
														   GpuSend4(remote_normal_mode);
														   GpuSend4("DS32(311,10,'手轮控制 ',0,0);PIC(324,48,53);");
														
														} 
														else
														{
														   GpuSend4(remote_normal_mode1);
														   GpuSend4("DS32(311,10,'handwheel',0,0);PIC(324,48,53);");
														}
												
												}
											
											
											}
											else if(control_mode_register==4)
											{
											  
												if(hand_wheel_disable)		
												{
												        if(language_register==0)
														{
														   GpuSend4(switch_realtime_mode);
														   GpuSend4("DS32(311,10,'远控模式',0,0);PIC(324,48,40);");
																
												
														} 
														else
														{
														   GpuSend4(switch_realtime_mode1);
														   GpuSend4("DS32(311,10,'remote  ',0,0);PIC(324,48,40);");
														}
												}
												else
												{
													   stop();
													   if(language_register==0)
														{
														   GpuSend4(switch_realtime_mode);
														   GpuSend4("DS32(311,10,'手轮控制 ',0,0);PIC(324,48,53);");
																
												
														} 
														else
														{
														   GpuSend4(switch_realtime_mode1);
														   GpuSend4("DS32(311,10,'handwheel',0,0);PIC(324,48,53);");
														}
												
												}
												   
												
											}
											else if(control_mode_register==5)
											{
											   
											if(hand_wheel_disable)		
											{
											        if(language_register==0)
													{
													   GpuSend4(switch_pulse_mode);
													   GpuSend4("DS32(311,10,'远控模式',0,0);PIC(324,48,40);");
													} 
													else
													{
													   GpuSend4(switch_pulse_mode1);
													   GpuSend4("DS32(311,10,'remote  ',0,0);PIC(324,48,40);");
													}
											}
											else
											{
												   stop();
												   if(language_register==0)
													{
													   GpuSend4(switch_pulse_mode);
													   GpuSend4("DS32(311,10,'手轮控制 ',0,0);PIC(324,48,53);");
													} 
													else
													{
													   GpuSend4(switch_pulse_mode1);
													   GpuSend4("DS32(311,10,'handwheel',0,0);PIC(324,48,53);");
													}
											 }
										}


											 else if(control_mode_register==6)
											{
											  
											if(hand_wheel_disable)		
											{
											        if(language_register==0)
													{
													   GpuSend4(two_line_mode);
													   GpuSend4("DS32(311,10,'远控模式',0,0);PIC(324,48,40);");
															
											
													} 
													else
													{
													   GpuSend4(two_line_mode1);
													   GpuSend4("DS32(311,10,'remote  ',0,0);PIC(324,48,40);");
													}
											}
											else
											{
												   stop();
												   if(language_register==0)
													{
													   GpuSend4(switch_pulse_mode);
													   GpuSend4("DS32(311,10,'手轮控制 ',0,0);PIC(324,48,53);");
															
											
													} 
													else
													{
													   GpuSend4(switch_pulse_mode1);
													   GpuSend4("DS32(311,10,'handwheel',0,0);PIC(324,48,53);");
													}
											
											}
												 
												 
											}
								

								
											display_classification=1;
											   
								
									  }
									  else if(display_classification==1)
									  {
									             c=percent_now/10;
											     if((percent_now%10)>=5)
												 {c=c+1;}
											

												 b=(c+55);
									             if(b<55)
											     {b=55;}
								                 if(b>155)
								                 {b=155;}						 
												 sprintf(buf,"PIC(38,74,%d);\r\n",b);  //
												 GpuSend4(buf);
												   
												 display_classification=2;

									

									 }		
									 else if(display_classification==2)	
									 {		  
									 			  	  if(alarm_sign==0)
													  {
																   if(torque_over_sign==0)
																   {
														                reverse_torque_relay_off();
																	    forward_torque_relay_off();
																		if(language_register==0)
																		{
																		  GpuSend4(normal);
																		
																		} 
																		else
																		{
																		  GpuSend4(normal1);
																		}


																   }
																   else
																   {
																   	                 
																				   
																		  if(language_register==0)
																		{
																	      	GpuSend4(torque_over);
																	
																		} 
																		else
																		{
																		    GpuSend4(torque_over1);
																	
																		}
																	
																   }
								
													  }
													  else
													  {
													      alarm_process();
													  }
											
											display_classification=0;
									 }
					}			
								   



                                    key_scan();


                                    if(key_enter_long_press)
									 {
									   key_register_reset;
									   
									   	reset_alarm();
										alarm_sign=0;
									    temperature_relay_off();
                                        voltage_fault_relay_off();
						             	general_fault_relay_off();
									  
									 }




    encoder_act(); 
	start_point_ad=((signed long int)start_point_ad_h_register*128+(signed long int)start_point_ad_l_register)*1024+((signed int)start_angle_register_h*128+(signed int)start_angle_register_l);
    end_point_ad=((signed long int)end_point_ad_h_register*128+(signed long int)end_point_ad_l_register)*1024+((signed int)end_angle_register_h*128+(signed int)end_angle_register_l);

	 
	 if(end_point_ad>start_point_ad)
	{
	     all_distance=end_point_ad-start_point_ad;
	}
	else
	{
      	all_distance=start_point_ad-end_point_ad;
	}
	 
 
	 
								if((pass_border_sign>1)||(pass_border_sign<(-1)))
								{
								    stop();   //注意
					    		
									  pass_border_sign=0;
									  
										crc_h_register= crc_modbus(important_data_array,46)/256;
										crc_l_register= crc_modbus(important_data_array,46)%256;
										
								      while(1)
										 {
										      fault_register=fault_register|0x40;
											  general_fault_relay_on();
					    					
													
								if(language_register==0)
	                        {
	                           GpuSend4("CLS(15);\r\n");
	                           GpuSend4("DS48(0,270,'取消',0,0);DS48(382,270,'确定',0,0);\r\n");
	                           delay_ms(20);
	                           GpuSend4("DS48(0,0,'重新标定行程',0,0);\r\n");
		                      }
	                         else
	                       {
	                           GpuSend4("CLS(15);\r\n");
	                           GpuSend4("DS48(0,270,'CANCEL',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                           delay_ms(20);
	                           GpuSend4("DS48(0,0,'reset distance',0,0);\r\n");
	                        }
													
							 key_scan();
						     if(key_toggle_long_press)
							 {
							   key_register_reset;
							   quit_sign=1;
							   function_point=parameter_first;
							   fault_register=fault_register&0xbf;
							   break;
							 }
										 
							}
								
						}
							//display_three_bit(0x80,speed_judge_period_count);
				/*	 
					      while((fail_times>5)||(encoder_error_sign!=0))
						{
						               
							          general_fault_relay_on();
											  stop();
					    					 // error_led_on;
					    					if(encoder_error_sign!=0)
											{
											   
												 
													if(language_register==0)
	                        {
	                           GpuSend4("DS48(0,0,'电位器故障',0,0);\r\n");
														 delay_ms(20);
		                      }
	                         else
	                       {
	                            GpuSend4("DS48(0,0,'POS FAULT',0,0);\r\n");
													    delay_ms(20);
	                        }
												
						          }
											else
											{
											 
													if(language_register==0)
	                        {
	                           GpuSend4("DS48(0,0,'编码器故障',0,0);\r\n");
														 delay_ms(20);
		                      }
	                         else
	                       {
	                            GpuSend4("DS48(0,0,'POS FAULT',0,0);\r\n");
													    delay_ms(20);
	                        }
												
											}
						             encoder_act();
						             fault_register=fault_register|0x80;
												 key_scan();
											   if(key_toggle_long_press)
												 {
												   key_register_reset;
												   quit_sign=1;
												   function_point=parameter_first;
												   fault_register=fault_register&0x7f;
												   break;
												 }
										
						}

				 */

                if(end_point_ad>start_point_ad)
						  {
		               if(all_angle>=start_point_ad)
							  {
							  middle_varible=all_angle-start_point_ad;
							  percent_now=(middle_varible)*1000/(all_distance);
								}
							  else
							  {
							  middle_varible=start_point_ad-all_angle;
							  middle_varible=middle_varible*1000/(all_distance);
							  percent_now=(-middle_varible);
							  }
		         }
               else
						  {
						      if(all_angle>=start_point_ad)
							  {
							  middle_varible=all_angle-start_point_ad;
							  middle_varible=middle_varible*1000/(all_distance);
							  percent_now=(-middle_varible);
							  }
							  else
							  {
							  middle_varible=start_point_ad-all_angle;
							  percent_now=middle_varible*1000/(all_distance);
							  
							  }
						  }
  


		  if(reaction_direction==255)
		  {
		     percent_now=1000-percent_now;
		  }

			        
		
          //display_percent_count_every_bit(0x96,ad_now);
          relay_process(); 
          phase_lack_check();   
	        check_motor_current(); 
			 
			    timer_delay_count++;  
			 
			 if(timer_delay_count>a)
			 {
			   
			    if(stop_sign==1)
    			{ 
				   if(timer_delay_sign)
    			   {
				   //torque_led_on;
    			   }
				   else
    			   {
				  // torque_led_off;
				   }
			   }
			   else
			   {
			      //torque_led_off;
			   }
			   
			   timer_delay_count=0;
			   timer_delay_sign=~timer_delay_sign;
			 }
			      
		 if(stop_sign==0)
		 {
		   AD_register=ad_now;
		   timer_AD_delay=0;
		 }
         else
		 {
		 timer_AD_delay++;
		 }
		   
			 
			 
			 
		  if(motor_protect_sign==0)
				{
    			        AD_temperature_register=Get_Adc(temperature_channel);
    		          if(AD_temperature_register>1750)
    				  {
    				      stop();
    					  //error_led_on;
    					  if(language_register==0)
    				      {
    					 
								 GpuSend4("DS48(0,100,'电机过温',0,0);\r\n");
							     delay_ms(20);
										
    				      }
    					  else
    					  {
    					  
								 GpuSend4("DS48(0,100,'motor too hot',0,0);\r\n");
							     delay_ms(20);	
									
    					  }
    				  
					      while(Get_Adc(temperature_channel)>1650)
						  
						  {
						      temperature_relay_on();
							  key_scan();

							 if(key_toggle_long_press)
							 {
							   key_register_reset;
							   quit_sign=1;
					           function_point=parameter_first;
							   break;
							 }
							 
							 
							 if(key_enter_long_press)
            				 {   
            				  key_register_reset;
							  temperature_relay_off();
							 
							  
							            if(language_register==0)
                            		    {
                            		
												  GpuSend4("DS48(0,100,'电机过热',0,0);\r\n");
							                      delay_ms(20);		
																			
                            			}
                            		    else
                            		    {
                            		   
												  GpuSend4("DS48(0,100,'motor too hot',0,0);\r\n");
							                      delay_ms(20);		
																			
																			
                            			}
									    while(KEY_ENTER);
                                        if(language_register==0)
                            		    {
                            		
												 GpuSend4("DS48(0,270,'取消',0,0);DS48(382,270,'确定',0,0);\r\n");
	                                             delay_ms(8);
		                                         GpuSend4("DS48(0,0,'阀位',0,0);\r\n");
			                                     delay_ms(8);
			
                            	      }
                            		    else
                            		    {
                            		   
												GpuSend4("DS48(0,270,'CANCEL',0,0);DS48(340,270,'ENTER',0,0);\r\n");
	                                            delay_ms(8);
		                                        GpuSend4("DS48(0,0,'open',0,0);\r\n");
				                                delay_ms(8);	
																			
                            			}
							  
							  break;
							 }
            						 
							 
						  }
						  
						  temperature_relay_off();
    				
    					  
    				  
    				  }
				  
		      }
		      
					
					
		   
		   if(fault_register==0)
		   {
		     general_fault_relay_off();
		   }
		   else
		   {
		     general_fault_relay_on();
		   }
		
  			
 }
 
 
 void local_process(void)
 {
     
   	 switch_mode_sign=TEXT_Buffer[eeprom_write_local_remote_sign];
	 local_register=TEXT_Buffer[eeprom_write_local_register];
	 TEXT_Buffer[eeprom_write_local_remote]=(1);	
	 STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	 GpuSend4("CLS(15);\r\n");
	 delay_ms(18);
	 
	 Usart5Open();
	 display_select=0;
	 mode_toggle=0;
	 operating_check[12]=mode_toggle;
	 mode_flag=0;
	 control_mode_register=1; 
   
	 operate_initial_dispaly();
	 remote_ready_relay_off();
	 local_ready_relay_on(); 
	 while(!KEY_IDLE);

	 while(1)	
	 {              
	    
		        pwm_excute();     
				remote_ready_relay_off();
	            local_ready_relay_on(); 	   	
				percent_now_count();
				
					if(go_up_direction==100)
					{
					   
					   if(KEY_UP&&(!switch_mode_detect))
						{  
					    
                      
						  if((torque_over_sign==0)&&(hand_wheel_disable))  
    					   { 
    							if(switch_operation_close_mode==0)
								{
								  if(percent_now<995)
        					     {
        					

								  go_up_on();


        					     }
        					    if(percent_now>998)
                                {
                                   stop();
                                }
    							 }
								 else
								 {
								    go_up_on();
								 }
								 
								 
								 
							    if(percent_now>(int)(1000-speed_fall_position_register_count))
									  
            	  	          {
            				       slow_speed_on();
            		          }
            					else
            					{
            					   slow_speed_off();
            					}
							  
						  }
						  
					   }
					   else if(KEY_DOWN&&(!switch_mode_detect))
					 
					   {  
    					   if((torque_over_sign==0)&&(hand_wheel_disable))     
							{
    							if(switch_operation_close_mode==0)
								 {  
									if(percent_now>5)
									{

									  go_down_on();
									}
									if(percent_now<2)
									{
                                      stop();
									}
									}
									else
									{
									   go_down_on();
									}
							   
							   
							   if(percent_now<(int)speed_fall_position_register_count)
            					{
            					  slow_speed_on();
            					}
            					else
            					{
            					  slow_speed_off();
            					}
						   }
					   	 
					   }
					   else
            		   {
            		    stop();
            		    torque_over_sign=0;
					          
					   }
					
					}
					
				else
					
					{
					
					   if(KEY_UP&&(!switch_mode_detect))
					   {
    					   if((torque_over_sign==0)&&(hand_wheel_disable))   
							{
        						  if(switch_operation_close_mode==0)
									{
									  if(percent_now<995)
            						  {
        							   
        							   go_down_on();
            					       
        							  }
        							  if(percent_now>998)
        							  {
            						 stop();
        							  }
							        }
									
								  else
								  {
								  go_down_on();
								  }
							    
								
								if(percent_now>(int)(1000-speed_fall_position_register_count))
            		            {
            					 slow_speed_on();
								}
            		            else
            		           {
            					slow_speed_off();
            		          }
						   
							  
							  
					       }
					   }
					   else if(KEY_DOWN&&(!switch_mode_detect))
					   {
					       if((torque_over_sign==0)&&(hand_wheel_disable)) 
    					    {
        						if(switch_operation_close_mode==0)
								{
									if(percent_now>5)
									{
									
								    	go_up_on();
									
									}
			        				if(percent_now<2)
			                        {
			                            stop();
			        							   
			        			    }
							    }
								else
								{
								go_up_on();
								}
								
							    if(percent_now<(int)speed_fall_position_register_count)
            					{
            					  slow_speed_on();
            					}
            					else
            					{
            					  slow_speed_off();
            					}
							  
						   }
					   }
					   else
            		   {
            		   
					   stop();
					 
            		   torque_over_sign=0;
					  
					   }
					  
				 }
		 
		 
		         key_scan();
				 read_motor_current();
				 
				 if((PGin(10)==1)||(PGin(9)==1)||(PDin(6)==1)||(PDin(7)==1))
			{
			   key_allowed=0;
			}	
				 
				
				  if((key_toggle_short_press)||(mode_toggle==1))
			    
				  {
				   	  key_register_reset;
					  if(switch_mode_sign==0)
					   {
					     function_point=remote_process;
						 (*function_point)();
							
				       }
					   else
					   {
					   function_point=switch_mode_process;
					   (*function_point)();
							 
					   }
					   break; 
					
				  }
		   	    
		 
			   	 if(key_toggle_long_press)
				 {
				  key_register_reset;
				  GpuSend4("CLS(15);\r\n");
	              delay_ms(18);
				  function_point=parameter_first;
				  (*function_point)(); 
				  break;
				 }  
				 
				   if(key_up_long_press)
				 {
				  
				  key_register_reset;
				    if(local_register!=0)
					{
				       local_long_press_key_down();
				    }
				 }    
		         
				 if(key_down_long_press)
				 {
				  
				  key_register_reset;
				   if(local_register!=0)
					{ 
				    	local_long_press_key_up();
				    }
				 } 
		  
	 }
 }




void percent_set_count(void)
 {
  
  unsigned long int middle_varible;
  ad_sample_number++;
  if(ad_sample_number>20)
  ad_sample_number=0;
	
	
  switch(ad_sample_number)
  {
  case 0:current_ad_now0=Get_Adc(current_ad_channel);break;
  case 1:current_ad_now1=Get_Adc(current_ad_channel);break;
  case 2:current_ad_now2=Get_Adc(current_ad_channel);break;
  case 3:current_ad_now3=Get_Adc(current_ad_channel);break;
  case 4:current_ad_now4=Get_Adc(current_ad_channel);break;
  case 5:current_ad_now5=Get_Adc(current_ad_channel);break;
  case 6:current_ad_now6=Get_Adc(current_ad_channel);break;
  case 7:current_ad_now7=Get_Adc(current_ad_channel);break;
  case 8:current_ad_now8=Get_Adc(current_ad_channel);break;
  case 9:current_ad_now9=Get_Adc(current_ad_channel);break;
  case 10:current_ad_now10=Get_Adc(current_ad_channel);break;
  case 11:current_ad_now11=Get_Adc(current_ad_channel);break;
  case 12:current_ad_now12=Get_Adc(current_ad_channel);break;
  case 13:current_ad_now13=Get_Adc(current_ad_channel);break;
  case 14:current_ad_now14=Get_Adc(current_ad_channel);break;
  case 15:current_ad_now15=Get_Adc(current_ad_channel);break;
  case 16:current_ad_now16=Get_Adc(current_ad_channel);break;
  case 17:current_ad_now17=Get_Adc(current_ad_channel);break;
  case 18:current_ad_now18=Get_Adc(current_ad_channel);break;
  case 19:current_ad_now19=Get_Adc(current_ad_channel);break;
  case 20:current_ad_now20=Get_Adc(current_ad_channel);break;
  }
  
  ad_now_input=(current_ad_now0+current_ad_now1+current_ad_now2+current_ad_now3+current_ad_now4   //2
  +current_ad_now5+current_ad_now6+current_ad_now7+current_ad_now8+current_ad_now9+current_ad_now10
  +current_ad_now11+current_ad_now12+current_ad_now13+current_ad_now14+current_ad_now15+current_ad_now16
  +current_ad_now17+current_ad_now18+current_ad_now19+current_ad_now20)/21;
  
  
  
  if(ad_now_input>=zero_mA_ad)   //3
  {
      middle_varible=ad_now_input-zero_mA_ad;   //4
      percent_set=(middle_varible*1000)/all_mA_ad;
      
      if(percent_set>1000)
      percent_set=1000;
  }
  else
  percent_set=0;
  
 
         		if(mode_flag==2)
				{											 
                  if(ad_now_input<100)   //5
				  {
				     if(emergency_position_register==1)
					 {
					   stop(); //
					   percent_set=percent_now;
					 }
					 else
					 {
					 
					   percent_set=(unsigned int)signal_emergency_position_register*10;
					 }
					   
					 
				  }
				 }
         
              if(hand_wheel_disable)		
		 {
                		if(torque_over_sign==0)
                		
                		{
									
                		             if(ad_now_input<100)   //6
                		            {
                    					 
										 	control_mode_register=2;
										 
									}


                					 else
                				  {
                				  
								          	control_mode_register=3;
                				  }
                		}
                		
                		
                		
                		 else
                		 {
                		 
                		              
                            
                		 }
                		 
  
           }
		   
		   else
		   {
		   
		                             
		   
		   }
 }

 
  void move_state_judge(void)
 {
        char stop_point;
		
		
		if(sensitive_register==3)
		{
		stop_point=1;
		}
	    else 
	    {
		stop_point=2;
		}
     
	   phase_lack_check();
	   
          if(percent_now>=percent_set)
					{
        					   
        							   if((percent_now-percent_set)> sensitive_register)
                					   {
                					   	   
										   
										   
										   if((torque_over_sign==0)&&(hand_wheel_disable))    
        							       {	
    										     remote_direction=1;
    										  
											  //stop_sign=1;
											  
    										 	    
											 		 if(fabs(percent_now-percent_set)<speed_fall_position_register_count)
														{
														slow_speed_on();
														}
														else
														{
														slow_speed_off();
														}
																				 
											 
											  if(go_up_direction==100)
                    						  {
                    						  go_down_on();
                    						  }
                    						  else
                    						  {
                    						  go_up_on();
                    					   	  }
                					       }
									  
									   }
									   
									   
									   
                					   else	if((percent_now-percent_set)<stop_point)
                					   {
            							   
										   torque_over_sign=0;
								           //torque_led_off;
										   stop();
										   stop_sign=0;
            							}
					
					         
							   
					
					}
					
					else
					{
        					     if((percent_set-percent_now)> sensitive_register)
           				{
                   					  
									   remote_direction=2;
									  
									  if((torque_over_sign==0)&&(hand_wheel_disable))    
        							{	
             							  
										 
										   if(fabs(percent_now-percent_set)<speed_fall_position_register_count)
											{
											slow_speed_on();
											}
											else
											{
											slow_speed_off();
											}
										 
										 
										 if(go_up_direction==100)
                 						  {
                 						  go_up_on();
                 						  }
                 						  else
                 						  {
                 						  go_down_on();
                 					   	  }
                      }
								  
								  }
                                
        					      else if((percent_set-percent_now)<stop_point)
                        {
                        		   torque_over_sign=0;
								   stop();
								   stop_sign=0;
                       }
					         }
                    
					
				 
			if(percent_now<=1)
			{
				 if(remote_direction==1)
				 {
				 stop();
				 }
			} 
           if(percent_now>=999)
		   {
		         if(remote_direction==2)
				 {
				 stop();
				 }
		   }
		    
 }
 
 

 
  void remote_process(void)
 {
    //int b;
	//float b,c;
	//switch_mode_sign=0;
	TEXT_Buffer[eeprom_write_local_remote_sign]=(0);
	STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	// operate_mode=1;   
	mode_toggle=1;
	operating_check[12]=mode_toggle;
	mode_flag=2;
	// Usart5Close();
	
	remote_ready_relay_on();
	local_ready_relay_off(); 
	GpuSend4("CLS(15);\r\n");     //?? ????
	delay_ms(10); 
	percent_set_count();
	operate_initial_dispaly();	 
	  while(1)	
{    
		        


			
		         pwm_excute();
		         percent_now_count();
								 
               remote_sign=1;
	        if(hand_wheel_enable)
					{
					  stop();
					}
					     percent_set_count();
					     move_state_judge();
					 
		                 percent_now_count();
					     move_state_judge();
					 
                         // percent_count_display();
					     move_state_judge();
					 
					     percent_now_count();
					     move_state_judge();
					 
					     pwm_excute();
                         move_state_judge();
					
					     percent_now_count();
					     move_state_judge();
					 
					    
    				 if(quit_sign==1)
    				 {
    				  quit_sign=0;
                       break;    
    				 
    				 }  	
					
					
					
					move_state_judge();
			    key_scan();//扫键；
          if(key_toggle_short_press)
				  {
				   	   key_register_reset;
						   
						   function_point=local_process;
						   remote_sign=0;
					     break;
					 
				  }
		 
			   
				 
           if((key_toggle_long_press)||(mode_toggle==0))
					//if(key_toggle_short_press)
				 {
				  
				  key_register_reset; 
				  function_point=parameter_first;
				  remote_sign=0;
				  break;
				 } 
                   
				
	 }

 }

 
void slow_speed_off(void)
 {
   
   	 unsigned int middle;
   	 unsigned int divider;
   	
	  if(speed_fast_sign!=1)
	{
			write_first=1;
			if(speed_select==0)
			{
			  divider=1;
			}
			if(speed_select==1)
			{
		      divider=1;
			}
			if(speed_select==2)
			{
			  divider=2;
			}
			
			
			middle=TEXT_Buffer[eeprom_write_speed];
			middle=(middle*500*divider)/4;
			
			if(receive_complete==1)		
			{
			  write_modbus_data1(32,1,middle/256,middle%256);
			  //write_modbus_data1(32,1,b/256,b%256);
			  speed_fast_sign=1;
			  write_first=0;
			}
	 }
	  
	  
		
} 

  void slow_speed_on(void)
 {
	    
	 	  unsigned int middle;
		
	   if(speed_fast_sign!=0)
		{
			
			middle= TEXT_Buffer[eeprom_write_decspeed];
		  middle=middle*100;		
			     write_first=1;
				if(receive_complete==1)	 
	          {
				write_modbus_data1(32,1,middle/256,middle%256);
				speed_fast_sign=0;
				write_first=0;
				speed_fast_sign=0;
				 
			  }
   }
	  
	 
	  
}

 
 
 void go_up_derection_detect(void)
{  
 
               key_scan();
              if(key_up_short_press)
					{
					    key_register_reset;
						ad_next=all_angle;
						
						if(ad_next>ad_previous)
						{
    						 if((ad_next-ad_previous)>10)
    						
							 { 
							 go_up_ad=255;
							 direction_judge_complete_sign=1;
							 }
						}
						else
						{
						    if((ad_previous-ad_next)>10)
							{
							go_up_ad=0;
							direction_judge_complete_sign=1;
							}
						}
						
						
						
						
				}
					
					if(key_down_short_press)
					{
					    key_register_reset;
						ad_next=all_angle;
						if(ad_next>ad_previous)
						{
						   if((ad_next-ad_previous)>10)
						   {
						   go_up_ad=0;
						   direction_judge_complete_sign=1;
						   }
						}
						else
						{
						  if((ad_previous-ad_next)>10)
						  {
						  go_up_ad=255;
						  direction_judge_complete_sign=1;
						  }
						}
				
					}
			
}						
 

 
void switch_realtime_process(void)
{
    
	//int b;
	//operate_mode=1;
	mode_toggle=1;
	operating_check[12]=mode_toggle;
	mode_flag=3;
    STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	switch_operation_close_mode=TEXT_Buffer[eeprom_write_switch_operation_close_mode];
	switch_operation_close_mode=switch_operation_close_mode&0x01;
    GpuSend4("CLS(15);\r\n");
    delay_ms(10);
	//Usart5Close();
    control_mode_register=4;
    operate_initial_dispaly();
													       

while(1)
{
                    
			if(hand_wheel_disable)		
			{		
			        if(torque_over_sign==0) 
        			{	
						
			        }
					
					else
                   	{

              		}
              			 
            }
			else
			{
			     stop();
			}		
					
					     //注意：
			
    			   if(quit_sign==1)
    				 {
    				  quit_sign=0;
                      break;    
    				 }
            		
			         
					    percent_now_count();
						pwm_excute();
			
        		   if(go_up_direction==100)
					{
					   
					   if(ExtKEY_OPEN&&(!ExtKEY_STOP))
					   {  
					      if((torque_over_sign==0)&&(hand_wheel_disable))  
    					   { 
							  
							  if(switch_operation_close_mode==0)  
							 {
    							  if(percent_now<995)
        					       {
        						   	
        						   if(percent_now>(int)(1000-speed_fall_position_register_count))
									  
            	  	          {
            				       slow_speed_on();
            		          }
            					else
            					{
            					   slow_speed_off();
            					}
    							   go_up_on();


        					       }
        						   
    							   
       							   if(percent_now>998)
									{
																	 
										stop();
																	
									}
							  }
							  else
							  {
							   go_up_on();
							  }
							  
						  }
						   
					   }
					   else if(ExtKEY_CLOSE&&(!ExtKEY_STOP))
					   {  
    					   if((torque_over_sign==0)&&(hand_wheel_disable))     
							{
        						if(switch_operation_close_mode==0)
								  {
									  if(percent_now>5)
            						  {
            						   
            						   if(percent_now<(int)speed_fall_position_register_count)
            					{
            					slow_speed_on();
            					}
            					else
            					{
            					slow_speed_off();
            					}
        							   go_down_on();
            					      }
            					       if(percent_now<2)
                            		   {
                                		     
        								   
                						   stop();
                            		      
        							      
        							   }
							       }
							   else
							   {
							   go_down_on();
							   }
							   
							   
							   
					       }
					   
					   }
					   else
            		   {
            		   
					   stop();
            		   torque_over_sign=0;
					   
					   }
					
					}
					
				else
					
					{
					
					   if(ExtKEY_OPEN&&(!ExtKEY_STOP))
					   {
    					     if((torque_over_sign==0)&&(hand_wheel_disable))   
							{
        						if(switch_operation_close_mode==0)
								  {
									  if(percent_now<995)
            						  {
        							   
        							  if(percent_now>(int)(1000-speed_fall_position_register_count))
									  
            	  	          {
            				       slow_speed_on();
            		          }
            					else
            					{
            					   slow_speed_off();
            					}
									   go_down_on();
            					      
        							  }
        							  if(percent_now>998)
        							  {
            						      
            							   stop();
        							      
        							  }
							     }
								 else
								 {
								 go_down_on();
								 }
							  
							  
							   
							  
					       }
					   }
					   else if(ExtKEY_CLOSE&&(!ExtKEY_STOP))
					   {
					       if((torque_over_sign==0)&&(hand_wheel_disable))  
    					    {
        							if(switch_operation_close_mode==0)
								  {  
									   if(percent_now>5)
            					       {
            						   
									  if(percent_now<(int)speed_fall_position_register_count)
            					{
            					slow_speed_on();
            					}
            					else
            					{
            					slow_speed_off();
            					}
            						   go_up_on();
            					      
        							   }
            						   else if(percent_now<2)
                            		  {
                                	       stop();
            						  }
							      }
								  
								  else
								 {
								    go_up_on();
								 }
							
						   }
					   }
					   else
            		   {
            		   
					   stop();
					  
            		   torque_over_sign=0;
					   //torque_led_off;
					   }
					
				 }
					
					
			 
				   key_scan();//扫键；

				
				 if((key_toggle_short_press)||(mode_toggle==0))   //闪屏BUG
					  //if(key_toggle_short_press)
				  {
				   	   key_register_reset;
				       while(!KEY_IDLE);
					    function_point=local_process;
				       break;
					 
				  }
				   
				  if(key_toggle_long_press)
				 {
				  
				   key_register_reset;
			   	 function_point=parameter_first;
				   break;
				 }     
				   
				   
   }

}



void ExtKEY_CLOSE_time_process(void)
{
  
	 while(1)   
	{	
	      
		 if(ExtKEY_DISABLE)
    	  {
        	   if(timer0_count>1)
    		   { 
				ExtKEY_CLOSE_process();
			   }
			   else
			   {
			    break;
    	    }
    	  }
    	 
			 
    	  if(timer0_count>1)
		  {
		    ExtKEY_CLOSE_process();
			break;
		  }
		
    }

}


void ExtKEY_OPEN_time_process(void)
{    
  
     while(1)   
	{	
		 if(ExtKEY_DISABLE)
    	  {
        	   if(timer0_count>1)
    		   { 
				ExtKEY_OPEN_process();
			   }
			   else
			   {
			    break;
    	       }
    	  }
    	  
    	  if(timer0_count>1)
		  {
		    ExtKEY_OPEN_process();
			break;
		  }
    }

}




void ExtKEY_CLOSE_process(void)
{
   //int a;
    STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	switch_operation_close_mode=TEXT_Buffer[eeprom_write_switch_operation_close_mode];
	switch_operation_close_mode=switch_operation_close_mode&0x01;
	
	while(1)
	{
    	             
    			     if(quit_sign==1)
    				 {
    				  
                       break;    
    				 
    				 }
            	    
					percent_now_count();
					pwm_excute(); 

					if(pulse_mode_quit_sign==1)
    				 {
    				  pulse_mode_quit_sign=0;
                	  break;    
    				 
    				 }
            
					
	                if(go_up_direction==100)
					{
					   if((torque_over_sign==0)&&(hand_wheel_disable))
					    {
    						if(switch_operation_close_mode==0)
    						 {	  
								  if(percent_now>5)
        					       {
        						   go_down_on();
								    if(percent_now<(int)speed_fall_position_register_count)
					{
					slow_speed_on();
					}
					else
					{
					slow_speed_off();
					}
							
        					       }
        						   if(percent_now<2)
                        		     {
                                	    stop();
            						    
                                	 }
    						}
							else
							{
							go_down_on();
							 
							} 
					   
					   }
					   
        					   
					
					}
					
				else
					
					{
					     if((torque_over_sign==0)&&(hand_wheel_disable))
					   {
					        if(switch_operation_close_mode==0)
    						 {
    							  if(percent_now>5)
        					       {
        						   
        						    if(percent_now<(int)speed_fall_position_register_count)
					{
					slow_speed_on();
					}
					else
					{
					slow_speed_off();
					}
    							   go_up_on();
        					       }
        						   else if(percent_now<2)
                        		  {
                                	     stop();
            				
    							  }
    					   }
						   else
						   {
						   go_up_on();
						   }
						   
						   
					   }
					
				   }
					
					key_scan();
					pwm_excute();
				if((ExtKEY_OPEN||ExtKEY_STOP||hand_wheel_enable||KEY_TOGGLE)||(mode_toggle==0)) 
				{
				   delay_short(10000);
				   if((ExtKEY_OPEN||ExtKEY_STOP||hand_wheel_enable||KEY_TOGGLE)||(mode_toggle==0))
				     {
					    delay_short(10000);
						if((ExtKEY_OPEN||ExtKEY_STOP||hand_wheel_enable||KEY_TOGGLE)||(mode_toggle==0))
						{
						 stop();
						 break;
						}
					 
					 }
				
				}
	      
	
	}
	
	
}




void ExtKEY_OPEN_process(void)
{ 
	
	  //int a;
     STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	switch_operation_close_mode=TEXT_Buffer[eeprom_write_switch_operation_close_mode];
	switch_operation_close_mode=switch_operation_close_mode&0x01; 	  
      
	  while(1)
	{
    	             
	                
					 
    			      if(quit_sign==1)
    				 {
    				  
					  break;    
    				 
    				 } 
            
					    percent_now_count();
						  
						  pwm_excute(); 
					  if(pulse_mode_quit_sign==1)
    				 {
    				  pulse_mode_quit_sign=0;
                	  break;    
    				 
    				 }
                    
					pwm_excute();
					
					
				
					
					
					if(go_up_direction==100)
					{
					   if((torque_over_sign==0)&&(hand_wheel_disable)) 
					    {
        							
								if(switch_operation_close_mode==0)
								  {	
									  if(percent_now<995)
            					       {
            						   
            						   	if(percent_now>(int)(1000-speed_fall_position_register_count))
					                     {
					                	  slow_speed_on();
					                     }
					                	else
					                	{
					                      slow_speed_off();
					                	}
        							   go_up_on();
            					       }
            						   else if(percent_now>998)
                            		  {
                            	      
            						   stop();
        							    
                            		   //stop_sign=0;
        							  }
						         }
								 else
								 {
								 go_up_on();
								 }
						
						}
        					   
					
					}
					
				else
					
					{
					     
					    if((torque_over_sign==0)&&(hand_wheel_disable))   
					   {
					        if(switch_operation_close_mode==0)
							{	
    							  if(percent_now<995)
        						  {
    							   	 	if(percent_now>(int)(1000-speed_fall_position_register_count))
					                     {
					                	  slow_speed_on();
					                     }
					                	else
					                	{
					                      slow_speed_off();
					                	}
    							   go_down_on();
        					       //stop_sign=1;
    							  }
    							  else if(percent_now>998)
    							  {
    						       
    							   stop();
    							    
    							   //stop_sign=0;
    							  }
					       }
						   else
						   {
						      go_down_on();
						   }
					       
					   }
					
				   }
					
					
					key_scan();

					
				
					if((ExtKEY_CLOSE||ExtKEY_STOP||hand_wheel_enable||KEY_TOGGLE)||(mode_toggle==0)) 
				{
				   delay_short(10000);
				   if((ExtKEY_CLOSE||ExtKEY_STOP||hand_wheel_enable||KEY_TOGGLE)||(mode_toggle==0))
				     {
					    delay_short(10000);
						if((ExtKEY_CLOSE||ExtKEY_STOP||hand_wheel_enable||KEY_TOGGLE)||(mode_toggle==0))
						{
						 stop();
						 break;
						}
					 
					 }
				
				}
	      
	
	}
	
}

void switch_pulse_process(void)
{
    //int b;
    STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	switch_operation_close_mode=TEXT_Buffer[eeprom_write_switch_operation_close_mode];
	switch_operation_close_mode=switch_operation_close_mode&0x01;
	mode_toggle=1;
	operating_check[12]=mode_toggle;
   //operate_mode=1;
	mode_flag=3;

	control_mode_register=5;
    GpuSend4("CLS(15);\r\n");
	delay_ms(8);
	operate_initial_dispaly();
	
 while(1)
   {
      	
      if(hand_wheel_disable)		
			{		
			        if(torque_over_sign==0) 
        			{	
							
		        	}
					
					else
                   	{
              			
              		         	if(switch_position_sign==1)
								 {
								     
								 }
                                 else if(switch_position_sign==2)
								 {
								     
								 }
                                 else
								 {
                        
                				 }                           
                				
              		}
              			 
              	
					
					
			}
			else
			{
			     ;
						
			
			}		

    			   if(quit_sign==1)
    				 {
    				  quit_sign=0;
                      break;    
    				 
    				 }
            		
			       percent_now_count();
				   pwm_excute();
					
				 if(ExtKEY_CLOSE&&(!ExtKEY_STOP)) 
				 {
				   timer0_reset();  
				   Timer4_Init();
                   ExtKEY_CLOSE_time_process();
				   
				 }
				 
				 
                          
				   
				  if(ExtKEY_OPEN&&(!ExtKEY_STOP)) 
				 {
				   timer0_reset();
				   Timer4_Init();
				   ExtKEY_OPEN_time_process();
				 } 
				   
                 if(ExtKEY_STOP)
				 {
				 	stop();
				 } 

                 key_scan();
				 
				if((key_toggle_short_press)||(mode_toggle==0))
				 
				// if(key_toggle_short_press)
				  {
				   	   key_register_reset;
				       
					   //while(!KEY_IDLE);
					   function_point=local_process;
				       break;
					 
				  }
   				
                 if(key_toggle_long_press)
				 {
				  
				  key_register_reset;
				  function_point=parameter_first;	 
				  break;
				 }  
   			   
   }
	 
    
} 
 
 

 
 
void read_motor_current(void)
{
  /* 
	unsigned char i;
     
	     
		{  
		   for(i=0;i<=7;i++)
           {
              while((USART1->SR&0X40)==0);
			  USART1->DR=read_current_array[i];
		   }
		   read_write_sign=0;
		}	
		*/	
}
 

void check_motor_current(void)
{
      
		unsigned int a;
		communicate();
		fault_check[fault_torque_over_position*2]=torque_over_times/256;
	    fault_check[fault_torque_over_position*2+1]=torque_over_times%256;
	
		 if(first_start_sign==1)
		 {
		 a=standard_torque+5;
		 first_start_sign=0;
		 }  
		 else
		 {
		 a=standard_torque;
		 }
		 a=standard_torque;
		 
		 if(operate_current_data>a)
		   {
		       stop_forward_simple;
               stop_reverse_simple;
			   stop_sign=0;
			   
		       torque_over_number=torque_over_number+1;
			   
				 
				// if(torque_over_number>=3)
			   {
			   torque_over_times=torque_over_times+1;
			   TEXT_Buffer[eeprom_write_torque_over_times]=(torque_over_times);	 
		       //fault_check[fault_torque_over_position*2]=torque_over_times/256;
			   //fault_check[fault_torque_over_position*2+1]=torque_over_times%256;
			   //delay_long(100);
			   current_data=0;
			   torque_over_relay_process();
			   torque_over_sign=1;
			   }
		/*	   
			   else
			   {
			   torque_over_times=torque_over_times+1;
			   TEXT_Buffer[eeprom_write_torque_over_times]=(torque_over_times);
			   delay_long(500);
			   //error_led_off;
			   //torque_led_off;
			   torque_over_sign=0;
			   current_data=0;
			   }
		*/	  
			  
		}
		    
			   if(current_data_over_sign==1)
			   {
			    torque_over_sign=1;
				  stop_sign=0;
			    //error_led_on;
			    //torque_led_off;
				  torque_over_times=torque_over_times+1;
			    TEXT_Buffer[eeprom_write_torque_over_times]=(torque_over_times);	
		        delay_long(100);
			    current_data=0;
				  current_data_over_sign=0;
			   }
			 																											 
		    
}
 
 		

void relay_process(void)
 {
                   
			 if(switch_operation_close_mode==0)
			{	   
				    if(percent_now<8)
					{
					   zero_pozition_relay_on();
					   full_pozition_relay_off();
					}
					 
					else if(percent_now<992)
					{ 
					   zero_pozition_relay_off();
					   full_pozition_relay_off();
					}
					else
					{
					  full_pozition_relay_on();
					  zero_pozition_relay_off();
					}
			}
			else
			{
			   
			       if(torque_over_sign==1)	
				   {
				   
        				      if(percent_now<30)
        					{
        					  zero_pozition_relay_on();
        					  full_pozition_relay_off();
							  switch_position_sign=1;
        				    }
        					 
        					else if(percent_now<970)
        					{ 
        					  zero_pozition_relay_off();
        					  full_pozition_relay_off();
							  switch_position_sign=0;
        					
        					}
        					else
        					{
        					   full_pozition_relay_on();
        					   zero_pozition_relay_off();
							   switch_position_sign=2;
        					}
        				   
				   }
				   
				   else
				   {
        				    if(percent_now<8)
        					{
        					zero_pozition_relay_on();
        					full_pozition_relay_off();
        					
        					
        					}
        					 
        					else if(percent_now<992)
        					{ 
        					zero_pozition_relay_off();
        					full_pozition_relay_off();
        					
        					}
        					else
        					{
        					full_pozition_relay_on();
        					zero_pozition_relay_off();
        					
        					}
				            switch_position_sign=0;
				   }
			
			}		
					
					
 }
 

 
 void relay_another_process(void)
 {
                   
			 if(switch_operation_close_mode==0)
			{	   
				    if(percent_now<8)
					{
					zero_pozition_relay_on();
					full_pozition_relay_off();
					
					
					}
					 
					else if(percent_now<992)
					{ 
					zero_pozition_relay_off();
					full_pozition_relay_off();
					
					}
					else
					{
					full_pozition_relay_on();
					zero_pozition_relay_off();
					
					}
			}
			else
			{
			   
			       if(torque_over_sign==1)	
				   {
				   
        				      if(percent_now<30)
        					{
        					  zero_pozition_relay_on();
        					 full_pozition_relay_off();
							     switch_position_sign=1;
        					
							    //error_led_off;
        					}
        					 
        					else if(percent_now<970)
        					{ 
        					zero_pozition_relay_off();
        					full_pozition_relay_off();
							    switch_position_sign=0;
        					
							
        					}
        					else
        					{
        					full_pozition_relay_on();
        					zero_pozition_relay_off();
							    switch_position_sign=2;
        					
							    // error_led_off;
        					}
        				   
				   }
				   
				   else
				   {
        				    if(percent_now<8)
        					{
        					zero_pozition_relay_on();
        					full_pozition_relay_off();
        					
        					
        					}
        					 
        					else if(percent_now<992)
        					{ 
        					zero_pozition_relay_off();
        					full_pozition_relay_off();
        					
        					}
        					else
        					{
        					full_pozition_relay_on();
        					zero_pozition_relay_off();
        					
        					}
				            switch_position_sign=0;
				   }
			
			}		
					
					
 }
 

void two_line_process(void)
{
    mode_toggle=1;
	operating_check[12]=mode_toggle;
	mode_flag=3;
    STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
	switch_operation_close_mode=TEXT_Buffer[eeprom_write_switch_operation_close_mode];

    GpuSend4("CLS(15);\r\n");
    delay_ms(10);
    control_mode_register=6;
    operate_initial_dispaly();
													       

while(1)
{
                  
    			   if(quit_sign==1)
    				 {
    				  quit_sign=0;
                      break;    
    				 }
            		
					percent_now_count();
					pwm_excute();
	
							
							
        		   if(go_up_direction==100)
					{
					   
					   if(ExtKEY_OPEN)
					   {  
					      if((torque_over_sign==0)&&(hand_wheel_disable))  
    					   { 
							  
							  if(switch_operation_close_mode==0)  
							 {
    							  if(percent_now<995)
        					       {
        						   	
        						   if(percent_now>(int)(1000-speed_fall_position_register_count))
									  
            	  	          {
            				       slow_speed_on();
            		          }
            					else
            					{
            					   slow_speed_off();
            					}
    							   go_up_on();


        					       }
        						   
    							   
       							   if(percent_now>998)
									{
																	 
										stop();
																	
									}
							  }
							  else
							  {
							   go_up_on();
							  }
						 
						  }
						   
					   }
					   else 
					   {  
    					   if((torque_over_sign==0)&&(hand_wheel_disable))     
							{
        						if(switch_operation_close_mode==0)
								  {
									  if(percent_now>5)
            						  {
            						   
            						   if(percent_now<(int)speed_fall_position_register_count)
            					{
            					slow_speed_on();
            					}
            					else
            					{
            					slow_speed_off();
            					}
        							   go_down_on();
            					      }
            					       if(percent_now<2)
                            		   {
                                		     
        								   
                						   stop();
                            		      
        							      
        							   }
							       }
							   else
							   {
							   go_down_on();
							   }
							   
					       }
					   
					   }
				
					
					}
					
				else
					
					{
					
					   if(ExtKEY_OPEN)
					   {
    					     if((torque_over_sign==0)&&(hand_wheel_disable))   
							{
        						if(switch_operation_close_mode==0)
								  {
									  if(percent_now<995)
            						  {
        							   
        							  if(percent_now>(int)(1000-speed_fall_position_register_count))
									  
            	  	          {
            				       slow_speed_on();
            		          }
            					else
            					{
            					   slow_speed_off();
            					}
									   go_down_on();
            					       //stop_sign=1;
        							  }
        							  if(percent_now>998)
        							  {
            						      stop();
        							  }
							     }
								 else
								 {
								     go_down_on();
								 }
							  
							  
							   
							  
					       }
					   }
					   else 
					   {
					       if((torque_over_sign==0)&&(hand_wheel_disable))  
    					    {
        							if(switch_operation_close_mode==0)
								  {  
									   if(percent_now>5)
            					       {
            						   
									  if(percent_now<(int)speed_fall_position_register_count)
            					{
            					slow_speed_on();
            					}
            					else
            					{
            					slow_speed_off();
            					}
            						   go_up_on();
            					       //stop_sign=1;
        							   }
            						   else if(percent_now<2)
                            		  {
                                	      stop();
            						  }
							      }
								  
								  else
								 {
								   go_up_on();
								 }
								 
						   }
					   }
				
					
				 }
					
				 key_scan();//扫键；
                 
				 if((key_toggle_short_press)||(mode_toggle==0))   //闪屏BUG
					  //if(key_toggle_short_press)
				  {
				   	   key_register_reset;
				       while(!KEY_IDLE);
					   function_point=local_process;
				       break;
					 
				  }
				   
				  if(key_toggle_long_press)
				 {
				  
				   key_register_reset;
			   	   function_point=parameter_first;
				   break;
				 }     
				   
				   
   }

}
















