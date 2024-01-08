/*C++ ElectricChargingBill.cpp
  Agnes Tang
  CIS054 C/C++ Programming
  Inputs: kWh
  Outputs: totalBill
*/

  #include <iostream> // for cin and cout
  #include <iomanip> // for rounding to two decimal places
  using namespace std;

  // constant variables
  const double TIER_ONE_RATE = 0.23; 
  const double TIER_TWO_RATE = 0.29;
  const double TIER_THREE_RATE = 0.45;
  const double TIER_ONE_ALLOWANCE = 350;
  const double TIER_TWO_ALLOWANCE = 1450;
  const double COMMISSON_TAX = 0.20;

  int main(int argc, char* argv[]) {
    // variables
    double kWh, tierOnekWh, tierTwokWh, tierThreekWh;
    double tierOneUsage, tierTwoUsage, tierThreeUsage;
    double totalBill;
   
    // Input
    cout << "Enter the kWh: ";
    cin >> kWh;
    cout << endl;

    /* Process
    Checks to make sure that what is being inputted is a number and is positive 
    */

    try {
        if (cin.fail()) 
            throw 0;
        if (kWh < 0)
            throw 0;

        if (kWh <= TIER_ONE_ALLOWANCE) {                                // fulfills condition when kWh is less than or equal 350
            tierOnekWh = kWh;
            tierOneUsage = kWh * TIER_ONE_RATE;
            tierTwoUsage = 0;
            tierThreeUsage = 0;
        } else if (kWh <= TIER_TWO_ALLOWANCE) {                         // fulfills condition when kWh is less than or equal to 1450
            tierOnekWh = TIER_ONE_ALLOWANCE;
            tierOneUsage = TIER_ONE_ALLOWANCE * TIER_ONE_RATE;
            tierTwokWh = kWh - TIER_ONE_ALLOWANCE;
            tierTwoUsage = (kWh - TIER_ONE_ALLOWANCE) * TIER_TWO_RATE;
            tierThreeUsage = 0;
        } else {                                                        // fulfills condition if kWh is greater than 1450
            tierOnekWh = TIER_ONE_ALLOWANCE;
            tierOneUsage = TIER_ONE_ALLOWANCE * TIER_ONE_RATE;
            tierTwokWh = TIER_TWO_ALLOWANCE - TIER_ONE_ALLOWANCE;
            tierTwoUsage = (TIER_TWO_ALLOWANCE - TIER_ONE_ALLOWANCE) * TIER_TWO_RATE;
            tierThreekWh = kWh - TIER_ONE_ALLOWANCE;
            tierThreeUsage = (kWh - TIER_TWO_ALLOWANCE) * TIER_THREE_RATE;
        }
    }

    catch (int errID) {     // catches the input if it is negative or isn't a numeric value
        cout << "Error: " << errID << endl;
        cout << "kWh must be a positive number" << endl;
    }

    // Finding the total bill
    totalBill = tierOneUsage + tierTwoUsage + tierThreeUsage + COMMISSON_TAX;

    // Output
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << "Tier One Usage: " << setprecision(2) << tierOnekWh << " kWh " << "$" << setprecision(2) << tierOneUsage << endl;
    cout << "Tier Two Usage: " << setprecision(2) << tierTwokWh << " kWh " << "$" << setprecision(2) << tierTwoUsage << endl;
    cout << "Tier Three Usage: " << setprecision(2)<< tierThreekWh << " kWh " << "$" << setprecision(2)<< tierThreeUsage << endl;
    cout << "Energy Tax: $" << COMMISSON_TAX << endl;
    cout << "Total Bill: $" << setprecision(2)<< totalBill;
  }