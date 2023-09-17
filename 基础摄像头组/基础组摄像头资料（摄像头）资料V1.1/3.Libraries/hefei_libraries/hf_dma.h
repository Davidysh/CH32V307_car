/*********************************************************************************************************************
 * @file            hf_dma.h
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-19
 ********************************************************************************************************************/

#ifndef _hf_dma_h
#define _hf_dma_h

#include "common.h"
#include "ch32v30x_dma.h"
#include "ch32v30x_rcc.h"

/* ö�ٶ������� */
/* ö��DMA���� */
typedef enum
{
    P2M = 0,        //������Ϊ���ݴ������Դ
    M2P             //������Ϊ���ݴ����Ŀ�ĵ�
}DMADIR_enum;

/* ö��DMAͨ�� */
typedef enum
{
    DMA1_CH1 = 0,
    DMA1_CH2,
    DMA1_CH3,
    DMA1_CH4,
    DMA1_CH5,
    DMA1_CH6,
    DMA1_CH7,

    DMA2_CH1,
    DMA2_CH2,
    DMA2_CH3,
    DMA2_CH4,
    DMA2_CH5,
    DMA2_CH6,
    DMA2_CH7,
    DMA2_CH8,
    DMA2_CH9,
    DMA2_CH10,
    DMA2_CH11,
}DMA_CH_enum;

/* �������� */

/* �ⲿ�������û������е���  */
/* ����DMA���� */
void dma_init(DMA_CH_enum DMA_CHx, uint32_t ppaddr, uint32_t memaddr, uint32_t num, DMADIR_enum directions);


#endif
