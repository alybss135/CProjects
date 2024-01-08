/*C++ RockPaperScissors.cpp
  Agnes Tang
  CIS054 C/C++ Programming 
  Inputs: player1 and player2 - (R)ock, (P)aper, or (S)cissor
  Output: Winner of the round
*/

  #include <iostream> // for cin and cout
  using namespace std;

  int main(int argc, char* argv[]) {
    // variables
    char player1; // input for Player 1
    char player2; // Input for Player 2
    char playAgain = 'Y'; // loop control

    cout << "Enter R P or S for rock, paper or scissors" << endl;
    do {
        cout << "Player 1 (R P S): ";
        cin >> player1;
        player1 = toupper(player1); // convert for easier comparisons

        cout << "Player 2 (R P S): ";
        cin >> player2;
        player2 = toupper(player2); // convert for easier comparisons

        if (player1 == 'R') {
            if (player2 == 'R') {
                cout << "Tie game, nobody wins" << endl;
            } else if (player2 == 'P') {
                cout << "Paper beats Rock, Player 2 is the winner" << endl;
            } else if (player2 == 'S') {
                cout << "Rock beats Scissors, Player 1 is the winner" << endl;
            } else {
                cout << "Please enter R, S, or P to continue playing" << endl;
            }
        } else if (player1 == 'P') {
            if (player2 == 'R') {
                cout << "Paper beats Rock, Player 1 is the winner" << endl;
            } else if (player2 == 'P') {
                cout << "Tie game, nobody wins" << endl;
            } else if (player2 == 'S') {
                cout << "Scissors beat Paper, Player 2 is the winner" << endl;
            } else {
                cout << "Please enter R, S, or P to continue playing" << endl;
            }
        } else if (player1 == 'S') {
            if (player2 == 'R') {
                cout << "Rock beats Scissors, Player 2 is the winner" << endl;
            } else if (player2 == 'P') {
                cout << "Scissors beat Rock, Player 1 is the winner" << endl;
            } else if (player2 == 'S') {
                cout << "Tie game, nobody wins" << endl;
            } else {
                cout << "Please enter R, S, or P to continue playing" << endl;
            }
        } else {
            cout << "Illegal selection for Player 1" << endl;
        }
        cout << "Do you want to play again? " << endl;
        cin >> playAgain;
        playAgain = toupper(playAgain);
        cout << endl; // blank line between games
    }
    while (playAgain == 'Y');
    
    return 0;
  }