/* C++ LengthOfLine.cpp
   Agnes Tang
   CIS054 C/C++ Programming
   Inputs: x1, y1, x2, y2
   Outputs: length
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// function prototype
double LengthOfLine (double x1, double y1, double x2, double y2); 

int main(int argc, char* argv[]) {
    // variables
    double x1, x2, y1, y2, length;
    
    // Inputs
    cout << "Calculating the Length Of a Line" << endl;
    cout << "================================" << endl;
    cout << endl;
    cout << "Enter X1 Y1 X2 Y2 separated by spaces: ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Ouputs:
    length = LengthOfLine(x1, y1, x2, y2);
    std::cout << "The length of the line is: " << std::fixed << std::setprecision(4) << length << std::endl;
    return 0;
}

double LengthOfLine(double x1, double y1, double x2, double y2) {
    double x, y, length;
    x = x2 - x1;            // subtracting x-coordinates
    y = y2 - y1;            // subtracting y-coordinates
    length = sqrt(x*x + y*y);   // finding the distance using the sqrt function
    return length;
}