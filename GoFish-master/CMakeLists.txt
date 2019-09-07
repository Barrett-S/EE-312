cmake_minimum_required(VERSION 3.12)
project(GoFish2)

set(CMAKE_CXX_STANDARD 14)

add_executable(GoFish2 go_fish.cpp card.h deck.h player.h player.cpp card.cpp deck.cpp)