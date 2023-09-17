/*********************************************************************************************************************
 * @file            hf_i2c_hardware.c
 * @brief           Ӳ��IIC����
 * @author          Fantastic Potato
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-5
 ********************************************************************************************************************/

#include "hf_i2c_hardware.h"

/* �궨�� */
#define SIZE sizeof(TEXT_Buffer)

/* �ڲ��������� */
const u8 TEXT_Buffer[]={""};

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Ӳ��I2C��ʼ��
// @param        I2Cx(x=0,1)                ѡ��I2Cͨ��
//  @param      address                     I2C�豸�����ַ
//  @return     void
//  Sample usage:                           i2c_hardware_init(I2C1,1000, 0x02); //I2C1,����Ϊ1KHz,��ַΪ0x02
//-------------------------------------------------------------------------------------------------------------------
void i2c_hardware_init(I2C_TypeDef* I2Cx, u16 address)
{
    I2C_InitTypeDef I2C_InitTSturcture;

    uint32_t i2c_rcc;

    /* GPIOʱ�ӳ�ʼ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE );

    /* I2C������ʼ�� */
    if (I2Cx == I2C1)           //ѡ��I2C1
    {
        i2c_rcc = RCC_APB1Periph_I2C1;

        /* GPIO��ʼ�� */
        gpio_init(B6, GPO, 1, SPEED_50MHZ | OUT_AF_OD);
        gpio_init(B7, GPO, 1, SPEED_50MHZ | OUT_AF_OD);
    }
    else   //ѡ��I2C2
    {
        i2c_rcc = RCC_APB1Periph_I2C2;

        /* GPIO��ʼ�� */
        gpio_init(B10, GPO, 1, SPEED_50MHZ | OUT_AF_OD);
        gpio_init(B11, GPO, 1, SPEED_50MHZ | OUT_AF_OD);
    }

    /* I2Cʱ�ӳ�ʼ�� */
    RCC_APB1PeriphClockCmd( i2c_rcc, ENABLE );

    /* I2C1��ʼ�� */
    I2C_InitTSturcture.I2C_ClockSpeed = 400000;              //������
    I2C_InitTSturcture.I2C_Mode = I2C_Mode_I2C;             //����Ϊ��ͨI2C����ģʽ
    I2C_InitTSturcture.I2C_DutyCycle = I2C_DutyCycle_2;     //ָ��I2C����ģʽռ�ձ�
    I2C_InitTSturcture.I2C_OwnAddress1 = address;           //ָ��I2C�����豸��ַ
    I2C_InitTSturcture.I2C_Ack = I2C_Ack_Enable;            //ʹ�ܻ��߹ر���Ӧ (һ�㶼��ʹ��)
    I2C_InitTSturcture.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;  //ָ����ַ�ĳ���,������7λ��10λ
    I2C_Init( I2Cx, &I2C_InitTSturcture );
    I2C_Cmd( I2Cx, ENABLE );

    I2C_AcknowledgeConfig( I2Cx, ENABLE );
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2C���͵��ֽ�
// @param        I2Cx(x=0,1)                ѡ��I2Cͨ��
// @param        slave_address              �ӻ���ַ
// @param        data                       ���͵��ֽ�
// @return        void
// Sample usage:        i2c_send_byte(I2C1, 0x21);
//                      I2C1��ʼͨ��,��������0x21
//-------------------------------------------------------------------------------------------------------------------
void i2c_send_byte(I2C_TypeDef * I2Cx, uint8_t slave_address, uint8_t data)
{
    /* �ȴ�I2C���߿��� */
    while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));

    /* ������ʼ�ź� */
    I2C_GenerateSTART(I2Cx, ENABLE);

    /* ѡ��I2C��Ϊ����ģʽ */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_MODE_SELECT ) );

    /* ���ʹӻ���ַ */
    I2C_Send7bitAddress( I2Cx, slave_address, I2C_Direction_Transmitter );

    /* �ȴ���ַ������� */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );

    /* �����ֽ����� */
    if( I2C_GetFlagStatus( I2Cx, I2C_FLAG_TXE ) !=  RESET )
    {
        I2C_SendData( I2Cx, data );
    }

    /* �ȴ�������� */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    /* I2Cͨ��ֹͣ�ź�  */
    I2C_GenerateSTOP( I2Cx, ENABLE );

    /* ���ֹͣ�ź��Ƿ������ */
//    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_SLAVE_STOP_DETECTED ) );
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2C��Ĵ�����ַд�뵥�ֽ�
// @param        I2Cx(x=0,1)           ѡ��I2Cͨ��
// @param        write_address         д��ӻ���ַ
// @param        reg_address           �Ĵ�����ַ
// @param        data                  ���͵��ֽ�
// @return       void
// Sample usage:        i2c_send_reg_byte(0x34, 0x21);
//                      //I2C_PERIPH��ʼͨ��,���ͼĴ�����ַ0x34,��������0x21
//-------------------------------------------------------------------------------------------------------------------
void i2c_send_reg_byte(I2C_TypeDef * I2Cx, uint8_t write_address, uint8_t reg_address, uint8_t data)
{
    /* �ȴ�I2C���߿��� */
    while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));

    /* ������ʼ�ź� */
    I2C_GenerateSTART(I2Cx, ENABLE);

    /* ѡ��I2C��Ϊ����ģʽ */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_MODE_SELECT ) );

    /* ���ʹӻ���ַ */
    I2C_Send7bitAddress( I2Cx, write_address, I2C_Direction_Transmitter );

    /* �ȴ���ַ������� */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );

    /* 8λ���ݵ�ַ */
#if (Address_Lenth  == Address_8bit)

    I2C_SendData( I2Cx, (uint8_t)(reg_address&0x00FF) );
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    /* 16λ���ݵ�ַ */
#elif (Address_Lenth  == Address_16bit)

    I2C_SendData( I2Cx, (u8)(reg_address>>8) );
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
    I2C_SendData( I2Cx, (u8)(reg_address&0x00FF) );
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
#endif

    /* �����ֽ����� */
    if( I2C_GetFlagStatus( I2Cx, I2C_FLAG_TXE ) !=  RESET )
    {
        I2C_SendData( I2Cx, data );
    }

    /* �ȴ�������� */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );


    /* I2Cͨ��ֹͣ�ź�  */
    I2C_GenerateSTOP( I2Cx, ENABLE );

    /* ���ֹͣ�ź��Ƿ������ */
//    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_SLAVE_STOP_DETECTED ) );
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2C��ȡ���ֽ�
// @param        I2Cx(x=0,1)                ѡ��I2Cͨ��
// @param        write_address              д��ӻ���ַ���������ֲ�ȷ����write_address������read_addressһ��
// @param        read_address               ��ȡ�ӻ���ַ
// @param        reg_address                �ӻ��Ĵ�����ַ
// @param        data_buffer                ���ݴ�ŵ�ַ
// @return        void
// Sample usage:        i2c_send_byte(I2C1, 0x21);
//                      I2C1��ʼͨ��,��������0x21
//-------------------------------------------------------------------------------------------------------------------
void i2c_read_reg_byte(I2C_TypeDef * I2Cx, uint8_t write_address, uint8_t read_address, uint8_t reg_address, uint8_t *data_buffer)
{
    /* �ȴ�I2C���߿��� */
    while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));

    /* ������ʼ�ź� */
    I2C_GenerateSTART(I2Cx, ENABLE);
    /* ѡ��I2C��Ϊ����ģʽ */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_MODE_SELECT ) );

    /* ���ʹӻ���ַ��д  */
#if (Hard_Device == Hard_Rtc)
    I2C_Send7bitAddress( I2Cx, write_address, I2C_Direction_Transmitter );
    /* �ȴ���ַ������� */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );
#endif

    /* �������ݵ�ַ */
#if (Address_Lenth  == Address_8bit)

        I2C_SendData( I2Cx, (uint8_t)(reg_address&0x00FF) );
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#elif (Address_Lenth  == Address_16bit)

        I2C_SendData( I2Cx, (u8)(reg_address>>8) );
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
        I2C_SendData( I2Cx, (u8)(reg_address&0x00FF) );
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#endif

    /* ���¿�ʼ */
    /* ������ʼ�ź� */
    I2C_GenerateSTART(I2Cx, ENABLE);
    /* ѡ��I2C��Ϊ����ģʽ */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_MODE_SELECT ) );

#if (Hard_Device == Hard_Rtc)
    /* ���ʹӻ���ַ����  */
    I2C_Send7bitAddress( I2Cx, read_address, I2C_Direction_Receiver );
    /* �ȴ���ַ������� */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED ) );
#endif

    /* ��һ�ֽ����� */
    I2C_AcknowledgeConfig(I2Cx, DISABLE);   //���ֽڶ��Ͷ��ֽڶ���Ӧ��λ������������������Ӧ��
    while(!I2C_GetFlagStatus(I2Cx, I2C_FLAG_RXNE));
    *data_buffer = I2C_ReceiveData(I2Cx);          //��ȡ����

    /* I2Cͨ��ֹͣ�ź�  */
    I2C_GenerateSTOP( I2Cx, ENABLE );
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        I2C��Ĵ�������д��
// @param        I2Cx(x=0,1)           ѡ��I2Cͨ��
// @param        write_address         д��ӻ���ַ
// @param        reg_address           �ӻ��Ĵ�����ַ
// @param        p_buffer              д����ֽڴ�ŵ������ַ
// @param        length                д����ֽ�����
// @return       void
// Sample usage:        uint8_t data[3]; i2c_send_reg_bytes(I2C1,0x75, 0x22, &data, 3);
//                      //I2C1��0x75�Ĵӻ���ַ��0x22�Ĵ���д��data���飬��������3���ֽ�
//-------------------------------------------------------------------------------------------------------------------
void i2c_send_reg_bytes(I2C_TypeDef * I2Cx, uint8_t write_address, uint8_t reg_address, uint8_t *p_buffer, uint16_t length)
{
    /* �ȴ�I2C���߿��� */
    while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));

    /* ������ʼ�ź� */
    I2C_GenerateSTART(I2Cx, ENABLE);
    /* ѡ��I2C��Ϊ����ģʽ */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_MODE_SELECT ) );

    /* ���ʹӻ���ַ��д  */
    I2C_Send7bitAddress( I2Cx, write_address, I2C_Direction_Transmitter );
    /* �ȴ���ַ������� */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );

    /* �������ݵ�ַ */
#if (Address_Lenth  == Address_8bit)

        I2C_SendData( I2Cx, (uint8_t)(reg_address&0x00FF) );
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#elif (Address_Lenth  == Address_16bit)

        I2C_SendData( I2Cx, (u8)(reg_address>>8) );
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
        I2C_SendData( I2Cx, (u8)(reg_address&0x00FF) );
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#endif

    /* ����д���� */
    for(uint16_t cnt=0; cnt<(length-1); cnt++)
    {
        /* �����ֽ����� */
        if( I2C_GetFlagStatus( I2Cx, I2C_FLAG_TXE ) !=  RESET )
        {
            I2C_SendData( I2Cx, *p_buffer );
        }
        /* �ȴ�������� */
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
        p_buffer++;
    }
    //���һ���ֽڶ�����������ֹHardFault_Handler
    if( I2C_GetFlagStatus( I2Cx, I2C_FLAG_TXE ) !=  RESET )
    {
        I2C_SendData( I2Cx, *p_buffer );
    }
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    /* I2Cͨ��ֹͣ�ź�  */
    I2C_GenerateSTOP( I2Cx, ENABLE );
}



//-------------------------------------------------------------------------------------------------------------------
// @brief        I2Cд�����飬����д��
// @param        I2Cx(x=0,1)
// @param        write_address         д��ӻ���ַ
// @param        reg_address           �ӻ��Ĵ�����ַ
// @param        p_buffer              д����ֽڴ�ŵ������ַ
// @param        length                д����ֽ�����
// @return       void
// Sample usage:        uint8_t data[3]; i2c_send_reg_bytes(I2C1,0x75, 0x22, &data, 3);
//                      //I2C1��0x75�Ĵӻ���ַ��0x22�Ĵ���д��data���飬��������3���ֽ�
//-------------------------------------------------------------------------------------------------------------------
/*
 * ҳд����˼����ָ��ӻ���ַ��ҳд���ݣ�Ҳ����EEPROM�ڲ�����ַָ�롱ָ��ĵ�ַ����ҳ��
 * ÿ��д֮ǰ���Ƕ�Ҫ������ַָ�롱ָ��һ����ַ��������Դ����д�Ĺ����С�
 * һ��д�����һ���ֽڣ�����ص���ҳ�׵�ַ����д��ȥ����ˣ�д���ҳ��������Ҫ���½�����ַָ�롱ָ����һҳ�׵�ַ */
void i2c_send_reg_buffer(I2C_TypeDef * I2Cx, uint8_t write_address, uint8_t reg_address, uint8_t *p_buffer, uint16_t length)
{
    uint8_t number_of_page, number_of_single, address, count;
    number_of_page = 0;
    number_of_single = 0;
    address = 0;
    count = 0;

    address = reg_address % I2C_PAGE_SIZE;
    count = I2C_PAGE_SIZE - address;
    number_of_page = length / I2C_PAGE_SIZE;
    number_of_single = length % I2C_PAGE_SIZE;

    /* ���д���ַ��ҳ��С����  */
    if (0 == address)
    {
        while (number_of_page--)
        {
            i2c_send_reg_bytes(I2Cx, write_address, reg_address, p_buffer, I2C_PAGE_SIZE);
            write_address += I2C_PAGE_SIZE;
            p_buffer += I2C_PAGE_SIZE;
        }
        if (0 != number_of_single)
        {
            i2c_send_reg_bytes(I2Cx, write_address, reg_address, p_buffer, I2C_PAGE_SIZE);
        }
    }
    else
    {
        /* ���д���ַ��ҳ��С������ */
        if (length < count)
        {
            i2c_send_reg_bytes(I2Cx, write_address, reg_address, p_buffer, count);
        }
        else
        {
            length -= count;
            number_of_page = length / I2C_PAGE_SIZE;
            number_of_single = length % I2C_PAGE_SIZE;
            if (0 != count)
            {
                i2c_send_reg_bytes(I2Cx, write_address, reg_address, p_buffer, count);
                write_address += count;
                p_buffer += count;
            }
            /* дҳ�� */
            while (number_of_page--)
            {
                i2c_send_reg_bytes(I2Cx, write_address, reg_address, p_buffer, count);
                write_address += I2C_PAGE_SIZE;
                p_buffer += I2C_PAGE_SIZE;
            }
            /* д�����ֽ� */
            if (0 != number_of_single)
            {
                i2c_send_reg_bytes(I2Cx, write_address, reg_address, p_buffer, count);
            }
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------
// @brief        I2C��ȡ����
// @param        I2Cx(x=0,1)
// @param        write_address              д��ӻ���ַ���������ֲ�ȷ����write_address������read_addressһ��
// @param        read_address               ��ȡ�ӻ���ַ
// @param        reg_address                �ӻ��Ĵ�����ַ
// @param        data_buffer                ���ݴ�ŵ�ַ
// @param        length                     ��ȡ���ֽ�����
// @return       void
// Sample usage:        uint8_t data[3]; i2c_read_buffer(I2C1, 0x68, 0x75, &data, 3);
//                      //I2C1��ȡ�ӻ���ַΪ0x68�������ڲ���ַΪ0x70�ļĴ�������������data��
//-------------------------------------------------------------------------------------------------------------------
void i2c_read_reg_buffer(I2C_TypeDef * I2Cx, uint8_t write_address, uint8_t read_address, uint8_t reg_address, uint8_t *data_buffer, uint16_t length)
{
    /* �ȴ�I2C���߿��� */
    while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));

    /* ������ʼ�ź� */
    I2C_GenerateSTART(I2Cx, ENABLE);
    /* ѡ��I2C��Ϊ����ģʽ */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_MODE_SELECT ) );

    /* ���ʹӻ���ַ��д  */
    I2C_Send7bitAddress( I2Cx, write_address, I2C_Direction_Transmitter );
    /* �ȴ���ַ������� */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );

    /* �������ݵ�ַ */
#if (Address_Lenth  == Address_8bit)

        I2C_SendData( I2Cx, (uint8_t)(reg_address&0x00FF) );
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#elif (Address_Lenth  == Address_16bit)

        I2C_SendData( I2Cx, (u8)(reg_address>>8) );
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
        I2C_SendData( I2Cx, (u8)(reg_address&0x00FF) );
        while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

#endif

    /* ���¿�ʼ */
    /* ������ʼ�ź� */
    I2C_GenerateSTART(I2Cx, ENABLE);
    /* ѡ��I2C��Ϊ����ģʽ */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_MODE_SELECT ) );

    /* ���ʹӻ���ַ����  */
    I2C_Send7bitAddress( I2Cx, read_address, I2C_Direction_Receiver );
    /* �ȴ���ַ������� */
    while( !I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED ) );

    /* �����ֽ����� */
    for(uint16_t cnt=0; cnt<(length-1); cnt++)
    {
        I2C_AcknowledgeConfig(I2Cx, ENABLE);    //���ֽڶ��Ͷ��ֽڶ���Ӧ��λ��������������Ӧ��
        while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_RXNE) == RESET);
        *data_buffer = I2C_ReceiveData(I2Cx);
    }
    I2C_AcknowledgeConfig(I2Cx, DISABLE);    //���ֽڶ��Ͷ��ֽڶ���Ӧ��λ������������������Ӧ��
    while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_RXNE) == RESET);
    *data_buffer = I2C_ReceiveData(I2Cx);

    /* I2Cͨ��ֹͣ�ź�  */
    I2C_GenerateSTOP( I2Cx, ENABLE );
}
