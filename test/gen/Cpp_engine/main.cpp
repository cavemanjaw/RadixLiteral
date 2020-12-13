#include "converter.hpp"
#include "LiteralBuffer.hpp"
#include "utils.hpp"
#include "inverted_converter.hpp"

#include <iostream>
#include <cstddef>
#include <climits>
#include <limits>
#include <cstring>
#include <string>
#include <string.h>
#include <random>


void VariationsWithRepetitions(char* nTupleSet, std::size_t k, std::size_t n, LiteralBuffer literalBuffer);
void GenerateNTuple(char* nTupleSet, std::size_t k, std::size_t n, LiteralBuffer literalBuffer);

constexpr
char* NumeralSuffix(std::size_t base);
std::string GenerateRandomLiteral(std::size_t literalLength, std::size_t base, std::size_t maxPossibleDigit);


// Globals, like "==" and so on, to speed up execution - do not create strings inside immediate cout expressions
// Probably the best way would be to create them on stack once


// TODO: Breaking const correctness by having non-const reference to literalBuffer
void PrintLiteralStaticAssert(LiteralBuffer& literalBuffer, std::size_t base)
{
	std::cout << "static_assert(" << literalBuffer.GetBuffer()
			  << "_b" << base << " == " << converter(literalBuffer.GetBuffer(), base)
			  << ", \"test command log\");\n";
}

// TODO: _b not needed in GenerateRandomLiteral() !!!!!! // to converter need to pass char*!!!!!!
void PrintLiteralStaticAssert(std::string literalString, std::size_t base)
{
	std::cout << "static_assert(" << literalString
			  << "_b" << base << " == " << converter(literalString.c_str(), base)
			  << ", \"test command log\");\n";
}

//char* returning the literal for a given base numeral system that can be represented in size_t type
LiteralBuffer MaximalRepresentableLiteral(std::size_t base, LetterPolicy letterPolicy)
{
	std::size_t maxValue = std::numeric_limits<size_t>::max();
	return inverted_converter(maxValue, base, letterPolicy);
}

// TODO: Move to C_engine implementation
//char* CharacterSet(std::size_t base);

// TODO: Break into several (two?) intervals of inserting (by calling Insert()) characters to
// the characterSet
// TODO: Character set for both upper- and lower- cases
// TODO: Consider the maximal number of digits for a literal and pass around a LiteralBuffer (for example)
LiteralBuffer CharacterSet(std::size_t base, LetterPolicy letterPolicy)// TODO: Template or constexpr if
{
	// For the PART of a base being less or equal to 10, do...
	LiteralBuffer characterSet;
	std::size_t digitPosition = 0;

	char baseCharacter = '0';

	while (digitPosition <= 10 && digitPosition < base)
	{
		characterSet.Insert(baseCharacter++);
		digitPosition++;
	}

	// Next digit imterval depends on letterPolicy
	// TODO: Can be a ternary operator
	if (letterPolicy == LetterPolicy::LOWER_CASE)
	{
		baseCharacter = 'a';
	}
	else // letterPolicy == LetterPolicy::UPPER_CASE
	{
		baseCharacter = 'A';
	}

	// TODO: Loop breaking condition for more than 'Z' needed
	while (digitPosition < base)
	{
		characterSet.Insert(baseCharacter++);
		digitPosition++;
	}

	return characterSet;
}

// On the testing side - finding duplicates would be great.
// Finding generated literals that have the same converted values.
// TODO: Generating the range of literals
void GenerateCharacterLiterals(TestingPolicy testingPolicy)
//(std::size_t numberOfDigits, char largestDigit) // TODO: For loop handling - the amout of steps
{
	// TODO: Hardcode
	std::size_t digitLimit = 5; // 7 can be calculated on Intel(R) Core(TM) i5-4210U CPU @ 1.70GHz 0m43.029s, 8 causes problems

	if (testingPolicy == TestingPolicy::ALL_TEST)
	{
		// TODO: Does this need to be a template for the buffer size to be computed at compile time?
		// Allocate the buffer for generated literals
		LiteralBuffer buffer;
		// HERE :)
		LiteralBuffer nTuple = CharacterSet(digitLimit, LetterPolicy::UPPER_CASE);
		//char* nTuple = "01234";

		// TODO: Zero will be zero, so no need to generate empty set
		for (std::size_t digitRange = 1; digitRange < digitLimit; digitRange++)
		{
			// TODO: Third argument could be calculated from nTuple c-string
			VariationsWithRepetitions(nTuple.GetBuffer(), digitRange, digitLimit, buffer);
		}
	}
	else // (testingPolicy == TestingPolicy::RANDOM_TEST)
	{
		// Arbitrary number of random literals to test
		std::size_t numOfTestedLiterals = 20000;
		std::size_t maxBase = 18;

		std::random_device randomDevice; // Will be used to obtain a seed for the random number engine
		std::mt19937 generator(randomDevice()); //Standard mersenne_twister_engine seeded with randomDevice()
		std::uniform_int_distribution<> baseDist(2, maxBase);

		for (std::size_t testNumber = 0; testNumber < numOfTestedLiterals; testNumber++)
		{
			PrintLiteralStaticAssert(
					GenerateRandomLiteral(digitLimit, baseDist(generator), digitLimit), baseDist(generator));
		}
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
	//TODO: Create a ladder of the maximal representable value for every system
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
		PrintLiteralStaticAssert(literalBuffer, n);
		// TODO:
		// Policy of testing here (TestStrategy)?
		// Overloads (execution-time overhead) or static polymorphism (template printing only picked (random?) tests)
		// TODO: Temporary printing the tests here, modularize eventually
		// TODO: Store instead of putting to stdout
		//std::cout << literalBuffer << std::endl; //converter(literalBuffer, 3)
		//static_assert(111_b2 == 7, "testBinary failed! 111_b2 != 7");
//		std::cout << "static_assert(" << literalBuffer.GetBuffer()
//				  << "_b" << n << " == " << converter(literalBuffer.GetBuffer(), n)
//				  << ", \"test command log\");\n";
	}
}

//void GenerateRandomTestData()
//{
//	// Go over a arbitrary number of test and generate a literal with random length and random base
//
//}
// Generates random literal of specified base
// TODO: maxNumOfDigits versus random feeded numOfDigits?
std::string GenerateRandomLiteral(std::size_t literalLength, std::size_t base, std::size_t maxPossibleDigit)
{
	// Construct the suffix for the literal
	//std::string baseSuffix = "_b" + std::to_string(base); //Parametrize from "main" or global (probably bad)
	std::random_device randomDevice; // Will be used to obtain a seed for the random number engine
	std::mt19937 generator(randomDevice()); //Standard mersenne_twister_engine seeded with randomDevice()

	//std::uniform_int_distribution<> characterSetDist(0, maxPossibleDigit);
	std::uniform_int_distribution<> literalInsertionDist(0, maxPossibleDigit - 1);

	// Get a character set for given random base - this would make the solution biased towards
	// smaller number - the random base < maxPossibleDigit //TODO: Base is chosed randmoly, and then other
	LiteralBuffer characterSet = CharacterSet(maxPossibleDigit, LetterPolicy::UPPER_CASE);
	LiteralBuffer literal;

	for (std::size_t digit = 0; digit < literalLength; digit++)
	{
		// Inserts a random character from character set using literalInsertionDist
		// as an index to characterSet buffer //TODO: Is inserting in random place!!
		literal.Insert((characterSet.GetBuffer())[literalInsertionDist(generator)]);
	}

	// TODO: Implement conversion between LiteralBuffer and std::string
	std::string randomLiteral = std::string(literal.GetBuffer()); //+ baseSuffix;

	return randomLiteral;

	// Generate a random integer up to the base value
	// Generate one single random literal
	// Take a random base, - or take every possible base...
	//take a random set of digits < random base,
	//take a random length < BufferSize() rturn value
	// !!the literal decimal value needs to be smaller that max value of std::size_t
	// Generate the literal and calculate the decimal value by calling converter()

	// Maximal number of digit is the number of bits that std::size_t is represented by
	// No numeral system could
	//std::size_t maximalNumberOfDigits = BufferSize() - 1;
}


// Random size and base?
//void GenerateRandomLiteral(std::size_t literalLenght, std::size_t base)
//{
//
//}


int main(int argc, char* argv[])
{

	//generate tests :)


//	char literalBuffer[10];
//	memset(literalBuffer, '\0', sizeof(literalBuffer));
//	GenerateNTuple("AB", 3, 2, literalBuffer);
	//GenerateCharacterLiterals(TestingPolicy::ALL_TEST);
	GenerateCharacterLiterals(TestingPolicy::RANDOM_TEST);

	return 0;
}
