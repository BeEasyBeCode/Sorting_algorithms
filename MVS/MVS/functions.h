#pragma once
#include <iostream>  //For Eugene's code
#include <ctime>	//For Eugene's code
#include <iomanip> //For Eugene's code

using namespace std;
const int N = 50000;

void BSort(int array[], int size);
void BSort2(int array[], int size);
void InsertionSort(int arrayPtr[], int length);
void QSort(int array[], int first, int last);
void PrintArray(int array[], int size);
void QuickPackage(int Array[], int size);
void Tester(void(*Function)(int array[], int size1), int Size);