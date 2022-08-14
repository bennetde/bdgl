cmake_minimum_required(VERSION 3.14)

project(BDGL)


add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glm)


include_directories(${CMAKE_SOURCE_DIR}/lib/glad/include)
SET(GLAD_SOURCE ${CMAKE_SOURCE_DIR}/lib/glad/src/glad.c)
add_subdirectory(src)


