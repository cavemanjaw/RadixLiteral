#include "converter.h"
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>

void VariationsWithRepetitions(char* nTupleSet, size_t k, size_t n, char* literalBuffer);

void GenerateNTuple(char* nTupleSet, size_t k, size_t n, char* literalBuffer);

char* NumeralSuffix(size_t base);

//char* returning the literal for a given base numeral system that can be represented in size_t type
char* MaximalRepresentableLiteral();


size_t BufferSize()
{
	// size_t bytes times the amount of bits in a byte plus one for NULL character
	return sizeof(size_t) * (size_t)(CHAR_BIT) + (size_t)1;
}


char* CharacterLiteral(size_t numberOfDigits, char largestDigit)
{
	// TODO: Does this need to be a template for the buffer size to be computed at compile time?
	// Allocate the buffer for generated literals
	char literalBuffer[BufferSize()]; // TODO: Will this be actually calculated during compilation time?
	memset(literalBuffer, '\0', sizeof(literalBuffer));

	for (size_t digitPosition = 0; digitPosition < numberOfDigits; digitPosition++)
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
//(size_t numberOfDigits, char largestDigit) // TODO: For loop handling - the amount of steps
{
	// TODO: Does this need to be a template for the buffer size to be computed at compile time?
	// Allocate the buffer for generated literals
	char literalBuffer[BufferSize()]; // TODO: Will this be actually calculated during compilation time?
	memset(literalBuffer, '\0', sizeof(literalBuffer));

	// TODO: Hardcode
	size_t digitLimit = 10;

	// HERE :)
	char* nTuple = "0123456789";

	// TODO: Zero will be zero, so no need to generate empty set
	for (size_t digitRange = 1; digitRange < digitLimit; digitRange++)
	{
		// TODO: Third argument could be calculated from nTuple c-string
		VariationsWithRepetitions(nTuple, digitRange, digitLimit, literalBuffer);
	}
}


// Make the buffer a class instead of such procedural programming
void InsertChar(char charToAppend, char* charBuffer, size_t position)
{
	charBuffer[position] = charToAppend;
}


void DeleteChar(char* charBuffer, size_t position)
{
	charBuffer[position] = '\0';
}


size_t BufferLength(char* charBuffer)
{
	size_t size = 0;

	while (*charBuffer++)
	{
		size++;
	}

	return size;
}


// Generate variations with repetitions, need to pass the
void VariationsWithRepetitions(char* nTupleSet, size_t k, size_t n, char* literalBuffer)
{
	GenerateNTuple(nTupleSet, k, n, literalBuffer);
}


// k is the of length of one literal result, n is the number of elements in digit set for given numeral system
void GenerateNTuple(char* nTupleSet, size_t k, size_t n, char* literalBuffer) // Literal buffer length
{
	if (k != 0)
	{
		// TODO: Make it work to not generate leading zeros
		// Starting from digit = 1, not zero to omit the zero digit on leftmost position
		for (size_t digit = 0; digit < n; digit++)
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
		printf("static_assert(%s_b3 == %zd, \"test command log\");\n", literalBuffer, converter(literalBuffer, 3));
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
