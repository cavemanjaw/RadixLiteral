#include "converter.h"
#include <iostream>
#include <cstddef>
#include <climits>
#include <cstring>
#include <string>
#include <string.h>

void VariationsWithRepetitions(char* nTupleSet, std::size_t k, std::size_t n, char* literalBuffer);
void GenerateNTuple(char* nTupleSet, std::size_t k, std::size_t n, char* literalBuffer);

// Globals, like "==" and so on, to speed up execution - do not create strings inside immediate cout expressions
// Probably the best way would be to create them on stack once

// enum for C
//enum class LetterPolicy
//{
//	LOWER_CASE,
//	UPPER_CASE
//
//};
//
//enum class TestStrategy
//{
//	PICKY_TEST,
//	ALL_TEST
//	//?
//};

constexpr
char* NumeralSuffix(std::size_t base);

// For C++20 can be consteval
constexpr
std::size_t BufferSize()
{
	// std::size_t bytes times the amount of bits in a byte plus one for NULL character
	return sizeof(std::size_t) * (std::size_t)(CHAR_BIT) + std::size_t{1};
}



//char* returning the literal for a given base numeral system that can be represented in size_t type
char* MaximalRepresentableLiteral();

//char LargestDigit(std::size_t base, LetterPolicy letterPolicy)
//{
//	// Some char magic based on policy
//	if (letterPolicy == LetterPolicy::LOWER_CASE)
//	{
//
//	}
//	else // letterPolicy == LetterPolicy::UPPER_CASE
//	{
//
//	}
//}

char* CharacterLiteral(std::size_t numberOfDigits, char largestDigit)
{
	// TODO: Does this need to be a template for the buffer size to be computed at compile time?
	// Allocate the buffer for generated literals
	char literalBuffer[BufferSize()]; // TODO: Will this be actually calculated during compilation time?
	std::memset(literalBuffer, '\0', sizeof(literalBuffer));

	for (std::size_t digitPosition = 0; digitPosition < numberOfDigits; digitPosition++)
	{
		// What should be the starting digit?
		for (char digit = 0; digit <= largestDigit; digit++)
		{
			// Put the digit in buffer and print it (?)
			literalBuffer[digitPosition] = digit;
		}
	}
}

// On the testing side - finding duplicates would be great.
// Finding generated literals that have the same converted values.


// TODO: Generating the range of literals
void GenerateCharacterLiterals()
//(std::size_t numberOfDigits, char largestDigit) // TODO: For loop handling - the amout of steps
{
	// TODO: Does this need to be a template for the buffer size to be computed at compile time?
	// Allocate the buffer for generated literals
	char literalBuffer[BufferSize()]; // TODO: Will this be actually calculated during compilation time?
	std::memset(literalBuffer, '\0', sizeof(literalBuffer));


	// TODO: Hardcode
	std::size_t digitLimit = 7;

	// HERE :)
	char* nTuple = "0123456";

	// TODO: Zero will be zero, so no need to generate empty set
	for (std::size_t digitRange = 1; digitRange < digitLimit; digitRange++)
	{
		// TODO: Third argument could be calculated from nTuple c-string
		VariationsWithRepetitions(nTuple, digitRange, digitLimit, literalBuffer);
	}
}


// Make the buffer a class instead of such procedural programming
void InsertChar(char charToAppend, char* charBuffer, std::size_t position)
{
	charBuffer[position] = charToAppend;
}

void DeleteChar(char* charBuffer, std::size_t position)
{
	charBuffer[position] = '\0';
}

std::size_t BufferLength(char* charBuffer)
{
	std::size_t size = 0;

	while (*charBuffer++)
	{
		size++;
	}

	return size;
}

// Generate variations with repetitions, need to pass the
void VariationsWithRepetitions(char* nTupleSet, std::size_t k, std::size_t n, char* literalBuffer)
{
	GenerateNTuple(nTupleSet, k, n, literalBuffer);
}

// k is the of length of one literal result, n is the number of elements in digit set for given numeral system
void GenerateNTuple(char* nTupleSet, std::size_t k, std::size_t n, char* literalBuffer) // Literal buffer length
{
	if (k != 0)
	{
		// TODO: Make it work to not generate leading zeros
		// Starting from digit = 1, not zero to omit the zero digit on leftmost position
		for (std::size_t digit = 0; digit < n; digit++)
		{
			// Add at the end of the literalBuffer the char at "digit" position from nTupleSet
			InsertChar(nTupleSet[digit], literalBuffer, BufferLength(literalBuffer)); // TODO: Save position instead of recalc!
			GenerateNTuple(nTupleSet, k - 1, n, literalBuffer);
			DeleteChar(literalBuffer, BufferLength(literalBuffer) - 1); // TODO: Save position instead of recalc!
		}
	}
	else // k == 0, generate the literal
	{
		// TODO:
		// Policy of testing here (TestStrategy)?
		// Overloads (execution-time overhead) or static polymorphism (template printing only picked (random?) tests)
		// TODO: Temporary printing the tests here, modularize eventually
		// TODO: Store instead of putting to stdout
		//std::cout << literalBuffer << std::endl; //converter(literalBuffer, 3)
		//static_assert(111_b2 == 7, "testBinary failed! 111_b2 != 7");
		std::cout << "static_assert(" << literalBuffer
				  << "_b3" << " == " << converter(literalBuffer, 3)
				  << ", \"test command log\");\n";
	}

}


int main(int argc, char* argv[])
{

	//generate tests :)


//	char literalBuffer[10];
//	memset(literalBuffer, '\0', sizeof(literalBuffer));
//	GenerateNTuple("AB", 3, 2, literalBuffer);
	GenerateCharacterLiterals();

	return 0;
}



