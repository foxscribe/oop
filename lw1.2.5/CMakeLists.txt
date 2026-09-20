cmake_minimum_required(VERSION 3.21)
project(lw1.2 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main main.cpp)

target_compile_features(main PRIVATE cxx_std_23)
