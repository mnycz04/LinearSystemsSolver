cmake_minimum_required(VERSION 3.21)
project(LinearSystemsSolver C)

set(CMAKE_C_STANDARD 17)

add_executable(LinearSystemsSolver main.c matrixfunctions.c matrixfunctions.h)
