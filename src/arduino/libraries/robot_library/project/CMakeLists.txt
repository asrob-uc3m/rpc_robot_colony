# set defaults
set(ARDUINO_DEFAULT_BOARD uno) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0) # Default Port, when not specified

#====================================================================#
# Advanced static library exmaple
#====================================================================#
generate_arduino_library(
    motor_interface_lib
    SRCS servomotor_driver.cpp motor_driver.cpp
    HDRS servomotor_driver.h motor_driver.h motor_interface.h
    BOARD uno
)

#====================================================================#
# Advanced firwmare example
#====================================================================#
generate_arduino_firmware(
    robot_library
    SRCS robot_library.cpp
    LIBS motor_interface_lib
    BOARD uno
)
