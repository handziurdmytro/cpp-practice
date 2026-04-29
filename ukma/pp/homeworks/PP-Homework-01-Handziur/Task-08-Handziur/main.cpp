//      Узагальніть обчислення рекурентного співвідношення на третій порядок і
//      запропонуйте власний приклад.

#include <iostream>

using ui64 = std::uint64_t;
using ui32 = std::uint32_t;

// реалізація рекурентного співвідношення 3 порядку: x(n) = x(n-3) - x(n-2) * 2 + x(n-1) * 3, де x(1) = 1, x(2) = 2, x(3) = 3 
ui64 recurrentSum(ui32 n)
{
    if (n < 1)
    {
        std::cout << "Invalid input: " << n << std::endl;
        return 0;
    }
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;
    if (n == 3)
        return 6;

    ui64 x1 = 1;
    ui64 x2 = 2;
    ui64 x3 = 3;
    ui64 buffer = 0;
    ui64 sum = x1 + x2 + x3;
    for (ui32 i = 3; i < n; i++)
    {
        buffer = x1 - x2 * 2 + x3 * 3;
        sum += buffer;
        x1 = x2;
        x2 = x3;
        x3 = buffer;
    }
    return sum;
}

// повернення n члена послідовності
ui64 getNthElement(ui32 n)
{
    if (n < 1)
    {
        std::cout << "Invalid input: " << n << std::endl;
        return 0;
    }
    if (n <= 3)
        return n;

    ui64 x1 = 1;
    ui64 x2 = 2;
    ui64 x3 = 3;
    ui64 buffer = 0;
    for (ui32 i = 3; i < n; i++)
    {
        buffer = x1 - x2 * 2 + x3 * 3;
        x1 = x2;
        x2 = x3;
        x3 = buffer;
    }
    return x3;
}

int main()
{

    for (ui32 i = 1; i < 30; i++)
    {
        std::cout << "getNthElement(" << i << "): " << getNthElement(i) << std::endl;
        std::cout << "recurrentSum(" << i << "): " << recurrentSum(i) << std::endl;
        std::cout << "-------------------\n";
    }
    for (ui32 i = 1; i < 30; i++)
    {
        std::cout << getNthElement(i) << " ";
    }
    std::cout << "\n-------------------\n";
}