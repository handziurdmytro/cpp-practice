// Developed by Handziur Dmytro on 29.03.2026
#pragma once
#include <cstddef>

template<typename T>
class ForwardList {
private:
    struct Node {
        T     _value;
        Node* _next;
        Node(const T& v, Node* n) : _value(v), _next(n) {}
    };

public:
    ForwardList() : _head(nullptr), _size(0) {}

    ~ForwardList() {
        while (_head) {
            Node* tmp = _head->_next;
            delete _head;
            _head = tmp;
        }
    }

    ForwardList(const ForwardList&) = delete;
    ForwardList& operator=(const ForwardList&) = delete;

    // ---- State ----
    std::size_t size()  const { return _size; }
    bool        empty() const { return _head == nullptr; }

    // ---- Modification ----

    // Prepend element (O(1)).
    // Note: iteration order is reverse of insertion order.
    void push_front(const T& x) {
        _head = new Node(x, _head);
        ++_size;
    }

    // Remove first occurrence of x.
    // Returns true if found and removed.
    // Implement yourself.
    bool remove_first(const T& x)
    {
        Node* prev = nullptr;
        Node* cur = _head;

        while (cur != nullptr) 
        {
            if (cur->_value == x)
            {
                if (prev) 
                {
                    prev->_next = cur->_next;
                }
                else
                {
                    _head = cur->_next;
                }

                delete cur;
                _size--;
                return true;
            }

            prev = cur;
            cur = cur->_next;
        }

        return false;
    }

    // Check membership.
    // Implement yourself.
    bool contains(const T& x) const
    {
        Node* cur = _head;
        while (cur != nullptr)
        {
            if (cur->_value == x) return true;

            cur = cur->_next;
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const ForwardList<T>& list)
    {
        os << "[ ";
        Node* cur = list._head;
        while (cur != nullptr)
        {
            os << cur->_value << " ";
            cur = cur->_next;
        }
        os << "]";
        return os;
    }

    // ---- Iterator (forward only) ----
    struct Iterator {
        Node* _node;

        const T& operator*()  const { return _node->_value; }
        Iterator& operator++() { _node = _node->_next; return *this; }
        bool operator!=(const Iterator& o) const { return _node != o._node; }
    };

    Iterator begin() const { return { _head }; }
    Iterator end()   const { return { nullptr }; }

private:
    Node* _head;
    std::size_t _size;
};
