cmake_minimum_required(VERSION 3.10)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Prevent error from CLion
SET(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Set compiler for ARM
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_OBJCOPY "arm-none-eabi-objcopy")

project(template C ASM)

include_directories(
        lib/SPL/inc
        lib/CMSIS
        include
)

SET(USER_SOURCES
        source/main.c
        source/stm32f30x_it.c
        source/system_stm32f30x.c
        source/startup_stm32f30x.s
        lib/SPL/src/stm32f30x_rcc.c
        lib/SPL/src/stm32f30x_gpio.c
        )

SET(CMAKE_EXE_LINKER_FLAGS "-Wl,--no-wchar-size-warning,--gc-sections,-M=binary.map,-T./../misc/STM32F303CB_FLASH.ld")

set(CMAKE_C_FLAGS "-g -O0 -DSTM32F303xC -DUSE_STDPERIPH_DRIVER -mthumb -mthumb-interwork -mcpu=cortex-m4 --specs=nosys.specs -ffreestanding -flto")

add_executable(template ${USER_SOURCES})
