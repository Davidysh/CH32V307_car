/*********************************************************************************************************************
 * @file            hf_i2c_hardware.h
 * @brief           Ӳ��IIC����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-5
 ********************************************************************************************************************/
#ifndef HF_I2C_HARDWARE_H_
#define HF_I2C_HARDWARE_H_

#include "ch32v30x_gpio.h"
#include "ch32v30x_i2c.h"
#include "ch32v30x_rcc.h"
#include "hf_gpio.h"

/* �궨�� */
/* I2C Mode Definition */
#define HOST_MODE    0
#define SLAVE_MODE   1

/* I2C Communication Mode Selection */
#define I2C_MODE   HOST_MODE
//#define I2C_MODE   SLAVE_MODE

/* DATA ADDRESS Length Definition */
#define Address_8bit  0
#define Address_16bit  1

/* DATA ADDRESS Length Selection */
#define Address_Lenth   Address_8bit
//#define Address_Lenth   Address_16bit

/* I2C ClockSpeed Definition */
#define I2C_CLOCKSPEED 400000

#define I2C_PAGE_SIZE         8

/* �������Ͷ��� */
#define Hard_Oled 0
#define Hard_Gyro 1
#define Hard_Rtc 2

#define Hard_Device Hard_Rtc


/* �������� */

/* �ⲿ�������û������е��� */
/* Ӳ��I2C��ʼ�� */
void i2c_hardware_init(I2C_TypeDef* I2Cx, u16 address);
/* I2C���͵��ֽ� */
void i2c_send_byte(I2C_TypeDef * I2Cx, uint8_t slave_address, uint8_t data);
/* I2C��Ĵ�����ַд�뵥�ֽ� */
void i2c_send_reg_byte(I2C_TypeDef * I2Cx, uint8_t slave_address, uint8_t reg_address, uint8_t data);
/* I2C��ȡ���ֽ� */
void i2c_read_reg_byte(I2C_TypeDef * I2Cx, uint8_t write_address, uint8_t read_address, uint8_t reg_address, uint8_t *data_buffer);
/* I2C��Ĵ�������д�� */
void i2c_send_reg_bytes(I2C_TypeDef * I2Cx, uint8_t slave_address, uint8_t reg_address, uint8_t *p_buffer, uint16_t length);
/* I2Cд�����飬����д�� */
void i2c_send_reg_buffer(I2C_TypeDef * I2Cx, uint8_t slave_address, uint8_t reg_address, uint8_t *p_buffer, uint16_t number_of_byte);
/* I2C��ȡ���� */
void i2c_read_reg_buffer(I2C_TypeDef * I2Cx, uint8_t write_address, uint8_t read_address, uint8_t reg_address, uint8_t *data_buffer, uint16_t length);



#endif /* HF_I2C_HARDWARE_H_ */
