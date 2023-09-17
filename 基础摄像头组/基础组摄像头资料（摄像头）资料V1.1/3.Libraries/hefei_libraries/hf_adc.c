/*********************************************************************************************************************
 * @file            hf_adc.c
 * @brief           ADC����
 * @author          FengGuorong
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-8
 ********************************************************************************************************************/

#include "hf_adc.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ADC��ʼ��
//  @param      ADC_INx_Ax              ѡ��ADCͨ������hf_adc.h�ڹ���ADCͨ���Ķ���
//  @return     void
//  Sample usage:               adc_init(ADC_IN0_A0);//��ʼ��A0����ΪADC����
//-------------------------------------------------------------------------------------------------------------------
void adc_init(ADCCH_enum ADC_INx_xx)
{
    /* ��ʼ��ADC�ṹ�� */
    ADC_InitTypeDef ADC_InitStructure;

    /* ����GPIO��ADC1��ʱ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 , ENABLE );   //ʹ��ADC1ͨ��ʱ�ӣ�Ĭ�ϲ���ADC1

    /* ����ADCͨ����ʼ��GPIO */
    adc_gpio_init(ADC_INx_xx);

    /* ����ADC��Ƶ���ӣ�����APB2��ʱ�ӽ������� */
    //RCC_ADCCLKConfig(RCC_PCLK2_Div2);
    if(sys_clk > 84000000)  RCC_ADCCLKConfig(RCC_PCLK2_Div8);           //����ADC��Ƶ���ӣ�ADC������ʲ��ܳ���14M
    else RCC_ADCCLKConfig(RCC_PCLK2_Div6);

    ADC_DeInit(ADC1);                                                   //��λADC1

    /* ����ADC��ʼ������ */
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;                  //ADC����ģʽ:ADC1�����ڶ���ģʽ
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;                       //ģ��ת�������ڵ�ͨ��ģʽ
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;                 //ģ��ת�������ڵ���ת��ģʽ
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; //ת��������������ⲿ��������
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;              //ADC�����Ҷ���
    ADC_InitStructure.ADC_NbrOfChannel = 1;                             //˳����й���ת����ADCͨ������Ŀ
    ADC_Init(ADC1, &ADC_InitStructure);                                 //����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���

    ADC_Cmd(ADC1, ENABLE);                                              //ʹ��ָ����ADC1
//    ADC_BufferCmd(ADC1, DISABLE);                                       //disable buffer

    ADC_ResetCalibration(ADC1);                                         //ʹ�ܸ�λУ׼
    while(ADC_GetResetCalibrationStatus(ADC1));                         //�ȴ���λУ׼����
    ADC_StartCalibration(ADC1);                                         //����ADУ׼
    while(ADC_GetCalibrationStatus(ADC1));                              //�ȴ�У׼����
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ADCת��һ��
//  @param      ADC_INx_Ax      ѡ��ADCͨ��
//  @param      resolution      �ֱ���(8λ 10λ 12λ)
//  @return     void
//  Sample usage:               adc_convert(ADC_IN0_A0, ADC_8BIT);  //�ɼ�A0�˿ڷ���8λ�ֱ��ʵ�ADֵ
//-------------------------------------------------------------------------------------------------------------------
uint16 adc_convert(ADCCH_enum ADC_INx_xx, ADCRES_enum resolution)
{
    /* ����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ�� */
    ADC_RegularChannelConfig(ADC1, (uint8)ADC_INx_xx, 1, ADC_SampleTime_239Cycles5);  //ADC1,ADCͨ��,����ʱ��Ϊ41.5����
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);                                          //ʹ��ָ����ADC1�����ת����������
    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));                                 //�ȴ�ת������
    return ((ADC1->RDATAR)>>resolution);                                            //�������һ��ADC1�������ת�����
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ADCת��N��
//  @param      ADC_IN0_Ax      ѡ��ADCͨ��
//  @param      resolution      �ֱ���(8λ 10λ 12λ)
//  @param      count           ת������
//  @return     void
//  Sample usage:               adc_convert(ADC_IN0_A0, ADC_8BIT,5);  //�ɼ�A0�˿ڷ���8λ�ֱ��ʵ�ADֵ���ɼ����ȡƽ��ֵ
//-------------------------------------------------------------------------------------------------------------------
uint16 adc_mean_filter(ADCCH_enum ADC_INx_xx, ADCRES_enum resolution, uint8 count)
{
    uint8 i;
    uint32 sum;

    assert(count);                                      //���Դ�������Ϊ0

    sum = 0;
    for(i=0; i<count; i++)
    {
        sum += adc_convert(ADC_INx_xx, resolution);
    }

    sum = sum/count;
    return sum;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ADC���ų�ʼ��
//  @param      ADC_INx_Ax          ��ѡ��Χ��hf_adc.h��ADCCH_enumö��ֵȷ��
//  @return     void
//  Sample usage:           �ڲ�ʹ��  �û��������
//-------------------------------------------------------------------------------------------------------------------
void adc_gpio_init(ADCCH_enum ADC_INx_xx)
{
    if(ADC_IN0_A0 == ADC_INx_xx)            gpio_init(A0, GPI, 0, IN_AIN);
    else if(ADC_IN1_A1 == ADC_INx_xx)       gpio_init(A1, GPI, 0, IN_AIN);
    else if(ADC_IN2_A2 == ADC_INx_xx)       gpio_init(A2, GPI, 0, IN_AIN);
    else if(ADC_IN3_A3 == ADC_INx_xx)       gpio_init(A3, GPI, 0, IN_AIN);
    else if(ADC_IN4_A4 == ADC_INx_xx)       gpio_init(A4, GPI, 0, IN_AIN);
    else if(ADC_IN5_A5 == ADC_INx_xx)       gpio_init(A5, GPI, 0, IN_AIN);
    else if(ADC_IN6_A6 == ADC_INx_xx)       gpio_init(A6, GPI, 0, IN_AIN);
    else if(ADC_IN7_A7 == ADC_INx_xx)       gpio_init(A7, GPI, 0, IN_AIN);
    else if(ADC_IN8_B0 == ADC_INx_xx)       gpio_init(B0, GPI, 0, IN_AIN);
    else if(ADC_IN9_B1 == ADC_INx_xx)       gpio_init(B1, GPI, 0, IN_AIN);
    else if(ADC_IN10_C0 == ADC_INx_xx)      gpio_init(C0, GPI, 0, IN_AIN);
    else if(ADC_IN11_C1 == ADC_INx_xx)      gpio_init(C1, GPI, 0, IN_AIN);
    else if(ADC_IN12_C2 == ADC_INx_xx)      gpio_init(C2, GPI, 0, IN_AIN);
    else if(ADC_IN13_C3 == ADC_INx_xx)      gpio_init(C3, GPI, 0, IN_AIN);
    else if(ADC_IN14_C4 == ADC_INx_xx)      gpio_init(C4, GPI, 0, IN_AIN);
    else if(ADC_IN15_C5 == ADC_INx_xx)      gpio_init(C5, GPI, 0, IN_AIN);
}


