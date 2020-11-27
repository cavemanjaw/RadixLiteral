#!/bin/bash
g++ main.cpp converter.cpp -g  -std=c++11 -o test_gen
./test_gen > test_gen.h
