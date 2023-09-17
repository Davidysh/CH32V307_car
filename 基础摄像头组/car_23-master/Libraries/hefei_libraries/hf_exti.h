/*********************************************************************************************************************
 * @file            hf_exti.h
 * @brief           EXTI����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-27
 ********************************************************************************************************************/

#ifndef _hf_exti_h
#define _hf_exti_h

#include "headfile.h"

/* ö���жϴ�����ʽ */
typedef enum
{
    RISING = 0x08,
    FALLING = 0x0C,
    BOTH = 0x10
}TRIGGER_enum;

/* �������� */

/* �ⲿ�������û������е��� */
/* ���������ⲿ�ж� */
void exti_enable(uint32 exti_line_num, gpio_pin_enum pin,TRIGGER_enum trigger);
/* �ر������ⲿ�ж� */
void exti_disable(gpio_pin_enum pin);

#endif
