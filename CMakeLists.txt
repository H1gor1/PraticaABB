cmake_minimum_required(VERSION 3.22)
project(PraticaABB C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(PraticaABB
        main.c arvBB.h arvBB.c fila.h fila.c)
