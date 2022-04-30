/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stdio.h"
#include "string.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"
#include "px31bf.h"

extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart2;


/* USER CODE END PV */
                              
/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void PX31BF_WriteOneByte(uint8_t reg, uint8_t data)
{
	uint16_t write_data = reg | (data << 8);
	if (HAL_I2C_Master_Transmit(&hi2c1, (PX31BF_ADDR << 1) | PX31BF_W, (uint8_t*)&write_data, 2, 300) != HAL_OK)
	{
		Error_Handler();
	}
	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY) ;
}

uint8_t PX31BF_ReadOneByte(uint8_t reg)
{
	uint8_t read_data = 0;
	if (HAL_I2C_Master_Transmit(&hi2c1, (PX31BF_ADDR << 1) | PX31BF_W, (uint8_t*)&reg, 1, 300) != HAL_OK)
	{
		Error_Handler();
	}
	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY) ;
	if (HAL_I2C_Master_Receive(&hi2c1, (PX31BF_ADDR << 1) | PX31BF_R, (uint8_t*)&read_data, 1, 300) != HAL_OK)
	{
		Error_Handler();
	}
	return read_data;
}


uint8_t PX31BF_Init(void)
{
	PX31BF_WriteOneByte(SwRst, 0xEE);            //Software Reset
	PX31BF_WriteOneByte(IntCtrl, 0x03);          //Interrupt control
	HAL_Delay(50);
	PX31BF_WriteOneByte(IntFlag, 0x00);         //Interrupt Flag Status
	HAL_Delay(50);
	PX31BF_WriteOneByte(WaitTime, 0x01);        //Waiting Time
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsCtrl, 0x55);          //PS Bits=10 bit and PS Mean Time is 40ms
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsPuw, 0x0B);           //PsPuw=22 us
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsPuc, 0x02);           //PsPuc=2 Count
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsDrvCtrl, 0x0B);       //PsDrv=12 mA
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsDacCtrl, 0x01);       //PsCtGain=0x01
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsCtCtrl, 0x00);        //PsCtDac=0x00
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsAlgoCtrl, 0x14);      //PsIntAlgo=1 and PsPers=0x04
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsThLowL, 0xC8);        //Low Ps Threshold Low Byte=200
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsThLowH, 0x00);        //Low Ps Threshold High Byte=200
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsThHighL, 0xF4);        //High Ps Threshold Low Byte=500
	HAL_Delay(50);
	PX31BF_WriteOneByte(PsThHighH, 0x01);        //High Ps Threshold High Byte=500
    HAL_Delay(50);
    PX31BF_WriteOneByte(DevCtrl, 0x02);          //Enable PX31BF

}

void PX31BF_Read_PS_Data(uint16_t* ps)
{
	uint8_t ps_l = 0, ps_h = 0;
	ps_l = PX31BF_ReadOneByte(PsDataLow);
	ps_h = PX31BF_ReadOneByte(PsDataHi);
	*ps = (ps_h  << 8) | (ps_l);
	printf("PX31BF PS low =  0x%x\n\r", ps_l);
	printf("PX31BF PS hi =  0x%x\n\r", ps_h);

}

void PX31BF_ReadDataTest()
{
	uint16_t ps=0;
	PX31BF_Read_PS_Data(&ps);
	printf("PX31BF PS =  0x%x\n\r", ps);
}








