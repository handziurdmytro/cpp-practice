// Developed by Handziur Dmytro on 14.02.2026
#pragma once
#include <iostream>

class Point
{
private:
	double x_, y_;
	static int actual_counter, all_time_counter;
public:
	Point(double x = 0.0, double y = 0.0) noexcept;

	/* Rule of 3 */
	~Point() noexcept;
	Point(const Point&) noexcept;
	Point& operator=(const Point&) noexcept;
	
	static int get_actual_counter() noexcept;
	static int get_all_time_counter() noexcept;
	
	friend std::ostream& operator<<(std::ostream&, const Point&);
	
	double x() const noexcept { return this->x_; };
	double y() const noexcept { return this->y_; };
};