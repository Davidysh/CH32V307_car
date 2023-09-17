
// #include <stdint.h>
// #include <stdio.h>

// #include "image_processing.h"
// #include "HF_Double_DC_Motor.h"
// #include "car_motion.h"
// #include "init.h"
// #include "message.h"
// #include "time.h"
// #include "dis_camera.h"
// #include "move.h"
// #include "key_fn.h"

// uint8_t display_status = 1;
// uint8_t frame_dis_status = 1;

// // #define Row  60 
// // #define Col  94
// // uint8_t midline = 0;

// int main() {

//     init();

//     unsigned char key_value;
//     uint16_t frame = 30;
//     uint16_t frame_time = 1000/frame;
//     uint8_t frame_show = 0;
//     int ms;
//     int ms_new;
//     uint16_t s_cnt = 0;

//     int8_t factor = 0;
//     // int16_t Leftspeed = 0;
//     // int16_t Rightspeed = 0;
//     // PID_struct* Motor1 = 0;
//     // PID_struct* Motor2 = 0;        
//     // Motor_Parameters_Init(Motor1);
//     // Motor_Parameters_Init(Motor2);

//     while(1) {

//         time_begin();
//         ms = get_time();
//         if(frame_dis_status){
//             sprintf(buf, "%d", frame_show);
//             show_left_bottom_message(buf);
//         }

//         key_value = key_check();

//         camera_check();
//         // Get_Pixle();
//         if(display_status)display();
//         change_flag();

//         factor = cal_factor();
//         // Motor1->E = factor;
//         // Motor2->E = factor;

//         // Leftspeed = Motro_PID_Control(Motor1);
//         // Rightspeed = Motro_PID_Control(Motor2); 
//         // midline = Horizontal_line(); 

//         // sprintf(buf, " %d|%d ", factor, midline);
//         // show_right_top_message(buf);
//         // motor_forward(left,Leftspeed);
//         // motor_forward(right,Rightspeed);

//         sample();

//         ms_new = get_time();
//         time_end();
//         int t = ms_new - ms;
//         if (t > 0 && t < frame_time) {
//             Delay_Ms(frame_time - t);
//             t += frame_time - t;
//         }
//         s_cnt += t;
//         if (s_cnt >= 1000) {
//             frame_show = frame_avg();
//             s_cnt = 0;
//             frame_cnt = 0;
//         }
//         key_fn(key_value);
//     }
// }


#include <stdint.h>
#include <stdio.h>

#include "HF_Double_DC_Motor.h"

#include "init.h"
#include "message.h"
#include "time.h"
#include "dis_camera.h"
#include "move.h"
#include "key_fn.h"

uint8_t display_status = 1;
uint8_t frame_dis_status = 1;

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
    short Leftspeed;
    short Rightspeed;
    uint8_t midline;

    while(1) {
        time_begin();
        ms = get_time();
        if(frame_dis_status){
            sprintf(buf, "%d", frame_show);
            show_left_bottom_message(buf);
        }

        key_value = key_check();

        camera_check();
        if(display_status)display();
        change_flag();
        factor = cal_factor();
        // midline = Get_mid(); 
        // PID_struct* Motor1;
        // PID_struct* Motor2;        
        // Motor_Parameters_Init(Motor1);
        // Motor_Parameters_Init(Motor2);
        // Motor1->E = MT9V03X_DVP_W/2 - midline;//获取偏差值进行PID
        // Motor2->E = MT9V03X_DVP_W/2 - midline;
        // Leftspeed = Motro_PID_Control(Motor1);
        // Rightspeed = Motro_PID_Control(Motor2);
        motor_forward(left, Leftspeed);
        motor_forward(right, Rightspeed);

        

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

