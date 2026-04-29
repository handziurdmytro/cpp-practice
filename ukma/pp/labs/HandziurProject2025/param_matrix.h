/*Handziur Dmytro, NaUKMA SWE-2*/
#pragma once
#include <iostream>
#include <cassert>

/* parameterized matrix with fields as grid elements*/
template <typename T>
struct Matrix2x2
{
	T	_00, _01, 
		_10, _11;
};

template <typename T>
Matrix2x2<T> operator*(const Matrix2x2<T>& A, const Matrix2x2<T>& B)
{

	/*hardcoded multiplication using struct fields */
	return {
		A._00 * B._00 + A._01 * B._10, A._00 * B._01 + A._01 * B._11,
		A._10 * B._00 + A._11 * B._10, A._10 * B._01 + A._11 * B._11,
	};
}

/* quick power, using binary multiplication */
template<typename T> 
Matrix2x2<T> power(Matrix2x2<T> base, int exp)
{
	assert(exp > 0);

	/* realization without identity matrix */

	if (exp == 1)
		return base;

	while (exp % 2 == 0)
	{
		base = base * base;
		exp /= 2;
	}

	Matrix2x2<T> result = base;

	exp /= 2;
	if (exp > 0) {
		base = base * base;
	}

	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			result = result * base;
		}

		base = base * base;
		exp /= 2;
	}

	return result;
}

/*print parameterized matrix*/
template<typename T>
void print(const Matrix2x2<T>& A)
{ 
	std::cout	<< "\t|\t" << A._00 << "\t" << A._01 << "\t|\n"
				<< "\t|\t" << A._10 << "\t" << A._11 << "\t|\n";
}