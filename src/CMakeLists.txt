set(SOURCES "BDGL.cpp" "shader.cpp" "image.cpp" "texture.cpp" "camera.cpp" "transform.cpp" "core/mesh.hpp" "core/vertex.cpp" "core/mesh_generator.hpp" ${GLAD_SOURCE}) #"glad.c"
set(LIBRARY_NAME "BDGL")
set(EXECUTABLE_NAME runBDGL)

find_package( OpenGL REQUIRED )

include_directories(${OPENGL_INCLUDE_DIRS})

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_library(${LIBRARY_NAME} ${SOURCES})

#target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${LIBRARY_NAME} ${OPENGL_LIBRARIES} glfw glm)
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_20)

add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME})
target_compile_features(${EXECUTABLE_NAME} PUBLIC cxx_std_20)

add_custom_target(copy-resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR})


add_dependencies(${EXECUTABLE_NAME} copy-resources)

