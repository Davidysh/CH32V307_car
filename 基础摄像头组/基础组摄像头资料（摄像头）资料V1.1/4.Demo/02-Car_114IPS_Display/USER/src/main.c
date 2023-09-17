/*********************************************************************************************************************
* @file            main.c
* @brief           1.14寸IPS屏幕例程
* @author          FantasticPotato
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-9-19
*
********************************************************************************************************************/

/* 用户头文件 */
#include "main.h"
#include "headfile.h"

/* 全局变量声明 */

/* 主函数 */
int main(void)
{
    /* 此处声明需要用到的局部变量 */

    /* 智能车初始化 */
    car_init();

    /* 此处编写单次运行的代码(例如：初始化代码等) */
    ips114_init();

    while(1)
    {
        /* 此处编写需要循环执行的代码 */
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





