@echo off

cd ../../cpp
mkdir build

REM compile c++ program
g++ -Iinclude -Iinclude/external src/*.cpp src/engine/*.cpp -o build/engine.exe

echo.
echo Build Successful!
echo Running Program...
echo.

REM Run executable
cd ..\scripts\windows
..\..\cpp\build\engine.exe

