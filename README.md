# RadixLiteral
RadixLiteral is header-only library implementing custom numeric system literal suffixes.

# Usage
For example usage run compile script with RadixLiteral argument:
```bash
./compile RadixLiteral

For use in client application - include the src/RadixLiteral.h header to your project and define the numeral system you want to use in your literals by defining following macro:
```c
OPERATOR_LITERAL(numeric_system);

For example for base-4 numeric system literals:
```c
OPERATOR_LITERAL(4);

Then you can use custom numeric system literals in your code, for example:
```c
312_b4 
