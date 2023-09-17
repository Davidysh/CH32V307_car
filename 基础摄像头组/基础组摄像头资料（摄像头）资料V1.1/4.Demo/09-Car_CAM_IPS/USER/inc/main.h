/*********************************************************************************************************************
* @file            main.h
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-3-2
********************************************************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_

#include "headfile.h"
#include "isr.h"


/* 宏定义 */


/* 变量定义 */
unsigned int g_ui_left_side,g_ui_right_side,g_ui_middle_point;
unsigned int g_ui_left_side_prev,g_ui_right_side_prev,g_ui_middle_line_prev;
unsigned char g_uc_miss_left_flag,g_uc_miss_right_flag,g_uc_miss_first_line_left_right_flag;
unsigned char g_uc_middle_line[120];
unsigned char g_uc_left_boundary[120];
unsigned char g_uc_right_boundary[120];
unsigned char kp;
unsigned char kd;
unsigned char g_uc_central;
unsigned int g_ui_left_motor_speed,g_ui_right_motor_speed;
unsigned int g_ui_left_motor_speed_1,g_ui_right_motor_speed_1;
unsigned int g_ui_error[6] = {0,0,0,0,0,0};
unsigned int exposure;
unsigned int speed_center;
/* 函数声明 */

#endif /* MAIN_H_ */
