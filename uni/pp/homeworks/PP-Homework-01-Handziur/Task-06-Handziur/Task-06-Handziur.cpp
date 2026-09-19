
// Обчислити суму (x^1)^2 + (x^2)^2 ... (x^n)^2 для заданих x та n

#include <iostream>

using ui32 = std::uint32_t;

//основна функція з найширшою функціональністю
double recurrentRowOfPowers(double x, ui32 n, ui32 power)
{
    if (n < 1 || x < 1 || power < 1)
    {
        std::cout << "Invalid input: (x: " << x << ", n: " << n << ", pow:" << power << ")" << std::endl;
        return 0;
    }

    double currentElement = 1.0;
    double sum = 0.0;
    double multiplier = x;

    for (ui32 i = 0; i < power - 1; i++) 
    {
        multiplier *= x;
    }

    for (ui32 i = 0; i < n; i++)
    {
        currentElement = currentElement * multiplier;
        sum += currentElement;
    }

    return sum;
}
//  пояснення:
// --------------------------------------------
//  1. за властивістю степенів, можемо позбутись 
// багатоповерховості за допомогою множення
//
// (x^1)^p + (x^2)^p ... (x^n)^p ===> x^(p*1) + x^(p*2) ... x^(p*n)
//
// 2. бачимо закономірність: степінь кожного наступного члена збільшується на p,
// отже можемо оформити обчислення рекурентно: з попереднього члена вивести наступний,
// а саме: при k >= 1 та k < n,  x^(p*2*(k+1)) = x^(p*2*k) * x^p
// ---------------------------------------------

//overload версія попередньої функції, що відповідає конкретній умові задачі (вхідні параметри n та x)
double recurrentRowOfPowers(double x, ui32 n)
{
    return recurrentRowOfPowers(x, n, 2);
}

//неефективний спосіб (3 цикли)
double rowOfPowers(double x, ui32 n)
{
    const ui32 power = 2;
    double sum = 0.0;
    double buffer = 0.0;
    double buffer2 = 0.0;

    for (ui32 i = 1; i <= n; i++)
    {
        for (ui32 j = 0; j < power; j++)
        {
            buffer = x;
            for (ui32 k = 0; k < i - 1; k++)
            {
                buffer *= x;
            }
            if (j == 0)
            {
                buffer2 = buffer;
                continue;
            }
            buffer2 *= buffer;
        }
        sum += buffer2;
    }

    return sum;
}

int main()
{
    std::cout << "\n\t\t** Optimized **\n\n";

    std::cout << "recurrentRowOfPowers(1, 4): " << recurrentRowOfPowers(1, 4) << std::endl;
    std::cout << "recurrentRowOfPowers(2, 2): " << recurrentRowOfPowers(2, 2) << std::endl;
    std::cout << "recurrentRowOfPowers(3, 3): " << recurrentRowOfPowers(3, 3) << std::endl;
    std::cout << "recurrentRowOfPowers(4, 2): " << recurrentRowOfPowers(4, 2) << std::endl;
    std::cout << "recurrentRowOfPowers(2, 3): " << recurrentRowOfPowers(2, 3) << std::endl;
    std::cout << "recurrentRowOfPowers(3, 5): " << recurrentRowOfPowers(3, 5) << std::endl;

    std::cout << "\n\t\t** Overloaded Optimized **\n\n";

    std::cout << "recurrentRowOfPowers(1, 4, 2): " << recurrentRowOfPowers(1, 4, 2) << std::endl;
    std::cout << "recurrentRowOfPowers(2, 2, 2): " << recurrentRowOfPowers(2, 2, 2) << std::endl;
    std::cout << "recurrentRowOfPowers(3, 3, 2): " << recurrentRowOfPowers(3, 3, 2) << std::endl;
    std::cout << "recurrentRowOfPowers(4, 2, 2): " << recurrentRowOfPowers(4, 2, 2) << std::endl;
    std::cout << "recurrentRowOfPowers(2, 3, 2): " << recurrentRowOfPowers(2, 3, 2) << std::endl;
    std::cout << "recurrentRowOfPowers(3, 5, 2): " << recurrentRowOfPowers(3, 5, 2) << std::endl;\

    std::cout << "\n\t\t** Non-Optimized **\n\n";
    
    std::cout << "rowOfPowers(1, 4): " << rowOfPowers(1, 4) << std::endl;
    std::cout << "rowOfPowers(2, 2): " << rowOfPowers(2, 2) << std::endl;
    std::cout << "rowOfPowers(3, 3): " << rowOfPowers(3, 3) << std::endl;
    std::cout << "rowOfPowers(4, 2): " << rowOfPowers(4, 2) << std::endl;
    std::cout << "rowOfPowers(2, 3): " << rowOfPowers(2, 3) << std::endl;
    std::cout << "rowOfPowers(3, 5): " << rowOfPowers(3, 5) << std::endl;
}
