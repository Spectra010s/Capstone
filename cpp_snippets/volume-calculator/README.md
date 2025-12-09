# Capstone - Volume of a Cuboid Snippet

## Overview

This is a simple C++ program that calculates the **volume of a rectangular prism or cuboid** using predefined dimensions: height (h), width (w), and depth (d).
It demonstrates basic variable declaration, arithmetic operations, and console output using iostream

## Getting Started

Follow these steps to get a local copy of the project up and running on your machine.

### Prerequisites

You need a C++ compiler (like **g++** or **Clang**) installed on your system.

Check on how to install them [here](../Installing-C++-on-your-system)

---

## Volume Calculator

The program uses the formula **Volume** = Height × Width × Depth. The result is printed to the console in cubic centimeters (cm³).

### Formula Used

- Volume = height × width × depth

* **Current Dimensions:**
  - Height (h): **15 cm**
  - Width (w): **14 cm**
  - Depth (d): **10 cm**
* **Calculated Volume:** 15 × 14 × 10 = **2100cm³**

## Code Logic Summary

- Three integer variables store the cuboid dimensions.

- The volume is computed by multiplying the three values.

- The result is displayed in cubic centimeters using cout.

## How to Compile and Run

1.  **Save the Code:** Save the provided code into a file named, for example, `volume.cpp`.

2.  **Compile:** Open your terminal or command prompt and use your C++ compiler to compile the file.

### Termux / macOS / Linux (Clang)

```bash
clang++ volume.cpp -o volume_calc
```

### Windows / Linux (G++)

```bash
g++ volume.cpp -o volume_calc
```

_(This command compiles `volume.cpp` and creates an executable file named `volume_calc`, you can choose any name you like.)_

--- 

## Usage

After successful compilation, run the executable directly from your terminal.

1.  **Navigate to the Project Directory**:
    Make sure your terminal is in the directory where you compiled `volume.cpp`.

2.  **Run the Executable**:
    Execute the compiled program:
    ```bash
    ./volume_calc
    ```

### Example Output

```
--- Cuboid Volume Calculator ---
Volume of the cuboid is: 2100 cm³
```

---

### Customization

To calculate a different volume, simply **modify the values** assigned to the `h`, `w`, and `d` variables inside the `main` function of the `volume.cpp` file:

```cpp
    int h = 15; // Change this value
    int w = 14; // Change this value
    int d = 10; // Change this value
```

## Explaining The Syntax

```cpp
#include <iostream>
using namespace std;

int main() {
    int h = 15;
    int w = 14;
    int d = 10;

    int volume = h * w * d;

    cout << "Volume of the cuboid is: " << volume << " cm³";
    return 0;
}
```

### Code Explanation:

---

#### #include `<iostream>`

- This brings in the “input/output stream” library.

- It allows you to use cout (display) and cin (input).

- Without it, your program cannot show anything on screen.

---

#### using namespace std;

- Lets you use **cout**, **cin**, **string**, etc., without writing `std::` every time.

- Makes code cleaner for beginners.

Example:

With namespace → cout << "hello";

Without namespace → std::cout << "hello";

---

#### int main() { … }

Every C++ program must have a main() function.

It is the starting point — the first thing the computer runs.

Anything inside the { } is your program.

---

#### int h = 15;

int means integer (whole number).

You created a variable called h and gave it the value 15.

Semicolon ; ends a statement, required in C++.

---

#### int volume = h _ w _ d;

This calculates the volume using multiplication.

Stores the result inside volume.

---

#### cout << "Volume" << volume;

cout → print to screen

<< → output operator

You can chain many outputs:
"text" then volume then "cm³"

---

#### return 0;

Tells the system “program finished without errors.”

Required in C++.

> This snippet is part of the cpp_snippets collection and serves as a simple introduction to variables, arithmetic, and basic I/O in C++.
