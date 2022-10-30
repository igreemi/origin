cmake_minimum_required(VERSION 3.22.0)

project(TASK2LIB_EXPORTS)

add_library(TASK2LIB_EXPORTS SHARED 
Task2_Client/Leaver.h
Task2_Client/Leaver.cpp )

add_executable(Task2Exe Task2_Client/Task2_Client.cpp)

target_link_libraries(Task2Exe TASK2LIB_EXPORTS)