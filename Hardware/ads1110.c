/*
 * ads1110.c
 *
 *  Created on: Apr 26, 2021
 *      Author: lzm_mac
 */
#include <string.h>

#include "stm32_i2c.h"
#include "ads1110.h"

struct I2C_Pins ads1110[4];

void InitADS1110(void)
{
	uint8_t i;
    uint8_t config = 0x8F;

    ads1110[0].dev_addr = 0x49;
    ads1110[0].SDA_GPIOx = SDA1_GPIO_Port;
    ads1110[0].SDA_GPIO_Pin = SDA1_Pin;
    ads1110[0].SCK_GPIOx = SCL1_GPIO_Port;
    ads1110[0].SCK_GPIO_Pin = SCL1_Pin;

    ads1110[1].dev_addr = 0x49;
    ads1110[1].SDA_GPIOx = SDA2_GPIO_Port;
    ads1110[1].SDA_GPIO_Pin = SDA2_Pin;
    ads1110[1].SCK_GPIOx = SCL2_GPIO_Port;
    ads1110[1].SCK_GPIO_Pin = SCL2_Pin;

    ads1110[2].dev_addr = 0x49;
    ads1110[2].SDA_GPIOx = SDA3_GPIO_Port;
    ads1110[2].SDA_GPIO_Pin = SDA3_Pin;
    ads1110[2].SCK_GPIOx = SCL3_GPIO_Port;
    ads1110[2].SCK_GPIO_Pin = SCL3_Pin;

    ads1110[3].dev_addr = 0x49;
    ads1110[3].SDA_GPIOx = SDA4_GPIO_Port;
    ads1110[3].SDA_GPIO_Pin = SDA4_Pin;
    ads1110[3].SCK_GPIOx = SCL4_GPIO_Port;
    ads1110[3].SCK_GPIO_Pin = SCL4_Pin;

    for (i = 0; i < 4; i++)
    {
		I2C_Open(&ads1110[i]);
		I2C_WriteBytesNoAddr(&ads1110[i], &config, 1);
    }
}

int ReadAD(uint8_t adc_idx)
{
	int val;
	uint16_t count;
    uint8_t data[2];
    while (1)
    {
        I2C_ReadBytesNoAddr(&ads1110[adc_idx], 2, data);
        count = data[0];
        count <<= 8;
        count += data[1];
        if (data[0] != 0xFF || data[1] != 0xFF)
            break;
    }

	if ((count & 0x8000) == 0x000000)
	{
		val = count;
	}
	else
	{
		val = (int32_t)count - (int32_t)0xFFFF - 1;
	}

    return val;
}

