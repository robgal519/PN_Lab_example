cmake_minimum_required(VERSION 3.10)
project(PN_lab_example C)
set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Wextra")

add_executable(PN_lab_example main.c argParseSetup/argParseSetup.c argParseSetup/argParseSetup.h logSetup/logSetup.h)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)

include_directories(${GTK2_INCLUDE_DIRS})
link_directories(${GTK2_LIBRARY_DIRS})

target_link_libraries(PN_lab_example ${GTK2_LIBRARIES} ${CMAKE_DL_LIBS})