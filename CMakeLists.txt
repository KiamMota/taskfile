cmake_minimum_required(VERSION 3.11)
project(taskfile C)
set(C_STANDARD_REQUIRED 90)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ALL_SRC 
  src/main.c
  src/messages.c
  src/dispatch.c
  src/cmd-init.c
  src/utils-file.c
  src/tfile_context.c
)

add_subdirectory(extern/cjson)
add_executable(task ${ALL_SRC})
include_directories(task PRIVATE extern src)
target_link_libraries(task PRIVATE cjson)
