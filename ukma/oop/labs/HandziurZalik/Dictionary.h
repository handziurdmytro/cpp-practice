// Developed by Handziur Dmytro on 16.04.2026
#pragma once
#include "Array.h"
#include <ostream>

/*Task #1: Dictionary */
template <typename T>
class Dictionary 
{
private:
    Array<T> _array;

    size_t find_idx(const T& value, bool& found) const 
    {
        return binary_search(value, 0, _array.size(), found);
    }

    size_t binary_search(const T& value, size_t lo, size_t hi, bool& found) const 
    {
        if (lo >= hi) 
        {
            found = false;
            return lo;
        }

        size_t mid = lo + (hi - lo) / 2;
        if (_array[mid] == value) 
        {
            found = true;
            return mid;
        }
        else if (_array[mid] < value) 
        {
            return binary_search(value, mid + 1, hi, found);
        }
        else 
        {
            return binary_search(value, lo, mid, found);
        }
    }

public:
    /* Task #1.1: Ro5, Dictionary is just a wrapper over Array, which properly manages all its resources */
    Dictionary() = default;
    ~Dictionary() = default;
    Dictionary(const Dictionary&) = default;
    Dictionary& operator=(const Dictionary&) = default;
    Dictionary(Dictionary&&) = default;
    Dictionary& operator=(Dictionary&&) = default;

    /*Task #1.1: insert*/
    void insert(const T& value) 
    {
        bool found = false;
        size_t idx = find_idx(value, found);
        if (!found) {
            _array.insert(idx, value);
        }   
    }

    /*Task #1.1: remove*/
    void remove(const T& value) 
    {
        bool found = false;
        size_t idx = find_idx(value, found);
        if (found) {
            _array.remove(idx);
        }
    }

    /*Task #1.1: contain*/
    bool contain(const T& value) const 
    {
        bool found = false;
        find_idx(value, found);
        return found;
    }

    size_t size() const { return _array.size(); }
    void clear() { _array.clear(); }

    /* Task 2: nested Iterator class */
    class Iterator {
    private:
        const Array<T>* _arr_ptr;
        size_t _idx;
    public:
        Iterator(const Array<T>* arr, size_t idx) : _arr_ptr(arr), _idx(idx) {}

        /*Task #2.1: operator */
        const T& operator*() const 
        {
            return (*_arr_ptr)[_idx];
        }

        /*Task #2.1: operator++ */
        Iterator& operator++()
        {
            ++_idx;
            return *this;
        }

        /*Task #2.1: operator!= */
        bool operator!=(const Iterator& other) const
        {
            return _idx != other._idx || _arr_ptr != other._arr_ptr;
        }
    };

    /*Task #2.2: begin/end**/
    Iterator begin() const { return Iterator(&_array, 0); }
    Iterator end() const { return Iterator(&_array, _array.size()); }

    /*Task #2.3: operator== for Dictionary */
    bool operator==(const Dictionary& other) const 
    {
        if (size() != other.size()) return false;
        auto it1 = begin();
        auto it2 = other.begin();
        while (it1 != end() && it2 != other.end()) 
        {
            if (!(*it1 == *it2)) return false;
            ++it1; ++it2;
        }
        return true;
    }
};

/*Task #3: operator+ (union)*/
template <typename T>
Dictionary<T> operator+(const Dictionary<T>& d1, const Dictionary<T>& d2)
{
    Dictionary<T> result = d1;
    for (auto it = d2.begin(); it != d2.end(); ++it) 
    {
        result.insert(*it);
    }
    return result;
}

/*Task #3: operator* (intersection)*/
template <typename T>
Dictionary<T> operator*(const Dictionary<T>& d1, const Dictionary<T>& d2)
{
    Dictionary<T> result;
    for (auto it = d1.begin(); it != d1.end(); ++it) 
    {
        if (d2.contain(*it)) 
        {
            result.insert(*it);
        }
    }
    return result;
}

/*Task #4: copy */
template <typename T>
void copy(Dictionary<T>& to, const Dictionary<T>& from) 
{
    to = from;
}

/*Task #4: merge_into */
template <typename T>
void merge_into(Dictionary<T>& to, Dictionary<T>&& from) 
{
    for (auto it = from.begin(); it != from.end(); ++it) 
    {
        to.insert(*it);
    }
    from.clear();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Dictionary<T>& dict) 
{
    os << "Dictionary(" << dict.size() << ") { ";
    bool first = true;
    for (auto it = dict.begin(); it != dict.end(); ++it) 
    {
        if (!first) os << ", ";
        os << *it;
        first = false;
    }
    os << "}";
    return os;
}
