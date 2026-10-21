################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../r_cg_adc.c \
../r_cg_adc_user.c \
../r_cg_cgc.c \
../r_cg_cgc_user.c \
../r_cg_port.c \
../r_cg_port_user.c \
../r_cg_serial.c \
../r_cg_serial_user.c \
../r_cg_timer.c \
../r_cg_timer_user.c \
../r_cg_wdt.c \
../r_cg_wdt_user.c \
../r_main.c \
../r_systeminit.c 

OBJS += \
./r_cg_adc.o \
./r_cg_adc_user.o \
./r_cg_cgc.o \
./r_cg_cgc_user.o \
./r_cg_port.o \
./r_cg_port_user.o \
./r_cg_serial.o \
./r_cg_serial_user.o \
./r_cg_timer.o \
./r_cg_timer_user.o \
./r_cg_wdt.o \
./r_cg_wdt_user.o \
./r_main.o \
./r_systeminit.o 

C_DEPS += \
./r_cg_adc.d \
./r_cg_adc_user.d \
./r_cg_cgc.d \
./r_cg_cgc_user.d \
./r_cg_port.d \
./r_cg_port_user.d \
./r_cg_serial.d \
./r_cg_serial_user.d \
./r_cg_timer.d \
./r_cg_timer_user.d \
./r_cg_wdt.d \
./r_cg_wdt_user.d \
./r_main.d \
./r_systeminit.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


