#!/bin/bash

cd ../../cpp || exit

#Compile C++ program
g++ -Iinclude -Iinclude/external src/*.cpp src/engine/*.cpp -o build/engine || exit
#Check for memory leak
valgrind --leak-check=full build/engine || exit
