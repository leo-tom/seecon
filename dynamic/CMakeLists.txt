cmake_minimum_required(VERSION 2.8)
include_directories("$PROJECT_SOURCE_DIR")
project(seecon C)
add_library(seecon SHARED ../ArrayList.c ../Map.c)
install(TARGETS seecon
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)
set(CMAKE_C_FLAGS "-g -ggdb")
