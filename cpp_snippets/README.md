# Capstone - C++ Utilities & Setup Guide

## Overview

This repository serves as a practical toolkit for C++ developers, providing a collection of fundamental utility programs alongside an essential, comprehensive guide for setting up your C++ development environment across various operating systems. Whether you're a beginner looking to compile your first C++ code or an experienced developer seeking quick utility snippets, this project offers clear, actionable resources to streamline your workflow.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Clone the Repository](#clone-the-repository)
- [Features](#features)
- [Usage](#usage)
  - [Monthly Pay Calculator](#monthly-pay-calculator)
  - [Student Mark Percentage Calculator](#student-mark-percentage-calculator)
  - [Cuboid Volume Calculator](#cuboid-volume-calculator)
- [Technologies Used](#technologies-used)
- [Contributing](#contributing)
- [Author](#author)

## Getting Started

To get a copy of this project up and running on your local machine, follow these steps.

### Prerequisites

You will need a C++ compiler installed on your system to compile and run these programs. Please refer to the detailed guide provided in this repository for specific instructions based on your operating system (Windows, macOS, Linux, Termux): [`Installing-C++-on-your-system.md`](https://github.com/Spectra010s/Capstone/blob/main/cpp_snippets%2FInstalling-C%2B%2B-on-your-system.md)

### Clone the Repository

Clone this repository to your local machine using git:

```bash
git clone https://github.com/Spectra010s/Capstone.git
cd Capstone
```

## Features

- **Comprehensive C++ Setup Guide**: Detailed, _OS-specific instructions_ for installing and configuring C++ compilers, covering environments like Windows (MinGW, Visual Studio), macOS (clang), Linux (g++ via apt/dnf/pacman), and Termux (clang).
- **Monthly Pay Calculator**: A straightforward command-line utility to compute monthly earnings efficiently based on daily rates and the number of workdays.
- **Student Mark Percentage Calculator**: An interactive program that allows input of student details and subject marks, subsequently calculating and displaying the overall percentage score.
- **Cuboid Volume Calculator**: A simple application dedicated to calculating and outputting the volume of a fixed-dimension cuboid.

## Usage

Once you have cloned the repository and successfully set up your C++ compiler, you can compile and run the individual utility programs. Each program's compilation and execution are demonstrated below.

### Monthly Pay Calculator

This program calculates a worker's monthly pay by multiplying the daily pay rate by the number of days worked.

**Source File**: `monthly-pay/monthly_pay.cpp`

**Compilation (Example using `g++` on Linux/Windows or `clang++` on macOS/Termux):**

```bash
g++ monthly-pay/monthly_pay.cpp -o monthly_pay
# Or for macOS/Termux:
# clang++ monthly-pay/monthly_pay.cpp -o monthly_pay
```

**Execution:**

```bash
./monthly_pay
```

**Example Interaction:**

```
--- Monthly Pay Calculator ---
    Enter daily pay: 100.50
    Enter number of days worked: 22
    --- Results ---
    Monthly pay is: # 2211

```

### Student Mark Percentage Calculator

This program collects a student's name, roll number, and marks for 6 subjects. It then totals the marks and calculates the overall percentage based on a maximum score of 600.

**Source File**: `student-mark-calculator/markscalculator.cpp`

**Compilation (Example using `g++`):**

```bash
g++ student-mark-calculator/markscalculator.cpp -o percentage_calc
# Or for macOS/Termux:
# clang++ student-mark-calculator/markscalculator.cpp -o percentage_calc
```

**Execution:**

```bash
./percentage_calc
```

**Example Interaction:**

```--- Student Percentage Score Calculator ---
Enter student's name: Spectra010s
Enter student's roll number: 001
Enter marks for subjects 1: 78
Enter marks for subjects 2: 66
Enter marks for subjects 3: 82
Enter marks for subjects 4: 74
Enter marks for subjects 5: 90
Enter marks for subjects 6: 80


Name: Spectra010s
Roll Number: 001
Percentage Score Secured:: 78.3333%

```

### Cuboid Volume Calculator

A simple program designed to calculate and display the volume of a predefined cuboid with dimensions 15 × 14 × 10 cm.

**Source File**: `volume-calculator/volume.cpp`

**Compilation (Example using `g++`):**

```bash
g++ volume-calculator/volume.cpp -o volume_calc
# Or for macOS/Termux:
# clang++ volume-calculator/volume.cpp -o volume_calc
```

**Execution:**

```bash
./volume_calc
```

**Example Interaction:**

```
--- Cuboid Volume Calculator ---
Volume of the cuboid is: 2100 cm³
```

## Technologies Used

---

| Technology | Description                                                                       | Link                                                  |
| :--------- | :-------------------------------------------------------------------------------- | :---------------------------------------------------- |
| **C++**    | The core programming language used for all utility programs.                      | [C++ Language](https://isocpp.org/)                   |
| **g++**    | The GNU C++ Compiler, a widely used compiler for Linux and Windows systems.       | [GNU Compiler Collection (GCC)](https://gcc.gnu.org/) |
| **clang**  | The LLVM C++ Compiler, commonly used as the default compiler on macOS and Termux. | [LLVM Clang](https://clang.llvm.org/)                 |

## Contributing

Contributions are welcome! If you have suggestions for improvements, new features, or code syntax fixes, please consider contributing to this project. Follow these general guidelines:

1.  **Fork** the repository to your GitHub account.
2.  **Create** a new branch for your feature or fix (e.g., `git checkout -b feature/add-new-utility`).
3.  **Implement** your changes, ensuring they are well-tested and follow consistent coding styles.
4.  **Commit** your changes with a clear and descriptive message (e.g., `git commit -m 'feat: Add a new temperature conversion utility'`).
5.  **Push** your branch to your forked repository (`git push origin feature/add-new-utility`).
6.  **Open** a Pull Request against the `main` branch of the original repository, describing your changes.

Please ensure your code adheres to standard C++ practices and is well-commented for clarity.

## Author

- **Adeloye Adetayo** - _Lead Developer_
  - LinkedIn: [Adeloye Adetayo](https://www.linkedin.com/in/adeloye-adetayo-273723253)
  - Twitter: [@Spectra010s](https://x.com/spectra010s)
