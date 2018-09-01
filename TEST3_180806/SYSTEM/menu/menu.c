#include "led.h"
#include "key.h"
#include "delay.h"
#include "sys.h"
#include "menu.h"
#include <stdio.h>  //printf ����������


#define NULL 0
extern char buf[128];		                              //�����ַ���������ʾ������

extern unsigned int  key_flag;
extern void LED_FLASH(void);
extern void language_set(void);
extern void sensitive_set(void);
extern void motor_temperature_protect(void);
extern void speed_fall_position_set(void);
extern void torque_set(void);
extern void normal_speed_set(void);
extern void relay1_define(void);
extern void relay2_define(void);
extern void relay3_define(void);
extern void relay4_define(void);
extern void relay5_define(void);
extern void reaction_direction_set(void);
extern void	read_bus_voltage(void);
extern void	read_frequency_set(void);
extern void	read_pm_temperature(void);
extern void	read_operate_time(void);
extern void soft_version(void);
extern void all_run_time(void);
extern void switch_num(void);
extern void torque_over_times_display(void);
extern void	read_fault_current(void);
extern void	read_fault_voltage(void);
extern void	read_fault_pm_temperature(void);
extern void	read_fault_bus_voltage(void);
extern void	read_fault_frequency(void);
extern void	read_fault_set_frequency(void);
extern void	read_first_fault(void);
extern void	read_second_fault(void);
extern void	read_Third_fault(void);
extern void relay1_open_close_set(void);
extern void relay2_open_close_set(void);
extern void relay3_open_close_set(void);
extern void relay4_open_close_set(void);
extern void relay5_open_close_set(void);

extern void torque_select_process(void);
extern void simens_add_speed_choice(void);
extern void analog_mode_enable(void);
extern void signal_off_set(void);
extern void emergency_set(void);
extern void switch_close_mode_select(void);
extern void switch_mode_select(void);
extern void switch_mode_enable(void);
extern void start_point_set(void);
extern void end_point_set(void);
extern void local_process(void);
extern void remote_process(void);
extern void zero_current_set(void);
extern void full_current_set(void);
extern void stop(void);
void Usart5Close(void);
extern	void BT_set(void);
extern void percent_now_count(void);

extern unsigned char quit_sign;
extern unsigned char fault_register;
extern void (*function_point)();//�ǳ���Ҫ ����ָ�� 

extern void GpuSend4(char *buf2);
extern void zero_feedback_adjust(void);
extern void full_feedback_adjust(void);
extern unsigned char   sensitive_register,move_direction_register,emergency_position_register,move_direction_register_temporary,move_direction_register_temporary1,
                       motor_protect_register,normal_speed_register,language_register,speed_register;
extern void torque_compensate_low_adjust(void);
extern void torque_compensate_adjust(void);
extern void dec_speed_set(void);
extern unsigned int passwd;
extern void password(void);
extern unsigned char uart5_count1_array[36];
extern unsigned char array_test[36];
extern void handware(void);
extern void product_id_set(void);
extern unsigned char switch_mode_sign;


void local_set(void);

volatile uint menuid[70]={1,2,3,10,11,12,13,14,15,16,17,18,19,20,21,30,31,32,33,34,35,36,110,111,140,141,150,151,180,181,182,183,184,190,191,192,193,194,200,201,202,203,204,205,206,207,
210,211,212,213,214,215,216,217,218,219,300,301,310,311,330,331,360,361,362,363,364,1410,1411,1412};
	
struct MenuItem  Menu_main[]=
{
 
			 {1,"�û���������","parameter set",3,0,NULL,1},   
			 {2,"�����۲����","diagnosis",3,1,NULL,2},   
			 {3,"������������","factory set",3,2,NULL,3},  
			
			 {10,"��������","language set",10,0,language_set,9},
			 {11,"�г�����","distance set",10,1,NULL,10},                                    
			 {12,"��������","sensitive set",10,2,sensitive_set,11},
			 {13,"�ض���������","torque set",10,3,torque_set,12},
			 {14,"����ģʽ����","control set",10,4,NULL,13}, 
			 {15,"����λ������","signal off set",10,5,NULL,14},
			 {16,"����λ������","speed.dec.pos.",10,6,speed_fall_position_set,15},
			 {17,"�����ٶ�����","speed set",10,7,normal_speed_set,16},
			 {18,"�̵�������","relay set",10,8,NULL,17},
			 {19,"��������","other set",10,9,NULL,18}, 
			
			 {20,"���в�����ѯ","param.check",2,0,NULL,19},
			 {21,"���ϲ�����ѯ","fault check",2,1,NULL,20},
			
			 {30,"�����źű궨","input set",7,0,NULL,0},
			 {31,"�����źű궨","output set",7,1,NULL,0},
			 {32,"�ͺ�����","model config",7,2,product_id_set,0},
			 {33,"���ز���","torque.com",7,3,NULL,0},
			 {34,"��������ѡ��","torque.cho",7,4,torque_select_process,0},
			 {35,"�ٶ�����ѡ��","speed.cho",7,5,simens_add_speed_choice,0},
			 {36,"�̵����л�����","Relay.cho",7,6,NULL,0},
																		   
			 {110,"��ĩ���趨","close.pos set",2,0,start_point_set,23},
			 {111,"��ĩ���趨","open.pos set",2,1,end_point_set,24},
			  
			 {140,"ģ����Զ��","analog remote",2,0,analog_mode_enable,25},
			 {141,"������Զ��","switch remote",2,1,NULL,26},
			
			 {150,"������λ����","em.keep.set ",2,0,signal_off_set,27},
			 {151,"����λ������","emergencyset",2,1,emergency_set,28},
			
			 {180,"�̵���1�趨","relay1 set",5,0,relay1_define,0},
			 {181,"�̵���2�趨","relay2 set",5,1,relay2_define,0},
			 {182,"�̵���3�趨","relay3 set",5,2,relay3_define,0},
			 {183,"�̵���4�趨","relay4 set",5,3,relay4_define,0},
			 {184,"�̵���5�趨","relay5 set",5,4,relay5_define,0},
			
			 {190,"�����ٶ�����","speed.dec.pos.",5,0,dec_speed_set,29},   
			 {191,"�����������","motor.pro set",5,1,motor_temperature_protect,30},  
			 {192,"������������","direction set",5,2,reaction_direction_set,31},
			 {193,"�ֳ�����","local set",5,3,local_set,54},
			 {194,"��������","BT set",5,4,BT_set,158},
			
			 {200,"ĸ�ߵ�ѹ","DC voltage",8,0,read_bus_voltage,32},
			 {201,"�趨Ƶ��","frequency set",8,1,read_frequency_set,33},
			 {202,"ģ���¶�","PM.tempe",8,2,read_pm_temperature,34},
			 {203,"����ʱ��","time operate",8,3,read_operate_time,35},
			 {204,"Ӳ���ͺ�","handware",8,4,handware,36},   
			 {205,"����汾","Software",8,5,soft_version,37},
			 {206,"ͨ����ʱ��","Power on time",8,6,all_run_time,38},
			 {207,"�����ܴ���","Switch times",8,7,switch_num,39}, 
			 
			 {210,"�����ش���","torque.ov times",10,0,torque_over_times_display,0},
			 {211,"����ʱ�������","current output",10,1,read_fault_current,0},
			 {212,"����ʱ�����ѹ","voltage output",10,2,read_fault_voltage,0},
			 {213,"����ʱ���Ƶ��","frequency out",10,3,read_fault_frequency,0},
			 {214,"����ʱ�趨Ƶ��","frequency set",10,4,read_fault_set_frequency,0},
			 {215,"����ʱĸ�ߵ�ѹ","DC bus voltage",10,5,read_fault_bus_voltage,0},
			 {216,"����ʱģ���¶�","PM temperature",10,6,read_fault_pm_temperature,0},
			 {217,"ǰһ�ι���","first fault",10,7,read_first_fault,0},
			 {218,"ǰ���ι���","second fault",10,8,read_second_fault,0},
			 {219,"ǰ���ι���","Third fault",10,9,read_Third_fault,0},  
			 
			 {300,"����4 mA�궨","input 4mA",2,0,zero_current_set,0},   
			 {301,"����20mA�궨","input20mA",2,1,full_current_set,0},   
			 
			 {310,"����4 mA�궨","output 4mA",2,0,zero_feedback_adjust,0},   
			 {311,"����20mA�궨","output20mA",2,1,full_feedback_adjust,0},   
			
			 {330,"�����ز���","torque1 set",2,0,torque_compensate_adjust,0},    
			 {331,"�����ز���","torque2 set",2,1,torque_compensate_low_adjust,0},    
			
			 {360,"�̵����л�1","Relay1",5,0,relay1_open_close_set,0},
			 {361,"�̵����л�2","Relay2",5,1,relay2_open_close_set,0},
			 {362,"�̵����л�3","Relay3",5,2,relay3_open_close_set,0},
			 {363,"�̵����л�4","Relay4",5,3,relay4_open_close_set,0},
			 {364,"�̵����л�5","Relay5",5,4,relay5_open_close_set,0},  
			
			 {1400,"����������","Switch control",3,0,switch_mode_enable,0},
			 {1401,"����ģʽ  ","Trigger  mode",3,1,switch_mode_select,0},
			 {1402,"�ض�ģʽ  ","Shutdown mode",3,2,switch_close_mode_select,0},  
			 
};


struct MenuItem *getmenu(uint id)
{
    uchar i;  
    for(i=0;i<69;i++)
 {
    if(id==menuid[i]) return &Menu_main[i];
 
 }   
    return NULL;
}


void parameter_first(void)

{
      stop();
	  Usart5Close();
	  order_point=0; 
	  menu_point=Menu_main;
	  GpuSend4("CLS(15);\r\n");   
      delay_ms(15); 


while(1)
{
		   key_scan();
 		   sprintf(buf,"PIC(327,0,%d);\r\n",(*menu_point).photo);
           GpuSend4(buf);
	       delay_ms(28);
		
		  if(language_register==1)
		  {
				GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
				delay_ms(18);
				sprintf(buf,"DS48(0,0,'%s',0);\r\n",(*menu_point).displaystring2);
				GpuSend4(buf);
				delay_ms(18);
			    GpuSend4("PIC(0,80,156);\r\n");
				delay_ms(18);
			  
         }
	     else
		{
				GpuSend4("DS48(0,270,'����',0,0);DS48(382,270,'ȷ��',0,0);\r\n");
				delay_ms(28);
				sprintf(buf,"DS48(0,0,'%s',0);\r\n",(*menu_point).displaystring);
				GpuSend4(buf);
				delay_ms(28);
			    GpuSend4("PIC(0,80,157);\r\n");
				delay_ms(28);
        }		 
			


			if(key_up_short_press)
			{
		     	key_register_reset; 
		        GpuSend4("CLS(15);"); 
		     	delay_ms(28);
			if((menu_point->cur)!=((menu_point->total)-1))
			{
		     	menu_point+=1;
			}	
			else
			{
		    	menu_point=getmenu((menu_point->ID)-((menu_point->total)-1));
		     	order_point=menu_point->ID;
			if(order_point>1500)
			{
			    menu_point=getmenu(1410);
			}					 
           }
			    
			  key_scan();
			}
             
	

			if(key_down_short_press)
			{
			     key_register_reset;
				 GpuSend4("CLS(15);");
				 delay_ms(28);
				if((menu_point->cur)!=0)
				{
				  menu_point-=1;
				}
				else
				{
				  menu_point=getmenu((menu_point->ID)+((menu_point->total)-1));
				   order_point=menu_point->ID;
				if(order_point>1500)
				{
				   menu_point=getmenu(1412);
				}					 
				
				}
       
          }	
		  
		  if(key_enter_short_press)
		{
				key_register_reset;
				GpuSend4("CLS(15);");
				delay_ms(18);
				
				order_point=(menu_point->ID)*10;
				ptemp=getmenu(order_point);
				
                if(ptemp!=NULL)
                {
                    menu_point=ptemp;
                }
				
				
				else
			 	{
				  (*menu_point->doing)(Menu_main); 
                }
			
			 
			 
			  if(menu_point->ID==30)
		 	 {
			   function_point=password;
			   (*function_point)();	 // ����
			 }	 
			 
			}
			
			key_scan();
			
			 if(key_toggle_short_press)
		   {
			  
				 key_register_reset;
				 GpuSend4("CLS(15);");
				 delay_ms(18);
			     order_point=(menu_point->ID)/10;
				
				if(order_point<1)
			    {
				   order_point=1;
				}		
			  ptemp=getmenu(order_point);
				
				if(ptemp!=NULL)
				{
				   menu_point=ptemp;
				}
			
        }	
		    if(key_toggle_long_press)
		   {
					key_register_reset;
					quit_sign=1;
				    function_point=local_process;
					fault_register=fault_register&0xbf;
					GpuSend4("CLS(15);");
			        delay_ms(18);

					 if(language_register==0)
					{
					  GpuSend4("DS32(0,0,'���ַ��������棡',0,0);\r\n");
					  delay_ms(20);			
				   } 
					else
					{
					   GpuSend4("DS32(0,0,'loose hand back to main',0,0);DS32(0,34,'-function!',0,0);\r\n");
			           delay_ms(20); 
					}
                    
					while(!KEY_IDLE);
					break;
			}
	   }	


}


void password(void)
{
    unsigned int middle;
	signed int a,b,c,d;
	unsigned char point;
	 
	GpuSend4("CLS(15);\r\n");
	delay_ms(10); 
	
	point=0;
	middle=0;
	
	a=middle/1000;
	b=middle/100;
	c=middle%100/10;
	d=middle%10;
  
	delay_long(20);
	key_register_reset;
	key_toggle_used=0;
	key_enter_used=0;
	key_up_used=0;
	key_down_used=0;
	
	while(1)
	{ 
			key_scan();

		if(language_register==1)
		{
			GpuSend4("DS48(0,270,'BACK',0,0);DS48(340,270,'ENTER',0,0);\r\n");
			delay_ms(20);
			GpuSend4("DS48(116,0,'PASSWORD',0,0);\r\n");
			delay_ms(20);
		
		}
		else
		{
			GpuSend4("DS48(0,270,'����',0,0);DS48(382,270,'ȷ��',0,0);\r\n");
			delay_ms(20);
			GpuSend4("DS48(116,0,'����������',0,0);\r\n");
			delay_ms(20);
		
		}	


		 switch(point)
     {
            						   
		  case 0:sprintf(buf,"DS48(180,137,'%d',1);\r\n",a);GpuSend4(buf);sprintf(buf,"DS48(210,137,'%d',0);\r\n",b);GpuSend4(buf);sprintf(buf,"DS48(240,137,'%d',0);\r\n",c);GpuSend4(buf);sprintf(buf,"DS48(270,137,'%d',0);\r\n",d);GpuSend4(buf);break;
          case 1:sprintf(buf,"DS48(180,137,'%d',0);\r\n",a);GpuSend4(buf);sprintf(buf,"DS48(210,137,'%d',1);\r\n",b);GpuSend4(buf);sprintf(buf,"DS48(240,137,'%d',0);\r\n",c);GpuSend4(buf);sprintf(buf,"DS48(270,137,'%d',0);\r\n",d);GpuSend4(buf);break;
          case 2:sprintf(buf,"DS48(180,137,'%d',0);\r\n",a);GpuSend4(buf);sprintf(buf,"DS48(210,137,'%d',0);\r\n",b);GpuSend4(buf);sprintf(buf,"DS48(240,137,'%d',1);\r\n",c);GpuSend4(buf);sprintf(buf,"DS48(270,137,'%d',0);\r\n",d);GpuSend4(buf);break;
          case 3:sprintf(buf,"DS48(180,137,'%d',0);\r\n",a);GpuSend4(buf);sprintf(buf,"DS48(210,137,'%d',0);\r\n",b);GpuSend4(buf);sprintf(buf,"DS48(240,137,'%d',0);\r\n",c);GpuSend4(buf);sprintf(buf,"DS48(270,137,'%d',1);\r\n",d);GpuSend4(buf);break;

     }
		
		
		
		
       if(key_up_short_press)
     {
		      key_register_reset;
		      switch(point)
		      {
		        case 0:a+=1;break;
		        case 1:b+=1;break;
		        case 2:c+=1;break;
				case 3:d+=1;break;
		      }
									
	 }
					           
		if(key_down_short_press)
       {
		        key_register_reset;
		        switch(point)
		        {
		          case 0:a-=1;break;
		          case 1:b-=1;break;
		          case 2:c-=1;break;
				  case 3:d-=1;break;
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
	   if(d>9)
	   {
	      d=0;
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
	    
	   if(d<0)
	   {
	     d=9;
	   }
							     

												
			   	 if(key_enter_long_press)
				 {
				    key_register_reset;
					if((a==3)&&(b==1)&&(c==5)&&(d==4))
					 {
						menu_point=getmenu(30);
						GpuSend4("CLS(15);"); 
						delay_ms(15);
						GpuSend4("DS48(0,0,'OK!',0,0);\r\n");
						delay_ms(20); 
						while(!KEY_IDLE);
						break;
                    }
				  
			else
			{
               if(language_register==1)
		          {
                        GpuSend4("DS48(116,137,'PASSWORD ERROR',0,0);\r\n");
					    delay_ms(500); 																	  
                  }
	            else
		        {
                        GpuSend4("DS48(116,137,'�������',0,0);\r\n");
						delay_ms(500); 
	            }	
					GpuSend4("CLS(15);\r\n");
	                delay_ms(10); 
					
            }
					
					
				 }
					 
					 if(key_enter_short_press)
				 {
				  
				    key_register_reset;
				    point+=1;
					if(point>3)
					{
					  point=0;
					}

				 }
			   	 
				 	 if(key_toggle_long_press)
				 {
				    key_register_reset;
					GpuSend4("CLS(15);\r\n");
	                 delay_ms(8);
					function_point=parameter_first;
					(*function_point)(); 
				     break;
				 } 
				
			} 


}







