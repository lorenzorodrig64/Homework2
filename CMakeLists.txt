cmake_minimum_required(VERSION 3.14.0)
project(Homework2 VERSION 0.1.0 LANGUAGES C CXX)

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
# Our Project
set(SOURCE_FILES
    main.cpp AerospaceControlSystem.cpp Sensor.cpp SensorFactory.cpp)

add_executable(Notes main.cpp AerospaceControlSystem.cpp AerospaceControlSystem.h Sensor.cpp Sensor.h SensorFactory.cpp SensorFactory.h)
target_link_libraries(Notes OpenGL::GL glfw libglew_static)

set(CPACK_PROJECT_NAME Notes)
set(CPACK_PROJECT_VERSION Notes)
include(CPack)
