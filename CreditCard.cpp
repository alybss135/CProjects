/* C++ CreditCard.cpp
   Agnes Tang
   CIS054 C/C++ Programming 
   Inputs: balance, monthlyPayment, monthlyCharges
   Output: newBalance
*/

#include <iostream>
#include <iomanip> // for rounding decimals
using namespace std;

// constants
const double YEARLY_INTEREST_RATE = 0.2224; // interest is 22.24%
const double MONTHLY_INTEREST_RATE = YEARLY_INTEREST_RATE / 12;
const double CREDIT_LIMIT = 500.00;
const int MAX_MONTHS = 12;

int main (int argc, char* argv[]) {
    // variables
    double balance;
    double payment;
    double charges;
    double interest;
    double balanceBeforePayment;
    double newBalance;
    int month = 1;

    // input balance, also checks if the input is a positive integer, if not, then prompts user to enter another value until the correct input is entered
    cout << "Enter your balance: " << endl;
    cin >> balance;
    if (cin.fail() || balance < 0) {
        cout << "Please enter a positive balance" << endl;
        cin.clear();
        cin.ignore(80,'\n');
        cout << "Enter your balance: " << endl;
        cin >> balance;
    }

    // input payment, also checks if the input is a positive integer, if not, then prompts user to enter another value until the correct input is entered
    cout << "Enter your monthly payment: " << endl;
    cin >> payment;
    if (cin.fail() || payment < 0) {
        cout << "Please enter a positive payment amount" << endl;
        cin.clear();
        cin.ignore(80,'\n');
        cout << "Enter your monthly payment: " << endl;
        cin >> payment;
    } 

    // input charges, also checks if the input is a positive integer, if not, then prompts user to enter another value until the correct input is entered
    cout << "Enter your monthly charges: " << endl;
    cin >> charges;
    if (cin.fail() || charges < 0) {
        cout << "Please enter a positive charge amount" << endl;
        cin.clear();
        cin.ignore(80,'\n');
        cout << "Enter your monthly charges: " << endl;
        cin >> charges;
    }

    // displays table
    cout << fixed << showpoint;
    cout << setw(7) << "Month" << setw(9) << "Balance" << setw(10) << "Interest" << setw(9) << "Payment" << setw(9) << "Charges" << setw(12) << "New Balance" << endl;

    // loops through till either balance is 0.00, credit limit is exceeded, or the balance is negative before 12 months is up
    do {
        interest = balance * MONTHLY_INTEREST_RATE;
        balanceBeforePayment = balance + interest + charges;

        if (balanceBeforePayment - payment < 0) {
            payment = balanceBeforePayment;
            newBalance = newBalance - payment + interest;
        } else if (newBalance >= 0.00) {
            newBalance = balanceBeforePayment - payment;
        } 
        
        // for when balance is 0.00
        if (newBalance == 0.00) {
            cout << setw(7) << month++ << setw(9) << balance << setw(10) << interest << setw(9) << payment << setw(9) << charges << setw(12) << newBalance << endl;
            break;
        }

        // creates a new line with new information
        cout << setprecision(2);
        cout << setw(7) << month << setw(9) << balance << setw(10) << interest << setw(9) << payment << setw(9) << charges << setw(12) << newBalance << endl;
        month++;

        balance = newBalance;

    } while (balance >= 0.00 && balance <= CREDIT_LIMIT && month <= 12 && newBalance >= 0.00);
        // OUTPUTS when a certain condition is fulfilled
        if (newBalance == 0.00) {
            cout << "Balance is 0" << endl;
        } else if (newBalance >= 0 && month >= 12) {
            cout << "Balance could not be paid in one year" << endl;
        } else {
            cout << "Balance is greater than the credit limit" << endl;
        }
}