#include "dichotomy.h"
#include <cassert>
#include <cmath>
#include <numbers>

double Simpson(double a, double b, double(*f)(double), double eps)
{
	assert(a <= b);
	assert(eps > 0.0);
	assert(f != nullptr);

	double curArea = 0.0;
	double prevArea = 0.0;
	int power = 1;

	double first = f(a);
	double last = f(b);

	double prevIter = 0.0;

	do
	{
		power *= 2;
		double step = (b - a) / power;

		double oddSum = 0.0;
		double evenSum = prevIter;

		{
			double current = a + step;
			for (int i = 0; i < power - 1; i += 2)
			{
				assert(current >= a && current <= b);
				assert(i >= 0 && i < power - 1);
				oddSum += f(current);
				current += step * 2;
			}
		}

		prevArea = curArea;

		curArea = (step / 3.0) * ((first + last + (4 * oddSum) + (2 * evenSum)));
		prevIter = oddSum + evenSum;
	} while (fabs(curArea - prevArea) > eps);

	return curArea;
}

namespace integrals
{
	double dirichletFun(double x)
	{
		if (x == 0.0)
			return 1.0;

		return sin(x) / x;
	}

	double dirichlet(
		double(*integral)(double a, double b, double(*f)(double), double eps),
		double epsilon
	)
	{
		assert(integral != nullptr);
		assert(epsilon > 0.0);

		double const pseudoInfinity = 100'000.0;
		return integral(0.0, pseudoInfinity, dirichletFun, epsilon);

	}

	double gaussFun(double x)
	{
		assert(x >= 0.0);

		return exp(-pow(x, 2));
	}

	double gauss(
		double(*integral)(double a, double b, double(*f)(double), double eps),
		double epsilon
	)
	{
		assert(integral != nullptr);
		assert(epsilon > 0.0);

		double const pseudoInfinity = 15.0;
		return integral(0.0, pseudoInfinity, gaussFun, epsilon);
	}

	double fresnelFun(double x)
	{
		if (x == 0.0)
			return 1.0;

		return sin(x * x);
	}
	double fresnel(
		double(*integral)(double a, double b, double(*f)(double), double eps),
		double epsilon
	)
	{
		assert(integral != nullptr);
		assert(epsilon > 0.0);

		double const pseudoInfinity = 250.0;
		return integral(0.0, pseudoInfinity, fresnelFun, epsilon);
	};
}