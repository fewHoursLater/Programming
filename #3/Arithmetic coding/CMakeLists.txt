cmake_minimum_required(VERSION 2.8)

project(AC)

#aux_source_directory(. SRC_LIST)

set(AC_SRC main.cpp Table.cpp Decode.cpp Encode.cpp)
set(AC_HDR Header.h)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${AC_SRC} ${AC_HDR})
add_executable(${PROJECT_NAME} ${AC_SRC} ${AC_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")