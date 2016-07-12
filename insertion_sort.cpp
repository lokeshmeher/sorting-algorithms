// efficient for smaller data sets but very inefficient for larger data sets.
// better than bubble sort and selection sort

#include <iostream>
#include <array>


int main()
{
	using namespace std;

	array<int, 6> nArray {5, 1, 6, 2, 4, 3};

	for (int index = 1; index < 6; ++index)
	{
		int key = nArray[index];
		int innerIndex = index - 1;
		while (innerIndex >= 0 && key < nArray[innerIndex])
		{
			nArray[innerIndex + 1] = nArray[innerIndex];
			--innerIndex;
		}
		nArray[innerIndex + 1] = key;
	}

	for (int index = 0; index < 6; ++index)
		cout << nArray[index] << " ";
	cout << "\n";

	return 0;
}