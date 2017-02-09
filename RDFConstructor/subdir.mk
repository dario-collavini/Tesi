################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RDFConstructor/RDFConstructor.cpp \
../RDFConstructor/TRexListener.cpp 

OBJS += \
./RDFConstructor/RDFConstructor.o \
./RDFConstructor/TRexListener.o 

CPP_DEPS += \
./RDFConstructor/RDFConstructor.d \
./RDFConstructor/TRexListener.d 


# Each subdirectory must supply rules for building sources it contributes
RDFConstructor/%.o: ../RDFConstructor/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/dario/Scrivania/EclipseRDFTRex/RDFTRex/include/antlr4-runtime" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


