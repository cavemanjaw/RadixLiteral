#include "../src/RadixLiteral.h"
#include <iostream>

// Temporarily defined for run-time assertion
#include <cassert>

OPERATOR_LITERAL(3);
OPERATOR_LITERAL(5);
OPERATOR_LITERAL(2);
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

//// TODO: operator"" taking different type of argument is needed
//constexpr bool test15BaseLowerCase()
//{
//   //constexpr
//   int value = ba1_b15;
//   //static_assert(value == 2626, "testBinary failed! ba1_b15 != 2626");
//   assert(("testBinary failed! BA1_b15 != 2626", value == 2626));
//   return true;
//}
//
//constexpr bool test15BaseUpperCase()
//{
//   //constexpr
//   int value = BA1_b15;
//   //static_assert(value == 2626, "testBinary failed! BA1_b15 != 2626");
//   assert(("testBinary failed! BA1_b15 != 2626", value == 2626));
//   return true;
//}

constexpr bool test15BaseOnlyDigits()
{
   //constexpr
   int value = 111_b15;
   //static_assert(value == 2626, "testBinary failed! BA1_b15 != 2626");
   assert(("testBinary failed! 111_b15 != 2626", value == 241));
   return true;
}

// TODO: Remove main and rely only on compile-time checks?
int main()
{
   //Run run-time tests
   (void)testBinary();
   (void)testTernary();
   (void)test15BaseOnlyDigits();

   //std::cout << 344_b3;
   //std::cout << 5_b5;
   return 0;
}

