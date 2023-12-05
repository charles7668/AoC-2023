cmake_minimum_required(VERSION 3.26)

project(Day4)

set(CMAKE_CXX_STANDARD 17)

file(GLOB file_list "*.cpp")

add_executable(Day4 ${file_list})