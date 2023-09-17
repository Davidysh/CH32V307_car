/*********************************************************************************************************************
* @file            HF_L9110S_2.c
* @author
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220905
********************************************************************************************************************/

#include <HF_Double_DC_Motor.h>

//-------------------------------------------------------------------------------------------------------------------
// @brief        PWM��ʼ��
// @param        object            ���ƶ���
// @return       void
// Sample usage:        motor_init(left);
                        //��ʼ������PWM
//-------------------------------------------------------------------------------------------------------------------
void motor_init(left_or_right object)
{
    if(object == left)
    {
        pwm_init(L_PWM_F, 180000, 0, TIM_OCPreload_Enable);
        pwm_init(L_PWM_B, 180000, 0, TIM_OCPreload_Enable);
    }

    else if(object == right)
    {
        pwm_init(R_PWM_F, 180000, 0, TIM_OCPreload_Disable);
        pwm_init(R_PWM_B, 180000, 0, TIM_OCPreload_Disable);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���Ƶ����ת
// @param        object            ���ƶ���
// @param        value             PWMռ�ձ�(0-10000)
// @return       void
// Sample usage:        motor_forward(right, 10000);
                        //�ҵ��������ת(10000/10000)
//-------------------------------------------------------------------------------------------------------------------
void motor_forward(left_or_right object, uint16 value)
{
    if(object == left)
    {
        pwm_duty(L_PWM_F, value);
        pwm_duty(L_PWM_B, 0);
    }

    else if(object == right)
    {
        pwm_duty(R_PWM_F, value);
        pwm_duty(R_PWM_B, 0);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���Ƶ����ת
// @param        object            ���ƶ���
// @param        value             PWMռ�ձ�(0-10000)
// @return       void
// Sample usage:        motor_back(left, 10000)��
                        //�������ٷ�ת(10000/10000)
//-------------------------------------------------------------------------------------------------------------------
void motor_back(left_or_right object, uint16 value)
{
    if(object == left)
    {
        pwm_duty(L_PWM_F, 0);
        pwm_duty(L_PWM_B, value);
    }

    else if(object == right)
    {
        pwm_duty(R_PWM_F, 0);
        pwm_duty(R_PWM_B, value);
    }
}


