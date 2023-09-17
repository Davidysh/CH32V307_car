/*********************************************************************************************************************
 * @file            hf_encoder.c
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-5
 ********************************************************************************************************************/

#include "hf_encoder.h"

/* �����ⲿ���� */
extern const uint32 TIMERN[];

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��������ʼ��
//  @param      TIMER_x     ��ʱ��
//  @param      phaseA      ͨ��A�Լ�����
//  @param      phaseB      ͨ��B�Լ�����
//  @return     void
//  Sample usage:           encoder_init(TIMER_2, TIMER2_CHA_A0, TIMER2_CHB_A1)
//                          //��ʱ��ѡ��TIM_2, A���A0, B���A1
//-------------------------------------------------------------------------------------------------------------------
void encoder_init(TIMERN_enum TIMER_x, ENCODER_PIN_enum phaseA, ENCODER_PIN_enum phaseB)
{
    /* GPIO���ų�ʼ�� */
    encoder_gpio_init(phaseA, phaseB);

    /* ʱ����ʼ�� */
    timbase_init(TIMER_x, 65535, 0);

    /* ��������ʼ�� */
    TIM_EncoderInterfaceConfig((TIM_TypeDef *)TIMERN[TIMER_x],              //������ģʽ3
            TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge, TIM_ICPolarity_BothEdge);

    /* ���벶���ʼ�� */
    TIM_ICInitTypeDef TIM_ICInitStructure;
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1 | TIM_Channel_2;        //ѡ��ͨ��1,2
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_BothEdge;           //˫���ز���
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;         //IC1��IC2ֱ��ӳ��ӳ�䵽 TI1��TI2��
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;                   //���������Ƶ,����Ƶ
    TIM_ICInitStructure.TIM_ICFilter = 0;                                   //IC2F=0000 ���������˲��� ���˲�
    TIM_ICInit((TIM_TypeDef *)TIMERN[TIMER_x], &TIM_ICInitStructure);

    TIM_ClearITPendingBit((TIM_TypeDef *)TIMERN[TIMER_x], TIM_IT_Update);   //���TIM���±�־λ
    TIM_ITConfig((TIM_TypeDef *)TIMERN[TIMER_x], TIM_IT_Update, ENABLE);    //ʹ�ܿ���TIM�ж�
    TIM_SetCounter((TIM_TypeDef *)TIMERN[TIMER_x], 0x7fff);                 //��λֵѡ��0x7fff,�Ա��������ת

    TIM_Cmd((TIM_TypeDef *)TIMERN[TIMER_x], ENABLE);                        //ʹ�ܶ�ʱ��
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ȡ��ʱ������ֵ
//  @param      TIMER_x     ��ʱ��
//  @return     ��ʱ������ֵ
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
int encoder_cnt_get(TIMERN_enum TIMER_x)
{
    int count = ((TIM_TypeDef*)(TIMERN[TIMER_x]))->CNT;
    return count;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �����ʱ������ֵ
//  @param      TIMER_x     ��ʱ��
//  @return
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void encoder_cnt_clear(TIMERN_enum TIMER_x)
{
    ((TIM_TypeDef*)(TIMERN[TIMER_x]))->CNT = 0x7fff;                        //��λֵѡ��0x7fff,�Ա��������ת
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ���������ų�ʼ��
//  @param      phaseA      ͨ��A�Լ�����
//  @param      phaseB      ͨ��B�Լ�����
//  @return     void
//  Sample usage:           �ڲ�ʹ�ã��û��������
//-------------------------------------------------------------------------------------------------------------------
void encoder_gpio_init(ENCODER_PIN_enum phaseA, ENCODER_PIN_enum phaseB)
{
    if(TIMER1_CHA_A8 == phaseA)       gpio_init(A8, GPI, 0, IN_FLOAT);
    else if(TIMER2_CHA_A0 == phaseA)  gpio_init(A0, GPI, 0, IN_FLOAT);
    else if(TIMER3_CHA_A6 == phaseA)  gpio_init(A6, GPI, 0, IN_FLOAT);
    else if(TIMER4_CHA_B6 == phaseA)  gpio_init(B6, GPI, 0, IN_FLOAT);

    if(TIMER1_CHB_A9 == phaseB)       gpio_init(A9, GPI, 0, IN_FLOAT);
    else if(TIMER2_CHB_A1 == phaseB)  gpio_init(A1, GPI, 0, IN_FLOAT);
    else if(TIMER3_CHB_A7 == phaseB)  gpio_init(A7, GPI, 0, IN_FLOAT);
    else if(TIMER4_CHB_B7 == phaseB)  gpio_init(B7, GPI, 0, IN_FLOAT);
}
