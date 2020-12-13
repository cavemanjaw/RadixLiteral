#include "LiteralBuffer.hpp"
#include "inverted_converter.hpp"

#include <cmath>

char MapSingleDigit(std::size_t value, std::size_t base, LetterPolicy letterPolicy)
{
	char baseCharacter = '0';
	char resultCharacter;

	if (value < 10)
	{
		resultCharacter = baseCharacter + value;
	}
	else // value >= 10
	{
		if (letterPolicy == LetterPolicy::LOWER_CASE)
		{
			baseCharacter = 'a';
		}
		else // letterPolicy == LetterPolicy::UPPER_CASE
		{
			baseCharacter = 'A';
		}
		resultCharacter = baseCharacter + value - 10;
	}
	return resultCharacter;
}

// TODO: Convert one digit in separate function?
// TODO: Need to add policy - LetterPolicy letterPolicy
LiteralBuffer inverted_converter(std::size_t arg, std::size_t base, LetterPolicy letterPolicy)
{
	// The builded base-valued base literal
	LiteralBuffer convertedLiteral;

	// The partial value (value of a single digit in a decimal base number system
	std::size_t decimalValue = base;
	std::size_t decimalModuloResult;
	char convertedCharModuloResult;

	while (decimalValue / base != 0)
	{
		// Get the modulo to calculate converted digit value
		decimalModuloResult = decimalValue % base;
		// Divide the value for next iteration
		decimalValue /= base;

		// Run the moduloResult through mapping converter
		convertedCharModuloResult = MapSingleDigit(decimalModuloResult, base, letterPolicy);

		convertedLiteral.Insert(convertedCharModuloResult);
	}
	// TODO: Far from ideal - repeates the code above!
	// Next dividing iteration would yield zero - put the last (first in significance) digit into
	// the convertedLiteral
	decimalModuloResult = decimalValue % base;
	// Run the moduloResult through mapping converter
	convertedCharModuloResult = MapSingleDigit(decimalModuloResult, base, letterPolicy);

	convertedLiteral.Insert(convertedCharModuloResult);

	convertedLiteral.Reverse();

	// Return the calculated number in base-std::size_t argument base numeral system
	return convertedLiteral;
}
