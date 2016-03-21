/*
	By Lokesh Nandan Meher.

	- Uses "siftDown" approach having time complexity O(logn)."siftUp" has worse time complexity of O(nlog(n)).

	Note:
	<random> is a C++11 feature. Use rand() [include header <cstdlib>] instead for older compilers. time(0), defined in <ctime>,
	can be used to seed srand().
*/

#include <iostream>
#include <random>


// Returns index of parent node in the array.
// iChild is index of child node in the array.
inline int iParent(int iChild)
{
	return (iChild - 1) / 2;	// floor(return value) -- using integer division
}


// Returns index of left child.
// iParent is index of parent node in the array.
inline int iLeftChild(int iParent)
{
	return 2 * iParent + 1;
}


// Returns index of right child.
// iParent is index of the parent node in the array.
inline int iRightChild(int iParent)
{
	return iLeftChild(iParent) + 1;	// for consistency
}


// Function forward declarations using function prototypes.
void heapify(int arr[], int length);
void siftDown(int arr[], int iStart, int iEnd);


void heapSort(int arr[], int length)
{
	// Build max heap
	heapify(arr, length);
	
	// Initially, the entire array is the heap
	int iHeapEnd = length - 1;

	while (iHeapEnd > 0)
	{
		// arr[0] is the root and holds the largest value
		int temp = arr[0];
		arr[0] = arr[iHeapEnd];
		arr[iHeapEnd] = temp;

		// The heapsize is reduced by one
		--iHeapEnd;

		// The swap ruined the heap property, restore it
		siftDown(arr, 0, iHeapEnd);
	}
}


// Put elements of arr in heap order, in-place.
void heapify(int arr[], int length)
{
	// Start from the last parent
	int iNode = iParent(length - 1);

	while (iNode >= 0)
	{
		// Sift down the node at index iNode in arr to proper place
		// such that all nodes below the index are in heap order.
		siftDown(arr, iNode, length - 1);

		// Go to the previous parent
		--iNode;
	}
	
	// After sifting down the root (iNode = 0), all nodes/elements are in heap order.
}


// Repair the heap whose root element is at index iNode,
// assuming the heaps rooted at its children nodes are valid.
void siftDown(int arr[], int iStart, int iEnd)
{
	int iRoot = iStart;
	
	// While the root has at least one child
	while (iLeftChild(iRoot) <= iEnd)
	{
		int iChild = iLeftChild(iRoot);
		int iSwap = iRoot;	// Keeps track of child to swap with

		if (arr[iChild] > arr[iSwap])
			iSwap = iChild;

		// If there is a right child and that child is greater
		if (iChild + 1 <= iEnd && arr[iChild + 1] > arr[iSwap])
			iSwap = iChild + 1;

		if (iSwap == iRoot)
		{
			// The root holds the largest element. Since we assume the heaps
			// rooted at the children are valid, this means we are done.
			return;
		}
		else
		{
			int temp = arr[iRoot];
			arr[iRoot] = arr[iSwap];
			arr[iSwap] = temp;

			// Repeat to continue sifting down the child now
			iRoot = iSwap;
		}
	}
}


void printArray(int arr[], int length)
{
	for (int index = 0; index < length; ++index)
	{
		std::cout << arr[index] << " ";
	}
	std::cout << "\n";
}


int main()
{
	const int length = 100000;	// 100,000
	int nArray[length] = {};	// All elements initialized to zero

	// Use a hardware entropy source to generate a random seed
	std::random_device rd;

	// Initialize our mersenne twister with the generated random seed
	std::mt19937 mersenne(rd());

	// Fill our array with random numbers in the range 0 to 1,000,000
	for (int index = 0; index < length; ++index)
		nArray[index] = mersenne() % 1000000;

	printArray(nArray, length);
	
	heapSort(nArray, length);
	
	printArray(nArray, length);

	return 0;
}
