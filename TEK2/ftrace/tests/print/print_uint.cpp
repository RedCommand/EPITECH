/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** print_uint.cpp
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
}

TEST(print_unsigned_int, print_42)
{
    testing::internal::CaptureStdout();
    print_unsigned_int(0, 42);
    ASSERT_EQ(fflush(stdout), 0);
    ASSERT_EQ(testing::internal::GetCapturedStdout(), "42");
}

#pragma clang diagnostic pop
