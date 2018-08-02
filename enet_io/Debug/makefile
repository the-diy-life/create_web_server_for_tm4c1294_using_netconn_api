################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./cgifuncs.obj" \
"./enet_io.obj" \
"./io.obj" \
"./io_fs.obj" \
"./startup_ccs.obj" \
"./drivers/pinout.obj" \
"./my_tasks/led.obj" \
"./source/croutine.obj" \
"./source/event_groups.obj" \
"./source/list.obj" \
"./source/queue.obj" \
"./source/stream_buffer.obj" \
"./source/tasks.obj" \
"./source/timers.obj" \
"./source/portable/CCS/ARM_CM4F/port.obj" \
"./source/portable/CCS/ARM_CM4F/portasm.obj" \
"./source/portable/MemMang/heap_1.obj" \
"./third_party/lwip-1.4.1/apps/httpserver_raw/httpd.obj" \
"./third_party/lwip-1.4.1/apps/httpserver_raw/httpserver-netconn.obj" \
"./utils/locator.obj" \
"./utils/lwiplib.obj" \
"./utils/uartstdio.obj" \
"./utils/ustdlib.obj" \
"../enet_io_ccs.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/ti/TivaWare_C_Series-2.1.4.178/driverlib/ccs/Debug/driverlib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include drivers/subdir_vars.mk
-include my_tasks/subdir_vars.mk
-include source/subdir_vars.mk
-include source/portable/CCS/ARM_CM4F/subdir_vars.mk
-include source/portable/MemMang/subdir_vars.mk
-include third_party/lwip-1.4.1/apps/httpserver_raw/subdir_vars.mk
-include utils/subdir_vars.mk
-include subdir_rules.mk
-include drivers/subdir_rules.mk
-include my_tasks/subdir_rules.mk
-include source/subdir_rules.mk
-include source/portable/CCS/ARM_CM4F/subdir_rules.mk
-include source/portable/MemMang/subdir_rules.mk
-include third_party/lwip-1.4.1/apps/httpserver_raw/subdir_rules.mk
-include utils/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
enet_io.out \

EXE_OUTPUTS__QUOTED += \
"enet_io.out" \

BIN_OUTPUTS += \
enet_io.bin \

BIN_OUTPUTS__QUOTED += \
"enet_io.bin" \


# All Target
all: enet_io.out

# Tool invocations
enet_io.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O2 --advice:power=all -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --define=TARGET_IS_TM4C129_RA0 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --ual -z -m"enet_io_ccs.map" --stack_size=1024 --heap_size=0 -i"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/lib" -i"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="enet_io_linkInfo.xml" --rom_model -o "enet_io.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

enet_io.bin: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armhex"  -o "enet_io.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "cgifuncs.obj" "enet_io.obj" "io.obj" "io_fs.obj" "startup_ccs.obj" "drivers\pinout.obj" "my_tasks\led.obj" "source\croutine.obj" "source\event_groups.obj" "source\list.obj" "source\queue.obj" "source\stream_buffer.obj" "source\tasks.obj" "source\timers.obj" "source\portable\CCS\ARM_CM4F\port.obj" "source\portable\CCS\ARM_CM4F\portasm.obj" "source\portable\MemMang\heap_1.obj" "third_party\lwip-1.4.1\apps\httpserver_raw\httpd.obj" "third_party\lwip-1.4.1\apps\httpserver_raw\httpserver-netconn.obj" "utils\locator.obj" "utils\lwiplib.obj" "utils\uartstdio.obj" "utils\ustdlib.obj" 
	-$(RM) "cgifuncs.d" "enet_io.d" "io.d" "io_fs.d" "startup_ccs.d" "drivers\pinout.d" "my_tasks\led.d" "source\croutine.d" "source\event_groups.d" "source\list.d" "source\queue.d" "source\stream_buffer.d" "source\tasks.d" "source\timers.d" "source\portable\CCS\ARM_CM4F\port.d" "source\portable\MemMang\heap_1.d" "third_party\lwip-1.4.1\apps\httpserver_raw\httpd.d" "third_party\lwip-1.4.1\apps\httpserver_raw\httpserver-netconn.d" "utils\locator.d" "utils\lwiplib.d" "utils\uartstdio.d" "utils\ustdlib.d" 
	-$(RM) "source\portable\CCS\ARM_CM4F\portasm.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-"C:/ti/ccsv8/utils/tiobj2bin/tiobj2bin" "enet_io.out" "enet_io.bin" "C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armofd" "C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armhex" "C:/ti/ccsv8/utils/tiobj2bin/mkhex4bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

