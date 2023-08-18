FROM ubuntu:16.04
        LABEL maintainer="greem@yandex.ru"
        RUN apt-get update && apt-get install -y g++ nano
        WORKDIR /home/test/
        COPY Source.cpp ./
        COPY . .
        RUN g++ -std=c++17 Source.cpp RS_Lib/vehicle.cpp \
        RS_Lib/ground_vehicle.cpp RS_Lib/air_vehicle.cpp \
        RS_Lib/ground_vehicle/all_terrain_boots.cpp \
        RS_Lib/ground_vehicle/camel.cpp RS_Lib/ground_vehicle/centaur.cpp \
        RS_Lib/ground_vehicle/speed_camel.cpp \
        RS_Lib/air_vehicle/broom.cpp RS_Lib/air_vehicle/eagle.cpp \
        RS_Lib/air_vehicle/magic_carpet.cpp -o Racing_Simulator
        # RUN g++ -o Racing_Simulator Source.o vehicle.o ground_vehicle.o air_vehicle.o all_terrain_boots.o camel.o centaur.o speed_camel.o broom.o eagle.o magic_carpet.o
        CMD ["./Racing_Simulator"]
