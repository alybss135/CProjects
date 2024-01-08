/*C++ CountingChange.cpp 
  Agnes Tang
  CIS054 C/C++ Programming
  Inputs: numOfquarters, numOfdimes, numOfnickels, numOfpennies
  Outputs: total
*/

#include <iostream> // for cin and cout
#include <iomanip> // for rounding decimals
using namespace std;

// defining constants
const double quarterValue = 0.25; // 25 cents
const double dimeValue = 0.1; // 10 cents
const double nickelValue = 0.05; // 5 cents
const double pennyValue = 0.01; // 1 cent

int main(int argc, char* argyv[]) {
    // variables
    int numOfQuarters, numOfDimes, numOfNickels, numOfPennies;
    double quarterTotal, dimeTotal, nickelTotal, pennyTotal, total;

    // inputs
    cout << "Agnes' Coin Computation Program" << "\n" << endl;

    cout << "Enter number of quarters: " << endl;
    cin >> numOfQuarters;
    cout << "Enter number of dimes: " << endl;
    cin >> numOfDimes;
    cout << "Enter number of nickels: " << endl;
    cin >> numOfNickels;
    cout << "Enter number of pennies: " << endl;
    cin >> numOfPennies;

    // in the case that a non int is entered
    if (cin.fail()) {
        cout << "Illegal Input - Please enter a number" << endl;
        numOfQuarters = quarterTotal;
        numOfDimes = dimeTotal;
        numOfNickels = nickelTotal;
        numOfPennies = pennyTotal;
    }

    // multiplying number of coins entered by the value of the coin
    quarterTotal = numOfQuarters * quarterValue;
    dimeTotal = numOfDimes * dimeValue;
    nickelTotal = numOfNickels * nickelValue;
    pennyTotal = numOfPennies * pennyValue;

    // adding everyting together for final total
    total = quarterTotal + dimeTotal + nickelTotal + pennyTotal;
    
    // displaying the total rounded to the second decimal place
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << "Your total is $" << setprecision(2) << total << endl; 
}