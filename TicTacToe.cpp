/*C++ TicTacToe.cpp
  Agnes Tang
  CIS054 C/C++ Programming
  Inputs: inputCharacter
  Outputs: player
*/

#include <iostream> // for cin and cout
#include <cstdlib>  // for srand()
#include <ctime>    // for time() function
using namespace std;

// constants
const int ROWS = 3;
const int COLUMNS = 3;

// function prototypes
void displayTicTacToe(char board[ROWS][COLUMNS]);
char checkForWinningGame(char board[ROWS][COLUMNS]);

int main (int argc, char* argv[]) {
    char board[ROWS][COLUMNS] = {       // creating the tic tac toe board
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int squareCounter = 0;             // count how many squares are used
    char gameWinner = '-';             // winner of the game ('X' or 'O')
    char inputCharacter;               // input from the user (should be '1' to '9')
    int choice;                        // input converted to integer 0 to 8 (start from 0)
    char player;                       // current player, either 'X' or 'O'

    // selecting the starting player
    srand((unsigned int)time(NULL));    // seeding the random number generator
    if (rand() % 2 == 1) {
        player = 'X';
    } else {
        player = 'O';
    }

    // starting instructions
    cout << "Please enter 1 - 9 to select a square." << endl;
    
    while (squareCounter < 9 && gameWinner != 'X' && gameWinner != 'O') {
        cout << "---------------------------------" << endl;
        displayTicTacToe(board);
        cout << "Player " << player << ", enter a number (1-9): ";
        cin >> inputCharacter;

        // convert inputCharacter from ASCII ('1' to '9') to integer (0 to 8)
        // to select the row and column index from the 3x3 array
        choice = inputCharacter - '1';  // now the input are 0,1,2,3,4,5,6,7,8
        int row = choice / 3;
        int col = choice % 3;

        if (choice < 0 || choice > 8) {     // see if the input is greater than 0 or less than 8
            cout << "Illegal value, try again" << endl;
        } else if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "This space has already been used, try again" << endl;
        } else {
            board[row][col] = player;       // put in an 'X' or an 'O'
            squareCounter++;                // count the number of squares completed
            
            if (player == 'X') {
                player = 'O';               // switch 'X' to 'O' for the next move
            } else {
                player = 'X';               // switch 'O' to 'X' for the next move
            }
            gameWinner = checkForWinningGame(board);   // returns 'X' or 'O if the game is won        
       }
    }

    displayTicTacToe(board);
    cout << endl;
    if (gameWinner == 'X' || gameWinner == 'O') {
        cout << "Player " << gameWinner << " wins the game" << endl << endl;
    } else {
        cout << "Tie game" << endl << endl;
    }
    return 0;
}

// Display the Tic Tac Toe Board
// includes extra credit
void displayTicTacToe(char board[ROWS][COLUMNS]) {
    // the title
    cout << " =================" << endl;
    cout << "    TIC TAC TOE   " << endl;
    cout << " =================" << endl;
    
    cout << endl;
    for (int row = 0; row < ROWS; row++) {
        cout << "      |     |     " << endl;        // separating the columns
        for (int col = 0; col < COLUMNS; col++) { 
            if (col == 0) {                         // checks to make sure that the last column does not have a '|'
                cout << "   " << board[row][col] << "  |";
            } else if (col == 1) {                                // other columns will have an '|'
              cout << "  " << board[row][col] << "  |";
            } else if (col == 2) {
                cout << "  " << board[row][col];
            }
        }

        if (row != 2) {                             // will have separating columns and dashes afterwards
            cout << endl;
            // cout << "     |     |     " << endl;
            cout << " _____|_____|_____ " << endl;
        }

        if (row == 2) {                             // for the last row
           cout << endl;
           cout << "      |     |     ";             // notice does not have dashes afterwards
        }
    }
    cout << endl;
    cout << endl;
}

// checks all eight possible combinations for a win
char checkForWinningGame(char board[ROWS][COLUMNS]) {
    char player;
    
    // checks first row to see if all squares are the same
    // checks left diagonal to see if all squares are the same
    // checks first column to see if all squares are the same
    player = board[0][0];
    if (board[0][1] == player && board[0][2] == player) {
        return player;
    } else if (board[1][1] == player && board[2][2] == player) {
        return player;
    } else if (board[1][0] == player && board[2][0] == player) {
        return player;
    }

    // checks second row to see if all squares are the same
    player = board[1][0];
    if (board[1][1] == player && board[1][2] == player) {
        return player;
    }

    // checks third row to see if all squares are the same
    player = board[2][0];
    if (board[2][1] == player && board[2][2] == player) {
        return player;
    }

    // checks second column to see if all squares are the same
    player = board[0][1];
    if (board[1][1] == player && board[2][1] == player) {
        return player;
    }

    // checks third column to see if all squares are the same
    // checks the right diagonal to see if all squares are the same
    player = board[0][2];
    if (board[1][2] == player && board[2][2] == player) {
        return player;
    } else if (board[1][1] == player && board[2][0] == player) {
        return player;
    }

    return '-'; // if there is no winner
}