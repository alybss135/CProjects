/*C++ RandomSentences.cpp 
  Agnes Tang
  CIS054 C/C++ Programming
  Inputs: selection
  Ouputs: sentence
*/

#include <iostream> // for cout
#include <cstdlib> // for random number generator
#include <ctime>   // to seed the number generator
#include <cctype>  // for toupper()
#include <string>  // for C++ strings
using namespace std;

// Arrays for article, adjective, noun, verb, and preposition along with the number of strings in the array
const string article[] = {"the", "a", "some", "any"};
int articleCount = sizeof(article)/sizeof(string);

const string adjective[] = {"brave", "orange", "fast", "red", "yellow", "green", "blue", "purple", "fast", "slow", "intelligent", "good", "bad", "sweet", "handsome", "pretty", "sharp"};
int adjectiveCount = sizeof(adjective)/sizeof(string);

const string noun[] = {"desk", "chair", "envelope", "car", "train", "bus", "boat", "elephant", "dog", "cat", "moose", "rabbit", "boy", "girl", "man", "woman"};
int nounCount = sizeof(noun)/sizeof(string);

const string verb[] = {"drove", "jump", "ran", "walked", "skipped", "flew"};
int verbCount = sizeof(verb)/sizeof(string);

const string preposition[] = {"to", "from", "over", "under", "on", "in"};
int prepositionCount = sizeof(preposition)/sizeof(string);

int main(int argc, const char * argv[]) {
    // variables
    string sentence;
    int selection;

    // seed the number generator
    srand((unsigned int)time(0) );

   
    for (int i = 0; i < 20; i++) {            // for generating 20 sentences
        selection = rand()%articleCount;     // picking a random article
        sentence = article[selection];       // place as the first word of the sentence
        sentence += " ";                    // adds a space between the first word and second word

        selection = rand()%adjectiveCount;
        sentence += adjective[selection];
        sentence += " ";
        
        selection = rand()%nounCount;
        sentence += noun[selection];
        sentence += " ";

        selection = rand()%verbCount;
        sentence += verb[selection];
        sentence += " ";

        selection = rand()%prepositionCount;
        sentence += preposition[selection];
        sentence += " ";

        selection = rand()%articleCount;
        sentence += article[selection];
        sentence += " ";

        selection = rand()%adjectiveCount;
        sentence += adjective[selection];
        sentence += " ";
        
        selection = rand()%nounCount;       // selects another noun
        sentence += noun[selection];        // adds noun to the sentence
        sentence += ".";                    // adds period to end of sentence

        sentence[0] = toupper(sentence[0]); // capitalizes the first letter of the sentence
        cout << sentence << endl;           // displays sentence
    }
}