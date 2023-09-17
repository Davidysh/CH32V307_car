/*********************************************************************************************************************
* @file            main.c
* @brief           智能车串口查询例程
* @author          GX
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220911
********************************************************************************************************************/


#include "main.h"
#include "headfile.h"

int main(void)
{
    /* 此处声明需要用到的局部变量 */

    unsigned char rx_char;

    /* 智能车初始化 */
    car_init();

    /* 此处编写单次运行的代码(例如：初始化代码等) */

    uart_send_char(UART_3, 'a');           //串口3发送字符

    while(1)
    {
        rx_char = uart_receive(UART_3);    //串口3接收数据
        uart_send_char(UART_3, rx_char);   //串口3发送接收到的数据
    }
}
