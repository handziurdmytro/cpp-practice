// Developed by Handziur Dmytro on 14.02.2026
#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include <memory>
#include <cmath>

/* Counters */
int Triangle::Segment::actual_counter = 0; 
int Triangle::Segment::all_time_counter = 0;

/* Constructor */
Triangle::Segment::Segment(const Point& start, const Point& end) noexcept:
	start_(start), middle_(nullptr), end_(end)
{
	Triangle::Segment::actual_counter++;
	Triangle::Segment::all_time_counter++;
}

/* Destructor */
Triangle::Segment::~Segment() noexcept
{
	Triangle::Segment::actual_counter--;
}

int Triangle::Segment::get_actual_counter() noexcept { return Triangle::Segment::actual_counter; }
int Triangle::Segment::get_all_time_counter() noexcept { return Triangle::Segment::all_time_counter; }

std::ostream& operator<<(std::ostream& os, const Triangle::Segment& s)
{
	return os << "Segment{" << s.start_ << ", " << s.end_ << "}";
}

double Triangle::Segment::length() const noexcept
{
	double diff_x = end_.x() - start_.x();
	double diff_y = end_.y() - start_.y();
	return std::sqrt(diff_x * diff_x + diff_y * diff_y);
}

const Point& Triangle::Segment::middle() const noexcept
{
	if (!this->middle_)
	{
		double mid_x = (this->end_.x() + this->start_.x()) / 2.0;
		double mid_y = (this->end_.y() + this->start_.y()) / 2.0;
		this->middle_ = std::make_unique<Point>(mid_x, mid_y);
	}

	return *(this->middle_);
}