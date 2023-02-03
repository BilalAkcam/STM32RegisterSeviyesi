/*
 * led.c
 *
 *  Created on: Jan 31, 2023
 *      Author: user
 */


#include "led.h"
#include "stm32f4xx_hal.h"

void ledInit(void){


	// Led Başlangıç Ayarlarımız

	RCC->AHB1ENR |= (1<<3);
	GPIOD->MODER |= (1<<24);
	GPIOD->MODER &= ~(1<<25);

	GPIOD->OTYPER &= ~(1<<13);

	GPIOD->OSPEEDR &= ~(1<<24);
	GPIOD->OSPEEDR &= ~(1<<25);



}



void ledState(int32_t buton_state){

	//Butonnun Durumu Kontrol Edilmekte (Eğer Butona Basılıyorsa Blink Yapılmakta).

	if(buton_state==1){

		GPIOD->ODR |= (1<<12);
		HAL_Delay(500);
		GPIOD->ODR &= ~(1<<12);
		HAL_Delay(500);

	}
	else
		return;


}
