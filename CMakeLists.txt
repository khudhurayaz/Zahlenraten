cmake_minimum_required(VERSION 3.29)
project(Zahlenraten)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "~/CLionProjects/Zahlenraten")

add_executable(Zahlenraten App.cpp)
