/*********************************************************************************************************************
 * @file            delay.h
 * @brief           ��ʱ����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-2
 ********************************************************************************************************************/

#ifndef __delay_h
#define __delay_h

#include "common.h"

/* ��������  */

/* �ⲿ�������û������е���  */
/* ��ʱ��ʼ��  */
void Delay_Init(void);
/* us����ʱ */
void Delay_Us (uint32_t n);
/* ms����ʱ */
void Delay_Ms (uint32_t n);


#endif


