#include "converter.h"
#include <iostream>
#include <cstddef>

enum class LetterPolicy
{
	LOWER_CASE,
	UPPER_CASE

};

// For C++20 can be consteval
constexpr std::size_t BufferSize()
{
	return sizeof(std::size_t) * (std::size_t)(CHAR_BIT);
}



//char* returning the literal for a given base numeral system that can be represented in size_t type
char* MaximalRepresentableLiteral();

char LargestDigit(std::size_t base, LetterPolicy letterPolicy)
{
	// Some char magic based on policy
	if (letterPolicy == LetterPolicy::LOWER_CASE)
	{

	}
	else // letterPolicy == LetterPolicy::UPPER_CASE
	{

	}
}

char* CharacterLiteral(std::size_t numberOfDigits, char largestDigit)
{
	// Allocate the buffer for generated literals
	char literalBuffer[BufferSize()]; // TODO: Will this be actually calculated during compilation time?

	for (std::size_t digitPosition = 0; digitPosition < numberOfDigits; digitPosition++)
	{
		// What should be the starting digit?
		for (char digit = 0; digit <= largestDigit; digit++)
		{
			// Put the digit in buffer and print it (?)
		}
	}
}

void print()
{
	std::cout << "Hello";
	std::cout << "world";
}

int main(int argc, char* argv[])
{

	return 0;
}



