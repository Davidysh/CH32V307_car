/*********************************************************************************************************************
 * @file            hf_tim.h
 * @brief           TIMER����
 * @author          FengGuorong
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-18
 ********************************************************************************************************************/


#ifndef HF_TIM_H_
#define HF_TIM_H_

#include "ch32v30x_rcc.h"
#include "ch32v30x_gpio.h"
#include "ch32v30x_tim.h"
#include "ch32v30x_misc.h"

/* ö���������� */

/* ö��TIMER */
typedef enum
{
    TIM_1,
    TIM_2,
    TIM_3,
    TIM_4,
    TIM_5,
    TIM_6,
    TIM_7,
    TIM_8,
    TIM_9,
    TIM_10,
}TIMERN_enum;


/* ö��TIMER�Ĺ��� */
typedef enum
{
    TIMER_FUNCTION_INIT = 0,                                                    // ����δ��ʼ��
    TIMER_FUNCTION_TIMER,                                                       // ���� TIMER ��ʱ
    TIMER_FUNCTION_PIT,                                                         // ���� PIT
    TIMER_FUNCTION_PWM,                                                         // ���� PWM
    TIMER_FUNCTION_ENCODER,                                                     // ���� ENCODER
    TIMER_FUNCTION_CAMERA,                                                      // ���� CAMERA
}timer_function_enum;



/* ö��TIMERͨ�� */
typedef enum
{
    CHANNEL_1 =0,
    CHANNEL_2,
    CHANNEL_3,
    CHANNEL_4,
}TIMERN_CHANNEL_enum;

/* �������� */

/* �ⲿ�������û������е��� */
/* ʱ����ʼ�� */
void timbase_init(TIMERN_enum TIMER_x, uint16_t arr, uint16_t pre);
/* ����ȷ�Ϲ���״̬ */
uint8_t     timer_funciton_check    (TIMERN_enum index, timer_function_enum mode);


#endif /* HF_TIM_H_ */
