cmake_minimum_required(VERSION 3.25)
project(bandera C)

set(CMAKE_C_STANDARD 99)

add_executable(bandera main.c bandera.c bandera.h)

find_package(GLUT)
find_package(OpenGL)
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(bandera ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} m)