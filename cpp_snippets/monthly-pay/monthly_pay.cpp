/* Monthly Pay Calculator (C++)
   --------------------------------
   This program calculates a worker's monthly pay by multiplying
   the daily pay rate by the number of days worked.

   Input:
     - Daily pay rate (float)
     - Number of days worked (integer)

   Output:
     - Monthly pay

   Compile:
      clang++ monthly_pay.cpp -o monthly_pay
      // Termux/macOS/Linux
      
      g++ monthly_pay.cpp -o monthly_pay
      // Windows/Linux

   Run:
      ./monthly_pay
*/

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

