/********************************************************************************************************************
* @file            HF_WS2812b.c
* @author
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220905
********************************************************************************************************************/

#include "HF_WS2812b.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief      RGB��ʼ��
//  @param      void
//  @return     void
//  @since      v1.0
//  Sample usage:           ws2812b_init();
//                          //��ʼ��RGB��
//-------------------------------------------------------------------------------------------------------------------
void ws2812b_init()
{
    uint8_t RGB[3] = {0x00,0x00,0x00};

    pwm_init(TIM1_PWM_CH4_A11, 180000, 0, TIM_OCPreload_Disable);
    TIM_OC4PolarityConfig(TIM1, TIM_OCPolarity_Low);

    ws2812b_write(RGB);
    Delay_Us(100);
    ws2812b_write(RGB);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        RGBд��
// @param        GRB             д�������
// @return       void
// Sample usage:        uint8_t RGB[3] = {0xff,0x00,0x00};  ws2812b_write(RGB);
                        //��RGBд�����飬��ʾ��ɫ
//-------------------------------------------------------------------------------------------------------------------
void ws2812b_write(uint8_t* RGB)
{
    unsigned int num, i;
    unsigned char GRB[3] = {0,};

    GRB[0] = RGB[1];
    GRB[1] = RGB[0];
    GRB[2] = RGB[2];
    TIM_SetCounter(((TIM_TypeDef *)TIM1_BASE), 0);

    for(num = 0; num<3; num++)
    {
        for(i = 8; i!=0; i--)
        {
            if((*(GRB+num)>>(i-1))&0x01)
            {
                //������ֵ(�Ƚ�ֵ,����ռ�ձȵ�ʱ��������ֵ)
                pwm_duty(TIM1_PWM_CH4_A11, 8500);/*��1*/
            }
            else
            {
                pwm_duty(TIM1_PWM_CH4_A11, 9500);/*��0*/
            }
            TIM_Cmd(((TIM_TypeDef *)TIM1_BASE), ENABLE);
            while(!TIM_GetFlagStatus(((TIM_TypeDef *)TIM1_BASE), TIM_FLAG_Update));
            TIM_Cmd(((TIM_TypeDef *)TIM1_BASE), DISABLE);
            TIM_ClearFlag(((TIM_TypeDef *)TIM1_BASE), TIM_FLAG_Update);
            TIM_SetCounter(((TIM_TypeDef *)TIM1_BASE), 0);
        }
    }
}


