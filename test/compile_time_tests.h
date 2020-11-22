#ifndef COMPILE_TIME_TESTS_H
#define COMPILE_TIME_TESTS_H

// TODO: Stress and check the boundary conditions NUMERAL_SYSTEM(INT_MAX); and so on...

//STATIC, COMPILE-TIME TESTS:
static_assert(111_b2 == 7, "testBinary failed! 111_b2 != 7");
static_assert(231_b3 == 28, "testTernary failed! 231_b3 != 28");
static_assert(323_b4 == 59, "323_b4 != 59");
static_assert(324_b5 == 89, "324_b5 != 89");
static_assert(111_b15 == 241, "test15BaseOnlyDigits failed! 111_b15 != 241");
static_assert("ba1"_b15 == 2626, "test15BaseLowerCase failed! \"ba1\"_b15 != 2626");
static_assert("BA1"_b15 == 2626, "test15BaseUpperCase failed! \"BA1\"_b15 != 2626");
static_assert("1A1"_b15 == 376, "test15BaseDigitsAndLettersStartingDigits failed! \"1A1\"_b15 != 376");

#endif // #ifndef COMPILE_TIME_TESTS_H
