/* C++ SumAndRange.cpp 
   Agnes Tang
   CIS054 C/C++ Programming
   Inputs: ten numbers
   Ouputs: sumOfOddNumbers, sumOfEvenNumbers, sumofAllNumbers, lowestValue, highestValue, average
*/

#include <iostream>
#include <iomanip>  // to round decimals
using namespace std;

// constant
const int NUMBER_COUNT = 10;

int main (int argc, char* argv[]) {
    // variables
    int sumOfOddNumbers = 0;
    int sumOfEvenNumbers = 0;
    double sumOfAllNumbers = 0;
    int minValue = 0;
    int maxValue = 0;
    int inputCounter = 0;
    int number;
    
    // for extra credit
    double average;

    // loops till the user has entered ten positive integers
    while (inputCounter < NUMBER_COUNT) {
        cout << "Enter a number: " << endl;
        cin >> number;
 
        // checks to make sure that the user is entering the correct input
        if (number < 1 || cin.fail()) {
            cout << "Please enter a positive number" << endl;
            cin.clear();            // clears input
            cin.ignore(80, '\n');   // ignores input up to 80 characters
            inputCounter--;
        }


        if (number > 0) {               //checks if number is positive before adding it to the sum for all numbers
            sumOfAllNumbers += number;  
            if (number % 2 == 0) {      // checks if number is even
                sumOfEvenNumbers += number;
            } else {
                sumOfOddNumbers += number;
            }
        
            // finds min and max value
            if (inputCounter == 0 && number > 0) {
                minValue = number;
                maxValue = number;
            } else {
                if (number < minValue) {
                    minValue = number;
                }
                if (number > maxValue) {
                    maxValue = number;
                }
            }
        }
        inputCounter++;
    }

    // calculating average
    average = sumOfAllNumbers / 10;

    // OUTPUT
    cout << endl;
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << "Sum of Odd Numbers: " << sumOfOddNumbers << endl;
    cout << "Sum of Even Numbers: " << sumOfEvenNumbers << endl;
    cout << "Sum of All Numbers: " << (int) sumOfAllNumbers << endl;
    cout << "Average of Numbers: " << setprecision(2) << average << endl;
    cout << "Min Value: " << minValue << endl;
    cout << "Max Value: " << maxValue << endl;
    cout << endl;
    
    return 0;
}