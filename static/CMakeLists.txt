cmake_minimum_required(VERSION 2.8)
include_directories("$PROJECT_SOURCE_DIR")
project(seecon_static C)
add_library(seecon_static STATIC ../ArrayList.c)

