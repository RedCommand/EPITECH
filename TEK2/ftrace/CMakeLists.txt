cmake_minimum_required(VERSION 3.14)

project(myftrace C)

set(CMAKE_COLOR_DIAGNOSTICS ON)

find_library(libelf elf REQUIRED)

add_executable(ftrace main.c)

add_library(${PROJECT_NAME} STATIC
        src/fork.c
        src/print/print.c
        src/print/print_int.c
        src/print/print_string.c
        src/print/print_uint.c
        src/ftrace.c
        src/nm.c
        src/wrapper/wrapper.c
        src/print/print_ptr.c
        src/args.c
        src/wrapper/get.c src/wrapper/ptrace.c)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(ftrace PUBLIC ${PROJECT_NAME} elf)

# tests
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_subdirectory(tests)
endif ()
