cmake_minimum_required(VERSION 3.22)
project(filesystem)

add_subdirectory(cd)
add_subdirectory(cdir)
add_subdirectory(copy)
add_subdirectory(list)
add_subdirectory(mkdir)
add_subdirectory(move)
add_subdirectory(remove)

include_directories(../shuffle/include)