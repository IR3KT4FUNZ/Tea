# --- 1. Project Setup ---
cmake_minimum_required(VERSION 3.20)
project(MyCppProject VERSION 1.0)

# --- 2. Set C++ Standard to 23 ---
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 3. Add GTest using FetchContent ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# --- 4. Define Your Main Library ---
# Add the library using only its source files
add_library(my_lib
  src/my_lib.cpp
)

# *** KEY CHANGE ***
# Publicly list your 'include' directory.
# This tells CMake that 'my_lib' requires this directory for its
# public headers, and any target that links to 'my_lib' 
# (like 'main' or 'run_tests') will also get this include path.
target_include_directories(my_lib 
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- 5. Define Your Main Executable ---
add_executable(main src/main.cpp)
# 'main' links to 'my_lib' and automatically gets the include path
target_link_libraries(main PRIVATE my_lib)

# --- 6. Define Your Test Executable ---
enable_testing()
add_executable(run_tests test/test_my_lib.cpp)

# 'run_tests' links to 'my_lib' (getting its include path) and GTest
target_link_libraries(run_tests 
  PRIVATE 
    my_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_tests)