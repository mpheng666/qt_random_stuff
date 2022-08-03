cmake_minimum_required(VERSION 3.14)

project(hello_moc_signals_slots LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(hello_moc_signals_slots
  main.cpp
  hellomoc.h
  hellomoc.cpp

)
target_link_libraries(hello_moc_signals_slots Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS hello_moc_signals_slots
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
