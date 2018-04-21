cmake_minimum_required(VERSION 3.10)
project(PN_lab_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

add_executable(PN_lab_example main.c argParseSetup/argParseSetup.c argParseSetup/argParseSetup.h)