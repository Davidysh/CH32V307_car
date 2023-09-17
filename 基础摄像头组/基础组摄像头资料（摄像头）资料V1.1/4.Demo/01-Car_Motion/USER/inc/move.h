#ifndef MOVE_H_
#define MOVE_H_
#include "common.h"

//PID结构体
typedef struct{
	int16 E;//—————————————————————————————————————————————————————————————本次的偏差
	int16 E_L;//———————————————————————————————————————————————————————————上一次的偏差
	int16 E_L_L;//—————————————————————————————————————————————————————————上上次的偏差
	int16 KP;//————————————————————————————————————————————————————————————比例系数
	int16 KI;//————————————————————————————————————————————————————————————积分系数
	int16 KD;//————————————————————————————————————————————————————————————微分系数
	int16 PIDOUT;//————————————————————————————————————————————————————————PID输出
}PID_struct;
extern int _speed;

void car_move(int8_t f);
void Motor_Parameters_Init1(PID_struct *Motor);
void Motor_Parameters_Init2(PID_struct *Motor);
short Motro_PID_Control(PID_struct* Motor);
void Motor_Ctrl(uint8 num, int16 duty);

#endif
