#pragma once
#include <complex>  

typedef double** Matrix;
typedef double** Matrix;

typedef std::complex<double>** ComplexMatrix;

void splitComplexMatrix(ComplexMatrix& A, Matrix& real, Matrix& imag, int rank);
ComplexMatrix mergeComplexMatrix(Matrix& real, Matrix& imag, int rank);
Matrix multiplySquare(Matrix& A, Matrix& B, int rank);
Matrix multiplySquareWithConstant(Matrix& A, int rank, double c);
Matrix subtractSquare(Matrix& A, Matrix& B, int rank);
Matrix addSquare(Matrix& A, Matrix& B, int rank);
void printSquareMatrix(Matrix& A, int rank);
void printComplexMatrix(ComplexMatrix& A, int rank);
Matrix allocMatrix(int rank);
ComplexMatrix allocComplexMatrix(int rank);
void deleteMatrix(Matrix& A, int rank);
void deleteComplexMatrix(ComplexMatrix& C, int rank);
ComplexMatrix multiplyComplexMatrix1(ComplexMatrix& X, ComplexMatrix& Y, int rank);
ComplexMatrix multiplyComplexMatrix2(ComplexMatrix& X, ComplexMatrix& Y, int rank);
void randomlyFillComplexMatrix(ComplexMatrix& C, int rank);
ComplexMatrix copyComplexMatrix(ComplexMatrix& C, int rank);