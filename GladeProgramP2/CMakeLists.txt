cmake_minimum_required(VERSION 3.17)
project(GladeProgramP2)

set(CMAKE_CXX_STANDARD 14)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtkmm-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
set(CMAKE_ENABLE_EXPORTS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(${GTK3_CFLAGS_OTHER})
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")

add_executable(GladeProgramP2 main.cpp gladeprogram.h)
target_link_libraries(GladeProgramP2 ${GTK3_LIBRARIES})