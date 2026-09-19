#define _USE_MATH_DEFINES
#include <iostream>
#include "main.h"
#include <cassert>
#include <cmath>
#include <iomanip>
#include <numbers>

using namespace std;

int main()
{
    const int precision = 10;
    const double epsilon = 10E-10;

    cout << "\t## Exponents ##\n\n";
    
    double test = 13.5;
    assert(fabs(myExponent(test) - std::exp(test)) < epsilon);
    assert(fabs(myQuickExponent(test) - std::exp(test)) < epsilon);
    cout << "myExponent("<< test <<"):\t" << setprecision(precision) << myExponent(test) << endl;
    cout << "myQuickExponent(" << test << "):\t" << setprecision(precision) << myQuickExponent(test) << endl;
    cout << "std::exp(" << test << "):\t" << setprecision(precision) << std::exp(test) << "\n\n\n\n";

    test = -4.67;
    assert(fabs(myExponent(test) - std::exp(test)) < epsilon);
    assert(fabs(myQuickExponent(test) - std::exp(test)) < epsilon);
    cout << "myExponent(" << test << "):\t" << setprecision(precision) << myExponent(test) << endl;
    cout << "myQuickExponent(" << test << "):\t" << setprecision(precision) << myQuickExponent(test) << endl;
    cout << "std::exp(" << test << "):\t" << setprecision(precision) << std::exp(test) << "\n\n\n\n";
    



    cout << "\n\t## Trigonometric functions ##\n\n";


    /*periodicity check*/
    assert(fabs(mySin(10) - mySin(10 + 111 * (2 * M_PI))) < epsilon);
    assert(fabs(mySin(10) - mySin(10 - 111 * (2 * M_PI))) < epsilon);
    assert(fabs(myCos(10) - myCos(10 + 111 * (2 * M_PI))) < epsilon);
    assert(fabs(myCos(10) - myCos(10 - 111 * (2 * M_PI))) < epsilon);
    assert(fabs(myTg(10) - myTg(10 + 111 * M_PI)) < epsilon);
    assert(fabs(myTg(10) - myTg(10 - 111 * M_PI)) < epsilon);
    assert(fabs(myCtg(10) - myCtg(10 + 111 * M_PI)) < epsilon);
    assert(fabs(myCtg(10) - myCtg(10 - 111 * M_PI)) < epsilon);


    test = 19.9;

    assert(fabs(mySin(test) - std::sin(test)) < epsilon);
    cout << "mySin(" << test << "):\t" << setprecision(precision) << mySin(test) << endl;
    cout << "std::sin(" << test << "):\t" << setprecision(precision) << std::sin(test) << endl << endl;

    assert(fabs(myCos(test) - std::cos(test)) < epsilon);
    cout << "myCos(" << test << "):\t" << setprecision(precision) << myCos(test) << endl;
    cout << "std::cos(" << test << "):\t" << setprecision(precision) << std::cos(test) << endl << endl;

    assert(fabs(myTg(test) - std::tan(test)) < epsilon);
    cout << "mySin(" << test << "):\t" << setprecision(precision) << myTg(test) << endl;
    cout << "std::sin(" << test << "):\t" << setprecision(precision) << std::tan(test) << "\n\n\n\n";
     

    test = 19.9 + 100 * M_PI;

    assert(fabs(mySin(test) - std::sin(test)) < epsilon);
    cout << "mySin(" << test << "):\t" << setprecision(precision) << mySin(test) << endl;
    cout << "std::sin(" << test << "):\t" << setprecision(precision) << std::sin(test) << endl << endl;

    assert(fabs(myCos(test) - std::cos(test)) < epsilon);
    cout << "myCos(" << test << "):\t" << setprecision(precision) << myCos(test) << endl;
    cout << "std::cos(" << test << "):\t" << setprecision(precision) << std::cos(test) << endl << endl;

    assert(fabs(myTg(test) - std::tan(test)) < epsilon);
    cout << "myTg(" << test << "):\t" << setprecision(precision) << myTg(test) << endl;
    cout << "std::tan(" << test << "):\t" << setprecision(precision) << std::tan(test) << "\n\n\n\n";


    test = 19.9 - 100 * M_PI;

    assert(fabs(mySin(test) - std::sin(test)) < epsilon);
    cout << "mySin(" << test << "):\t" << setprecision(precision) << mySin(test) << endl;
    cout << "std::sin(" << test << "):\t" << setprecision(precision) << std::sin(test) << endl << endl;

    assert(fabs(myCos(test) - std::cos(test)) < epsilon);
    cout << "myCos(" << test << "):\t" << setprecision(precision) << myCos(test) << endl;
    cout << "std::cos(" << test << "):\t" << setprecision(precision) << std::cos(test) << endl << endl;

    assert(fabs(myTg(test) - std::tan(test)) < epsilon);
    cout << "myTg(" << test << "):\t" << setprecision(precision) << myTg(test) << endl;
    cout << "std::tan(" << test << "):\t" << setprecision(precision) << std::tan(test) << "\n\n\n\n";




    cout << "\n\t## Natural Logarithm ##\n\n";
    assert(fabs(myLn(M_E) - 1.0) < epsilon);

    test = 23.67;

    assert(fabs(myLn(test) - std::log(test)) < epsilon);
    cout << "myLn(" << test << "):\t" << setprecision(precision) << myLn(test) << endl;
    cout << "std::log(" << test << "):\t" << setprecision(precision) << std::log(test) << "\n\n\n\n";

    test = 4.91;

    assert(fabs(myLn(test) - std::log(test)) < epsilon);
    cout << "myLn(" << test << "):\t" << setprecision(precision) << myLn(test) << endl;
    cout << "std::log(" << test << "):\t" << setprecision(precision) << std::log(test) << "\n\n\n\n";



    return 0;
}


double exponent(double x, double epsilon)
{
    assert(epsilon > 0.0);

    double step = 1.0;
    double sum = step;
    int i = 0;

    while (fabs(step) > epsilon)
    {
        i++;
        step = step / i * x;
        sum += step;
    }

    return sum;
}

double quickExponent(double x, double epsilon)
{
    assert(epsilon > 0.0);
    if (x < 0.0)
        return 1 / quickExponent(fabs(x), epsilon);

    int integerPart = std::floor(x);
    double fractionalPart = x - integerPart;

    return exponent(fractionalPart, epsilon) * quickPower(M_E, integerPart);
}

double quickPower(double x, int n)
{
    assert(x >= 0 && n >= 0);

    if (n == 0)
        return 1.0;

    if (x == 0)
        return 0;

    double buffer = 1.0;

    while (n != 0)
    {
        if (n % 2 == 1)
        {
            n--;
            buffer *= x;
        }

        if (n == 0)
            break;

        x *= x;
        n /= 2;
    };

    return buffer;
}

double sin(double x, double epsilon)
{
    assert(epsilon > 0.0);

    x = std::fmod(x, M_PI * 2);

    double step = x;
    double sum = step;
    int n = 1;

    while (fabs(step) > epsilon)
    {
        n += 2;

        step = step * (x * x) / ((n - 1) * n);

        sum += ((n + 1) % 4 == 0) ? -step : step;
    }

    return sum;
}

double cos(double x, double epsilon)
{
    assert(epsilon > 0.0);

    x = std::fmod(x, M_PI * 2);

    double step = 1;
    double sum = step;
    int n = 0;

    while (fabs(step) > epsilon)
    {
        n += 2;

        step = step * (x * x) / ((n - 1) * n);

        sum += (n % 4 == 0) ? step : -step;
    }

    return sum;
}

double tg(double x, double epsilon) 
{
    assert(epsilon > 0.0);

    double sinVal = sin(x, epsilon);
    double cosVal = cos(x, epsilon);
    assert(sinVal >= -1 && sinVal <= 1 && cosVal >= -1 && cosVal <= 1);

    if (cosVal == 0)
        return NAN;

    return sinVal / cosVal;
}

double ctg(double x, double epsilon)
{
    assert(epsilon > 0.0);

    double sinVal = sin(x, epsilon);
    double cosVal = cos(x, epsilon);
    assert(sinVal >= -1 && sinVal <= 1 && cosVal >= -1 && cosVal <= 1);

    if (sinVal == 0)
        return NAN;

    return cosVal / sinVal;
}

double ln(double x, double epsilon)
{
    assert(x > 0 && epsilon > 0);

    double sum = 0.0;

    while (x >= 2.0)
    {
        x /= M_E;
        sum++;
    }

    double step = x - 1.0;
    sum += step;
    int n = 1;

    while (fabs(step) > epsilon)
    {
        n++;
        step = step * (x - 1) * (n - 1) / n;
        sum += (n % 2 == 0) ? -step : step;
    }

    return sum;
}


double myExponent(double x)
{
    return exponent(x, std::numeric_limits<double>::epsilon());
}

double myQuickExponent(double x) 
{
    return quickExponent(x, std::numeric_limits<double>::epsilon());
}

double mySin(double x)
{
    return sin(x, std::numeric_limits<double>::epsilon());
}

double myCos(double x)
{
    return cos(x, std::numeric_limits<double>::epsilon());
}

double myTg(double x)
{
    return tg(x, std::numeric_limits<double>::epsilon());
}

double myCtg(double x)
{
    return ctg(x, std::numeric_limits<double>::epsilon());
}

double myLn(double x)
{
    return ln(x, std::numeric_limits<double>::epsilon());
}

double exponent(double x, int n)
{
    assert(n > 0);

    double step = 1.0;
    double sum = step;

    for (double i = 1; i <= n; i++)
    {
        step = step / i * x;
        sum += step;
    }

    return sum;
}