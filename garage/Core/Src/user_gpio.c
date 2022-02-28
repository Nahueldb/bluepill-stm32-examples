/*
 * user_gpio.c
 *
 *  Created on: 20 abr. 2021
 *      Author: nahueldb
 */

#include "fsm_garaje.h"
#include "user_gpio.h"
#include "main.h"

void user_gpio_init(void)
{
	fsmCerrarBarrera();
	fsmDesactivarAlarma();
}

void user_gpio(void)
{
	if (HAL_GPIO_ReadPin(SENSOR1_GPIO_Port, SENSOR1_Pin) == GPIO_PIN_RESET)
	{
			fsmRaiseEvSensor1_On();
	}

	if (HAL_GPIO_ReadPin(SENSOR2_GPIO_Port, SENSOR2_Pin) == GPIO_PIN_RESET)
	{
			fsmRaiseEvSensor2_On();
	}
	else
	{
			fsmRaiseEvSensor2_Off();
	}

}


void fsmActivarAlarma(void)
{
	HAL_GPIO_WritePin(ALARMA_GPIO_Port, ALARMA_Pin, GPIO_PIN_RESET);
}
void fsmDesactivarAlarma(void)
{
	HAL_GPIO_WritePin(ALARMA_GPIO_Port, ALARMA_Pin, GPIO_PIN_SET);
}
void fsmAbrirBarrera(void)
{
	HAL_GPIO_WritePin(BARRERA_GPIO_Port, BARRERA_Pin, GPIO_PIN_RESET);
}
void fsmCerrarBarrera(void)
{
	HAL_GPIO_WritePin(BARRERA_GPIO_Port, BARRERA_Pin, GPIO_PIN_SET);
}
