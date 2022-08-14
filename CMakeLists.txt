cmake_minimum_required(VERSION 3.14)

project(Hello)


add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glfw)
include_directories(lib/glfw/include)
add_subdirectory(src)


