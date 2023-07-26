cmake_minimum_required(VERSION 2.8)

get_filename_component(ROOT_DIR ${CMAKE_CURRENT_LIST_DIR} PATH)

project(cpp20 CXX)

set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(src)
