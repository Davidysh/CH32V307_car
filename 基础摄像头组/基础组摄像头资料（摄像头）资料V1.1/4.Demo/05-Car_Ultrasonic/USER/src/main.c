/*********************************************************************************************************************
* @file            main.c
* @brief           智能车超声波测距例程
* @author          Fantastic Potato
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-9-19
* TFT模块改变显示颜色
********************************************************************************************************************/


#include "main.h"
#include "headfile.h"

int main(void)
{
    /* 此处声明需要用到的局部变量 */
    unsigned int  distance_value;
    unsigned char distance_ascii[6];

    /* 此处编写单次运行的代码(例如：初始化代码等) */

    /* 智能车初始化 */
    car_init();

    /* 此处编写单次运行的代码(例如：初始化代码等) */

    while(1)
    {
        /* 此处编写循环运行的代码 */
        distance_value = ultra_get_distance();              //超声波模块测距

        int_to_ascii(distance_value, distance_ascii);       //将测得距离转换为ascii码

        uart_send_distance_ascii(distance_ascii);           //串口发送测得的距离
        Delay_Ms(500);
    }
}

void uart_send_distance_ascii(unsigned char *ascii_value)
{
    uart_send_char(UART_1, ascii_value[1]);
    uart_send_char(UART_1, ascii_value[2]);
    uart_send_char(UART_1, ascii_value[3]);
    uart_send_char(UART_1, '.');
    uart_send_char(UART_1, ascii_value[4]);
    uart_send_char(UART_1, 0x0D);
    uart_send_char(UART_1, 0x0A);                            //换行
}
