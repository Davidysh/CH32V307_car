################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/liu/Desktop/����С������/����������ͷ���ϣ�����ͷ������V1.1/4.Demo/Libraries/hefei_libraries/board/board.c 

OBJS += \
./hefei_libraries/board/board.o 

C_DEPS += \
./hefei_libraries/board/board.d 


# Each subdirectory must supply rules for building sources it contributes
hefei_libraries/board/board.o: C:/Users/liu/Desktop/����С������/����������ͷ���ϣ�����ͷ������V1.1/4.Demo/Libraries/hefei_libraries/board/board.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\03-Car_uart_interrupt\CODE" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\03-Car_uart_interrupt\USER\src" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\03-Car_uart_interrupt\USER\inc" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

