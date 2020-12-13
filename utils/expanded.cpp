# 1 "test/RadixLiteral.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 325 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "test/RadixLiteral.cpp" 2
# 1 "test/../src/RadixLiteral.h" 1
# 50 "test/../src/RadixLiteral.h"
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
# 106 "test/../src/RadixLiteral.h"
COMPILE_TIME_SPECIFIER RadixLiteral::size_t operator "" _z(unsigned long long arg)
{
 return arg;
}
# 130 "test/../src/RadixLiteral.h"
template<typename Data>
COMPILE_TIME_SPECIFIER Data pow(Data arg, int power)
{


   return power == 0 ? 1.0 : arg * pow(arg, power - 1);
}



template<unsigned base, char c>
COMPILE_TIME_SPECIFIER int bHelper()
{

   return (c - '0');
}


template<unsigned base, char c, char... tail, RadixLiteral::enable_if_t<(sizeof...(tail) > 0)>* = nullptr>

COMPILE_TIME_SPECIFIER int
bHelper()
{




   return c > '9' ?
     (c < 'Z' ?
              (c - 55) * pow(base, sizeof...(tail)) + bHelper<base, tail...>() :
       (c - 87) * pow(base, sizeof...(tail)) + bHelper<base, tail...>()) :
   ((c - 48) * pow(base, sizeof...(tail)) + bHelper<base, tail...>());
}
# 186 "test/../src/RadixLiteral.h"
COMPILE_TIME_SPECIFIER
int bHelper(const char* arg, RadixLiteral::size_t numeralSystem)
{





 char* charIter_p = (char*)arg;
 RadixLiteral::size_t stringLen = RadixLiteral::size_t{0};
 while (*charIter_p)
 {
  stringLen++;
  charIter_p++;
 }


 charIter_p = (char*)arg;


 RadixLiteral::size_t number = RadixLiteral::size_t{0};
 RadixLiteral::size_t exponent = stringLen - 1;

 while (*charIter_p)
 {




  unsigned charToIntOffset = 0;

  if (*charIter_p > '9')
  {




   if (*charIter_p < 'Z')
   {

    charToIntOffset = 55;
   }
   else
   {

    charToIntOffset = 87;
   }
  }
  else
  {

   charToIntOffset = 48;
  }






  number += ((int)(*charIter_p - (char)charToIntOffset)) * pow(numeralSystem, exponent--);





  charIter_p++;
 }


 return number;
}
# 2 "test/RadixLiteral.cpp" 2
# 12 "test/RadixLiteral.cpp"
# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/cassert" 1 3
# 42 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/cassert" 3

# 1 "/usr/include/assert.h" 1 3 4
# 35 "/usr/include/assert.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 345 "/usr/include/features.h" 3 4
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 346 "/usr/include/features.h" 2 3 4
# 367 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 410 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 411 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 368 "/usr/include/features.h" 2 3 4
# 391 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 392 "/usr/include/features.h" 2 3 4
# 36 "/usr/include/assert.h" 2 3 4
# 66 "/usr/include/assert.h" 3 4
extern "C" {


extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     throw () __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     throw () __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     throw () __attribute__ ((__noreturn__));


}
# 44 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/cassert" 2 3
# 13 "test/RadixLiteral.cpp" 2
# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/cstddef" 1 3
# 43 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/cstddef" 3

# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0/bits/c++config.h" 1 3
# 194 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0/bits/c++config.h" 3
namespace std
{
  typedef long unsigned int size_t;
  typedef long int ptrdiff_t;




}
# 216 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0/bits/c++config.h" 3
namespace std
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
namespace __gnu_cxx
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
# 482 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0/bits/c++config.h" 3
# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0/bits/os_defines.h" 1 3
# 483 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0/bits/c++config.h" 2 3


# 1 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0/bits/cpu_defines.h" 1 3
# 486 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0/bits/c++config.h" 2 3
# 45 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/cstddef" 2 3
# 1 "/usr/lib/llvm-3.8/bin/../lib/clang/3.8.0/include/stddef.h" 1 3
# 51 "/usr/lib/llvm-3.8/bin/../lib/clang/3.8.0/include/stddef.h" 3
typedef long int ptrdiff_t;
# 62 "/usr/lib/llvm-3.8/bin/../lib/clang/3.8.0/include/stddef.h" 3
typedef long unsigned int size_t;
# 46 "/usr/bin/../lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/cstddef" 2 3
# 14 "test/RadixLiteral.cpp" 2







template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b2() { return bHelper<((2)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b2(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (2)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b3() { return bHelper<((3)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b3(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (3)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b4() { return bHelper<((4)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b4(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (4)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b5() { return bHelper<((5)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b5(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (5)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b6() { return bHelper<((6)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b6(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (6)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b7() { return bHelper<((7)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b7(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (7)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b8() { return bHelper<((8)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b8(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (8)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b9() { return bHelper<((9)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b9(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (9)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b10() { return bHelper<((10)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b10(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (10)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b11() { return bHelper<((11)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b11(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (11)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b12() { return bHelper<((12)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b12(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (12)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b13() { return bHelper<((13)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b13(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (13)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b14() { return bHelper<((14)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b14(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (14)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b15() { return bHelper<((15)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b15(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (15)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b16() { return bHelper<((16)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b16(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (16)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b17() { return bHelper<((17)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b17(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (17)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b18() { return bHelper<((18)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b18(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (18)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b19() { return bHelper<((19)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b19(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (19)); };;
template<char... chars> COMPILE_TIME_SPECIFIER int operator"" _b20() { return bHelper<((20)), chars...>(); }; COMPILE_TIME_SPECIFIER int operator"" _b20(const char* arg, RadixLiteral::size_t) { return bHelper(arg, (20)); };;




# 1 "test/compile_time_tests.h" 1






static_assert(111_b2 == 7, "testBinary failed! 111_b2 != 7");
static_assert(231_b3 == 28, "testTernary failed! 231_b3 != 28");
static_assert(323_b4 == 59, "323_b4 != 59");
static_assert(324_b5 == 89, "324_b5 != 89");
static_assert(111_b15 == 241, "test15BaseOnlyDigits failed! 111_b15 != 241");
static_assert("ba1"_b15 == 2626, "test15BaseLowerCase failed! \"ba1\"_b15 != 2626");
static_assert("BA1"_b15 == 2626, "test15BaseUpperCase failed! \"BA1\"_b15 != 2626");
static_assert("1A1"_b15 == 376, "test15BaseDigitsAndLettersStartingDigits failed! \"1A1\"_b15 != 376");
# 44 "test/RadixLiteral.cpp" 2



constexpr bool testBinary()
{

   int value = 111_b2;

   ((("testBinary failed! 111_b != 7", value == 7)) ? static_cast<void> (0) : __assert_fail ("(\"testBinary failed! 111_b != 7\", value == 7)", "test/RadixLiteral.cpp", 52, __PRETTY_FUNCTION__));
   return true;
}

constexpr bool testTernary()
{

   int value = 231_b3;

   ((("testTernary failed! 231_b3 != 28", value == 28)) ? static_cast<void> (0) : __assert_fail ("(\"testTernary failed! 231_b3 != 28\", value == 28)", "test/RadixLiteral.cpp", 61, __PRETTY_FUNCTION__));
   return true;
}


constexpr
bool test15BaseLowerCase()
{




   int value = "ba1"_b15;




   ((("testBinary failed! BA1_b15 != 2626", value == 2626)) ? static_cast<void> (0) : __assert_fail ("(\"testBinary failed! BA1_b15 != 2626\", value == 2626)", "test/RadixLiteral.cpp", 78, __PRETTY_FUNCTION__));
   return true;
}

constexpr
bool test15BaseUpperCase()
{




   int value = "BA1"_b15;

   ((("testBinary failed! BA1_b15 != 2626", value == 2626)) ? static_cast<void> (0) : __assert_fail ("(\"testBinary failed! BA1_b15 != 2626\", value == 2626)", "test/RadixLiteral.cpp", 91, __PRETTY_FUNCTION__));
   return true;
}

constexpr bool test15BaseOnlyDigits()
{

   int value = 111_b15;
   ((("testBinary failed! 111_b15 != 241", value == 241)) ? static_cast<void> (0) : __assert_fail ("(\"testBinary failed! 111_b15 != 241\", value == 241)", "test/RadixLiteral.cpp", 99, __PRETTY_FUNCTION__));
   return true;
}

constexpr
bool test15BaseDigitsAndLettersStartingDigits()
{


   int value = "1A1"_b15;






   ((("testBinary failed! 1A1_b15 != 376", value == 376)) ? static_cast<void> (0) : __assert_fail ("(\"testBinary failed! 1A1_b15 != 376\", value == 376)", "test/RadixLiteral.cpp", 115, __PRETTY_FUNCTION__));
   return true;
}

static bool (*testFunction[6])() =
{
  &testBinary,
  &testTernary,
  &test15BaseLowerCase,
  &test15BaseUpperCase,
  &test15BaseOnlyDigits,
  &test15BaseDigitsAndLettersStartingDigits
};

static_assert(6 == sizeof(testFunction) / sizeof(testFunction[0]),
     "Number of tests is not equal to the test array size!");



constexpr void runAllTests()
{
 for (std::size_t test = 0_z; test < 6; test++)
 {
  (*testFunction[test]);
 }
}
# 156 "test/RadixLiteral.cpp"
int main()
{

 runAllTests();




   (void)testBinary();
   (void)testTernary();

   (void)test15BaseUpperCase();
   (void)test15BaseLowerCase();

   (void)test15BaseOnlyDigits();
   (void)test15BaseDigitsAndLettersStartingDigits();



   return 0;
}
