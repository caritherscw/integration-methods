################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../term/PolyTerm.cpp \
../term/Term.cpp 

OBJS += \
./term/PolyTerm.o \
./term/Term.o 

CPP_DEPS += \
./term/PolyTerm.d \
./term/Term.d 


# Each subdirectory must supply rules for building sources it contributes
term/%.o: ../term/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


