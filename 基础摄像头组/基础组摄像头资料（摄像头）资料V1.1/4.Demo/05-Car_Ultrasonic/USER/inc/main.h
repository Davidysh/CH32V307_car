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


/* 函数声明 */
void uart_send_distance_ascii(unsigned char *ascii_value);

#endif /* MAIN_H_ */
