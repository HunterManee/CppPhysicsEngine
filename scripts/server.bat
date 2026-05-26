@echo off

cd ../cpp

REM compile c++ program
g++ -Iinclude -Iinclude/external src/*.cpp src/engine/*.cpp -o build/engine.exe

echo.
echo Build Successful!
echo Starting Server...
echo.

REM start server
cd ../scripts
node ../node/server.js
