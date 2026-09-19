// Developed by Handziur Dmytro on 19.04.2026
#pragma once
#include "IQueue.h"

template <typename T>
class ListBased : public IQueue<T> 
{
private:
    struct Node {
        T _value;
        Node* _next;
        Node(const T& value) : _value(value), _next(nullptr) {}
    };

    Node* _start;
    Node* _end;
    size_t _size;

public:
    ListBased() : _start(nullptr), _end(nullptr), _size(0) {}

    ~ListBased() override 
    {
        while (_start != nullptr) {
            Node* temp = _start;
            _start = _start->_next;
            delete temp;
        }
    }

    bool empty() const override { return _size == 0; }
    size_t size() const override { return _size; }

    const T& front() const override 
    {
        if (empty()) 
            throw std::out_of_range("queue is empty");
        return _start->_value;
    }

    void put(const T& value) override 
    {
        Node* new_node = new Node(value);
        if (empty()) 
        {
            _end = new_node;
            _start = _end;
        }
        else 
        {
            _end->_next = new_node;
            _end = new_node;
        }
        ++_size;
    }

    void pop() override 
    {
        if (empty()) 
            throw std::out_of_range("queue is empty");
        Node* temp = _start;
        _start = _start->_next;
        delete temp;
        --_size;
        if (_start == nullptr) _end = nullptr;
    }

    const T& peek(size_t idx) const override 
    {
        if (idx >= _size)
            throw std::out_of_range("index is out of queue bounds");
        Node* current = _start;
        for (size_t i = 0; i < idx; ++i) 
        {
            current = current->_next;
        }
        return current->_value;
    }
};