cmake_minimum_required(VERSION 3.21)
project(NN)

set(CMAKE_CXX_STANDARD 20)
add_library(NN STATIC NN.h NN.cpp)