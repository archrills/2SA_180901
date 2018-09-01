#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
 

#define LED_TORQUE      PDout(3)       //4
#define LED_FAULT       PDout(4)       //3
#define LED_ZERO        PDout(5)       //2
#define LED_FULL        PAout(15)      //1
#define MCU_POWER       PGout(11)
void LED_Init(void);//≥ı ºªØ

		 				    
#endif
