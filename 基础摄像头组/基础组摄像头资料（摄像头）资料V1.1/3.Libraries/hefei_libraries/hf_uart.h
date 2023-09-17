/*********************************************************************************************************************
 * @file            hf_uart.h
 * @brief           UART����
 * @author          FengGuorong
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-10
 ********************************************************************************************************************/

#ifndef HF_UART_H_
#define HF_UART_H_

#include "common.h"
#include "ch32v30x.h"
#include "ch32v30x_misc.h"
#include "ch32v30x_gpio.h"
#include "ch32v30x_rcc.h"
#include "ch32v30x_usart.h"
#include "hf_gpio.h"
#include "hf_nvic.h"

/* ö�����Ͷ��� */
/* ö��UART���� */
typedef enum        //��ʼ����ʱ�򣬱���ʹ��ͬһ���������磬UART1_TX_A9��UART1_RX_A10��һ������
{
    //----------UART1-----------//
    UART1_TX_A9  = 0x00,    UART1_RX_A10,   //  Ĭ������
    UART1_TX_B6,            UART1_RX_B7,    //  ��ӳ��
    //UART1_TX_B15,
    //----------UART2-----------//
    UART2_TX_A2  = 0x10,    UART2_RX_A3,    //  Ĭ������
    UART2_TX_D5,            UART2_RX_D6,    //  ��ӳ��

    //----------UART3-----------//
    UART3_TX_B10 = 0x20,    UART3_RX_B11,   //  Ĭ������
    UART3_TX_C10,           UART3_RX_C11,   //  ������ӳ��
    UART3_TX_D8,            UART3_RX_D9,    //  ��ȫ��ӳ��

    //----------UART4-----------//
    UART4_TX_C10 = 0x40,    UART4_RX_C11,   //  Ĭ������
    UART4_TX_B0,            UART4_RX_B1,

    //----------UART5-----------//
    UART5_TX_C12 = 0x50,    UART5_RX_D2,    //  Ĭ������
    UART5_TX_E8,            UART5_RX_E9,
    //----------UART6-----------//
    UART6_TX_C0  = 0x60,    UART6_RX_C1,    //  Ĭ������
    UART6_TX_E10,           UART6_RX_E11,
    //----------UART7-----------//
    UART7_TX_C2  = 0x70,    UART7_RX_C3,    //  Ĭ������
    UART7_TX_A6,            UART7_RX_A7,
    UART7_TX_E12,           UART7_RX_E13,
    //----------UART8-----------//
    UART8_TX_C4  = 0x80,    UART8_RX_C5,     //  Ĭ������
    UART8_TX_E14,           UART8_RX_E15,
    //8������ ֻ��123��Ӳ��RTS CTS���� 45678û��
}UARTPIN_enum;

/* ö��UART */
typedef enum
{
    UART_1 = 0,
    UART_2,
    UART_3,
    UART_4,
    UART_5,
    UART_6,
    UART_7,
    UART_8
}UARTN_enum;

/* ö��UART�жϷ�ʽ */
typedef enum
{
    UARTINT_RX = 0,
    UARTINT_TX,
    UARTINT_BOTH
}UARTNINT_enum;

/* �������� */

/* �ⲿ�������û������е��� */
/* ���ڳ�ʼ�� */
void uart_init(UARTN_enum UART_x, uint32 baud, UARTPIN_enum tx_pin, UARTPIN_enum rx_pin);
/* ���ڷ���һ���ֽ� */
void uart_putchar(UARTN_enum UART_x, uint8 dat);
/* ���ڷ������� */
void uart_putbuff(UARTN_enum UART_x, uint8 *buff, uint32 len);
/* ���ڷ����ַ��� */
void uart_putstr(UARTN_enum UART_x, const uint8 *str);
/* ��ȡ���ڽ��յ����ݣ���ѯ���գ� */
uint8 uart_getchar(UARTN_enum UART_x);
/* ��ȡ���ڽ��յ����ݣ�whlie�ȴ��� */
uint8 uart_query(UARTN_enum UART_x, uint8 *dat);
/* �򿪴��ڷ��ͽ����ж� */
void uart_interrupt_init(UARTN_enum UART_x,uint8 status, UARTNINT_enum UARTINT_xx);

/* �ڲ��������û������ע */
/* �������ų�ʼ�� */
void uart_gpio_init(UARTPIN_enum tx_pin, UARTPIN_enum rx_pin);


#endif /* HF_UART_H_ */
