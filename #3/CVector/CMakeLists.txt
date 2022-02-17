cmake_minimum_required(VERSION 2.8)

project(CVector)

#aux_source_directory(. SRC_LIST)

set(CVector_SRC main.cpp test.cpp CVector_operators.cpp CVector_methods.cpp)
set(CVector_HDR CVector.h Header.h)

add_executable(${PROJECT_NAME} ${CVector_SRC} ${CVector_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")