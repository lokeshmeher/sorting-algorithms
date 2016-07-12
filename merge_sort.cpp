// Divide and conquer
// Unsorted list is divided into N sublists, each having one element, because
//  a list of one element is considered sorted.
// Repeatedly merges these sublist to produce new sorted sublists 
// and at last one sorted list is produced.
// * Fast
// * Time complexity: O(nlogn)
// * Stable sort

#include <iostream>


void merge(int arr[], int firstIndex, int midIndex, int lastIndex)
{
	int arrayLength = lastIndex - firstIndex + 1;
	int newArray[arrayLength];	// cannot initialize as arrayLength is not a compile time constant
	
	int count_1 = firstIndex;
	int count_2 = midIndex + 1;
	int index = 0;

	while (count_1 <= midIndex && count_2 <= lastIndex)
	{
		if (arr[count_1] < arr[count_2])
			newArray[index++] = arr[count_1++];
		else
			newArray[index++] = arr[count_2++];
	}

	while (count_1 <= midIndex)
		newArray[index++] = arr[count_1++];

	while (count_2 <= lastIndex)
		newArray[index++] = arr[count_2++];

	// Replace values in original array by corresponding values from the sorted array
	for (int index = 0; index < arrayLength; ++index)
		arr[index + firstIndex] = newArray[index];
}


void mergeSort(int arr[], int firstIndex, int lastIndex)
{
	if (firstIndex < lastIndex)	// base case (termination condition for recursion)
	{
		int midIndex = (firstIndex + lastIndex) / 2;	// floor division (using integer division)
		
		mergeSort(arr, firstIndex, midIndex);
		mergeSort(arr, midIndex + 1, lastIndex);
		
		merge(arr, firstIndex, midIndex, lastIndex);
	}
}


void printArray(int arr[], int size)
{
	for (int index = 0; index < size; ++index)
		std::cout << arr[index] << " ";
	std::cout << "\n";
}


int main()
{
	int arr[8] = { 5, 2, 4, 6, 1, 3, 2, 6 };
	int a[5] = { 32, 45, 67, 2, 7 };

	mergeSort(arr, 0, 7);
	printArray(arr, 8);

	mergeSort(a, 0, 4);
	printArray(a, 5);

	return 0;
}

/*
Another slightly different implementation of merge():

	int numberOfComparisons = (midIndex - firstIndex + 1) + (lastIndex - midIndex + 1) - 1;
	for (int count = 0; count < numberOfComparisons; ++count)
	{
		if (arr[count_1] < arr[count_2])
		{
			newArray[count] = arr[count_1];
			
			if (count_1 < midIndex)
				++count_1;
			else
			{
				++count;
				for (int iii = count_2; iii <= lastIndex; ++iii, ++count)
					newArray[count] = arr[iii];
				break;
			}
		}
		else
		{
			newArray[count] = arr[count_2];
			
			if (count_2 < lastIndex)
				++count_2;
			else
			{
				++count;
				for (int jjj = count_1; jjj <= midIndex; ++jjj, ++count)
					newArray[count] = arr[jjj];
				break;
			}
		}
	}

*/