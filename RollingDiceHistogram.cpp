/* C++ RolingDiceHistogram
   Agnes Tang
   CIS054 C/C++ Programming
*/

#include <iostream> // for cin and cout
#include <ctime>    // for srand()
using namespace std;

// function prototypes
int roll();
int roll2Dice();

int main (int argc, char* argyv[]) {
    // counter variables
    int twoCounter = 0;
    int threeCounter = 0;
    int fourCounter = 0;
    int fiveCounter = 0;
    int sixCounter = 0;
    int sevenCounter = 0;
    int eightCounter = 0;
    int nineCounter = 0;
    int tenCounter = 0;
    int elevenCounter = 0;
    int twelveCounter = 0;

    // for loop for 1000 times
    for (int i = 0; i < 1000; i++) {
        int total = roll2Dice();
        if (total == 2) {
            twoCounter++;
        } else if (total == 3) {
            threeCounter++;
        } else if (total == 4) {
            fourCounter++;
        } else if (total == 5) {
            fiveCounter++;
        } else if (total == 6) {
            sixCounter++;
        } else if (total == 7) {
            sevenCounter++;
        } else if (total == 8) {
            eightCounter++;
        } else if (total == 9) {
            nineCounter++;
        } else if (total == 10) {
            tenCounter++;
        } else if (total == 11) {
            elevenCounter++;
        } else {
            twelveCounter++;
        }
    }

    // display statements
    cout << "2: " << twoCounter << endl;
    cout << "3: " << threeCounter << endl;
    cout << "4: " << fourCounter << endl;
    cout << "5: " << fiveCounter << endl;
    cout << "6: " << sixCounter << endl;
    cout << "7: " << sevenCounter << endl;
    cout << "8: " << eightCounter << endl;
    cout << "9: " << nineCounter << endl;
    cout << "10: " << tenCounter << endl;
    cout << "11: " << elevenCounter << endl;
    cout << "12: " << twelveCounter << endl;
}

// rolls one dice by randomizing a number from 1 to 6
int roll() {
    static bool randomInitalized = false;   // rand intialized flag

    if (!randomInitalized) {                // only 1st time the function is called
        srand((unsigned int) time(NULL));   // initalize the random number generator
        randomInitalized = true;            // don't do it again
    }                           
    return (rand() % 6) + 1;                // add 1 because rand starts at zero
}

// rolls two dice using the roll() function
int roll2Dice() {
    int rollOne = roll();                   // first roll
    int rollTwo = roll();                   // second roll
    return rollOne + rollTwo;               // adds the first and second roll together
}