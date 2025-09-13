@echo off
set OUT=autoclicker
set BUILD_DIR=build

if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
)

REM
set SRC=src\main.cpp src\choose.cpp src\Autocliker.cpp src\AutoclikerMenu.cpp

REM 
set INCLUDE_DIRS=-Iinclude

REM
g++ -std=c++17 %SRC% %INCLUDE_DIRS% -o %BUILD_DIR%\%OUT% -lncurses

IF %ERRORLEVEL% EQU 0 (
    echo Compilation successful. Output: %BUILD_DIR%\%OUT%
) ELSE (
    echo Compilation failed.
)
pause
