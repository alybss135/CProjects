/*C++ Falafel.cpp
  Agnes Tang
  CIS054 C/C++ Programming
  Inputs: falafel, extra, soda
  Ouputs: totalCost
*/

#include <iostream> // for cin and cout
#include <iomanip>  // for rounding decimals
#include <cctype>   // for toupper()
void displayMenu(); // function prototype
using namespace std;

// constants
const double PRICE_FALAFEL = 5.15;
const double PRICE_SODA = 2.24;
const double PRICE_EXTRA = 1.57;
const double TAX_RATE = 0.087;

int main (int argc, char* argyv[]) {
    // variables
    int falafelCounter = 0;
    int sodaCounter = 0;
    int extraCounter = 0;
    int totalItemsCounter = 0;
    double subtotal;
    double totalCost;
    double price;
    double tax;
    char selection;
    
    displayMenu();

    do {
        price = 0;
        cout << "Make your selection (FSXT): ";     // prompt user for input
        cin >> selection;
        if (toupper(selection) == 'F') {            // checks for if order is falafel
            price = PRICE_FALAFEL;
            falafelCounter++;                       // increments by one
            totalItemsCounter++;                    // increments by one
        } else if (toupper(selection) == 'S') {     // check if order is soda
            price = PRICE_SODA;
            sodaCounter++;                          
            totalItemsCounter++;
        } else if (toupper(selection) == 'X') {     // check if order is extra
            price = PRICE_EXTRA;
            extraCounter++;
            totalItemsCounter++;
        } else if (toupper(selection) == 'T') {     // checks to see if user is done ordering
            break;
        } else {                                    // case if F, S, X, and T are not selected
            cout << "Ilegal selection, try again." << endl;
        }
        subtotal += price;                          // adds price of each item
     } while (selection != 'T' && selection != 't');    // keeps going until T is entered

    cout << endl;
    tax = subtotal * TAX_RATE;     // calculating tax
    totalCost = subtotal + tax;    // calculate total cost
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << setprecision(2);
    
    // Outputs
    cout << falafelCounter << " Falafel Orders" << endl;
    cout << sodaCounter << " Soda Orders" << endl;
    cout << extraCounter << " Extra Orders" << endl;
    cout << "------------------" << endl;
    cout << totalItemsCounter << " Total Orders" << endl;
    cout << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Total Cost: $" << totalCost << endl;
}

// function
void displayMenu() {
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << setprecision(2);
    cout << "F = Falafel, $" << PRICE_FALAFEL << endl;
    cout << "S = Soda, $" << PRICE_SODA << endl;
    cout << "X = Extras, $" << PRICE_EXTRA << endl;
    cout << "Total" << endl;
}