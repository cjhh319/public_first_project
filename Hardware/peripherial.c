/*
 * peripherial.c
 *
 *  Created on: Apr 26, 2021
 *      Author: lzm_mac
 */

#include "peripherial.h"

void PowerOn(void)
{
	HAL_GPIO_WritePin(POWER_CON_GPIO_Port, POWER_CON_Pin, GPIO_PIN_SET);
}

void PowerOff(void)
{
	HAL_GPIO_WritePin(POWER_CON_GPIO_Port, POWER_CON_Pin, GPIO_PIN_RESET);
}

void TurnOnPowerLED(void)
{
	HAL_GPIO_WritePin(LED_GPIO3_GPIO_Port, LED_GPIO3_Pin, GPIO_PIN_SET);
}

void TurnOffPowerLED(void)
{
	HAL_GPIO_WritePin(LED_GPIO3_GPIO_Port, LED_GPIO3_Pin, GPIO_PIN_RESET);
}

void TurnOnBoardLED(uint8_t idx)
{
	if (idx == 0)
		HAL_GPIO_WritePin(LED_GPIO5_GPIO_Port, LED_GPIO5_Pin, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(LED_GPIO1_GPIO_Port, LED_GPIO1_Pin, GPIO_PIN_SET);
}

void TurnOffBoardLED(uint8_t idx)
{
	if (idx == 0)
		HAL_GPIO_WritePin(LED_GPIO5_GPIO_Port, LED_GPIO5_Pin, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(LED_GPIO1_GPIO_Port, LED_GPIO1_Pin, GPIO_PIN_RESET);
}

void ToggleBoardLED(uint8_t idx)
{
	if (idx == 0)
		HAL_GPIO_TogglePin(LED_GPIO5_GPIO_Port, LED_GPIO5_Pin);
	else
		HAL_GPIO_TogglePin(LED_GPIO1_GPIO_Port, LED_GPIO1_Pin);
}
