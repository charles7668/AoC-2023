cmake_minimum_required(VERSION 3.26)

project(Day10)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE file_list "*.cpp")

add_executable(Day10 ${file_list})