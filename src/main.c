/*
 * main.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Ahmed Salah
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "OS_interface.h"


#define	TASK_1_PRIORITY		(0)
#define	TASK_2_PRIORITY		(1)
#define	TASK_3_PRIORITY		(1)
#define	TASK_4_PRIORITY		(2)
#define	TASK_5_PRIORITY		(2)
#define	TASK_6_PRIORITY		(3)

#define	TASK_1_ID			(100)
#define	TASK_2_ID			(201)
#define	TASK_3_ID			(202)
#define	TASK_4_ID			(203)
#define	TASK_5_ID			(204)
#define	TASK_6_ID			(205)

#define	TASK_1_PERIOD		(10000UL)
#define	TASK_2_PERIOD		(1000UL)
#define	TASK_3_PERIOD		(2000UL)
#define	TASK_4_PERIOD		(4000UL)
#define	TASK_5_PERIOD		(8000UL)
#define	TASK_6_PERIOD		(16000UL)

#define	TASK_1_INITIALDELAY	(5000UL)
#define	TASK_2_INITIALDELAY	(0)
#define	TASK_3_INITIALDELAY	(0)
#define	TASK_4_INITIALDELAY	(0)
#define	TASK_5_INITIALDELAY	(0)
#define	TASK_6_INITIALDELAY	(0)


void Task_1(void);
void Task_2(void);
void Task_3(void);
void Task_4(void);
void Task_5(void);
void Task_6(void);

int main (void)
{
	MRCC_voidInitSysClock ();
	MRCC_voidEnableClock  (RCC_APB2,RCC_APB2_IOPBEN);

	MGPIO_voidSetPinMode  (GPIOB, PIN11, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (GPIOB, PIN12, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (GPIOB, PIN13, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (GPIOB, PIN14, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (GPIOB, PIN15, OUTPUT_GP_PP_2MHZ);

	SOS_voidCreateTask    (TASK_1_PRIORITY, TASK_1_ID, TASK_1_PERIOD, TASK_1_INITIALDELAY, Task_1);
	SOS_voidStartScheduler();

	while(1);
}

void Task_1(void)
{
	for(u8 i=0; i<16; i++)
	{
		MGPIO_voidTogglePin (GPIOB, PIN11);
		MGPIO_voidTogglePin (GPIOB, PIN12);
		MGPIO_voidTogglePin (GPIOB, PIN13);
		MGPIO_voidTogglePin (GPIOB, PIN14);
		MGPIO_voidTogglePin (GPIOB, PIN15);

		for(u16 j=0; j<65000UL; j++)
		{
			asm volatile("NOP");
		}
	}

	SOS_voidCreateTask (TASK_2_PRIORITY, TASK_2_ID, TASK_2_PERIOD, TASK_2_INITIALDELAY, Task_2);
	SOS_voidCreateTask (TASK_3_PRIORITY, TASK_3_ID, TASK_3_PERIOD, TASK_3_INITIALDELAY, Task_3);
	SOS_voidCreateTask (TASK_4_PRIORITY, TASK_4_ID, TASK_4_PERIOD, TASK_4_INITIALDELAY, Task_4);
	SOS_voidCreateTask (TASK_5_PRIORITY, TASK_5_ID, TASK_5_PERIOD, TASK_5_INITIALDELAY, Task_5);
	SOS_voidCreateTask (TASK_6_PRIORITY, TASK_6_ID, TASK_6_PERIOD, TASK_6_INITIALDELAY, Task_6);

	SOS_voidKillTask   (Task_1);
}

void Task_2(void)
{
	MGPIO_voidTogglePin (GPIOB, PIN11);
}

void Task_3(void)
{
	MGPIO_voidTogglePin (GPIOB, PIN12);
}
void Task_4(void)
{
	MGPIO_voidTogglePin (GPIOB, PIN13);
}

void Task_5(void)
{
	MGPIO_voidTogglePin (GPIOB, PIN14);
}

void Task_6(void)
{
	MGPIO_voidTogglePin (GPIOB, PIN15);
}
