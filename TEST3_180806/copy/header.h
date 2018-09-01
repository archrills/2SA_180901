#include "stmflash.h"

   #define SIZE sizeof(TEXT_Buffer)	 			  	//数组长度
   #define FLASH_SAVE_ADDR  0X08030000 
   #define length1 56
   #define length2 112
   #define  eeprom_write_sensitive            0
   #define  eeprom_write_move_direction       1
   #define  eeprom_write_motor_protect        2
   #define  eeprom_write_normal_speed         3
   #define  eeprom_write_emergency_position   4
   #define  eeprom_write_start_point_ad_h     5
   #define  eeprom_write_start_point_ad_l     6
   #define  eeprom_write_end_point_ad_h       7
   #define  eeprom_write_end_point_ad_l       8
   #define  eeprom_write_zero_mA_ad_h         9
   #define  eeprom_write_zero_mA_ad_l         10
   #define  eeprom_write_full_mA_ad_h         11
   #define  eeprom_write_full_mA_ad_l         12
   #define  eeprom_write_language             13
   #define  eeprom_write_pwm_value_zero_h     14
   #define  eeprom_write_pwm_value_zero_l     15
   #define  eeprom_write_pwm_value_full_h     16
   #define  eeprom_write_pwm_value_full_l     17
   #define  eeprom_write_torque               18
   #define  eeprom_write_speed                19
   #define  eeprom_write_speed_fall_position  20
   #define  eeprom_write_torque_compensate    21
   #define  eeprom_write_torque_h             22
   
   #define  eeprom_write_relay1               23
   #define  eeprom_write_relay2               24
   #define  eeprom_write_relay3               25
   #define  eeprom_write_relay4               26
   #define  eeprom_write_relay5               27
   #define  eeprom_write_relay6               28
   #define  eeprom_write_relay7               29
   #define  eeprom_write_relay8               30
   
   #define  eeprom_write_local_remote         31
   #define  eeprom_write_torque_select        32
   
   #define  eeprom_write_switch_mode          33
   #define  eeprom_write_torque_over_times    34
   #define  eeprom_write_local_remote_sign    35
   #define  eeprom_write_speed_rpm_select     36
   #define  eeprom_write_frequency_compensate           37
   #define  eeprom_write_switch_operation_close_mode    38
   #define  eeprom_write_english_only_sign              39
   #define  eeprom_write_fault_fist       40
   #define  eeprom_write_fault_second     41
   #define  eeprom_write_fault_third      42
   #define  eeprom_write_fault_forth      43
   #define  eeprom_write_torque_compensate_h     44
   #define  eeprom_write_torque_percent          45
   #define  eeprom_write_torque_compensate_low      46
   #define  eeprom_write_analog_limit_sign      47
   #define  eeprom_write_reaction_direction     48
   #define  eeprom_write_relay1_state      49
   #define  eeprom_write_relay2_state      50
   #define  eeprom_write_relay3_state      51
   #define  eeprom_write_relay4_state      52
   #define  eeprom_write_relay5_state      53
   #define  eeprom_write_bluetooth      54
   #define  eeprom_write_signal_emergency_position  55
   


   #define  eeprom_write_sensitive_crc_l            0+length1
   #define  eeprom_write_move_direction_crc_l       1+length1
   #define  eeprom_write_motor_protect_crc_l        2+length1
   #define  eeprom_write_normal_speed_crc_l         3+length1
   #define  eeprom_write_emergency_position_crc_l   4+length1
   #define  eeprom_write_start_point_ad_h_crc_l     5+length1
   #define  eeprom_write_start_point_ad_l_crc_l     6+length1
   #define  eeprom_write_end_point_ad_h_crc_l       7+length1
   #define  eeprom_write_end_point_ad_l_crc_l       8+length1
   #define  eeprom_write_zero_mA_ad_h_crc_l         9+length1
   #define  eeprom_write_zero_mA_ad_l_crc_l         10+length1
   #define  eeprom_write_full_mA_ad_h_crc_l         11+length1
   #define  eeprom_write_full_mA_ad_l_crc_l         12+length1
   #define  eeprom_write_language_crc_l             13+length1
   #define  eeprom_write_pwm_value_zero_h_crc_l     14+length1
   #define  eeprom_write_pwm_value_zero_l_crc_l     15+length1
   #define  eeprom_write_pwm_value_full_h_crc_l     16+length1
   #define  eeprom_write_pwm_value_full_l_crc_l     17+length1
   #define  eeprom_write_torque_crc_l               18+length1
   #define  eeprom_write_speed_crc_l                19+length1
   #define  eeprom_write_speed_fall_position_crc_l  20+length1
   #define  eeprom_write_torque_compensatev         21+length1
   #define  eeprom_write_torque_h_crc_l             22+length1
   
   
   #define  eeprom_write_relay1_crc_l               23+length1
   #define  eeprom_write_relay2_crc_l               24+length1
   #define  eeprom_write_relay3_crc_l               25+length1
   #define  eeprom_write_relay4_crc_l               26+length1
   #define  eeprom_write_relay5_crc_l               27+length1
   #define  eeprom_write_relay6_crc_l               28+length1
   #define  eeprom_write_relay7_crc_l               29+length1
   #define  eeprom_write_relay8_crc_l               30+length1
   
   #define  eeprom_write_local_remote_crc_l         31+length1
   #define  eeprom_write_torque_select_crc_l        32+length1
   
   #define  eeprom_write_switch_mode_crc_l          33+length1
   #define  eeprom_write_torque_over_times_crc_l    34+length1
   #define  eeprom_write_local_remote_sign_crc_l    35+length1
   #define  eeprom_write_speed_rpm_select_crc_l     36+length1
   #define  eeprom_write_frequency_compensate_crc_l           37+length1
   #define  eeprom_write_switch_operation_close_mode_crc_l    38+length1
   #define  eeprom_write_english_only_sign_crc_l              39+length1
   #define  eeprom_write_fault_fist_crc_l       40+length1
   #define  eeprom_write_fault_second_crc_l     41+length1
   #define  eeprom_write_fault_third_crc_l      42+length1
   #define  eeprom_write_fault_forth_crc_l      43+length1
   #define  eeprom_write_torque_compensate_h_crc_l     44+length1
   #define  eeprom_write_torque_percent_crc_l          45+length1
   #define  eeprom_write_torque_compensate_low_crc_l      46+length1
   #define  eeprom_write_analog_limit_sign_crc_l      47+length1
   #define  eeprom_write_reaction_direction_crc_l     48+length1
   #define  eeprom_write_relay1_state_crc_l      49+length1
   #define  eeprom_write_relay2_state_crc_l      50+length1
   #define  eeprom_write_relay3_state_crc_l      51+length1
   #define  eeprom_write_relay4_state_crc_l      52+length1
   #define  eeprom_write_relay5_state_crc_l      53+length1

   #define  eeprom_write_sensitive_crc_h            0+length2
   #define  eeprom_write_move_direction_crc_h       1+length2
   #define  eeprom_write_motor_protect_crc_h        2+length2
   #define  eeprom_write_normal_speed_crc_h         3+length2
   #define  eeprom_write_emergency_position_crc_h   4+length2
   #define  eeprom_write_start_point_ad_h_crc_h     5+length2
   #define  eeprom_write_start_point_ad_l_crc_h     6+length2
   #define  eeprom_write_end_point_ad_h_crc_h       7+length2
   #define  eeprom_write_end_point_ad_l_crc_h       8+length2
   #define  eeprom_write_zero_mA_ad_h_crc_h         9+length2
   #define  eeprom_write_zero_mA_ad_l_crc_h         10+length2
   #define  eeprom_write_full_mA_ad_h_crc_h         11+length2
   #define  eeprom_write_full_mA_ad_l_crc_h         12+length2
   #define  eeprom_write_language_crc_h             13+length2
   #define  eeprom_write_pwm_value_zero_h_crc_h     14+length2
   #define  eeprom_write_pwm_value_zero_l_crc_h     15+length2
   #define  eeprom_write_pwm_value_full_h_crc_h     16+length2
   #define  eeprom_write_pwm_value_full_l_crc_h     17+length2
   #define  eeprom_write_torque_crc_h               18+length2
   #define  eeprom_write_speed_crc_h                19+length2
   #define  eeprom_write_speed_fall_position_crc_h  20+length2
   #define  eeprom_write_torque_compensate_crc_h    21+length2
   #define  eeprom_write_torque_h_crc_h             22+length2
   
   
   #define  eeprom_write_relay1_crc_h               23+length2
   #define  eeprom_write_relay2_crc_h               24+length2
   #define  eeprom_write_relay3_crc_h               25+length2
   #define  eeprom_write_relay4_crc_h               26+length2
   #define  eeprom_write_relay5_crc_h               27+length2
   #define  eeprom_write_relay6_crc_h               28+length2
   #define  eeprom_write_relay7_crc_h               29+length2
   #define  eeprom_write_relay8_crc_h               30+length2
   
   #define  eeprom_write_local_remote_crc_h         31+length2
   #define  eeprom_write_torque_select_crc_h        32+length2
   
   #define  eeprom_write_switch_mode_crc_h          33+length2
   #define  eeprom_write_torque_over_times_crc_h    34+length2
   #define  eeprom_write_local_remote_sign_crc_h    35+length2
   #define  eeprom_write_speed_rpm_select_crc_h     36+length2
   #define  eeprom_write_frequency_compensate_crc_h           37+length2
   #define  eeprom_write_switch_operation_close_mode_crc_h    38+length2
   #define  eeprom_write_english_only_sign_crc_h              39+length2
   #define  eeprom_write_fault_fist_crc_h       40+length2
   #define  eeprom_write_fault_second_crc_h     41+length2
   #define  eeprom_write_fault_third_crc_h      42+length2
   #define  eeprom_write_fault_forth_crc_h      43+length2
   #define  eeprom_write_torque_compensate_h_crc_h        44+length2
   #define  eeprom_write_torque_percent_crc_h             45+length2
   #define  eeprom_write_torque_compensate_low_crc_h      46+length2
   #define  eeprom_write_analog_limit_sign_crc_h          47+length2
   #define  eeprom_write_reaction_direction_crc_h         48+length2
   #define  eeprom_write_relay1_state_crc_h      49+length2
   #define  eeprom_write_relay2_state_crc_h      50+length2
   #define  eeprom_write_relay3_state_crc_h      51+length2
   #define  eeprom_write_relay4_state_crc_h      52+length2
   #define  eeprom_write_relay5_state_crc_h      53+length2

   #define  eeprom_write_torque1   56+length2
   #define  eeprom_write_speed1    57+length2
   #define  eeprom_write_volt      58+length2
   #define  eeprom_write_year      59+length2
   #define  eeprom_write_number1   60+length2
   #define  eeprom_write_number2   61+length2
   #define  eeprom_write_decspeed  62+length2
   

   #define  switch_num1        63+length2
   #define  switch_num2        64+length2
   #define  switch_num3        65+length2
   #define  switch_num4        66+length2
   #define  eeprom_backlit     67+length2
	 
 #define  eeprom_write_start_angle_h        68+length2
 #define  eeprom_write_start_angle_l        69+length2
 #define  eeprom_write_end_angle_h          70+length2
 #define  eeprom_write_end_angle_l          71+length2
 #define  eeprom_write_pass_border_sign     72+length2    //为编码器专用
 
 #define  eeprom_write_local_register           185
 
 


#define current_ad_channel    10 
#define	position_channel	  12
#define	temperature_channel	  11 

//#define	menu1_count 12
#define	menu1_count 14

#define	menu0_count 3
#define	watch_count 2
#define	operate_count 5
#define	fault_count 13
//#define	devolop_count 15
#define	devolop_count 16






#define torque_led_on     LED1=1;        
#define torque_led_off    LED1=0;       

#define error_led_on      LED0=1;        
#define error_led_off     LED0=0;      	

#define sigle_double_wrong     
#define sigle_double_correct   

#define key_toggle_short_press 	(key_short_register==1)   
#define key_enter_short_press 	(key_short_register==2)   
#define key_up_short_press     	(key_short_register==3)
#define key_down_short_press    (key_short_register==4)

#define key_toggle_long_press 	(key_longtime_register==1)	   
#define key_enter_long_press 	(key_longtime_register==2)   
#define key_up_long_press     	(key_longtime_register==3)
#define key_down_long_press     (key_longtime_register==4)
#define key_register_reset     {key_short_register=0;key_longtime_register=0;}


/* 外部部按键 */
#define ExtKEY_DISABLE 	(PEin(2)==1)&&(PEin(3)==1) 	 
#define ExtKEY_OPEN		PEin(2)==0	 	
#define ExtKEY_CLOSE	PEin(3)==0	 	
#define ExtKEY_STOP		PEin(4)==0	 	
	



#define hand_wheel_enable     PAin(4)==1 
#define hand_wheel_disable    PAin(4)==0

//
//#define phase_lack_enable     PAin(1)==1 
//#define phase_lack_disable    PAin(1)==0 

#define phase_lack_enable     PEin(1)==1 
#define phase_lack_disable    PEin(1)==0 


#define blue_power_on  		       PDout(0)=0
#define blue_power_off  		   PDout(0)=1;

//#define switch_mode_detect (0)

    

//#define   back_light_on   	  PAout(15)=0;
//#define   back_light_off  	  PAout(15)=1;

#define   go_forward_simple   	  PAout(5)=1
#define   go_reverse_simple  	    PDout(11)=1

#define   stop_forward_simple     PAout(5)=0     //41
#define   stop_reverse_simple  	  PDout(11)=0    //80
       

#define uart_write_enable  
#define uart_read_enable   

   
// 5pe5 6(126)	PG11       7PC13   8PC14     132PG15     9PC15   10PF0   11PF1
 
 
//4   5    7 8 9



 #define relay5_on       PCout(15)=1
 #define relay5_off   	 PCout(15)=0
 
 #define relay4_on   	   PCout(14)=1
 #define relay4_off   	 PCout(14)=0
 
 #define relay3_on    	 PCout(13)=1
 #define relay3_off  	   PCout(13)=0
 
 #define relay2_on   	   PEout(6)=1
 #define relay2_off      PEout(6)=0
   
 #define relay1_on    	 PEout(5)=1
 #define relay1_off   	 PEout(5)=0
 

 
 #define relay6_on    	 PFout(0)=1
 #define relay6_off  	   PFout(0)=0
 
 #define relay7_on   	   PFout(1)=1
 #define relay7_off      PFout(1)=0
   
 #define relay8_on    	 PFout(2)=1
 #define relay8_off   	 PFout(2)=0
 
 
 
 
 
 
 #define NULL 0
  
 
//extern void sendBYTE(unsigned char dat);
//extern void sendCMD(unsigned char dat);
//extern void sendDAT(unsigned char dat);
//extern void display_chinese_letter(unsigned char x_add,unsigned char *p);
//extern void initlcm(void);


//unsigned char write_register_array[8]={0x01,0x06,0x0A,0x06,0x00,0x01,0x4B,0xD2};




extern void IO_Init(void);
extern void delay_short(unsigned int a);
extern void delay_long(unsigned int count);


extern   void remote_process(void);
extern   void local_process(void);



extern   void go_up_action_d(void);
extern   void go_down_action_u(void);
extern   void go_down_action_d(void);
extern   void go_up_action_u(void);

	 

extern   void percent_count_display(void);
//extern   void display_percent( unsigned char x_add,unsigned char hun,unsigned char ten,unsigned char bit1);
//extern   void display_percent_count_every_bit(unsigned char x_add,unsigned int data);
//extern   void display_percent_point(unsigned char x_add,unsigned char bit1,unsigned char point);
//extern   void display_percent_small(unsigned char x_add,unsigned char hun,unsigned char ten,unsigned char bit1,unsigned char small);

extern   void display_number_3(unsigned char x_add,unsigned char num0,unsigned char num1,unsigned char num2);
//extern   void display_chinese_letter(unsigned char x_add,unsigned char *p);
extern   void display_address(unsigned char x_add);
extern  void display_every_bit_current(unsigned char x_add,unsigned int data);
extern void parameter_first(void);
extern void Usart3Close(void);
extern void Usart3Open(void);
extern void sensitive_set(void);
extern void move_direction_set(void);
extern void signal_off_set(void);
extern void motor_temperature_protect_set(void);
extern void start_point_set(void);
extern void end_point_set(void);

extern void sps_up_action(void);
extern void sps_down_action(void);
extern void eps_up_action(void);
extern void eps_down_action(void);

extern void torque_compensate_low_adjust(void);
extern void normal_speed_set(void);
extern void torque_set(void);
extern void general_fault_relay_on (void);
extern void general_fault_relay_off (void);
extern void write_modbus_data(unsigned char address_hundred,unsigned char address_ten_bit,unsigned char value_ten,unsigned char value_bit);
extern unsigned int read_modbus_data(unsigned char address_hundred,unsigned char address_ten_bit);
extern void register_initial(void);

extern void percent_set_count(void);
extern void percent_set_count1(void);
extern void key_scan_process(void);
extern void key_scan_process1(void);
extern void key_toggle_long_process(void);
extern void key_toggle_long_process1(void);
extern void  timer0_int_start(void);
extern void  timer2_int_start(void);
extern void  timer0_reset(void);
extern void  timer2_reset(void);
extern void timer3_reset(void);
extern void pwm_initial(void);
extern void PWM(unsigned int i);
extern void pwm_excute(void);

//extern void display_four_bit(unsigned char x_add,unsigned int data);
extern unsigned int AD_convert(unsigned char channel);
extern void percent_now_count(void);
extern void percent_set_count(void);
extern void display_two_bit(unsigned char x_add,unsigned char data);
extern void zero_current_set(void);
extern void full_current_set(void);

extern void zero_feedback_adjust(void);
extern void full_feedback_adjust(void);
extern void language_set(void);
extern void go_up_on(void);
extern void go_down_on(void);												 
extern void stop(void);
extern void parameter_reset(void);
extern void go_up_derection_detect(void);
extern void relay_process(void);
extern void start_point_set_display(void);
extern void end_point_set_display(void);
extern void speed_torque_feedback_pwm_initial(void);
extern void  timer3_int_start(void);//16位定时器
extern void product_id_set(void);



 
 extern void remote_ready_relay_on(void);
 extern void remote_ready_relay_off(void);
 extern void local_ready_relay_on(void);
 extern void local_ready_relay_off(void);
 extern void zero_pozition_relay_on (void);
 extern void zero_pozition_relay_off (void);
 extern void full_pozition_relay_on (void);
 extern void full_pozition_relay_off (void);
 extern void forward_torque_relay_on (void);
 extern void forward_torque_relay_off (void);
 extern void reverse_torque_relay_on (void);
 extern void reverse_torque_relay_off (void);
 extern void temperature_relay_on (void);
 extern void temperature_relay_off (void);
 extern void phase_lack_relay_on (void);
 extern void phase_lack_relay_off (void);
 extern void uart0_initial(void);
 extern void torque_set(void);
 extern void slow_speed_on(void);
 extern void normal_speed_set(void);
 extern unsigned int CRC_16(unsigned char *ptr,unsigned char length);
 extern void display_every_bit(unsigned char x_add,unsigned int data);
 extern unsigned int crc_modbus(unsigned char *data, unsigned char length);
 extern void instpect_error(void);
 extern void display_alarm(void);
 extern void alarm_process(void);
 extern void uart1_initial(void);
 extern void inspect_error_1(void);
 extern void inspect_error(void);
 extern void read_motor_current(void);
 extern void check_motor_current(void);
 extern void move_state_judge(void);
 extern void speed_fall_position_set(void);
 extern void switch_mode_process(void);
 extern void switch_mode_enable(void);
 extern void analog_mode_enable(void);
 extern void reset_alarm(void);
 extern void display_number(unsigned char x_add,unsigned char num1,unsigned char num2);
 extern void torque_compensate_adjust(void);
 extern void motor_temperature_protect(void);
 extern void  relay1_define(void);
 extern void  relay2_define(void);
 extern void  relay3_define(void);
 extern void  relay4_define(void);
 extern void  relay5_define(void);
 extern void  relay6_define(void);
 extern void  relay7_define(void);
 extern void  relay8_define(void);
 
 
 
//extern void relay_define_display(void);
extern void torque_select_process(void);
 
extern void torque_over_relay_process(void);
extern void switch_mode_select(void);
  


extern void switch_pulse_process(void);
extern void switch_realtime_process(void);
extern void ExtKEY_CLOSE_process(void);
extern void ExtKEY_OPEN_process(void);

extern void ExtKEY_CLOSE_time_process(void);
extern void ExtKEY_OPEN_time_process(void);

extern void torque_over_times_display(void);
extern void simens_add_speed_choice(void);
extern void self_study_process(void);
extern void parameter_modify(void);
extern void write_parameter(unsigned char *p);
extern void read_parameter(unsigned char *p);
extern void initlcm_reverse(void);
extern void display_number_4(unsigned char x_add,unsigned char num0,unsigned char num1,unsigned char num2,unsigned char num3);
extern void phase_lack_check_pulse(void);
extern void switch_close_mode_select(void);
extern void chinese_prohibit(void);
extern void  local_long_press_key_up(void);
extern void  local_long_press_key_down(void);
extern void display_number_3_new(unsigned char x_add,unsigned char num0,unsigned char num1,unsigned char num2);
extern void parameter_read(void);
extern void fault_read(void);
extern void display_three_bit(unsigned char x_add,unsigned int data);
extern void reaction_direction_set(void);
extern void voltage_fault_relay_off(void);
extern void voltage_fault_relay_on(void);
extern void go_switch_Init(void);
extern void phase_check_Init(void);
extern  void slow_speed_off(void);
extern  void drive_parameter_modify(void);
extern void blue_Init(void);
extern void uart3_init(u32 bound);
extern void relay_set(void);
extern void display_address_new(unsigned char x_add);
extern void key_toggle_short_process(void);
extern void	 read_bus_voltage(void);
extern void	 read_frequency_set(void);
extern void	 read_pm_temperature(void);
extern void	 read_operate_time(void);
extern void	 read_software_code(void);
extern void	 read_fault_current(void);
extern void	 read_fault_voltage(void);
extern void	 read_fault_frequency(void);
extern void	 read_fault_set_frequency(void);
extern void	 read_fault_bus_voltage(void);
extern void	 read_fault_pm_temperature(void);

extern void	 read_first_fault(void);
extern void  read_second_fault(void);
extern void  read_Third_fault(void);
extern void  read_Fourth_fault(void);
extern void  read_Fifth_fault(void);
extern void  read_Sixth_fault(void);
extern void	 all_run_time(void);
extern void blue_power_set(void);
extern void backlit_set(void);
extern void	soft_version(void);
extern void	hand_version(void);
extern void switch_num(void);

extern void relay1_open_close_set(void);
extern void relay2_open_close_set(void);
extern void relay3_open_close_set(void);
extern void relay4_open_close_set(void);
extern void relay5_open_close_set(void);
extern void display_two_bit_1(unsigned char x_add,unsigned char data);
extern void emergency_set(void);
extern void display_every_bit_2_point(unsigned char x_add,unsigned int data);
extern void display_every_bit_1_point(unsigned char x_add,unsigned int data);
extern void read_modbus_data_fast(unsigned char address_hundred,unsigned char address_ten_bit);
extern void communicate(void);
extern void write_modbus_data1(unsigned char address_hundred,unsigned char address_ten_bit,unsigned char value_ten,unsigned char value_bit);
extern void speed_process_modbus(void);
extern void dec_speed_set(void);
extern void delay_ms(u16 nms);
extern void delay_us(u32 nms);
extern void encoder_act(void);






