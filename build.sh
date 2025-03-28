#!/bin/bash

OUT="autoclicker"

g++ -std=c++11 main.cpp -o $OUT -framework ApplicationServices -lncurses

echo "Build complete. Executable is: $OUT"
