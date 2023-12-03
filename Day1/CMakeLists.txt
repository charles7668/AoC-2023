cmake_minimum_required(VERSION 3.26)

project(day1)

file(GLOB file_list *.cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(day1 ${file_list})