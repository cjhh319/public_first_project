#include "stm32_i2c.h"
#include "my_delay.h"

int I2C_Open(struct I2C_Pins *i2c)
{
	GPIO_InitTypeDef GPIO_Out_InitStruct = {0};

	GPIO_Out_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Out_InitStruct.Pull = GPIO_NOPULL;
	GPIO_Out_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	GPIO_Out_InitStruct.Pin = i2c->SCK_GPIO_Pin;
	HAL_GPIO_Init(i2c->SCK_GPIOx, &GPIO_Out_InitStruct);
	GPIO_Out_InitStruct.Pin = i2c->SDA_GPIO_Pin;
    HAL_GPIO_Init(i2c->SDA_GPIOx, &GPIO_Out_InitStruct);

    HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_SET);
    my_delay_count(10);
    HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_RESET);
	my_delay_count(10);
    HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_SET);
    my_delay_count(20);
    return 0;
}

void I2C_SendStart(struct I2C_Pins *i2c)
{
    // Assert start bit
	GPIO_InitTypeDef GPIO_Out_InitStruct = {0};
	GPIO_Out_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Out_InitStruct.Pull = GPIO_NOPULL;
	GPIO_Out_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Out_InitStruct.Pin = i2c->SDA_GPIO_Pin;
	HAL_GPIO_Init(i2c->SDA_GPIOx, &GPIO_Out_InitStruct);
	HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_SET);
	my_delay_count(5);
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_SET);
	my_delay_count(5);
	HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_RESET);
	my_delay_count(5);
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
	my_delay_count(5);
}

void I2C_Stop(struct I2C_Pins *i2c)
{
    my_delay_count(5);
	GPIO_InitTypeDef GPIO_Out_InitStruct = {0};
	GPIO_Out_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Out_InitStruct.Pull = GPIO_NOPULL;
	GPIO_Out_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Out_InitStruct.Pin = i2c->SDA_GPIO_Pin;
    HAL_GPIO_Init(i2c->SDA_GPIOx, &GPIO_Out_InitStruct);
    HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_RESET);
	my_delay_count(5);
    HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_SET);
	my_delay_count(5);
    HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_SET);
	my_delay_count(5);
}

void I2C_Ack(struct I2C_Pins *i2c)
{
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
	GPIO_InitTypeDef GPIO_Out_InitStruct = {0};
	GPIO_Out_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Out_InitStruct.Pull = GPIO_NOPULL;
	GPIO_Out_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Out_InitStruct.Pin = i2c->SDA_GPIO_Pin;
	HAL_GPIO_Init(i2c->SDA_GPIOx, &GPIO_Out_InitStruct);
	my_delay_count(5);
	HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_RESET);
	my_delay_count(5);
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_SET);
	my_delay_count(5);
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
	my_delay_count(5);
}

void I2C_NAck(struct I2C_Pins *i2c)
{
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
	GPIO_InitTypeDef GPIO_Out_InitStruct = {0};
	GPIO_Out_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Out_InitStruct.Pull = GPIO_NOPULL;
	GPIO_Out_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Out_InitStruct.Pin = i2c->SDA_GPIO_Pin;
	HAL_GPIO_Init(i2c->SDA_GPIOx, &GPIO_Out_InitStruct);
	my_delay_count(5);
	HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_SET);
	my_delay_count(5);
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_SET);
	my_delay_count(5);
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
	my_delay_count(5);
}

uint8_t I2C_Wait_Ack(struct I2C_Pins *i2c)
{
	uint8_t bit;
	uint8_t ucErrTime = 0;
	GPIO_InitTypeDef GPIO_In_InitStruct = {0};
	GPIO_In_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_In_InitStruct.Pull = GPIO_PULLUP;
	GPIO_In_InitStruct.Pin = i2c->SDA_GPIO_Pin;
    HAL_GPIO_Init(i2c->SDA_GPIOx, &GPIO_In_InitStruct);
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_SET);
	my_delay_count(5);
	bit = (HAL_GPIO_ReadPin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin) == GPIO_PIN_RESET ? 0 : 1);
	while (bit)
	{
		ucErrTime++;
		if(ucErrTime > 250)
		{
			I2C_Stop(i2c);
			return 1;
		}
		my_delay_count(5);
		bit = (HAL_GPIO_ReadPin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin) == GPIO_PIN_RESET ? 0 : 1);
	}
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
	my_delay_count(5);
	return 0;
}

void I2C_Send_Byte(struct I2C_Pins *i2c, uint8_t data)
{
	uint8_t i;
	GPIO_InitTypeDef GPIO_Out_InitStruct = {0};
	GPIO_Out_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Out_InitStruct.Pull = GPIO_NOPULL;
	GPIO_Out_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Out_InitStruct.Pin = i2c->SDA_GPIO_Pin;
    HAL_GPIO_Init(i2c->SDA_GPIOx, &GPIO_Out_InitStruct);
	HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
	my_delay_count(5);
	for (i = 0; i < 8; i++)
    {
		if (data & 0x80)
			HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin, GPIO_PIN_RESET);

		my_delay_count(5);
		data <<= 1;
		HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_SET);
		my_delay_count(5);
		HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
		my_delay_count(5);
    }
	I2C_Wait_Ack(i2c);
}

uint8_t I2C_Read_Byte(struct I2C_Pins *i2c, uint8_t ack)
{
	uint8_t i, receive = 0;
	uint8_t bit;
	GPIO_InitTypeDef GPIO_In_InitStruct = {0};
	GPIO_In_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_In_InitStruct.Pull = GPIO_PULLUP;
	GPIO_In_InitStruct.Pin = i2c->SDA_GPIO_Pin;
	HAL_GPIO_Init(i2c->SDA_GPIOx, &GPIO_In_InitStruct);
	my_delay_count(5);
	for (i = 0; i < 8; i++)
	{
		HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_RESET);
		my_delay_count(5);
		HAL_GPIO_WritePin(i2c->SCK_GPIOx, i2c->SCK_GPIO_Pin, GPIO_PIN_SET);
		receive <<= 1;
		my_delay_count(5);
		bit = (HAL_GPIO_ReadPin(i2c->SDA_GPIOx, i2c->SDA_GPIO_Pin) == GPIO_PIN_RESET ? 0 : 1);
		my_delay_count(5);
		if (bit) receive++;
	}
	if (!ack)
		I2C_NAck(i2c);//??nACK
	else
		I2C_Ack(i2c); //??ACK
	return receive;
}

void I2C_WriteBytes(struct I2C_Pins *i2c, uint8_t addr, uint8_t *pData, int len)
{
    int i;
    I2C_SendStart(i2c);
    I2C_Send_Byte(i2c, i2c->dev_addr << 1);
    I2C_Send_Byte(i2c, addr);
	for (i = 0; i < len; i++)
        I2C_Send_Byte(i2c, pData[i]);
    I2C_Stop(i2c);
}

void I2C_WriteBytesNoAddr(struct I2C_Pins *i2c, uint8_t *pData, int len)
{
    int i;
    I2C_SendStart(i2c);
    I2C_Send_Byte(i2c, i2c->dev_addr << 1);
	for (i = 0; i < len; i++)
        I2C_Send_Byte(i2c, pData[i]);
    I2C_Stop(i2c);
}

uint8_t I2C_ReadByte(struct I2C_Pins *i2c, uint8_t addr)
{
    uint8_t u8Data;

    // 1-Phase(ID address, register address) write transmission
	I2C_SendStart(i2c);
    I2C_Send_Byte(i2c, i2c->dev_addr << 1);
    I2C_Send_Byte(i2c, addr);
	I2C_SendStart(i2c);
	I2C_Send_Byte(i2c, (i2c->dev_addr << 1) | 0x01);
    u8Data = I2C_Read_Byte(i2c, 0);
    I2C_Stop(i2c);

    return u8Data;
}

void I2C_ReadBytesNoAddr(struct I2C_Pins *i2c, int len, uint8_t *pData)
{
    int i;
	I2C_SendStart(i2c);
	I2C_Send_Byte(i2c, (i2c->dev_addr << 1) | 0x01);
    for (i = 0; i < len; i++) {
        //if (i == len - 1)
        //    pData[i] = I2C_Read_Byte(i2c, 0);
        //else
            pData[i] = I2C_Read_Byte(i2c, 1);
    }
    I2C_Stop(i2c);
}
