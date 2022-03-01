/*
 * my_delay.c
 *
 *  Created on: Apr 26, 2021
 *      Author: lzm_mac
 */
#include "my_delay.h"

void my_delay_count(uint16_t cnt)
{
	volatile uint16_t i;
	for (i = 0; i < cnt; i++);
}
