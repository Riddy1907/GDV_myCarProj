cmake_minimum_required(VERSION 3.17)
project(car_scene_code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -framework GLUT -framework OpenGL") # compiler version and compiler flags.

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp car.cpp car.h terrain.cpp terrain.h) # which files should be compiled

include_directories(.)


add_executable(car_scene_code
        car.cpp
        car.h
        main.cpp
        terrain.cpp
        terrain.h)










