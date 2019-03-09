################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/domain/model/milk.cpp \
../src/domain/model/smart_product.cpp 

OBJS += \
./src/domain/model/milk.o \
./src/domain/model/smart_product.o 

CPP_DEPS += \
./src/domain/model/milk.d \
./src/domain/model/smart_product.d 


# Each subdirectory must supply rules for building sources it contributes
src/domain/model/%.o: ../src/domain/model/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


