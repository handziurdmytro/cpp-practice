/*Handziur Dmytro, NaUKMA SWE - 2*/
#pragma once
#include <iostream>
#include <concepts>
#include <cassert>
#include <cmath>

template<std::integral T>
void reverse(T* first, size_t n)
{
	if (n <= 1) return;

	T* last = (first + n) - 1;

	// swapping elements
	while (first < last)
	{
		T temp = *first;
		*first = *last;
		*last = temp;

		// moving ptrs
		first++;
		last--;
	}
}


/* only integer types restriction */
template<std::integral T>

/*optimized function without memory allocation*/
void cyclic_shift_optimized(T* arr, size_t n, int k)
{
	if (k == 0) return;
	assert(n > 0);

	/* normalize positive and negative shifts */
	k = (k > 0) ? k % (int)n : (abs(k) % (int)n) * -1;
	int shift = (k > 0) ? k : (int)n + k;

	/* reverse all array*/
	reverse(arr, n);
	/*reverse array before shift*/
	reverse(arr, shift);
	/*reverse array after shift*/
	reverse(arr + shift, n - shift);
}

/*prints parameterized array*/
template<std::integral T>
void print_array(T* arr, size_t n)
{
	std::cout << "[ ";
	for (int i = 0; i < n; i++)
	{
		std::cout << *(arr + i) << " ";
	}
	std::cout << "];\n";
}