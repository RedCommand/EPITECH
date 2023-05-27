cmake_minimum_required(VERSION 3.14)

project(${CMAKE_PROJECT_NAME}_test C CXX)

add_executable(${PROJECT_NAME} EXCLUDE_FROM_ALL
        print/print_int.cpp
        print/print_const_voidp.cpp
        print/print_string.cpp
        print/print_type.cpp
        print/print_uint.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

# googletest
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
include(FetchContent)
include(CTest)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.0 # or a later release
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
target_link_libraries(${PROJECT_NAME} ${CMAKE_PROJECT_NAME} GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
