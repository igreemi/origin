FROM ubuntu:16.04
        LABEL maintainer="greem@yandex.ru"
        RUN apt-get update && apt-get install -y clang nano
        WORKDIR /home/test/
        COPY Source.cpp ./
        COPY . .
        RUN clang++ -std=c++1z Source.cpp RS_Lib/vehicle.cpp \
        RS_Lib/ground_vehicle.cpp RS_Lib/air_vehicle.cpp \
        RS_Lib/ground_vehicle/all_terrain_boots.cpp \
        RS_Lib/ground_vehicle/camel.cpp RS_Lib/ground_vehicle/centaur.cpp \
        RS_Lib/ground_vehicle/speed_camel.cpp \
        RS_Lib/air_vehicle/broom.cpp RS_Lib/air_vehicle/eagle.cpp \
        RS_Lib/air_vehicle/magic_carpet.cpp -o Racing_Simulator
        CMD ["./Racing_Simulator"]
