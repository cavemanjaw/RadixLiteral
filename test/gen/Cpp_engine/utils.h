#ifndef UTILS_H
#define UTILS_H

#include <climits>

enum class LetterPolicy
{
	LOWER_CASE,
	UPPER_CASE
};

//
//enum class TestStrategy
//{
//	PICKY_TEST,
//	ALL_TEST,
//  ESSENTIAL_TEST
//  BOUNDARY_CONDITION_TEST
//
//};
enum class TestingPolicy
{
	ALL_TEST,
	RANDOM_TEST
};


// For C++20 can be consteval
constexpr
std::size_t BufferSize()
{
	// std::size_t bytes times the amount of bits in a byte plus one for NULL character
	return sizeof(std::size_t) * (std::size_t)(CHAR_BIT) + std::size_t{1};
}


#endif // #ifndef UTILS_H
