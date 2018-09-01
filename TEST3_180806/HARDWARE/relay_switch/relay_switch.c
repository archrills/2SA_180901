#include "stm32f10x.h"
#include "led.h"
#include "header.h"
#include "variable.h"


extern unsigned char relay1_meaning,relay2_meaning,relay3_meaning,relay4_meaning,relay5_meaning,
                     relay6_meaning,relay7_meaning,relay8_meaning;
extern unsigned char relay1_state,relay2_state,relay3_state,relay4_state,relay5_state; 
extern unsigned char fault_register;
extern unsigned char move_direction;
extern unsigned char run_direction;


void relay_switch_Init(void)                                
{
                                               //PE5,PE6,PC13,PC14,PC15    1,2,3,4,5              PF0,PF1,PF2      PG15
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);      
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;	    	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);	
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 		
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;				 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;	    	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOF, &GPIO_InitStructure);	
 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);	 
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_15;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
 						  

}
 
 void torque_over_relay_process(void)
 {
      if(move_direction==0)
	  {
	      forward_torque_relay_on();
        reverse_torque_relay_off();
	  }
      else
	  {
	     forward_torque_relay_off();
       reverse_torque_relay_on();
	  }
 }
 
 
 
 void zero_pozition_relay_on (void)
 {
  if(run_direction==1)
	{
       LED_FULL=1;
	   LED_ZERO=1;

  }	
	 
	 else
	 { 
	   LED_FULL=1;
	   LED_ZERO=0;
	 }
	 
    if(relay1_meaning==0)
	{
	 if(relay1_state==0)
	 relay1_on;
	 else
	 relay1_off;
	}
	if(relay2_meaning==0)
	{
	 if(relay2_state==0)
	 relay2_on;
	 else
	 relay2_off;
	 
	}
	if(relay3_meaning==0)
	{
	 if(relay3_state==0)
	 relay3_on;
	 else
	 relay3_off;
	}
	if(relay4_meaning==0)
	{
	 if(relay4_state==0)
	 relay4_on;
	 else
	 relay4_off;
	}
	if(relay5_meaning==0)
    {
	 if(relay5_state==0)
	 relay5_on;
	 else
	 relay5_off;
	}
	
 }
 
 
 
 void zero_pozition_relay_off (void)
 {
   
	 //LED_FULL=1;
	 if(run_direction!=2)
	 {
	 LED_ZERO=1;
	 }
   if(relay1_meaning==0)
	{
	 if(relay1_state==0)
	 relay1_off;
	 else
	 relay1_on;
	}
	if(relay2_meaning==0)
	{
	 if(relay2_state==0)
	 relay2_off;
	 else
	 relay2_on;
	}
	if(relay3_meaning==0)
	{
	 if(relay3_state==0)
	 relay3_off;
	 else
	 relay3_on;
	}
	if(relay4_meaning==0)
	{
	 if(relay4_state==0)
	 relay4_off;
	 else
	 relay4_on;
	}
	if(relay5_meaning==0)
    {
	 if(relay5_state==0)
	 relay5_off;
	 else
	 relay5_on;
	}
  
 }
 
 void full_pozition_relay_on (void)
 {
	 
	 
	 if(run_direction==2)
	{
     LED_FULL=1;
	   LED_ZERO=1;

  }	
	 
	 else
	 { 
	 LED_FULL=0;
	 LED_ZERO=1;
	 }
	 
	 
	 
   if(relay1_meaning==1)
	{
	 if(relay1_state==0)
	 relay1_on;
	 else
	 relay1_off;
	}
	if(relay2_meaning==1)
	{
	 if(relay2_state==0)
	 relay2_on;
	 else
	 relay2_off;
	 
	}
	if(relay3_meaning==1)
	{
	 if(relay3_state==0)
	 relay3_on;
	 else
	 relay3_off;
	}
	if(relay4_meaning==1)
	{
	 if(relay4_state==0)
	 relay4_on;
	 else
	 relay4_off;
	}
	if(relay5_meaning==1)
    {
	 if(relay5_state==0)
	 relay5_on;
	 else
	 relay5_off;
	}
	
	
 }
 
 
 void full_pozition_relay_off (void)
 {
	 
	 if(run_direction!=1)
	 {
	 LED_FULL=1;
	 }
	
	 
	 //LED_ZERO=0;
	 
    if(relay1_meaning==1)
	{
	 if(relay1_state==0)
	 relay1_off;
	 else
	 relay1_on;
	}
	if(relay2_meaning==1)
	{
	 if(relay2_state==0)
	 relay2_off;
	 else
	 relay2_on;
	}
	if(relay3_meaning==1)
	{
	 if(relay3_state==0)
	 relay3_off;
	 else
	 relay3_on;
	}
	if(relay4_meaning==1)
	{
	 if(relay4_state==0)
	 relay4_off;
	 else
	 relay4_on;
	}
	if(relay5_meaning==1)
    {
	 if(relay5_state==0)
	 relay5_off;
	 else
	 relay5_on;
	}
   
 }
 
 
 void remote_ready_relay_on(void)
 {
    
 if(fault_register==0)
 {	
	
	LED_TORQUE=0;  // Ô¶¿Ø  
    LED_FAULT=1;
 }
 else
 {
 
    LED_FAULT=1;
 }	 
	 
	 if(relay1_meaning==2)
	{
	 if(relay1_state==0)
	 relay1_on;
	 else
	 relay1_off;
	}
	if(relay2_meaning==2)
	{
	 if(relay2_state==0)
	 relay2_on;
	 else
	 relay2_off;
	 
	}
	if(relay3_meaning==2)
	{
	 if(relay3_state==0)
	 relay3_on;
	 else
	 relay3_off;
	}
	if(relay4_meaning==2)
	{
	 if(relay4_state==0)
	 relay4_on;
	 else
	 relay4_off;
	}
	if(relay5_meaning==2)
    {
	 if(relay5_state==0)
	 relay5_on;
	 else
	 relay5_off;
	}
	
 }
 
 void remote_ready_relay_off(void)
 {


   if(fault_register==0)
   {
	 LED_TORQUE=1;  // Ô¶¿Ø  
   }
   
   //LED_FAULT=1;
	 
	 
    if(relay1_meaning==2)
	{
	 if(relay1_state==0)
	 relay1_off;
	 else
	 relay1_on;
	}
	if(relay2_meaning==2)
	{
	 if(relay2_state==0)
	 relay2_off;
	 else
	 relay2_on;
	}
	if(relay3_meaning==2)
	{
	 if(relay3_state==0)
	 relay3_off;
	 else
	 relay3_on;
	}
	if(relay4_meaning==2)
	{
	 if(relay4_state==0)
	 relay4_off;
	 else
	 relay4_on;
	}
	if(relay5_meaning==2)
    {
	 if(relay5_state==0)
	 relay5_off;
	 else
	 relay5_on;
	}
	
 }
 
 
 void local_ready_relay_on(void)
 {
	  
	  if(fault_register==0)
	  {
	   LED_TORQUE=1;  // Ô¶¿Ø  
      } 
	   
	   LED_FAULT=0;
	 
	 
    if(relay1_meaning==3)
	{
	 if(relay1_state==0)
	 relay1_on;
	 else
	 relay1_off;
	}
	if(relay2_meaning==3)
	{
	 if(relay2_state==0)
	 relay2_on;
	 else
	 relay2_off;
	 
	}
	if(relay3_meaning==3)
	{
	 if(relay3_state==0)
	 relay3_on;
	 else
	 relay3_off;
	}
	if(relay4_meaning==3)
	{
	 if(relay4_state==0)
	 relay4_on;
	 else
	 relay4_off;
	}
	if(relay5_meaning==3)
    {
	 if(relay5_state==0)
	 relay5_on;
	 else
	 relay5_off;
	}
 }
 
 void local_ready_relay_off(void)
 {
	  //LED_TORQUE=1;  // Ô¶¿Ø  
    LED_FAULT=1;
	 
    if(relay1_meaning==3)
	{
	 if(relay1_state==0)
	 relay1_off;
	 else
	 relay1_on;
	}
	if(relay2_meaning==3)
	{
	 if(relay2_state==0)
	 relay2_off;
	 else
	 relay2_on;
	}
	if(relay3_meaning==3)
	{
	 if(relay3_state==0)
	 relay3_off;
	 else
	 relay3_on;
	}
	if(relay4_meaning==3)
	{
	 if(relay4_state==0)
	 relay4_off;
	 else
	 relay4_on;
	}
	if(relay5_meaning==3)
    {
	 if(relay5_state==0)
	 relay5_off;
	 else
	 relay5_on;
	}
 }
 
 
 
 
 
 void temperature_relay_on (void)
 {
    if(relay1_meaning==4)
	{
	 if(relay1_state==0)
	 relay1_on;
	 else
	 relay1_off;
	}
	if(relay2_meaning==4)
	{
	 if(relay2_state==0)
	 relay2_on;
	 else
	 relay2_off;
	 
	}
	if(relay3_meaning==4)
	{
	 if(relay3_state==0)
	 relay3_on;
	 else
	 relay3_off;
	}
	if(relay4_meaning==4)
	{
	 if(relay4_state==0)
	 relay4_on;
	 else
	 relay4_off;
	}
	if(relay5_meaning==4)
    {
	 if(relay5_state==0)
	 relay5_on;
	 else
	 relay5_off;
	}
   fault_register=fault_register|0x01;
   general_fault_relay_on();
 }
 
 
 
 
 void temperature_relay_off (void)
 {
 
    if(relay1_meaning==4)
	{
	 if(relay1_state==0)
	 relay1_off;
	 else
	 relay1_on;
	}
	if(relay2_meaning==4)
	{
	 if(relay2_state==0)
	 relay2_off;
	 else
	 relay2_on;
	}
	if(relay3_meaning==4)
	{
	 if(relay3_state==0)
	 relay3_off;
	 else
	 relay3_on;
	}
	if(relay4_meaning==4)
	{
	 if(relay4_state==0)
	 relay4_off;
	 else
	 relay4_on;
	}
	if(relay5_meaning==4)
    {
	 if(relay5_state==0)
	 relay5_off;
	 else
	 relay5_on;
	}
	
	fault_register=fault_register&0xfe;
 }
 
 
 void voltage_fault_relay_on (void)
 {
    if(relay1_meaning==5)
	{
	 if(relay1_state==0)
	 relay1_on;
	 else
	 relay1_off;
	}
	if(relay2_meaning==5)
	{
	 if(relay2_state==0)
	 relay2_on;
	 else
	 relay2_off;
	 
	}
	if(relay3_meaning==5)
	{
	 if(relay3_state==0)
	 relay3_on;
	 else
	 relay3_off;
	}
	if(relay4_meaning==5)
	{
	 if(relay4_state==0)
	 relay4_on;
	 else
	 relay4_off;
	}
	if(relay5_meaning==5)
    {
	 if(relay5_state==0)
	 relay5_on;
	 else
	 relay5_off;
	}
	fault_register=fault_register|0x02;
	general_fault_relay_on();
 }
 
 
 void voltage_fault_relay_off (void)
 {
    if(relay1_meaning==5)
	{
	 if(relay1_state==0)
	 relay1_off;
	 else
	 relay1_on;
	}
	if(relay2_meaning==5)
	{
	 if(relay2_state==0)
	 relay2_off;
	 else
	 relay2_on;
	}
	if(relay3_meaning==5)
	{
	 if(relay3_state==0)
	 relay3_off;
	 else
	 relay3_on;
	}
	if(relay4_meaning==5)
	{
	 if(relay4_state==0)
	 relay4_off;
	 else
	 relay4_on;
	}
	if(relay5_meaning==5)
    {
	 if(relay5_state==0)
	 relay5_off;
	 else
	 relay5_on;
	}
    fault_register=fault_register&0xfd;
  
 }
 
 
 void forward_torque_relay_on (void)
 {
    if(relay1_meaning==6)
	{
	 if(relay1_state==0)
	 relay1_on;
	 else
	 relay1_off;
	}
	if(relay2_meaning==6)
	{
	 if(relay2_state==0)
	 relay2_on;
	 else
	 relay2_off;
	 
	}
	if(relay3_meaning==6)
	{
	 if(relay3_state==0)
	 relay3_on;
	 else
	 relay3_off;
	}
	if(relay4_meaning==6)
	{
	 if(relay4_state==0)
	 relay4_on;
	 else
	 relay4_off;
	}
	if(relay5_meaning==6)
    {
	 if(relay5_state==0)
	 relay5_on;
	 else
	 relay5_off;
	}
    fault_register=fault_register|0x04;
	general_fault_relay_on();
 }
 
 void forward_torque_relay_off (void)
 {
 
    if(relay1_meaning==6)
	{
	 if(relay1_state==0)
	 relay1_off;
	 else
	 relay1_on;
	}
	if(relay2_meaning==6)
	{
	 if(relay2_state==0)
	 relay2_off;
	 else
	 relay2_on;
	}
	if(relay3_meaning==6)
	{
	 if(relay3_state==0)
	 relay3_off;
	 else
	 relay3_on;
	}
	if(relay4_meaning==6)
	{
	 if(relay4_state==0)
	 relay4_off;
	 else
	 relay4_on;
	}
	if(relay5_meaning==6)
    {
	 if(relay5_state==0)
	 relay5_off;
	 else
	 relay5_on;
	}
	fault_register=fault_register&0xfb;
 }
 
 
 void reverse_torque_relay_on (void)
 {
    if(relay1_meaning==7)
	{
	 if(relay1_state==0)
	 relay1_on;
	 else
	 relay1_off;
	}
	if(relay2_meaning==7)
	{
	 if(relay2_state==0)
	 relay2_on;
	 else
	 relay2_off;
	 
	}
	if(relay3_meaning==7)
	{
	 if(relay3_state==0)
	 relay3_on;
	 else
	 relay3_off;
	}
	if(relay4_meaning==7)
	{
	 if(relay4_state==0)
	 relay4_on;
	 else
	 relay4_off;
	}
	if(relay5_meaning==7)
    {
	 if(relay5_state==0)
	 relay5_on;
	 else
	 relay5_off;
	}
	
	fault_register=fault_register|0x08;
	general_fault_relay_on();
 }
 
 
 void reverse_torque_relay_off (void)
 {
    if(relay1_meaning==7)
	{
	 if(relay1_state==0)
	 relay1_off;
	 else
	 relay1_on;
	}
	if(relay2_meaning==7)
	{
	 if(relay2_state==0)
	 relay2_off;
	 else
	 relay2_on;
	}
	if(relay3_meaning==7)
	{
	 if(relay3_state==0)
	 relay3_off;
	 else
	 relay3_on;
	}
	if(relay4_meaning==7)
	{
	 if(relay4_state==0)
	 relay4_off;
	 else
	 relay4_on;
	}
	if(relay5_meaning==7)
    {
	 if(relay5_state==0)
	 relay5_off;
	 else
	 relay5_on;
	}
    fault_register=fault_register&0xf7;
 }
 
 
 void general_fault_relay_on (void)
 {
    if(relay1_meaning==8)
	{
	 if(relay1_state==0)
	 relay1_on;
	 else
	 relay1_off;
	}
	if(relay2_meaning==8)
	{
	 if(relay2_state==0)
	 relay2_on;
	 else
	 relay2_off;
	 
	}
	if(relay3_meaning==8)
	{
	 if(relay3_state==0)
	 relay3_on;
	 else
	 relay3_off;
	}
	if(relay4_meaning==8)
	{
	 if(relay4_state==0)
	 relay4_on;
	 else
	 relay4_off;
	}
	if(relay5_meaning==8)
    {
	 if(relay5_state==0)
	 relay5_on;
	 else
	 relay5_off;
	}
	
 }
 
 
 void general_fault_relay_off (void)
 {
    if(relay1_meaning==8)
	{
	 if(relay1_state==0)
	 relay1_off;
	 else
	 relay1_on;
	}
	if(relay2_meaning==8)
	{
	 if(relay2_state==0)
	 relay2_off;
	 else
	 relay2_on;
	}
	if(relay3_meaning==8)
	{
	 if(relay3_state==0)
	 relay3_off;
	 else
	 relay3_on;
	}
	if(relay4_meaning==8)
	{
	 if(relay4_state==0)
	 relay4_off;
	 else
	 relay4_on;
	}
	if(relay5_meaning==8)
    {
	 if(relay5_state==0)
	 relay5_off;
	 else
	 relay5_on;
	}
    
 }
 
