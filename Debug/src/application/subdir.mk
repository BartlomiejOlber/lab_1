################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/application/candys_service.cpp \
../src/application/container_service.cpp \
../src/application/container_service_factory.cpp \
../src/application/drinks_service.cpp \
../src/application/preference_service.cpp \
../src/application/refridgerator_service.cpp \
../src/application/shopping_list_service.cpp \
../src/application/smart_product_container_factory.cpp \
../src/application/stock_service.cpp 

OBJS += \
./src/application/candys_service.o \
./src/application/container_service.o \
./src/application/container_service_factory.o \
./src/application/drinks_service.o \
./src/application/preference_service.o \
./src/application/refridgerator_service.o \
./src/application/shopping_list_service.o \
./src/application/smart_product_container_factory.o \
./src/application/stock_service.o 

CPP_DEPS += \
./src/application/candys_service.d \
./src/application/container_service.d \
./src/application/container_service_factory.d \
./src/application/drinks_service.d \
./src/application/preference_service.d \
./src/application/refridgerator_service.d \
./src/application/shopping_list_service.d \
./src/application/smart_product_container_factory.d \
./src/application/stock_service.d 


# Each subdirectory must supply rules for building sources it contributes
src/application/%.o: ../src/application/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


