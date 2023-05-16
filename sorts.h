#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <time.h>
#include <ctime>
#include <chrono>
#include <fstream>
#include <stdio.h>
#include <string>
void Heapify(int* ar, int n, int i);
void Merge(int* ar, int l, int m, int r);
int Partition(int* ar, int first, int last);
int GetMax(int* ar, int size);
void InsertionSort(int* ar, int len);
void insertionSort(int* ar, int left, int right);
void BubbleSort(int* ar, int len);
void QuickSort(int* ar, int len);
void quickSort(int* ar, int last, int first);
void SelectionSort(int* ar, int len);
void CountingSort(int* ar, int len);
void MergeSort(int* ar, int len);
void mergeSort(int* ar, int right, int left);
void ShellSort(int* ar, int len);
void GnomeSort(int* ar, int len);
void HeapSort(int* ar, int len);
int GetRandomNumber(int min, int max);
void Sort(int index, int* ar, int len);
void Megatest();