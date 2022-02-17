cmake_minimum_required(VERSION 2.8)

project(CStack)

#aux_source_directory(. SRC_LIST)

set(CStack_SRC main.cpp CStack_methods.cpp test.cpp)
set(CStack_HDR CStack.h Header.h)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${CStack_SRC} ${CStack_HDR})
add_executable(${PROJECT_NAME} ${CStack_SRC} ${CStack_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")