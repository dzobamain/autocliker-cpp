@echo off
set OUT=autoclicker.exe

REM Список файлів
set SRC=main.cpp choose.cpp Autocliker.cpp AutoclikerMenu.cpp

REM Компіляція
g++ -std=c++17 %SRC% -o %OUT% -lncursesw

IF %ERRORLEVEL% EQU 0 (
    echo Compilation successful. Output: %OUT%
) ELSE (
    echo Compilation failed.
)

pause
