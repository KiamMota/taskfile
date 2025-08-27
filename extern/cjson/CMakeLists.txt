cmake_minimum_required(VERSION 3.11)
project(cjson C)

set(ALL_SRC 
  cJSON.c 
  cJSON_Utils.c
)

include_directories(${CMAKE_SOURCE_DIR})
add_library(cjson STATIC EXCLUDE_FROM_ALL ${ALL_SRC})
