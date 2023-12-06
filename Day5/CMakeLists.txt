cmake_minimum_required(VERSION 3.26)

project(Day5)

set(CMAKE_CXX_STANDARD 17)

file(GLOB file_lists "*.cpp")

add_executable(Day5 ${file_lists})