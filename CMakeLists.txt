cmake_minimum_required(VERSION 3.8)
project(LSystems)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        canvas.cpp
        canvas.h
        cfg.h interpreter.h main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(LSystems ${SOURCE_FILES})
add_executable(main.cpp ${SOURCE_FILES})
target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
target_link_libraries (LSystems ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})