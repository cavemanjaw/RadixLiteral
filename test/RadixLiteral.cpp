#include "../src/RadixLiteral.h"

// OPTIONAL DEBUG DEFINE
//#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

// Temporarily defined for run-time assertion
#include <cassert>



#ifdef DEBUG
#endif

OPERATOR_LITERAL(3);
OPERATOR_LITERAL(5);
OPERATOR_LITERAL(2);

// IMPORTANT: Is for the case of 111_b15;
OPERATOR_LITERAL(15);

//constexpr bool testBinary()
//{
//   constexpr int value = 111_b2;
//   static_assert(value == 7, "testBinary failed! 111_b != 7");
//}

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
//constexpr
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

//constexpr
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

//constexpr
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

