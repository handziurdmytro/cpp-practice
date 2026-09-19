#include <iostream>
#include <cassert>
#include <cstdlib>
#include "main.h"

using complex = std::complex<double>;
namespace RodionSTD 
{
    void a()
    {
        std::cout << "Rodion\n";
    }
}
int main()
{
    RodionSTD::a();

    int rank = 3;
    ComplexMatrix C1 = allocComplexMatrix(rank);
    randomlyFillComplexMatrix(C1, rank);

    ComplexMatrix C2 = allocComplexMatrix(rank);
    randomlyFillComplexMatrix(C2, rank);

    ComplexMatrix C1copy = copyComplexMatrix(C1, rank);
    ComplexMatrix C2copy = copyComplexMatrix(C2, rank);

    ComplexMatrix res1 = multiplyComplexMatrix1(C1, C2, rank);
    ComplexMatrix res2 = multiplyComplexMatrix2(C1copy, C2copy, rank);

    std::cout << "\n---Matrix1:\n\n";
    printComplexMatrix(C1, rank);
    std::cout << "\n---Matrix2:\n\n";
    printComplexMatrix(C2, rank);
    std::cout << "\n---Matrix1 (copy):\n\n";
    printComplexMatrix(C1copy, rank);
    std::cout << "\n---Matrix2 (copy):\n\n";
    printComplexMatrix(C2copy, rank);
    std::cout << "\n---Res1:\n\n";
    printComplexMatrix(res1, rank);
    std::cout << "\n---Res2:\n\n";
    printComplexMatrix(res2, rank);
    std::cout << "\n---\n";

    deleteComplexMatrix(C1, rank);
    deleteComplexMatrix(C2, rank);
    deleteComplexMatrix(C1copy, rank);
    deleteComplexMatrix(C2copy, rank);
    deleteComplexMatrix(res1, rank);
    deleteComplexMatrix(res2, rank);


    /*splitComplexMatrix(C, real, imag, rank);
    printSquareMatrix(real, rank);
    std::cout << "-----------------\n";

    printSquareMatrix(imag, rank);
    std::cout << "-----------------\n";

    Matrix sum = addSquare(real, imag, rank);
    printSquareMatrix(sum, rank);
    std::cout << "-----------------\n";

    Matrix diff = subtractSquare(real, imag, rank);
    printSquareMatrix(diff, rank);
    std::cout << "-----------------\n";

    Matrix newMatrix = multiplySquareWithConstant(sum, rank, 5.0);
    printSquareMatrix(newMatrix, rank);
    std::cout << "-----------------\n";

    Matrix mult = multiplySquare(real, imag, rank);
    printSquareMatrix(mult, rank);
    std::cout << "-----------------\n";*/

}

void splitComplexMatrix(ComplexMatrix& A, Matrix& real, Matrix& imag, int rank)
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
Matrix multiplySquare(Matrix& A, Matrix& B, int rank)
{
    assert(rank >= 1);

    Matrix res = allocMatrix(rank);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < rank; k++)
            {
                double num1 = *(*(A + i) + k);
                double num2 = *(*(B + k) + j);
                sum += num1 * num2;
            }
            *(*(res + i) + j) = sum;
        }
    }

    return res;
};
Matrix multiplySquareWithConstant(Matrix& A, int rank, double c)
{
    assert(rank >= 1);

    Matrix res = allocMatrix(rank);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            double el = *(*(A + i) + j);
            *(*(res + i) + j) = el * c;
        }
    }

    return res;
};
Matrix subtractSquare(Matrix& A, Matrix& B, int rank)
{
    assert(rank >= 1);

    Matrix res = allocMatrix(rank);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            double num1 = *(*(A + i) + j);
            double num2 = *(*(B + i) + j);
            *(*(res + i) + j) = num1 - num2;
        }
    }

    return res;
};
Matrix addSquare(Matrix& A, Matrix& B, int rank)
{
    assert(rank >= 1);

    Matrix res = allocMatrix(rank);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            double num1 = *(*(A + i) + j);
            double num2 = *(*(B + i) + j);
            *(*(res + i) + j) = num1 + num2;
        }
    }

    return res;
};

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

ComplexMatrix allocComplexMatrix(int rank)
{
    ComplexMatrix C = new complex * [rank];

    for (int i = 0; i < rank; i++)
    {
        *(C + i) = new std::complex<double>[rank];
    }

    return C;
}

Matrix allocMatrix(int rank)
{
    Matrix A = new double* [rank];

    for (int i = 0; i < rank; i++)
    {
        *(A + i) = new double[rank];
    }

    return A;
}


void deleteMatrix(Matrix& A, int rank)
{
    for (int i = 0; i < rank; i++)
    {
        delete[] * (A + i);
    }
    delete[] A;
}
void deleteComplexMatrix(ComplexMatrix& C, int rank)
{
    for (int i = 0; i < rank; i++)
    {
        delete[] * (C + i);
    }
    delete[] C;
}

ComplexMatrix multiplyComplexMatrix1(ComplexMatrix& X, ComplexMatrix& Y, int rank)
{
    Matrix A = allocMatrix(rank); // real X
    Matrix B = allocMatrix(rank); // imag X
    Matrix C = allocMatrix(rank); // real Y
    Matrix D = allocMatrix(rank); // imag Y

    splitComplexMatrix(X, A, B, rank);
    splitComplexMatrix(Y, C, D, rank);

    /* Z = (AC-BD) + i(AD+BC) */
    Matrix AC = multiplySquare(A, C, rank);
    Matrix BD = multiplySquare(B, D, rank);
    Matrix AD = multiplySquare(A, D, rank);
    Matrix BC = multiplySquare(B, C, rank);

    Matrix realZ = subtractSquare(AC, BD, rank);
    Matrix imagZ = addSquare(AD, BC, rank);

    ComplexMatrix res = mergeComplexMatrix(realZ, imagZ, rank);

    deleteMatrix(A, rank);
    deleteMatrix(B, rank);
    deleteMatrix(C, rank);
    deleteMatrix(D, rank);
    deleteMatrix(AC, rank);
    deleteMatrix(BD, rank);
    deleteMatrix(AD, rank);
    deleteMatrix(BC, rank);
    deleteMatrix(realZ, rank);
    deleteMatrix(imagZ, rank);

    return res;
}
ComplexMatrix multiplyComplexMatrix2(ComplexMatrix& X, ComplexMatrix& Y, int rank)
{
    Matrix A = allocMatrix(rank); // real X
    Matrix B = allocMatrix(rank); // imag X
    Matrix C = allocMatrix(rank); // real Y
    Matrix D = allocMatrix(rank); // imag Y

    splitComplexMatrix(X, A, B, rank);
    splitComplexMatrix(Y, C, D, rank);

    /* T = (A+B)*(C-D); R = A*D; S= B*C */
    Matrix sumAB = addSquare(A, B, rank);
    Matrix diffCD = subtractSquare(C, D, rank);

    Matrix T = multiplySquare(sumAB, diffCD, rank);
    Matrix R = multiplySquare(A, D, rank);
    Matrix S = multiplySquare(B, C, rank);

    /* X = T + R – S; Y = A*D+B*C = R + S */
    Matrix sumTR = addSquare(T, R, rank);
    Matrix realZ = subtractSquare(sumTR, S, rank);
    Matrix imagZ = addSquare(R, S, rank);

    ComplexMatrix res = mergeComplexMatrix(realZ, imagZ, rank);

    deleteMatrix(A, rank);
    deleteMatrix(B, rank);
    deleteMatrix(C, rank);
    deleteMatrix(D, rank);
    deleteMatrix(T, rank);
    deleteMatrix(R, rank);
    deleteMatrix(S, rank);
    deleteMatrix(realZ, rank);
    deleteMatrix(imagZ, rank);
    deleteMatrix(sumTR, rank);
    deleteMatrix(diffCD, rank);
    deleteMatrix(sumAB, rank);

    return res;
}
void randomlyFillComplexMatrix(ComplexMatrix& C, int rank)
{
    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            complex c(rand() % 10, rand() % 10);
            *(*(C + i) + j) = c;
        }
    }
}

void printComplexMatrix(ComplexMatrix& C, int rank)
{
    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            std::complex<double> myComplex = *(*(C + i) + j);
            std::cout << "(" << myComplex.real() << ", " << myComplex.imag() << "i)\t";
        }
        std::cout << std::endl;
    }
}


ComplexMatrix copyComplexMatrix(ComplexMatrix& C, int rank)
{
    ComplexMatrix res = allocComplexMatrix(rank);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            *(*(res + i) + j) = *(*(C + i) + j);
        }
    }
    return res;
}

ComplexMatrix mergeComplexMatrix(Matrix& real, Matrix& imag, int rank)
{
    assert(rank >= 1);

    ComplexMatrix res = allocComplexMatrix(rank);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            double realPart = *(*(real + i) + j);
            double imagPart = *(*(imag + i) + j);

            std::complex<double> myComplex(realPart, imagPart);
            *(*(res + i) + j) = myComplex;
        }
    }

    return res;
}