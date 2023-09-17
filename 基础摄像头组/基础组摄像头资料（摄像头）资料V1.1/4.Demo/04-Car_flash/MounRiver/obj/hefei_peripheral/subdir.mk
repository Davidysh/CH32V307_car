################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_Double_DC_Motor.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_HC_SR04.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_IPS114.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_MT9V03X.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_TFT180.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_WS2812b.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_Wireless_uart.c 

OBJS += \
./hefei_peripheral/HF_Double_DC_Motor.o \
./hefei_peripheral/HF_HC_SR04.o \
./hefei_peripheral/HF_IPS114.o \
./hefei_peripheral/HF_MT9V03X.o \
./hefei_peripheral/HF_TFT180.o \
./hefei_peripheral/HF_WS2812b.o \
./hefei_peripheral/HF_Wireless_uart.o 

C_DEPS += \
./hefei_peripheral/HF_Double_DC_Motor.d \
./hefei_peripheral/HF_HC_SR04.d \
./hefei_peripheral/HF_IPS114.d \
./hefei_peripheral/HF_MT9V03X.d \
./hefei_peripheral/HF_TFT180.d \
./hefei_peripheral/HF_WS2812b.d \
./hefei_peripheral/HF_Wireless_uart.d 


# Each subdirectory must supply rules for building sources it contributes
hefei_peripheral/HF_Double_DC_Motor.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_Double_DC_Motor.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_HC_SR04.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_HC_SR04.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_IPS114.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_IPS114.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_MT9V03X.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_MT9V03X.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_TFT180.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_TFT180.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_WS2812b.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_WS2812b.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_Wireless_uart.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/Libraries/hefei_peripheral/HF_Wireless_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\04-Car_flash\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

