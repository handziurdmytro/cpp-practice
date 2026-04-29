#include <iostream>
#include "tetranacci.h"
#include "rational.h"
#include "settings.h"
#include "cyclic_shift.h"
#include "dynamic_array.h"
#include "sort.h"
#include "param_matrix.h"
#include "integral.h"
#include "sparse_matrix.h"

using namespace::std;

int main()
{
    /*
        Handziur Dmytro, NaUKMA SWE-2

        Task #1..............settings.h
        Task #2..........cyclic_shift.h
        Task #3............tetranacci.h
        Task #4..............rational.h
        Task #5..............rational.h
        Task #6.........dynamic_array.h
        Task #7..................sort.h
        Task #8..........param_matrix.h
        Task #9..............integral.h
        Task #10........sparse_matrix.h
    */
    {
        /* TASK #1 (settings.h)*/
        cout << "\t** TASK #1 **\n\n";
        Settings s1 = { 2, 1, 0, 3 };
        assert(sizeof(s1) == 1);

        cout << "10(01)0011 = 2 (1) 0 3\n";
        cout << "before invert: " << (s1._color & 0xFF) << endl;
        invert_second_field(s1);
        cout << "10(10)0011 = 2 (2) 0 3\n";
        cout << "after invert: " << (s1._color & 0xFF) << endl;
        invert_second_field(s1);
        cout << "10(01)0011 = 2 (1) 0 3\n";
        cout << "after reinvert: " << (s1._color & 0xFF) << endl;

        cout << endl;
        Settings s2 = { 1, 0, 1, 1 };
        assert(sizeof(s2) == 1);

        cout << "11(00)1111 = 1 (0) 1 1\n";
        cout << "before invert: " << (s2._color & 0xFF) << endl;
        invert_second_field(s2);
        cout << "11(11)1111 = 1 (3) 1 1\n";
        cout << "after invert: " << (s2._color & 0xFF) << endl;
        invert_second_field(s2);
        cout << "11(00)1111 = 1 (0) 1 1\n";
        cout << "after reinvert: " << (s2._color & 0xFF) << endl;
    }

    {
        /* TASK #2 (cyclic_shift.h)*/
        cout << "\n----\n\t** TASK #2 **\n\n";

        int arr1[] = { 3, 5, 1, 8, 9 };
        int size1 = 5;
        int shift1 = 3;
        cout << "Shift: " << shift1 << endl;
        print_array(arr1, size1);
        cyclic_shift_optimized(arr1, size1, shift1);
        print_array(arr1, size1);

        long long int arr2[] = { 9LL, 17LL, 8LL, 3LL, 11LL, 4LL, 20LL, 16LL, 2LL, 37LL };
        int size2 = 10;
        int shift2 = -5;
        cout << "Shift: " << shift2 << endl;
        print_array(arr2, size2);
        cyclic_shift_optimized(arr2, size2, shift2);
        print_array(arr2, size2);
    }

    {
        /*TASK #3 (tetranacci.h) */
        cout << "\n----\n\t** TASK #3 **\n\n";
        std::cout << "Tetranacci sequence:\n";
        for (int i = 0; i < 30; i++)
        {
            std::cout << i <<"\t=>\t" << get_tetranacci_n(i) << std::endl;
        }
    }

    {
        /*TASK #4 (rational.h)*/
        cout << "\n----\n\t** TASK #4 **\n\n";
        Rational r1 = create(10, 4);
        cout << "r1: " << r1 << endl;
        Rational r2 = create(3, 5);
        cout << "r2: " << r2 << endl;


        Rational sum = r1 + r2;
        Rational mul = r1 * r2;

        std::cout << "SUM r1 + r2 = " << sum._numerator << "/" << sum._denominator << std::endl;
        std::cout << "MUL r1 * r2 = " << mul._numerator << "/" << mul._denominator << std::endl;

        int int1 = 3;
        Rational sum2 = r1 + int1;
        //assert(r1 + int1 == int1 + r1);

        long long int2 = 20LL;
        Rational mul2 = int2 * r2;
        //assert(r2 * int2 == int2 * r2);

        std::cout << "SUM r1 + " << int1 << "(int) = " << sum2._numerator << "/" << sum2._denominator << std::endl;
        std::cout << "MUL " << int2 << "(long long) * r2 = " << mul2._numerator << "/" << mul2._denominator << std::endl;
    }

    {
        /*TASK #5 (rational.h)*/
        cout << "\n----\n\t** TASK #5 **\n\n";
        Rational r1 = create(10, 4);
        cout << "r1: " << r1 << endl;
        Rational r2 = create(3, 5);
        cout << "r2: " << r2 << endl;

        assert(!(r1 == r2));
        assert(r1 != r2);
        assert(r1 > r2);
        assert(!(r1 < r2));
        assert(r1 >= r2);
        assert(!(r1 <= r2));
        std::cout << r1 << " == " << r2 << "? => " << boolalpha << (r1 == r2) << endl;
        std::cout << r1 << " != " << r2 << "? => " << boolalpha << (r1 != r2) << endl;
        std::cout << r1 << " > " << r2 << "? => " << boolalpha << (r1 > r2) << endl;
        std::cout << r1 << " < " << r2 << "? => " << boolalpha << (r1 < r2) << endl;
        std::cout << r1 << " >= " << r2 << "? => " << boolalpha << (r1 >= r2) << endl;
        std::cout << r1 << " <= " << r2 << "? => " << boolalpha << (r1 <= r2) << endl;
    }

    {
        /* TASK #6 (dynamic_array.h) */
        cout << "\n----\n\t** TASK #6 **\n\n";

        size_t size1 = 7;
        int arr1[] = { 3, 5, 2, 67, 33, 9, 18 };
        DynamicArray<int> da1;
        da1._data = new int[size1];
        da1._size = size1;

        for (size_t i = 0; i < size1; i++)
        {
            *(da1._data + i) = *(arr1 + i);
        }

        size_t size2 = 7;
        int arr2[] = { 4, 0, 9, 2, 13, 3, 10 };
        DynamicArray<int> da2;
        da2._data = new int[size2];
        da2._size = size2;

        for (size_t i = 0; i < size2; i++)
        {
            *(da2._data + i) = *(arr2 + i);
        }

        size_t size3 = 7;
        int arr3[] = { 1, 1, 1, 1, 1, 1, 1 };
        DynamicArray<int> da3;
        da3._data = new int[size3];
        da3._size = size3;

        for (size_t i = 0; i < size3; i++)
        {
            *(da3._data + i) = *(arr3 + i);
        }

        DynamicArray<int> da1_copy = deep_copy(da1);

        cout << "DA1: \n";
        print_dynamic_array(da1);
        cout << "DA2: \n";
        print_dynamic_array(da2);
        cout << "DA3: \n";
        print_dynamic_array(da3);

        cout << "DA1 deep copy: \n";
        print_dynamic_array(da1_copy);

        cout << "replace DA3 with copy of DA2: \n";
        cout << "DA3 before: ";
        print_dynamic_array(da3);

        replace(da2, da3);
        
        cout << "DA3 after: ";
        print_dynamic_array(da3);

        delete_array(da1);
        delete_array(da2);
        delete_array(da3);
        delete_array(da1_copy);
    }

    {
        /* TASK #7 (sort.h) */
        cout << "\n----\n\t** TASK #7 **\n\n";

        int arr1[] = { 3, 5, -1, -8, 9, 2, -6};
        size_t size1 = 7;
        cout << "Original #1:\n";
        print_typed_array(arr1, size1);
        
        sort(arr1, size1, Compare::natural<int>);
        cout << "Sorted in natural order #1:\n";
        print_typed_array(arr1, size1);
        
        sort(arr1, size1, Compare::by_abs_value<int>);
        cout << "Sorted by module #1:\n";
        print_typed_array(arr1, size1);

        sort(arr1, size1, Compare::reversed<int>);
        cout << "Sorted in reversed order #1:\n";
        print_typed_array(arr1, size1);



        double arr2[] = { -4.4, 1.2, 1.9, -11.0, -47.67, 22.3, 0.34, 5.2 };
        size_t size2 = 8;
        cout << "\nOriginal #2:\n";
        print_typed_array(arr2, size2);

        sort(arr2, size2, Compare::natural<double>);
        cout << "Sorted in natural order #2:\n";
        print_typed_array(arr2, size2);

        sort(arr2, size2, Compare::by_abs_value<double>);
        cout << "Sorted by module #2:\n";
        print_typed_array(arr2, size2);

        sort(arr2, size2, Compare::reversed<double>);
        cout << "Sorted in reversed order #2:\n";
        print_typed_array(arr2, size2);
    }

    {
        /*TASK #8 (param_matrix.h)*/
        cout << "\n----\n\t** TASK #8 **\n\n";

        Rational r1 = create(-1, 1);
        Rational r2 = create(3, 1);
        Rational r3 = create(0, 1);
        Rational r4 = create(4, 1);

        Matrix2x2<Rational> M1 =
        {
            r1, r2,
            r3, r4
        };

        cout << "Original(Rat):\n";
        print(M1);

        int pow1 = 3;
        Matrix2x2<Rational> M1_power3 = power(M1, pow1);

        cout << "To power of 3:\n";
        print(M1_power3);

        Matrix2x2<int> M2 =
        {
            -4, 3,
            -1, 1
        };

        cout << "Original(Int):\n";
        print(M2);

        int pow2 = 4;
        Matrix2x2<int> M2_power4 = power(M2, pow2);

        cout << "To power of 4:\n";
        print(M2_power4);
    }

    {
        /*TASK #9 (integral.h)*/
        cout << "\n----\n\t** TASK #9 **\n\n";

        const double eps = 1e-6;

        double a1 = 0.0, b1 = 10.0;
        double area1 = integrate_trapezoidal(a1, b1, eps, Functions::add5);
        cout << "f(x) = x + 5; a = 0.0, b = 10.0; integral = " << area1 << endl;

        double a2 = 3.0, b2 = 15.0;
        double area2 = integrate_trapezoidal(a2, b2, eps, Functions::mul2);
        cout << "f(x) = x * 2; a = 3.0, b = 15.0; integral = " << area2 << endl;

        double a3 = -2.5, b3 = 2.5;
        double area3 = integrate_trapezoidal(a3, b3, eps, Functions::pow_2);
        cout << "f(x) = x * x; a = -2.5, b = 2.5; integral = " << area3 << endl;
    }

    {
        /*TASK #10 (sparse_matrix.h)*/
        cout << "\n----\n\t** TASK #10 **\n\n";

        COO<int> coo_list[] = {
            { 0, 0, 1 },
            { 1, 1, 2 },
            { 0, 2, 3 },
            { 2, 2, 4 },
        };
        cout << "Sparse matrix #1 triplets: \n";
        cout << "{  row, col, val }\n";
        size_t list_size = 4;
        for (size_t i = 0; i < list_size; i++)
        {
            COO<int> coo = coo_list[i];
            cout << "{  " << coo._row << ",   " << coo._col << ",   " << coo._value << "   }\n";
        }
        size_t rank = 3;

        SparseMatrix<int> sp1 =
        {
            rank,
            coo_list,
            list_size,
        };

        DenseMatrix<int> d1 = to_dense(sp1);
        cout << "Dense Matrix #1\n";
        for (size_t i = 0; i < d1._rank; i++)
        {
            for (size_t j = 0; j < d1._rank; j++)
            {
                cout << d1._grid[i][j] << " ";
            }
            cout << endl;
        }

        size_t v1_size = 3;
        int v1_vals[] = { 2, -1, 1 };
        Vector<int> v1 =
        {
            v1_size,
            v1_vals,
        };

        cout << "Vector #1:\n";
        for (size_t i = 0; i < v1_size; i++)
        {
            cout << "(" << v1_vals[i] << ")\n";
        }

        cout << "Multiplication of Sparse M. and Vector #1:\n";
        Vector<int> mul = sp1 * v1;
        for (size_t i = 0; i < mul._size; i++)
        {
            cout << "(" << mul._values[i] << ")\n";
        }

        /* free memory */
        delete[] mul._values;

        for (size_t i = 0; i < d1._rank; i++) {
            delete[] d1._grid[i];
        }
        delete[] d1._grid;
    }
}