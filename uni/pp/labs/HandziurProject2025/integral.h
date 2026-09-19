/*Handziur Dmytro, NaUKMA SWE - 2*/
#pragma once
#include <cassert>
#include <cmath>

/* mark double fun ptr as Function */
using Function = double(*)(double);

// non-optimized iterative computation
double integrate_trapezoidal(double a, double b, double eps, Function f)
{
	assert(a <= b);
	assert(eps > 0.0);
	assert(f != nullptr);

	double curArea = 0.0;
	double prevArea = 0.0;
	int power = 1;// on how many pieces will be area divided

	do
	{
		power *= 2;
		double step = (b - a) / power;
		prevArea = curArea;

		curArea = 0.0;
		for (int i = 0; i < power; i++)
		{
			/* for each piece solve trapeze area*/
			curArea += (f(a + i * step) + f(a + (i + 1) * step)) / 2 * step;
		}
		// comparing current and previous result with epsilon precision
	} while (fabs(curArea - prevArea) > eps);

	return curArea;
}

/*simple test funs */
namespace Functions
{
	// y = x ^ 2
	double pow_2(double x)
	{
		return x * x;
	}

	// y = x + 5
	double add5(double x)
	{
		return x + 5;
	}

	// y = x * 2
	double mul2(double x)
	{
		return x * 2;
	}
}