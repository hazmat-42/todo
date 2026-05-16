cmake_minimum_required(VERSION 4.2)
project(todo C)

set(CMAKE_C_STANDARD 17)

add_executable(todo main.c
        todo.h)