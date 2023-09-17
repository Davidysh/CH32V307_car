/*********************************************************************************************************************
* @file            main.c
* @brief           Flash����ģ��
* @author          lemon
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-3-2
* �򻺳���д�����ݣ�flash��ȡ���������ݣ�Ȼ����ջ���������ȡ���������ݣ�Ȼ��flash�е�����д�뻺�����������ٶ�ȡ����
********************************************************************************************************************/

/* �û�ͷ�ļ� */
#include "main.h"
/* ȫ�ֱ������� */
extern flash_data_union flash_data_union_buffer[FLASH_DATA_BUFFER_SIZE];// FLASH ���������ݻ�����
unsigned char g_flash_flag;
unsigned char key_value;
int* number;
int* number1;
int a;
/* ������ */
int main(void)
{
    /* �˴�������Ҫ�õ��ľֲ����� */
    extern flash_data_union flash_data_union_buffer[FLASH_DATA_BUFFER_SIZE];               // FLASH ���������ݻ�����
    /* ��ʼ�� */
    uart_init(UART_3, 115200, UART3_TX_B10, UART3_RX_B11);
    board_led_init(LED1);
    key_init(K1);
    key_init(K2);
    key_init(K3);
    key_init(K4);
    printf("This is printf example\r\n"); //���ڲ���
    board_led_on(LED1);//����LED�Ʋ���
    a=36;
    number1=&a;
    g_flash_flag=1;
    while(1)
    {
       if(g_flash_flag==1)
       {
           if(flash_check(FLASH_SECTION_62, FLASH_PAGE_3)==1)                      // �ж��Ƿ�������
           {
               flash_erase_page(FLASH_SECTION_62, FLASH_PAGE_3);                // ������һҳ
           }
           flash_read_page_to_data_buffer(FLASH_SECTION_62, FLASH_PAGE_3);      // �����ݴ� flash ��ȡ��������
           printf("\r\n FLASH_SECTION_INDEX: %d, FLASH_PAGE_INDEX: %d, origin data is :", FLASH_SECTION_62,FLASH_PAGE_3);
           printf("\r\n int32_type : %d", flash_data_union_buffer[2].uint32_type);      // ���������� 2 ��λ�õ������� int32  ��ʽ���
           flash_data_union_buffer[2].int32_type  = -2147483648;                       // �򻺳����� 2 ��λ��д�� int32  ����
           printf("\r\n int32_type : %d", flash_data_union_buffer[2].int32_type);      // ���������� 2 ��λ�õ������� int32  ��ʽ���
           flash_write_page_to_data_buffer(FLASH_SECTION_62, FLASH_PAGE_3);     // ��ָ�� Flash ������ҳ��д�뻺��������
           flash_data_buffer_clear();                                           // ��ջ�����
           printf("\r\n int32_type : %d", flash_data_union_buffer[2].int32_type);      // ���������� 2 ��λ�õ������� int32  ��ʽ���
           flash_read_page_to_data_buffer(FLASH_SECTION_62, FLASH_PAGE_3);      // �����ݴ� flash ��ȡ��������
           printf("\r\n int32_type : %d", flash_data_union_buffer[2].int32_type);      // ���������� 2 ��λ�õ������� int32  ��ʽ���
           uint32 *x;
           uint32 a=2;
           x=&a;
           flash_page_read (FLASH_SECTION_62, FLASH_PAGE_3, (uint32 *)x, 16);
           printf("\r\naֵΪ%p", a);

           printf("\r\n --");//�����޷���ʾ,Ϊ�˱�֤��һ�е�������ʾ���ʼ������
           g_flash_flag=0;
       }
       }

}
