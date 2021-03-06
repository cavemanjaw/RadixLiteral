# RadixLiteral
RadixLiteral is header-only library implementing custom numeral system literal suffixes.

# Usage
For example usage and build tests run compile script:
```bash
./compile
```
It will build RadixLiteral and RadixLiteral_clang binaries (for g++ and Clang respectively). You can make use of appending ``` -g ``` flag to the command for builing debug target.


For use in client application - include the src/RadixLiteral.h header to your project and define the numeral system you want to use in your literals by defining following macro:
```c
NUMERAL_SYSTEM(numeral_system_base);
```

For example for base-4 numeric system literals:
```c
NUMERAL_SYSTEM(4);
```

Then you can use custom numeric system literals in your code, for example:
```c
312_b4 
```

For past 10-based numeral systems there is a limitation - you'll need to surround the desired value with quotation marks ```""```, similarly like when defining a string, for example:
```c
"3A1"_15
```
