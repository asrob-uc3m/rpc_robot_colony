#====================================================================#
# firwmare
#====================================================================#
generate_arduino_firmware(
    test_motors
    SRCS test_motors.cpp
    LIBS motor_interface_lib
    BOARD uno
)

#====================================================================#
# firwmare
#====================================================================#
generate_arduino_firmware(
    test_servomotors
    SRCS test_servomotors.cpp
    LIBS motor_interface_lib
    BOARD uno
    SERIAL screen @SERIAL_PORT@ -b 9600
)
