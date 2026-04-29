// Developed by Handziur Dmytro on 14.02.2026
#pragma once
#include <iostream>
#include <memory>
#include "Point.h"

class Triangle
{
public:
	class Segment;
private:
	/* Points: composition */
	Point a_;
	Point b_;
	Point c_;
	
	/* Sides: aggregation */
	mutable std::unique_ptr<Segment> ab_;
	mutable std::unique_ptr<Segment> bc_;
	mutable std::unique_ptr<Segment> ca_;

	/* Medians: aggregation */
	mutable std::unique_ptr<Segment> median_from_a_to_bc_;
	mutable std::unique_ptr<Segment> median_from_b_to_ca_;
	mutable std::unique_ptr<Segment> median_from_c_to_ab_;

	static int actual_counter, all_time_counter;

	void update() const noexcept;
public:
	class Segment
	{
	private:
		/* Points: start & end - reference aggregation; middle - ptr aggregation */
		const Point& start_;
		mutable std::unique_ptr<Point> middle_;
		const Point& end_;

		static int actual_counter, all_time_counter;
	public:
		/* Constructor*/
		Segment(const Point&, const Point&) noexcept;

		/*Rule of 5*/
		~Segment() noexcept;
		Segment(const Segment&) = delete;
		Segment& operator=(const Segment&) = delete;
		Segment(Segment&&) = delete;
		Segment& operator=(Segment&&) = delete;

		static int get_actual_counter() noexcept;
		static int get_all_time_counter() noexcept;

		friend std::ostream& operator<<(std::ostream&, const Segment&);
		
		double length() const noexcept;
		const Point& middle() const noexcept;
	};
	/* Constructors */
	Triangle(const Point&, const Point&, const Point&) noexcept;
	Triangle(
		double x1 = 0.0, double y1 = 0.0,
		double x2 = 0.0, double y2 = 0.0,
		double x3 = 0.0, double y3 = 0.0
	) noexcept;

	/* Rule of 5 */
	~Triangle() noexcept;
	Triangle(const Triangle&) = delete;
	Triangle& operator=(const Triangle&) = delete;
	Triangle(Triangle&&) = delete;
	Triangle& operator=(Triangle&&) = delete;

	const Point& vertex_a() const noexcept;
	const Point& vertex_b() const noexcept;
	const Point& vertex_c() const noexcept;

	const Segment& side_AB() const noexcept;
	const Segment& side_BC() const noexcept;
	const Segment& side_CA() const noexcept;

	double length_AB() const noexcept;
	double length_BC() const noexcept;
	double length_CA() const noexcept;

	static int get_actual_counter() noexcept;
	static int get_all_time_counter() noexcept;

	friend std::ostream& operator<<(std::ostream&, const Triangle&);

	const Segment& median_from_A_to_BC() const noexcept;
	const Segment& median_from_B_to_CA() const noexcept;
	const Segment& median_from_C_to_AB() const noexcept;

	double median_from_A_to_BC_len() const noexcept;
	double median_from_B_to_CA_len() const noexcept;
	double median_from_C_to_AB_len() const noexcept;

	void set_a(const Point& a) noexcept;
	void set_b(const Point& b) noexcept;
	void set_c(const Point& c) noexcept;
};