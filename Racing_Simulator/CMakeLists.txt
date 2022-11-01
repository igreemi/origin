cmake_minimum_required(VERSION 3.22.0)

project(Racing_Simulator)

set(SOURCE_LIB "RS_Lib/vehicle.cpp" "RS_Lib/vehicle.h" 
"RS_Lib/ground_vehicle.cpp" "RS_Lib/ground_vehicle.h" 
"RS_Lib/air_vehicle.cpp" "RS_Lib/air_vehicle.h" 
"RS_Lib/ground_vehicle/camel.cpp" "RS_Lib/ground_vehicle/camel.h" 
"RS_Lib/ground_vehicle/speed_camel.cpp" "RS_Lib/ground_vehicle/speed_camel.h" 
"RS_Lib/ground_vehicle/centaur.cpp" "RS_Lib/ground_vehicle/centaur.h" 
"RS_Lib/ground_vehicle/all_terrain_boots.h" "RS_Lib/ground_vehicle/all_terrain_boots.cpp" 
"RS_Lib/air_vehicle/magic_carpet.cpp" "RS_Lib/air_vehicle/magic_carpet.h" 
"RS_Lib/air_vehicle/eagle.cpp" "RS_Lib/air_vehicle/eagle.h" 
"RS_Lib/air_vehicle/broom.cpp" "RS_Lib/air_vehicle/broom.h")

 set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

 add_library( RS_Lib SHARED ${SOURCE_LIB} )

 add_executable(RS Source.cpp)

 target_include_directories(RS_Lib PUBLIC "RS_Lib/")

target_link_libraries(RS PUBLIC RS_Lib)