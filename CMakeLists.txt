cmake_minimum_required(VERSION 3.10)
project(cube)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party/glfw)

include_directories(
    third_party/glfw/include
    third_party/glad/include
    third_party/glm
    src
    src/shaders
    src/mesh
)

add_executable(cube
    src/main.cpp
    third_party/glad/src/gl.c
)

target_link_libraries(cube
    glfw
)

