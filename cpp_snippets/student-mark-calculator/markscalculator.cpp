/* Student Percentage Calculator (C++)
   -----------------------------------
   This program collects a student's name, roll number, and marks
   for 6 subjects. It totals the marks and calculates the percentage
   based on a maximum score of 600.

   Input:
     - Student name
     - Student Roll number
     - Marks for 6 subjects

   Output:
     - Name
     - Roll number
     - Percentage (0–100%)

   Compile:
      clang++ student_percentage.cpp -o percentage_calc
      // Termux/macOS/Linux
      
      g++ student_percentage.cpp -o percentage_calc
       // Windows/Linux

   Run:
      ./percentage_calc
*/


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
