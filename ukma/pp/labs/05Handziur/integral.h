#pragma once
#include <numbers>

double Simpson(double a, double b, double(*f)(double), double eps);
namespace integrals
{
	double dirichlet(
		double(*integral)(double a, double b, double(*f)(double), double eps),
		double epsilon
	);
	double dirichletCorrect = std::numbers::pi / 2.0;

	double gauss(
		double(*integral)(double a, double b, double(*f)(double), double eps),
		double epsilon
	);
	double gaussCorrect = sqrt(std::numbers::pi) / 2.0;

	double fresnel(
		double(*integral)(double a, double b, double(*f)(double), double eps),
		double epsilon
	);
	double fresnelCorrect = sqrt(std::numbers::pi / 8.0);
}