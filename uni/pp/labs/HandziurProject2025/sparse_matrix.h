/*Handziur Dmytro, NaUKMA SWE - 2*/
#pragma once
#include <cassert>

/* triplet struct */
template <typename T>
struct COO
{
	size_t _row, _col;
	T _value;
};

/* sparse matrix with array of triplets */
template <typename T>
struct SparseMatrix
{
	size_t _rank;
	COO<T>* _coord_list;
	size_t _list_size;
};

/* common matrix(dense) with grid (2D array) */
template <typename T>
struct DenseMatrix
{
	size_t _rank;
	T** _grid;
};

/* vactor struct with 1D array */
template <typename T>
struct Vector
{
	size_t _size;
	T* _values;
};


/* converts sparse matrix to dense*/
template <typename T>
DenseMatrix<T> to_dense(const SparseMatrix<T>& A)
{
	size_t rank = A._rank;
	DenseMatrix<T> matrix;
	matrix._rank = rank;

	/*memory allocation for grid in new matrix*/
	matrix._grid = new T*[rank];
	for (size_t i = 0; i < rank; i++)
	{
		matrix._grid[i] = new T[rank];
		for (size_t j = 0; j < rank; j++)
		{
			matrix._grid[i][j] = 0;
		}
	}

	for (size_t i = 0; i < A._list_size; i++)
	{
		//parsing COO list
		COO<T> coo = A._coord_list[i];
		assert(coo._row < rank);
		assert(coo._col < rank);
		//filling matrix with triplets values
		matrix._grid[coo._row][coo._col] = coo._value;
	}
	return matrix;
}

//multiplication realization
template <typename T>
Vector<T> operator*(const SparseMatrix<T>& A, const Vector<T>& x)
{
	assert(A._rank == x._size);

	Vector<T> result;
	size_t size = A._rank;
	result._size = size;

	// allocation of memory for array
	result._values = new T[size];

	// init array
	for (size_t i = 0; i < size; i++)
	{
		result._values[i] = 0;
	}

	for (size_t i = 0; i < A._list_size; i++)
	{
		// parsing triplets
		COO<T> coo = A._coord_list[i];
		// filling vector with new values
		result._values[coo._row] += coo._value * x._values[coo._col];
	}

	return result;
}