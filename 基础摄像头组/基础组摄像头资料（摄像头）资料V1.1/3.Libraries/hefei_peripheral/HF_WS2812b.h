/********************************************************************************************************************
* @file            HF_WS2812b.h
* @author
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220905
********************************************************************************************************************/

#ifndef HF_WS2812B_H_
#define HF_WS2812B_H_

#include "headfile.h"

//函数声明
/* RGB初始化 */
void ws2812b_init();
/* RGB写入 */
void ws2812b_write(uint8_t* RGB);

//全局变量声明

#endif
