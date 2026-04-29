/*Handziur Dmytro, NaUKMA SWE-2*/
#pragma once
#include <cassert>
#include "tetranacci.h"

/* TASK #3 */
struct Matrix4x4
{
	static const int rank = 4;
	long long int** grid;
};

/*create empty matrix*/
Matrix4x4 create()
{
	Matrix4x4 A;
	int rank = Matrix4x4::rank;

	// alloc
	A.grid = new long long* [rank];

	// init
	for (int i = 0; i < rank; i++)
	{
		A.grid[i] = new long long[rank];
		for (int j = 0; j < rank; j++)
		{
			A.grid[i][j] = 0;
		}
	}
	return A;
}

//free memory
void delete_matrix(Matrix4x4& A)
{
	assert(A.grid != nullptr);

	int rank = Matrix4x4::rank;

	// init
	for (int i = 0; i < rank; i++)
	{
		delete[] A.grid[i];
	}

	delete[] A.grid;
	A.grid = nullptr;
}

/*func to copy matrix*/
Matrix4x4 copy(const Matrix4x4& from)
{
	Matrix4x4 to = create();
	int rank = Matrix4x4::rank;
	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			to.grid[i][j] = from.grid[i][j];
		}
	}
	return to;
}

/* this function multiplies 2 matrixes with rank 4*/
Matrix4x4 multiply(const Matrix4x4& A, const Matrix4x4& B)
{
	int rank = Matrix4x4::rank;
	int res = 0;

	/* resulting matrix*/
	Matrix4x4 R = create();

	/* 3 for loops to multiply matrixes*/
	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			long long int sum = 0;
			for (int k = 0; k < rank; k++)
			{
				sum += A.grid[i][k] * B.grid[k][j];
			}
			R.grid[i][j] = sum;
		}
	}

	return R;
}

/*
	4x4 id matrix:
	1 0 0 0
	0 1 0 0
	0 0 1 0
	0 0 0 1
*/
Matrix4x4 identity_matrix()
{
	Matrix4x4 A = create();
	int rank = Matrix4x4::rank;
	for (int i = 0; i < rank; i++)
	{
		A.grid[i][i] = 1;
	}

	return A;
}

// quick power with binary multiplication (O(logN))
Matrix4x4 quick_power(const Matrix4x4& A, int n)
{
	assert(n >= 0);

	if (n == 1)
		return copy(A);

	Matrix4x4 result = identity_matrix();


	if (n == 0)
		return result;
	

	Matrix4x4 matrix_copy = copy(A);

	while (n != 0)
	{
		assert(n > 0);
		if (n % 2 == 1)
		{
			Matrix4x4 temp = multiply(result, matrix_copy);
			delete_matrix(result);
			result = temp;
		}

		Matrix4x4 temp = multiply(matrix_copy, matrix_copy);
		delete_matrix(matrix_copy);
		matrix_copy = temp;
		n /= 2;
	}

	/* free memory */
	delete_matrix(matrix_copy);
	return result;
}

/*
	4x4 base matrix:
	1 1 1 1
	1 0 0 0
	0 1 0 0
	0 0 1 0
*/
Matrix4x4 baseMatrix()
{
	Matrix4x4 A = create();
	int rank = A.rank;
	A.grid[0][0] = 1LL;
	A.grid[0][1] = 1LL;
	A.grid[0][2] = 1LL;
	A.grid[0][3] = 1LL;
	A.grid[1][0] = 1LL;
	A.grid[2][1] = 1LL;
	A.grid[3][2] = 1LL;
	return A;
}

/* returns N number of tetranacci sequence by multiplying matrixes N-3 times*/
long long int get_tetranacci_n(int n)
{
	assert(n >= 0);

	if (n <= 2)
		return 0LL;

	if (n == 3)
		return 1LL;

	Matrix4x4 base = baseMatrix();
	Matrix4x4 res = quick_power(base, n - 3);

	long long value = res.grid[0][0];

	delete_matrix(base);
	delete_matrix(res);

	return value;
}