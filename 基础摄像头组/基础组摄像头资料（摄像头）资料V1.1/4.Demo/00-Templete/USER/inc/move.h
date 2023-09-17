#ifndef MOVE_H_
#define MOVE_H_
#include "common.h"
#include "HF_MT9V03X.h"
//PID结构体
typedef struct{
	int16 Current_Speed;//—————————————————————————————————————————————————当前速度
	int16 Target_Speed;//——————————————————————————————————————————————————目标速度
	int16 Encoder;//———————————————————————————————————————————————————————编码器值
	int16 E;//—————————————————————————————————————————————————————————————本次的偏差
	int16 E_L;//———————————————————————————————————————————————————————————上一次的偏差
	int16 E_L_L;//—————————————————————————————————————————————————————————上上次的偏差
	int16 KP;//————————————————————————————————————————————————————————————比例系数
	int16 KI;//————————————————————————————————————————————————————————————积分系数
	int16 KD;//————————————————————————————————————————————————————————————微分系数
	int16 PIDOUT;//————————————————————————————————————————————————————————PID输出
	int16 Target_Speed_old;
  	int16 Current_Speed_last;	
 	int16 Current_Speed_llast;		
}PID_struct;

extern int _speed;
extern int Leftspeed;
extern int Rightspeed;


void car_move(int8_t f);
void Motor_Parameters_Init(PID_struct *Motor);
short Motro_PID_Control(PID_struct* Motor);
void Motor_Ctrl(uint8 num, int16 duty);

#endif