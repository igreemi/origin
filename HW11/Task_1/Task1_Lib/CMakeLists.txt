cmake_minimum_required(VERSION 3.22.0)

project(Task1)

add_library(Task1_Static_lib STATIC 
Task1_Client/Greeter.h
Task1_Client/Greeter.cpp )

add_executable(Task1Exe Task1_Client/Task1_Client.cpp)

target_link_libraries(Task1Exe Task1_Static_lib)