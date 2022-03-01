#ifndef _STM32_I2C_H_
#define _STM32_I2C_H_

#include "main.h"

struct I2C_Pins
{
    uint8_t                	dev_addr;
    GPIO_TypeDef *         	SDA_GPIOx;
    uint16_t				SDA_GPIO_Pin;
    GPIO_TypeDef *         	SCK_GPIOx;
    uint16_t		       	SCK_GPIO_Pin;
};

extern int I2C_Open(struct I2C_Pins *i2c);
extern void I2C_WriteBytes(struct I2C_Pins *i2c, uint8_t addr, uint8_t *pData, int len);
extern void I2C_WriteBytesNoAddr(struct I2C_Pins *i2c, uint8_t *pData, int len);
extern uint8_t I2C_ReadByte(struct I2C_Pins *i2c, uint8_t addr);
extern void I2C_ReadBytesNoAddr(struct I2C_Pins *i2c, int len, uint8_t *pData);

#endif
