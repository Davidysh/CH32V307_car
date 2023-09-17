/*********************************************************************************************************************
* @file            HF_TFT180.h
* @author
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220905
********************************************************************************************************************/

#ifndef _HF_TFT180_H_
#define _HF_TFT180_H_

#include "hf_common_font.h"
#include "delay.h"
#include "hf_spi.h"

#define TFT180_USE_SOFT_SPI             (0)                                     // Ĭ��ʹ��Ӳ�� SPI ��ʽ���� ����ʹ��Ӳ�� SPI ��ʽ����
#if TFT180_USE_SOFT_SPI                                                         // ������ ��ɫ�����Ĳ�����ȷ�� ��ɫ�ҵľ���û���õ�
//====================================================��� SPI ����====================================================
#define TFT180_SOFT_SPI_DELAY           (1 )                                    // ��� SPI ��ʱ����ʱ���� ��ֵԽС SPI ͨ������Խ��
#define TFT180_SCL_PIN                  (B13)                                    // ��� SPI SCK ����
#define TFT180_SDA_PIN                  (B15)                                    // ��� SPI MOSI ����
//====================================================��� SPI ����====================================================
#else
//====================================================Ӳ�� SPI ����====================================================
#define TFT180_SPI_SPEED                (SystemCoreClock / 4)                      // Ӳ�� SPI ����
#define TFT180_SPI                      (SPI_2)                                 // Ӳ�� SPI ��
#define TFT180_SCL_PIN                  (SPI2_SCK_B13)                          // Ӳ�� SPI SCK ����
#define TFT180_SDA_PIN                  (SPI2_MOSI_B15)                         // Ӳ�� SPI MOSI ����
//====================================================Ӳ�� SPI ����====================================================
#endif

#define TFT180_RES_PIN                  (B7)                                    // Һ����λ���Ŷ���
#define TFT180_DC_PIN                   (D7)                                    // Һ������λ���Ŷ���
#define TFT180_CS_PIN                   (D4)                                    // CS Ƭѡ����
#define TFT180_BL_PIN                   (D0)                                    // Һ���������Ŷ���

#define TFT180_DC(x)                    ((x) ? (gpio_high(TFT180_DC_PIN)) : (gpio_low(TFT180_DC_PIN)))
#define TFT180_RST(x)                   ((x) ? (gpio_high(TFT180_RES_PIN)) : (gpio_low(TFT180_RES_PIN)))
#define TFT180_CS(x)                    ((x) ? (gpio_high(TFT180_CS_PIN)) : (gpio_low(TFT180_CS_PIN)))
#define TFT180_BLK(x)                   ((x) ? (gpio_high(TFT180_BL_PIN)) : (gpio_low(TFT180_BL_PIN)))

typedef enum
{
    TFT180_PORTAIT                      = 0,                                    // ����ģʽ
    TFT180_PORTAIT_180                  = 1,                                    // ����ģʽ  ��ת180
    TFT180_CROSSWISE                    = 2,                                    // ����ģʽ
    TFT180_CROSSWISE_180                = 3,                                    // ����ģʽ  ��ת180
}tft180_dir_enum;

#define TFT180_DEFAULT_DISPLAY_DIR      (TFT180_PORTAIT)                        // Ĭ�ϵ���ʾ����
#define TFT180_DEFAULT_PENCOLOR         (RGB565_RED)                            // Ĭ�ϵĻ�����ɫ
#define TFT180_DEFAULT_BGCOLOR          (RGB565_WHITE)                          // Ĭ�ϵı�����ɫ


void    tft180_clear                    (void);
void    tft180_full                     (const uint16_t color);
void    tft180_set_dir                  (tft180_dir_enum dir);
void    tft180_set_color                (const uint16_t pen, const  uint16_t bgcolor);
void    tft180_draw_point               (uint16_t x, uint16_t y, const uint16_t color);

void    tft180_show_char                (uint16_t x, uint16_t y, const char dat);
void    tft180_show_string              (uint16_t x, uint16_t y, const char dat[]);
void    tft180_show_int                 (uint16_t x,uint16_t y, const int32_t dat, uint8_t num);
void    tft180_show_uint                (uint16_t x,uint16_t y, const uint32_t dat, uint8_t num);
void    tft180_show_float               (uint16_t x,uint16_t y, const float dat, uint8_t num, uint8_t pointnum);

void    tft180_show_binary_image        (uint16_t x, uint16_t y, const uint8_t *image, uint16_t width, uint16_t height, uint16_t dis_width, uint16_t dis_height);
void    tft180_show_gray_image          (uint16_t x, uint16_t y, const uint8_t *image, uint16_t width, uint16_t height, uint16_t dis_width, uint16_t dis_height, uint8_t threshold);
void    tft180_show_rgb565_image        (uint16_t x, uint16_t y, const uint16_t *image, uint16_t width, uint16_t height, uint16_t dis_width, uint16_t dis_height, uint8_t color_mode);

void    tft180_show_wave                (uint16_t x, uint16_t y, const uint16_t *wave, uint16_t width, uint16_t value_max, uint16_t dis_width, uint16_t dis_value_max);
void    tft180_show_chinese             (uint16_t x, uint16_t y, uint8_t size, const uint8_t *chinese_buffer, uint8_t number, const uint16_t color);

void    float_to_str                        (char *str, float number, uint8_t point_bit);
void    uint_to_str                         (char *str, uint32_t number);
void    int_to_str                          (char *str, int32_t number);

#define tft180_displayimage7725(p, width, height)                                       (tft180_show_binary_image(0, 0, (p), (width), (height), (width), (height)))

#define tft180_displayimage032(p, width, height)                                        (tft180_show_gray_image(0, 0, (p), (width), (height), (width), (height), 0))
#define tft180_displayimage032_zoom(p, width, height, dis_width, dis_height)            (tft180_show_gray_image(0, 0, (p), (width), (height), (dis_width), (dis_height), 0))
#define tft180_displayimage032_zoom1(x, y, p, width, height, dis_width, dis_height)     (tft180_show_gray_image((x), (y), (p), (width), (height), (dis_width), (dis_height), 0))

#define tft180_displayimage8660(p, width, height)                                       (tft180_show_rgb565_image(0, 0, (p), (width), (height), (width), (height), 1))
#define tft180_displayimage8660_zoom(p, width, height, dis_width, dis_height)           (tft180_show_rgb565_image(0, 0, (p), (width), (height), (dis_width), (dis_height), 1))
#define tft180_displayimage8660_zoom1(x, y, p, width, height, dis_width, dis_height)    (tft180_show_rgb565_image((x), (y), (p), (width), (height), (dis_width), (dis_height), 1))

void    tft180_init                     (void);

#endif
