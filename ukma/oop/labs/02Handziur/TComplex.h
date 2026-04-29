// Developed by Handziur Dmytro on 21.02.2026
#pragma once
#include <iostream>

class AComplex;
class TComplex
{
	
private:
	/* z = r * (cos(phi) + i * sin(phi)) */
	double r_, phi_;

	/*
		Invariants:

		1. r >= 0
		2. phi >= 0 && phi < 2PI
		3. only one zero value: <0, 0>
	*/
	void normalize();
	void normalize_r();
	void normalize_phi();

public:
	TComplex(double r = 0.0, double phi = 0.0);

	/*Rule of 5*/
	~TComplex();
	TComplex(const TComplex&);
	TComplex& operator=(const TComplex&) = delete;
	TComplex(TComplex&&) = default;
	TComplex& operator=(TComplex&&) = default;

	/* convertor */
	TComplex(const AComplex&);

	TComplex& operator+=(const TComplex&);
	TComplex& operator-=(const TComplex&);
	TComplex& operator*=(const TComplex&);
	TComplex& operator/=(const TComplex&);

	

	double r() const { return this->r_; }
	double phi() const { return this->phi_; }

	friend std::ostream& operator<<(std::ostream&, const TComplex&);
	
	/* is a boilerplate if double -> TComplex is implicit
	
	TComplex& operator*=(double);
	friend TComplex operator*(double, const TComplex&);
	friend TComplex operator*(const TComplex&, double);

	TComplex& operator/=(double);
	friend TComplex operator/(double, const TComplex&);
	friend TComplex operator/(const TComplex&, double);
	*/
};

TComplex operator*(const TComplex&, const TComplex&);
TComplex operator/(const TComplex&, const TComplex&);