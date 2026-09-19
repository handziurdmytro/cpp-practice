#include <iostream>
#include "dichotomy.h"
#include "integral.h"
#include <cassert>
#include <cmath>

using namespace std;

bool equalsDouble(double a, double b, double eps);

int main()
{
    double eps = 0.001;

    assert(equalsDouble(10.0, 10.0, 0.001));
    assert(equalsDouble(19.3, 19.3, 0.001));
    assert(equalsDouble(28.12002, 28.12001, 0.001));
    assert(!equalsDouble(28.12002, 28.12001, 0.000001));

    cout << "\n\tTask #1 DICHOTOMY\n\n";

    double res1 = dichotomy(tests::fun1, -1.0, 1.0, eps);
    cout << "sin(x) = x, [-1,1]: " << res1 << endl;

    double res2 = dichotomy(tests::fun2, std::numbers::pi-1.0, std::numbers::pi, eps);
    cout << "sin(x) = 0, [PI - 1, PI]: " << res2 << endl;

    double res3 = dichotomy(tests::fun3, 2.0, 3.0, eps);
    cout << "ln(x) = 1, [2, 3]: " << res3 << endl;

    double res4 = dichotomy(tests::fun4, 0.0, 2.0, eps);
    cout << "exp(x) = 2 - x, [0,2]: " << res4 << endl;

    cout << "\n--------------------\n\tTask #2 SIMPSON\n\n";

    double dirichletRes = integrals::dirichlet(Simpson, eps);
    cout << "Dirichlet result: " << dirichletRes << endl;
    cout << "Dirichlet desired: " << integrals::dirichletCorrect << endl;
    assert(equalsDouble(dirichletRes, integrals::dirichletCorrect, eps));

    double gaussRes = integrals::gauss(Simpson, eps);
    cout << "Gauss result: " << gaussRes << endl;
    cout << "Gauss desired: " << integrals::gaussCorrect << endl;
    assert(equalsDouble(gaussRes, integrals::gaussCorrect, eps));

    double fresnelRes = integrals::fresnel(Simpson, eps);
    cout << "Fresnel result: " << fresnelRes << endl;
    cout << "Fresnel desired: " << integrals::fresnelCorrect << endl;
    assert(equalsDouble(fresnelRes, integrals::fresnelCorrect, eps));

    cout << "\n--------------------\n";

    return 0;
}

bool equalsDouble(double a, double b, double eps)
{
    return fabs(a - b) <= eps;
}