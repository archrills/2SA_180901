#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "key.h"
#include "menu.h"
#include "timer.h"
#include "adc.h"
#include "stmflash.h"
#include "header.h"
#include "pwm.h"
#include "exti.h"
#define switch_mode_detect (0)

unsigned char  key_toggle_used,key_enter_used,key_up_used,key_down_used;
unsigned int   timer0_count,timer2_count,torque_register;
unsigned char  key_short_register,key_longtime_register;
unsigned char  menu0_position,menu1_position,menu2_position;
unsigned int   speed_fall_position_register,speed_fall_position_register_count;
unsigned char  motor_protect_sign;
unsigned char  torque_select;
unsigned int   key_flag;
unsigned char  go_up_direction;
unsigned char  reaction_direction; 
unsigned char  relay1_state,relay2_state,relay3_state,relay4_state,relay5_state;
float          sen_temp;
unsigned long  switch_number;
unsigned char  torque_over_times;
signed int     order_point;
struct  MenuItem *menu_point,*ptemp;
signed char menu_position;
unsigned char speed_select;
unsigned char speed_rpm_select;
unsigned char signal_emergency_position_register;
unsigned char switch_operation_close_mode;
unsigned char switch_mode_select_variable;	
unsigned char analog_limit_sign;
unsigned char uart1_count=0;
//unsigned char first_uart;
unsigned char remote_sign;
signed char pass_border_sign;
unsigned char crc_h_register,crc_l_register;
unsigned char important_data_array[47];
unsigned char fault_register;

// 0x01	  0xfe		过温
// 0x02	  0xfd		过压
// 0x04   0x0b      正向过力矩
// 0X08   0x07      反向过力矩

unsigned char quit_sign;
unsigned char encoder_error_sign=0;
signed long int  start_point_ad,end_point_ad,all_distance;
signed long int turns,all_angle,angle;
int   percent_now,percent_set;
unsigned char reaction_direction;  
unsigned char  stop_sign;
unsigned char timer_delay_count;
unsigned char timer_delay_sign;
unsigned int AD_temperature_register;
unsigned char motor_protect_sign;								    
unsigned int timer_AD_delay;
unsigned int current_data,AD_register;
unsigned char pulse_mode_quit_sign;
unsigned char first_uart=0;

unsigned char uart2_receive_array[6]={0,0,0,0,0,0};

unsigned char first_uart_start=0;
unsigned int turns_act,angle_act;
signed char pass_border_sign;
signed int  turns_provious;
signed char pass_border_sign;
signed char pass_border_sign_previous;
signed char start_point_ad_h_register,start_angle_register_h,end_angle_register_h,end_point_ad_h_register;
signed char start_point_ad_l_register,start_angle_register_l,end_angle_register_l,end_point_ad_l_register;
signed long int    start_point_ad,end_point_ad,all_distance;
unsigned char go_up_ad;
signed char   pass_border_sign;
unsigned char key_keep_register;
unsigned char torque_over_sign;
unsigned char display_select;

unsigned char read_write_sign;
unsigned char crc_result;
unsigned char uart1_count_array[9];
unsigned int  operate_current_data;
unsigned int  operate_voltage_data;

unsigned int  operate_set_freq_data;
unsigned int  operate_hour_data;
unsigned int  operate_module_temperature_data;
unsigned int  operate_motor_speed_data;
unsigned int  operate_inverter_code_data;
unsigned int  operate_bus_voltage_data;
unsigned char send_catalogue;						 
unsigned int  fault_first_record_data;
unsigned int  fault_second_record_data;
unsigned int  fault_third_record_data;
unsigned int  fault_out_freq_data ;
unsigned int  fault_set_freq_data ;
unsigned int  fault_out_current_data;
unsigned int  fault_out_voltage_data;
unsigned int  fault_bus_voltage_data;
unsigned int  fault_module_temperature_data;
unsigned char mode_check[20];
unsigned char operating_check[20];
unsigned char first_fault_record;	
int zero_mA_ad_h_register,full_mA_ad_h_register;
int full_mA_ad,all_mA_ad;
unsigned int ad_now_input;
int zero_mA_ad;
unsigned char fault_check[35];
unsigned char parameter_check[];

unsigned int try1,try2,try3,try4;
char buf[128];		       //常用字符串翻译显示缓冲区
void (*function_point)();//非常重要 程序指针
extern void language_set(void);
extern void sensitive_set(void);
extern void motor_temperature_protect(void);
extern void speed_fall_position_set(void);
extern void torque_set(void);
extern void RUN_TEST(void);
extern void encoder_act(void);
extern void go_up_on(void);
extern void go_down_on(void);
extern void stop(void);
extern void start_point_set(void);
extern void percent_now_count(void);
extern void local_process(void);
extern  void remote_process(void);
extern void zero_current_set(void);
extern unsigned char TEXT_Buffer[262];
extern void switch_realtime_process(void);
extern void Timer5_Init(void);

signed int   percent_dispaly,percent_dispaly1,percent_dispaly2;
unsigned int current_ad_now0,current_ad_now1,current_ad_now2,current_ad_now3,current_ad_now4,
             current_ad_now5,current_ad_now6,current_ad_now7,current_ad_now8,current_ad_now9,
			 current_ad_now10,current_ad_now11,current_ad_now12,current_ad_now13,current_ad_now14,
			 current_ad_now15,current_ad_now16,current_ad_now17,current_ad_now18,current_ad_now19,current_ad_now20;

unsigned char ad_sample_number;
unsigned int ad_now_input;
int zero_mA_ad;
int full_mA_ad,all_mA_ad;
unsigned char signal_emergency_position_register;
unsigned char operate_mode,mode_flag;
unsigned char remote_direction;
unsigned char mode_toggle,flag_test,stop_flag,stop_flag1;
char pwm_value_zero_l_register,pwm_value_full_l_register,zero_mA_ad_l_register,full_mA_ad_l_register;
int    zero_mA_ad_h_register,full_mA_ad_h_register;

unsigned char timer0_count_enough;
unsigned char long_quit_sign;
extern unsigned char   sensitive_register,move_direction_register,emergency_position_register,move_direction_register_temporary,move_direction_register_temporary1,
                       motor_protect_register,normal_speed_register,language_register,speed_register;
unsigned char switch_mode_sign;
unsigned int torque_compensate_number;
unsigned char switch_position_sign;	
unsigned char try11,try12,try13;
unsigned int address,standard_torque;
unsigned int all_pwm_value_register,zero_pwm_value_register,full_pwm_value_register,pwm_value_zero_h_register,pwm_value_full_h_register;
unsigned char first_start_sign;	
unsigned char current_data_over_sign;
unsigned char *p_receive;
unsigned char uart3_order;
unsigned char relay1_meaning,relay2_meaning,relay3_meaning,relay4_meaning,relay5_meaning,
              relay6_meaning,relay7_meaning,relay8_meaning;
unsigned char order;							
unsigned char request_order=0;							
unsigned char torque_over_number;							
unsigned char release_sign; 							
unsigned char have_writen_sign;							
int flag_pwm;	
extern unsigned char timer_ov;
unsigned char read_current_array[16]={0X01,0X03,0x21,0X04,0X00,0X01,0xCF,0xF7};

signed long int ad_previous,ad_next,encoder_previous;
unsigned char  direction_judge_complete_sign=0;
unsigned char go_up_ad;

unsigned char start_speed_test;
unsigned int speed_judge_period_count=0;
unsigned char switch_position_sign;

unsigned char alarm_sign;

unsigned char relay1_meaning,relay2_meaning,relay3_meaning,relay4_meaning,relay5_meaning,
              relay6_meaning,relay7_meaning,relay8_meaning;
unsigned char relay1_state,relay2_state,relay3_state,relay4_state,relay5_state;
unsigned char move_direction;
unsigned char first_start_sign;	
extern unsigned char timer5_count;
void phase_lack_check(void);
void write_modbus_data(unsigned char address_hundred,unsigned char address_ten_bit,unsigned char value_ten,unsigned char value_bit);
void relay_switch_Init(void);   
extern void switch_mode_process(void);
long int   count_number,count_number1;
void password(void);
unsigned int passwd;

unsigned char uart5_receive_array[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char uart5_order;
unsigned char Bluetooth_AT,Bluetooth_NAME;
unsigned char uart5_count_array[36];
unsigned char uart5_count1_array[36];
unsigned char uart5_bit0;	
unsigned char try6;

unsigned char key_allowed=0;
unsigned char ProductId[20];
unsigned char parameter_set[36]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned int signal_out_value;
signed char app_volt,app_speed,app_year,app_torque,app_number1,app_number2;	
unsigned int at1_array[40]={0,0,0,0,0,0,0,0,0,0};	
unsigned char at_array[2];	
void  uart5_init(u32 bound);
void bluetooth_Init(void);
unsigned char temp1,temp2;
unsigned char switch_flag;
u32 ChipUniqueID[3];

unsigned char run_direction;
unsigned char local_register;
unsigned char bluetooth_sign;
void two_line_process(void);

extern void Timer6_Init(void);
extern void Timer7_Init(void);

void register_initial(void)
{
   unsigned char a;													    
   unsigned int middle,middle1;
   unsigned int num1,num2,num3,num4;
	
   STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
   middle1=TEXT_Buffer[eeprom_write_torque_h]; 
   
   sensitive_register=TEXT_Buffer[eeprom_write_sensitive];            
   analog_limit_sign=TEXT_Buffer[eeprom_write_analog_limit_sign];
   move_direction_register_temporary=TEXT_Buffer[eeprom_write_reaction_direction];	
   go_up_direction=TEXT_Buffer[eeprom_write_move_direction];       
   signal_emergency_position_register=TEXT_Buffer[eeprom_write_signal_emergency_position];    //紧急位置   
   emergency_position_register=TEXT_Buffer[eeprom_write_emergency_position];  				  
   long_quit_sign=0;
   speed_select=TEXT_Buffer[eeprom_write_speed_rpm_select];
   bluetooth_sign=TEXT_Buffer[eeprom_write_bluetooth];

   zero_mA_ad_h_register=       TEXT_Buffer[eeprom_write_zero_mA_ad_h];         
   zero_mA_ad_l_register=       TEXT_Buffer[eeprom_write_zero_mA_ad_l];        
   full_mA_ad_h_register=       TEXT_Buffer[eeprom_write_full_mA_ad_h];         
   full_mA_ad_l_register=       TEXT_Buffer[eeprom_write_full_mA_ad_l]; 
	 
   start_point_ad_h_register=   TEXT_Buffer[eeprom_write_start_point_ad_h];     
   start_point_ad_l_register=   TEXT_Buffer[eeprom_write_start_point_ad_l];     
   end_point_ad_h_register=     TEXT_Buffer[eeprom_write_end_point_ad_h];       
   end_point_ad_l_register=     TEXT_Buffer[eeprom_write_end_point_ad_l];
   start_angle_register_h=      TEXT_Buffer[eeprom_write_start_angle_h];
   start_angle_register_l=      TEXT_Buffer[eeprom_write_start_angle_l];
   end_angle_register_h=        TEXT_Buffer[eeprom_write_end_angle_h];
   end_angle_register_l=        TEXT_Buffer[eeprom_write_end_angle_l];

   local_register=TEXT_Buffer[eeprom_write_local_register];
	  
    start_point_ad=((signed long int)start_point_ad_h_register*128+(signed long int)start_point_ad_l_register)*1024+((signed int)start_angle_register_h*128+(signed int)start_angle_register_l);
    end_point_ad=((signed long int)end_point_ad_h_register*128+(signed long int)end_point_ad_l_register)*1024+((signed int)end_angle_register_h*128+(signed int)end_angle_register_l);
    all_distance=end_point_ad-start_point_ad;
	 
   
   torque_register= middle1*256 + TEXT_Buffer[eeprom_write_torque];
   speed_register= TEXT_Buffer[eeprom_write_speed]; 
   
   speed_fall_position_register= TEXT_Buffer[eeprom_write_speed_fall_position];
   speed_fall_position_register_count=speed_fall_position_register*10;
        
   torque_compensate_number=TEXT_Buffer[eeprom_write_torque_compensate];
   motor_protect_sign=TEXT_Buffer[eeprom_write_motor_protect];
   switch_position_sign=0;
   
   remote_direction=0;
   //motor_protect_sign=0;
   
   torque_select=TEXT_Buffer[eeprom_write_torque_select];
	 
   try11=TEXT_Buffer[eeprom_write_torque_percent];
   try12=TEXT_Buffer[eeprom_write_torque_compensate_low];
   try13= TEXT_Buffer[eeprom_write_torque_compensate];
	 
	 
   standard_torque=((unsigned int)(TEXT_Buffer[eeprom_write_torque_compensate_h]*256+
   (unsigned int)TEXT_Buffer[eeprom_write_torque_compensate]-(unsigned int)TEXT_Buffer[eeprom_write_torque_compensate_low])*
   (unsigned int)(TEXT_Buffer[eeprom_write_torque_percent]-3)/7+TEXT_Buffer[eeprom_write_torque_compensate_low]+5);
  
	 
   num1=TEXT_Buffer[switch_num1];
   num2=TEXT_Buffer[switch_num2];
   num3=TEXT_Buffer[switch_num3];
   num4=TEXT_Buffer[switch_num4];
   switch_number=((num4<<24)+(num3<<16)+(num2*256)+num1);
  
	 
   middle=speed_register;
   if(middle<10)
   middle=10;
   middle=torque_register;
  
   
   display_select=0;
   zero_mA_ad=zero_mA_ad_h_register*256+zero_mA_ad_l_register;
   full_mA_ad=full_mA_ad_h_register*256+full_mA_ad_l_register;
   all_mA_ad=full_mA_ad-zero_mA_ad;
   
   start_point_ad=start_point_ad_h_register*256+start_point_ad_l_register;
   end_point_ad=end_point_ad_h_register*256+end_point_ad_l_register;
   all_distance=(end_point_ad-start_point_ad);
   
   pwm_value_zero_h_register= TEXT_Buffer[eeprom_write_pwm_value_zero_h];
   pwm_value_zero_l_register= TEXT_Buffer[eeprom_write_pwm_value_zero_l];
   pwm_value_full_h_register= TEXT_Buffer[eeprom_write_pwm_value_full_h];
   pwm_value_full_l_register= TEXT_Buffer[eeprom_write_pwm_value_full_l];
	
   zero_pwm_value_register=pwm_value_zero_h_register*256+pwm_value_zero_l_register;
   full_pwm_value_register=pwm_value_full_h_register*256+pwm_value_full_l_register;
   all_pwm_value_register=full_pwm_value_register-zero_pwm_value_register;
	 
   language_register=TEXT_Buffer[eeprom_write_language];
   timer_delay_count=0;
   timer_delay_sign=0;
   stop_sign=0;
   first_start_sign=1;
   current_data_over_sign=0;
   quit_sign=0;
   torque_over_sign=0;
   remote_sign=0;
   timer_AD_delay=0;
	
   key_short_register=0;
   key_longtime_register=0;
   key_toggle_used=0;
   key_enter_used=0;
   key_up_used=0;
   key_down_used=0;
   
   switch_mode_select_variable=TEXT_Buffer[eeprom_write_switch_mode];
   switch_mode_sign=TEXT_Buffer[eeprom_write_local_remote_sign];
   switch_operation_close_mode=TEXT_Buffer[eeprom_write_switch_operation_close_mode];
   analog_limit_sign=TEXT_Buffer[eeprom_write_analog_limit_sign];
   
   ad_sample_number=0;
   uart3_order=0;
   a=TEXT_Buffer[eeprom_write_local_remote];
   pulse_mode_quit_sign=0;
	 
   if(a==0)
   {
     function_point=remote_process;
   }
   		  
   else if(a==1)
   
  {
     function_point=local_process;
  }
   else
   {
     function_point=switch_mode_process;
   }
	
   timer0_count_enough=0;
   order=0;
   current_data=0;
   request_order=0;

   torque_select=TEXT_Buffer[eeprom_write_torque_select];
   speed_rpm_select=TEXT_Buffer[eeprom_write_speed_rpm_select];
   reaction_direction=TEXT_Buffer[eeprom_write_reaction_direction];

   relay1_meaning=TEXT_Buffer[eeprom_write_relay1];
   relay2_meaning=TEXT_Buffer[eeprom_write_relay2];
   relay3_meaning=TEXT_Buffer[eeprom_write_relay3];
   relay4_meaning=TEXT_Buffer[eeprom_write_relay4];
   relay5_meaning=TEXT_Buffer[eeprom_write_relay5];
   relay6_meaning=TEXT_Buffer[eeprom_write_relay6];
   relay7_meaning=TEXT_Buffer[eeprom_write_relay7];
   relay8_meaning=TEXT_Buffer[eeprom_write_relay8];
   relay1_state=TEXT_Buffer[eeprom_write_relay1_state];
   relay2_state=TEXT_Buffer[eeprom_write_relay2_state];
   relay3_state=TEXT_Buffer[eeprom_write_relay3_state];
   relay4_state=TEXT_Buffer[eeprom_write_relay4_state];
   relay5_state=TEXT_Buffer[eeprom_write_relay5_state];
   torque_over_times=TEXT_Buffer[eeprom_write_torque_over_times];
   torque_over_number=0;
   release_sign=0;
   fault_register=0;
   have_writen_sign=0;
   read_write_sign=0;
   crc_result=0;
   slow_speed_on();
   slow_speed_off();
 
}


void IO_INIT(void)
{
		 GPIO_InitTypeDef GPIO_InitStructure;
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  
		 GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;                         //forward
		 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
		 GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		 GPIO_Init(GPIOA,&GPIO_InitStructure);
		
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);  
		 GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;                       //reverse
		 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
		 GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		 GPIO_Init(GPIOD,&GPIO_InitStructure);
			
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	       //手轮 PA4
		 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		 GPIO_Init(GPIOA,&GPIO_InitStructure);
			
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	       //Extopen 
		 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		 GPIO_Init(GPIOE,&GPIO_InitStructure);
		 
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	     //Extclose   
		 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		 GPIO_Init(GPIOE,&GPIO_InitStructure);
			
			
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	    //Extstop    
		 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		 GPIO_Init(GPIOE,&GPIO_InitStructure);
		
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);  
		 GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;                 //复位变频器
		 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
		 GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		 GPIO_Init(GPIOD,&GPIO_InitStructure);
			
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	   //phase_check
		 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
		 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		 GPIO_Init(GPIOE,&GPIO_InitStructure);
			
}

void  lcd_test(void)
{
 
	int t=10;
	while(t--)
  {

      GpuSend4("DS48(0,0,'please waiting!!!',0,0);\r\n");
	  delay_ms(50); 
		
  }
      GpuSend4("CLS(15);SEBL(100);\r\n");     //清屏 设置背光
	  delay_ms(10); 
}  
 

 int main(void)
 {	

	SystemInit();
	delay_init();	    	               //延时函数初始化	
	LED_Init();
    TIM1_PWM_Init(36000,0);
	TIM_SetCompare1(TIM1,3500);	
	Timer5_Init();
	Timerx_Init1();
 	Timer6_Init();
	Timer7_Init();
	delay_ms(500); 
	uart4_init(115200);
	lcd_test();
	uart2_init(9600); 
    uart_init(38400);
	uart5_init(9600);
	LED_Init();	
	bluetooth_Init();
	relay_switch_Init();
	IO_INIT();
	      	             //初始化与LED连接的硬件接口
	KEY_Init();
	Adc_Init(); 
    register_initial(); 
	EXTIX_Init();
	timer_ov=1;
	 
	LED_FAULT=0;   
	LED_TORQUE=0; 
	LED_FULL=0; 
	LED_ZERO=0; 
	MCU_POWER=0;
	try6=0;
    GpuSend4("CLS(15);\r\n");     //清屏 设置背光
	delay_ms(15); 
	LED_FULL=0;

	if(bluetooth_sign==0)
    {blue_power_off;}
    else
    {blue_power_on;}

	while(1)
	{
		 (*function_point)();
         delay_short(2);
	}
 }

