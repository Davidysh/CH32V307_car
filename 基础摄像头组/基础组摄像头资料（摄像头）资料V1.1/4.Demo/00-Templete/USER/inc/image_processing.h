#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include "common.h"
#include "HF_MT9V03X.h"
#include "headfile.h"

extern uint8_t flag_show_status;
extern uint8_t Pixle[MT9V03X_DVP_H][MT9V03X_DVP_W];
extern uint8_t midline;
extern uint8_t leftline;
extern uint8_t rightline;

uint8_t get_threshold();
uint8 Horizontal_line(void);
void Get_Pixle(void);
void Pixle_Filter (int Pixle[MT9V03X_DVP_H][MT9V03X_DVP_W]);
uint8 Horizontal_line(void);
uint8 Get_mid(void);
#endif