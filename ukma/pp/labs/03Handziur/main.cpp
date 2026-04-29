#include <iostream>
#include "main.h"
#include <cassert>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(time(0));

    int size1 = 11;
    
    assert(size1 > 0);
    
    int* orig1 = new int[size1] {49, 1, 23, 43, 23, 12, 90, 26, 156, 32, 86};
    int* ms1 = copyArray(orig1, size1);
    int* qs1 = copyArray(orig1, size1);

    assert(orig1 != nullptr); 
    assert(ms1 != nullptr);
    assert(qs1 != nullptr);

    std::cout << "\n---\n#1 Original Array:\n\n";
    printArray(orig1, size1);

    mergeSort(ms1, size1, false);
    assert(checkElements(orig1, ms1, size1));
    assert(checkAscendance(ms1, size1));

    std::cout << "\n---\n#1 Merge Sort (Ascending):\n\n";
    printArray(ms1, size1);

    mergeSort(ms1, size1, true);
    assert(checkElements(orig1, ms1, size1));
    
    std::cout << "\n---\n#1 Merge Sort (Descending):\n\n";
    printArray(ms1, size1);

    quickSort(qs1, size1, false);
    assert(checkElements(orig1, qs1, size1));
    assert(checkAscendance(qs1, size1));

    std::cout << "\n---\n#1 Quick Sort (Ascending):\n\n";
    printArray(qs1, size1);

    quickSort(qs1, size1, true);
    assert(checkElements(orig1, qs1, size1));

    std::cout << "\n---\n#1 Quick Sort (Descending):\n\n";
    printArray(qs1, size1);


    int size2 = 37;

    assert(size2 > 0);

    int* orig2 = randomlyGeneratedArray(size2);
    int* ms2 = copyArray(orig2, size2);
    int* qs2 = copyArray(orig2, size2);

    assert(orig2 != nullptr);
    assert(ms2 != nullptr);
    assert(qs2 != nullptr);

    std::cout << "\n---\n#2 Original Array:\n\n";
    printArray(orig2, size2);

    mergeSort(ms2, size2, false);
    assert(checkElements(orig2, ms2, size2));
    assert(checkAscendance(ms2, size2));

    std::cout << "\n---\n#2 Merge Sort (Ascending):\n\n";
    printArray(ms2, size2);

    quickSort(qs2, size2, false);
    assert(checkElements(orig2, qs2, size2));
    assert(checkAscendance(qs2, size2));

    std::cout << "\n---\n#2 Quick Sort (Ascending):\n\n";
    printArray(qs2, size2);



    int size3 = 1'000;

    assert(size3 > 0);

    int* orig3 = randomlyGeneratedArray(size3);
    int* ms3 = copyArray(orig3, size3);
    int* qs3 = copyArray(orig3, size3);

    assert(orig3 != nullptr);
    assert(ms3 != nullptr);
    assert(qs3 != nullptr);


    std::cout << "\n---\n#3 Original Array:\n\n";
    printArray(ms3, size3);

    mergeSort(ms3, size3, false);
    assert(checkElements(orig3, ms3, size3));
    assert(checkAscendance(ms3, size3));

    std::cout << "\n---\n#3 Merge Sort (Ascending):\n\n";
    printArray(ms3, size3);

    quickSort(qs3, size3, false);
    assert(checkElements(orig3, qs3, size3));
    assert(checkAscendance(qs3, size3));

    std::cout << "\n---\n#3 Quick Sort (Ascending):\n\n";
    printArray(qs3, size3);


    delete[] orig1;
    delete[] ms1;
    delete[] qs1;

    delete[] orig2;
    delete[] ms2;
    delete[] qs2;

    delete[] orig3;
    delete[] ms3;
    delete[] qs3;

}

void mergeSort(int* array, int size, bool desc)
{
    assert(size > 0);
    assert(array != nullptr);

    mergeSortHelper(array, size, 0, size - 1);

    if (desc)
        reverse(array, size);
}

void mergeSortHelper(int* array, int size, int left, int right)
{
    if (right <= left)
        return;

    assert(array != nullptr);
    assert(size > 0);
    assert(left >= 0);
    assert(right >= 0);


    int middle = left + (right - left) / 2;

    mergeSortHelper(array, size, left, middle);
    mergeSortHelper(array, size, middle + 1, right);

    merge(array, size, left, middle, right);
}
void merge(int* array, int size, int left, int middle, int right)
{
    assert(size > 0);
    assert(array != nullptr);
    assert(middle >= left);
    assert(middle < right);
    assert(right < size);
    assert(left >= 0);

    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    assert(leftSize > 0);
    assert(rightSize > 0);

    int* leftPart = new int[leftSize];
    int* rightPart = new int[rightSize];

    assert(leftPart != nullptr);
    assert(rightPart != nullptr);

    for (int i = 0; i < leftSize; i++)
    {
        *(leftPart + i) = *(array + left + i);
    }

    for (int i = 0; i < rightSize; i++)
    {
        *(rightPart + i) = *(array + middle + 1 + i);
    }

    int leftPtr = 0, rightPtr = 0;
    int ptr = left;

    while (leftPtr < leftSize && rightPtr < rightSize)
    {
        int leftEl = *(leftPart + leftPtr);
        int rightEl = *(rightPart + rightPtr);

        if (leftEl <= rightEl) 
        {
            *(array + ptr++) = leftEl;
            leftPtr++;
        }
        else
        {
            *(array + ptr++) = rightEl;
            rightPtr++;
        }
    }

    while (leftPtr < leftSize)
    {
        int element = *(leftPart + leftPtr);

        *(array + ptr++) = element;
        leftPtr++;
    }

    while (rightPtr < rightSize)
    {
        int element = *(rightPart + rightPtr);

        *(array + ptr++) = element;
        rightPtr++;
    }

    delete[] leftPart;
    delete[] rightPart;
}
void printArray(int* array, int size)
{
    assert(array != nullptr);
    assert(size > 0);

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << *(array + i);
        if(i != size - 1)
            std::cout << ", ";
    }
    std::cout << "]\n";
}

int* randomlyGeneratedArray(int size)
{
    assert(size > 0);

    int* array = new int[size];

    for (int i = 0; i < size; i++)
    {
        *(array + i) = rand() % 100;
    }

    return array;
}

void shuffle(int* array, int size)
{
    assert(size > 0);
    assert(array != nullptr);

    for (int i = size - 1; i > 0; i--)
    {
        int idx = rand() % (i + 1);

        swap(array, size, i, idx);
    }
}

int pivot(int* array, int size, int left, int right)
{
    assert(array != nullptr);
    assert(size > 0);
    assert(left >= 0);
    assert(left < size);
    assert(right >= 0);
    assert(right < size);

    int lo = left;
    int hi = right;
    int pivIdx = left + (right - left) / 2;
    int pivotEl = *(array + pivIdx);

    assert(pivIdx >= lo);
    assert(pivIdx <= hi);

    while (lo <= hi)
    {
        while (pivotEl > *(array + lo))
            lo++;
        while (pivotEl < *(array + hi))
            hi--;

        if (lo <= hi)
            swap(array, size, lo++, hi--);
    }

    assert(lo >= left);
    assert(lo <= right);
    return lo;
}


void quickSort(int* array, int size, bool desc)
{
    assert(array != nullptr);
    assert(size > 0);

    shuffle(array, size);

    quickSortHelper(array, size, 0, size - 1);

    if (desc)
        reverse(array, size);
}

void quickSortHelper(int* array, int size, int left, int right)
{

    assert(array != nullptr);
    assert(size > 0);

    assert(left >= 0);
    assert(left < size);

    assert(right >= 0);
    assert(right < size);

    if (right <= left)
        return;

    int pivotIdx = pivot(array, size, left, right);

    assert(pivotIdx >= left);
    assert(pivotIdx <= right);

    quickSortHelper(array, size, left, pivotIdx - 1);
    quickSortHelper(array, size, pivotIdx, right);
}

void swap(int* array, int size, int a, int b)
{
    assert(array != nullptr);
    assert(size > 0);
    assert(a >= 0);
    assert(a < size);
    assert(b >= 0);
    assert(b < size);

    int temp = *(array + a);
    *(array + a) = *(array + b);
    *(array + b) = temp;
}

int* copyArray(int* array, int size)
{
    assert(array != nullptr);
    assert(size > 0);
 
    int* newArr = new int[size];

    for (int i = 0; i < size; i++)
    {
        *(newArr + i) = *(array + i);
    }

    return newArr;
}

void reverse(int* array, int size)
{
    assert(array != nullptr);
    assert(size > 0);

    for (int i = 0; i < size / 2; i++)
    {
        swap(array, size, i, (size - 1) - i);
    }
}

bool checkAscendance(int* array, int size)
{
    assert(array != nullptr);
    assert(size > 0);

    for (int i = 0; i < size - 1; i++)
    {
        if (*(array + i) > *(array + i + 1))
            return false;
    }

    return true;
}

bool checkElements(int* original, int* sorted, int size)
{
    assert(original != nullptr);
    assert(sorted != nullptr);
    assert(size > 0);

    bool* presence = new bool[size] {false};
    for (int i = 0; i < size; i++)
    {
        int target = *(original + i);
        bool found = false;

        for (int j = 0; j < size; j++)
        {
            if (*(sorted + j) == target && !*(presence + j))
            {
                *(presence + j) = true;
                found = true;
                break;
            }
        }
        if (!found) 
        {
            delete[] presence;
            return false;
        }
    }

    delete[] presence;
    return true;
}