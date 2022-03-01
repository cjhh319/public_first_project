/*
 * peripherial.h
 *
 *  Created on: Apr 26, 2021
 *      Author: lzm_mac
 */

#ifndef PERIPHERIAL_H_
#define PERIPHERIAL_H_

#include "main.h"

extern void PowerOn(void);
extern void PowerOff(void);
extern void TurnOnPowerLED(void);
extern void TurnOffPowerLED(void);
extern void TurnOnBoardLED(uint8_t idx);
extern void TurnOffBoardLED(uint8_t idx);
extern void ToggleBoardLED(uint8_t idx);

#endif /* PERIPHERIAL_H_ */
