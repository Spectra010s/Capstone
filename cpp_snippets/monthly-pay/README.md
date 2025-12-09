# Capstone - Monthly Pay Calculator Snippet

## Overview
 
This C++ program calculates a worker’s **monthly pay** based on:

- the **daily rate**, and
- the **number of days worked** in the month.

It’s a simple introduction to variables, input/output, multiplication, and displaying results in C++. A simple yet effective tool for basic payroll calculations.


---

## Getting Started

Follow these steps to get a local copy of the project up and running on your machine.

### Prerequisites

You need a C++ compiler (like **g++** or **Clang**) installed on your system.

Check on how to install them [here](https://github.com/Spectra010s/Capstone/blob/main/cpp_snippets%2FInstalling-C%2B%2B-on-your-system.md)

---

## How It Works

The program:

- Asks the user for their **daily earning rate**
- Asks for the **number of days worked**
- Multiplies both values to compute the **monthly pay**
- Displays the final total in a simple message

### Formula Used

```
monthly pay = daily rate × number of days worked
```

---

## Code Logic Summary

- A **float** stores the daily rate (because it may contain decimals).
- An **int** stores the number of days worked.
- The multiplication result is stored in another **float**.
- Input is taken using **cin**.
- Output is displayed using **cout**.

---

## How to Compile and Run

1.  **Save the Code:** Save the provided code into a file named, for example, `monthly_pay.cpp`.

2.  **Compile:** Open your terminal or command prompt and use your C++ compiler to compile the file.

### Termux / macOS / Linux (Clang)

Compile:

```bash
clang++ monthly_pay.cpp -o monthly_pay
```

### Windows / Linux (G++)

Compile:

```bash
g++ monthly_pay.cpp -o monthly_pay
```

_(This command compiles `monthly_pay.cpp` and creates an executable file named `monthly_pay`, you can choose any name you like.)_

---

## Usage

After successful compilation, run the executable directly from your terminal.

1.  **Run the Executable**:

    ```bash
    ./monthly_pay
    ```

2.  **Follow the Prompts**:
    The program will prompt you to enter the daily pay rate and the number of days worked.

    *   **Enter daily pay**: Input a numerical value for the daily pay rate (e.g., `100.50`).
    *   **Enter number of days worked**: Input an integer for the number of days (e.g., `22`).

3.  **View Results**:
    Once both inputs are provided, the program will display the calculated monthly pay.

    ```
    --- Monthly Pay Calculator ---
    Enter daily pay: 100.50
    Enter number of days worked: 22
    --- Results ---
    Monthly pay is: # 2211
    ```

---

## Explaining The Syntax

```cpp
#include <iostream>
using namespace std;

int main() {
    float rate;
    int days;
float monthlyPay;


     cout << "--- Monthly Pay Calculator ---" << endl;
    cout << "Enter daily pay: ";
    cin >> rate;

    cout << "Enter number of days worked: ";
    cin >> days;

    monthlyPay = rate * days;


    cout << "--- Results ---" << endl;
    cout << "Monthly pay is: " << "# " << monthlyPay << endl;
    return 0;
}
```

### Code Explanation

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

#### endl (End Line)

​
endl stands for end line.

- It's used with cout to insert a newline character and immediately flush (clear) the output buffer.
- It ensures that the output is displayed immediately on the screen and moves the cursor to the beginning of the next line, just like pressing Enter.

---

#### Variables

```cpp
float rate;
int days;
float monthlyPay;
```

Creates variables to store the rate, days worked and the monthlypay.

- **rate** → daily pay
- **days** → number of days worked
- **monthlyPay** → computed monthly salary

---

### Taking User Input

```cpp
cin >> rate;
cin >> days;
```

The program waits for the user to type values and press Enter.

---

#### Salary Calculation

```cpp
monthlyPay = rate * days;
```

Multiplies daily rate by number of days.

---

#### Output

Uses **cout** to print:

```cpp
cout << "Monthly pay is: " << monthlyPay << endl;
```

Prints the final salary to the screen.

---

#### return 0;

Tells the system “program finished without errors.”

Required in C++.

> This snippet is part of the cpp_snippets collection and is ideal for beginners learning basic arithmetic, variable types, and user interaction in C++.
