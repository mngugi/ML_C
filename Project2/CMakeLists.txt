cmake_minimum_required(VERSION 3.10)

# Project name
project(ML_C_Project C)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the source files
add_executable(ml_app main.c ml_utils.c)
