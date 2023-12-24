cmake_minimum_required(VERSION 3.22)
project(time)

add_library(${PROJECT_NAME} SHARED lib.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ../../shuffle/include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SHFL_LIBS})