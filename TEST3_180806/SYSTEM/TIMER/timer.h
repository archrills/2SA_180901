#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
	  
extern unsigned int   timer0_count,timer2_count,torque_register;

void Timerx_Init(void); 
void Timerx_Init1(void);
 
#endif

 void Timer2_Init(void); 
 void Timer4_Init(void);
void timer2_reset(void);
void timer4_reset(void);
void timer0_reset(void);
