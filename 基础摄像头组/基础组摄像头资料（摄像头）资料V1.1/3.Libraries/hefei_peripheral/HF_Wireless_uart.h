/********************************************************************************************************************
* @file            HF_Wireless_uart.h
* @author
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220905
********************************************************************************************************************/

#ifndef HF_WIRELESS_UART_H_
#define HF_WIRELESS_UART_H_


#include "headfile.h"

#define WIRELESS_UART_NUMBER       1                                           // �����������ߴ��ڵ����� Ĭ����������
#define WIRELESS_UART_INDEX        UART_2                                      // ���ߴ��� 1 ��Ӧʹ�õĴ��ں�
#define WIRELESS_UART_BUAD_RATE    115200                                      // ���ߴ��� 1 ��Ӧʹ�õĴ��ڲ�����
#define A3                         UART2_RX_A3                                 // ���ߴ��� 1 ��Ӧģ��� TX Ҫ�ӵ���Ƭ���� RX
#define A2                         UART2_TX_A2                                 // ���ߴ��� 1 ��Ӧģ��� RX Ҫ�ӵ���Ƭ���� TX
#define WIRELESS_UART_RTS_PIN      E10                                         // ���ߴ��� 1 ��Ӧģ��� RTS ����


#define WIRELESS_UART_AUTO_BAUD_RATE    0
// ------------------------------------ �Զ������� ------------------------------------

#define WIRELESS_UART_BUFFER_SIZE       64
#define WIRELESS_UART_TIMEOUT_COUNT     0x64


//��������

/*���ߴ��ڷ���һ���ֽ�*/
uint32 wireless_uart_putchar (uint8 data);
/*���ߴ��ڶ�ȡһ���ֽ�*/
uint32 wireless_uart_getchar (uint8 data);
/*���ߴ��ڷ����ַ���*/
uint32 wireless_uart_putbuff ( uint8 *buff, uint32 len);
/*���ߴ��ڷ����ַ���*/
uint32 wireless_uart_putstr ( uint8 *str);
/*���ߴ��ڷ���ͼ��*/
uint8 wireless_uart_putimage ( uint8 *image_addr, uint32 image_size);
/*���ߴ��ڳ�ʼ��*/
uint8 wireless_uart_init (void);


#endif
