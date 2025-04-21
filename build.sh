#!/bin/bash

OUT="autoclicker"

SRC=$(find . -name "*.cpp")

g++ -std=c++11 $SRC -o $OUT -lncurses

if [ $? -eq 0 ]; then
    echo "Compilation successful. Output: $OUT"
else
    echo "Compilation failed."
fi
