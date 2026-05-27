#!/bin/bash
cd ../../cpp || exit
mkdir -p build

#Compile C++ program
clang++ -Iinclude -Iinclude/external src/*.cpp src/engine/*.cpp -o build/engine || exit

echo
echo "Build Successful!"
echo "Starting Server..."
echo

#Run from server
cd ../node || exit
node server.js
