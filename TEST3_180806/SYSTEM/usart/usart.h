#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 


void uart_init(u32 bound);
void uart2_init(u32 bound);
void uart4_init(u32 bound);
void GpuSend(char * buf1);
//void GpuSend2(char * buf1);
void GpuSend4(char * buf1);



#endif


