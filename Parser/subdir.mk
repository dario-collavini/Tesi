################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Parser/ParserEmulator.cpp 

OBJS += \
./Parser/ParserEmulator.o 

CPP_DEPS += \
./Parser/ParserEmulator.d 


# Each subdirectory must supply rules for building sources it contributes
Parser/%.o: ../Parser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/home/dario/Scrivania/trunk/CppRDFox/include -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


