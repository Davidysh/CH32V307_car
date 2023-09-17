/*********************************************************************************************************************
 * @file            hf_adc.h
 * @brief           ADC����
 * @author          FengGuorong
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-8
 ********************************************************************************************************************/


#ifndef HF_ADC_H_
#define HF_ADC_H_

#include "ch32v30x.h"
#include "ch32v30x_adc.h"
#include "ch32v30x_rcc.h"
#include "hf_gpio.h"

/* ö�ٶ������� */
/* ö��ADCͨ�� */
typedef enum        //CH32V307ֻ��һ��ADC�����Է�ʱ�����ںܶ��ͨ������
{
    ADC_IN0_A0 = 0,
    ADC_IN1_A1,
    ADC_IN2_A2,
    ADC_IN3_A3,
    ADC_IN4_A4,
    ADC_IN5_A5,
    ADC_IN6_A6,
    ADC_IN7_A7,
    ADC_IN8_B0,
    ADC_IN9_B1,
    ADC_IN10_C0,
    ADC_IN11_C1,
    ADC_IN12_C2,
    ADC_IN13_C3,
    ADC_IN14_C4,
    ADC_IN15_C5,
}ADCCH_enum;

/* ö��ADCͨ���ֱ��� */
typedef enum
{
    ADC_8BIT = 4,       //8λ�ֱ���
    ADC_10BIT = 2,      //10λ�ֱ���
    ADC_12BIT = 0,      //12λ�ֱ���
}ADCRES_enum;

/* �������� */

/* �ⲿ�������û������е��� */
/* ADC��ʼ�� */
void adc_init(ADCCH_enum ADC_INx_xx);
/* ADCת��һ�� */
uint16 adc_convert(ADCCH_enum ADC_INx_xx, ADCRES_enum resolution);
/* ADCת��N�� */
uint16 adc_mean_filter(ADCCH_enum ADC_INx_xx, ADCRES_enum resolution, uint8 count);

/* �ڲ��������û������ע */
/* ADC���ų�ʼ�� */
void adc_gpio_init(ADCCH_enum ADC_INx_xx);

#endif /* HF_ADC_H_ */
