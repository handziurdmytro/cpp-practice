#pragma once
#include <complex>  

typedef double** Matrix;
typedef std::complex<double>** ComplexMatrix;

void splitSquareMatrix(ComplexMatrix& A, Matrix& real, Matrix& imag, int rank);
Matrix multiplySquare(Matrix& A, Matrix& B, int rank);
Matrix multiplySquareWithConstant(Matrix& A, int rank, double c);
Matrix subtractSquare(Matrix& A, Matrix& B, int rank);
Matrix addSquare(Matrix& A, Matrix& B, int rank);
void printSquareMatrix(Matrix& A, int rank);