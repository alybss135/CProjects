/*C++ SentenceFormatting.cpp 
  Agnes Tang
  CIS054 C/C++ Programming
  Inputs: sentence
  Outputs: sentence
  September 24th, 2023
*/

#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char* argv[]) {
    char sentence[200]; // setting sentence length
    int i;

    // INPUT
    cout << "Please enter a sentence that ends with a period: " << endl;
    cin.getline(sentence, 200);

    // checking to see if there is any whitespace using a for loop
    for (int i = 0; sentence[i]; i++) {
        if (isspace(sentence[i])) {
            sentence[i] = ' ';
        }
    }

    // removes extra spaces between words if there are any
    i = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] == ' ' && sentence[i+1] == ' ') {
            for (int j = i; sentence[j]; j++) {
                sentence[j] = sentence[j+1];
            }
        } else {
            i++;
        }
    }

    // upper-cases the first letter of the sentence and lower-cases the rest of the sentence
    sentence[0] = toupper(sentence[0]);
    for (i = 1; sentence[i]; i++) {
        sentence[i] = tolower(sentence[i]);
    }

    cout << sentence << endl; // displays sentence
}