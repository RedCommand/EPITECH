cmake_minimum_required(VERSION 3.14)

project(panoramix)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COLOR_DIAGNOSTICS ON)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_library(${PROJECT_NAME}_lib STATIC src/with_sem.c main.c src/args.c src/utils.c src/panoramix.c src/print_villager.c src/print_druid.c)
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)


add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

# script for deps graph
find_program(DOT_EXE "dot")
if (DOT_EXE)
    message(STATUS "dot found: ${DOT_EXE}")

    set(DOT_OUTPUT_TYPE "svg" CACHE STRING "Build a dependency graph. Options are dot output types: ps, png, pdf...")

    add_custom_target(dependency-graph
            COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR} --graphviz=${CMAKE_BINARY_DIR}/graphviz/${PROJECT_NAME}.dot
            COMMAND ${DOT_EXE} -T${DOT_OUTPUT_TYPE} ${CMAKE_BINARY_DIR}/graphviz/${PROJECT_NAME}.dot -o ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.${DOT_OUTPUT_TYPE}
            )

    add_custom_command(
            TARGET dependency-graph POST_BUILD
            COMMAND
            xdg-open ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.${DOT_OUTPUT_TYPE} || true;
            COMMENT
            "Dependency graph generated and located at ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.${DOT_OUTPUT_TYPE}"
    )
else ()
    message(STATUS "dot not found!")
endif ()
