/*********************************************************************************************************************
 * @file            hf_exti.c
 * @brief           EXTI����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-27
 ********************************************************************************************************************/

#include "hf_exti.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���������ⲿ�ж�
// @param        pin         ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
// @param        exti_mode              �жϵ�ģʽ��ֻ��ѡ�����²�����
//  @arg          CHANGE:                ��ƽ�ı䴥��
//  @arg          RISING:                �����ش���
//  @arg          FALLING:               �½��ش���
// @return       void
// Sample usage:            exti_enable(EXTI_Line0,A0, RISING);//����PA0�ⲿ�жϣ�ģʽΪ��ƽ�����ش���
                            //ע���޷�ͬʱ����ͬһ���������ⲿ�жϣ���PA0��PB0��;;;�����жϵ�IO���ʼ��Ϊ����ģʽ
//-------------------------------------------------------------------------------------------------------------------
void exti_enable(uint32 exti_line_num, gpio_pin_enum pin,TRIGGER_enum trigger)
{
    //GPIO �ⲿ�жϳ�ʼ��

    EXTI_InitTypeDef EXTI_InitStructure={0};  //EXTI��ʼ���ṹ��
//    NVIC_InitTypeDef NVIC_InitStructure={0};  //NVIC��ʼ���ṹ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);  //ʹ��AFIO����ʱ��

    gpio_init(pin, GPI, 1, IN_PULLUP);
    GPIO_EXTILineConfig(pin >> 5, pin & 0x1F);


    EXTI_InitStructure.EXTI_Line= 1 << (pin & 0x1F);     //����EXTI�ṹ��
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = trigger;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    if((pin&0x1F) < 1)
       interrupt_enable(EXTI0_IRQn);                                             // ʹ�� Line0 ���ж���Ӧ
    else if((pin&0x1F) < 2)
       interrupt_enable(EXTI1_IRQn);                                             // ʹ�� Line1 ���ж���Ӧ
    else if((pin&0x1F) < 3)
       interrupt_enable(EXTI2_IRQn);                                             // ʹ�� Line2 ���ж���Ӧ
    else if((pin&0x1F) < 4)
       interrupt_enable(EXTI3_IRQn);                                             // ʹ�� Line3 ���ж���Ӧ
    else if((pin&0x1F) < 5)
       interrupt_enable(EXTI4_IRQn);                                             // ʹ�� Line4 ���ж���Ӧ
    else if((pin&0x1F) < 10)
       interrupt_enable(EXTI9_5_IRQn);                                           // ʹ�� Line5-9 ���ж���Ӧ
    else
       interrupt_enable(EXTI15_10_IRQn);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���������ⲿ�ж�
// @param        pin         ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
// @return       void
// Sample usage:        exti_disable(A0);
                        //�ر�����PX0���ⲿ�жϣ�X=A��B��C��F��
//-------------------------------------------------------------------------------------------------------------------
void exti_disable(gpio_pin_enum pin)
{
    EXTI->INTENR &= ~(1 << (pin & 0x1F));
}

