#include "converter.h"
#include <iostream>
#include <cstddef>

enum class LetterPolicy
{
	LOWER_CASE,
	UPPER_CASE

};

char CalculateLargestDigit(std::size_t base, LetterPolicy letterPolicy)
{
	// Some char magic based on policy
	if (letterPolicy == LetterPolicy::LOWER_CASE)
	{

	}
	else // letterPolicy == LetterPolicy::UPPER_CASE
	{

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



