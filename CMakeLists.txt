cmake_minimum_required(VERSION 3.10)

project(linked-int-addition)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(src)
add_executable(linked-int-addition main.c)
target_link_libraries(linked-int-addition PRIVATE linked-int)
