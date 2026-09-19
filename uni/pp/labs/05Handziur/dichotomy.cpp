#include "dichotomy.h"
#include <cassert>
#include <cmath>

using namespace std;

double dichotomy(double (*f)(double), double a, double b, double eps)
{
	assert(eps > 0.0);
	assert(f != nullptr);
	assert(a <= b);

	double min = a;
	double max = b;
	double funMin = f(min);

	double x = 0.0;

	do
	{
		x = (max + min) / 2.0;
		double funX = f(x);

		if (funX == 0.0)
			return x;

		if (funX * funMin > 0.0)
		{
			min = x;
			funMin = funX;
		}
		else
		{
			max = x;
		}

	} while (fabs(max - min) > eps);

	return (max + min) / 2.0;
}

namespace tests
{
	double fun1(double x)
	{
		return sin(x) - x;
	}

	double fun2(double x)
	{
		return sin(x);
	}

	double fun3(double x)
	{
		assert(x > 0.0);
		return log(x) - 1;
	}

	double fun4(double x)

	{
		return exp(x) - 2 + x;
	}
}