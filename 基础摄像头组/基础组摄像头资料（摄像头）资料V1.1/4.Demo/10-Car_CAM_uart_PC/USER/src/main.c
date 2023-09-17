/*********************************************************************************************************************
* @file            main.c
* @brief           ����ͷͼ����Ļ��ʾ����
* @author          lemon
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-3-2
*
********************************************************************************************************************/

/* �û�ͷ�ļ� */
#include "main.h"
#include "headfile.h"

/* ȫ�ֱ������� */
void Daimxa_Pc_Display188x120(void)
{   //unsigned char y;
    int i=0;
    int j=0;
    uart_putchar(UART_3,0x00); //����֡ͷ��������UART�ĳ��Լ���
    uart_putchar(UART_3,0xff);//����֡ͷ
    uart_putchar(UART_3,0x01);//����֡ͷ
    uart_putchar(UART_3,0x01);//����֡ͷ
    for(i=0;i<120;i++)//����ͼ������Ϊ188X120
    {
        for(j=0;j<188;j++)
            uart_putchar(UART_3,mt9v03x_image_dvp[i][j]);//�Ҷȣ���ֵ������
        }
//--------------------��ֻ��ͼ�����������д������ɾ��--------------------
   /* for(y = 0; y<120; y++)//���������
        uart_putchar(UART_0,Daimxa_ImageDeal[y].LeftBorder);//�ڶ���������Ϊ����120�ֽڱ�������
    for(y = 0; y<120; y++)//�����ұ���
        uart_putchar(UART_0,Daimxa_ImageDeal[y].RightBorder);
    for(y = 0; y<120; y++)//��������
        uart_putchar(UART_0,Daimxa_ImageDeal[y].Center);
    */
}

/* ������ */
int main(void)
{
    /* �˴�������Ҫ�õ��ľֲ����� */

    /* ���ܳ���ʼ�� */
    car_init();

    /* �˴���д�������еĴ���(���磺��ʼ�������) */
    ips114_init();     //��ʼ����Ļ
    ips114_show_string(0,0,"CAM-IPS");
    ips114_show_string(0,20,"DEMO");
    mt9v03x_init_dvp();

    Delay_Ms(100);
//uart_send_char(UART_3, rx_char);   //����3���ͽ��յ�������
    while(1)
    {
        /* �˴���д��Ҫѭ��ִ�еĴ��� */
        if(mt9v03x_finish_flag_dvp)
        {
            mt9v03x_finish_flag_dvp = 0;
            // ����ԭʼͼ���С,��ʾԭʼͼ��
           // ips114_displayimage032(mt9v03x_image_dvp[0], MT9V03X_DVP_W, MT9V03X_DVP_H);
            Daimxa_Pc_Display188x120();
        }
    }
}





