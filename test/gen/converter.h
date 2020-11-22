#ifndef CONVERTER_H
#define CONVERTER_H

#include <cstddef>

// Function returning std::size_t and taking c-string
// The return type is not guaranteed to be the largest representable type on a given platform
// size_t was decided, size_t is "large enough to contain the size in bytes of any object"
// Type larger than size_t could cause overflow or truncation on single-digit literal in product code
// The function argument 'char*' enables low-level, simple and efficient solution
std::size_t converter(char* arg);

#endif // #ifndef CONVERTER_H
