set (SOURCES "BDGL.cpp" ) #"glad.c"
set(LIBRARY_NAME BDGL)
set(EXECUTABLE_NAME RUNBDGL)

find_package( OpenGL REQUIRED )

include_directories(${OPENGL_INCLUDE_DIRS})

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_library(${LIBRARY_NAME} ${SOURCES})

#target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${LIBRARY_NAME} ${OPENGL_LIBRARIES} glfw)
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_20)

add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME})

