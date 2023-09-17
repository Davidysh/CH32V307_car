/*********************************************************************************************************************
 * @file            hf_encoder.h
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-5
 ********************************************************************************************************************/

#ifndef _hf_encoder_h
#define _hf_encoder_h

#include "hf_gpio.h"
#include "hf_tim.h"

/* ö�ٱ��������� */
typedef enum
{
    TIMER1_CHA_A8,
    TIMER1_CHB_A9,

    TIMER2_CHA_A0,
    TIMER2_CHB_A1,

    TIMER3_CHA_A6,
    TIMER3_CHB_A7,

    TIMER4_CHA_B6,
    TIMER4_CHB_B7,

}ENCODER_PIN_enum;

/* �������� */

/* �ⲿ�������û������е���  */
/* ��������ʼ�� */
void encoder_init(TIMERN_enum TIMER_x, ENCODER_PIN_enum phaseA, ENCODER_PIN_enum phaseB);
/* ��ȡ��ʱ������ֵ */
int encoder_cnt_get(TIMERN_enum TIMER_x);
/* �����ʱ������ֵ */
void encoder_cnt_clear(TIMERN_enum TIMER_x);

/* �ڲ��������û������ע */
/* ���������ų�ʼ�� */
void encoder_gpio_init(ENCODER_PIN_enum phaseA, ENCODER_PIN_enum phaseB);

#endif
