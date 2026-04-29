#pragma once

double dichotomy(double (*f)(double), double a, double b, double eps);
namespace tests
{
	double fun1(double x);
	double fun2(double x);
	double fun3(double x);
	double fun4(double x);
}