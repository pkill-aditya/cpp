/* Searching a string for characters from a set */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main()
{
	std::string text;	// The string to be searched
	std::cout << "Enter some text terminated by *:\n";
	std::getline(std::cin, text, '*');

	const std::string seperators { " ,;:.\"!?'\n" };	// Word delimiters
	std::vector<std::string> words;	// Words found
	std::size_t start { text.find_first_not_of(seperators) };	// First word start index

	while (start != std::string::npos)	// Find the words
	{
		std::size_t end = text.find_first_of(seperators, start + 1);	// Find end of word
		if (end == std::string::npos)	// Found a seperator?
			end = text.length();	// No, so set to end of text
		words.push_back(text.substr(start, end - start));	// Store the word
		start = text.find_first_not_of(seperators, end + 1);	// Find first character of next word
	}

	std::cout << "Your string contains the following " << words.size() << " words:\n";
	std::size_t count {};	// Number output
	for (const auto& word : words)
	{
		std::cout << std::setw(15) << word;
		if (!(++count % 5))
			std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

