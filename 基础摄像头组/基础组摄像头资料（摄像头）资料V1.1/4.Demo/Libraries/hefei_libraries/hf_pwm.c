/*********************************************************************************************************************
 * @file            hf_pwm.c
 * @brief           PWM����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-11
 ********************************************************************************************************************/

#include "hf_pwm.h"

/* �����ⲿ���� */
extern const uint32 TIMERN[];

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM��ʼ��
//  @param      pwmch           PWMͨ���ż�����
//  @param      freq            PWMƵ��
//  @param      duty            PWMռ�ձ�
//  @param      TIM_OCPreload_Enable_Disable     Ĭ������ΪTIM_OCPreload_Disable,���ڿ�ɾ�����β�ֻ��Ϊ������RGB�������޸�
//  @return     void
//  Sample usage:               pwm_init(PWM1_CH1_A8, 50, 5000);   //��ʼ��PWM1 ͨ��1 ʹ������A8  ���PWMƵ��50HZ   ռ�ձ�Ϊ�ٷ�֮ 5000/PWM_DUTY_MAX*100
//                              PWM_DUTY_MAX��wh_pwm.h�ļ��� Ĭ��Ϊ10000
//-------------------------------------------------------------------------------------------------------------------
void pwm_init(PWMCH_enum pwmch, uint32 freq, uint32 duty, uint16_t TIM_OCPreload_Enable_Disable)
{
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    uint16 match_temp;                                          //ռ�ձ�ֵ
    uint16 period_temp;                                         //����ֵ
    uint16 freq_div = 0;                                        //��Ƶֵ

    pwm_gpio_init(pwmch);                                       //PWM���ų�ʼ��

    /* ��ȡϵͳ��Ƶ */
    freq_div = (uint16)((SystemCoreClock / freq) >> 16);                            //���ٷ�Ƶ
    period_temp = (uint16)(SystemCoreClock/(freq*(freq_div + 1)));                  //����
    match_temp = period_temp * duty / PWM_DUTY_MAX;                         //ռ�ձ�

    /* ʱ����ʼ�� */
    timbase_init((pwmch >> 8), period_temp - 1, freq_div);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);        //ʹ��AFIO���ù���ģ��ʱ��

    //������ӳ��


    if((pwmch >> 4) == 0x01)      GPIO_PinRemapConfig(GPIO_FullRemap_TIM1, ENABLE);
    else if((pwmch >> 4) == 0x11) GPIO_PinRemapConfig(GPIO_FullRemap_TIM2, ENABLE);
    else if((pwmch >> 4) == 0x21) GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
    else if((pwmch >> 4) == 0x22) GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);
    else if((pwmch >> 4) == 0x31) GPIO_PinRemapConfig(GPIO_Remap_TIM4, ENABLE);
    else if((pwmch >> 4) == 0x71) AFIO->PCFR2 |= 0x01<<2;
    else if((pwmch >> 4) == 0x81) AFIO->PCFR2 |= 0x02<<3;
    else if((pwmch >> 4) == 0x91) AFIO->PCFR2 |= 0x02<<5;
    else if((pwmch >> 4) == 0x92) AFIO->PCFR2 |= 0x01<<5;


    //��ʼ��TIM PWMģʽ
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;                       //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;           //�Ƚ����ʹ��
    TIM_OCInitStructure.TIM_Pulse = match_temp;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;               //�������:TIM����Ƚϼ��Ը�
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;

    if((pwmch & 0x03) == 0x00)                                              //ͨ��ѡ��
    {
        TIM_OC1Init(((TIM_TypeDef *) TIMERN[pwmch>>8]), &TIM_OCInitStructure );                         //��ʱ��ͨ��1��ʼ��
        TIM_CtrlPWMOutputs(((TIM_TypeDef *) TIMERN[pwmch>>8]), ENABLE );
        TIM_OC1PreloadConfig(((TIM_TypeDef *) TIMERN[pwmch>>8]), TIM_OCPreload_Enable_Disable);         //��ʱ��Ԥװ������
    }
    else if((pwmch & 0x03) == 0x01)
    {
        TIM_OC2Init(((TIM_TypeDef *) TIMERN[pwmch>>8]), &TIM_OCInitStructure );
        TIM_CtrlPWMOutputs(((TIM_TypeDef *) TIMERN[pwmch>>8]), ENABLE );
        TIM_OC2PreloadConfig(((TIM_TypeDef *) TIMERN[pwmch>>8]), TIM_OCPreload_Enable_Disable);
    }
    else if((pwmch & 0x03) == 0x02)
    {
        TIM_OC3Init(((TIM_TypeDef *) TIMERN[pwmch>>8]), &TIM_OCInitStructure );
        TIM_CtrlPWMOutputs(((TIM_TypeDef *) TIMERN[pwmch>>8]), ENABLE );
        TIM_OC3PreloadConfig(((TIM_TypeDef *) TIMERN[pwmch>>8]), TIM_OCPreload_Enable_Disable);
    }
    else if((pwmch & 0x03) == 0x03)
    {
        TIM_OC4Init(((TIM_TypeDef *) TIMERN[pwmch>>8]), &TIM_OCInitStructure );
        TIM_CtrlPWMOutputs(((TIM_TypeDef *) TIMERN[pwmch>>8]), ENABLE );
        TIM_OC4PreloadConfig(((TIM_TypeDef *) TIMERN[pwmch>>8]), TIM_OCPreload_Enable_Disable);
    }

    TIM_Cmd(((TIM_TypeDef *) TIMERN[pwmch>>8]), ENABLE);                                              //��ʱ��ʹ��
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWMռ�ձ��趨
//  @param      pwmch           PWMͨ���ż�����
//  @param      duty            PWMռ�ձ�
//  @return     void
//  Sample usage:               pwm_duty(PWM1_CH1_A8, 5000);   //PWM1 ͨ��1 ʹ������A8 ռ�ձ�Ϊ�ٷ�֮ 5000/PWM_DUTY_MAX*100
//                              PWM_DUTY_MAX��wh_pwm.h�ļ��� Ĭ��Ϊ10000
//-------------------------------------------------------------------------------------------------------------------
void pwm_duty(PWMCH_enum pwmch, uint32 duty)
{
    uint16 match_temp;
    uint16 period_temp;

    //��ȡ����ֵ
    //����ռ�ձ�

    period_temp = ((TIM_TypeDef *) TIMERN[pwmch>>8])->ATRLR;    //��ȡ��ʱ��������ֵ
    match_temp = period_temp * duty / PWM_DUTY_MAX;             //ռ�ձ�

    (*(volatile uint32_t*)(TIMERN[pwmch>>8] + 0x34 + (pwmch&0x03) * 0x04)) = match_temp;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWMƵ���趨
//  @param      pwmch           PWMͨ���ż�����
//  @param      freq            PWMƵ��
//  @param      duty            PWMռ�ձ�
//  @return     void
//  Sample usage:               pwm_freq(PWM1_CH1_A8, 60, 5000);   //ʹ������A8  ���PWMƵ��60HZ   ռ�ձ�Ϊ�ٷ�֮ 5000/PWM_DUTY_MAX*100
//                              PWM_DUTY_MAX��wh_pwm.h�ļ��� Ĭ��Ϊ10000
//-------------------------------------------------------------------------------------------------------------------
void pwm_freq(PWMCH_enum pwmch, uint32 freq,uint32_t duty)
{
    uint16 period_temp = 0;                                     //����ֵ
    uint16 freq_div = 0;                                        //��Ƶֵ
    uint16 match_temp;

    freq_div = (uint16)((sys_clk / freq) >> 16);                //������ٷ�Ƶ
    period_temp = (uint16)(sys_clk/(freq*(freq_div + 1)));      //��������

    ((TIM_TypeDef *) TIMERN[pwmch>>8])->ATRLR = period_temp - 1 ;
    ((TIM_TypeDef *) TIMERN[pwmch>>8])->PSC = freq_div;
    match_temp = period_temp * duty / PWM_DUTY_MAX;             //ռ�ձ�

    (*(volatile uint32_t*)(TIMERN[pwmch>>8] + 0x34 + (pwmch&0x03) * 0x04)) = match_temp;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWMֹͣ���
//  @param      pwmch           PWMͨ���ż�����
//  @return     void
//  Sample usage:               pwm_freq(PWM1_CH1_A8, 60, 5000);   //ʹ������A8  ���PWMƵ��60HZ   ռ�ձ�Ϊ�ٷ�֮ 5000/PWM_DUTY_MAX*100
//                              PWM_DUTY_MAX��wh_pwm.h�ļ��� Ĭ��Ϊ10000
//-------------------------------------------------------------------------------------------------------------------
void pwm_stop(PWMCH_enum pwmch)
{
    TIM_Cmd(((TIM_TypeDef *) TIMERN[pwmch>>8]), DISABLE);         //��ʱ��ʧ��
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM���ų�ʼ��
//  @param      pwmch       PWMͨ��(��ѡ��Χ��wh_pwm.h��PWMCH_enumö��ֵȷ��)
//  @return     void
//  Sample usage:           �ڲ�ʹ��  �û��������
//-------------------------------------------------------------------------------------------------------------------
void pwm_gpio_init(PWMCH_enum pwmch)
{
    //-------------------------------PWM1-------------------------------//
         if(pwmch == TIM1_PWM_CH1_A8 )   gpio_init(A8 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM1_PWM_CH2_A9 )   gpio_init(A9 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM1_PWM_CH3_A10)   gpio_init(A10, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM1_PWM_CH4_A11)   gpio_init(A11, GPO, 0, SPEED_50MHZ|OUT_AF_PP);

    else if(pwmch == TIM1_PWM_CH1_E9 )   gpio_init(E9 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM1_PWM_CH2_E11)   gpio_init(E11, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM1_PWM_CH3_E13)   gpio_init(E13, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM1_PWM_CH4_E14)   gpio_init(E14, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    //-------------------------------PWM2-------------------------------//
    else if(pwmch == TIM2_PWM_CH1_A0 )    gpio_init(A0 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM2_PWM_CH2_A1 )    gpio_init(A1 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM2_PWM_CH3_A2 )    gpio_init(A2 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM2_PWM_CH4_A3 )    gpio_init(A3 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);

    else if(pwmch == TIM2_PWM_CH1_A15)    gpio_init(A15, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM2_PWM_CH2_B3 )    gpio_init(B3 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM2_PWM_CH3_B10)    gpio_init(B10, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM2_PWM_CH4_B11)    gpio_init(B11, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    //-------------------------------PWM3-------------------------------//
    else if(pwmch == TIM3_PWM_CH1_A6 )    gpio_init(A6,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM3_PWM_CH2_A7 )    gpio_init(A7,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM3_PWM_CH3_B0 )    gpio_init(B0,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM3_PWM_CH4_B1 )    gpio_init(B1,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);

    else if(pwmch == TIM3_PWM_CH1_C6 )    gpio_init(C6,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM3_PWM_CH2_C7 )    gpio_init(C7,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM3_PWM_CH3_C8 )    gpio_init(C8,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM3_PWM_CH4_C9 )    gpio_init(C9,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);

    else if(pwmch == TIM3_PWM_CH1_B4 )    gpio_init(B4,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM3_PWM_CH2_B5 )    gpio_init(B5,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    //-------------------------------PWM4-------------------------------//
    else if(pwmch == TIM4_PWM_CH1_B6 )    gpio_init(B6,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM4_PWM_CH2_B7 )    gpio_init(B7,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM4_PWM_CH3_B8 )    gpio_init(B8,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM4_PWM_CH4_B9 )    gpio_init(B9,  GPO, 0, SPEED_50MHZ|OUT_AF_PP);

    else if(pwmch == TIM4_PWM_CH1_D12)    gpio_init(D12, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM4_PWM_CH2_D13)    gpio_init(D13, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM4_PWM_CH3_D14)    gpio_init(D14, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM4_PWM_CH4_D15)    gpio_init(D15, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    //-------------------------------PWM5-------------------------------//
    else if(pwmch == TIM5_PWM_CH1_A0 )    gpio_init(A0 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM5_PWM_CH2_A1 )    gpio_init(A1 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM5_PWM_CH3_A2 )    gpio_init(A2 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM5_PWM_CH4_A3 )    gpio_init(A3 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    //-------------------------------PWM8-------------------------------//
    else if(pwmch == TIM8_PWM_CH1_C6 )    gpio_init(C6 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM8_PWM_CH2_C7 )    gpio_init(C7 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM8_PWM_CH3_C8 )    gpio_init(C8 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM8_PWM_CH4_C9 )    gpio_init(C9 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);

    else if(pwmch == TIM8_PWM_CH1_B6 )    gpio_init(B6 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM8_PWM_CH2_B7 )    gpio_init(B7 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM8_PWM_CH3_B8 )    gpio_init(B8 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM8_PWM_CH4_C13)    gpio_init(C13, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    //-------------------------------PWM9-------------------------------//
    else if(pwmch == TIM9_PWM_CH1_A2 )    gpio_init(A2 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM9_PWM_CH2_A3 )    gpio_init(A3 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM9_PWM_CH3_A4 )    gpio_init(A4 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM9_PWM_CH4_C4 )    gpio_init(C4 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);

    else if(pwmch == TIM9_PWM_CH1_D9 )    gpio_init(D9 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM9_PWM_CH2_D11)    gpio_init(D11, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM9_PWM_CH3_D13)    gpio_init(D13, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM9_PWM_CH4_D15)    gpio_init(D15, GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    //-------------------------------PWM10-------------------------------//
    else if(pwmch == TIM10_PWM_CH1_B8 )   gpio_init(B8 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM10_PWM_CH2_B9 )   gpio_init(B9 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM10_PWM_CH3_C3 )   gpio_init(C3 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM10_PWM_CH4_C11)   gpio_init(C11, GPO, 0, SPEED_50MHZ|OUT_AF_PP);

    else if(pwmch == TIM10_PWM_CH1_D1 )   gpio_init(D1 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM10_PWM_CH2_D3 )   gpio_init(D3 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM10_PWM_CH3_D5 )   gpio_init(D5 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM10_PWM_CH4_D7 )   gpio_init(D7 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);

    else if(pwmch == TIM10_PWM_CH1_B3 )   gpio_init(B3 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM10_PWM_CH2_B4 )   gpio_init(B4 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM10_PWM_CH3_B5 )   gpio_init(B5 , GPO, 0, SPEED_50MHZ|OUT_AF_PP);
    else if(pwmch == TIM10_PWM_CH4_C15)   gpio_init(C15, GPO, 0, SPEED_50MHZ|OUT_AF_PP);

}
