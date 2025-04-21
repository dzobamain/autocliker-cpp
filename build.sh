#!/bin/bash

OUT="autoclicker"

SRC=$(find . -name "*.cpp")

g++ -std=c++11 $SRC -o $OUT -framework ApplicationServices -lncurses
