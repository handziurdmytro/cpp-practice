// Developed by Handziur Dmytro on 19.04.2026
#pragma once
#include "IQueue.h"
#include <utility>

template<typename T>
class UnboundedArrayBased : public IQueue<T>
{
private:
	T* _data;
	size_t _size;
	size_t _capacity;
	size_t _start;
	size_t _end;

	void resize(size_t new_cap)
	{
		T* new_data = new T[new_cap];
		for (size_t i = 0; i < _size; ++i)
		{
			new_data[i] = std::move(_data[(i + _start) % _capacity]);
		}
		delete[] _data;
		_data = new_data;
		_capacity = new_cap;
		_start = 0;
		_end = _size;
	}

public:

	explicit UnboundedArrayBased(size_t capacity = 8) : _size(0),
		_capacity(capacity), _start(0), _end(0)
	{
		if (capacity == 0)
			throw std::invalid_argument("capacity must be positive");
		_data = new T[_capacity];
	}

	~UnboundedArrayBased() override
	{
		delete[] _data;
	}


	bool empty() const override { return _size == 0; }
	size_t size() const override { return _size; }

	const T& front() const override
	{
		if (empty())
			throw std::out_of_range("queue is empty");
		return _data[_start];
	}

	void pop() override
	{
		if (empty())
			throw std::out_of_range("queue is empty");
		--_size;
		_start = (_start + 1) % _capacity;
	}

	void put(const T& value) override
	{
		if (_size == _capacity)
			resize(_capacity == 0 ? 1 : _capacity * 2);
		++_size;
		_data[_end] = value;
		_end = (_end + 1) % _capacity;
	}

	const T& peek(size_t idx) const override
	{
		if (idx >= _size)
			throw std::out_of_range("index is out of queue bounds");
		size_t correct_idx = (_start + idx) % _capacity;
		return _data[correct_idx];
	}
};