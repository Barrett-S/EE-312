cmake_minimum_required(VERSION 3.12)
project(UtPod)

set(CMAKE_CXX_STANDARD 14)

add_executable(UtPod UtPod.cpp UtPod.h UtPodDriver.cpp Song.cpp Song.h)