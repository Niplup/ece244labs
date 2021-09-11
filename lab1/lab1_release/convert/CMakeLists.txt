cmake_minimum_required(VERSION 3.20)
project(convert)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(convert convert.cpp)
