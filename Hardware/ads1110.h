/*
 * ads1110.h
 *
 *  Created on: Apr 26, 2021
 *      Author: lzm_mac
 */

#ifndef ADS1110_H_
#define ADS1110_H_

#include "main.h"

extern void InitADS1110(void);
extern int ReadAD(uint8_t adc_idx);


#endif /* ADS1110_H_ */
