FROM ubuntu:16.04
        LABEL maintainer="greem@yandex.ru"
        RUN apt-get update && apt-get install -y g++ nano net-tools inetutils-ping
        WORKDIR /home/test/
        COPY docker_hello.cpp .
        RUN g++ docker_hello.cpp -o docker_hello
        CMD ["./docker_hello"]
