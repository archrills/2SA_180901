#ifndef __KEY_H
#define __KEY_H	 
#include "stm32f10x.h"


void KEY_Init(void);
void key_scan_process(void);
void key_scan_process1(void);
void key_scan1(void);

#endif




#define KEY_UP  	      (PGin(10)==1||((uart5_count_array[0]==0x02)&&(key_allowed==1)))   			        
#define KEY_DOWN        (PGin(9)==1||((uart5_count_array[0]==0x03)&&(key_allowed==1)))         
#define KEY_TOGGLE      PDin(6)==1
#define KEY_ENTER	      PDin(7)==1
#define KEY_IDLE       ((PGin(10)==0)&&(PGin(9)==0)&&(PDin(6)==0)&&(PDin(7)==0))
#define KEY_IN         ((PGin(10)==1)||(PGin(9)==1)||(PDin(6)==1)||(PDin(7)==1))

extern void GpuSend(char * buf1);
void key_scan(void);
extern unsigned char  key_toggle_used,key_enter_used,key_up_used,key_down_used;
extern unsigned int   timer0_count,timer2_count,torque_register;
extern unsigned char  key_short_register,key_longtime_register;

extern signed int order_point;
extern struct MenuItem *menu_point;
extern signed char menu_position;




#define key_toggle_short_press 	(key_short_register==1)
#define key_enter_short_press 	(key_short_register==2)   
#define key_up_short_press     	(key_short_register==3)
#define key_down_short_press    (key_short_register==4)

#define key_toggle_long_press 	(key_longtime_register==1)	   
#define key_enter_long_press 	  (key_longtime_register==2)   
#define key_up_long_press     	(key_longtime_register==3)
#define key_down_long_press     (key_longtime_register==4)
#define key_register_reset      {key_short_register=0;key_longtime_register=0;}











