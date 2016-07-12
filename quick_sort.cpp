// Divide and conquer(partition and exchange sort)
// Not stable sort but fast and requires less additional space

#include <iostream>


int partition(int arr[], int index_1, int index_2)
{
	int pivot = arr[index_1];

	while (true)
	{
		// We traverse the array from both ends and arrange the elements so that all the elements
		// smaller than our pivot are on the left hand side and those that are larger are on it's right.
		while (arr[index_1] < pivot && arr[index_1] != pivot)
			++index_1;
		while (arr[index_2] > pivot && arr[index_2] != pivot)
			--index_2;

		if (index_1 < index_2)
		{
			int temp = arr[index_1];
			arr[index_1] = arr[index_2];
			arr[index_2] = temp;
		}
		else
			return index_2;
	}
}


// Recursively sorts an array based on 'quick sort' algorithm.
void quickSort(int arr[], int firstIndex, int lastIndex)
{
	if (firstIndex < lastIndex)	// base case (termination condition)
	{
		int pivotIndex = partition(arr, firstIndex, lastIndex);
		quickSort(arr, firstIndex, pivotIndex);
		quickSort(arr, pivotIndex + 1, lastIndex);
	}
}


void printArray(int arr[], int length)
{
	for (int index = 0; index < length; ++index)
		std::cout << arr[index] << " ";
	
	std::cout << "\n";
}


int main()
{
	int nArray[9] = {6, 5, 1, 3, 8, 4, 7, 9, 2};

	quickSort(nArray, 0, 8);
	printArray(nArray, 9);

	return 0;
}