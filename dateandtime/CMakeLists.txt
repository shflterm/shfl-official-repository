cmake_minimum_required(VERSION 3.22)
project(filesystem)

add_subdirectory(date)
add_subdirectory(time)
add_subdirectory(datediff)
add_subdirectory(timer)

include_directories(../shuffle/include)