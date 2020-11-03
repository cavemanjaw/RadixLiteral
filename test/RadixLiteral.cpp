#include "../src/RadixLiteral.h"
#include <iostream>

OPERATOR_LITERAL(3);
OPERATOR_LITERAL(5);
OPERATOR_LITERAL(2);

//constexpr bool testBinary()
//{
//   constexpr int value = 111_b2;
//   static_assert(value == 7, "testBinary failed! 111_b != 7");
//}

// TODO: Remove main and rely only on compile-time checks?
int main()
{
   std::cout << 344_b3;
   std::cout << 5_b5;
   return 0;
}

