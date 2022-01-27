cmake_minimum_required(VERSION 3.21)
set(TARGET "myNN")
project("${TARGET}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add library NN
add_subdirectory(NN)
add_subdirectory(matplotplusplus)

add_executable("${TARGET}" MNIST_test.cpp)

target_link_libraries("${TARGET}" PUBLIC NN matplot)

target_include_directories("${TARGET}" PUBLIC
        "${PROJECT_SOURCE_DIR}/NN"
        )
