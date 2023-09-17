/*********************************************************************************************************************
 * @file            hf_pit.c
 * @brief           PIT����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-17
 ********************************************************************************************************************/

#include "hf_pit.h"

/* �����ⲿ���� */
extern const uint32 TIMERN[];

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ʱ�������ж�(ms)
//  @param      timern      ��ʱ��ͨ��
//  @param      ms          ��ʱ����(1-32767)
//  @return     void
//  Sample usage:           timer_pit_interrupt(TIMER_1, 5); ʹ�ö�ʱ��1��Ϊ5msһ�ε������ж�
//-------------------------------------------------------------------------------------------------------------------
void timer_pit_interrupt_ms(TIMERN_enum TIMER_x, uint16 ms)
{
    const uint32_t  irq_index[10] =
    {
        TIM1_UP_IRQn, TIM2_IRQn, TIM3_IRQn, TIM4_IRQn,
        TIM5_IRQn, TIM6_IRQn, TIM7_IRQn, TIM8_UP_IRQn,
        TIM9_UP_IRQn, TIM10_UP_IRQn
    };
    /* ��ʱ��TIM��ʼ��,������ */
    assert(ms);

    uint16 arr, pre;
    arr = sys_clk/1640 - 1;
    pre = 2*ms - 1;

    timbase_init(TIMER_x, arr, pre);

    TIM_ITConfig((TIM_TypeDef *)TIMERN[TIMER_x],TIM_IT_Update,ENABLE );      //ʹ��ָ����TIM�ж�,��������ж�
    TIM_ClearITPendingBit((TIM_TypeDef *)TIMERN[TIMER_x], TIM_IT_Update);

    interrupt_set_priority((IRQn_Type)irq_index[(uint8_t)TIMER_x], 0x03);                    // �����ж����ȼ�
    interrupt_enable((IRQn_Type)irq_index[TIMER_x]);                                // ʹ���ж�

    TIM_Cmd((TIM_TypeDef*)TIMERN[TIMER_x], ENABLE);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ʱ�������ж�(us)
//  @param      timern      ��ʱ��ͨ��
//  @param      us          ��ʱ����(1-65535)
//  @return     void
//  Sample usage:           timer_pit_interrupt(TIMER_1, 5); ʹ�ö�ʱ��1��Ϊ5msһ�ε������ж�
//-------------------------------------------------------------------------------------------------------------------
void timer_pit_interrupt_us(TIMERN_enum TIMER_x, uint16 us)
{
    const uint32_t  irq_index[10] =
    {
        TIM1_UP_IRQn, TIM2_IRQn, TIM3_IRQn, TIM4_IRQn,
        TIM5_IRQn, TIM6_IRQn, TIM7_IRQn, TIM8_UP_IRQn,
        TIM9_UP_IRQn, TIM10_UP_IRQn
    };
    /* ��ʱ��TIM��ʼ��,������ */
    assert(us);

    uint16 arr, pre;
    arr = sys_clk/1000000 - 1;
    pre = us - 1;

    timbase_init(TIMER_x, arr, pre);

    TIM_ITConfig((TIM_TypeDef *)TIMERN[TIMER_x],TIM_IT_Update,ENABLE );      //ʹ��ָ����TIM�ж�,��������ж�
    TIM_ClearITPendingBit((TIM_TypeDef *)TIMERN[TIMER_x], TIM_IT_Update);

    interrupt_set_priority((IRQn_Type)irq_index[(uint8_t)TIMER_x], 0x03);                    // �����ж����ȼ�
    interrupt_enable((IRQn_Type)irq_index[TIMER_x]);

    TIM_Cmd((TIM_TypeDef *)TIMERN[TIMER_x], ENABLE);  //ʹ��TIMx

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ر�PIT��ʱ��
//  @param      timern      ѡ��ģ���ͨ�� (ѡ��Χ ��TIMERN_enumö��ֵ������ȷ��)
//  @return     void
//  Sample usage:           �رն�ʱ���������־λ
//-------------------------------------------------------------------------------------------------------------------
void timer_pit_close(TIMERN_enum TIMER_x)
{
    TIM_DeInit((TIM_TypeDef *)TIMERN[TIMER_x]);
    TIM_Cmd((TIM_TypeDef *)TIMERN[TIMER_x], DISABLE);  //ʧ��TIMx
}
