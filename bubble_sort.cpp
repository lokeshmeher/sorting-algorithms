#include <iostream>
#include <array>
#include <utility>

int main()
{
	std::array<int, 6> nArray = {5, 1, 6, 2, 4, 3};
	
	for (unsigned int iteration = 0; iteration < nArray.size() - 1; ++iteration)
	{
		bool swapped = false;
		for (unsigned int currentIndex = iteration + 1; currentIndex < nArray.size(); ++currentIndex)
		{
			if (nArray.at(iteration) > nArray.at(currentIndex))
			{	
				std::swap(nArray.at(iteration), nArray.at(currentIndex));
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

	for (unsigned int count = 0; count < nArray.size(); ++count)
		std::cout << nArray.at(count) << " ";
	std::cout << '\n';
	
	return 0;
}