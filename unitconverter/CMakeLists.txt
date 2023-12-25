cmake_minimum_required(VERSION 3.22)
project(unitconverter)

add_subdirectory(convertlength)
add_subdirectory(convertweight)
add_subdirectory(convertvolume)
add_subdirectory(converttemperature)
add_subdirectory(convertspeed)
add_subdirectory(converttime)
add_subdirectory(convertangle)
add_subdirectory(convertdatavolume)
add_subdirectory(convertenergy)

include_directories(../shuffle/include)