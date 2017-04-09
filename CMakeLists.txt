cmake_minimum_required(VERSION 3.7)
project(HelloGlut)
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)

# FINDING GLUT
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if (NOT GLUT_FOUND)
    message("Error: GLUT not found")
endif(NOT GLUT_FOUND)

# FIND OPENGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)


add_executable(HelloGlut ${SOURCE_FILES})

target_link_libraries(HelloGlut ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
