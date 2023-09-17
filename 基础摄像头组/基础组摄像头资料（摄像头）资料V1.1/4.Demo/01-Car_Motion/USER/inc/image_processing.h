#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include "common.h"
#include "headfile.h"
uint8_t get_threshold();
extern uint8_t flag_show_status;
extern uint8_t Pixle[MT9V03X_DVP_H][MT9V03X_DVP_W];
uint8 Horizontal_line(int Pixle[MT9V03X_DVP_H][MT9V03X_DVP_W]);
void Get_Pixle(void);

#endif