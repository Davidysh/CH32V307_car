/*********************************************************************************************************************
* @file            main.c
* @brief           Flash程序模板
* @author          lemon
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-3-2
* 向缓冲区写入数据，flash读取缓冲区数据，然后清空缓冲区，读取缓冲区数据，然后将flash中的数据写入缓冲区，而后再读取数据
********************************************************************************************************************/

/* 用户头文件 */
#include "main.h"
/* 全局变量声明 */
extern flash_data_union flash_data_union_buffer[FLASH_DATA_BUFFER_SIZE];// FLASH 操作的数据缓冲区
unsigned char g_flash_flag;
unsigned char key_value;
int* number;
int* number1;
int a;
/* 主函数 */
int main(void)
{
    /* 此处声明需要用到的局部变量 */
    extern flash_data_union flash_data_union_buffer[FLASH_DATA_BUFFER_SIZE];               // FLASH 操作的数据缓冲区
    /* 初始化 */
    uart_init(UART_3, 115200, UART3_TX_B10, UART3_RX_B11);
    board_led_init(LED1);
    key_init(K1);
    key_init(K2);
    key_init(K3);
    key_init(K4);
    printf("This is printf example\r\n"); //串口测试
    board_led_on(LED1);//板载LED灯测试
    a=36;
    number1=&a;
    g_flash_flag=1;
    while(1)
    {
       if(g_flash_flag==1)
       {
           if(flash_check(FLASH_SECTION_62, FLASH_PAGE_3)==1)                      // 判断是否有数据
           {
               flash_erase_page(FLASH_SECTION_62, FLASH_PAGE_3);                // 擦除这一页
           }
           flash_read_page_to_data_buffer(FLASH_SECTION_62, FLASH_PAGE_3);      // 将数据从 flash 读取到缓冲区
           printf("\r\n FLASH_SECTION_INDEX: %d, FLASH_PAGE_INDEX: %d, origin data is :", FLASH_SECTION_62,FLASH_PAGE_3);
           printf("\r\n int32_type : %d", flash_data_union_buffer[2].uint32_type);      // 将缓冲区第 2 个位置的数据以 int32  格式输出
           flash_data_union_buffer[2].int32_type  = -2147483648;                       // 向缓冲区第 2 个位置写入 int32  数据
           printf("\r\n int32_type : %d", flash_data_union_buffer[2].int32_type);      // 将缓冲区第 2 个位置的数据以 int32  格式输出
           flash_write_page_to_data_buffer(FLASH_SECTION_62, FLASH_PAGE_3);     // 向指定 Flash 扇区的页码写入缓冲区数据
           flash_data_buffer_clear();                                           // 清空缓冲区
           printf("\r\n int32_type : %d", flash_data_union_buffer[2].int32_type);      // 将缓冲区第 2 个位置的数据以 int32  格式输出
           flash_read_page_to_data_buffer(FLASH_SECTION_62, FLASH_PAGE_3);      // 将数据从 flash 读取到缓冲区
           printf("\r\n int32_type : %d", flash_data_union_buffer[2].int32_type);      // 将缓冲区第 2 个位置的数据以 int32  格式输出
           uint32 *x;
           uint32 a=2;
           x=&a;
           flash_page_read (FLASH_SECTION_62, FLASH_PAGE_3, (uint32 *)x, 16);
           printf("\r\na值为%p", a);

           printf("\r\n --");//该行无法显示,为了保证上一行的正常显示，故加入此行
           g_flash_flag=0;
       }
       }

}
