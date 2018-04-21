cmake_minimum_required(VERSION 3.10)
project(PN_lab_example C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Wextra")

add_executable(PN_lab_example main.c argParseSetup/argParseSetup.c argParseSetup/argParseSetup.h logSetup/logSetup.h)