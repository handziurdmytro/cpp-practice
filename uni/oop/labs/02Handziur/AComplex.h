// Developed by Handziur Dmytro on 21.02.2026
#pragma once
#include <iostream>

class TComplex;
class AComplex
{
private:
	/* z = re + i * im */
	double re_, im_;

	/*
		Invariants:

		1. re is finite
		2. im is finite
	*/
	void check() const;

public:
	AComplex(double re = 0.0, double im = 0.0);

	/*Rule of 5*/
	~AComplex();
	AComplex(const AComplex&);
	AComplex& operator=(const AComplex&) = delete;
	AComplex(AComplex&&) = default;
	AComplex& operator=(AComplex&&) = default;

	/* convertor */
	AComplex(const TComplex&);

	AComplex& operator+=(const AComplex&);
	AComplex& operator-=(const AComplex&);
	AComplex& operator*=(const AComplex&);
	AComplex& operator/=(const AComplex&);

	double re() const { return this->re_; }
	double im() const { return this->im_; }

	friend std::ostream& operator<<(std::ostream&, const AComplex&);
	
	/* is a boilerplate if double -> AComplex is implicit
	
	AComplex& operator+=(double);
	friend AComplex operator+(double, const AComplex&);
	friend AComplex operator+(const AComplex&, double);

	AComplex& operator-=(double);
	friend AComplex operator-(double, const AComplex&);
	friend AComplex operator-(const AComplex&, double);
	*/
};

AComplex operator+(const AComplex&, const AComplex&);
AComplex operator-(const AComplex&, const AComplex&);