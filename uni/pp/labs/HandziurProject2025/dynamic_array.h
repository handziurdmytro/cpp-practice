/*Handziur Dmytro, NaUKMA SWE - 2*/
#pragma once
#include <cassert>
#include <iostream>

template<typename T>
struct DynamicArray
{
	T* _data;
	size_t _size;
};

template<typename T>
DynamicArray<T> deep_copy(const DynamicArray<T>& arr)
{
	DynamicArray<T> result;

	size_t size = arr._size;
	assert(size > 0);
	T* array = new T[size];
	
	// manual iterative copy from old arr to new
	for (size_t i = 0; i < size; i++)
	{
		*(array + i) = *(arr._data + i);
	}

	// copying private fields 
	result._data = array;
	result._size = size;

	return result;
}

template<typename T>
void delete_array(DynamicArray<T>& arr)
{
	assert(arr._data != nullptr);
	/* free array memory*/
	delete[] arr._data;
	/* assigning nullptr to dangling ptr */
	arr._data = nullptr;
	/* reduring size to 0 */
	arr._size = 0;
}

template<typename T>
void replace(const DynamicArray<T>& arr_from, DynamicArray<T>& arr_to)
{
	assert(arr_from._data != nullptr);
	assert(arr_from._data != arr_to._data);

	/*cleaning destination array*/
	delete_array(arr_to);
	size_t size = arr_from._size;
	arr_to._size = size;
	arr_to._data = new T[size];

	// manual array copy
	for (size_t i = 0; i < size; i++)
	{
		*(arr_to._data+ i) = *(arr_from._data + i);
	}
}

/* print of parameterized array */
template<typename T>
void print_dynamic_array(const DynamicArray<T>& da)
{
	assert(da._data != nullptr);

	std::cout << "[ ";
	for (size_t i = 0; i < da._size; i++)
	{
		std::cout << *(da._data + i) << " ";
	}
	std::cout << "]\n";
}
