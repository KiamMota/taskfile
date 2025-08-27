cmake_minimum_required(VERSION 3.11)
project(taskfile C)
set(C_STANDARD_REQUIRED 90)

set(ALL_SRC 
  src/main.c
)

add_subdirectory(extern)
add_executable(task src/main.c)
target_include_directories(task PRIVATE extern src)
