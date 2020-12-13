#ifndef INVERTED_CONVERTER_HPP
#define INVERTED_CONVERTER_HPP

#include <cstddef>
#include "utils.hpp"

// Function returning LiteralBuffer (convertible to std::string) and taking std::size_t as and argument

// size_t was decided, size_t is "large enough to contain the size in bytes of any object"
// Type larger than size_t could cause overflow or truncation on single-digit literal in product code

// Converts a std::size_t arg (first argument), which is a representation of a base-10 number
// to a LiteralBuffer object (the return value) containing converted base-10 number to a arbitrary
// base number (second argument)
LiteralBuffer inverted_converter(std::size_t arg, std::size_t base, LetterPolicy letterPolicy);

#endif // #ifndef INVERTED_CONVERTER_HPP
