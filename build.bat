@echo off
g++ src/*.cpp -Iinclude -o build/engine.exe

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

echo.
echo Build successful!
echo Running program...
echo.

build\engine.exe