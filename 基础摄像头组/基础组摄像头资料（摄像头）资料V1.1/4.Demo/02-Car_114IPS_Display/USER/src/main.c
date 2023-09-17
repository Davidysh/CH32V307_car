/*********************************************************************************************************************
* @file            main.c
* @brief           1.14��IPS��Ļ����
* @author          FantasticPotato
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-9-19
*
********************************************************************************************************************/

/* �û�ͷ�ļ� */
#include "main.h"
#include "headfile.h"

/* ȫ�ֱ������� */

/* ������ */
int main(void)
{
    /* �˴�������Ҫ�õ��ľֲ����� */

    /* ���ܳ���ʼ�� */
    car_init();

    /* �˴���д�������еĴ���(���磺��ʼ�������) */
    ips114_init();

    while(1)
    {
        /* �˴���д��Ҫѭ��ִ�еĴ��� */
        ips114_full(RGB565_RED);
        ips114_show_string(50, 50, "DEMO");
        Delay_Ms(1000);

        ips114_full(RGB565_YELLOW);
        ips114_show_string(50, 50, "DEMO");
        Delay_Ms(1000);

        ips114_full(RGB565_BLUE);
        ips114_show_string(50, 50, "DEMO");
        Delay_Ms(1000);

        ips114_full(RGB565_GREEN);
        ips114_show_string(50, 50, "DEMO");
        Delay_Ms(1000);

        ips114_clear();
        ips114_show_string(50, 50, "DEMO");
        Delay_Ms(1000);


    }
}





