cmake_minimum_required(VERSION 3.16)
project(Game_of_Life)

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

add_executable(gol src/main.cpp src/functions.cpp)
target_include_directories(gol PRIVATE include)
target_compile_features(gol PRIVATE cxx_std_17)
target_link_libraries(gol PRIVATE SFML::Graphics)