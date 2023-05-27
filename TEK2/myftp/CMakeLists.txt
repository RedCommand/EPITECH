cmake_minimum_required(VERSION 3.14)

project(myftp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COLOR_DIAGNOSTICS ON)

add_library(${PROJECT_NAME}_lib STATIC src/ftp.c)
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)


add_executable(${PROJECT_NAME} main.c src/CLIENT/client.c src/CMD/cmd.c src/SERVER/server.c src/UTILS/utils.c src/UTILS/cwd.c src/CMD/pasv.c src/CMD/list.c src/UTILS/client.c src/CMD/user.c src/CMD/files.c src/CMD/path.c src/SERVER/init.c src/CLIENT/init.c)
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