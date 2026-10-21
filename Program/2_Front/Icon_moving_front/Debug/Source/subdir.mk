################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../Source/cstart.asm 

C_SRCS += \
../Source/adc.c \
../Source/communication.c \
../Source/display.c \
../Source/input.c \
../Source/keycontrol.c \
../Source/main.c \
../Source/operation.c \
../Source/output.c \
../Source/safety.c \
../Source/timer.c 

OBJS += \
./Source/adc.o \
./Source/communication.o \
./Source/cstart.o \
./Source/display.o \
./Source/input.o \
./Source/keycontrol.o \
./Source/main.o \
./Source/operation.o \
./Source/output.o \
./Source/safety.o \
./Source/timer.o 

C_DEPS += \
./Source/adc.d \
./Source/communication.d \
./Source/display.d \
./Source/input.d \
./Source/keycontrol.d \
./Source/main.d \
./Source/operation.d \
./Source/output.d \
./Source/safety.d \
./Source/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/%.o: ../Source/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


