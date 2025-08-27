cmake_minimum_required(VERSION 3.11)
project(taskfile C)
set(C_STANDARD_REQUIRED 90)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ALL_SRC 
  src/main.c
)

add_subdirectory(extern/cjson)
add_executable(task src/main.c)
include_directories(task PRIVATE extern src)
