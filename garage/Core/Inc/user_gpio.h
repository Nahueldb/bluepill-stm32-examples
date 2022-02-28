/*
 * user_gpio.h
 *
 *  Created on: 20 abr. 2021
 *      Author: nahueldb
 */

#ifndef INC_USER_GPIO_H_
#define INC_USER_GPIO_H_

void fsmActivarAlarma(void);
void fsmAbrirBarrera(void);
void fsmCerrarBarrera(void);
void fsmDesactivarAlarma(void);

void user_gpio_init(void);
void user_gpio(void);

#endif /* INC_USER_GPIO_H_ */
