cmake_minimum_required(VERSION 3.28) # Specify CMake version.
project(Homework2) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR}/include) # header file folder.
add_executable(Notes main.cpp Sensor.h Sensor.cpp SensorFactory.h SensorFactory.cpp AerospaceControlSystem.h AerospaceControlSystem.cpp)