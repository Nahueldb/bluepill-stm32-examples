/*
 * fsmCafetera.c
 *
 *  Created on: May 3, 2021
 *      Author: nahueldb
 */
#include "fsmCafetera.h"
#include "userGpio.h"
#include <stdint.h>
#include <stdbool.h>

#define ESPERA_2SEG  2000
#define ESPERA_5SEG  5000
#define ESPERA_7SEG  7000
#define ESPERA_10SEG  10000
#define ESPERA_5HZ  100
#define ESPERA_1HZ  500


static FSM_CAFETERA_ESTADOS_T estado;

static bool evMoneda;
static bool evCafe;
static bool evTe;
static bool evTick1MiliSeg;

static uint32_t timerMiliSeg;

static void clrEv(void)
{
	evMoneda = 0;
	evCafe = 0;
	evTe = 0;
	evTick1MiliSeg = 0;
}

void fsmCafeteraInit(void)
{
	estado = REPOSO;
	clrEv();
}

void fsmCafetera(void){
	switch (estado)
	{
		case REPOSO:
			if (evMoneda)
			{
				estado = ESPERANDO;
				timerMiliSeg = 0;
				prenderToggle();
				/*Teniendo en mente la interfaz con el usuario, el led del toggle queda prendido
				 *para que haya una diferencia visual entre los estados ESPERANDO y REPOSO
				 */
			}
			else if (evTick1MiliSeg && (timerMiliSeg %  ESPERA_1HZ == 0))
			{
				togglePin();
				timerMiliSeg ++;
			}

			else if (evTick1MiliSeg)
			{
				timerMiliSeg ++;
			}

			break;
		case ESPERANDO:
			if (evCafe)
			{
				estado = CAFE;
				timerMiliSeg = 0;
				erogarCafeOn();
			}
			else if (evTe)
			{
				estado = TE;
				timerMiliSeg = 0;
				erogarTeOn();
			}
			else if (evTick1MiliSeg && (timerMiliSeg < ESPERA_5SEG))
			{
				timerMiliSeg ++;
			}
			else if (evTick1MiliSeg && (timerMiliSeg == ESPERA_5SEG))
			{
				estado = REPOSO;
				//devolverMoneda();
			}
			break;
		case CAFE:
			if (evTick1MiliSeg)
			{
				if (timerMiliSeg == ESPERA_10SEG)
				{
					estado = SONIDO;
					timerMiliSeg = 0;
					erogarCafeOff();
					activarSonido();
					apagarToggle();
				}
				else if (timerMiliSeg %  ESPERA_5HZ == 0)
				{
					timerMiliSeg ++;
					togglePin();
				}

				else if (timerMiliSeg < ESPERA_10SEG)
				{
					timerMiliSeg ++;
				}
			}
			break;
		case TE:
			if (evTick1MiliSeg)
			{
				if (timerMiliSeg == ESPERA_7SEG)
				{
					estado = SONIDO;
					timerMiliSeg = 0;
					erogarTeOff();
					activarSonido();
					apagarToggle();
				}
				else if (timerMiliSeg %  ESPERA_5HZ == 0)
				{
					timerMiliSeg ++;
					togglePin();
				}

				else if (timerMiliSeg < ESPERA_7SEG)
				{
					timerMiliSeg ++;
				}
			}
			break;
		case SONIDO:
			if (evTick1MiliSeg && (timerMiliSeg == ESPERA_2SEG))
			{
				estado = REPOSO;
				desactivarSonido();
			}
			else if (evTick1MiliSeg && (timerMiliSeg < ESPERA_2SEG))
			{
				timerMiliSeg ++;

			}
	}
	clrEv();
}

void cafeteraTick(void)
{
	evTick1MiliSeg = 1;
}
void raiseEvMoneda(void)
{
	evMoneda = 1;
}
void raiseEvCafe(void)
{
	evCafe = 1;
}
void raiseEvTe(void)
{
	evTe = 1;
}
