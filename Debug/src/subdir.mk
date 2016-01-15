################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bP_02_main.cpp 

OBJS += \
./src/bP_02_main.o 

CPP_DEPS += \
./src/bP_02_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -UNDEBUG -I~/ROOT/ROOT_6_06_00/include -O0 -g3 -Wall -c -fmessage-length=0 -pthread -Wno-deprecated-declarations -m64 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


