/*********************************************************************************************************************
* @file            main.c
* @brief           6按键例程
* @author          lemon
* @version         1.0
* @Target core     CH32V307VCT6
* @date            -2022.9.12, V1.0
* 通过4按键模块控制小车尾灯亮灭和颜色变化
********************************************************************************************************************/

/* 用户头文件 */
#include "main.h"
#include "headfile.h"

/* 全局变量声明 */


/* 主函数 */
int main(void)
{
    /* 此处声明需要用到的局部变量 */
    unsigned char key_value;

    /* 智能车初始化 */
    car_init();

    board_led_init(1);

    /* 此处编写单次运行的代码(例如：初始化代码等) */
    ips114_init();
    car_both_rgb_off();

    exti_enable(EXTI_Line3, C3, BOTH);
    exti_enable(EXTI_Line4, C4, BOTH);
    exti_enable(EXTI_Line5, C5, BOTH);


    while(1)
    {
        /* 此处编写需要循环执行的代码 */
        key_value = key_check();

        if (key_value != 0xFF)
        {
            if(key_value == 0x01)
            {
                car_both_rgb_on(yellow);  //按下按键1，尾灯显示黄色
                ips114_show_string(0, 0, "key1");
            }
            else if(key_value == 0x02)
            {
                car_both_rgb_on(red);     //按下按键2，尾灯显示红色
                ips114_show_string(0, 0, "key2");
            }
            else if(key_value == 0x03)
            {
                car_both_rgb_on(blue);    //按下按键3，尾灯显示蓝色
                ips114_show_string(0, 0, "key3");
            }

            //按键4-6功能使用中断实现，详见isr.c
        }
    }
}
