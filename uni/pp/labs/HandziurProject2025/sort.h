/*Handziur Dmytro, NaUKMA SWE - 2*/
#pragma once
#include <cassert>
#include <cmath>

/* parameterized selection sort; passing comparing function as parameter */
template<typename T, typename Comp> 
void sort(T* arr, size_t n, Comp compare)
{
	assert(arr != nullptr);
	assert(n > 0);
	/* restriction: function can receive only fun ptr */
	assert(compare != nullptr);

	for (int i = 0; i < n; i++)
	{
		size_t min = i;
		for (size_t j = i + 1; j < n; j++)
		{
			/* changing sequence depending on comparator result */
			if (compare(arr[j], arr[min]) < 0)
				min = j;
		}

		T temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

namespace Compare 
{
	/* natural comparator */
	// if	a == b return 0, 
	//		a > b  ret 1, 
	//		a < b  ret -1 
	template<typename T>
	int natural(T a, T b)
	{
		if (a == b)
			return 0;
		return a > b ? 1 : -1;
	}

	/* comparing by absolute value */
	template<typename T>
	int by_abs_value(T a, T b)
	{
		if (std::abs(a) == std::abs(b))
			return 0;
		return std::abs(a) > std::abs(b) ? 1 : -1;
	}

	/* reversed comparator */
	template<typename T>
	int reversed(T a, T b)
	{
		if (a == b)
			return 0;
		return a > b ? -1 : 1;
	}
}

/* print parameterized array */
template<typename T>
void print_typed_array(T* arr, size_t n)
{
	std::cout << "[ ";
	for (int i = 0; i < n; i++)
	{
		std::cout << *(arr + i) << " ";
	}
	std::cout << "];\n";
}