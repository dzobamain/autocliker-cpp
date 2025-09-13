#!/bin/bash

OUT="autoclicker"

SRC=(
    main.cpp
    choose.cpp
    Autocliker.cpp
    AutoclikerMenu.cpp
)

g++ -std=c++17 "${SRC[@]}" -o "$OUT" -lncurses -framework ApplicationServices

if [ $? -eq 0 ]; then
    echo "Compilation successful. Output: $OUT"
else
    echo "Compilation failed."
fi
