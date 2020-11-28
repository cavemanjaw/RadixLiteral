#!/bin/bash
g++ main.cpp converter.cpp -std=c++11 -o test_gen -Wno-write-strings
#gcc converter.c main.c -lm -o test_gen
./test_gen > test_gen.h
