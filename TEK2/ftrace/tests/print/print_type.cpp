/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** print_type.cpp
*/

#pragma clang diagnostic push
#pragma ide diagnostic ignored "clion-misra-cpp2008-6-4-5"
#pragma ide diagnostic ignored "clion-misra-cpp2008-6-4-1"
#pragma ide diagnostic ignored "clion-misra-cpp2008-6-3-1"

#include <filesystem>
#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
#include "print.h"
#include "types.h"
}

TEST(print_type, print_overflow)
{
    testing::internal::CaptureStdout();
    print_type(0, NB_PRINT + 1, 0, true);
    ASSERT_EQ(fflush(stdout), 0);
    ASSERT_EQ(testing::internal::GetCapturedStdout(), "(nil)");
}

TEST(print_type, print_int)
{
    testing::internal::CaptureStdout();
    print_type(0, NUM, 42, true);
    ASSERT_EQ(fflush(stdout), 0);
    ASSERT_EQ(testing::internal::GetCapturedStdout(), "42");
}

// TEST(print_type, print_string)
//{
//     const char *str = (const char *) "Hello World";
//
//     testing::internal::CaptureStdout();
//     print_type(0, STRING, (size_t) str);
//     ASSERT_EQ(fflush(stdout), 0);
//     ASSERT_EQ(testing::internal::GetCapturedStdout(), "\"Hello World\"");
// }

TEST(print_type, print_unsigned_int)
{
    testing::internal::CaptureStdout();
    print_type(0, UNSIGNED, 42, true);
    ASSERT_EQ(fflush(stdout), 0);
    ASSERT_EQ(testing::internal::GetCapturedStdout(), "42");
}

TEST(print_type, print_void_p_null)
{
    testing::internal::CaptureStdout();
    print_type(0, VOID_P, 0, true);
    ASSERT_EQ(fflush(stdout), 0);
    ASSERT_EQ(testing::internal::GetCapturedStdout(), "NULL");
}

TEST(print_type, print_void_p)
{
    testing::internal::CaptureStdout();
    print_type(0, VOID_P, 42, true);
    ASSERT_EQ(fflush(stdout), 0);
    ASSERT_EQ(testing::internal::GetCapturedStdout(), "0x2a");
}

#pragma clang diagnostic pop
