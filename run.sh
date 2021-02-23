#!/bin/bash

echo "Compiling all .cpp files"
g++ -Wall -std=c++17 *.cpp -o proj1.out

echo "Run the program"
./proj1.out

echo "Showing the output"
cat output.txt
