#include <iostream>
#include "main.h"
#include <cassert>

int main()
{
    const int rank1 = 3;
    const int rank2 = 5;
    int numberSet1[rank1][rank1] =
    {
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5}
    };

    int numberSet2[rank1][rank1] =
    {
        {1, 2, 3},
        {2, 9, 2},
        {3, 3, 3}
    };

    int numberSet3[rank1][rank1] =
    {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    };

    int** dynamic1 = staticToDynamic(&numberSet1[0][0], rank1);
    printSquareMatrix(dynamic1, rank1);

    std::cout << "\nIs a magic square? " << std::boolalpha << checkMagicSquare(dynamic1, rank1);
    std::cout << "\n-----\n";
    deleteMatrix(dynamic1, rank1);


    int** dynamic2 = staticToDynamic(&numberSet2[0][0], rank1);
    printSquareMatrix(dynamic2, rank1);

    std::cout << "\nIs a magic square? " << std::boolalpha << checkMagicSquare(dynamic2, rank1);
    std::cout << "\n-----\n";
    deleteMatrix(dynamic2, rank1);


    int** dynamic3 = staticToDynamic(&numberSet3[0][0], rank1);
    printSquareMatrix(dynamic3, rank1);

    std::cout << "\nIs a magic square? " << std::boolalpha << checkMagicSquare(dynamic3, rank1);
    std::cout << "\n-----\n";
    deleteMatrix(dynamic3, rank1);



    std::cout << "\ngenerated:\n\n";
    int** custom = generateMagicSquare(rank2);
    printSquareMatrix(custom, rank2);

    std::cout << "\nIs a magic square? " << std::boolalpha << checkMagicSquare(custom, rank2);
    std::cout << "\n-----\n";
    deleteMatrix(custom, rank2);



    std::cout << "\ngenerated2:\n\n";
    int** custom2 = generateMagicSquare(rank1);
    printSquareMatrix(custom2, rank1);

    std::cout << "\nIs a magic square? " << std::boolalpha << checkMagicSquare(custom2, rank1);
    std::cout << "\n-----\n";
    deleteMatrix(custom2, rank1);
}
int** staticToDynamic(int* matrix, int rank)
{
    assert(rank >= 1);

    int** arr = allocMatrix(rank);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            *(*(arr + i) + j) = matrix[i * rank + j];
        }
    }
    return arr;
}


void printSquareMatrix(int** matrix, int rank)
{
    assert(rank >= 1);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            std::cout << *(*(matrix + i) + j) << "\t";
        }
        std::cout << std::endl;
    }
}

int** allocMatrix(int rank)
{
    int** A = new int* [rank];

    for (int i = 0; i < rank; i++)
    {
        *(A + i) = new int[rank];
    }

    return A;
}

void deleteMatrix(int** matrix, int rank)
{
    for (int i = 0; i < rank; i++)
    {
        delete[] * (matrix + i);
    }
    delete[] matrix;
}

bool checkMagicSquare(int** matrix, int rank)
{
    assert(rank % 2 == 1);
    
    if (!checkUniqueNumbers(matrix, rank))
        return false;

    const int magicConstant = rank * (rank * rank + 1) / 2;
    int sumHor = 0;
    int sumVer = 0;
    int sumDiag1 = 0;
    int sumDiag2 = 0;


    /*rows and columns*/
    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            sumHor += *(*(matrix + i) + j);
            sumVer += *(*(matrix + j) + i);
        }
        if (magicConstant != sumHor || magicConstant != sumVer)
            return false;
        sumHor = 0;
        sumVer = 0;
    }

    /*diagonals*/
    for (int i = 0; i < rank; i++)
    {
        sumDiag1 += *(*(matrix + i) + i);
        sumDiag2 += *(*(matrix + (rank - i - 1)) + i);
    }
    if (magicConstant != sumDiag1 || magicConstant != sumDiag2)
        return false;

    return true;
}

bool checkUniqueNumbers(int** matrix, int rank)
{
    int hi = rank * rank;
    bool* uniqueArray = new bool[hi] {false};   
    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            int matrixIdx = *(*(matrix + i) + j);
            if (matrixIdx < 1 || matrixIdx > hi)
                return false;
            *(uniqueArray + matrixIdx - 1) = true;
        }
    }

    for (int i = 0; i < hi; i++) {
        if (!*(uniqueArray + i))
            return false;
    }

    return true;
}

int** generateMagicSquare(int rank)
{
    assert(rank > 0 && rank % 2 == 1);

    int** matrix = allocMatrix(rank);

    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < rank; j++)
        {
            *(*(matrix + i) + j) = 0;
        }
    }

    int i = rank / 2;
    int j = rank - 1;
    int hi = rank * rank;

    for (int number = 1; number <= hi; ) {
        if (i == -1 && j == rank) {
            j = rank - 2;
            i = 0;
        }
        else {
            if (j == rank) 
                j = 0;
            if (i < 0) 
                i = rank - 1;
        }

        if (*(*(matrix + i) + j) != 0) {
            j -= 2;
            i++;
            continue;
        }
        else {
            *(*(matrix + i) + j) = number++;
        }

        j++; i--;
    }

    return matrix;
}