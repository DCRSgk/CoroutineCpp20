cmake_minimum_required(VERSION 3.16)
project(cpp20)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS  "-fcoroutines")

add_executable("cpp20"
./src/main.cpp)

