/*C++ PlayersOnATeam.cpp 
  Uses a function selectTeamSize() - determine if there are not enough, too many or just right for the number of players on a team
  Agnes Tang
  CIS054 C/C++ Programming
*/

#include <iostream> // used by cin and cout
using namespace std;

int selectTeamSize(); // function prototype

int main(int argc, char* argyv[]) {
    int teamSize;
    int numOfPlayers;
    int playersNeeded;
    int extraPlayers;

    // Display a title at the top of the program's output
    cout << "Welcome to the select a team program" << "\n" << endl;

    // Input the data
    // use the SelectTeamSize() function to select a sport and return the number of players needed on a team for that sport
    teamSize = selectTeamSize(); // use function shown below
    cout << "There should be " << teamSize << " players on the team" << endl;

    cout << "How many players are on the team?" << "\n";
    cin >> numOfPlayers;
    if (cin.fail()) {
        cout << "Illegal entry for team size" << endl;
        return 1;
    }

    // Process and output
    if (numOfPlayers < teamSize) {
        cout << "There are not enough players" << endl;
        playersNeeded = teamSize - numOfPlayers;
        cout << "You still need " << playersNeeded << " players" << endl;
    } else if (numOfPlayers > teamSize) {
        cout << "There are too many players" << endl;
        extraPlayers = numOfPlayers - teamSize;
        cout << "You need to remove " << extraPlayers << " players" << endl;
    } else {
        cout << "You have the right amount of players" << endl;
    }
    return 0;
}

// The SelectTeamSize() function asks the user to select a sport and then returns the number of players on a team for that sport.

int selectTeamSize() {
    char teamSelection; // team selection entered at the keyboard
    int teamSize; // # players that should be on a team

    do {
        cout << "What team would you like to select?\n1 - NFL Football\n2 - NBA Basketball\n3 - MLB Baseball\n4 - NHL Hockey\nSelect (1-4):" << endl;
        cin >> teamSelection;

        if (teamSelection == '1') {
            teamSize = 53; // NFL
        } else if (teamSelection == '2') {
            teamSize = 13; // NBA
        } else if (teamSelection == '3') {
            teamSize = 25; // MLB
        } else if (teamSelection == '4') {
            teamSize = 23; // NHL
        } else {
            cout << "That was not one of the options, please choose a number between 1 and 4" << endl;
            teamSize = 0; // error flag
        }
    } while (teamSize == 0); // loop until a valid selection is made
    return teamSize; // to be used by the main program
}