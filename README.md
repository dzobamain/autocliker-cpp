# Concole - Autocliker 🎯

## Description

**Autocliker** — a simple and fun console auto-clicker for your PC! 🖱️  
It allows you to configure:

- Number of clicks  
- Delay between clicks  
- Click execution time  
- Time before start ⏱️  

For now, the auto-clicker only works at the cursor position, but don’t worry — it’s easy to extend and add your own functionality in the future! 🚀  

Supported platforms: **Windows, macOS, Linux** 💻

---

## Currently Implemented ✅

- Clicks at cursor position 🖱️  

*(More features will be added here in the future… stay tuned!)*

---

## Installation Guide 🛠️

<p align="center">
    <a href="https://gcc.gnu.org/">
        <img src="https://img.shields.io/badge/install-gcc-blue" alt="gcc">
    </a>
    <a href="https://invisible-island.net/ncurses/">
        <img src="https://img.shields.io/badge/install-ncurses-orange" alt="ncurses">
    </a>
    <a href="https://git-scm.com/">
        <img src="https://img.shields.io/badge/install-git-red" alt="git">
    </a>
</p>

1. Install **gcc**  
    - [GCC Official](https://gcc.gnu.org/)  
    - Linux: 
      ```bash
      sudo apt install build-essential
      ```
    - macOS: 
      ```bash
      brew install gcc
      ```
    - Windows (MSYS2):
      ```bash
      pacman -S mingw-w64-ucrt-x86_64-gcc
      ```

2. Install the **ncurses** library  
    - [Ncurses Official](https://invisible-island.net/ncurses/)  
    - Linux:
      ```bash
      sudo apt install libncurses5-dev libncursesw5-dev
      ```
    - macOS:
      ```bash
      brew install ncurses
      ```
    - Windows (MSYS2):
      ```bash
      pacman -S mingw-w64-ucrt-x86_64-ncurses
      ```

3. Clone the project:
    ```bash
    git clone https://github.com/dzobamain/autocliker-cpp
    cd autocliker-cpp
    ```

---

## Compilation and Running 🚀

### Linux/macOS

The compiled file will be created in the `build/` folder 🎉

```bash
./build.sh
./build/autoclicker
```

### Windows

The compiled file will be created in the build\ folder 🎉

```
build.bat
build\autoclicker.exe
```
