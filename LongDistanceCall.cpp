/*C++ LongDistanceCall.cpp
  Agnes Tang
  CIS054 C/C++ Programming
  Inputs: time, day
  Outputs: costOfCall
*/

#include <iostream> // for cin and cout
#include <cstring>  // for strings
#include <iomanip>  // for rounding decimals
using namespace std;

int main (int argc, char* argyv[]) {
    // constants
    const double WEEKEND_RATE = 0.15;
    const double EVENING_RATE = 0.25;
    const double DAY_RATE = 0.40;
    
    // Variables of inputs
    char day1;              // first character
    char day2;              // second character
    int hour;               // for hour
    char separator;         // separates hour and minute
    int minute;
    int lengthOfCall;       // stores length of call

    char again;             // loop variable
    int timeStarted;        
    double billingRate;
    double costOfCall;

    do {
        cout << "Enter the day (Mo Tu We Th Fr Sa Su): ";
        cin >> day1 >> day2;        
        day1 = toupper(day1);
        day2 = toupper(day2);

        cout << "Enter the time started (ex: 13:30): ";
        cin >> hour >> separator >> minute;
        timeStarted = hour * 100 + minute;              // converts hours to minutes and adds minutes 

        cout << "Enter the length of the call in minutes: ";
        cin >> lengthOfCall;

        if (day1 == 'S' && day2 == 'A') {               // checks if call was made on a Saturday or Sunday
            billingRate = WEEKEND_RATE;
        } else if (day1 == 'S' && day2 == 'A') {
            billingRate = WEEKEND_RATE;
        } else {
            if (timeStarted >= 800 && timeStarted <= 1800) {        // checks if call was made during the day
                billingRate = DAY_RATE;
            } else {
                billingRate = EVENING_RATE;
            }
        }
        costOfCall = lengthOfCall * billingRate;                    // calculating the cost based on the billing rate

        // outputs
        cout << setiosflags(ios::fixed | ios::showpoint);
        cout << "Start of Call: " << hour << separator << minute << endl;
        cout << "Length of Call: " << lengthOfCall << endl;
        cout << "Total Cost of Call: $" << setprecision(2) << costOfCall << endl;

        // Loop control
        cout << "Another call (Y/N)? ";
        cin >> again;
        again = toupper(again); 
    } while (again == 'Y');
    return 0;
}