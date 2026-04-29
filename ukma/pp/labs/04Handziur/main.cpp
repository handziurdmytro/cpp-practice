#include <iostream>
#include "matrix.h"
#include "fibonacci.h"
#include <cassert>

using namespace std;

int main()
{
    const int size = 25;

    int fibs[size] = {
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
    55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
    6765, 10946, 17711, 28657, 46368
    };

    for (int i = 1; i <= size; i++)
    {
        int correct = fibs[i - 1];
        cout << "\n--------------------------\n\n";

        int steps = 0;
        assert(fibonacciElementIterative(i, steps) == correct);
        cout << "Iterative(" << i << ")\t\tresult: " << correct << "; steps: " << steps << ";\n";


        steps = 0;
        assert(fibonacciElementMatrix(i, steps) == correct);
        cout << "Matrix(" << i << ")\t\tresult: " << correct << "; steps: " << steps << ";\n";

        steps = 0;
        assert(fibonacciElementRecursive(i, steps) == correct);
        cout << "Recursive(" << i << ")\t\tresult: " << correct << "; steps: " << steps << ";\n";

        steps = 0;
        assert(fibonacciElementRecursiveFast(i, steps) == correct);
        cout << "RecursiveFast(" << i << ")\tresult: " << correct << "; steps: " << steps << ";\n";
    }

    cout << "\n\nTests are completed!\n";
}