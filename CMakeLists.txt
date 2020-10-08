cmake_minimum_required(VERSION 2.8.9)
project(honor)

include_directories(inc/)


add_executable(honor inc/Jumper.cpp inc/Manager.cpp main.cpp)

find_package(SFML 2.5.1 COMPONENTS graphics system window REQUIRED)
target_link_libraries(honor sfml-graphics sfml-window sfml-system)