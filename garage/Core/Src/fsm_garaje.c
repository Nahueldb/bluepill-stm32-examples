/*
 * fsm_garaje.c
 *
 *  Created on: 20 abr. 2021
 *      Author: nahueldb
 */
#include "fsm_garaje.h"
#include "user_gpio.h"
#include <stdint.h>
#include <stdbool.h>

#define ESPERA_5SEG  5

static FSM_GARAJE_ESTADOS_T estado;

static bool evSensor1_On;
static bool evSensor2_On;
static bool evSensor2_Off;
static bool evTick1seg;

static uint32_t contMs;
static uint8_t contSeg;


static void clrEv(void)
{
	evSensor1_On = 0;
	evSensor2_On = 0;
	evSensor2_Off = 0;
	evTick1seg = 0;
}


void fsmGarajeInit(void)
{
	estado=REPOSO;
	clrEv();

}
void fsmGaraje(void){
	switch (estado)
	{
		case REPOSO:
			if(evSensor2_On)
			{
				fsmActivarAlarma();
				estado=ALARMA;
			}
			else if(evSensor1_On)
			{
				fsmAbrirBarrera();
				estado=ENTRANDO;
			}
			break;
		case ENTRANDO:
			if(evSensor2_On)
			{
				contSeg=0;
				estado=ESPERANDO;
			}
			break;
		case ESPERANDO:
			if(evSensor1_On)
			{
				estado=ENTRANDO;
			}
			else if(evTick1seg && contSeg<ESPERA_5SEG)
			{
				contSeg++;
			}
			else if(evTick1seg && contSeg==ESPERA_5SEG)
			{
				fsmCerrarBarrera();
				estado=REPOSO;
			}
			break;
		case ALARMA:
			if(evSensor2_Off)
			{
				fsmDesactivarAlarma();
				estado=REPOSO;
			}

			break;
	}
	clrEv();
}
void fsmGarajeTick(void)
{
	contMs ++;
	if (contMs>=1000)
	{
		evTick1seg=1;
		contMs=0;
	}
}
void fsmRaiseEvSensor1_On (void)
{
	evSensor1_On=1;
}
void fsmRaiseEvSensor2_On (void)
{
	evSensor2_On=1;
}
void fsmRaiseEvSensor2_Off (void)
{
	evSensor2_Off=1;
}
