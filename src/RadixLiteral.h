// Implementation of user-defined literals for different base number literals

#ifndef RADIX_LITERAL_H
#define RADIX_LITERAL_H

#if __cplusplus >= 201402L // if C++14
// Relaxed limitations on constexpr functions evaluated at compile time
#else
// constexpr evaluation in compile time has some restrictions
// TODO: Other implementation needed for literals that use letters as "digits"
// std::enable_if_t not available, could be easily typedefed with an enabler and enable_if (I think...)
// static_assert tests using past-10 letter-using literals will fail
#endif // #if __cplusplus >= 201402L // if C++14

// Reimplement type_traits for smaller binaries size when this header is included
// (probably true, at least in a portion of cases)
// TODO: std::size_t depends on it
//#include <type_traits> // for enable_if, TODO: Any other option to disambiguate the template function call?
//#define _b(numeral_system)
// For std::size_t, probably the most lightweight header that does not declare any function
// could be made also with using size_type = decltype(alignof(char)); since standard imposes the return
// type of sizeof, sizeof... and alignof to be std::size_t
//#include <cstddef>

namespace RadixLiteral
{
   template<bool B, class T = void>
   struct enable_if {};

   template<class T>
   struct enable_if<true, T> {typedef T type;};

   template<bool B, class T = void>
   using enable_if_t = typename enable_if<B,T>::type;

   using size_t = decltype(alignof(char));
}

//#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

#define CHAR_TO_INT_NUMBER_OFFSET 48
#define CHAR_TO_INT_LOWER_CASE_OFFSET 55
#define CHAR_TO_INT_UPPER_CASE_OFFSET 87

//// To satisfy enable_if interface, could be anything and won't be used
//enum class enabler_t {};
//template<typename T>
//using EnableIf = typename std::enable_if<T::value, enabler_t>::type;

// TODO: OPERATOR_LITERAL() that wraps OPERATOR_LITERAL10(15); and OPERATOR_LITERAL(15);
// TODO: Then try to unify that solution into one macro

#define NUMERAL_SYSTEM(numeral_system) \
	OPERATOR_LITERAL_internal(numeral_system); \
	OPERATOR_LITERAL10_internal(numeral_system); \

// TODO: If the token is more than 10-based then use the operator""(const char* arg, std::size_t n)
#define OPERATOR_LITERAL_internal(numeral_system) \
	template<char... chars> \
	constexpr int operator"" _b##numeral_system() \
	{ \
	return bHelper<((numeral_system)), chars...>(); \
	}

// TODO: The whole mechanism (macro-based) for literals containing letters
// IMPORTANT: Is for case of "1A1"_b15;
#define OPERATOR_LITERAL10_internal(numeral_system) \
		constexpr int operator"" _b##numeral_system(const char* arg, RadixLiteral::size_t) \
		{ \
		return bHelper(arg, (numeral_system)); \
		}

// TODO: Macros for enabling specific features if compiled with different versions of C++ standard
// TODO: Iterative version (can work for C++14 and beyond)

// For having the literal for std::size_t objects
constexpr RadixLiteral::size_t operator "" _z(unsigned long long arg)
{
	return arg;
}

// PROGRAM DESCRIPTION
// Use cases:
// 231_b4 -> operator""_b4<2, 3, 1>() -> 2*4^2 + 3*4^1 + 1*4^0
// 254_b6 -> operator""_b6<2, 5, 4>()
// 457_b7 -> operator""_b7<4, 5, 7>() -> should cause static_assert or some safety mechanism, not SFINAE

// Define every of 0-9 numeric system implementations of just enable if it is used?
// This could be guarded by additional #define which could decide what range of available numeric systems should
// be generated by the preprocessor. Do it with a macro loop? Or switch case? Or it could be somehow be driven by the usage of the literal?

// Taking template parameter pack of non-type template arguments of type char
// Variadic tamplate needed probably only for C++11 standard to assign meaning for the values of digits (because of no loops, no 'if' statements, but recursion possible etc.) 
// No non-constexpr version needed, user-defined literals were introduced in C++11, the same standard as for constexpr

// TODO: Any macro magic to change the _b3 to, for example, _b6 in case of senary based system?
// Need to just replace the hardcoded number in literal suffix and implementation
// Introduce macro for literal replacing and second template argument for the numeric system?
// Introduce the least amount of macro substitution - only in operator""() implementation?

template<typename Data> // TODO: Artificial constrains on the types that this template could be instantiated with?
constexpr Data pow(Data arg, int power)
{  
   // Only arithmetic types possible - how to deal with possible conversions and so on? How to deal with returning 1.0?
   // Could be done in one template or template partial specialization would be needed?
   return power == 0 ? 1.0 : arg * pow(arg, power - 1); // TODO: Swap the actual calculations with base case for more efficiency? Mark calc more likely?
}

// TODO: Ambiguous call in case of one template parameter - disambiguation presently done with enable_if(tail > 0)
// Base case for variadic template - a helper function
template<unsigned base, char c>
constexpr int bHelper() // No function to match in case of ambiguous call without enable_if
{
   // TODO: static_assert or other kind of check
   return (c - '0'); // TODO: Conversion from char to int is needed to give meaningful result? Or ASCII cares about it? Can this be instantiated with modified char template argment on the caller side?
}

//std::enable_if_t<std::is_integral<T>::value>* = nullptr
template<unsigned base, char c, char... tail, RadixLiteral::enable_if_t<(sizeof...(tail) > 0)>* = nullptr> //std::enable_if<(sizeof...(tail) > 0)>* = nullptr> // TODO: Analyze, template template argument?
//typename std::enable_if<(sizeof...(tail) > 0), int>::type // TODO: Will that return a constexpr qualified int 'constexpr int'?
constexpr int
bHelper()
{
   // In later C++ standards:
   // constexpr if (sizeof.. (tail)) > 0 call this function
   // else call <unsigned, char> bHelper
   // TODO: Assert or other check // TODO: Make a macro or a function out of the common part of the expression
   return c > '9' ?
	    (c < 'Z' ?
              (c - CHAR_TO_INT_LOWER_CASE_OFFSET) * pow(base, sizeof...(tail)) + bHelper<base, tail...>() :
	      (c - CHAR_TO_INT_UPPER_CASE_OFFSET) * pow(base, sizeof...(tail)) + bHelper<base, tail...>()) :
	  ((c - CHAR_TO_INT_NUMBER_OFFSET) * pow(base, sizeof...(tail)) + bHelper<base, tail...>()); // TODO: (c-'0') would get the actual int representation
} //TODO: This would be called recursively - but no problem with char interpretation - lower base systems just won't have any letters

// TODO: Generalize with a macro printing a proper version of this function and introduce additional
//       template parameter substituted with the macro arg?
//template<char... chars> // At this point it should be a macro
//constexpr int operator"" _b3()
//{
//   return bHelper<chars...>();
//}

//OPERATOR_LITERAL(3);
//OPERATOR_LITERAL(5);

//#define OPERATOR_LITERAL(numeral_system) \
//		template<char... chars> \
//		constexpr int operator"" _b##numeral_system() \
//		{ \
//		   return bHelper<chars..., (numeral_system)>(); \
//		}

// TODO: For tests of 15-base system
//template<char... chars>

// TODO: Argument for numeral system (the base)
constexpr
int bHelper(const char* arg, RadixLiteral::size_t numeralSystem)
{
	#ifdef DEBUG
	std::cout << "Calling b15Helper()\n";
	#endif

	// Calculate the length of c-string
	char* charIter_p = (char*)arg;
	RadixLiteral::size_t stringLen = RadixLiteral::size_t{0}; // Construct the size_t variable to avoid implicit casting
	while (*charIter_p)
	{
		stringLen++;
		charIter_p++;
	}

	// Reassign charIter_p to point to the beginning of c-string
	charIter_p = (char*)arg;

	// Currently calling templated pow(), so the chosen instantiation of pow depends on the type of this var
	RadixLiteral::size_t number = RadixLiteral::size_t{0};
	RadixLiteral::size_t exponent = stringLen - 1;

	while (*charIter_p)
	{
		// pow() currently is also returning int type
		// TODO: Should be different for letters!

		// TODO: Initialized only to satisfy the compiler at this point
		unsigned charToIntOffset = 0; // Only one byte needed - needed is the size of storage equal to the capacity of char

		if (*charIter_p > '9')
		{
			#ifdef DEBUG
			std::cout << (int)*charIter_p << "\n";
			#endif

			if (*charIter_p < 'Z')
			{
				//CHAR_TO_INT_LOWER_CASE_OFFSET
				charToIntOffset = CHAR_TO_INT_LOWER_CASE_OFFSET;
			}
			else
			{
				//CHAR_TO_INT_UPPER_CASE_OFFSET
				charToIntOffset = CHAR_TO_INT_UPPER_CASE_OFFSET;
			}
		}
		else
		{
			//CHAR_TO_INT_NUMBER_OFFSET
			charToIntOffset = CHAR_TO_INT_NUMBER_OFFSET; // The same as charToIntOffset = (char)('0')
		}

		#ifdef DEBUG
		std::cout << "offset: " << charToIntOffset << "\n";
		std::cout << "exponent: " << exponent << "\n";
		#endif

		number += ((int)(*charIter_p - (char)charToIntOffset)) * pow(numeralSystem, exponent--);

		#ifdef DEBUG
		std::cout << "number: " << number << "\n";
		#endif

		charIter_p++;
	}

	// Return the calculated number in base-10 numeral system
	return number;
}

// TODO: The whole mechanism (macro-based) for literals containing letters
// IMPORTANT: Is for case of "1A1"_b15;

//constexpr
//int operator"" _b15(const char* arg, std::size_t n)
//{
//	return b15Helper(arg); // TODO: Take base numeral value of numeral system
//}

#endif // #ifndef RADIX_LITERAL_H
