################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Parser/RDFTESLABaseListener.cpp \
../Parser/RDFTESLALexer.cpp \
../Parser/RDFTESLAListener.cpp \
../Parser/RDFTESLAParser.cpp \
../Parser/RDFTRexRuleParser.cpp 

OBJS += \
./Parser/RDFTESLABaseListener.o \
./Parser/RDFTESLALexer.o \
./Parser/RDFTESLAListener.o \
./Parser/RDFTESLAParser.o \
./Parser/RDFTRexRuleParser.o 

CPP_DEPS += \
./Parser/RDFTESLABaseListener.d \
./Parser/RDFTESLALexer.d \
./Parser/RDFTESLAListener.d \
./Parser/RDFTESLAParser.d \
./Parser/RDFTRexRuleParser.d 


# Each subdirectory must supply rules for building sources it contributes
Parser/%.o: ../Parser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/dario/Scrivania/EclipseRDFTRex/RDFTRex/include/antlr4-runtime" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


