#!/bin/bash

OUT="autoclicker"
BUILD_DIR="build"

mkdir -p "$BUILD_DIR"

SRC=(
    src/main.cpp
    src/choose.cpp
    src/Autocliker.cpp
    src/AutoclikerMenu.cpp
    src/settings.cpp
)

INCLUDE_DIRS=(
    -Iinclude
)

g++ -std=c++17 "${SRC[@]}" "${INCLUDE_DIRS[@]}" -o "$BUILD_DIR/$OUT" -lncurses -framework ApplicationServices

if [ $? -eq 0 ]; then
    echo "Compilation successful. Output: $BUILD_DIR/$OUT"
else
    echo "Compilation failed."
fi
