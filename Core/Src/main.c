/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "peripherial.h"
#include "ads1110.h"

#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
//#define	BOARD_MASTER			1
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */
osThreadId secondCommTaskHandle;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  PowerOn();
  TurnOnPowerLED();
  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, POWER_CON_Pin|O_GPIO_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SDA1_Pin|SCL1_Pin|SDA2_Pin|SCL2_Pin
                          |SDA3_Pin|SCL3_Pin|SDA4_Pin|SCL4_Pin
                          |LED_GPIO1_Pin|LED_GPIO5_Pin|LED_GPIO3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : POWER_CON_Pin O_GPIO_Pin */
  GPIO_InitStruct.Pin = POWER_CON_Pin|O_GPIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SDA1_Pin SCL1_Pin SDA2_Pin SCL2_Pin
                           SDA3_Pin SCL3_Pin SDA4_Pin SCL4_Pin
                           LED_GPIO1_Pin LED_GPIO5_Pin LED_GPIO3_Pin */
  GPIO_InitStruct.Pin = SDA1_Pin|SCL1_Pin|SDA2_Pin|SCL2_Pin
                          |SDA3_Pin|SCL3_Pin|SDA4_Pin|SCL4_Pin
                          |LED_GPIO1_Pin|LED_GPIO5_Pin|LED_GPIO3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
#define UARTBUFFERSIZE			512
uint8_t aRxBuffer[1];
uint8_t bRxBuffer[1];
static int uartS, uartE;
static uint8_t uartRBuffer[UARTBUFFERSIZE];
static uint8_t crcTempBuf[32];
uint8_t send_buf[64];
uint8_t second_buf[32];

void StartUartReceiveProc(void)
{
    HAL_UART_Receive_IT(&huart1, aRxBuffer, 1);
}

void StartSecondReceiveProc(void)
{
    HAL_UART_Receive_IT(&huart2, bRxBuffer, 1);
}

void ReceiveByteFromUart2(uint8_t b)
{
    uartRBuffer[uartS] = b;
    uartS++;
    if (uartS >= UARTBUFFERSIZE)
        uartS -= UARTBUFFERSIZE;
}

static int GetRBufferSize(void)
{
	return (uartS + UARTBUFFERSIZE - uartE) % UARTBUFFERSIZE;
}

static uint8_t GetRBuffer(int idx)
{
	return uartRBuffer[(uartE + idx) % UARTBUFFERSIZE];
}

static void SetRBufferIndex(int size)
{
	uartE += size;
	if (uartE >= UARTBUFFERSIZE)
		uartE -= UARTBUFFERSIZE;
}

uint8_t turnoff;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        //ReceiveByteFromUart1(aRxBuffer[0]);
    	if (aRxBuffer[0] == 'S') turnoff = 1;
        StartUartReceiveProc();
    }
    else if (huart->Instance == USART2)
    {
#ifdef BOARD_MASTER
        ReceiveByteFromUart2(bRxBuffer[0]);
#else
        if (bRxBuffer[0] == 'S') turnoff = 1;
#endif
        StartSecondReceiveProc();
    }
}

void SendDataToUSB(uint8_t * pData, uint16_t len)
{
    HAL_UART_Transmit(&huart1, pData, len, 300);
}

void SendDataToMaster(uint8_t * pData, uint16_t len)
{
    HAL_UART_Transmit(&huart2, pData, len, 300);
}

void SecondCommTask(void const * argument)
{
	int i;
    while(1)
    {
    	if (GetRBufferSize() >= 18)
    	{
    		crcTempBuf[0] = GetRBuffer(0);
            if (crcTempBuf[0] == 0xAA)
            {
				crcTempBuf[1] = GetRBuffer(1);
				if (crcTempBuf[1] == 0x55)
				{
					for (i = 2; i <= 18; i++)
						crcTempBuf[i] = GetRBuffer(i);
					memcpy(second_buf, crcTempBuf, 18);
					SetRBufferIndex(18);
				}
				else
				{
					SetRBufferIndex(2);
				}
            }
    		else
    		{
    			SetRBufferIndex(1);
    		}
    	}
        osDelay(5);
    }
}

char strTemp[32];

int myabs(int a)
{
	if (a < 0) return -a;
	return a;
}

int32_t val[4];
int32_t sig[4];
int32_t init_val[4] = {0, 0, 0, 0};
int32_t avg_val[4] = {0, 0, 0, 0};
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
	int i, j, k;
	//int sleep_cnt;

	osDelay(1000);

	turnoff = 0;

	uartS = 0;
	uartE = 0;

	TurnOnBoardLED(0);
	TurnOnBoardLED(1);
	InitADS1110();

	memset(second_buf, 0x00, sizeof(second_buf));

	StartSecondReceiveProc();
#ifdef BOARD_MASTER
    osThreadDef(secondCommTask, SecondCommTask, osPriorityNormal, 0, 128);
    secondCommTaskHandle = osThreadCreate(osThread(secondCommTask), NULL);
#endif

	for (k = 0; k < 10; k++)
	{
		for (i = 0; i < 4; i++)
			init_val[i] = 0;

		for (j = 0; j < 10; j++)
		{
			for (i = 0; i < 4; i++)
				init_val[i] += ReadAD(i);

			ToggleBoardLED(1);

			osDelay(100);
		}

		if (k >= 5)
		{
			for (i = 0; i < 4; i++)
				avg_val[i] += init_val[i] / 10;
		}
	}

	for (i = 0; i < 4; i++)
		avg_val[i] /= 5;

	TurnOffBoardLED(1);

	StartUartReceiveProc();

	for (i = 0; i < 4; i++)
		sig[i] = (avg_val[i] >= 0 ? 1 : -1);

  /* Infinite loop */
	for(;;)
	{
		for (i = 0; i < 4; i++)
		{
			//if (sig[i] == 1)
			//	val[i] = myabs(ReadAD(i) - avg_val[i]);
			//else
			//	val[i] = myabs(avg_val[i] - ReadAD(i));
			val[i] = ReadAD(i) - avg_val[i] + 100;
		}

		ToggleBoardLED(0);

#ifdef BOARD_MASTER
		//sprintf(strTemp, "%ld,%ld,%ld,%ld", val[0], val[1], val[2], val[3]);
		//SendDataToUSB((uint8_t *)strTemp, strlen(strTemp));
		//osDelay(100);
		send_buf[0] = 0xAA;
		send_buf[1] = 0x55;
		memcpy(&send_buf[2], val, sizeof(int32_t) * 4);
		memcpy(&send_buf[2 + sizeof(int32_t) * 4], &second_buf[2], sizeof(int32_t) * 4);
		SendDataToUSB(send_buf, sizeof(int32_t) * 4 * 2 + 2);

		if (turnoff == 1)
		{
			send_buf[0] = (uint8_t)'S';
			SendDataToMaster(send_buf, 1);
			osDelay(1000);
			PowerOff();
			osDelay(1000);
		}
#else
		send_buf[0] = 0xAA;
		send_buf[1] = 0x55;
		memcpy(&send_buf[2], val, sizeof(int32_t) * 4);
		SendDataToMaster(send_buf, sizeof(int32_t) * 4 + 2);
		if (turnoff == 1)
		{
			PowerOff();
			osDelay(1000);
		}
#endif

		//osDelay(100);
	}
  /* USER CODE END 5 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
