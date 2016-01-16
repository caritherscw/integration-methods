################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../term/trig/CosineTerm.cpp \
../term/trig/SineTerm.cpp \
../term/trig/TangentTerm.cpp 

OBJS += \
./term/trig/CosineTerm.o \
./term/trig/SineTerm.o \
./term/trig/TangentTerm.o 

CPP_DEPS += \
./term/trig/CosineTerm.d \
./term/trig/SineTerm.d \
./term/trig/TangentTerm.d 


# Each subdirectory must supply rules for building sources it contributes
term/trig/%.o: ../term/trig/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


