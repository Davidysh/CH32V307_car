/*********************************************************************************************************************
 * @file            hf_tim.c
 * @brief           TIMER����
 * @author          FengGuorong
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-2
 ********************************************************************************************************************/

#include "hf_tim.h"

/* �ڲ��������� */
const uint32_t TIMERN[] = {TIM1_BASE, TIM2_BASE, TIM3_BASE, TIM4_BASE,TIM5_BASE, TIM8_BASE, TIM9_BASE, TIM10_BASE};

// �������ֹ�޸ģ��ڲ�ʹ���û��������
static timer_function_enum timer_function_state[10] =
{
    TIMER_FUNCTION_INIT, TIMER_FUNCTION_INIT,
    TIMER_FUNCTION_INIT, TIMER_FUNCTION_INIT,
    TIMER_FUNCTION_INIT, TIMER_FUNCTION_INIT,
    TIMER_FUNCTION_INIT, TIMER_FUNCTION_INIT,
    TIMER_FUNCTION_INIT, TIMER_FUNCTION_INIT
};

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ʱ����ʼ��
//  @param      index     ѡ��ʱ��(��ѡ��Χ��hf_tim.h��TIMERN_enumö��ֵȷ��)
//  @param      arr         ����ֵ
//  @param      pre         ��Ƶϵ��
//  @return     void
//  Sample usage:           timbase_init(TIMER_2, 44000, 1);
//                          //ʱ����ʼ��Ϊ��ʱ��2,����ֵΪ44000,Ƶ��Ϊ1MHz
//-------------------------------------------------------------------------------------------------------------------
void timbase_init(TIMERN_enum index, uint16_t arr, uint16_t pre)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

    if(TIM_1 == index)
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);//ʹ�ܶ�ʱ��1��ʱ��
    else  if(TIM_2 == index)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//ʹ�ܶ�ʱ��2��ʱ��
    else  if(TIM_3 == index)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//ʹ�ܶ�ʱ��3��ʱ��
    else  if(TIM_4 == index)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//ʹ�ܶ�ʱ��4��ʱ��
    else  if(TIM_5 == index)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);//ʹ�ܶ�ʱ��5��ʱ��
    else  if(TIM_5 == index)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);//ʹ�ܶ�ʱ��6��ʱ��
    else  if(TIM_5 == index)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);//ʹ�ܶ�ʱ��7��ʱ��
    else  if(TIM_8 == index)
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);//ʹ�ܶ�ʱ��8��ʱ��
    else  if(TIM_9 == index)
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);//ʹ�ܶ�ʱ��9��ʱ��
    else  if(TIM_10== index)
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10,ENABLE);//ʹ�ܶ�ʱ��10��ʱ��


    TIM_TimeBaseStructure.TIM_Period = arr;                    //����44000
    TIM_TimeBaseStructure.TIM_Prescaler = pre;                      //����Ϊ1MHZ����һ��,Ҳ����1us����һ��
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;             //TIM���ϼ���ģʽ
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;                        //�ظ�����������Ϊ0
    TIM_TimeBaseInit((TIM_TypeDef *)TIMERN[index], &TIM_TimeBaseStructure);//����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       TIMER ����ȷ�Ϲ���״̬ ���ڲ�����
// @param       index           TIMER ����ģ���
// @param       mode            ��Ҫȷ�ϵĹ���ģ��
// @return      uint8_t         1-����ʹ�� 0-������ʹ��
// Sample usage:                zf_assert(timer_funciton_check(TIM_1, TIMER_FUNCTION_PWM);
//-------------------------------------------------------------------------------------------------------------------
uint8_t timer_funciton_check (TIMERN_enum index, timer_function_enum mode)
{
    if(timer_function_state[index] == TIMER_FUNCTION_INIT)
        timer_function_state[index] = mode;
    else if(timer_function_state[index] == mode)
        return 1;
    else
        return 0;
    return 1;
}


