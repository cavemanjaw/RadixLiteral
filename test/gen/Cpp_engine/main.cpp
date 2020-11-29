#include "converter.h"
#include <iostream>
#include <cstddef>
#include <climits>
#include <cstring>
#include <string>
#include <string.h>

class LiteralBuffer;

void VariationsWithRepetitions(char* nTupleSet, std::size_t k, std::size_t n, LiteralBuffer literalBuffer);
void GenerateNTuple(char* nTupleSet, std::size_t k, std::size_t n, LiteralBuffer literalBuffer);

constexpr
char* NumeralSuffix(std::size_t base);

// For C++20 can be consteval
constexpr
std::size_t BufferSize()
{
	// std::size_t bytes times the amount of bits in a byte plus one for NULL character
	return sizeof(std::size_t) * (std::size_t)(CHAR_BIT) + std::size_t{1};
}

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

class LiteralBuffer
{
public:
	// TODO: Argument for the buffer size?
	//constexpr
	LiteralBuffer()
		: size{std::size_t{0}}
	{
		std::memset(buffer, '\0', sizeof(buffer));
	}


	std::size_t Length()
	{
		return size;
	}


	void Insert(char charToAppend, std::size_t position)
	{
		buffer[position] = charToAppend;
		size++;
	}


	void Delete(std::size_t position)
	{
		buffer[position] = '\0';
		size--;
	}

	char* GetBuffer()
	{
		return buffer;
	}


private:
	// TODO: constexpr specifier for calculation of buffer array size
	char buffer[BufferSize()];
	std::size_t size;
};


//char* returning the literal for a given base numeral system that can be represented in size_t type
char* MaximalRepresentableLiteral();


// On the testing side - finding duplicates would be great.
// Finding generated literals that have the same converted values.
// TODO: Generating the range of literals
void GenerateCharacterLiterals()
//(std::size_t numberOfDigits, char largestDigit) // TODO: For loop handling - the amout of steps
{
	// TODO: Does this need to be a template for the buffer size to be computed at compile time?
	// Allocate the buffer for generated literals
	LiteralBuffer buffer;

	// TODO: Hardcode
	std::size_t digitLimit = 7;

	// HERE :)
	char* nTuple = "0123456";

	// TODO: Zero will be zero, so no need to generate empty set
	for (std::size_t digitRange = 1; digitRange < digitLimit; digitRange++)
	{
		// TODO: Third argument could be calculated from nTuple c-string
		VariationsWithRepetitions(nTuple, digitRange, digitLimit, buffer);
	}
}


// Generate variations with repetitions, need to pass the
void VariationsWithRepetitions(char* nTupleSet, std::size_t k, std::size_t n, LiteralBuffer literalBuffer)
{
	GenerateNTuple(nTupleSet, k, n, literalBuffer);
}

// k is the of length of one literal result, n is the number of elements in digit set for given numeral system
void GenerateNTuple(char* nTupleSet, std::size_t k, std::size_t n, LiteralBuffer literalBuffer) // Literal buffer length
{
	if (k != 0)
	{
		// TODO: Make it work to not generate leading zeros
		// Starting from digit = 1, not zero to omit the zero digit on leftmost position
		for (std::size_t digit = 0; digit < n; digit++)
		{
			// Add at the end of the literalBuffer the char at "digit" position from nTupleSet
			literalBuffer.Insert(nTupleSet[digit], literalBuffer.Length());
			GenerateNTuple(nTupleSet, k - 1, n, literalBuffer);
			literalBuffer.Delete(literalBuffer.Length());
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
		std::cout << "static_assert(" << literalBuffer.GetBuffer()
				  << "_b7" << " == " << converter(literalBuffer.GetBuffer(), 7)
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



