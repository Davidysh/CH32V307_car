################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/liu/Desktop/����С������/����������ͷ���ϣ�����ͷ������V1.1/4.Demo/Libraries/Device/Core/core_riscv.c 

OBJS += \
./CH32V30x/Core/core_riscv.o 

C_DEPS += \
./CH32V30x/Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
CH32V30x/Core/core_riscv.o: C:/Users/liu/Desktop/����С������/����������ͷ���ϣ�����ͷ������V1.1/4.Demo/Libraries/Device/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\05-Car_Ultrasonic\CODE" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\05-Car_Ultrasonic\USER\src" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\05-Car_Ultrasonic\USER\inc" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\����С������\����������ͷ���ϣ�����ͷ������V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

