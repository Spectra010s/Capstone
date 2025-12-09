/* Cuboid Volume Calculator
   This program calculates the volume of a cuboid (15 × 14 × 10 cm).
   Compile: clang++ volume.cpp -o volume
   Run: ./volume
*/

#include <iostream>
using namespace std;

int main() {
    int h = 15;
    int w = 14;
    int d = 10;

    int volume = h * w * d;
    
    cout << "--- Cuboid Volume Calculator ---" << endl;
    cout << "Volume of the cuboid is: " << volume << " cm³";
    return 0;
}