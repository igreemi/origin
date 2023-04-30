cmake_minimum_required(VERSION 3.5)

project(Q_Widget VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

    qt_add_executable(Q_Widget
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

target_link_libraries(Q_Widget PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS Q_Widget
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

    qt_finalize_executable(Q_Widget)
