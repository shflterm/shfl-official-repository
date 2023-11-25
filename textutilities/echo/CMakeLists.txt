cmake_minimum_required(VERSION 3.22)
project(echo)

add_library(${PROJECT_NAME} SHARED lib.cpp)