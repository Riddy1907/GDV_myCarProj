cmake_minimum_required(VERSION 3.17)
project(car_design)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -framework GLUT -framework OpenGL") # compiler version and compiler flags.

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp car.cpp car.h) # which files should be compiled

include_directories(.)

add_executable(car_design
        car.cpp
        car.h
        main.cpp)

link_directories(/home/public/projects/lib)

link_directories(/usr/local/include/SOIL2-master)

add_executable(untitled main.cpp)
target_link_libraries (untitled LINK_PUBLIC Engine)







#add_executable(opengl_projects ${SOURCE_FILES}) # which files should produce executables