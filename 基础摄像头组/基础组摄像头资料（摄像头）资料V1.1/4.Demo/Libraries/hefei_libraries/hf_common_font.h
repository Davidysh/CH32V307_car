/*********************************************************************************************************************
* @file            hf_common_font.h
* @author
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220907
********************************************************************************************************************/
#include "common.h"
#ifndef _HF_COMMON_FONT_H_
#define _HF_COMMON_FONT_H_



//-------������ɫ----------
#define RGB565_WHITE           0xFFFF  // ��ɫ
#define RGB565_BLACK           0x0000  // ��ɫ
#define RGB565_BLUE            0x001F  // ��ɫ
#define RGB565_PURPLE          0XF81F  // ��ɫ
#define RGB565_PINK            0XFE19  // ��ɫ
#define RGB565_RED             0xF800  // ��ɫ
#define RGB565_MAGENTA         0xF81F  // Ʒ��
#define RGB565_GREEN           0x07E0  // ��ɫ
#define RGB565_CYAN            0x07FF  // ��ɫ
#define RGB565_YELLOW          0xFFE0  // ��ɫ
#define RGB565_BROWN           0XBC40  // ��ɫ
#define RGB565_GRAY            0X8430  // ��ɫ

//-------------------------------------------------------------------------------------------------------------------
// @brief       ����ֵ���� ���ݷ�Χ�� [-32767,32767]
// @param       dat             ��Ҫ�����ֵ����
// @return      int             ���ؾ���ֵ
// Sample usage:                dat = myabs(dat);                               // ��dat�������
//-------------------------------------------------------------------------------------------------------------------
#define     myabs(x)            (x>=0? x: -(x))

extern const uint8      tft_ascii[95][16];
extern const uint8      oled_6x8[][6];
extern const uint8      oled_8x16[];
#endif
