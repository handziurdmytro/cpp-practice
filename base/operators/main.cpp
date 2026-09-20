#include <iostream>
#include "Vector.h"

int main() {
    Vector v1{1, 2};
    Vector v2{3, 4};

    v1 += v2;

    std::cout << v1 << '\n';

    Vector v3 = v1 + v2;

    std::cout << v3 << '\n';

    return 0;
}
