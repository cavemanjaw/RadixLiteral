#include "converter.h"

// TODO: Temporary to get pow()
#include <math.h>

// TODO: Implement tailored pow()

// Based on ASCII table
#define CHAR_TO_INT_NUMBER_OFFSET 48
#define CHAR_TO_INT_LOWER_CASE_OFFSET 55
#define CHAR_TO_INT_UPPER_CASE_OFFSET 87

// TODO: Convert one digit in separate function?
size_t converter(char* arg, size_t base)
{
	// Calculate the length of c-string
	char* charIter_p = (char*)arg;
	size_t stringLen = (size_t)0; // Construct the size_t variable to avoid implicit casting
	while (*charIter_p)
	{
		stringLen++;
		charIter_p++;
	}

	// Reassign charIter_p to point to the beginning of c-string
	charIter_p = (char*)arg;

	size_t number = (size_t)0;
	size_t exponent = stringLen - 1;

	while (*charIter_p)
	{
		char charToIntOffset = 0;

		if (*charIter_p > '9')
		{
			if (*charIter_p < 'Z')
			{
				charToIntOffset = CHAR_TO_INT_LOWER_CASE_OFFSET;
			}
			else
			{
				charToIntOffset = CHAR_TO_INT_UPPER_CASE_OFFSET;
			}
		}
		else
		{
			charToIntOffset = CHAR_TO_INT_NUMBER_OFFSET; // The same as charToIntOffset = (char)('0')
		}

		number += ((size_t)
		  (*charIter_p - charToIntOffset)) * pow(base, exponent--);

		charIter_p++;
	}

	// Return the calculated number in base-10 numeral system
	return number;
}




