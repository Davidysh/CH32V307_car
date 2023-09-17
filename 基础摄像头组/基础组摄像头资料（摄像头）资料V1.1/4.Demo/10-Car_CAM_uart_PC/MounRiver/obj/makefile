################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include user_c/subdir.mk
-include hefei_peripheral/subdir.mk
-include hefei_libraries/board/subdir.mk
-include hefei_libraries/subdir.mk
-include CODE/subdir.mk
-include CH32V30x/Core/subdir.mk
-include CH32V30x/CH32V30x_p/Startup/subdir.mk
-include CH32V30x/CH32V30x_p/CH32V30x_Lib/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
10-Car_CAM_uart_PC.hex \

SECONDARY_LIST += \
10-Car_CAM_uart_PC.lst \

SECONDARY_SIZE += \
10-Car_CAM_uart_PC.siz \


# All Target
all: 10-Car_CAM_uart_PC.elf secondary-outputs

# Tool invocations
10-Car_CAM_uart_PC.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -T "C:\Users\liu\Desktop\智能小车比赛\基础组摄像头资料（摄像头）资料V1.1\4.Demo\10-Car_CAM_uart_PC\MounRiver\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"10-Car_CAM_uart_PC.map" --specs=nano.specs --specs=nosys.specs -o "10-Car_CAM_uart_PC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
10-Car_CAM_uart_PC.hex: 10-Car_CAM_uart_PC.elf
	@	riscv-none-embed-objcopy -O ihex "10-Car_CAM_uart_PC.elf"  "10-Car_CAM_uart_PC.hex"
	@	@
10-Car_CAM_uart_PC.lst: 10-Car_CAM_uart_PC.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble "10-Car_CAM_uart_PC.elf" > "10-Car_CAM_uart_PC.lst"
	@	@
10-Car_CAM_uart_PC.siz: 10-Car_CAM_uart_PC.elf
	@	riscv-none-embed-size --format=berkeley "10-Car_CAM_uart_PC.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) 10-Car_CAM_uart_PC.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
