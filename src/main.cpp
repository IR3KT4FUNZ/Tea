#include <iostream>
#include <string_view>  // C++17

#include "my_lib.h"

int main() {
    // C++23 feature: using std::string_view literal
    using namespace std::literals;

    std::cout << greet("World"sv) << std::endl;
    return 0;
}