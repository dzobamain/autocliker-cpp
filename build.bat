@echo off

set OUT=autoclicker.exe

set SRC=
for /R %%f in (*.cpp) do (
    set SRC=!SRC! "%%f"
)

g++ -std=c++11 %SRC% -o %OUT% -lncurses

if %ERRORLEVEL%==0 (
    echo Compilation successful. Output: %OUT%
) else (
    echo Compilation failed.
)

pause

