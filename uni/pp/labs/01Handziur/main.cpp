#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    runTests();
    //!!! Conclusion is in this project as 'Handziur-Conclusion-01.txt'
    return 0;
}


double power(double x, int n)
{
    int steps = 0;
    try
    {
        if (x < 0)
            throw x;

        if (n < 0)
            throw n;

        double buffer = 1.0;

        for (int i = 0; i < n; i++)
            buffer *= x, steps++;

        cout << "Amount of steps: " << steps << endl;

        return buffer;
    }
    catch (double error)
    {
        std::cout << "Invalid X value: " << error << std::endl;
    }
    catch (int error)
    {
        std::cout << "Invalid N value: " << error << std::endl;
    }
    return -1;
}

double quickPower(double x, int n)
{
    int steps = 0;
    try
    {
        if (x < 0)
            throw x;

        if (n < 0)
            throw n;

        double buffer = 1.0;

        while (n != 0)
        {
            if (n % 2 == 1)
            {
                n--;
                buffer *= x;
                steps++;
            }

            if (n == 0)
                break;
                
            x *= x;
            n /= 2;
            steps++;
        };

        cout << "Amount of steps: " << steps << endl;

        return buffer;
    }
    catch (double error)
    {
        std::cout << "Invalid X value: " << error << std::endl;
    }
    catch (int error)
    {
        std::cout << "Invalid N value: " << error << std::endl;
    }
    return -1;
}

double power_rec(double x, int n)
{
    try
    {
        if (x < 0)
            throw x;

        if (n < 0)
            throw n;

        if (n == 0 || n == 1)
        {
            cout << "Base case step in recursion: power_rec(" << x << ", " << n << "); \n";
            return n == 0 ? 1.0 : x;
        }

        cout << "Step in recursion: power_rec(" << x << ", " << n << ");\n";
        return x * power_rec(x, n - 1);
    }
    catch (double error)
    {
        std::cout << "Invalid X value: " << error << std::endl;
    }
    catch (int error)
    {
        std::cout << "Invalid N value: " << error << std::endl;
    }
    return -1;
}

double quickPower_rec(double x, int n)
{
    try
    {
        if (x < 0)
            throw x;

        if (n < 0)
            throw n;


        if (n == 0 || n == 1)
        {
            cout << "Base case step in recursion: quickPower_rec(" << x << ", " << n << "); \n";
            return n == 0 ? 1.0 : x;
        }

        cout << "Step in recursion: quickPower_rec(" << x << ", " << n << ");\n";


        if (n % 2 == 0)
        {
            double halfPower = quickPower_rec(x, n / 2);
            return halfPower * halfPower;
        }
        else
        {
            return x * quickPower_rec(x, n - 1);
        }
    }
    catch (double error)
    {
        std::cout << "Invalid X value: " << error << std::endl;
    }
    catch (int error)
    {
        std::cout << "Invalid N value: " << error << std::endl;
    }
    return -1;
}

void runTests() 
{

    //  TEST #1

    cout << "\t### TEST #1 (2^6) ###\n\n";
    double p1 = power(2.0, 6); cout << "power:\t\t\t" << p1 << "\n\n";
    double qp1 = quickPower(2.0, 6); cout << "quick power:\t\t" << qp1 << "\n\n";
    double pr1 = power_rec(2.0, 6); cout << "\nrecursive power:\t\t" << pr1 << "\n\n";
    double qpr1 = quickPower_rec(2.0, 6); cout << "\nrecursive quick power:\t\t" << qpr1 << "\n\n";
    cout << "\n-------------------------------------------------------\n";
    cout << "Validation: " << boolalpha << (p1 == qp1 && qp1 == pr1 && pr1 == qpr1) << endl;
    cout << "-------------------------------------------------------\n";

    //  TEST #2

    cout << "\t### TEST #2 (3^12) ###\n\n";
    double p2 = power(3.0, 12); cout << "power:\t\t\t" << p2 << "\n\n";
    double qp2 = quickPower(3.0, 12); cout << "quick power:\t\t" << qp2 << "\n\n";
    double pr2 = power_rec(3.0, 12); cout << "\nrecursive power:\t\t" << pr2 << "\n\n";
    double qpr2 = quickPower_rec(3.0, 12); cout << "\nrecursive quick power:\t\t" << qpr2 << "\n\n";
    cout << "\n-------------------------------------------------------\n";
    cout << "Validation: " << boolalpha << (p2 == qp2 && qp2 == pr2 && pr2 == qpr2) << endl;
    cout << "-------------------------------------------------------\n";

    //  TEST #3

    cout << "\t### TEST #3 (2^50) ###\n\n";
    double p3 = power(2.0, 50); cout << "power:\t\t\t" << p3 << "\n\n";
    double qp3 = quickPower(2.0, 50); cout << "quick power:\t\t" << qp3 << "\n\n";
    double pr3 = power_rec(2.0, 50); cout << "\nrecursive power:\t\t" << pr3 << "\n\n";
    double qpr3 = quickPower_rec(2.0, 50); cout << "\nrecursive quick power:\t\t" << qpr3 << "\n\n";
    cout << "\n-------------------------------------------------------\n";
    cout << "Validation: " << boolalpha << (p3 == qp3 && qp3 == pr3 && pr3 == qpr3) << endl;
    cout << "-------------------------------------------------------\n";


    cout << "\n!!! Conclusion is in this project as 'Handziur-Conclusion-01.txt'";
    cout << "-------------------------------------------------------\n";
}