# Capstone - Student Percentage Calculator Snippet

## Overview

This C++ program collects a student's data ( **name**, **roll number**, and **marks for six subjects**), then calculates the **total score** and the **overall percentage** out of 600 achieved by the student.

It demonstrates basic input/output, arrays, loops, and simple arithmetic operations in C++.

---

## Getting Started

Follow these steps to get a local copy of the project up and running on your machine.

### Prerequisites

You need a C++ compiler (like **g++** or **Clang**) installed on your system.

Check on how to install them [here](https://github.com/Spectra010s/Capstone/blob/main/cpp_snippets%2FInstalling-C%2B%2B-on-your-system.md)

---

## How It Works

The program:

- Asks for the **student's name**
- Asks for the **student's roll number**
- Asks for **marks in 6 subjects**
- Calculates:
  - **Total Marks**
  - **Percentage** out of 600
- Displays the result neatly

### Formula

```
Percentage = (Total Marks / 600) × 100
```

### Program Steps

1. Ask for student name
2. Ask for roll number
3. Input marks for 6 subjects
4. Calculate total
5. Compute percentage
6. Display the result

---

## Code Logic Summary

- A **string** stores the student's name.
- A **string** stores the roll number.
- `marks[6]` stores marks for each of the six subjects.
- A **for-loop** collects user input and adds each value to the total.
- Percentage is computed from the total score.
- Printed output includes:
  - Student Name
  - Roll Number
  - Final Percentage

---

## How to Compile and Run

1.  **Save the Code:** Save the provided code into a file named, for example, `percentage.cpp`.

2.  **Compile:** Open your terminal or command prompt and use your C++ compiler to compile the file.

### Termux / macOS / Linux (Clang)

Compile:

```bash
clang++ percentage.cpp -o percentage_calc
```

### Windows / Linux (G++)

Compile:

```bash
g++ percentage.cpp -o percentage_calc
```

_(This command compiles `percentage.cpp` and creates an executable file named `percentage_calc`, you can choose any name you like.)_

--- 

## Usage

After successful compilation, run the executable directly from your terminal.

1.  **Run the Program**:
    ```bash
    ./percentage_calc
    ```

2.  **Follow the Prompts**:
    The program will prompt you to enter the student's name, roll number, and marks for six subjects.

    **Example Interaction**:
    ```
--- Student Percentage Score Calculator ---
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

---

## Explaining The Syntax

```cpp
#include <iostream>
using namespace std;

int main() {
    string name;
    string roll;
    float marks[6];
    float total = 0;


    cout << "--- Student Percentage Score Calculator ---" << endl;
    cout << "Enter student's name: ";
    cin >> name;

    cout << "Enter student's roll number: ";
    cin >> roll;

    for (int i = 0; i < 6; i++) {
        cout << "Enter marks for subjects " << i + 1 << ": ";
        cin >> marks[i];
        total += marks[i];
    }

    float percentage = (total / 600) * 100;

    cout << "Name: " << name << endl;
    cout << "Roll Number: " << roll << endl;
    cout << "Percentage Score Secured:: " << percentage << "%" << endl;

    return 0;
}
```

---

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

### variables

```cpp
string name;
string roll;
```

Creates variables to store the student’s identity. they are strings

- **name** → student's name
- **roll** → student's roll number

---

### `float marks[6];`

An array that can hold **6 subject scores**.

---

#### The For-Loop

```cpp
for (int i = 0; i < 6; i++) {
    cin >> marks[i];
    total += marks[i];
}
```

- Repeats 6 times
- Takes input for each subject
- Adds each score to the total

---

#### Percentage Calculation

```cpp
float percentage = (total / 600) * 100;
```

Gets the percentage by dividing the total with 600 times 100

---

#### Output Section

Uses **cout** to print:

- Name
- Roll Number
- Percentage

---

#### return 0;

Tells the system “program finished without errors.”

Required in C++.

> This snippet is part of the cpp_snippets collection and teaches arrays, loops, user input, and basic arithmetic — perfect for beginners learning structured C++ logic.
