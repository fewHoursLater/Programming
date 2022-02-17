cmake_minimum_required(VERSION 2.8)

project(CintN)

#aux_source_directory(. SRC_LIST)

set(CintN_SRC main.cpp functions.cpp CintN_operators.cpp CintN_methods.cpp)
set(CintN_HDR CintN.hpp Header.hpp)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${CintN_SRC} ${CintN_HDR})
add_executable(${PROJECT_NAME} ${CintN_SRC} ${CintN_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")