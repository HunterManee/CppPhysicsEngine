@echo off

cd /d %~dp0\..\cpp

g++ src/*.cpp -Iinclude -Iinclude/external -o build/sim.exe

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

echo.
echo Build successful!
echo Running program...
echo.

build\sim.exe

cd /d %~dp0\..\scripts