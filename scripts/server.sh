#!/bin/bash
cd ../cpp || exit

#Compile C++ program
g++ -Iinclude -Iinclude/external src/*.cpp src/engine/*.cpp -o build/engine

echo
echo "Build Successful!"
echo "Starting Server..."
echo

#Run from server
cd ../node
node server.js
