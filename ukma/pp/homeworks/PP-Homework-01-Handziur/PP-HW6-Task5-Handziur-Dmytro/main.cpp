#include <iostream>
#include <cassert>
#include "main.h"


using complex = std::complex<double>;

int main()
{
    int rank = 3;
    ComplexMatrix C = new std::complex<double>*[rank];

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            complex c(10.0, 2.0);
            *(*(C + i) + j) = c;
        }
    }

    Matrix real = new double* [rank];
    Matrix imag = new double* [rank];

    splitSquareMatrix(C, real, imag, rank);
    printSquareMatrix(real, rank);
    printSquareMatrix(imag, rank);
}

void splitSquareMatrix(ComplexMatrix& A, Matrix& real, Matrix& imag, int rank)
{
    assert(rank >= 1);


    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            std::complex<double> complex = *(*(A + i) + j);

            *(*(real + i) + j) = std::real(complex);
            *(*(imag + i) + j) = std::imag(complex);
        }
    }
};
//Matrix multiplySquare(Matrix& A, Matrix& B, int rank)
//{
//    assert(rank >= 1);
//
//    Matrix res = Matrix();
//
//    double sum = 0.0;
//
//    for (int i = 0; i < rank; i++)
//    {
//        for (int j = 0; j < rank; j++)
//        {
//            double num1 = *(*(A + i) + j);
//            double num2 = *(*(B + j) + i);
//            *(*(res + i) + j) = num1 - num2;
//        }
//    }
//
//    return res;
//};
//Matrix multiplySquareWithConstant(Matrix& A, int rank, double c) 
//{
//    assert(rank >= 1);
//
//    int rank = rank * rank;
//
//    for (int i = 0; i < rank; i++)
//    {
//        for (int j = 0; j < rank; j++)
//        {
//            *(*(A + i) + j) *= c;
//        }
//    }
//
//    return A;
//};
//Matrix subtractSquare(Matrix& A, Matrix& B, int rank)
//{
//    assert(rank >= 1);
//
//    Matrix res = Matrix();
//
//    int iterations = rank * rank;
//    double sum = 0.0;
//
//    for (int i = 0; i < rank; i++)
//    {
//        for (int j = 0; j < rank; j++)
//        {
//            double num1 = *(*(A + i) + j);
//            double num2 = *(*(B + i) + j);
//            *(*(res + i) + j) = num1 - num2;
//        }
//    }
//
//    return res;
//};
//Matrix addSquare(Matrix& A, Matrix& B, int rank)
//{
//    assert(rank >= 1);
//
//    double sum = 0.0;
//
//    for (int i = 0; i < rank; i++)
//    {
//        for (int j = 0; j < rank; j++)
//        {
//            double num1 = *(*(A + i) + j);
//            double num2 = *(*(B + i) + j);
//            *(*(res + i) + j) = num1 + num2;
//        }
//    }
//
//    return res;
//};

void printSquareMatrix(Matrix& A, int rank)
{
    assert(rank >= 1);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            std::cout << *(*(A + i) + j) << "\t";
        }
        std::cout << std::endl;
    }
}