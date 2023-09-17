/*********************************************************************************************************************
* @file            main.c
* @brief           摄像头图像屏幕显示例程
* @author          lemon
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-3-2
*
********************************************************************************************************************/

/* 用户头文件 */
#include "main.h"
#include "headfile.h"

/* 全局变量声明 */
void Daimxa_Pc_Display188x120(void)
{   //unsigned char y;
    int i=0;
    int j=0;
    uart_putchar(UART_3,0x00); //发送帧头，函数、UART改成自己的
    uart_putchar(UART_3,0xff);//发送帧头
    uart_putchar(UART_3,0x01);//发送帧头
    uart_putchar(UART_3,0x01);//发送帧头
    for(i=0;i<120;i++)//发送图像，像素为188X120
    {
        for(j=0;j<188;j++)
            uart_putchar(UART_3,mt9v03x_image_dvp[i][j]);//灰度，二值化均可
        }
//--------------------若只发图像，则下面六行代码可以删除--------------------
   /* for(y = 0; y<120; y++)//发送左边线
        uart_putchar(UART_0,Daimxa_ImageDeal[y].LeftBorder);//第二个参数均为长度120字节边线数组
    for(y = 0; y<120; y++)//发送右边线
        uart_putchar(UART_0,Daimxa_ImageDeal[y].RightBorder);
    for(y = 0; y<120; y++)//发送中线
        uart_putchar(UART_0,Daimxa_ImageDeal[y].Center);
    */
}

/* 主函数 */
int main(void)
{
    /* 此处声明需要用到的局部变量 */

    /* 智能车初始化 */
    car_init();

    /* 此处编写单次运行的代码(例如：初始化代码等) */
    ips114_init();     //初始化屏幕
    ips114_show_string(0,0,"CAM-IPS");
    ips114_show_string(0,20,"DEMO");
    mt9v03x_init_dvp();

    Delay_Ms(100);
//uart_send_char(UART_3, rx_char);   //串口3发送接收到的数据
    while(1)
    {
        /* 此处编写需要循环执行的代码 */
        if(mt9v03x_finish_flag_dvp)
        {
            mt9v03x_finish_flag_dvp = 0;
            // 根据原始图像大小,显示原始图像
           // ips114_displayimage032(mt9v03x_image_dvp[0], MT9V03X_DVP_W, MT9V03X_DVP_H);
            Daimxa_Pc_Display188x120();
        }
    }
}





