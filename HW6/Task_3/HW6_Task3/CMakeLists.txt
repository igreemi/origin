cmake_minimum_required(VERSION 3.22.0)
project(figure_project)
set(SOURCE HW6_Task3/HW6_Task3.cpp
HW6_Task3/Figure.cpp
HW6_Task3/Triangle.cpp
HW6_Task3/Quadrilateral.cpp
HW6_Task3/Right_Triangle.cpp
HW6_Task3/Isosceles_Triangle.cpp
HW6_Task3/Equilateral_Triangle.cpp
HW6_Task3/Rectangl.cpp
HW6_Task3/Square.cpp
HW6_Task3/Parallelogram.cpp
HW6_Task3/Rhombus.cpp)
add_executable(figure ${SOURCE})