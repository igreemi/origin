cmake_minimum_required(VERSION 3.22.0)
project(Task5)
set( SOURCE_LIB Task5_Lib/Figure.h Task5_Lib/Figure.cpp
Task5_Lib/Equilateral_Triangle.h Task5_Lib/Equilateral_Triangle.cpp
Task5_Lib/Isosceles_Triangle.h Task5_Lib/Isosceles_Triangle.cpp
Task5_Lib/Parallelogram.h Task5_Lib/Parallelogram.cpp
Task5_Lib/Quadrilateral.h Task5_Lib/Quadrilateral.cpp
Task5_Lib/Rectangl.h Task5_Lib/Rectangl.cpp
Task5_Lib/Rhombus.h Task5_Lib/Rhombus.cpp
Task5_Lib/Square.h Task5_Lib/Square.cpp
Task5_Lib/Triangle.h Task5_Lib/Triangle.cpp
Task5_Lib/Right_Triangle.h Task5_Lib/Right_Triangle.cpp)
set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
add_library( Task5_lib SHARED ${SOURCE_LIB} )
add_executable(Task5 Task5_Client.cpp)
target_include_directories(Task5_lib PUBLIC Task5_Lib/)
target_link_libraries(Task5 PUBLIC Task5_lib)