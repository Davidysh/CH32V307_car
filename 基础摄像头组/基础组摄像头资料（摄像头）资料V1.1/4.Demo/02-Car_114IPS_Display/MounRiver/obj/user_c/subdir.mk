################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/02-Car_114IPS_Display/USER/src/isr.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/02-Car_114IPS_Display/USER/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/02-Car_114IPS_Display/USER/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\02-Car_114IPS_Display\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\02-Car_114IPS_Display\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\02-Car_114IPS_Display\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/02-Car_114IPS_Display/USER/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\02-Car_114IPS_Display\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\02-Car_114IPS_Display\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\02-Car_114IPS_Display\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

