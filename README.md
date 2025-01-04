# Autocliker for MacOS.cpp
## Installation Guide

1. Install **Homebrew**
   + https://brew.sh/
   + ```/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"```
2. Install **gcc**
    + https://gcc.gnu.org/
    + ```bash brew install gcc```
3. Install **ncurses** library
    + https://invisible-island.net/ncurses/
    + ```brew install ncurses```
4. Install **Autocliker_for_MacOS_cpp**
    1. ```git clone https://github.com/Dzobamain/Autocliker_for_MacOS_cpp.git```
    2. ```cd Autocliker_for_MacOS_cpp```
   
## How to Compile

Code Compilation (Console)
```
g++ main.cpp -o AutoClicker -framework ApplicationServices -lncurses -std=c++11
```
"AutoClicker" can be changed; it is the name of the compiled code  

Running the program
```
./AutoClicker
````




