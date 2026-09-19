// Developed by Handziur Dmytro on 29.03.2026
#pragma once
#include "Array.h"
#include "ForwardList.h"

template<typename T, template<typename> class Storage = Array>
class Sequence {
private:
    Storage<T> _storage;

    void _push(Array<T>& storage, const T& x)
    {
        storage.push_back(x);
    }

    void _push(ForwardList<T>& storage, const T& x)
    {
        storage.push_front(x);
    }

public:
    void append(const T& x)
    {
        _push(this->_storage, x);
    }
    
    void remove(const T& x)
    {
        this->_storage.remove_first(x);
    }

    bool contains(const T& x) const
    {
        return this->_storage.contains(x);
    }

    std::size_t size() const
    {
        return this->_storage.size();
    }

    bool empty() const
    {
        return this->_storage.empty();
    }

    friend std::ostream& operator<<(std::ostream& os, const Sequence<T, Storage>& seq)
    {
        os << seq._storage;
        return os;
    }
};