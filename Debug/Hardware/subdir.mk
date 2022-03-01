################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hardware/ads1110.c \
../Hardware/my_delay.c \
../Hardware/peripherial.c \
../Hardware/stm32_i2c.c 

OBJS += \
./Hardware/ads1110.o \
./Hardware/my_delay.o \
./Hardware/peripherial.o \
./Hardware/stm32_i2c.o 

C_DEPS += \
./Hardware/ads1110.d \
./Hardware/my_delay.d \
./Hardware/peripherial.d \
./Hardware/stm32_i2c.d 


# Each subdirectory must supply rules for building sources it contributes
Hardware/%.o: ../Hardware/%.c Hardware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Hardware -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

