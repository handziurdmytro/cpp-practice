// Developed by Handziur Dmytro on 21.02.2026
#include "TComplex.h"
#include "AComplex.h"
#include <cmath>
#include <cassert>
#include <numbers>
#include <iostream>

#define TC_DEBUG

/*
	implicitly converts double -> TComplex; explicit keyword will
	require a realization of lots of boilerplate functions (mul/div(TC/double, double/TC)
*/
/*explicit*/ TComplex::TComplex(double r, double phi) : r_(r), phi_(phi)
{
	normalize();
#ifdef TC_DEBUG
	std::cout << "[CREATION] TComplex: " << *this << '\n';
#endif
};

/*
	r = sqrt(re^2 + im^2)
	phi = arctan(im / re)
*/
TComplex::TComplex(const AComplex& alg) 
{
	double re = alg.re();
	double im = alg.im();
	this->r_ = std::sqrt(re * re + im * im);
	this->phi_ = std::atan2(im, re);
	normalize();
#ifdef TC_DEBUG
	std::cout << "[CONVERTION] AComplex " << alg << " -> TComplex " << *this << '\n';
#endif
}

TComplex::~TComplex()
{
#ifdef TC_DEBUG
	std::cout << "[DESTRUCTION] TComplex: " << *this << '\n';
#endif
}

TComplex::TComplex(const TComplex& tri) : r_(tri.r_), phi_(tri.phi_)
{
#ifdef TC_DEBUG
	std::cout << "[COPY] TComplex: " << *this << '\n';
#endif
}

void TComplex::normalize()
{
	if (this->r_ == 0)
	{
		this->phi_ = 0;
	}
	else 
	{
		normalize_r();
		normalize_phi();
	}
}
void TComplex::normalize_r()
{
	if (this->r_ < 0)
	{
		this->r_ *= -1;
		this->phi_ += std::numbers::pi;
	}
}
void TComplex::normalize_phi()
{
	double pi = std::numbers::pi;
	this->phi_ = std::fmod(this->phi_, pi * 2.0);
	if (this->phi_ < 0.0)
	{
		this->phi_ += pi * 2.0;
	}
}

std::ostream& operator<<(std::ostream& os, const TComplex& tri)
{
	return os << '<' << tri.r() << ", " << tri.phi() << '>';
}

TComplex& TComplex::operator*=(const TComplex& tri)
{
	this->r_ *= tri.r_;
	this->phi_ += tri.phi_;
	normalize();
	return *this;
}

TComplex operator*(const TComplex& tri1, const TComplex& tri2)
{
	TComplex temp(tri1);
	temp *= tri2;
	return temp;
}

TComplex& TComplex::operator/=(const TComplex& tri)
{
	assert(tri.r_ != 0);
	this->r_ /= tri.r_;
	this->phi_ -= tri.phi_;
	normalize();
	return *this;
}
TComplex operator/(const TComplex& tri1, const TComplex& tri2)
{
	TComplex temp(tri1);
	temp /= tri2;
	return temp;
}

TComplex& TComplex::operator+=(const TComplex& tri)
{
	*this = (*this) + tri;
	return *this;
}

TComplex& TComplex::operator-=(const TComplex& tri)
{
	*this = (*this) - tri;
	return *this;
}

/*
TComplex& TComplex::operator*=(double n)
{
	if (n >= 0)
	{
		this->r_ *= n;
	}
	else
	{
		this->r_ *= -n;
		this->phi_ += std::numbers::pi;
	}
	normalize();
	return *this;
}
TComplex operator*(double n, const TComplex& tri)
{
	TComplex temp(n);
	temp *= tri;
	return temp;
}
TComplex operator*(const TComplex& tri, double n)
{
	TComplex temp(tri);
	temp *= n;
	return temp;
}
TComplex& TComplex::operator/=(double n)
{
	assert(n != 0);
	if (n > 0)
	{
		this->r_ /= n;
	}
	else
	{
		this->r_ /= -n;
		this->phi_ -= std::numbers::pi;
	}
	normalize();
	return *this;
}
TComplex operator/(double n, const TComplex& tri)
{
	TComplex temp(n);
	temp /= tri;
	return temp;
}
TComplex operator/(const TComplex& tri, double n)
{
	TComplex temp(tri);
	temp /= n;
	return temp;
}
*/