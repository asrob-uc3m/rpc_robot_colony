#====================================================================#
# firwmare
#====================================================================#
generate_arduino_firmware(
    test_motors
    SRCS test_motors.cpp
    LIBS motor_interface_lib
    BOARD uno
)
