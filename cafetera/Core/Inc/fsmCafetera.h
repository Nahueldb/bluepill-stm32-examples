/*
 * fsmCafetera.h
 *
 *  Created on: May 3, 2021
 *      Author: nahueldb
 */

#ifndef INC_FSMCAFETERA_H_
#define INC_FSMCAFETERA_H_

/** @brief Enumeracion de todos los estados */
typedef enum {
    REPOSO,
    ESPERANDO,
	CAFE,
	TE,
    SONIDO
} FSM_CAFETERA_ESTADOS_T;



/** @brief Inicializacion de la maquina de estados*/
void fsmCafeteraInit(void);

/** @brief Maquina de estados*/
void fsmCafetera(void);

/** @brief Manejo de eventos de tiempo*/
void cafeteraTick(void);

/** @brief Generacion de eventos de la maquina de estados @{ */
void raiseEvMoneda(void);
void raiseEvCafe(void);
void raiseEvTe(void);
/** @} */



#endif /* INC_FSMCAFETERA_H_ */
