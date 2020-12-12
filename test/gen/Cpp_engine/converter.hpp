#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <cstddef>

// Function returning std::size_t and taking c-string
// The return type is not guaranteed to be the largest representable type on a given platform
// size_t was decided, size_t is "large enough to contain the size in bytes of any object"
// Type larger than size_t could cause overflow or truncation on single-digit literal in product code
// The function argument 'char*' enables low-level, simple and efficient solution

// Converts a const char* c-style string (first argument), which is a representation of a numeral literal
// in a a non-10 valued base of numeral system (the second argument)
// to std::size_t typed decimal number (the return value)
std::size_t converter(const char* arg, std::size_t base);

#endif // #ifndef CONVERTER_HPP
