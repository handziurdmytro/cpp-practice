// Developed by Handziur Dmytro on 19.04.2026
#pragma once
#include "IQueue.h"

template<typename T>
class BoundedArrayBased : public IQueue<T>
{
private:
	T* _data;
	size_t _size;
	size_t _capacity;
	size_t _start;
	size_t _end;

public:

	explicit BoundedArrayBased(size_t capacity) : _size(0),
		_capacity(capacity), _start(0), _end(0)
	{
		if (capacity == 0) 
			throw std::invalid_argument("capacity must be positive");
		_data = new T[_capacity];
	}

	~BoundedArrayBased() override
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
			throw std::out_of_range("queue is full");
		_data[_end] = value;
		++_size;
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