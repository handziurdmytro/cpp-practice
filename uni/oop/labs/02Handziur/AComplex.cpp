// Developed by Handziur Dmytro on 21.02.2026
#include "AComplex.h"
#include "TComplex.h"
#include <iostream>
#include <cmath>
#include <cassert>

#define AC_DEBUG

/* 
	implicitly converts double -> AComplex; explicit keyword will 
	require a realization of lots of boilerplate functions (+-(AC/double, double/AC) 
*/
/*explicit*/ AComplex::AComplex(double re, double im) : re_(re), im_(im) 
{
	check();
#ifdef AC_DEBUG
	std::cout << "[CREATION] AComplex: " << *this << '\n';
#endif
};

/*
	a = r * cos(phi)
	b = r * sin(phi)
*/
AComplex::AComplex(const TComplex& tri) {
	double r = tri.r();
	double phi = tri.phi();
	this->re_ = r * std::cos(phi);
	this->im_ = r * std::sin(phi);
	check();
#ifdef AC_DEBUG
	std::cout << "[CONVERTION] TComplex " << tri << " -> AComplex " << *this << '\n';
#endif
}

AComplex::~AComplex()
{
#ifdef AC_DEBUG
	std::cout << "[DESTRUCTION] AComplex: " << *this << '\n';
#endif
}
AComplex::AComplex(const AComplex& alg): re_(alg.re_), im_(alg.im_)
{
#ifdef AC_DEBUG
	std::cout << "[COPY] AComplex: " << *this << '\n';
#endif
}

AComplex& AComplex::operator+=(const AComplex& alg)
{
	this->re_ += alg.re_;
	this->im_ += alg.im_;
	check();
	return *this;
}
AComplex& AComplex::operator-=(const AComplex& alg)
{
	this->re_ -= alg.re_;
	this->im_ -= alg.im_;
	check();
	return *this;
}

AComplex operator+(const AComplex& alg1, const AComplex& alg2)
{
	AComplex temp(alg1);
	temp += alg2;
	return temp;
}
AComplex operator-(const AComplex& alg1, const AComplex& alg2)
{
	AComplex temp(alg1);
	temp -= alg2;
	return temp;
}

AComplex& AComplex::operator*=(const AComplex& alg)
{
	*this = (*this) * alg;
	return *this;
}

AComplex& AComplex::operator/=(const AComplex& alg)
{
	*this = (*this) / alg;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AComplex& alg)
{
	return os << '(' << alg.re() << ", " << alg.im() << "i)";
}

void AComplex::check() const
{
	assert(std::isfinite(this->re_));
	assert(std::isfinite(this->im_));
}
/*
AComplex& AComplex::operator+=(double n)
{
	this->re_ += n;
	check();
	return *this;
}
AComplex& AComplex::operator-=(double n)
{
	this->re_ -= n;
	check();
	return *this;
}

AComplex operator+(double n, const AComplex& alg)
{
	AComplex temp(n);
	temp += alg;
	return temp;
}
AComplex operator+(const AComplex& alg, double n)
{
	AComplex temp(alg);
	temp += n;
	return temp;
}
AComplex operator-(double n, const AComplex& alg)
{
	AComplex temp(n);
	temp -= alg;
	return temp;
}
AComplex operator-(const AComplex& alg, double n)
{
	AComplex temp(alg);
	temp -= n;
	return temp;
}
*/