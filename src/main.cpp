#include <iostream>
#include <string_view>

#include "tea/Queue.h"
#include "tea/Vector.h"

int main() {
    // C++23 feature: using std::string_view literal
    tea::Vector<int> v;
    tea::Queue<int> a;
    a.push(2);
    a.push(3);

    std::cout << a.top() << '\n';
    a.pop();
    std::cout << a.top() << '\n';

    // std::cout << greet("World"sv) << std::endl;
    return 0;
}