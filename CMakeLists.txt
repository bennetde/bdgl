cmake_minimum_required(VERSION 3.14)

project(BDGL)


add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glm)
add_subdirectory(src)


