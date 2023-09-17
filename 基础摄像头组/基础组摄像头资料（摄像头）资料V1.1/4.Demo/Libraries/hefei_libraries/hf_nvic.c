/*********************************************************************************************************************
 * @file            hf_nvic.c
 * @brief           NVIC����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-4
 ********************************************************************************************************************/

#include "hf_nvic.h"
//static uint32 interrupt_nest_count = 0;
//-------------------------------------------------------------------------------------------------------------------
// @brief       ָ���ж�ʹ��
// @param       irqn            ָ���жϺ� �ɲ鿴 isr.c ��Ӧ�жϷ������ı�ע
// @return      void
// Sample usage:                interrupt_enable(UART1_IRQn);
//-------------------------------------------------------------------------------------------------------------------
void interrupt_enable (IRQn_Type irqn)
{
    NVIC_EnableIRQ(irqn);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ָ���ж�����
// @param       irqn            ָ���жϺ� �ɲ鿴 isr.c ��Ӧ�жϷ������ı�ע
// @return      void
// Sample usage:                interrupt_disable(UART1_IRQn);
//-------------------------------------------------------------------------------------------------------------------
void interrupt_disable (IRQn_Type irqn)
{
    NVIC_DisableIRQ(irqn);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ָ���ж��������ȼ�
// @param       irqn            ָ���жϺ� �ɲ鿴 isr.c ��Ӧ�жϷ������ı�ע
// @param       priority        �ж����ȼ� 0-7 Խ��Խ��
// @return      void
// Sample usage:                interrupt_enable(UART1_IRQn, 0);
//-------------------------------------------------------------------------------------------------------------------
void interrupt_set_priority (IRQn_Type irqn, uint8_t priority)
{
    NVIC_SetPriority(irqn, priority);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       �ж����ʼ�� clock_init �ڲ�����
// @param       void
// @return      void
// Sample usage:                interrupt_init();
//-------------------------------------------------------------------------------------------------------------------
void interrupt_init (void)
{
    //NVIC_SetPriorityGrouping(4);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ȫ���ж�ʹ��
// @param       void
// @return      void
// Sample usage:                interrupt_global_enable ();
//-------------------------------------------------------------------------------------------------------------------
void interrupt_global_enable ()
{
//    extern void en_interrupt();
//    en_interrupt();

}

////-------------------------------------------------------------------------------------------------------------------
//// @brief       ȫ���ж�����
//// @param       void
//// @return      void
//// Sample usage:                interrupt_disable_all();
////-------------------------------------------------------------------------------------------------------------------
//uint32_t interrupt_disable_all (void)
//{
//    uint32_t temp;
//    extern void dis_interrupt();
//    dis_interrupt();
//    temp = __get_MSTATUS();
//    //���ص�ǰmstatus�Ĵ�����ֵ
//    return temp;
//}
//-------------------------------------------------------------------------------------------------------------------
// @brief       ȫ���ж�����
// @param       void
// @return      void
// Sample usage:                interrupt_global_disable ();
//-------------------------------------------------------------------------------------------------------------------
void interrupt_global_disable ()
{
//    if(!interrupt_nest_count)
//    {
//        extern void dis_interrupt();
//        dis_interrupt();
//    }
//    interrupt_nest_count++;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �жϳ�ʼ��
//  @param      irqn                        �жϺţ����Բ鿴CH32V30x.h�ļ��е�IRQn_Typeö���嶨��
//  @param      preemption_priority         ��ռ���ȼ�ֵԽС�����ȼ�Խ�� (��ѡ����0-7�����0�����7)
//  @param      sub_priority                �����ȼ�ֵԽС�����ȼ�Խ��     (��ѡ����0-7�����0�����7)
//  @param      status                      ʹ�ܻ���ʧ��
//  @return     void
//  Sample usage:                           nvic_init(EXTI0_IRQn,0, 0, ENABLE); //�ⲿ�ж�0ʹ��,��ռ���ȼ���ߣ������ȼ���ߡ�
//-------------------------------------------------------------------------------------------------------------------
void nvic_init(IRQn_Type irqn, uint8_t preemption_priority, uint8_t sub_priority, uint8_t status)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = irqn;                                  //�жϺ�����
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=preemption_priority;   //��ռ���ȼ�ֵԽС�����ȼ�Խ��
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = sub_priority;               //�����ȼ�ֵԽС�����ȼ�Խ��
    NVIC_InitStructure.NVIC_IRQChannelCmd = status;                             //ʹ��
    NVIC_Init(&NVIC_InitStructure);

}

