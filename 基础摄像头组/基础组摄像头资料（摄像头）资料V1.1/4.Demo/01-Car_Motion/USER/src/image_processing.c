

#include "image_processing.h"

#include "dis_camera.h"
#include "message.h"
#include "HF_Double_DC_Motor.h"
#include <stdint.h>

uint8_t flag_show_status = 0;
#define  _avg_fre 12
static uint8_t _threshold_avg[_avg_fre] = {0};
static uint8_t _pos = 0;
#define Row 60
#define Col 94
uint8_t Pixle[MT9V03X_DVP_H][MT9V03X_DVP_W];

uint8_t threshold_avg(uint8_t threshold){
    _threshold_avg[_pos] = threshold;
    _pos += 1;
    if (_pos >= _avg_fre)_pos = 0;
    uint8_t pos = _pos + _avg_fre;
    uint16_t ans = 0;
    for (uint8_t i = 1; i <= _avg_fre; ++i) {
        ans += _threshold_avg[(pos-i)%_avg_fre];
    }
    return ans/_avg_fre;
}

/*************************************************************** 
* 函数名称：GetOSTU 大津法
* 函数输入：摄像头传感器图像数组（mt9v03x_image_dvp）
* 函数输出：阈值大小 （Threshold）
* 功能说明：求阈值大小
***************************************************************/ 
uint8 GetOSTU(uint8 mt9v03x_image_dvp[MT9V03X_DVP_H][MT9V03X_DVP_W]){ 
    int16 i,j; 
    uint32 Amount = 0; 
    uint32 PixelBack = 0; 
    uint32 PixelIntegralBack = 0; 
    uint32 PixelIntegral = 0; 
    int32 PixelIntegralFore = 0; 
    int32 PixelFore = 0; 
    double OmegaBack, OmegaFore, MicroBack, MicroFore, SigmaB, Sigma; // 类间方差;
    int16 MinValue, MaxValue; 
    uint8 Threshold = 0;
    uint8 HistoGram[256];              //  
    
    for (j = 0; j < 256; j++)  HistoGram[j] = 0; //初始化灰度直方图
    
    for (j = 0; j < MT9V03X_DVP_H; j++) 
    { 
        for (i = 0; i < MT9V03X_DVP_W; i++) 
        { 
        HistoGram[mt9v03x_image_dvp[j][i]]++; //统计灰度级中每个像素在整幅图像中的个数
        } 
    } 
    
    for (MinValue = 0; MinValue < 256 && HistoGram[MinValue] == 0; MinValue++) ;        //获取最小灰度的值
    for (MaxValue = 255; MaxValue > MinValue && HistoGram[MinValue] == 0; MaxValue--) ; //获取最大灰度的值
        
    if (MaxValue == MinValue)     return MaxValue;         // 图像中只有一个颜色
    if (MinValue + 1 == MaxValue)  return MinValue;        // 图像中只有二个颜色
        
    for (j = MinValue; j <= MaxValue; j++)    Amount += HistoGram[j];        //  像素总数
        
    PixelIntegral = 0;
    for (j = MinValue; j <= MaxValue; j++)
    {
        PixelIntegral += HistoGram[j] * j;//灰度值总数
    }
    SigmaB = -1;
    for (j = MinValue; j < MaxValue; j++)
    {
        PixelBack = PixelBack + HistoGram[j];   //前景像素点数
        PixelFore = Amount - PixelBack;         //背景像素点数
        OmegaBack = (double)PixelBack / Amount;//前景像素百分比
        OmegaFore = (double)PixelFore / Amount;//背景像素百分比
        PixelIntegralBack += HistoGram[j] * j;  //前景灰度值
        PixelIntegralFore = PixelIntegral - PixelIntegralBack;//背景灰度值
        MicroBack = (double)PixelIntegralBack / PixelBack;   //前景灰度百分比
        MicroFore = (double)PixelIntegralFore / PixelFore;   //背景灰度百分比
        Sigma = OmegaBack * OmegaFore * (MicroBack - MicroFore) * (MicroBack - MicroFore);//计算类间方差
        if (Sigma > SigmaB)                    //遍历最大的类间方差g //找出最大类间方差以及对应的阈值
        {
        SigmaB = Sigma;
        Threshold = j;
        }
    }
    return Threshold;                        //返回最佳阈值;
}

uint8_t get_threshold() {//灰度值图像直方图
    uint8_t histogram[256];

    for (int i = 0; i < c_h; ++i) {
        uint8_t *one_h = mt9v03x_image_dvp[i];
        for (int j = 0; j < c_w; ++j) {
            histogram[one_h[j]]++;
        }
    }
    // return otsu_threshold(histogram, c_h * c_w);
    return GetOSTU(mt9v03x_image_dvp);
}

/*==================================================================
* 函数名: Get_Bin_Image
* 功能: 对灰度值图像进行二值化
* 输入: void
* 输出: void
* 用法: Get_Bin_Image();
* 修改记录:
===================================================================*/
void Get_Pixle(void)
{  
  uint8 Gate;
  Gate = GetOSTU(mt9v03x_image_dvp);
  for(uint8 hang=0;hang<MT9V03X_DVP_H;hang++)
    for(uint8 lie=0;lie<MT9V03X_DVP_W;lie++)
    {
      if(mt9v03x_image_dvp[hang][lie]>=Gate)
        Pixle[hang][lie]=1;
      else
        Pixle[hang][lie]=0;
    }
}

/*==================================================================
* 函数名: Bin_Image_Filter
* 功能: 对二值化图像进行降噪
* 输入: void
* 输出: void
* 用法: Bin_Image_Filter(Bin_Image,row,line);
* 修改记录:
===================================================================*/
void Pixle_Filter (void){
    uint16 nr; //行
    uint16 nc; //列

    for (nr = 1; nr < MT9V03X_DVP_H - 1; nr++)
    {
        for (nc = 1; nc < MT9V03X_DVP_W - 1; nc = nc + 1)
        {
            if ((Pixle[nr][nc] == 0)
                    && (Pixle[nr - 1][nc] + Pixle[nr + 1][nc] + Pixle[nr][nc + 1] + Pixle[nr][nc - 1] > 2))
            {
                Pixle[nr][nc] = 1;
            }
            else if ((Pixle[nr][nc] == 1)
                    && (Pixle[nr - 1][nc] + Pixle[nr + 1][nc] + Pixle[nr][nc + 1] + Pixle[nr][nc - 1] < 2))
            {
                Pixle[nr][nc] = 0;
            }
        }
    }
}

/************************************************************
【函数名称】Horizontal_line
【功    能】横向巡线函数
【参    数】无
【返 回 值】无
【实    例】Horizontal_line(Bin_Image,20,20);
【注意事项】无
***********************************************************/
uint8_t Horizontal_line(){
  uint8_t L1,R1;
  uint8_t L2,R2;
  uint8_t L3,R3;
  uint8_t midline;
  if(Pixle[Row][Col] == 1){
    L1 = Col;
    R1 = Col;
    while(Pixle[Row][L1--] == 1){}
    while(Pixle[Row][R1++] == 1){}
    midline = (L1+R1+L2+R2+R3+L3)/2;
  }
  return midline;
}

// /************************************************************
// 【函数名称】CommonRectificate
// 【功    能】补线(主要是看找的黑线是否标准)
// 【参    数】无
// 【返 回 值】无
// 【实    例】CommonRectificate(unsigned char data[],unsigned char begin,unsigned char end);
// 【注意事项】无
// ***********************************************************/
// void CommonRectificate(unsigned char data[],unsigned char begin,unsigned char end){
//        unsigned char MidPos = 0;
//        if (end > 60-1)
//        {
//           end = 60-1;
//        }
//        if (begin == end)
//        {
//           data[begin] = (data[begin-1]+data[begin+1])>>1;
//          // BlackLineData[begin] =  LeftBlack[begin] + (RightBlack[begin]-LeftBlack[begin])/2;
//        }
//        else if(begin < end)
//        {
//           MidPos = (begin+end)>>1;
//           data[MidPos] = (data[begin]+data[end])>>1;
//           //BlackLineData[MidPos] =  LeftBlack[MidPos] + (RightBlack[MidPos]-LeftBlack[MidPos])/2;
//           if (begin + 1 < MidPos)
//           {
//              CommonRectificate(data,begin,MidPos);
//           }
//           if (MidPos + 1 < end)
//           {
//              CommonRectificate(data,MidPos,end);
//           }
//        }
// }
