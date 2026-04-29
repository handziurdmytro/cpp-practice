/*Handziur Dmytro, NaUKMA SWE - 2*/
#pragma once
#include <cmath>
#include <cassert>
#include <iostream>

struct Rational
{
	long long int _numerator, _denominator;
};

/*Euclid algo*/
long long GCD(long long a, long long b)
{
	a = abs(a);
	b = abs(b);

	if (a == 0 && b == 0)
		return 0;
	else if (a == 0)
		return b;
	else if (b == 0)
		return a;

	while (a != b)
	{
		a > b ? a -= b : b -= a;
	}

	return a;
}

/* factory method */
Rational create(long long num, long long den)
{
	assert(den != 0);
	long long gcd = GCD(abs(num), abs(den));
	/* simplifying fractions */
	if (gcd != 0)
	{
		num /= gcd;
		den /= gcd;
	}

	/* den cannot be negative*/
	if (den < 0) {
		num = -num;
		den = -den;
	}
	return Rational{ num, den };
}

Rational operator+(const Rational& rat1, const Rational& rat2)
{
	/* a/b + c/d = (ad + dc) / bd*/
	long long num = rat1._numerator * rat2._denominator +
		rat2._numerator * rat1._denominator;
	long long den = rat1._denominator * rat2._denominator;
	return create(num, den);
}

Rational operator*(const Rational& rat1, const Rational& rat2)
{
	/* a/b * c/d = ac / bd*/
	long long num = rat1._numerator * rat2._numerator;
	long long den = rat1._denominator * rat2._denominator;

	return create(num, den);
}

/* only integeres allowed */
template<std::integral T>
Rational operator+(const T& integer, const Rational& rat)
{
	Rational rat_int = create(integer, 1);
	return rat_int + rat;
}

template<std::integral T>
Rational operator*(const T& integer, const Rational& rat)
{
	Rational rat_int = create(integer, 1);
	return rat_int * rat;
}

template<std::integral T>
Rational operator+(const Rational& rat, const T& integer)
{
	Rational rat_int = create(integer, 1);
	return rat_int + rat;
}

template<std::integral T>
Rational operator*(const Rational& rat, const T& integer)
{
	Rational rat_int = create(integer, 1);
	return rat_int * rat;
}

bool operator==(const Rational& rat1, const Rational& rat2)
{
	/* a/b == c/d when a == c && b == d*/
	return (rat1._numerator == rat2._numerator) && (rat1._denominator == rat2._denominator);
}
bool operator!=(const Rational& rat1, const Rational& rat2)
{
	/* a/b != c/d when a != c || b != d*/
	// we do not use GCD, because create() normalizes francions
	return (rat1._numerator != rat2._numerator) || (rat1._denominator != rat2._denominator);
}
bool operator>(const Rational& rat1, const Rational& rat2)
{
	/* a/b > c/d when ad > bc*/
	// we do not use GCD, because create() normalizes francions
	return rat1._numerator * rat2._denominator > rat2._numerator * rat1._denominator;
}
bool operator<(const Rational& rat1, const Rational& rat2)
{
	/* a/b < c/d when ad < bc*/
	return rat1._numerator * rat2._denominator < rat2._numerator * rat1._denominator;
}
bool operator>=(const Rational& rat1, const Rational& rat2)
{
	return rat1 > rat2 || rat1 == rat2;
}
bool operator<=(const Rational& rat1, const Rational& rat2)
{
	return rat1 < rat2 || rat1 == rat2;
}
std::ostream& operator<<(std::ostream& out, const Rational& rat)
{
	/* format: num/den */
	out << rat._numerator << "/" << rat._denominator;
	return out;
}