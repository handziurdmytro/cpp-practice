// Developed by Handziur Dmytro on 19.04.2026
#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include "IQueue.h"
#include "BoundedArrayBased.h"
#include "UnboundedArrayBased.h"
#include "ListBased.h"

using std::cout;

void test_queue(IQueue<int>& q, const std::string& name, const std::string& sep)
{
    cout << sep << "\t** " << name << " **" << sep;

    assert(q.empty());
    q.put(43);
    q.put(17);
    q.put(51);

    assert(q.size() == 3);
    assert(q.front() == 43);

    assert(q.peek(0) == 43);
    assert(q.peek(1) == 17);
    assert(q.peek(2) == 51);

    cout << "[INFO] queue: " << q << '\n';

    bool caught = false;
    try { q.peek(99); }
    catch (const std::out_of_range&) { caught = true; }
    assert(caught);

    q.pop();
    assert(q.front() == 17);
    assert(q.size() == 2);

    q.put(40);
    q.put(50);

    cout << "[INFO] FIFO test: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n[INFO] success\n";

    caught = false;
    try { q.front(); }
    catch (const std::out_of_range&) { caught = true; }
    assert(caught);

    caught = false;
    try { q.pop(); }
    catch (const std::out_of_range&) { caught = true; }
    assert(caught);

    caught = false;
    try { q.peek(0); }
    catch (const std::out_of_range&) { caught = true; }
    assert(caught);

    cout << "[INFO] underflow and out of bounds exceptions caught successfully\n";
}

int main()
{
    bool test_bounded_queue = true;
    bool test_unbounded_queue = true;
    bool test_list_queue = true;
    bool test_exceptions = true;

    std::string sep = "\n-----------------------------------\n";

    if (test_bounded_queue)
    {
        BoundedArrayBased<int> bounded_queue(5);
        test_queue(bounded_queue, "BOUNDED ARRAY-BASED QUEUE", sep);
    }

    if (test_unbounded_queue)
    {
        UnboundedArrayBased<int> unbounded_queue(2);
        test_queue(unbounded_queue, "UNBOUNDED ARRAY-BASED QUEUE (resize)", sep);
    }

    if (test_list_queue)
    {
        ListBased<int> list_queue;
        test_queue(list_queue, "LIST-BASED QUEUE", sep);
    }

    if (test_exceptions)
    {
        cout << sep << "\t** ADDITIONAL EXCEPTION TESTING **" << sep;

        BoundedArrayBased<int> queue(2);
        queue.put(1);
        queue.put(2);

        bool caught = false;
        try
        {
            queue.put(3);
        }
        catch (const std::out_of_range& e)
        {
            caught = true;
            cout << "[INFO] caught expected exception (overflow in bounded queue): " << e.what() << '\n';
        }
        assert(caught);
        cout << "[INFO] specific bounds checked successfully\n" << sep;
    }

    return 0;
}