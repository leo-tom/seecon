cmake_minimum_required(VERSION 2.8)
include_directories("$PROJECT_SOURCE_DIR")
project(seecon C)
add_library(seecon SHARED ../ArrayList.c)
install(TARGETS seecon
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)


