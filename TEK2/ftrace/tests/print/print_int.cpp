/*
** EPITECH PROJECT, 2023
** Project
** File description:
** tests.cpp
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

TEST(print_int, print_zero)
{
    testing::internal::CaptureStdout();
    print_int(0, 0);
    ASSERT_EQ(fflush(stdout), 0);
    ASSERT_EQ(testing::internal::GetCapturedStdout(), "0");
}

#pragma clang diagnostic pop
