/*********************************************************************************************************************
 * @file            hf_pwm.h
 * @brief           PWM����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-11
 ********************************************************************************************************************/

#ifndef HF_PWM_H_
#define HF_PWM_H_

#include "ch32v30x_rcc.h"
#include "ch32v30x_gpio.h"
#include "ch32v30x_tim.h"
#include "hf_gpio.h"
#include "hf_tim.h"

/* �궨�� */
#define PWM_DUTY_MAX 10000

/* ö�����Ͷ��� */
/* ö��PWMͨ�� */
typedef enum
{
    //ͬһ��PWMPģ�鲻ͬͨ��ֻ�������ͬƵ�ʵ�PWM��ռ�ձȿ����ò�ͬ
    //����PWM1_CH1_PA8��PWM1_CH3_PA10����ͬһ����ģ�飬Ƶ��ֻ��һ��������ռ�ձȿ��Բ�һ��

    //----------------PWM1----------------
    //����ΪTIM1��PWM��һ��ͨ����������ͨ�����á�
    //���磺PWM1_PWM_CH2_PA9��PWM1_PWM_CH1N_PB13����ͬʱʹ�á�
    TIM1_PWM_CH1_A8 = 0x0000,
    TIM1_PWM_CH2_A9,
    TIM1_PWM_CH3_A10,
    TIM1_PWM_CH4_A11,

    //��ӳ��
    TIM1_PWM_CH1_E9 = 0x0010,
    TIM1_PWM_CH2_E11,
    TIM1_PWM_CH3_E13,
    TIM1_PWM_CH4_E14,

    //----------------PWM2----------------
    //����ΪTIM2��PWM��һ��ͨ����������ͨ�����á�
    //���磺PWM2_PWM_CH1_A15��PWM2_PWM_CH3_A2����ͬʱʹ�á�
    TIM2_PWM_CH1_A0 = 0x0100,
    TIM2_PWM_CH2_A1,
    TIM2_PWM_CH3_A2,
    TIM2_PWM_CH4_A3,

    //����ΪTIM2��PWM��һ��ͨ����������ͨ�����á�
    TIM2_PWM_CH1_A15 = 0x0110,     //��ȫӳ��
    TIM2_PWM_CH2_B3,               //��ȫӳ��
    TIM2_PWM_CH3_B10,              //��ȫӳ��,����������
    TIM2_PWM_CH4_B11,              //��ȫӳ��,����������

    //----------------PWM3----------------
    ///����ΪTIM3��PWM��һ��ͨ����������ͨ�����á�
    //���磺PWM3_PWM_CH1_PA6��PWM3_PWM_CH4_C9����ͬʱʹ�á�
    TIM3_PWM_CH1_A6 = 0x0200,
    TIM3_PWM_CH2_A7,
    TIM3_PWM_CH3_B0,
    TIM3_PWM_CH4_B1,

    //����ΪTIM3��PWM��һ��ͨ����������ͨ�����á�
    TIM3_PWM_CH1_C6 = 0x0210,      //��ȫӳ��
    TIM3_PWM_CH2_C7,               //��ȫӳ��
    TIM3_PWM_CH3_C8,               //��ȫӳ��
    TIM3_PWM_CH4_C9,               //��ȫӳ��

    //����ΪTIM3��PWM��һ��ͨ����������ͨ�����á�
    TIM3_PWM_CH1_B4 = 0x0220,      //����ӳ��
    TIM3_PWM_CH2_B5,               //����ӳ��

    //----------------PWM4----------------
    //����ΪTIM4��PWM��һ��ͨ����
    TIM4_PWM_CH1_B6 = 0x0300,
    TIM4_PWM_CH2_B7,
    TIM4_PWM_CH3_B8,
    TIM4_PWM_CH4_B9,

    //��ӳ��
    TIM4_PWM_CH1_D12 = 0x0310,
    TIM4_PWM_CH2_D13,
    TIM4_PWM_CH3_D14,
    TIM4_PWM_CH4_D15,


    //��ʱ��5
    TIM5_PWM_CH1_A0 = 0x0400,
    TIM5_PWM_CH2_A1,
    TIM5_PWM_CH3_A2,
    TIM5_PWM_CH4_A3,

    //��ʱ��8
    TIM8_PWM_CH1_C6 = 0x0700,
    TIM8_PWM_CH2_C7,
    TIM8_PWM_CH3_C8,
    TIM8_PWM_CH4_C9,

    //��ӳ��
    TIM8_PWM_CH1_B6 = 0x0710,
    TIM8_PWM_CH2_B7,
    TIM8_PWM_CH3_B8,
    TIM8_PWM_CH4_C13,

    //��ʱ��9
    TIM9_PWM_CH1_A2 = 0x0800,
    TIM9_PWM_CH2_A3,
    TIM9_PWM_CH3_A4,
    TIM9_PWM_CH4_C4,

    //��ӳ��
    TIM9_PWM_CH1_D9 = 0x0810,
    TIM9_PWM_CH2_D11,
    TIM9_PWM_CH3_D13,
    TIM9_PWM_CH4_D15,

    //��ʱ��10
    TIM10_PWM_CH1_B8 = 0x0900,
    TIM10_PWM_CH2_B9,
    TIM10_PWM_CH3_C3,
    TIM10_PWM_CH4_C11,

    //�ض���һ
    TIM10_PWM_CH1_D1 = 0x0910,
    TIM10_PWM_CH2_D3,
    TIM10_PWM_CH3_D5,
    TIM10_PWM_CH4_D7,

    //�ض����
    TIM10_PWM_CH1_B3 = 0x0920,
    TIM10_PWM_CH2_B4,
    TIM10_PWM_CH3_B5,
    TIM10_PWM_CH4_C15,


}PWMCH_enum;

/* �������� */

/* �ⲿ�������û������е��� */
/* PWM��ʼ�� */
void pwm_init(PWMCH_enum pwmch, uint32 freq, uint32 duty, uint16_t TIM_OCPreload_Enable_Disable);
/* PWMռ�ձ��趨 */
void pwm_duty(PWMCH_enum pwmch, uint32 duty);
/* PWMƵ���趨 */
void pwm_freq(PWMCH_enum pwmch, uint32 freq,uint32_t duty);
/* PWMֹͣ��� */
void pwm_stop(PWMCH_enum pwmch);

/* �ڲ��������û������ע */
/* PWM���ų�ʼ�� */
void pwm_gpio_init(PWMCH_enum pwmch);

#endif /* HF_PWM_H_ */
