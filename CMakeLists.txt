cmake_minimum_required(VERSION 2.8)
include_directories("$PROJECT_SOURCE_DIR")
project(seecon C)
add_subdirectory(static)
add_subdirectory(dynamic)
add_subdirectory(test)
set(CMAKE_C_FLAGS "-g -ggdb")
install(FILES seecon.h DESTINATION include)
