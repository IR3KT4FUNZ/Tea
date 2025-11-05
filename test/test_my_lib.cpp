#include <gtest/gtest.h>

#include "my_lib.h"  // Include the code to be tested

// Test fixture for greet function
TEST(GreetTest, HandlesBasicInput) {
    EXPECT_EQ(greet("World"), "Hello, World!");
    EXPECT_EQ(greet("C++23"), "Hello, C++23!");
}

TEST(GreetTest, HandlesEmptyInput) {
    EXPECT_EQ(greet(""), "Hello, !");
}