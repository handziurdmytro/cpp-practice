#pragma once

void mergeSort(int* array, int size, bool desc);
void mergeSortHelper(int* array, int size, int left, int right);
void merge(int* array, int size, int left, int middle, int right);
void printArray(int* array, int size); 
int* randomlyGeneratedArray(int size);
void shuffle(int* array, int size);
int pivot(int* array, int size, int left, int right);
void quickSort(int* array, int size, bool desc);
void quickSortHelper(int* array, int size, int left, int right);
void swap(int* array, int size, int a, int b);
int* copyArray(int* array, int size);
void reverse(int* array, int size);
bool checkAscendance(int* array, int size);
bool checkElements(int* original, int* sorted, int size);