cmake_minimum_required(VERSION 3.26)

project(day2)

set(CMAKE_CXX_STANDARD 17)

file(GLOB file_list *.cpp)

add_executable(day2 ${file_list})