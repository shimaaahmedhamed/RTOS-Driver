/*
 * main.c
 *
 *  Created on: Dec 17, 2022
 *      Author: Aspire
 */

#include"RTOS_STACK/RTOS_Interface.h"
#include"MCAL/DIO/DIO_interface.h"
#include <util/delay.h>
#include"Free_RTOS/FreeRTOS.h"
#include "Free_RTOS/FreeRTOSConfig.h"
#include"Free_RTOS/task.h"
#include"HAL/LCD-/LCD_configure.h"
#include"HAL/SSD/SSD_Interface.h"
#include"Free_RTOS/semphr.h"

/*    define semphore     */
/* xSemaphoreHandle name; */
 xSemaphoreHandle LCDSem;

u8 arr1[20]="welcome";
u8 arr2[20]="HI";

void segment1fun()
{
	while(1)
	{
		static u8 counter=0;
		SSD_voidPrintNum_1(counter++);
		if(counter==10)
		{
			counter=0;

		}
		vTaskDelay(1000);
	}


}

void str1()
{

	while(1)
	{

		static u8 count=0;
		LCD_WRITE_DATA(arr1[count++]);
		if(count==10)
		{
			count=0;

		}
		vTaskDelay(5000);

	}

}



//void segment1fun()
//{
//	while(1)
//	{
//		u8 SemState = xSemaphoreTake(LCDSem,10);
//		static u8 counter1=0;
//		xSemaphoreTake(LCDSem, 10);
//		if(SemState == pdPASS)
//		{
//
//			while(counter1<10)
//			{
//				SSD_voidPrintNum_1(counter1++);
//
//				if(counter1==10)
//				{
//					counter1=0;
//
//				}
//			}
//
//
//
//		 xSemaphoreGive(LCDSem);
//		 }
//		else
//		{
//			/* do nothing */
//		}
//		}
//
//	vTaskDelay(1000);
//}
//
//

//void segment2fun()
//{
//	while(1)
//	{
//		u8 SemState = xSemaphoreTake(LCDSem,10);
//		static u8 counter2=0;
//		xSemaphoreTake(LCDSem, 10);
//		if(SemState == pdPASS)
//		  {
//
//			while(counter2<10)
//			{
//				SSD_voidPrintNum_1(counter2);
//				counter2++;
//				if(counter2==10)
//				{
//					counter2=0;
//
//				}
//			}
//			xSemaphoreGive(LCDSem);
//		  }
//		else
//		{
//			/* do nothing */
//		}
//
//	vTaskDelay(1000);
//	}
//
//
//}

void LED_1()
{
   while(1)
   {
	DIO_voidToggelPin(PORTB_ID,PIN0);
	vTaskDelay(2000);
   }

}
//void LED_2()
//{
//    while(1)
//    {
//	DIO_voidToggelPin(PORTD_ID,PIN1);
//	vTaskDelay(2000);
//    }
//
//}
//void LED_3()
//{
//    while(1)
//    {
//	DIO_voidToggelPin(PORTD_ID,PIN2);
//	vTaskDelay(3000);                 //priodicty 1000msec=1sec
//    }
//}

//void str1()
//{
//
//	while(1)
//	{
//		u8 SemState = xSemaphoreTake(LCDSem,10);
//		static u8 count=0;
//		xSemaphoreTake(LCDSem, 10);
//
//		if(SemState == pdPASS)
//		{
//			//LCD_WRITE_STRING("NTI1");           //Access the LCD
////			for(count=0;count<12;count++)
////			{
////				LCD_WRITE_DATA(arr1[count]);
////				_delay_ms(100);
////			}
//			static u8 count=0;
//
//			LCD_WRITE_DATA(arr1[count++]);
//
//
//			if(count==10)
//			{
//				count=0;
//
//			}
//
//			xSemaphoreGive(LCDSem);            //Give the semaphore
//		}
//		else
//		{
//			//Semaphore isn't available, and the timeout has passed
//		}
//
//
//		vTaskDelay(5);
//	}
//
//}

//void str2()
//{
//
//	while(1)
//	{
//		u8 SemState = xSemaphoreTake(LCDSem,10);
//      static u8 count=0;
//		xSemaphoreTake(LCDSem, 10);
//
//		if(SemState == pdPASS)
//		{
//			//LCD_WRITE_STRING("NTI2");           //Access the LCD
//			for(count=0;count<6;count++)
//			{
//				LCD_WRITE_DATA(arr2[count]);
//				_delay_ms(100);
//			}
//
//			xSemaphoreGive(LCDSem);            //Give the semaphore
//		}
//		else
//		{
//			//Semaphore isn't available, and the timeout has passed
//		}
//
//
//		vTaskDelay(10);
//	}
//
//}
//

//int main()
//{
//
//	DIO_voidSetPinDirection(PORTD_ID, PIN0, PIN_OUTPUT);
//	DIO_voidSetPinDirection(PORTD_ID, PIN1, PIN_OUTPUT);
//	DIO_voidSetPinDirection(PORTD_ID, PIN2, PIN_OUTPUT);
//
////	RTOS_VoCreateTask(LED_1,1000,1,0);
//	xTaskCreate(LED_1,"LED_1",100,NULL,0,NULL);
////	RTOS_VoCreateTask(LED_2,2000,1,2);
//	xTaskCreate(LED_2,"LED_2",100,NULL,1,NULL);        //first priority has the largest number
////	RTOS_VoCreateTask(LED_3,3000,2,4);
//	xTaskCreate(LED_3,"LED_3",100,NULL,2,NULL);
//
////	RTOS_VoInit();
//	vTaskStartScheduler();
//
//while(1)
//{
//
//}
//
//return 0;
//}

//int main()
//{
//	LCD_INIT();
//
//	SSD_voidInit();
//
//	/*   create semphore   */
////	vSemaphoreCreateBinary(LCDSem);            //define type of semaphore, its value by default 1 and if it's waiting any tasks
//
//	xTaskCreate(segment1fun,"segment1fun",100,NULL,1,NULL);
////	xTaskCreate(segment2fun,"segment2fun",100,NULL,1,NULL);
//	xTaskCreate(str1,"str1",100,NULL,2,NULL);
////	xTaskCreate(str2,"str2",100,NULL,1,NULL);
//
//	vTaskStartScheduler();
//
//while(1)
//{
//
//}
//return 0;
//}

int main()
{
	LCD_INIT();
	SSD_voidInit();
	DIO_voidSetPinDirection(PORTB_ID, PIN0, PIN_OUTPUT);
	vSemaphoreCreateBinary(LCDSem);
	xTaskCreate(segment1fun,"segment1fun",100,NULL,1,NULL);
	xTaskCreate(str1,"str1",100,NULL,2,NULL);
	xTaskCreate(LED_1,"LED_1",100,NULL,0,NULL);

	vTaskStartScheduler();

while(1)
{

}
return 0;
}
