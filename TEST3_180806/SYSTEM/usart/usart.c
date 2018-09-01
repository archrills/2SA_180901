#include "sys.h"
#include "usart.h"	 
#include "delay.h"
#include "header.h"
#include "timer.h"
#include "stmflash.h"
#include "led.h"


#define	fault_first_record  0
#define	fault_second_record 7
#define	fault_third_record  8
#define	fault_out_freq      1
#define	fault_set_freq	    2
#define	fault_out_current   3
#define	fault_out_voltage   4
#define	fault_bus_voltage   5
#define	fault_module_temperature  6

#define	operate_current              9
#define	operate_voltage             10
#define	operate_freq                11
#define	operate_hour                12
#define	operate_module_temperature  13
#define	operate_motor_speed         14
#define	operate_inverter_code       15
#define	operate_bus_voltage         16
#define	operate_set_freq            17
#define	check_error                 18
#define	send_speed                  19

#define	fault_first_record_position  	   8
#define	fault_second_record_position 	   9
#define	fault_third_record_position  	   10
#define	fault_out_freq_position  		   4
#define	fault_set_freq_position			   5
#define	fault_out_current_position   	   1
#define	fault_out_voltage_position   	   2
#define	fault_bus_voltage_position   	   3
#define	fault_module_temperature_position  6
#define	fault_torque_over_position  	   7


#define	operate_current_position  				 1
#define	operate_voltage_position 				 2
#define	operate_freq_position   				 4
#define	operate_set_freq_position 				 5
#define	operate_hour_position       			 6
#define	operate_module_temperature_position   	 8
#define	operate_motor_speed_position    		 9
#define	operate_inverter_code_position   		 10
#define	operate_bus_voltage_position    		 3

#define	operate_start_angle_position    		 11
#define	operate_end_angle_position   		     12

unsigned char uart1_order=0;
unsigned char write_register_array[8]={0x01,0x06,0x0A,0x06,0x00,0x01,0x4B,0xD2};
unsigned char timer_ov;
extern unsigned int current_data,AD_register;
extern unsigned char first_uart;
unsigned char uart1_receive_array[8]={0,0,0,0,0,0,0,0,};
extern unsigned char uart2_receive_array[6];
extern signed long int turns,all_angle,angle;
extern unsigned char first_uart_start;
extern unsigned int turns_act,angle_act;
extern signed int turns_provious;
extern signed char pass_border_sign;

extern unsigned char encoder_error_sign;
extern signed char pass_border_sign_previous;


extern unsigned char read_write_sign;
extern unsigned char crc_result;
unsigned char detect_list=9;
extern unsigned int	operate_current_data;
extern unsigned int	operate_voltage_data;
static unsigned int	operate_freq_data;
extern unsigned int	operate_set_freq_data;
extern unsigned int	operate_hour_data;
extern unsigned int	operate_module_temperature_data;
extern unsigned int	operate_motor_speed_data;
extern unsigned int	operate_inverter_code_data;
extern unsigned int	operate_bus_voltage_data ;
extern unsigned char send_catalogue;						 
extern unsigned int	fault_first_record_data;
extern unsigned int	fault_second_record_data;
extern unsigned int	fault_third_record_data;
extern unsigned int	fault_out_freq_data ;
extern unsigned int	fault_set_freq_data ;
extern unsigned int	fault_out_current_data;
extern unsigned int	fault_out_voltage_data;
extern unsigned int	fault_bus_voltage_data	;
extern unsigned int	fault_module_temperature_data;
extern unsigned char fault_check[35];
extern unsigned char parameter_check[];
extern unsigned char mode_check[20];
extern unsigned char operating_check[20];
extern unsigned char first_fault_record;	
extern int zero_mA_ad_h_register,full_mA_ad_h_register;
extern int full_mA_ad,all_mA_ad;
extern unsigned int ad_now_input;
extern int zero_mA_ad;
extern unsigned char request_order;
extern unsigned char speed_select;
//extern unsigned char request_queue[39];

extern unsigned int try1,try2,try3,try4;
extern unsigned char TEXT_Buffer[262];

extern unsigned char uart5_receive_array[40];
extern unsigned char uart5_order;
extern unsigned char uart5_count_array[36];
	
	
extern unsigned char   sensitive_register,move_direction_register,emergency_position_register,move_direction_register_temporary,move_direction_register_temporary1,
                       motor_protect_register,normal_speed_register,language_register,speed_register;
extern unsigned char   operate_mode,mode_flag;	
extern unsigned int   speed_fall_position_register,speed_fall_position_register_count;
extern unsigned char  reaction_direction; 
extern unsigned char motor_protect_sign;
extern unsigned char relay1_meaning,relay2_meaning,relay3_meaning,relay4_meaning,relay5_meaning,
                     relay6_meaning,relay7_meaning,relay8_meaning;
	
extern int percent_now,percent_set;
extern unsigned char mode_toggle,flag_test,stop_flag,stop_flag1;	
extern unsigned char  go_up_direction;	

extern unsigned char key_allowed;	
extern unsigned char switch_operation_close_mode;	
extern unsigned char signal_emergency_position_register;	
extern unsigned char ProductId[20];
extern unsigned char parameter_set[36];
extern unsigned int signal_out_value;

extern signed char app_volt,app_speed,app_year,app_torque,app_number1,app_number2;	
//extern unsigned char Bluetooth_AT,Bluetooth_NAME;
extern unsigned char temp1,temp2;
extern unsigned int crc_modbus3(unsigned char *data, unsigned char length); 	
extern unsigned char uart1_count_array[15];
extern unsigned char uart5_bit0;	
unsigned char array_test[36];
unsigned char detect_register;
unsigned  char  receive_complete=1;
unsigned char receive_array[7];
unsigned int receive_arrange=0;
unsigned char receive_number=0;
unsigned char fail_times=0;
extern  unsigned char write_first;
unsigned char display_queue=0;
extern unsigned char display_classification;
unsigned char send_queue=0;
unsigned char reset_times=0; 

const unsigned char request_queue[43]=                     
{
		 operate_current,
		 operate_voltage,
		 operate_current,
		 operate_freq,
		 operate_current,
		 operate_hour,
	     operate_current,
		 operate_module_temperature,
	     operate_freq,
		 operate_current,
		 operate_motor_speed,
		 operate_current,
	     operate_freq,
		// send_speed,
		 operate_current,
		 operate_inverter_code,
		 operate_current,
		 
	     operate_freq,
	     operate_current,
		 fault_second_record,
		 operate_current,
		 fault_third_record,
		 operate_current,
		 operate_bus_voltage,
		 operate_freq,
		 fault_out_freq,
		 operate_current,
		 //send_speed,
		 fault_set_freq,
		 operate_current,
		 operate_freq,
		 operate_set_freq,
		 operate_current,
		 fault_out_current,
		 operate_current,
		 operate_freq,
		 fault_out_voltage,
		 operate_current,
		 fault_bus_voltage,
		 operate_current,
		 operate_freq,
		 fault_module_temperature,
		 operate_current,
		 check_error,
		 operate_current,
		// send_speed,
};



void array_recount1(unsigned char p)
{
     signed char order_fact,i;
	    
	   	   	  for(i=0;i<=7;i++)
			  {
		      	order_fact=p+i;
					  if(order_fact>6)
						{
							order_fact=order_fact-7;
                        }
					  receive_array[i]=uart1_receive_array[order_fact];
			  }
	   
}


void array_recount(unsigned char count)	 // 队列整理
{
	  signed char order_fact,i,a;
	   a=count;
	   if(a==36)
	   {
	   	  
	   	   	  for(i=0;i<=35;i++)
			  {
		      		   order_fact=uart5_order-(35-i);
					   if(order_fact<0)
					   {
					   order_fact=40+order_fact;
					   }
					  uart5_count_array[i]=uart5_receive_array[order_fact];
			  }
	   }
	   
	  else if(a==20)
	   {
		  for(i=0;i<=19;i++)
			  {
		      		   order_fact=uart5_order-(19-i);
					   if(order_fact<0)
					   {
					      order_fact=40+order_fact;
					   }
					  uart5_count_array[i]=uart5_receive_array[order_fact];
			  }
	   }
}


unsigned int crc_modbus1(unsigned char *data, unsigned char length) 	
{
        int j;
        unsigned int reg_crc=0xffff;
        while(length--)
		{
            reg_crc^=*data++;
            for(j=0;j<8;j++)
    		{
                if(reg_crc&0x01)
        		 {
                 reg_crc=(reg_crc>>1)^0xa001;
                 }
        		else
        		 {
                 reg_crc=reg_crc>>1;
                 }
            }
       }
        return reg_crc;
}




void uart_init(u32 bound){
    //GPIO端口设置
    GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);
     //USART1_TX   PA.9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
   
    //USART1_RX	  PA.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);  

    //Usart1 NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;		   //
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			   //IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	                       //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器USART1
  
    //USART 初始化设置
    USART_InitStructure.USART_BaudRate = bound;//一般设置为9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
    USART_ITConfig(USART1, USART_IT_RXNE,ENABLE);//开启中断
    USART_Cmd(USART1,ENABLE);                    //使能串口 

}

void uart2_init(u32 bound){
    //GPIO端口设置
    GPIO_InitTypeDef GPIO_InitStructure;
	  USART_InitTypeDef USART_InitStructure;
	  NVIC_InitTypeDef NVIC_InitStructure;
	 
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE); //注意犯过错误
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
     //USART1_TX   PA.2
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
   
    //USART1_RX	  PA.3
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);  

    //Usart1 NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;   //错误！
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority =2;		   //
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			   //IRQ通道使能
	  NVIC_Init(&NVIC_InitStructure);	                       //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器USART1
  
    //USART 初始化设置
    USART_InitStructure.USART_BaudRate = bound;//一般设置为9600;
	  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	  USART_InitStructure.USART_StopBits = USART_StopBits_1;
	  USART_InitStructure.USART_Parity = USART_Parity_No;
	  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	  USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
		
    USART_Init(USART2, &USART_InitStructure);
    USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);//开启中断
    USART_Cmd(USART2,ENABLE);                    //使能串口 

}

void  uart4_init(u32 bound)
{
          
     GPIO_InitTypeDef GPIO_InitStructure;
     USART_InitTypeDef USART_InitStructure;
     NVIC_InitTypeDef NVIC_InitStructure;
  
     RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);  
     RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
     RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);
 
     GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
     GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
     GPIO_Init(GPIOC,&GPIO_InitStructure);

     GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;
     GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
     GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
     GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	   //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  //   NVIC_InitStructure.NVIC_IRQChannel=UART4_IRQn;
     NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;
     NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
     NVIC_InitStructure.NVIC_IRQChannelCmd=DISABLE;
     NVIC_Init(&NVIC_InitStructure);

	   USART_InitStructure.USART_BaudRate=bound;
     USART_InitStructure.USART_WordLength=USART_WordLength_8b;
     USART_InitStructure.USART_StopBits=USART_StopBits_1;
     USART_InitStructure.USART_Parity=USART_Parity_No;
     USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
     USART_InitStructure.USART_Mode=USART_Mode_Tx;
        
     USART_Init(UART4,&USART_InitStructure);
     USART_ITConfig(UART4,USART_IT_RXNE,ENABLE);
		 USART_Cmd(UART4,ENABLE);
     USART_ClearFlag(UART4,USART_FLAG_TC);
	
}


void uart5_init(u32 bound)
{
					GPIO_InitTypeDef GPIO_InitStructure;
					USART_InitTypeDef USART_InitStructure;
					NVIC_InitTypeDef NVIC_InitStructure;        

					RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE );
					RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE );

					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //UART5 TX;
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
					GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
					GPIO_Init(GPIOC, &GPIO_InitStructure); 
							
					GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //UART5 RX;
					GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	                //GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPD;
	                GPIO_Init(GPIOD, &GPIO_InitStructure); 

					USART_InitStructure.USART_BaudRate = bound; 
					USART_InitStructure.USART_WordLength = USART_WordLength_8b; 
					USART_InitStructure.USART_StopBits = USART_StopBits_1; 
					USART_InitStructure.USART_Parity = USART_Parity_No ;
					USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
					USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
					USART_Init(UART5, &USART_InitStructure);

					//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
                    NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn; 
					NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
					NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5; 
					NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
					NVIC_Init(&NVIC_InitStructure);

					USART_Init(UART5,&USART_InitStructure);
                    USART_ITConfig(UART5,USART_IT_RXNE,ENABLE);
		            USART_Cmd(UART5,ENABLE);
                    USART_ClearFlag(UART5,USART_FLAG_TC);
}




void USART1_IRQHandler(void)                	//串口1中断服务程序
{
     unsigned char detect_list_instead;
     unsigned int  y,a,b,z,instead;
	   float power;
		// u8 Res;

	 receive_number=receive_number+1;
	/*
	 if(receive_arrange>1)
	 {
    uart1_order=0;
   }
	*/
						if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  
						{
						uart1_receive_array[uart1_order] =USART_ReceiveData(USART1);
						}
	
						
	 
		 
                 if((uart1_receive_array[0]==1)&&(uart1_receive_array[1]==3)&&(uart1_order==6))
				   {
			        	  
						  
						    
							y=crc_modbus1(uart1_receive_array,5);
			        		a=uart1_receive_array[5];
			        		b=uart1_receive_array[6];
			        		 if(y==(256*b+a))
			        		 {
									 
			        		      z=uart1_receive_array[3];
							     instead=z*256+uart1_receive_array[4];
							     current_data=instead;
			        		     crc_result=1;
									// LED_TORQUE =0;
									 receive_complete=1;
									 receive_arrange=0; 
										 //receive_success=1;
										 
										//detect_list_instead=request_queue[request_order];
										 switch(detect_list)
								     {

								         case operate_current:operate_current_data=instead;break;
										 case operate_voltage:operate_voltage_data=instead;break;
										 case operate_freq:operate_freq_data=instead;break;
										 case operate_hour:operate_hour_data=instead;break;
										 case operate_module_temperature:operate_module_temperature_data=instead;break;
										 case operate_motor_speed:operate_motor_speed_data=instead;break;
										 case operate_inverter_code:operate_inverter_code_data=instead;break;
										 case operate_bus_voltage:operate_bus_voltage_data=instead; break;
										 case operate_set_freq:operate_set_freq_data=instead;break;
										 case check_error:first_fault_record=instead;fault_first_record_data=instead;break;
										 case fault_first_record:fault_first_record_data=instead;break;
										 case fault_second_record:fault_second_record_data=instead;break;
										 case fault_third_record:fault_third_record_data=instead;break;
										 case fault_out_freq:fault_out_freq_data=instead;break;
										 case fault_set_freq:fault_set_freq_data=instead;break;
										 case fault_out_current:fault_out_current_data=instead;break;
										 case fault_out_voltage:fault_out_voltage_data=instead;break;
										 case fault_bus_voltage:fault_bus_voltage_data=instead;break;
										 case fault_module_temperature:fault_module_temperature_data=instead;break;
										
									 }         
										
									  if((detect_list==operate_current)&&(current_data!=0))
										 {
                                         //  while(1);
                                         }
									 
									 
										
										fault_check[1]=fault_out_current_data/256;
									    fault_check[2]=fault_out_current_data%256;
									 
										fault_check[3]=fault_out_voltage_data/256;
									    fault_check[4]=fault_out_voltage_data%256;
										
										fault_check[5]=fault_bus_voltage_data/256;
									    fault_check[6]=fault_bus_voltage_data%256; 
									 
									    fault_check[7]=fault_out_freq_data/256;
									    fault_check[8]=fault_out_freq_data%256;
									 
										fault_check[9]=fault_set_freq_data/256;
									    fault_check[10]=fault_set_freq_data%256;
									 
									    fault_check[11]=fault_module_temperature_data/256;
									    fault_check[12]=fault_module_temperature_data%256;
									 
										fault_check[17]= fault_first_record_data/256;
									    fault_check[18]= fault_first_record_data%256;
									 
									    fault_check[19]=fault_second_record_data/256;
									    fault_check[20]=fault_second_record_data%256;
									 
										fault_check[21]=fault_third_record_data/256;
									    fault_check[22]=fault_third_record_data%256;
									 
									 
							/*		 	 
							   if(send_queue==0)
							   {
								    	parameter_check[operate_current_position*2-1]=operate_current_data/256;
								    	parameter_check[operate_voltage_position*2-1]=operate_voltage_data/256;
								    	parameter_check[operate_freq_position*2-1]=operate_freq_data/256;
								    	
								    	mode_check[5]=operate_freq_data/256;
								    	parameter_check[operate_hour_position*2-1]=operate_hour_data/256;
								    	parameter_check[operate_module_temperature_position*2-1]=operate_module_temperature_data/256;
								     	parameter_check[operate_motor_speed_position*2-1]=operate_motor_speed_data/256;
								     	parameter_check[operate_inverter_code_position*2-1]=operate_inverter_code_data/256;
								    	parameter_check[operate_bus_voltage_position*2-1]=operate_bus_voltage_data/256;
										  parameter_check[operate_set_freq_position*2-1]=operate_set_freq_data/256;
									    

										

									
                                        parameter_check[operate_current_position*2]=operate_current_data%256;
								        parameter_check[operate_voltage_position*2]=operate_voltage_data%256;
								        parameter_check[operate_freq_position*2]=operate_freq_data%256;
								    
								         mode_check[6]=operate_freq_data%256;
									    parameter_check[operate_hour_position*2]=operate_hour_data%256; 
										  parameter_check[operate_module_temperature_position*2]=operate_module_temperature_data%256;
									    parameter_check[operate_motor_speed_position*2]=operate_motor_speed_data%256;
									    parameter_check[operate_inverter_code_position*2]=operate_inverter_code_data%256;
									    parameter_check[operate_bus_voltage_position*2]=operate_bus_voltage_data%256;
											parameter_check[operate_set_freq_position*2]=operate_set_freq_data%256;
                    
								 }


								if(ad_now_input<=full_mA_ad)
										{power=((160*ad_now_input-zero_mA_ad)/all_mA_ad);}
										else
										{power=((160*(ad_now_input-zero_mA_ad))/all_mA_ad)+40;}

										if((power<0)||(power>1000))
										{power=0;}
										parameter_check[7*2]=	(int)power%256;
										parameter_check[7*2-1]=	(int)power/256;




							*/	
								
										

							   /*
			        		 else
			        		 {
			        		 crc_result=0;
							  
			        		 }
								*/	 
									 
					     }
						  
				     
				   
				   }
					 
					 if((uart1_receive_array[0]==1)&&(uart1_receive_array[1]==6)&&(uart1_order==7))
					 {
					 
						      y=crc_modbus1(uart1_receive_array,6);
			        		 a=uart1_receive_array[6];
			        		 b=uart1_receive_array[7];
			        		 if(y==(256*b+a))
			        		 {
			        		   receive_complete=1;
							   crc_result=1;
							    receive_arrange=0;
							 }
			        		/*
										else
			        		 {
			        		 crc_result=0;
			        		 }
									*/	
					 }
					 
					       								 
					 
				    uart1_order=uart1_order+1; 
	               if(uart1_order>7)
				   {
				   uart1_order=0;  
				   }
					 
          	
         // LED_TORQUE =1;				 
}





void USART2_IRQHandler(void)       
{
    unsigned int middle;
	  u8 Res; 
    unsigned int a,b,c,d;

	   if(USART_GetITStatus(USART2,USART_IT_RXNE) != RESET)  
		{
		Res =USART_ReceiveData(USART2);
		}
    
		uart2_receive_array[first_uart]=Res;
    //first_uart++; 
	  
	  if(first_uart==4)
	  {
	          a=uart2_receive_array[1];
						b=uart2_receive_array[2];
						c=uart2_receive_array[3];
						d=a+b+c;
						if(d>=512)
						{
						 d=d-512;
						}
						else if(d>=256)
						{
							 d=d-256;
						}
						else
						{
							
						};

			if(d==uart2_receive_array[4])
		  {
		     
			  
				if((uart2_receive_array[3]&0x03)!=0)
			  {
			  encoder_error_sign=1;
			  }
			  else
			  {
			  encoder_error_sign=0;
			  }
			  
			  middle=uart2_receive_array[1];
			  turns=middle<<4;
			  middle=uart2_receive_array[2]>>4;
			  turns=middle+turns;          //得到圈数
			  turns_act=turns;
			  
			  if(first_uart_start==0)
			  {
			   turns_provious=turns;
			   first_uart_start=1;
			  }
			  
			  
			  if(turns>turns_provious)
			  {
			     if((turns-turns_provious)>2000)
				 {
				 pass_border_sign=pass_border_sign-1;
				 }
				 
			  }
			  else
			  {
			     if((turns_provious-turns)>2000)
				 {
				 pass_border_sign=pass_border_sign+1;
				 }
				 
			  }
			  
			  if(pass_border_sign_previous!=pass_border_sign)
			  {
			 //eeprom_write_pass_border_sign(pass_border_sign);
			                                
			  }
			  
			  
			  pass_border_sign_previous=pass_border_sign;
			  turns_provious=turns;
			 
			 
			        if(pass_border_sign==1)
						  {
						  turns=turns+4096;
						  }
						  if(pass_border_sign==(-1))
						  {
						  turns=turns-4096;
						  }
			 
			 
			  middle=uart2_receive_array[2]&0x0f;
			  angle=middle<<6;
			  middle=uart2_receive_array[3]>>2;
			  angle=angle+middle;             //得到角度
			  
			  all_angle=turns*1024+angle;    //得到总角度
			  fail_times=0;
			  first_uart=0;
						
		  }
		  else
		  {
		  first_uart=first_uart+1;
				
		  }
	  }
	  else
	  {
      first_uart=first_uart+1;
			
	  }
	  
	  if(first_uart>5)
	  {
	  first_uart=5;
		
	  }
}





void UART5_IRQHandler(void)                	

{
   	 
    unsigned int  i,y,a,b,jjwz;
		//unsigned char sent_array[25];
		//signed char order_fact,num;
		//unsigned char array_test[36];
    u8 Res;
		
	   if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)  
		{
		Res =USART_ReceiveData(UART5);
		}
       uart5_receive_array[uart5_order]=Res;		 //次序

	   if(uart5_receive_array[uart5_order]==0x3c)
	   {
	   	   		 
		array_recount(36);
	    for(i=0;i<36;i++)
		{
		
		    array_test[i]=uart5_count_array[i];
		    uart5_bit0=uart5_count_array[0];
		
		};
		
		y=crc_modbus3(array_test,33);
	    a=array_test[33];
	    b=array_test[34];
		
		
						                                                                                                                                                                                                                                                                                                             
		                     if(y==(256*b+a))
			        		 {
			        		 	   crc_result=1;

							 		   if(array_test[0]==0xf1)
									 {

										if(mode_flag==0)  //仅在现场模式下可以改参数
										{

									      STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
                                          move_direction_register_temporary=TEXT_Buffer[eeprom_write_reaction_direction];	//读取正反作用参数

											language_register=(unsigned int)array_test[1]*256+array_test[2];
										  if(language_register==1)
										  {language_register=255;}	   // 语言设置有问题暂时屏蔽 16/01/10
										    
									     //   torque_register= (unsigned int)array_test[3]*256+array_test[4];
											//speed_register= (unsigned int)array_test[5]*256+array_test[6];
										    
                                            sensitive_register= (unsigned int)array_test[7]*256+array_test[8];           
                                            speed_fall_position_register= (unsigned int)array_test[9]*256+array_test[10];
                                                         jjwz=(unsigned int)array_test[11]*256+array_test[12];  
											reaction_direction=(unsigned int)array_test[13]*256+array_test[14]; //读取APP正反作用参数
											motor_protect_sign=(unsigned int)(array_test[15]*256+array_test[16]);
											relay1_meaning=(unsigned int)(array_test[17]*256+array_test[18]);
											relay2_meaning=(unsigned int)(array_test[19]*256+array_test[20]);
										    relay3_meaning=(unsigned int)(array_test[21]*256+array_test[22]);
										    relay4_meaning=(unsigned int)(array_test[23]*256+array_test[24]);
											relay5_meaning=(unsigned int)(array_test[25]*256+array_test[26]);
 											switch_operation_close_mode=(unsigned int)array_test[27]*256+array_test[28];
											
											//if((sensitive_register!=0)&&(speed_fall_position_register!=0)&&(array_test[33]!=0x78)&&(array_test[34]!=0x26))
											 if((sensitive_register!=0)&&(speed_fall_position_register!=0))
											
				            {
													TEXT_Buffer[eeprom_write_language]=(language_register);
													TEXT_Buffer[eeprom_write_torque_h]=(torque_register)/256;
													TEXT_Buffer[eeprom_write_torque]=(torque_register)%256;

													TEXT_Buffer[eeprom_write_speed]=(speed_register);
													TEXT_Buffer[eeprom_write_sensitive]=(sensitive_register);
													TEXT_Buffer[eeprom_write_speed_fall_position]=(speed_fall_position_register);
												  
											    TEXT_Buffer[eeprom_write_reaction_direction]=(move_direction_register_temporary1);
													TEXT_Buffer[eeprom_write_motor_protect]=(motor_protect_sign);
													TEXT_Buffer[eeprom_write_relay1]=(relay1_meaning);
													TEXT_Buffer[eeprom_write_relay2]=(relay2_meaning);
													TEXT_Buffer[eeprom_write_relay3]=(relay3_meaning);
													TEXT_Buffer[eeprom_write_relay4]=(relay4_meaning);
													TEXT_Buffer[eeprom_write_relay5]=(relay5_meaning);
													TEXT_Buffer[eeprom_write_switch_operation_close_mode]=(switch_operation_close_mode);

										 
										
											   if(jjwz==101)
											  {
											   emergency_position_register=1;
											   TEXT_Buffer[eeprom_write_emergency_position]=(1);
          
											  }

											  else

											  {
											   emergency_position_register=0;
											   TEXT_Buffer[eeprom_write_signal_emergency_position]=(jjwz); //紧急位置
                                               TEXT_Buffer[eeprom_write_emergency_position]=(0);

											  }
											
										 
												
												
												 if((reaction_direction)!=(move_direction_register_temporary))
												  {

													 if(go_up_direction==100)
													{
														go_up_direction=0;
					 
													}
												 else
													{
														go_up_direction=100;
					
													 }
				
													 // reaction_direction=(~reaction_direction);
													  reaction_direction=reaction_direction&0x01;
													  TEXT_Buffer[eeprom_write_reaction_direction]=(reaction_direction);
													  TEXT_Buffer[eeprom_write_move_direction]=(go_up_direction);
													    
														
                         }
												 	
												 STMFLASH_Write(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
											}

										}//条件在发送之前执行	
										send_catalogue=5;					  
															  
									 }
									 else if(array_test[0]==0xf2)
									 {
									  send_catalogue=8;
									 }


									 else if(array_test[0]==0xf3)
									 {
									  send_catalogue=9;
                    }
								
									 //display_every_bit(0x80,array_test[0]);
									 //delay_ms(1000);
							  }
			        		 else
			        		 {
			        		 crc_result=0;
							
			        		 }
		   				 
							



					array_recount(20);

					for(i=0;i<20;i++)
	              	{
		
		                array_test[i]=uart5_count_array[i];
		            }
							 y=crc_modbus3(array_test,17);
			        		 a=array_test[17];
			        	 	 b=array_test[18];				                                                                                                                                                                                                                                                                                                             
					       
						     if(y==(256*b+a))
							 {
							        if(array_test[0]==0x01)
									 {
									   send_catalogue=7;
							 		 }
									 else if(array_test[0]==0x11)
									 {
									   
									   //stop_flag1=1;
										 stop();
										 
									   send_catalogue=7;
										 
									   mode_toggle+=1;
										 if(mode_toggle>1)
										 {
										   	mode_toggle=0;
										 }
										 
										 
										  /*
										   operate_mode+=1;
										   if(operate_mode>1)
										   {
										   	  operate_mode=0;
										   }
                      */
									

									 }
									 else if(array_test[0]==0x10)
									 {
									   
									   send_catalogue=6;
									  
									 }
									 else if(array_test[0]==0x03)
									 {
									    send_catalogue=7;
									   	 key_allowed=1;
									      if(mode_toggle==0)
										  {

										   flag_test=1;
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
										  {flag_test=0;}
									 }
									 else if(array_test[0]==0x02)
									 {
									 	send_catalogue=7;
										key_allowed=1;
										 if(mode_toggle==0)
										 {

										 flag_test=1;
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
										  {flag_test=0;}	   
									 }

									
									
									 else if(array_test[0]==0x00)
									 {
									
										stop_flag=1;
										send_catalogue=7;
										if(mode_toggle==0)
										{
										stop();
										}
									 }
									
							 }
			        		 else
			        		 {
			        		 crc_result=0;		    
							 }
						  

	   }

	               uart5_order=uart5_order+1; 
	               if(uart5_order>39)
				   {
				   uart5_order=0;  
				   }
			
} 


void GpuSend4(char *buf2)
{  u8 i=0;
 
	while (1)
   {  
		 if (buf2[i]!=0)
     {  
			 USART_SendData(UART4,buf2[i]);  
       
			// while( USART_GetITStatus(UART4, USART_IT_RXNE) == RESET){};
		     while(USART_GetFlagStatus(UART4,USART_FLAG_TXE) ==RESET){};
			   i++;
			   delay_us(100);
     }
     else return;
   }
	 
}



void GpuSend5(char *buf2)
{  
 
	/*   
		 if (buf2[display_queue]!=0)
     {  
			 
         if(timer5_count==1)
		 {  
			            
			               
				   if(USART_GetFlagStatus(UART4,USART_FLAG_TXE) !=RESET)
				   {
		              USART_SendData(UART4,buf2[display_queue]); 
					  display_queue++; 
					 // Timer5_Init();
					 // timer5_count=0;
					  
					       
					  						 
		           }
		 }	     
     }
     else
	 {
       display_queue=0;
	   display_classification=display_classification+1;
	   if(display_classification>3)
	   {
	   	display_classification=0;
		delay_ms(1);
	
	   }
	   	
     }
	  */
}



unsigned int crc_modbus(unsigned char *data, unsigned char length) 	
{
        int j;
        unsigned int reg_crc=0xffff;
        while(length--)
		{
            reg_crc^=*data++;
            for(j=0;j<8;j++)
    		{
                if(reg_crc&0x01)
        		 {/*LSB(b0)=1*/
                 reg_crc=(reg_crc>>1)^0xa001;
                 }
        		else
        		 {
                 reg_crc=reg_crc>>1;
                 }
            }
       }
        return reg_crc;
}


unsigned int read_modbus_data(unsigned char address_hundred,unsigned char address_ten_bit)
{
   

	unsigned int y;
	unsigned char i;

	 	//delay_ms(20);

    write_register_array[0]=1;
    write_register_array[1]=3;
    write_register_array[2]=address_hundred;
	write_register_array[3]=address_ten_bit; 
    write_register_array[4]=0;
	write_register_array[5]=1;
    y=crc_modbus(write_register_array,6);
	write_register_array[6]=y%256;
	write_register_array[7]=y/256;
	
	    if(timer_ov==1)
		 {
		   for(i=0;i<=7;i++)
           {
              while((USART1->SR&0X40)==0);
			  USART1->DR=write_register_array[i];
		      delay_us(50);
		   }
		 }
		uart1_order=0;
	delay_ms(20);
	return(current_data);
 
}


void write_modbus_data1(unsigned char address_hundred,unsigned char address_ten_bit,unsigned char value_ten,unsigned char value_bit)
{
    unsigned int y;
	  unsigned char i;

    write_register_array[0]=1;
    write_register_array[1]=6;
    write_register_array[2]=address_hundred;
	  write_register_array[3]=address_ten_bit;
	  write_register_array[4]=value_ten;
	  write_register_array[5]=value_bit;
	
    y=crc_modbus(write_register_array,6);
	  write_register_array[6]=y%256;
	  write_register_array[7]=y/256;

		
				    if(!((address_hundred==3)&&((address_ten_bit==9)||(address_ten_bit==10))))
					  {
					   for(i=0;i<=7;i++)
			           {
			              while((USART1->SR&0X40)==0);
						  USART1->DR=write_register_array[i];
					   }
				    }
	          receive_complete=0;
						uart1_order=0;
	// delay_ms(10);
}			




void read_modbus_data_fast(unsigned char address_hundred,unsigned char address_ten_bit)
{
    unsigned int y;
	  unsigned char i;
    //unsigned char flag;
    write_register_array[0]=1;
    write_register_array[1]=3;
    write_register_array[2]=address_hundred;
	  write_register_array[3]=address_ten_bit;   
    write_register_array[4]=0;
	  write_register_array[5]=1;
    y=crc_modbus(write_register_array,6);
	  write_register_array[6]=y%256;
	  write_register_array[7]=y/256;
	  
	 
   	{
		   for(i=0;i<=7;i++)
           {
              while((USART1->SR&0X40)==0);
			  USART1->DR=write_register_array[i];
		       }
			read_write_sign=0;
					 
		 }
		
		 receive_complete=0;
     uart1_order=0;
		 // delay_ms(15);
		 
		 
		 
		 //收发的同步问题
	   //return(current_data);
}





void communicate(void)                     //[k?'mju:n?ke?t]  通信
{
	
  unsigned char buf5[20];
	   float power;
	unsigned int i,y; 
     signed char flag;
//	   unsigned int number;
	   unsigned int middle1;
              
	 
				   
	                                if(receive_complete==1)
					            	{
												if(send_catalogue==9)    
										 {
													
											    fault_check[0]=0xf3;
                                                fault_check[35]=0x3c;
												y=crc_modbus(fault_check,33);
												fault_check[33]=y%256;															  
												fault_check[34]=y/256;

													
																if((UART5->SR&0X40)!=0)
														{	
																UART5->DR=fault_check[send_queue];
																send_queue=send_queue+1;
																if(send_queue>35)
																{
																  send_queue=0;
																}
														}
													//	 delay_ms(15);
										 
										 }
											else if(send_catalogue==8)
											{
												
												
												  if(send_queue==0)
											   {
												    
													
														parameter_check[0]=0xf2;
														parameter_check[operate_start_angle_position*2-1]=turns/256;
														parameter_check[operate_start_angle_position*2]=turns%256;
														parameter_check[operate_end_angle_position*2-1]=turns/256;
														parameter_check[operate_end_angle_position*2]=turns%256;
													
													
														parameter_check[operate_current_position*2-1]=operate_current_data/256;
												    	parameter_check[operate_voltage_position*2-1]=operate_voltage_data/256;
												    	parameter_check[operate_freq_position*2-1]=operate_freq_data/256;
												    	
												    	mode_check[5]=operate_freq_data/256;
												    	parameter_check[operate_hour_position*2-1]=operate_hour_data/256;
												    	parameter_check[operate_module_temperature_position*2-1]=operate_module_temperature_data/256;
												     	parameter_check[operate_motor_speed_position*2-1]=operate_motor_speed_data/256;
												     	parameter_check[operate_inverter_code_position*2-1]=operate_inverter_code_data/256;
												    	parameter_check[operate_bus_voltage_position*2-1]=operate_bus_voltage_data/256;
														parameter_check[operate_set_freq_position*2-1]=operate_set_freq_data/256;
													    
				
														if(ad_now_input<=full_mA_ad)
														{power=((160*ad_now_input-zero_mA_ad)/all_mA_ad);}
														else
														{power=((160*(ad_now_input-zero_mA_ad))/all_mA_ad)+40;}
				
														if((power<0)||(power>1000))
														{power=0;}
														parameter_check[7*2]=	(int)power%256;
														parameter_check[7*2-1]=	(int)power/256;
				
													
				                                        parameter_check[operate_current_position*2]=operate_current_data%256;
												        parameter_check[operate_voltage_position*2]=operate_voltage_data%256;
												        parameter_check[operate_freq_position*2]=operate_freq_data%256;
												    
												        mode_check[6]=operate_freq_data%256;
													    parameter_check[operate_hour_position*2]=operate_hour_data%256; 
														parameter_check[operate_module_temperature_position*2]=operate_module_temperature_data%256;
													    parameter_check[operate_motor_speed_position*2]=operate_motor_speed_data%256;
													    parameter_check[operate_inverter_code_position*2]=operate_inverter_code_data%256;
													    parameter_check[operate_bus_voltage_position*2]=operate_bus_voltage_data%256;
													    parameter_check[operate_set_freq_position*2]=operate_set_freq_data%256;
				                    
											            y=crc_modbus(parameter_check,33);
														parameter_check[33]=y%256;
														parameter_check[34]=y/256;
														parameter_check[35]=0x3c;
											
												 }
												
												
													 if((UART5->SR&0X40)!=0)
														{	
																UART5->DR=parameter_check[send_queue];
																send_queue=send_queue+1;
																if(send_queue>35)
																{
																   send_queue=0;
																}
														}


													
										 }

											else if(send_catalogue==6)
											{

												STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
												app_torque=TEXT_Buffer[eeprom_write_torque1];
												app_speed =TEXT_Buffer[eeprom_write_speed1];
												app_volt=TEXT_Buffer[eeprom_write_volt];
												app_year=TEXT_Buffer[eeprom_write_year];
												app_number1=TEXT_Buffer[eeprom_write_number1];
												app_number2=TEXT_Buffer[eeprom_write_number2];
											
												ProductId[0]=0x10;
												ProductId[1]=app_torque/256;
												ProductId[2]=app_torque%256;
												ProductId[3]=app_speed/256;
												ProductId[4]=app_speed%256;
												ProductId[5]=app_volt/256;
												ProductId[6]=app_volt%256;
												ProductId[7]=app_year/256;
												ProductId[8]=app_year%256;
												ProductId[9]=app_number1/256;
												ProductId[10]=app_number1%256;
												ProductId[11]=app_number2/256;
												ProductId[12]=app_number2%256;
												 
												y=crc_modbus(ProductId,17);
												ProductId[17]=y%256;
												ProductId[18]=y/256;
												ProductId[19]=0x3c;


												for(i=0;i<20;i++)
												{
												   while((UART5->SR&0X40)==0);
												   UART5->DR=ProductId[i];
												}
											
										 }

											 else if(send_catalogue==5)
											{
												STMFLASH_Read(FLASH_SAVE_ADDR,(u16*)TEXT_Buffer,SIZE);
                                                middle1=TEXT_Buffer[eeprom_write_torque_h];
												language_register=TEXT_Buffer[eeprom_write_language];
												torque_register= middle1*256 + TEXT_Buffer[eeprom_write_torque];
															speed_register= TEXT_Buffer[eeprom_write_speed];
												sensitive_register=TEXT_Buffer[eeprom_write_sensitive];
												speed_fall_position_register= TEXT_Buffer[eeprom_write_speed_fall_position];
												 
												//go_up_direction= TEXT_Buffer[eeprom_write_move_direction];
												move_direction_register_temporary=TEXT_Buffer[eeprom_write_reaction_direction];	       
												motor_protect_sign=TEXT_Buffer[eeprom_write_motor_protect];
												relay1_meaning=TEXT_Buffer[eeprom_write_relay1];
												relay2_meaning=TEXT_Buffer[eeprom_write_relay2];
												relay3_meaning=TEXT_Buffer[eeprom_write_relay3];
												relay4_meaning=TEXT_Buffer[eeprom_write_relay4];
												relay5_meaning=TEXT_Buffer[eeprom_write_relay5];
												switch_operation_close_mode=TEXT_Buffer[eeprom_write_switch_operation_close_mode];
												signal_emergency_position_register=TEXT_Buffer[eeprom_write_signal_emergency_position]; // 紧急位置
												emergency_position_register=TEXT_Buffer[eeprom_write_emergency_position];    //	保位
												
                                                if(emergency_position_register==1)
											   {
												  flag=101;
											   }

											 else

											 {
												 flag=signal_emergency_position_register;
											 }

												
												parameter_set[0]=0xf1;
												parameter_set[35]=0x3c;
												y=crc_modbus(parameter_set,33);
												parameter_set[33]=y%256;
												parameter_set[34]=y/256;


												parameter_set[1]=language_register/256;
												parameter_set[2]=language_register%256;
												parameter_set[3]=torque_register/256;
												parameter_set[4]=torque_register%256; 
												parameter_set[5]=speed_register/256;
												parameter_set[6]=speed_register%256;
												parameter_set[7]=sensitive_register/256;
												parameter_set[8]=sensitive_register%256;
												parameter_set[9]= speed_fall_position_register/256;
												parameter_set[10]=speed_fall_position_register%256;
												parameter_set[11]=flag/256;
												parameter_set[12]=flag%256;
												parameter_set[13]=move_direction_register_temporary/256;
												parameter_set[14]=move_direction_register_temporary%256;
												parameter_set[15]=motor_protect_sign/256;
												parameter_set[16]=motor_protect_sign%256;
												parameter_set[17]=relay1_meaning/256;
												parameter_set[18]=relay1_meaning%256;
												parameter_set[19]=relay2_meaning/256;
												parameter_set[20]=relay2_meaning%256; 
												parameter_set[21]=relay3_meaning/256;
												parameter_set[22]=relay3_meaning%256;
												parameter_set[23]=relay4_meaning/256;
												parameter_set[24]=relay4_meaning%256; 
												parameter_set[25]=relay5_meaning/256;
												parameter_set[26]=relay5_meaning%256;
												parameter_set[27]=switch_operation_close_mode/256;
												parameter_set[28]=switch_operation_close_mode%256;
												//parameter_set[29]=operate_mode_a%256;
												//parameter_set[30]=operate_mode_a/256;
												parameter_set[29]=0/256;
												parameter_set[30]=0%256;  

													for(i=0;i<=35;i++)
														 {
																while((UART5->SR&0X40)==0);
																UART5->DR=parameter_set[i];
													     }
												
										 }

											else if(send_catalogue==7)
											{
											
													   if(send_queue==0)
													   {
																if(uart5_receive_array[0]==0x02)
																{
																 operating_check[0]=0x02;
																}
																else if(uart5_receive_array[0]==0x03)
																{
																operating_check[0]=0x03;
																}
																else if(uart5_receive_array[0]==0x01)
																{
																operating_check[0]=0x01;
																}
															 
				
																else if(uart5_receive_array[0]==0x00)
																{
																operating_check[0]=0x00;
																}  
																else if(uart5_receive_array[0]==0x11)
																{
																operating_check[0]=0x11;
																}
																
																operating_check[0]=uart5_count_array[0];
																
																if(percent_now<0)  //显示大于0
																{percent_now=0;}
				
																operating_check[1]=percent_now/256;
																operating_check[2]=percent_now%256;
																operating_check[3]=operate_current_data/256;
																operating_check[4]=operate_current_data%256;
																operating_check[5]=operate_freq_data/256;
																operating_check[6]=operate_freq_data%256;
																operating_check[7]=0;
																if((ad_now_input>=zero_mA_ad-100)&&(ad_now_input<=full_mA_ad+100))
																{operating_check[8]=1;}
				
																else
																{operating_check[8]=0;}
																 
																signal_out_value=40+((long int)percent_now*160)/1000;
				
																operating_check[9]=signal_out_value/256;
																operating_check[10]=signal_out_value%256;
																operating_check[11]=0x00;
																operating_check[12]=mode_toggle;
															    
																operating_check[19]=0x3c;
																y=crc_modbus(operating_check,17);
																operating_check[17]=y%256;
																operating_check[18]=y/256;
														  }
											
													   

												      if((UART5->SR&0X40)!=0)
														{	
																UART5->DR=operating_check[send_queue];
																send_queue=send_queue+1;
																if(send_queue>19)
																{
																  send_queue=0;
																}
														}
                                                 }
										
								}
	
	
	          receive_arrange=receive_arrange+1; 
			 if(receive_arrange>2000)
			 {
                receive_arrange=0;
				receive_complete=1;
				reset_times++;
              }
		                  
						  
						                    if( write_first==0)
											 {
															if(receive_complete==1)
															{					
																	request_order+=1;
															
																	 if(request_order>42)
																		{
																			request_order=0;
																		}
																		detect_list=request_queue[request_order];
																		 
																	      switch(detect_list)
																		 {
																		
																		 case operate_current:detect_register=operate_current;read_modbus_data_fast(33,4);break;
																		 case operate_voltage:detect_register=operate_voltage;read_modbus_data_fast(33,6);break;
																		 case operate_freq:detect_register=operate_freq;read_modbus_data_fast(33,3);break;
																		 case operate_hour:detect_register=operate_hour;read_modbus_data_fast(3,40);break;
																		 case operate_module_temperature:read_modbus_data_fast(33,8);detect_register=operate_module_temperature;break;
																		 case operate_motor_speed:read_modbus_data_fast(33,7);detect_register=operate_motor_speed;break;      //运行速度
																		 case operate_inverter_code:read_modbus_data_fast(12,2);detect_register=operate_inverter_code;break;
																		 case operate_bus_voltage:detect_register=operate_bus_voltage;read_modbus_data_fast(33,5);break;
																		 case operate_set_freq:read_modbus_data_fast(33,2);detect_register=operate_set_freq;break;
																		 case check_error:read_modbus_data_fast(6,0);detect_register=check_error;break;
																		// case send_speed:speed_process_modbus();break;
																		// case send_speed:break;
																		 case fault_second_record:read_modbus_data_fast(6,7);detect_register=fault_second_record;break;
																		 case fault_third_record:read_modbus_data_fast(6,8);detect_register=fault_third_record;break;
																		 case fault_out_freq:read_modbus_data_fast(6,1);detect_register=fault_out_freq;break;
																		 case fault_set_freq:read_modbus_data_fast(6,2);detect_register=fault_set_freq;break;
																		 case fault_out_current:read_modbus_data_fast(6,3);detect_register=fault_out_current;break;
																		 case fault_out_voltage:read_modbus_data_fast(6,4);detect_register=fault_out_voltage;break;
																		 case fault_bus_voltage:read_modbus_data_fast(6,5);detect_register=fault_bus_voltage;break;
																		 case fault_module_temperature:read_modbus_data_fast(6,6);detect_register=fault_module_temperature;break;
																		 default:detect_register=detect_list;break;
																	 }         
														
																		
															}	
	
														}

}
 

void write_modbus_data(unsigned char address_hundred,unsigned char address_ten_bit,unsigned char value_ten,unsigned char value_bit)
{
    unsigned int y;
	unsigned char i;

    write_register_array[0]=1;
    write_register_array[1]=6;
    write_register_array[2]=address_hundred;
	write_register_array[3]=address_ten_bit;
	write_register_array[4]=value_ten;
	write_register_array[5]=value_bit;
    y=crc_modbus(write_register_array,6);
	write_register_array[6]=y%256;
	write_register_array[7]=y/256;
		 
		 {
				if(!((address_hundred==3)&&((address_ten_bit==9)||(address_ten_bit==10))))
					{
					   for(i=0;i<=7;i++)
			           {
			              while((USART1->SR&0X40)==0);
						        USART1->DR=write_register_array[i];
					   }
				    }
	     }
	 delay_long(2);
}


 unsigned int crc_modbus3(unsigned char *data, unsigned char length) 	
{
        int j;
        unsigned int reg_crc=0xffff;
        while(length--)
		{
            reg_crc^=*data++;
            for(j=0;j<8;j++)
    		{
                if(reg_crc&0x01)
        		 {
                 reg_crc=(reg_crc>>1)^0xa001;
                 }
        		else
        		 {
                 reg_crc=reg_crc>>1;
                 }
            }
       }
        return reg_crc;
}


void Usart5Close(void)
{																																								   
  // USART_InitTypeDef USART_InitStructure;
	USART_Cmd(UART5, DISABLE); //使能串口 
  
} 

void Usart5Open(void)
{
   //USART_InitTypeDef USART_InitStructure;
  USART_Cmd(UART5, ENABLE); //使能串口 
}




