/*********************************************************************************************************************
 * @file            hf_nvic.h
 * @brief           NVIC����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-4
 ********************************************************************************************************************/

#ifndef HF_NVIC_H_
#define HF_NVIC_H_

#include "common.h"
#include "stdint.h"
#include "ch32v30x.h"
#include "ch32v30x_misc.h"


/* ��������*/

/* �ⲿ�������û������е��� */
/* �жϳ�ʼ�� */
void        interrupt_init              (void);
/* �����ж� */
void        interrupt_global_enable     (void);
/* �ر����ж� */
void        interrupt_global_disable    (void);
/* ʹ���ж� */
void        interrupt_enable            (IRQn_Type irqn);
/* ʧ���ж� */
void        interrupt_disable           (IRQn_Type irqn);
/* �����ж����ȼ� */
void        interrupt_set_priority      (IRQn_Type irqn, uint8_t priority);

void nvic_init(IRQn_Type irqn, uint8_t preemption_priority, uint8_t sub_priority, uint8_t status);

#endif /* HF_NVIC_H_ */
