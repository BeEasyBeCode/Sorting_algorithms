#include "functions.h"
// Maks
// I will add testing function later
// "Standart choice"
//-----------------------------------------------------------------------------------------------------
void BSort(int array[], int size)
{
	bool flag = true;
	int i, j;

	int temp;

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
//*-----------------------------------------------------------------------------------------------------
// Modification of "boat" sorting


void BSort2(int array[], int size) // size - size of array
{
	int i, rezerv;				//i - counter for array, rezerv - for saving counter pisition
	int temp;						//temp - for swap
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

void InsertionSort(int arrayPtr[], int length) // Insertion sort
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
//-----------------------------------------------------------------------------------------------------
//Andriy Datskiv
//Quick Sort

void QSort(int array[], int first, int last)
{
	if (first < last)//compare first element with last 
	{
		int i;//vaiables for indexes
		int j;
		int temp;//for swap
		int point;

		point = array[first];//fixed element of array

		i = first;//left end of array
		j = last;//right end of array

		while (i < j)
		{
			while (array[i] <= point && i < last)
				i++;
			while (array[j] >= point && j > first)
				j--;

			if (i < j)//swapping elements
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}

		temp = array[first];
		array[first] = array[j];
		array[j] = temp;

		//Recursion QuickSort
		QSort(array, first, j - 1);
		QSort(array, j + 1, last);
	}
}


void PrintArray(int array[], int size)
{

	int i, j, in;
	cout << "\n\n V masyvi : " << size << "Elementiv \n";

	for (j = 0; j<3; ++j)
	{
		switch (j)
		{
		case 0:  in = 0;
			cout << "\n\n Pochatok : \n";
			break;
		case 1:  in = size / 2 - 5;
			cout << "\n\n Seredyna : \n";
			break;
		case 2:  in = size - 10;
			cout << "\n\n Kinets : \n";
			break;
		}

		for (i = in; i<in + 10; ++i)
		{
			if (i % 5 == 0)
				cout << endl;
			cout << setw(15) << array[i];
		}
	}
	cout << endl;
}

void QuickPackage(int Array[], int size)
{
	QSort(Array, 0, N - 1);
}

void Tester(void(*Function)(int array[], int size1), int Size)  //Tester all methods
{
	int Array[N];		//Array
	srand(time(0));
	for (int i = 0; i < N; ++i)
	{
		Array[i] = rand() % Size;	//Random Array
	}
	float start_time = clock(); //Time Start
	PrintArray(Array, Size);
	Function(Array, Size);		//Sorting
	float end_time = clock();	//Time End
	float search_time = end_time - start_time;
	PrintArray(Array, Size);
	cout << "\nTime: ";
	cout << search_time / CLOCKS_PER_SEC << endl;

}