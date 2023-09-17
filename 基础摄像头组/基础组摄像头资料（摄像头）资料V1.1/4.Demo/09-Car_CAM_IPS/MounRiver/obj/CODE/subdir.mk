################################################################################
# MRS Version: {"version":"1.8.5","date":"2023/05/22"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/board_led.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/camera.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_adc.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_init.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_keys.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_ligth.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_motion.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_reed.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_uart.c \
C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_value_process.c 

OBJS += \
./CODE/board_led.o \
./CODE/camera.o \
./CODE/car_adc.o \
./CODE/car_init.o \
./CODE/car_keys.o \
./CODE/car_ligth.o \
./CODE/car_motion.o \
./CODE/car_reed.o \
./CODE/car_uart.o \
./CODE/car_value_process.o 

C_DEPS += \
./CODE/board_led.d \
./CODE/camera.d \
./CODE/car_adc.d \
./CODE/car_init.d \
./CODE/car_keys.d \
./CODE/car_ligth.d \
./CODE/car_motion.d \
./CODE/car_reed.d \
./CODE/car_uart.d \
./CODE/car_value_process.d 


# Each subdirectory must supply rules for building sources it contributes
CODE/board_led.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/board_led.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/camera.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/camera.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_adc.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_init.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_init.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_keys.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_keys.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_ligth.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_ligth.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_motion.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_motion.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_reed.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_reed.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_uart.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_value_process.o: C:/Users/liu/Desktop/智能小车比赛/基础组摄像头资料（摄像头）资料V1.1/4.Demo/09-Car_CAM_IPS/CODE/car_value_process.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\CODE" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_libraries\board" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\src" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\09-Car_CAM_IPS\USER\inc" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\hefei_peripheral" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\Core" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

