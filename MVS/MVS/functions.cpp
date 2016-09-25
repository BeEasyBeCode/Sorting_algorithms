#include "functions.h"

// Maks
// I will add testing function later
// "Standart choice"
//-----------------------------------------------------------------------------------------------------
template <typename T>
void BSort(T array[], long size)
{
	bool flag = true;
	long i, j;

	T temp;

	for (j = 1;; j++)
	{
		for (i = 0; i < size - j; i++)
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				flag = false;
			}

		if (flag)
			break;

		flag = true;
	}
}
//-----------------------------------------------------------------------------------------------------
// Modification of "boat" sorting
template <typename T>
void BSort2(T array[], long size) // size - size of array
{
	long i, rezerv;				//i - counter for array, rezerv - for saving counter pisition
	T temp;						//temp - for swap
	i = 0;

	while (i < size - 1)
	{
		if (array[i] > array[i + 1]) // compare
		{
			rezerv = i + 1;			// save counter position
			while ((i >= 0) && (array[i] > array[i + 1]))  // swap while..
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				i--;				// compare elements behind 'i'
			}
			i = rezerv;				// return 'i' on position
		}
		else
			i++;					// next elements
	}
}
//-----------------------------------------------------------------------------------------------------
// Eugene Roman
void InsertionSort(int *arrayPtr, int length) // Insertion sort
{
	int temp, // temporary variable for storing the value of the sorted array element
		item; // the index of the previous element
	for (int counter = 1; counter < length; counter++)
	{
		temp = arrayPtr[counter]; // initialize a temporary variable current value of the array element
		item = counter - 1; // remember the previous index of the array element
		while (item >= 0 && arrayPtr[item] > temp) // while the index is not equal to 0, and the previous element of an array greater than the current
		{
			arrayPtr[item + 1] = arrayPtr[item]; // permutation of the array elements
			arrayPtr[item] = temp;
			item--;
		}
	}
}

// Eugene Roman
void TEST_ALGORITHM_INSERT_SORTING(void)
{
	srand(time(0));
	cout << "Input size of array: ";
	int size_of_array; // length of the array
	cin >> size_of_array;

	int *sorted_array = new int[size_of_array]; // one dimensional dynamic array
	for (int counter = 0; counter < size_of_array; counter++)
	{
		cin>>sorted_array[counter]; // fill an array
		cout << setw(4) << sorted_array[counter] << "  "; // the output of the array on the screen
	}
	cout << "----------------------------------------------------------------";

	InsertionSort(sorted_array, size_of_array); // call inserts sorting functions

	for (int counter = 0; counter < size_of_array; counter++)
	{
		cout << setw(4) << sorted_array[counter] << "   "; // Printing a sorted array
	}
	cout << "----------------------------------------------------------------";
	delete[] sorted_array; // frees up the memory
	cout << "\nSpent time: " << clock()/1000.0 << endl;
}
//-----------------------------------------------------------------------------------------------------