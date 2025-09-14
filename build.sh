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
    src/lang.cpp
)

INCLUDE_DIRS=(-Iinclude)

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

g++ -std=c++17 "${SRC[@]}" "${INCLUDE_DIRS[@]}" -o "$BUILD_DIR/$OUT" -lncurses -framework ApplicationServices

if [ $? -eq 0 ]; then
    echo -e "${GREEN}Compilation successful. Output: $BUILD_DIR/$OUT${NC}"
else
    echo -e "${RED}Compilation failed.${NC}"
fi
