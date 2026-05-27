#!/bin/bash
cd ../../cpp || exit
mkdir -p build

#Compile C++ program
g++ -Iinclude -Iinclude/external src/*.cpp src/engine/*.cpp -o build/engine || exit

echo
echo "Build Successful!"
echo "Running Program.."
echo

#Run from terminal
./build/engine || exit

