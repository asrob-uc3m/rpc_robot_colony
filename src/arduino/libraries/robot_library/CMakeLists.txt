## CMake file to compile an Arduino project.
## Adjust the settings according to your board.
## The settings here work for an Arduino UNO, Rev. 3.

# Project name
project(motor_interface)

# CMake version
cmake_minimum_required(VERSION 2.8)

# Options
# Adjust to your board
set(MCU "atmega328p" CACHE STRING "Processor Type")
set(CPU_SPEED "16000000" CACHE STRING "Speed of the CPU")
set(PORT "/dev/ttyACM0" CACHE STRING "USB Port")
set(PORT_SPEED "115200" CACHE STRING "Serial Port Speed")
set(PIN_VARIANT "standard" CACHE STRING "Pin Selection Variant. Either standard, mega, leonardo, eightanaloginputs")
set(ARDUINO_PATH "$ENV{HOME}/programs/arduino/" CACHE PATH "Path to arduino installation")
set(PROGRAMMER "stk500v1" CACHE STRING "Programmer Type")
set(COMPILE_FLAGS "" CACHE STRING "Additional Compiler Flags")

# Find Arduino SDK delivered include directories
file(GLOB_RECURSE _TF1 ${ARDUINO_PATH}/**/tgmath.h)
file(GLOB_RECURSE _TF2 ${ARDUINO_PATH}/**/math.h)
get_filename_component(AR_AVR_INC ${_TF1} PATH)
get_filename_component(AR_AVRGCC_INC ${_TF2} PATH)


# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ARDUINO_PATH}/hardware/arduino/cores/arduino
    ${ARDUINO_PATH}/hardware/arduino/variants/${PIN_VARIANT}
    ${AR_AVR_INC}
    ${AR_AVRGCC_INC}
)

# Find Arduino source files.
file(GLOB_RECURSE ARDUINO_CORE_SRC
    ${ARDUINO_PATH}/hardware/arduino/cores/arduino/*.c
    ${ARDUINO_PATH}/hardware/arduino/cores/arduino/*.cpp
)

set(CMAKE_SYSTEM_NAME Arduino)

# Find Arduino SDK delivered programs
find_program(AR_AVR_GCC NAMES avr-gcc PATHS ${ARDUINO_PATH}/hardware/tools/avr/bin NO_DEFAULT_PATH)
find_program(AR_AVR_CXX NAMES avr-g++ PATHS ${ARDUINO_PATH}/hardware/tools/avr/bin NO_DEFAULT_PATH)
find_program(AR_AVR_OBJCOPY NAMES avr-objcopy PATHS ${ARDUINO_PATH}/hardware/tools/avr/bin NO_DEFAULT_PATH)
find_program(AR_AVR_OBJDUMP NAMES avr-objdump PATHS ${ARDUINO_PATH}/hardware/tools/avr/bin NO_DEFAULT_PATH)
find_program(AR_AVR_RANLIB NAMES avr-ranlib PATHS ${ARDUINO_PATH}/hardware/tools/avr/bin NO_DEFAULT_PATH)
find_program(AR_AVR_LD NAMES avr-ld PATHS ${ARDUINO_PATH}/hardware/tools/avr/bin NO_DEFAULT_PATH)

# Compiler suite specification
set(CMAKE_C_COMPILER ${AR_AVR_GCC})
set(CMAKE_CXX_COMPILER ${AR_AVR_CXX})
set(CMAKE_OBJCOPY ${AR_AVR_OBJCOPY})
set(CMAKE_OBJDUMP ${AR_AVR_OBJDUMP})
set(CMAKE_RANLIB ${AR_AVR_RANLIB})
set(CMAKE_LINKER ${AR_AVR_LD})

# Compiler flags
add_definitions(-mmcu=${MCU} -DF_CPU=${CPU_SPEED})
add_definitions(-c -g -Os -Wall)
add_definitions(-fno-exceptions -ffunction-sections -fdata-sections)

# Linker flags
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")   # remove -rdynamic for C
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "") # remove -rdynamic for CXX
set(CMAKE_EXE_LINKER_FLAGS "-Os -Wl,--gc-sections -mmcu=${MCU}")

# set output directories
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# Set own source files
# Simply list all your C / C++ source (not header!) files here
set(SRC_FILES
    ${PROJECT_NAME}.cpp
    servomotor_driver.cpp)

add_executable(${PROJECT_NAME} ${ARDUINO_CORE_SRC} ${SRC_FILES})

find_program(AR_AVRDUDE NAMES avrdude PATHS ${ARDUINO_PATH}/hardware/tools/ NO_DEFAULT_PATH)
file(GLOB_RECURSE AR_AVRDUDE_CFG ${ARDUINO_PATH}/**/avrdude.conf)

add_custom_target(upload
    COMMAND ${CMAKE_OBJCOPY} -j .text -j .data -O ihex ${PROJECT_NAME} ${PROJECT_NAME}.hex
    COMMAND ${AR_AVRDUDE} -C${AR_AVRDUDE_CFG} -F -p${MCU} -c${PROGRAMMER} -P${PORT} -b${PORT_SPEED} -D -Uflash:w:${PROJECT_NAME}.hex:i
    DEPENDS ${PROJECT_NAME}
)
