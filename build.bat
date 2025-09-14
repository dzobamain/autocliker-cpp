@echo off
set OUT=autoclicker.exe
set BUILD_DIR=build

if not exist %BUILD_DIR% mkdir %BUILD_DIR%

set SRC=src\main.cpp src\choose.cpp src\Autocliker.cpp src\AutoclikerMenu.cpp src\settings.cpp src\lang.cpp
set INCLUDE=-Iinclude

echo Compiling...

g++ -std=c++17 %SRC% %INCLUDE% -o %BUILD_DIR%\%OUT% -lncurses

if %ERRORLEVEL% equ 0 (
    echo Compilation successful. Output: %BUILD_DIR%\%OUT%
) else (
    echo Compilation failed.
)
pause
