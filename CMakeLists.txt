cmake_minimum_required(VERSION 3.28) # Specify CMake version.
project(Homework2) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.

include(CTest)
enable_testing()

# Dependencies
find_package(OpenGL REQUIRED)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

FetchContent_Declare(
        glew
        GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
)
FetchContent_MakeAvailable(glew)

include_directories(${CMAKE_SOURCE_DIR}/include) # header file folder.
add_executable(Notes main.cpp Sensor.h Sensor.cpp SensorFactory.h SensorFactory.cpp AerospaceControlSystem.h AerospaceControlSystem.cpp)
target_include_directories(Notes PUBLIC ${CMAKE_SOURCE_DIR})