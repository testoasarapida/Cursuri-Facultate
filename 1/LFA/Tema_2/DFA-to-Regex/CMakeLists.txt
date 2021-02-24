cmake_minimum_required(VERSION 3.7)
project(DFA_to_Regex)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(DFA_to_Regex ${SOURCE_FILES})