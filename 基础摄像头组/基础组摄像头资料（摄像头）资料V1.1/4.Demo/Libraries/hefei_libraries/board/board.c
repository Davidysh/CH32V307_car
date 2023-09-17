/*********************************************************************************************************************
* @file             board.c
* @brief            ѧϰ�����������ʼ��
* @author           Fantastic Potato
* @version          1.0
* @Target core      CH32V307VCT6
* @date             2022-3-3
********************************************************************************************************************/
#include "board.h"

#if (1 == PRINTF_ENABLE)
//-------------------------------------------------------------------------------------------------------------------
//  @brief      ѧϰ���ʼ��
//  @param      void
//  @return     void
//  @since      v1.0
//  Sample usage:              board_init();
//-------------------------------------------------------------------------------------------------------------------
void board_init(void)
{
    //��ȡϵͳ��Ƶ
    sys_clk = 8000000 * (((RCC->CFGR0 >> 18)&0x0F) + 2);
    //��ʼ��DEBUG����
    uart_init(DEBUG_UART, DEBUG_UART_BAUD, DEBUG_UART_TX_PIN, DEBUG_UART_RX_PIN);
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      printf�ض���
//  @param      void
//  @return     void
//  @since      v1.0
//  Sample usage:              �ض���printf��DEBUG������
//-------------------------------------------------------------------------------------------------------------------
__attribute__((used)) int _write(int fd, char *buf, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
        USART_SendData(USART3, *buf++);
    }

    return size;
}

#endif
