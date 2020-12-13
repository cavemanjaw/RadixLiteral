#include "../src/RadixLiteral.h"


// OPTIONAL DEBUG DEFINE
//#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

// Temporarily defined for run-time assertion
#include <cassert>
#include <cstddef>

#ifdef DEBUG
#endif

#define NUM_OF_TESTS 6

// for loop equivalent for printing the n number of lines of NUMERAL_SYSTEM(n);
NUMERAL_SYSTEM(2);
NUMERAL_SYSTEM(3);
NUMERAL_SYSTEM(4);
NUMERAL_SYSTEM(5);
NUMERAL_SYSTEM(6);
NUMERAL_SYSTEM(7);
NUMERAL_SYSTEM(8);
NUMERAL_SYSTEM(9);
NUMERAL_SYSTEM(10);
NUMERAL_SYSTEM(11);
NUMERAL_SYSTEM(12);
NUMERAL_SYSTEM(13);
NUMERAL_SYSTEM(14);
NUMERAL_SYSTEM(15);
NUMERAL_SYSTEM(16);
NUMERAL_SYSTEM(17);
NUMERAL_SYSTEM(18);
NUMERAL_SYSTEM(19);
NUMERAL_SYSTEM(20);


// TODO: Requires NUMERAL_SYSTEM(x) to be defined, so it is here, below NUMERAL_SYSTEM definitions
#include "compile_time_tests.h"

// TODO: Automatically generated test inclusion
#include "gen/test_gen.h"

// TODO: Stress and check the boundary conditions NUMERAL_SYSTEM(INT_MAX); and so on...

constexpr bool testBinary()
{
   //constexpr
   int value = 111_b2;
   //static_assert(value == 7, "testBinary failed! 111_b != 7");
   assert(("testBinary failed! 111_b != 7", value == 7));
   return true;
}

constexpr bool testTernary()
{
   //constexpr
   int value = 231_b3;
   //static_assert(value == 28, "testTernary failed! 231_b3 != 28");
   assert(("testTernary failed! 231_b3 != 28", value == 28));
   return true;
}

// TODO: operator"" taking different type of argument is needed
constexpr
bool test15BaseLowerCase()
{
	#ifdef DEBUG
	std::cout << "CALLING LOWER:\n";
	#endif
   //constexpr
   int value = "ba1"_b15;
   #ifdef DEBUG
   std::cout << value << "\n";
   #endif
   //static_assert(value == 2626, "testBinary failed! ba1_b15 != 2626");
   assert(("testBinary failed! BA1_b15 != 2626", value == 2626));
   return true;
}

constexpr
bool test15BaseUpperCase()
{
	#ifdef DEBUG
	std::cout << "CALLING UPPER:\n";
	#endif
	//constexpr
   int value = "BA1"_b15;
   //static_assert(value == 2626, "testBinary failed! BA1_b15 != 2626");
   assert(("testBinary failed! BA1_b15 != 2626", value == 2626));
   return true;
}

constexpr bool test15BaseOnlyDigits()
{
   //constexpr
   int value = 111_b15;
   assert(("testBinary failed! 111_b15 != 241", value == 241));
   return true;
}

constexpr
bool test15BaseDigitsAndLettersStartingDigits()
{
   // TODO: Test and debug with a macro - containing the static_assert and std::cout
   //constexpr
   int value = "1A1"_b15;

   #ifdef DEBUG
   std::cout << value << "\n";
   #endif

   //static_assert(value == 2626, "testBinary failed! BA1_b15 != 2626");
   assert(("testBinary failed! 1A1_b15 != 376", value == 376));
   return true;
}

static bool (*testFunction[NUM_OF_TESTS])() =
{
		&testBinary,
		&testTernary,
		&test15BaseLowerCase,
		&test15BaseUpperCase,
		&test15BaseOnlyDigits,
		&test15BaseDigitsAndLettersStartingDigits
};

static_assert(NUM_OF_TESTS == sizeof(testFunction) / sizeof(testFunction[0]),
			  "Number of tests is not equal to the test array size!");

// TODO: For C++11 not possible to invoke tests - 'for' loop in the body of the function
// TODO: Just a fun done with std::vector
constexpr void runAllTests()
{
	for (std::size_t test = 0_z; test < NUM_OF_TESTS; test++)
	{
		(*testFunction[test]);
	}
}

//constexpr bool test15BaseDigitsAndLettersStartingLetters()
//{
//   //constexpr
//   int value = A11_b15;
//   #ifdef DEBUG
//   std::cout << value;
//   #endif
//   //static_assert(value == 2626, "testBinary failed! BA1_b15 != 2626");
//   assert(("testBinary failed! 111_b15 != 2626", value == 241));
//   return true;
//}


// TODO: Remove main and rely only on compile-time checks?
int main()
{
	// Run the tests!
	runAllTests();

	//TODO: The number of defined functions should equal the number of calls down here

   //Run run-time tests
   (void)testBinary();
   (void)testTernary();

   (void)test15BaseUpperCase();
   (void)test15BaseLowerCase(); // TODO: Lower case is not working currently

   (void)test15BaseOnlyDigits();
   (void)test15BaseDigitsAndLettersStartingDigits();

   //std::cout << 344_b3;
   //std::cout << 5_b5;
   return 0;
}

