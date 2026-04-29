// Developed by Handziur Dmytro on 14.02.2026
#include "Point.h"

using namespace std;

/* Counters */
int Point::actual_counter = 0;
int Point::all_time_counter = 0;

/* Constructor */
Point::Point(double x, double y) noexcept:
	x_(x), y_(y)
{
	Point::actual_counter++;
	Point::all_time_counter++;
}

/* Rule of 3 */

/* Destructor */
Point::~Point() noexcept
{
	Point::actual_counter--;
}

/* Copy Constructor */
Point::Point(const Point& p) noexcept:
	x_(p.x_), y_(p.y_)
{
	Point::actual_counter++;
	Point::all_time_counter++;
}

/* Copy Operator */
Point& Point::operator=(const Point& p) noexcept
{
	if (this != &p)
	{
		this->x_ = p.x_;
		this->y_ = p.y_;
	}

	return *this;
}

int Point::get_actual_counter() noexcept { return Point::actual_counter; }
int Point::get_all_time_counter() noexcept { return Point::all_time_counter; }

ostream& operator<<(ostream& os, const Point& p)
{
	return os << '(' << p.x_ << ',' << p.y_ << ')';
}