// Developed by Handziur Dmytro on 16.04.2026
#pragma once
#include <iostream>
#include <utility>
#include <ostream>
#include <cassert>

template<typename T>
class Array 
{
private:
	T* _data;
	size_t _size;
	size_t _capacity;

	void resize(size_t new_cap)
	{
		T* new_data = new T[new_cap];
		for (size_t i = 0; i < _size; ++i)
		{
			new_data[i] = std::move(_data[i]);
		}
		delete[] _data;
		_data = new_data;
		_capacity = new_cap;
	}
public:
	/* Constructor with lazy init of _data*/
	Array() : _data(nullptr), _size(0), _capacity(0) {}

	/* Destructor */
	~Array() { delete[] _data; }

	/* Task #1.1: Copy c-tor */
	Array(const Array<T>& that) : _size(that._size), _capacity(that._capacity) 
	{
		_data = _capacity > 0 ? new T[_capacity] : nullptr;
		for (size_t i = 0; i < _size; ++i)
		{
			_data[i] = that._data[i];
		}
	}

	/* Task #1.1: Copy assignment*/
	Array& operator=(const Array& that) {
		if (this != &that) {
			T* new_data = that._capacity > 0 ? new T[that._capacity] : nullptr;
			for (size_t i = 0; i < that._size; ++i) {
				new_data[i] = that._data[i];
			}
			delete[] _data;
			_data = new_data;
			_size = that._size;
			_capacity = that._capacity;
		}
		return *this;
	}

	/* Task #1.1: Move c-tor */
	Array(Array&& that) noexcept : _data(that._data), _size(that._size), _capacity(that._capacity)
	{
		that._data = nullptr;
		that._size = 0;
		that._capacity = 0;
	}

	/* Task #1.1: Move assignment */
	Array& operator=(Array&& that) noexcept
	{
		if (this != &that)
		{
			delete[] _data;
			_data = that._data;
			_size = that._size;
			_capacity = that._capacity;
			that._data = nullptr;
			that._size = 0;
			that._capacity = 0;
		}
		return *this;
	}

	/* Task #1.1: insert */
	void insert(size_t idx, const T& value)
	{
		assert(idx <= _size);
		if (_size == _capacity)
		{
			resize(_capacity == 0 ? 1 : _capacity * 2);
		}

		for (size_t i = _size; i > idx; --i)
		{
			_data[i] = std::move(_data[i - 1]);
		}
		_data[idx] = value;
		++_size;
	}

	/* Task #1.1: remove */
	void remove(size_t idx)
	{
		assert(idx < _size);
		for (size_t i = idx; i < _size - 1; ++i)
		{
			_data[i] = std::move(_data[i + 1]);
		}
		--_size;
	}

	/*Task #1.1: contain */
	bool contain(const T& value) const
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_data[i] == value) return true;
		}
		return false;
	}

	void clear() noexcept 
	{
		_size = 0;
	}

	const T& operator[](size_t idx) const 
	{
		assert(idx < _size);
		return _data[idx]; 
	}
	T& operator[](size_t idx) 
	{
		assert(idx < _size);
		return _data[idx];
	}

	size_t size() const noexcept { return _size; }
	size_t capacity() const noexcept { return _capacity; }
	const T* data() const noexcept { return _data; }
};

/* no friend kw; incapsulation is not broken; selector used */
template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) 
{
	os << "Array(" << arr.size() << "/" << arr.capacity() << ") [";

	for (std::size_t i = 0; i < arr.size(); ++i) 
	{
		os << arr[i];
		if (i < arr.size() - 1) 
		{
			os << ", ";
		}
	}
	os << "]";
	return os;
}
