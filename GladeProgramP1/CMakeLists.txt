cmake_minimum_required(VERSION 3.17)
project(GladeProgramP1 C)

set(CMAKE_C_STANDARD 99)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
set(CMAKE_ENABLE_EXPORTS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(${GTK3_CFLAGS_OTHER})
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")

add_executable(GladeProgramP1 main.c)
target_link_libraries(GladeProgramP1 ${GTK3_LIBRARIES})
