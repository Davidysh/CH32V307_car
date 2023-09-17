/*********************************************************************************************************************
 * @file            hf_pit.h
 * @brief           PIT����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-17
 ********************************************************************************************************************/

#ifndef HF_PIT_H_
#define HF_PIT_H_

#include "hf_nvic.h"
#include "hf_tim.h"


/* �������� */

/* �ⲿ�������û������е��� */
/* ��ʱ�������ж�(ms) */
void timer_pit_interrupt_ms(TIMERN_enum TIMER_x, uint16 ms);
/* ��ʱ�������ж�(us) */
void timer_pit_interrupt_us(TIMERN_enum TIMER_x, uint16 us);
/* �رն�ʱ�� */
void timer_pit_close(TIMERN_enum TIMER_x);

#endif /* HF_PIT_H_ */
