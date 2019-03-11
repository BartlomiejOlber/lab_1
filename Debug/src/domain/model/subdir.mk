################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/domain/model/available_item.cpp \
../src/domain/model/refridgerator.cpp \
../src/domain/model/smart_product.cpp \
../src/domain/model/smart_product_container.cpp \
../src/domain/model/stock.cpp 

OBJS += \
./src/domain/model/available_item.o \
./src/domain/model/refridgerator.o \
./src/domain/model/smart_product.o \
./src/domain/model/smart_product_container.o \
./src/domain/model/stock.o 

CPP_DEPS += \
./src/domain/model/available_item.d \
./src/domain/model/refridgerator.d \
./src/domain/model/smart_product.d \
./src/domain/model/smart_product_container.d \
./src/domain/model/stock.d 


# Each subdirectory must supply rules for building sources it contributes
src/domain/model/%.o: ../src/domain/model/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


