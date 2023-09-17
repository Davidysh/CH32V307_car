/*********************************************************************************************************************
* @file            main.c
* @brief           6��������
* @author          lemon
* @version         1.0
* @Target core     CH32V307VCT6
* @date            -2022.9.12, V1.0
* ͨ��4����ģ�����С��β���������ɫ�仯
********************************************************************************************************************/

/* �û�ͷ�ļ� */
#include "main.h"
#include "headfile.h"

/* ȫ�ֱ������� */


/* ������ */
int main(void)
{
    /* �˴�������Ҫ�õ��ľֲ����� */
    unsigned char key_value;

    /* ���ܳ���ʼ�� */
    car_init();

    board_led_init(1);

    /* �˴���д�������еĴ���(���磺��ʼ�������) */
    ips114_init();
    car_both_rgb_off();

    exti_enable(EXTI_Line3, C3, BOTH);
    exti_enable(EXTI_Line4, C4, BOTH);
    exti_enable(EXTI_Line5, C5, BOTH);


    while(1)
    {
        /* �˴���д��Ҫѭ��ִ�еĴ��� */
        key_value = key_check();

        if (key_value != 0xFF)
        {
            if(key_value == 0x01)
            {
                car_both_rgb_on(yellow);  //���°���1��β����ʾ��ɫ
                ips114_show_string(0, 0, "key1");
            }
            else if(key_value == 0x02)
            {
                car_both_rgb_on(red);     //���°���2��β����ʾ��ɫ
                ips114_show_string(0, 0, "key2");
            }
            else if(key_value == 0x03)
            {
                car_both_rgb_on(blue);    //���°���3��β����ʾ��ɫ
                ips114_show_string(0, 0, "key3");
            }

            //����4-6����ʹ���ж�ʵ�֣����isr.c
        }
    }
}
