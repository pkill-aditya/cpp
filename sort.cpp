/* Sorting an array in ascending sequence - using an indefinite while loop */

#include <iostream>
#include <iomanip>

int main()
{
	const std::size_t size {1000};	// Array size
	double x[size] {};	// Stores data to be sorted
	std::size_t count {};	// Number of values in array

	while (true)
	{
		double input {};	// Temporary store for a value
		std::cout << "Enter a non-zero value, or 0 to end: ";
		std::cin >> input;
		if (input == 0)
			break;

		x[count] = input;

		if (++count == size)
		{
			std::cout << "Sorry, I can only store " << size << " values.\n";
			break;
		}
	}

	if (!count)
	{
		std::cout << "Nothing to sort..." << std::endl;
		return 0;
	}

	std::cout << "Starting sort." << std::endl;

	while (true)
	{
		bool swapped { false };	// becomes true when not all values are in order
		for (std::size_t i {}; i < count - 1; ++i)
		{
			if (x[i] > x[i + 1])	// Out of order so swap them
			{
				const auto temp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = temp;
				swapped = true;
			}
		}

		if (!swapped)	// If there were no swaps
			break;	// ...all values are in order...
	}			// ...otherwise, go round again.

	std::cout << "Your data in ascending sequence:\n"
		<< std::fixed << std::setprecision(1);
	const std::size_t perline {10};	// Number of output per line
	std::size_t n {};	// Number on current line

	for (std::size_t i {}; i < count; ++i)
	{
		std::cout << std::setw(8) << x[i];
		if (++n == perline)	// When perline have been written...
		{
			std::cout << std::endl;	// ...reset count on this line
			n = 0;
		}
	}
	std::cout << std::endl;

	return 0;
}

