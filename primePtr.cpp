/* Calculating primes using pointer notation */

#include <iostream>
#include <iomanip>

int main()
{
	const std::size_t max {100};	// Number of primes required
	long primes[max] {2L};	// First prime defined
	std::size_t count {1};	// Count of primes so far
	long trial {3L};	// Candidate prime

	while (count < max)
	{
		bool isPrime {true};	// Indicates when a prime is found

		// Try dividing the candidate by all the primes we have
		for (std::size_t i {}; i < count && isPrime; ++i)
		{
			isPrime = trial % *(primes + i) > 0;	// False for exact division
		}

		if (isPrime)
		{					// We got one...
			*(primes + count++) = trial;	// ...so save it in primes array
		}

		trial += 2;	// Next value for checking
	}

	// Output primes 10 to a line
	std::cout << "The first " << max << " primes are:" << std::endl;
	for (std::size_t i {}; i < max; ++i)
	{
		std::cout << std::setw(7) << *(primes + i);
		if ((i + 1) % 10 == 0)	// Newline after every 10th line
			std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
