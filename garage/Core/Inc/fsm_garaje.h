/*
 * fsm_garaje.h
 *
 *  Created on: 20 abr. 2021
 *      Author: nahueldb
 */

#ifndef INC_FSM_GARAJE_H_
#define INC_FSM_GARAJE_H_

typedef enum {
    REPOSO,
    ENTRANDO,
    ESPERANDO,
    ALARMA
} FSM_GARAJE_ESTADOS_T;


void fsmGarajeInit(void);
void fsmGaraje(void);
void fsmGarajeTick(void);

void fsmRaiseEvSensor1_On (void);
void fsmRaiseEvSensor2_On (void);
void fsmRaiseEvSensor2_Off (void);



#endif /* INC_FSM_GARAJE_H_ */
