cmake_minimum_required(VERSION 3.22)
project(mkdir)

add_library(${PROJECT_NAME} SHARED lib.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ../../shuffle/include)