/* C++ ReservationSystem.cpp
   Agnes Tang
   CIS054 C/C++ Programming
   Inputs:
   Outputs:
*/

#include <iostream>
#include <cctype>
using namespace std;

// function protoypes
char **CreateArrayOfSeats (int NumberOfRows, int seats);
void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int seats, int seatCounter);
void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int seats);

int main(int argc, char* argv[]) {
   // variables
   char **ArrayOfSeats; // for dynamic array
   int NumberOfRows;
   int NumberOfSeats;
   char rowSelection;
   char seatSelection;
   int row;
   int seat;
   int seatCounter = 0; // counter variable

   // INPUTs
   cout << "Enter the number of rows: ";
   cin >> NumberOfRows;
   cout << "Enter the number of seats in each row: ";
   cin >> NumberOfSeats;

   int maxSeats = NumberOfRows*NumberOfSeats;         // finds the max amount of seats

   // creates the new board
   ArrayOfSeats = CreateArrayOfSeats(NumberOfRows, NumberOfSeats);
   InitializeSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
   DisplayArrayOfSeats(ArrayOfSeats, NumberOfRows, NumberOfSeats, seatCounter);

   do {
      cout << endl << "Enter a row selection (example 5A or 00 to quit): ";
      cin >> rowSelection;
      cin >> seatSelection;
      if (rowSelection == '0') {
         break;
      } 

      seatSelection = toupper(seatSelection);      // sets seat selection to uppercase
      row = rowSelection - '1';
      seat = seatSelection - 'A'; 

      // conditionals
      if (row < 0 || row > NumberOfRows) {
         cout << "Please enter the appropriate number" << endl;
      } else if (seat < 0 || seat > NumberOfSeats) {
         cout << "Please enter the appropriate seat" << endl;
      } else if (ArrayOfSeats[row][seat] == '-') {
         cout << "This seat has already been taken, please choose another seat" << endl;
      } else {
         ArrayOfSeats[row][seat] = '-';
         seatCounter++;
      }

      // displays the board after seat has been taken
      DisplayArrayOfSeats(ArrayOfSeats, NumberOfRows, NumberOfSeats, seatCounter);
   
   } while (rowSelection != '0' && seatCounter < maxSeats);
      cout << endl;
      cout << "All seats have been taken" << endl;             // display message after all seats have been taken
      cout << endl;
      MemoryCleanup(ArrayOfSeats, NumberOfRows, NumberOfSeats);
      return 0;
}

char **CreateArrayOfSeats (int NumberOfRows, int seats) {
   char **ArrayOfSeats;
   ArrayOfSeats = new char*[NumberOfRows];         // create array of pointers for NumberOfRows
   for (int i = 0; i < NumberOfRows; i++) {
      ArrayOfSeats[i] = new char[seats];           // create an array of seats for each row
   }
   return ArrayOfSeats;                            // return pointer to the array back to main program
}

void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats) {
   for (int i = 0; i < NumberOfRows; i++) {        // initialize the data for each row
      for (int j = 0; j < seats; j++) {
         ArrayOfSeats[i][j] = 'A' + j;             // put 'A' 'B' 'C' etc in each row
      }
   }
}

void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats, int seatCounter) {
   int maxSeats = NumberOfRows*NumberOfSeats;
   for (int i = 0; i < NumberOfRows; i++) {
      cout.width(2);
      cout << i+1 << ' ';
      for (int j = 0; j < NumberOfSeats; j++) {    // Display row numbers starting from 1
         cout << ArrayOfSeats[i][j] << ' ';        // display infor for each seat
      }
      cout << endl;                                // new line after each row
   }
   // Display of how many seats are taken and total amount of seats
   cout << "Total Seats: " << maxSeats << endl;       
   cout << "Total Seats Taken: " << seatCounter << endl;
   seatCounter++;
}

void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats) {
   for (int i = 0; i < NumberOfRows; i++) {
      delete [] ArrayOfSeats[i];             // delets each row of seats individually
   }
   delete [] ArrayOfSeats;                   // deletes row array
}