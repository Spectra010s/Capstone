# Installation / Setup of C++ Compiler

## Overview

To run C++ programs, you need a C++ compiler installed on your system:

- **Termux (Android)** → clang
- **Windows** → MinGW-w64 or Visual Studio Build Tools
- **macOS** → clang (via Xcode tools)
- **Linux** → g++ (via apt/dnf/pacman)

---

## Below are the commands for:

- Termux (Android)

- Windows

- macOS

- Linux (Ubuntu/Debian, Fedora, Arch)

---

1. Termux (Android)

Termux uses the clang compiler.

```bash
pkg update && pkg upgrade
pkg install clang
```

Check version:

```
clang --version
```

Compile C++:

```
clang++ file.cpp -o output
./output
```

---

2.  Windows

## On Windows, you have two major options:

Option A: Install MinGW (most common)

Download MinGW-w64 from MSYS2 (best version):

1. Install MSYS2 from: https://www.msys2.org

2. Then open MSYS2 MINGW64 terminal and run:

```bash
pacman -Syu
```

> Note: This command is crucial. It updates the MSYS2 core system packages before installing the compiler, preventing potential conflicts or errors with the newer compiler packages. If the terminal closes after running this, restart it and run the command again until it completes without closing.

3.​Install the MinGW-w64 GCC compiler:

```
pacman -S mingw-w64-x86_64-gcc
```

4. Add Compiler to System PATH (Highly Recommended)

> The path variable allows you to run g++ from any Windows terminal (like Command Prompt or PowerShell), not just the MSYS2 terminal.

**Path to Add:**

```
C:\msys64\mingw64\bin
```

(This path assumes you used the default installation location.)

**How to Add:** Search for "Edit the system environment variables" in the Windows Start Menu, click the Environment Variables... button, find the Path variable under System variables, and add the directory above.

---

Compile C++:

g++ file.cpp -o output.exe

Run:

```bash
./output.exe
```

---

Option B: Install Visual Studio Build Tools

1. Download: "Build Tools for Visual Studio"

2. Choose C++ Desktop Development

Then compile using:

```
cl file.cpp
```

---

3. macOS

> macOS uses Apple’s clang.

Just run:

```
xcode-select --install
```

This installs:

- clang C/C++ compiler

- make

- full developer tools

Check version:

```bash
clang++ --version
```

Compile:

```bash
clang++ file.cpp -o output
./output
```

---

4.  Linux

**Ubuntu / Debian**

```bash
sudo apt update
sudo apt install g++
```

Check:

```bash
g++ --version
```

---

** Fedora **

```bash
sudo dnf install gcc-c++
```

---

** Arch Linux **

```bash
sudo pacman -S gcc
```

---

## Your Setup Summary

Termux → uses clang++

Windows → MinGW or Visual Studio

macOS → xcode-select --install

Linux → package manager (apt, dnf, pacman)
