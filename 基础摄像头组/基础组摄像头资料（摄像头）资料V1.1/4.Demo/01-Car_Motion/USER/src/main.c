
#include <stdint.h>
#include <stdio.h>

#include "HF_Double_DC_Motor.h"
#include "image_processing.h"
#include "init.h"
#include "message.h"
#include "time.h"
#include "dis_camera.h"
#include "move.h"
#include "key_fn.h"

uint8_t display_status = 1;
uint8_t frame_dis_status = 1;

       PID_struct *Motor1 = (PID_struct*)malloc(sizeof(PID_struct));
       PID_struct *Motor2 = PID_struct;
       Motor_Parameters_Init1(Motor1);
       Motor_Parameters_Init2(Motor2);

int main() {

    init();

    unsigned char key_value;
    uint16_t frame = 30;
    uint16_t frame_time = 1000/frame;
    uint8_t frame_show = 0;
    int ms;
    int ms_new;
    uint16_t s_cnt = 0;

    int8_t factor = 0;
    short Leftspeed = 0;
    short Rightspeed = 0;
    uint8_t midline = 0;
    while(1) {
        time_begin();
        ms = get_time();
        if(frame_dis_status){
            sprintf(buf, "%d", frame_show);
            show_left_bottom_message(buf);
        }

        key_value = key_check();

        camera_check();
        change_flag();
        Get_Pixle();
        //Pixle_Filter();
        
        factor = cal_factor();
        midline = Horizontal_line();
        // Pixle[Row][midline] = 0;//让找到的中线变黑这样二值化后的图像方便观察
        ips114_show_gray_image(0, 0,
            Pixle,
            c_w, c_h,
            d_w, d_h,
            flag);//显示去噪后的二值化图像那display就可以改一下了（中线变黑）
        sprintf(buf, " %d|%d ", factor, midline);
        show_right_top_message(buf);
//        PID_struct* Motor1;
//        PID_struct* Motor2;
//        Motor_Parameters_Init(Motor1);
//        Motor_Parameters_Init(Motor2);
//        Motor1->E = factor;
//        Motor2->E = factor;
//        Leftspeed = Motro_PID_Control(Motor1);
//        Rightspeed = Motro_PID_Control(Motor2);
//        Motor_Ctrl(1, Leftspeed);
//        Motor_Ctrl(2, Rightspeed);
        
        sample();

        ms_new = get_time();
        time_end();
        int t = ms_new - ms;
        if (t > 0 && t < frame_time) {
            Delay_Ms(frame_time - t);
            t += frame_time - t;
        }
        s_cnt += t;
        if (s_cnt >= 1000) {
            frame_show = frame_avg();
            s_cnt = 0;
            frame_cnt = 0;
        }

        key_fn(key_value);
    }
}
