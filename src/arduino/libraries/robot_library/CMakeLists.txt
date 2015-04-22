#====================================================================#
#  Commands                                                          #
#====================================================================#
# Compile
#
#   Go to the build folder and type in a console:
#       To compile all the projects:
#           $ make
#       To compile only one project:
#           $ make executable_name
#
# Upload (also compiles the project)
#
#   Go to the build folder and type in a console:
#       $ make executable_name-upload
#
#
# Show (serial monitor)
#
#   Go to the build folder, make sure the program has been uploaded, and type in a console:
#       $ make executable_name-serial
#

set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake) # Arduino Toolchain

cmake_minimum_required(VERSION 2.8)

#====================================================================#
#  Setup Project                                                     #
#====================================================================#
project(ArduinoRobot C CXX)

#print_board_list()
#print_programmer_list()

add_subdirectory(project)
