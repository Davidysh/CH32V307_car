/*********************************************************************************************************************
* @file             board.h
* @brief            ѧϰ�����������ʼ��
* @author           Fantastic Potato
* @version          1.0
* @Target core      CH32V307VCT6
* @date             2022-3-3
********************************************************************************************************************/

#ifndef BOARD_BOARD_H_
#define BOARD_BOARD_H_

#include "headfile.h"

/* �궨�� */
#define PRINTF_ENABLE           1                   //printfʹ��
#define DEBUG_UART              UART_3              //DEBUG����
#define DEBUG_UART_BAUD         115200              //DEBUG���ڲ�����
#define DEBUG_UART_TX_PIN       UART3_TX_B10        //DEBUG����TX����
#define DEBUG_UART_RX_PIN       UART3_RX_B11        //DEBUG����RX����


/* �������� */

/* �ⲿ�������û������е��� */
void board_init(void);

#endif /* BOARD_BOARD_H_ */
