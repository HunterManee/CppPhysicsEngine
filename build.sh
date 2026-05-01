#!/bin/bash

# Compile
clang++ src/*.cpp -Iinclude -o engine.out

# Check if compilation failed
if [ $? -ne 0 ]; then
    echo "Build failed."
    exit $?
fi

echo
echo "Build successful!"
echo "Running program..."
echo

# Run the program
./engine.out