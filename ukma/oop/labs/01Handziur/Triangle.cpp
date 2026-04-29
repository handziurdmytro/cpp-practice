//Developed by Handziur Dmytro on 15.02.2026
#include <iostream>
#include "Point.h"
#include <memory>
#include "Triangle.h"

/* Counters */
int Triangle::actual_counter = 0;
int Triangle::all_time_counter = 0;

/* Constructor #1 */
Triangle::Triangle(const Point& a, const Point& b, const Point& c) noexcept:
	a_(a), b_(b), c_(c), ab_(nullptr), bc_(nullptr), ca_(nullptr)
{
	Triangle::actual_counter++;
	Triangle::all_time_counter++;
}

/* Constructor #2 */
Triangle::Triangle(
	double x1, double y1,
	double x2, double y2,
	double x3, double y3
)  noexcept:
	a_(x1, y1), b_(x2, y2), c_(x3, y3), ab_(nullptr), bc_(nullptr), ca_(nullptr)
{
	Triangle::actual_counter++;
	Triangle::all_time_counter++;
}

/* Destructor */
Triangle::~Triangle() noexcept
{
	Triangle::actual_counter--;
}

const Point& Triangle::vertex_a() const noexcept
{
	return this->a_;
}
const Point& Triangle::vertex_b() const noexcept
{
	return this->b_;
}
const Point& Triangle::vertex_c() const noexcept
{
	return this->c_;
}

const Triangle::Segment& Triangle::side_AB() const noexcept
{
	if (!this->ab_) 
	{
		this->ab_ = std::make_unique<Segment>(this->a_, this->b_);
	}

	return *(this->ab_);
}
const Triangle::Segment& Triangle::side_BC() const noexcept
{
	if (!this->bc_)
	{
		this->bc_ = std::make_unique<Segment>(this->b_, this->c_);
	}

	return *(this->bc_);
}
const Triangle::Segment& Triangle::side_CA() const noexcept
{
	if (!this->ca_)
	{
		this->ca_ = std::make_unique<Segment>(this->c_, this->a_);
	}

	return *(this->ca_);
}

double Triangle::length_AB() const noexcept
{
	return side_AB().length();
}
double Triangle::length_BC() const noexcept
{
	return side_BC().length();
}
double Triangle::length_CA() const noexcept
{
	return side_CA().length();
}

int Triangle::get_actual_counter() noexcept { return Triangle::actual_counter; }
int Triangle::get_all_time_counter() noexcept { return Triangle::all_time_counter; }

std::ostream& operator<<(std::ostream& os, const Triangle& t)
{
	return os << "Triangle{" << t.a_ << ", " << t.b_ << ", " << t.c_ << "}";
}

const Triangle::Segment& Triangle::median_from_A_to_BC() const noexcept
{
	if (!this->median_from_a_to_bc_)
	{
		this->median_from_a_to_bc_ = std::make_unique<Segment>
			(
				this->a_,
				side_BC().middle()
			);
	}
	return *(this->median_from_a_to_bc_);
}

const Triangle::Segment& Triangle::median_from_B_to_CA() const noexcept
{
	if (!this->median_from_b_to_ca_)
	{
		this->median_from_b_to_ca_ = std::make_unique<Segment>
			(
				this->b_,
				side_CA().middle()
			);
	}
	return *(this->median_from_b_to_ca_);
}

const Triangle::Segment& Triangle::median_from_C_to_AB() const noexcept
{
	if (!this->median_from_c_to_ab_)
	{
		this->median_from_c_to_ab_ = std::make_unique<Segment>
			(
				this->c_,
				side_AB().middle()
			);
	}
	return *(this->median_from_c_to_ab_);
}

double Triangle::median_from_A_to_BC_len() const noexcept
{
	return median_from_A_to_BC().length();
}
double Triangle::median_from_B_to_CA_len() const noexcept
{
	return median_from_B_to_CA().length();
}
double Triangle::median_from_C_to_AB_len() const noexcept
{
	return median_from_C_to_AB().length();
}

void Triangle::update() const noexcept
{
	this->ab_.reset();
	this->bc_.reset();
	this->ca_.reset();
	this->median_from_a_to_bc_.reset();
	this->median_from_b_to_ca_.reset();
	this->median_from_c_to_ab_.reset();
}

void Triangle::set_a(const Point& a) noexcept { this->a_ = a; update(); }
void Triangle::set_b(const Point& b) noexcept { this->b_ = b; update(); }
void Triangle::set_c(const Point& c) noexcept { this->c_ = c; update(); }