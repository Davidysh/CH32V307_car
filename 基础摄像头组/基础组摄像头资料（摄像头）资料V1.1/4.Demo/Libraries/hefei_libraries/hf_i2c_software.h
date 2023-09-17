/*********************************************************************************************************************
 * @file            hf_i2c_software.h
 * @brief           ���IIC����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-5
 ********************************************************************************************************************/

#ifndef _hf_i2csoftware_h
#define _hf_i2csoftware_h

#include <stdio.h>
#include "hf_gpio.h"
#include "delay.h"

/* �궨�� */

/* IIC���߹涨��IIC����ʱ��SCL��SDA��Ϊ�ߵ�ƽ������ⲿ������һ������������
 * SDA/SCL��GPIO��ʼ������Ϊ��©��� */
#define sim_scl A8
#define sim_sda A11

#define scl_clr() gpio_bit_output(sim_scl, 0)
#define scl_set() gpio_bit_output(sim_scl, 1)

#define sda_clr() gpio_bit_output(sim_sda, 0)
#define sda_set() gpio_bit_output(sim_sda, 1)

#define sda_get()   gpio_get_input(sim_sda)
#define scl_get()   gpio_get_input(sim_scl)

#define delay_time 20                         //�ȴ�ʱ����оƬ�����ֲ�ʱ��ͼȷ��

/* �������� */

/* �ⲿ�������û������е��� */
/* ����дһ���ֽ� */
void i2c_sim_send_byte(uint8 i2c_byte);      //Ĭ�ϸ�λ��ǰ
/* ������һ���ֽ� */
uint8 i2c_sim_read_byte(void);               //Ĭ�ϸ�λ��ǰ
/* I2C��ȡ���ֽ� */
uint8 i2c_sim_read_reg_byte(uint8 write_add, uint8 read_add,uint8 reg_add);
/* I2C��Ĵ���д��һ���ֽ� */
void i2c_sim_write_reg_byte(uint8 write_add, uint8 reg_add, uint8 dat);

/* �ڲ��������û������ע */
/* SDA,SCL�ÿ���״̬ */
void i2c_sim_idle(void);
/* ������ʼ�ź� */
void i2c_sim_start(void);
/* ����ֹͣ�ź� */
void i2c_sim_stop(void);
/* �����ȴ�Ӧ���ź� */
uint8 i2c_sim_waitack(void);
/* ��������Ӧ���ź�ACK */
void i2c_sim_ack(void);
/* ����������Ӧ���ź�NACK */
void i2c_sim_nack(void);

#endif
