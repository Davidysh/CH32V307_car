/*********************************************************************************************************************
* @file            HF_MT9V03X.c
* @author          Fantastic Potato
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220905
 ********************************************************************************************************************/

#include "HF_MT9V03X.h"

uint8_t *camera_buffer_addr;                                                    // ����ͷ��������ַָ��

uint8_t mt9v03x_finish_flag_dvp = 0;                                                // һ��ͼ��ɼ���ɱ�־λ
uint8_t mt9v03x_image_dvp[MT9V03X_DVP_H][MT9V03X_DVP_W];

static          uint8_t     receive_dvp[3];
static          uint8_t     receive_num_dvp = 0;
static volatile uint8_t     uart_receive_flag_dvp;

//��Ҫ���õ�����ͷ������
int16_t mt9v03x_set_confing_buffer_dvp[CONFIG_FINISH][2]=
{
    {AUTO_EXP,          0},                                                     // �Զ��ع�����       ��Χ1-63 0Ϊ�ر� ����Զ��ع⿪��  EXP_TIME�������õ����ݽ����Ϊ����ع�ʱ�䣬Ҳ�����Զ��ع�ʱ�������
                                                                                // һ������ǲ���Ҫ����������ܣ���Ϊ�������ع���һ�㶼�ȽϾ��ȣ�����������߷ǳ������ȵ�������Գ������ø�ֵ������ͼ���ȶ���
    {EXP_TIME,          450},                                                   // �ع�ʱ��         ����ͷ�յ�����Զ����������ع�ʱ�䣬������ù���������Ϊ�������������ع�ֵ
    {FPS,               50},                                                    // ͼ��֡��         ����ͷ�յ�����Զ���������FPS���������������Ϊ������������FPS
    {SET_COL,           MT9V03X_DVP_W},                                         // ͼ��������        ��Χ1-752     K60�ɼ���������188
    {SET_ROW,           MT9V03X_DVP_H},                                         // ͼ��������        ��Χ1-480
    {LR_OFFSET,         0},                                                     // ͼ������ƫ����  ��ֵ ��ƫ��   ��ֵ ��ƫ��  ��Ϊ188 376 752ʱ�޷�����ƫ��    ����ͷ��ƫ�����ݺ���Զ��������ƫ�ƣ�������������ü�����������ƫ��
    {UD_OFFSET,         0},                                                     // ͼ������ƫ����  ��ֵ ��ƫ��   ��ֵ ��ƫ��  ��Ϊ120 240 480ʱ�޷�����ƫ��    ����ͷ��ƫ�����ݺ���Զ��������ƫ�ƣ�������������ü�����������ƫ��
    {GAIN,              20},                                                    // ͼ������         ��Χ16-64     ����������ع�ʱ��̶�������¸ı�ͼ�������̶�
    {PCLK_MODE,         1},                                                     // �������MT9V034 V1.5�Լ����ϰ汾֧�ָ����
                                                                                // ����ʱ��ģʽ���� PCLKģʽ     Ĭ�ϣ�0     ��ѡ����Ϊ��0 1��        0������������źţ�1����������źš�(ͨ��������Ϊ0�����ʹ��CH32V307��DVP�ӿڻ�STM32��DCMI�ӿڲɼ���Ҫ����Ϊ1)


    {INIT,              0}                                                      // ����ͷ��ʼ��ʼ��
};

//������ͷ�ڲ���ȡ������������
int16_t mt9v03x_get_confing_buffer_dvp[CONFIG_FINISH-1][2]=
{
    {AUTO_EXP,          0},                                                     // �Զ��ع�����
    {EXP_TIME,          0},                                                     // �ع�ʱ��
    {FPS,               0},                                                     // ͼ��֡��
    {SET_COL,           0},                                                     // ͼ��������
    {SET_ROW,           0},                                                     // ͼ��������
    {LR_OFFSET,         0},                                                     // ͼ������ƫ����
    {UD_OFFSET,         0},                                                     // ͼ������ƫ����
    {GAIN,              0},                                                     // ͼ������
    {PCLK_MODE,         0},                                                     //����ʱ��ģʽ(�������MT9V034 V1.5�Լ����ϰ汾֧�ָ�����)
};

//-------------------------------------------------------------------------------------------------------------------
// @brief       ��������ͷ�ڲ�������Ϣ �ڲ�����
// @param       uartn           ѡ��ʹ�õĴ���
// @param       buff            ����������Ϣ�ĵ�ַ
// @return      uint8_t         1-ʧ�� 0-�ɹ�
// Sample usage:                ���øú���ǰ���ȳ�ʼ������
//-------------------------------------------------------------------------------------------------------------------
static uint8_t mt9v03x_set_config_dvp (int16_t buff[CONFIG_FINISH-1][2])
{
    uint16_t temp, i;
    uint8_t  send_buffer[4];
    int16_t timeout = MT9V03X_INIT_TIMEOUT;

    uart_receive_flag_dvp = 0;

    // ���ò���  ������ο���������ֲ�
    // ��ʼ��������ͷ�����³�ʼ��
    for(i=0; i<CONFIG_FINISH; i++)
    {
        send_buffer[0] = 0xA5;
        send_buffer[1] = buff[i][0];
        temp = buff[i][1];
        send_buffer[2] = temp>>8;
        send_buffer[3] = (uint8_t)temp;
        uart_putbuff(MT9V03X_COF_UART_DVP,send_buffer,4);

        Delay_Ms(2);
    }

    while(!uart_receive_flag_dvp && timeout-- > 0)                                   // �ȴ����ܻش�����
    {
        Delay_Ms(1);
    }
    timeout = MT9V03X_INIT_TIMEOUT;

    uart_receive_flag_dvp = 0;
    while(((0xff != receive_dvp[1]) || (0xff != receive_dvp[2])) && timeout-- > 0)   // �ж������Ƿ��ȡ����Ӧ����
    {
        Delay_Ms(1);
    }

    // ���ϲ��ֶ�����ͷ���õ�����ȫ�����ᱣ��������ͷ��51��Ƭ����eeprom��
    // ����set_exposure_time�����������õ��ع����ݲ��洢��eeprom��
    if(timeout <= 0)                                                         // ��ʱ
        return 1;
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ��ȡ����ͷ�ڲ�������Ϣ �ڲ�����
// @param       uartn           ѡ��ʹ�õĴ���
// @param       buff            ����������Ϣ�ĵ�ַ
// @return      uint8_t         1-ʧ�� 0-�ɹ�
// Sample usage:                ���øú���ǰ���ȳ�ʼ������
//-------------------------------------------------------------------------------------------------------------------
static uint8_t mt9v03x_get_config_dvp (int16_t buff[CONFIG_FINISH-1][2])
{
    uint16_t temp, i;
    uint8_t  send_buffer[4];
    int16_t timeout = MT9V03X_INIT_TIMEOUT;

    for(i=0; i<(CONFIG_FINISH-1); i++)
    {
        send_buffer[0] = 0xA5;
        send_buffer[1] = GET_STATUS;
        temp = buff[i][0];
        send_buffer[2] = temp>>8;
        send_buffer[3] = (uint8_t)temp;
        uart_putbuff(MT9V03X_COF_UART_DVP,send_buffer,4);

        timeout = MT9V03X_INIT_TIMEOUT;
        while(!uart_receive_flag_dvp && timeout-- > 0)                              // �ȴ����ܻش�����
        {
            Delay_Ms(1);
        }
        if(timeout <= 0 && i==0)                                                     // ��ʱ
            return 1;

        uart_receive_flag_dvp = 0;
        buff[i][1] = receive_dvp[1]<<8 | receive_dvp[2];
    }
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       MT9V03X����ͷ�����жϺ���
// @param       void
// @return      void
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void mt9v03x_uart_callback_dvp (void)
{
//    receive_dvp[receive_num_dvp] = ((USART_TypeDef*)uart_index[MT9V03X_COF_UART_DVP])->DATAR & 0xFF;
//    receive_num_dvp++;

    if(uart_query(MT9V03X_COF_UART_DVP, &receive_dvp[receive_num_dvp]))
        receive_num_dvp++;

    if(1 == receive_num_dvp && 0XA5!=receive_dvp[0])
        receive_num_dvp = 0;
    if(3 == receive_num_dvp)
    {
        receive_num_dvp = 0;
        uart_receive_flag_dvp = 1;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ��ȡ����ͷ�̼��汾
// @param       void            ѡ��ʹ�õĴ���
// @return      uint16_t        0-��ȡ���� N-�汾��
// Sample usage:                ���øú���ǰ���ȳ�ʼ������
//-------------------------------------------------------------------------------------------------------------------
uint16_t mt9v03x_get_version_dvp (void)
{
    uint16_t temp;
    uint8_t  send_buffer[4];
    int16_t  timeout = MT9V03X_INIT_TIMEOUT;

    send_buffer[0] = 0xA5;
    send_buffer[1] = GET_STATUS;
    temp = GET_VERSION;
    send_buffer[2] = temp>>8;
    send_buffer[3] = (uint8_t)temp;
    uart_putbuff(MT9V03X_COF_UART_DVP,send_buffer,4);

    while(!uart_receive_flag_dvp && timeout-- > 0)                                  // �ȴ����ܻش�����
    {
        Delay_Ms(1);
    }
    uart_receive_flag_dvp = 0;

    if(timeout <= 0)                                                            // ��ʱ
        return 0;
    return ((uint16_t)(receive_dvp[1]<<8) | receive_dvp[2]);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ������������ͷ�ع�ʱ��
// @param       uartn           ѡ��ʹ�õĴ���
// @param       light           �����ع�ʱ��Խ��ͼ��Խ��������ͷ�յ������ݷֱ��ʼ�FPS��������ع�ʱ��������õ����ݹ�����ô����ͷ��������������ֵ
// @return      uint8_t         1-ʧ�� 0-�ɹ�
// Sample usage:                ���øú���ǰ���ȳ�ʼ������
//-------------------------------------------------------------------------------------------------------------------
uint8_t mt9v03x_set_exposure_time_dvp (uint16_t light)
{
    uint16_t temp;
    uint8_t  send_buffer[4];
    int16_t timeout = MT9V03X_INIT_TIMEOUT;

    send_buffer[0] = 0xA5;
    send_buffer[1] = SET_EXP_TIME;
    temp = light;
    send_buffer[2] = temp>>8;
    send_buffer[3] = (uint8_t)temp;
    uart_putbuff(MT9V03X_COF_UART_DVP,send_buffer,4);

    while(!uart_receive_flag_dvp && timeout-- > 0)                                  // �ȴ����ܻش�����
    {
        Delay_Ms(1);
    }
    uart_receive_flag_dvp = 0;

    temp = receive_dvp[1]<<8 | receive_dvp[2];

    if(timeout <= 0 || temp != light)
        return 0;
    return 1;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       ������ͷ�ڲ��Ĵ�������д����
// @param       uartn           ѡ��ʹ�õĴ���
// @param       addr            ����ͷ�ڲ��Ĵ�����ַ
// @param       data            ��Ҫд�������
// @return      uint8_t         1-ʧ�� 0-�ɹ�
// Sample usage:                ���øú���ǰ���ȳ�ʼ������
//-------------------------------------------------------------------------------------------------------------------
uint8_t mt9v03x_set_reg_dvp (uint8_t addr, uint16_t data)
{
    uint16_t temp;
    uint8_t  send_buffer[4];
    int16_t timeout = MT9V03X_INIT_TIMEOUT;

    send_buffer[0] = 0xA5;
    send_buffer[1] = SET_ADDR;
    temp = addr;
    send_buffer[2] = temp>>8;
    send_buffer[3] = (uint8_t)temp;
    uart_putbuff(MT9V03X_COF_UART_DVP,send_buffer,4);

    Delay_Ms(10);
    send_buffer[0] = 0xA5;
    send_buffer[1] = SET_DATA;
    temp = data;
    send_buffer[2] = temp>>8;
    send_buffer[3] = (uint8_t)temp;
    uart_putbuff(MT9V03X_COF_UART_DVP,send_buffer,4);

    while(!uart_receive_flag_dvp && timeout-- > 0)                                  // �ȴ����ܻش�����
    {
        Delay_Ms(1);
        timeout--;
    }
    uart_receive_flag_dvp = 0;

    temp = receive_dvp[1]<<8 | receive_dvp[2];
    if(timeout <= 0 || temp != data)
        return 0;
    return 1;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      MT9V03X����ͷ���ж�
//  @param      NULL
//  @return     void
//  @since      v1.0
//  Sample usage:               ��isr.c�����ȴ�����Ӧ���жϺ�����Ȼ����øú���(֮�����������жϱ�־λ)
//-------------------------------------------------------------------------------------------------------------------
void mt9v03x_handler_dvp(void)
{
    DVP->DMA_BUF0 = (uint32_t)camera_buffer_addr;       // �ָ�DMA��ַ
    mt9v03x_finish_flag_dvp = 1;                        // ����ͷ�ɼ���ɱ�־λ��1
    DVP->CR0 |= RB_DVP_ENABLE;                          // ���´�DVP���ɼ���һ��ͼ��
}



//-------------------------------------------------------------------------------------------------------------------
// @brief       MT9V03X����ͷ��ʼ��
// @param       void
// @return      uint8_t         1-ʧ�� 0-�ɹ�
// Sample usage:                ʹ��FLEXIO�ӿڲɼ�����ͷ
//-------------------------------------------------------------------------------------------------------------------
uint8_t mt9v03x_init_dvp (void)
{
    //���� ��������ͷ
    uart_init(UART_5, 9600, UART5_TX_C12, UART5_RX_D2);
    //uart_rx_interrupt(MT9V03X_COF_UART_DVP, ENABLE);
    uart_interrupt_init(UART_5,ENABLE, UARTINT_RX);

    interrupt_global_enable();

    uart_receive_flag_dvp = 0;
    if(mt9v03x_get_config_dvp(mt9v03x_get_confing_buffer_dvp))
    {
        assert(0);
        return 1;
    }

    uart_receive_flag_dvp = 0;
    if(mt9v03x_set_config_dvp(mt9v03x_set_confing_buffer_dvp))
    {
        assert(0);
        return 1;
    }

    uart_receive_flag_dvp = 0;
    if(mt9v03x_get_config_dvp(mt9v03x_get_confing_buffer_dvp))
    {
        assert(0);
        return 1;
    }

    interrupt_global_disable();

    // DVP���ų�ʼ��
    dvp_gpio_init(
            MT9V03X_D0_PIN_DVP, MT9V03X_D1_PIN_DVP, MT9V03X_D2_PIN_DVP, MT9V03X_D3_PIN_DVP,
            MT9V03X_D4_PIN_DVP, MT9V03X_D5_PIN_DVP, MT9V03X_D6_PIN_DVP, MT9V03X_D7_PIN_DVP,
            MT9V03X_PCLK_PIN_DVP, MT9V03X_VSY_PIN_DVP, MT9V03X_HERF_PIN_DVP);
    // ���õ�ַ
    camera_buffer_addr = mt9v03x_image_dvp[0];

    // DVP�ӿڳ�ʼ��
    dvp_camera_init((uint32_t *)camera_buffer_addr, NULL, MT9V03X_DVP_W*MT9V03X_DVP_H, 1);
    return 0;
}
