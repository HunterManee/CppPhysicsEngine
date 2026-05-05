#!/bin/bash

# Exit immediately on error
set -e

# Go to cpp directory relative to this script
cd "$(dirname "$0")/../cpp"

# Ensure build folder exists
mkdir -p build

# Compile (clang is default on macOS)
clang++ src/*.cpp -Iinclude -Iinclude/external -std=c++17 -O2 -o build/sim

echo
echo "Build successful!"
echo "Running program..."
echo

# Run
./build/sim