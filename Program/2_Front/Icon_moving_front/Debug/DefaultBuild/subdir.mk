################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../DefaultBuild/adc.asm \
../DefaultBuild/communication.asm \
../DefaultBuild/display.asm \
../DefaultBuild/input.asm \
../DefaultBuild/keycontrol.asm \
../DefaultBuild/main.asm \
../DefaultBuild/operation.asm \
../DefaultBuild/output.asm \
../DefaultBuild/r_cg_adc.asm \
../DefaultBuild/r_cg_adc_user.asm \
../DefaultBuild/r_cg_cgc.asm \
../DefaultBuild/r_cg_cgc_user.asm \
../DefaultBuild/r_cg_port.asm \
../DefaultBuild/r_cg_port_user.asm \
../DefaultBuild/r_cg_serial.asm \
../DefaultBuild/r_cg_serial_user.asm \
../DefaultBuild/r_cg_timer.asm \
../DefaultBuild/r_cg_timer_user.asm \
../DefaultBuild/r_cg_wdt.asm \
../DefaultBuild/r_cg_wdt_user.asm \
../DefaultBuild/r_main.asm \
../DefaultBuild/r_systeminit.asm \
../DefaultBuild/safety.asm \
../DefaultBuild/timer.asm 

OBJS += \
./DefaultBuild/adc.o \
./DefaultBuild/communication.o \
./DefaultBuild/display.o \
./DefaultBuild/input.o \
./DefaultBuild/keycontrol.o \
./DefaultBuild/main.o \
./DefaultBuild/operation.o \
./DefaultBuild/output.o \
./DefaultBuild/r_cg_adc.o \
./DefaultBuild/r_cg_adc_user.o \
./DefaultBuild/r_cg_cgc.o \
./DefaultBuild/r_cg_cgc_user.o \
./DefaultBuild/r_cg_port.o \
./DefaultBuild/r_cg_port_user.o \
./DefaultBuild/r_cg_serial.o \
./DefaultBuild/r_cg_serial_user.o \
./DefaultBuild/r_cg_timer.o \
./DefaultBuild/r_cg_timer_user.o \
./DefaultBuild/r_cg_wdt.o \
./DefaultBuild/r_cg_wdt_user.o \
./DefaultBuild/r_main.o \
./DefaultBuild/r_systeminit.o \
./DefaultBuild/safety.o \
./DefaultBuild/timer.o 


# Each subdirectory must supply rules for building sources it contributes
DefaultBuild/%.o: ../DefaultBuild/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


