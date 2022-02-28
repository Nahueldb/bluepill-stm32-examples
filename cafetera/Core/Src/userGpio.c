/*
 * userGpio.c
 *
 *  Created on: May 3, 2021
 *      Author: nahueldb
 */
#include "fsmCafetera.h"
#include "userGpio.h"
#include "main.h"

void userGpioInit(void)
{
	desactivarSonido();
	erogarCafeOff();
	erogarTeOff();
}

void userGpio(void)
{
	if (HAL_GPIO_ReadPin(FICHA_GPIO_Port, FICHA_Pin) == GPIO_PIN_RESET)
	{
			raiseEvMoneda();
	}

	if (HAL_GPIO_ReadPin(INPUT_CAFE_GPIO_Port, INPUT_CAFE_Pin) == GPIO_PIN_RESET)
	{
			raiseEvCafe();
	}

	if (HAL_GPIO_ReadPin(INPUT_TE_GPIO_Port, INPUT_TE_Pin) == GPIO_PIN_RESET)
	{
			raiseEvTe();
	}
}


void activarSonido(void)
{
	HAL_GPIO_WritePin(SONIDO_GPIO_Port, SONIDO_Pin, GPIO_PIN_RESET);
}
void desactivarSonido(void)
{
	HAL_GPIO_WritePin(SONIDO_GPIO_Port, SONIDO_Pin, GPIO_PIN_SET);
}
void erogarCafeOn(void)
{
	HAL_GPIO_WritePin(OUTPUT_CAFE_GPIO_Port, OUTPUT_CAFE_Pin, GPIO_PIN_RESET);
}
void erogarCafeOff(void)
{
	HAL_GPIO_WritePin(OUTPUT_CAFE_GPIO_Port, OUTPUT_CAFE_Pin, GPIO_PIN_SET);
}
void erogarTeOn(void)
{
	HAL_GPIO_WritePin(OUTPUT_TE_GPIO_Port, OUTPUT_TE_Pin, GPIO_PIN_RESET);
}
void erogarTeOff(void)
{
	HAL_GPIO_WritePin(OUTPUT_TE_GPIO_Port, OUTPUT_TE_Pin, GPIO_PIN_SET);
}
void togglePin(void)
{
	HAL_GPIO_TogglePin(LED13_GPIO_Port, LED13_Pin);

}
void prenderToggle(void)
{
	HAL_GPIO_WritePin(LED13_GPIO_Port, LED13_Pin, GPIO_PIN_RESET);
}
void apagarToggle(void)
{
	HAL_GPIO_WritePin(LED13_GPIO_Port, LED13_Pin, GPIO_PIN_SET);
}
