/*********************************************************************************************************************
* @file            HF_HC_SR04.h
* @author          Fantastic Potato
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-9-19
 ********************************************************************************************************************/

#ifndef _HF_HC_SR04_H
#define _HF_HC_SR04_H

#include "headfile.h"

/* ��Դ���� */
#define TRIG         B4
#define ECHO         D9
#define EXTI_NUM     EXTI_9


//��������
/* ��������ʼ�� */
void ultra_init(void);
/* ����������һ�β����ؾ��� */
unsigned int ultra_get_distance(void);

//ȫ�ֱ�������

#endif
