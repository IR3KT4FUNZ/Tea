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

# --- 4. Define Your Header-Only Library ---
# The Vector class is header-only, so we define 'tea' as an INTERFACE library.
# This means no source files are compiled, but the include directories are propagated.
add_library(tea INTERFACE)

# Publicly list your 'include' directory.
# Any target that links to 'tea' will automatically get the 'include' path.
target_include_directories(tea 
  INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- 5. Define Your Main Executable ---
# The executable is built *only* from src/main.cpp
add_executable(main src/main.cpp)
# 'main' links to 'tea' to get access to the include paths for Vector.h
target_link_libraries(main PRIVATE tea)

# --- 6. Define Your Test Executable ---
enable_testing()
add_executable(run_tests test/Vector_test.cpp)

# 'run_tests' links to 'tea' (getting its include path) and GTest
target_link_libraries(run_tests 
  PRIVATE 
    tea
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_tests)