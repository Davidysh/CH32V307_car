/*
 * camera.c
 *
 *  Created on: 2022年10月30日
 *      Author: 非凡土豆
 */

#include "camera.H"

extern unsigned char g_uc_miss_left_flag,g_uc_miss_right_flag;
extern unsigned char g_uc_middle_line[120];
extern unsigned char g_uc_left_boundary[120];
extern unsigned char g_uc_right_boundary[120];
extern unsigned int g_ui_left_side,g_ui_right_side,g_ui_middle_point;
extern unsigned int g_ui_left_side_prev,g_ui_right_side_prev,g_ui_middle_line_prev;
extern unsigned char g_uc_miss_left_flag,g_uc_miss_right_flag;
extern unsigned char g_uc_middle_line[120];
extern unsigned char g_uc_left_boundary[120];
extern unsigned char g_uc_right_boundary[120];
extern unsigned char kp;
extern unsigned char kd;
extern unsigned char g_uc_central;

extern unsigned int g_ui_left_motor_speed,g_ui_right_motor_speed;
extern unsigned int g_ui_left_motor_speed_1,g_ui_right_motor_speed_1;
extern unsigned int g_ui_error[6];
extern unsigned int speed_center;

unsigned int g_uc_element_flag;


void binarization(uint8 thro)
{
    for(unsigned int h = 0;h<120;h++)
    {
        for(unsigned int w = 0;w<188;w++)
        {
            if(mt9v03x_image_dvp[h][w] > thro)
            {
                mt9v03x_image_dvp[h][w] = 0;
            }
            else
            {
                mt9v03x_image_dvp[h][w] = 1;
            }
        }
    }
}
void side_lookout()
{
    for(unsigned int h = 0;h < 119;h++)
    {
        for(unsigned int w = g_uc_middle_line[h];w<187;w++)
        {
            if(mt9v03x_image_dvp[120-h][w] != mt9v03x_image_dvp[120-h][w-1] && mt9v03x_image_dvp[120-h][w] == mt9v03x_image_dvp[120-h][w+1]  && mt9v03x_image_dvp[120-h][w] == 1)
            {
                mt9v03x_image_dvp[120-h][w-1] = 2;
                g_ui_right_side = w;
                g_uc_right_boundary[120-h] = w;
                break;
            }
        }
        if(g_ui_right_side == 0)
        {
            g_ui_right_side = 188;
            g_uc_right_boundary[120-h] = 188;
        }
        for(unsigned int w = g_uc_middle_line[h];w>1;w--)
        {
            if(mt9v03x_image_dvp[120-h][w] != mt9v03x_image_dvp[120-h][w+1] && mt9v03x_image_dvp[120-h][w] == mt9v03x_image_dvp[120-h][w-1] && mt9v03x_image_dvp[120-h][w] == 1 )
            {
                mt9v03x_image_dvp[120-h][w+1] = 2;
                g_ui_left_side = w;
                g_uc_left_boundary[120-h] = w;
                g_uc_miss_right_flag = 0;
                break;
            }
            else
            {
                ;
            }
        }
        if(g_ui_left_side == 0)
        {
            g_ui_left_side = 0;
            g_uc_left_boundary[120-h] = 0;
            g_uc_miss_right_flag = 1;
        }
        g_ui_middle_point = (g_ui_left_side+g_ui_right_side)/2;
        if(mt9v03x_image_dvp[120-h][g_ui_middle_point-1] == 1 && mt9v03x_image_dvp[120-h][g_ui_middle_point+1] == 1)
        {
            ;
        }
        else
        {
            mt9v03x_image_dvp[120-h][g_ui_middle_point] = 3;
        }

        g_uc_middle_line[h+1] = g_ui_middle_point;

        g_ui_left_side_prev = g_ui_left_side;
        g_ui_middle_line_prev = g_ui_middle_point;
        g_ui_right_side_prev = g_ui_right_side;

        g_ui_left_side = 0;
        g_ui_right_side = 0;

        g_uc_miss_right_flag = 0;
        g_uc_miss_left_flag = 0;
    }

    for(unsigned char x = g_uc_left_boundary[100];x < g_uc_right_boundary[100];x++)
    {
        mt9v03x_image_dvp[100][x] = 5;
    }
    for(unsigned char x = g_uc_left_boundary[80];x < g_uc_right_boundary[80];x++)
    {
        mt9v03x_image_dvp[80][x] = 5;
    }
    for(unsigned char x = g_uc_left_boundary[60];x < g_uc_right_boundary[60];x++)
    {
        mt9v03x_image_dvp[60][x] = 5;
    }

}


void cam_guide()
{
    if(g_uc_middle_line[20] < g_uc_central && g_uc_middle_line[20] != 0 && g_uc_middle_line[40] != 0)   //speed control
    {
        g_ui_error[0] = g_uc_central - g_uc_middle_line[20];
        g_ui_error[1] = g_uc_central - g_uc_middle_line[40];
        g_ui_error[2] = g_uc_central - g_uc_middle_line[60];
        unsigned int speed_c = (kp*(1*g_ui_error[0] + 1*g_ui_error[1] + 1*g_ui_error[2]) + kd*(1*g_ui_error[0] + 1*g_ui_error[1] + g_ui_error[2] - 1*g_ui_error[3] - 1*g_ui_error[4] - g_ui_error[5]));
        if(speed_c/2 + speed_center > 10000)
        {
            g_ui_right_motor_speed = 10000;
        }
        else
        {
            g_ui_right_motor_speed  = (speed_center + speed_c/2);
        }
        if(speed_c/2 > speed_center)
        {
            g_ui_left_motor_speed = 0;
        }
        else
        {
            g_ui_left_motor_speed = (speed_center - speed_c/2);
        }
    }
    else if(g_uc_middle_line[20] > g_uc_central)
    {
        g_ui_error[0] = g_uc_middle_line[20] - g_uc_central;
        g_ui_error[1] = g_uc_middle_line[40] - g_uc_central;
        g_ui_error[2] = g_uc_middle_line[60] - g_uc_central;
        unsigned int speed_c = (kp*(1*g_ui_error[0] + 1*g_ui_error[1] + 1*g_ui_error[2]) + kd*(1*g_ui_error[0] + 1*g_ui_error[1] + g_ui_error[2] - 1*g_ui_error[3] - 1*g_ui_error[4] - g_ui_error[5]));
        if(speed_c/2 + speed_center > 10000)
        {
            g_ui_left_motor_speed = 10000;
        }
        else
        {
            g_ui_left_motor_speed  = (speed_center + speed_c/2);
        }
        if(speed_c/2 > speed_center)
        {
            g_ui_right_motor_speed = 0;
        }
        else
        {
            g_ui_right_motor_speed = (speed_center - speed_c/2);
        }
    }

    if(g_ui_left_motor_speed == 0 && g_ui_right_motor_speed < 0)
    {
        g_ui_left_motor_speed = g_ui_left_motor_speed_1;
        g_ui_right_motor_speed = g_ui_right_motor_speed_1;
    }
    else if(g_ui_left_motor_speed < 0 && g_ui_right_motor_speed == 0)
    {
        g_ui_left_motor_speed = g_ui_left_motor_speed_1;
        g_ui_right_motor_speed = g_ui_right_motor_speed_1;
    }
    else if(g_ui_left_motor_speed == 0 && g_ui_right_motor_speed == 0)
    {
        g_ui_left_motor_speed = speed_center;
        g_ui_right_motor_speed = speed_center;
    }
    else
    {
        g_ui_left_motor_speed_1 = g_ui_left_motor_speed;
        g_ui_right_motor_speed_1 = g_ui_right_motor_speed;
    }
    if(g_ui_left_motor_speed == 10000 & g_ui_right_motor_speed == 0)
    {
        g_ui_left_motor_speed  = speed_center;
        g_ui_right_motor_speed = speed_center;
    }
    else if(g_ui_left_motor_speed == 0 & g_ui_right_motor_speed == 10000)
    {
        g_ui_left_motor_speed  = speed_center;
        g_ui_right_motor_speed = speed_center;
    }


    g_ui_error[3] = g_ui_error[0];
    g_ui_error[4] = g_ui_error[1];
    g_ui_error[5] = g_ui_error[2];
}

