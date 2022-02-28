/*
 * userGpio.h
 *
 *  Created on: May 3, 2021
 *      Author: nahueldb
 */

#ifndef INC_USERGPIO_H_
#define INC_USERGPIO_H_

/** @brief Inicializacion de GPIO*/
void userGpioInit(void);

/** @brief Funcion que evalua el estado de los inputs GPIO */
void userGpio(void);

/** @brief Acciones de la maquina de estados @{ */
void activarSonido(void);
void desactivarSonido(void);
void erogarCafeOn(void);
void erogarCafeOff(void);
void erogarTeOn(void);
void erogarTeOff(void);
void togglePin(void);
void prenderToggle(void);
void apagarToggle(void);
/** @} */

#endif /* INC_USERGPIO_H_ */
