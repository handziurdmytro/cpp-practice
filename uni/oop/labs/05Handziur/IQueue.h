// Developed by Handziur Dmytro on 19.04.2026
#pragma once
#include <cassert>
#include <stdexcept>
#include <cstddef>
#include <ostream>

template<typename T>
class IQueue
{
public:
	IQueue() = default;
	virtual ~IQueue() = default;

	/* forbid copying of abstract class instances to prevent Object Slicing*/
	IQueue(const IQueue&) = delete;
	IQueue& operator=(const IQueue&) = delete;

	virtual bool empty() const = 0;
	virtual const T& front() const = 0;
	virtual void pop() = 0;
	virtual void put(const T& value) = 0;
	virtual size_t size() const = 0;

	/* bonus: peek element*/
	virtual const T& peek(size_t idx) const = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const IQueue<T>& queue)
{
	os << "Queue(" << queue.size() << ") [";
	for (size_t i = 0; i < queue.size(); ++i)
	{
		os << queue.peek(i);
		if (i < queue.size() - 1)
		{
			os << ", ";
		}
	}
	os << "]";
	return os;
}