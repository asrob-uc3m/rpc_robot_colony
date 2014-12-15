# set defaults
set(ARDUINO_DEFAULT_BOARD uno) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0) # Default Port, when not specified

#link_directories(${ARDUINO_SDK_PATH}/libraries)
set(ARD_LIB_DIR ${ARDUINO_SDK_PATH}/libraries)

#====================================================================#
# static library
#====================================================================#
generate_arduino_library(
    motor_interface_lib
    SRCS servomotor_driver.cpp motor_driver.cpp ${ARD_LIB_DIR}/Servo/Servo.cpp
    HDRS servomotor_driver.h motor_driver.h motor_interface.h ${ARD_LIB_DIR}/Servo/Servo.h
    BOARD uno
)

#====================================================================#
# firwmare
#====================================================================#
generate_arduino_firmware(
    robot_library
    SRCS robot_library.cpp
    LIBS motor_interface_lib m
    BOARD uno
)

add_subdirectory(test)
