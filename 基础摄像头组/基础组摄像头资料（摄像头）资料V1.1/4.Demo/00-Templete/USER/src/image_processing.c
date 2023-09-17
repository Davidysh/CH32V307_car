
#include "image_processing.h"

#include "dis_camera.h"
#include "message.h"
#include "HF_Double_DC_Motor.h"
#include <stdint.h>

#define Row  60 
#define Col  94
uint8_t midline[MT9V03X_DVP_H];//变量可能要改
uint8_t leftline[MT9V03X_DVP_H];
uint8_t rightline[MT9V03X_DVP_H];
uint8_t flag_show_status = 0;
#define  _avg_fre 12
static uint8_t _threshold_avg[_avg_fre] = {0};
static uint8_t _pos = 0;
uint8_t Pixle[MT9V03X_DVP_H][MT9V03X_DVP_W];

/*************************************************************** 
* 函数名称：GetOSTU(mt9v03x_csi_image); 大津法
* 函数输入：摄像头传感器图像数组（mt9v03x_csi_image）
* 函数输出：阈值大小 （Threshold）
* 功能说明：求阈值大小 
***************************************************************/ 
uint8 GetOSTU(uint8 mt9v03x_image_dvp[MT9V03X_DVP_H][MT9V03X_DVP_W])
{ 
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

/*************************************************************** 
* 函数名称：Get_Pixle(void)
* 函数输入：无
* 函数输出：无
* 功能说明：二值化处理图像像素点
***************************************************************/
void Get_Pixle(void)
{  
  uint8 Gate;
  uint8_t Pixle[MT9V03X_DVP_H][MT9V03X_DVP_W];
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

// /*==================================================================
// * 函数名: Get_Use_Image
// * 功能: 获取比赛所用的图像大小即对图像进行分割选取
// * 输入: void
// * 输出: (Pixle[row][line])分割后的二维数组
// * 用法: Get_Use_Image();
// * 修改记录:
// ===================================================================*/
// int** Get_Use_Image(void){
//     short i = 0, j = 0, row = 0, line = 0;
//     int** Image;
//     for (i = 0; i < d_h; i += 2)          
//     // for (i = 0; i < IMAGEH; i += 3)       
//     {
//         for (j = 0; j <= d_w; j += 2)     
//         // for (j = 0; j <= IMAGEW; j += 3)  
//         {
//             Image[row][line] = mt9v03x_image_dvp[i][j];//mt9v03x_image_dvp是灰度值图像
//             line++;
//         }
//         line = 0;
//         row++;
//     }
//     return Image;
// }

/*==================================================================
* 函数名: Pixle_Filter
* 功能: 对二值化图像进行降噪
* 输入: void
* 输出: void
* 用法: Pixle_Filter();
* 修改记录:
===================================================================*/
void Pixle_Filter (int Pixle[MT9V03X_DVP_H][MT9V03X_DVP_W]){
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
【实    例】Horizontal_line();
【注意事项】无
***********************************************************/
void Horizontal_line(void)
{
  uint8 i,j;
  if(Pixle[Row-1][Col/2]==0)//不知道干嘛的
  {
    if(Pixle[Row-1][5] == 1)
      midline[Row]=5;
    else if(Pixle[Row-1][Col-5] == 1)
      midline[Row]=Col-5;
    else
      midline[Row]=Col/2;
  }
  else
	{
    midline[Row]=Col/2;		
	}
	
  for(i=Row-1;i>0;i--)//扫左边界
  {
    for(j=midline[i+1];j>=0;j--)
    {
      if(Pixle[i][j]==0||j==0)
      {
        leftline[i]=j;
        break;
      }
    }
    for(j=midline[i+1];j<=Col-1;j++)//扫右边界
    {
      if(Pixle[i][j]==0||j==Col-1)
      {
        rightline[i]=j;
        break;
      }
    }

    midline[i]=(leftline[i]+rightline[i])/2;//计算中线位置

    if(Pixle[i-1][midline[i]] == 0 ||i == 0)
    {
    for(j = i;j > 0; --j)
    {
      midline[j] = midline[i];
      leftline[j] = midline[i];
      rightline[j] = midline[i];
    }
      break;
    }
  }
}

/************************************************************      
【函数名称】Get_mid
【功    能】横向巡线函数
【参    数】无
【返 回 值】无
【实    例】Get_mid();
【注意事项】无
***********************************************************/
uint8 Get_mid(void){
  int mid;
  int L1,R1;
  int L3,R3;
  int L2,R2;
  if(Pixle[Row][Col] == 1){
    L1 = Col;
    R2 = Col;

    while(Pixle[Row + 1][L1--] == 1){}
    while(Pixle[Row + 1][R1++] == 1){} 
    while(Pixle[Row][L2--] == 1){}
    while(Pixle[Row][R2++] == 1){}
    while(Pixle[Row - 1][L3--] == 1){}
    while(Pixle[Row - 1][R3++] == 1){}
    mid = (L1+L2+L3+R1+R2+R3)/2;
 }
 return mid;
}