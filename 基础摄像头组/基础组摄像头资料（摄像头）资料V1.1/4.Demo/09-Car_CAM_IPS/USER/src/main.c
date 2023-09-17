//注意：本程序为摄像头组示例程序，仅供同学们参考，请勿直接烧录本工程程序参赛！！！
//本程序包含摄像头基础寻迹功能，通过修改程序开头关键变量数值可以实现小车的运动控制，
//但直接烧录该程序无法完成元素识别等操作，可基于本程序自行开发识别处理程序。
#include "main.h"
#include "headfile.h"

int main(void)
{
    //关键变量初始化
    g_uc_central = 94;          //中线值，此数值定义了摄像头图像参考中线位置
    speed_center = 3000;        //速度中值，电机PWM占空比基于此数值左加右减或左减右加实现差速前进
    exposure = 500;             //曝光值，此数值越大则曝光效果越强，图像整体更亮，需根据现场光亮情况调整此数值

    //方向环参数初始化
    //本段两个参数因小车摄像头高度、角度、前瞻大小而各有差别，需自行调整，直接烧录大概率无法直接运行
    kp = 10;                    //方向环P，此数值越大则小车可以更快向中线靠拢，但数值过大会引起小车不断左右摇摆
    kd = 10;                    //方向环D，此数值可以抑制KP的摇摆作用，适当增加D可以让P的抖动效果减弱

    //以下参数为寻迹函数内部使用，请勿修改
    g_uc_middle_line[0] = 94;
    g_ui_left_side = 0;
    g_ui_middle_point = 0;
    g_ui_right_side = 0;

    //小车初始化
    car_init();

    //曝光值写入摄像头
    mt9v03x_set_exposure_time_dvp (exposure);

    while(1)
    {
        //图像处理
        if(mt9v03x_finish_flag_dvp)
        {
            //二值化函数，输入参数为二值化阈值，大于此阈值的认为是白色，小于此阈值为黑色。
            binarization(230);
            //边界扫描
            side_lookout();
            //摄像头寻迹
            cam_guide();
}
        //显示图像
        mt9v03x_finish_flag_dvp = 0;
        ips114_displayimage032(mt9v03x_image_dvp[0], MT9V03X_DVP_W, MT9V03X_DVP_H);


        //图像处理
        motor_forward(right, g_ui_right_motor_speed);
        motor_forward(left ,  g_ui_left_motor_speed);
    }
}





