#include <iostream>	// Basic C++ Console Library
#include <windows.h>	// This allows access to Windows Function only. Therefore this code can only run on Windows machines.

using namespace std;	

// Critical Game Variables
// C x R matrix
#define C 22 // Size of the Columns
#define R 15 // Size of the Rows

// Counter that hold the count for each player position
int counter1 = 0; // Room 1
int counter2 = 0; // Room 3
int counter3 = 0; // Room 5
int counter4 = 0; // Room 6
int counter5 = 0; // Room 7
int counter6 = 0; // Room 8

// Forward Declaration of the "displayMaze" function.
void displayMaze(int);

// Mazeboard for Room 1
const char *mazeboard1[R][C] =
  {
    {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
    {"1","P","1","0","0","0","0","1","X","1","0","0","0","0","1","X","1","0","0","0","0","1"},
    {"1","0","1","0","0","0","0","1","0","1","0","0","0","0","1","0","1","0","0","0","0","1"},
    {"1","0","1","1","1","1","0","1","0","1","1","1","1","0","1","0","1","0","1","1","1","1"},
    {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","X","1"},
    {"1","1","1","1","1","0","1","1","1","1","0","1","0","0","0","0","0","0","1","1","1","1"},
    {"1","0","0","0","0","0","1","0","0","0","0","1","0","0","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","1","1","1","1","1","1","0","1"},
    {"E","0","0","0","0","0","1","0","1","0","0","1","0","0","0","0","0","0","0","1","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","X","1"},
    {"1","0","0","0","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","1","1"},
    {"1","0","0","0","0","0","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","X","0","0","0","0","0","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","1","1","1","1","1","E","1","1","1","1","1","1","1","1","1"}
  };

// Mazeboard for Room 3
const char *mazeboard2[R][C] =
 {
   {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
   {"1","X","1","0","0","0","0","1","P","1","0","0","0","0","1","X","1","0","0","0","0","1"},
   {"1","0","1","0","0","0","0","1","0","1","0","0","0","0","1","0","1","0","0","0","0","1"},
   {"1","0","1","1","1","1","0","1","0","1","1","1","1","0","1","0","1","0","1","1","1","1"},
   {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","X","1"},
   {"1","1","1","1","1","0","1","1","1","1","0","1","0","0","0","0","0","0","1","1","1","1"},
   {"1","0","0","0","0","0","1","0","0","0","0","1","0","0","0","0","0","0","0","0","0","1"},
   {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","1","1","1","1","1","1","0","1"},
   {"E","0","0","0","0","0","1","0","1","0","0","1","0","0","0","0","0","0","0","1","0","1"},
   {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","X","1"},
   {"1","0","0","0","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","1","1"},
   {"1","0","0","0","0","0","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
   {"1","1","1","1","1","1","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
   {"1","X","0","0","0","0","0","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
   {"1","1","1","1","1","1","1","1","1","1","1","1","E","1","1","1","1","1","1","1","1","1"}
  };

// Mazeboard for Room 5
const char *mazeboard3[R][C] =
  {
    {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
    {"1","X","1","0","0","0","0","1","X","1","0","0","0","0","1","P","1","0","0","0","0","1"},
    {"1","0","1","0","0","0","0","1","0","1","0","0","0","0","1","0","1","0","0","0","0","1"},
    {"1","0","1","1","1","1","0","1","0","1","1","1","1","0","1","0","1","0","1","1","1","1"},
    {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","X","1"},
    {"1","1","1","1","1","0","1","1","1","1","0","1","0","0","0","0","0","0","1","1","1","1"},
    {"1","0","0","0","0","0","1","0","0","0","0","1","0","0","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","1","1","1","1","1","1","0","1"},
    {"E","0","0","0","0","0","1","0","1","0","0","1","0","0","0","0","0","0","0","1","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","X","1"},
    {"1","0","0","0","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","1","1"},
    {"1","0","0","0","0","0","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","X","0","0","0","0","0","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","1","1","1","1","1","E","1","1","1","1","1","1","1","1","1"}
  };

// Mazeboard for Room 6
const char *mazeboard4[R][C] =
  {
    {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
    {"1","X","1","0","0","0","0","1","X","1","0","0","0","0","1","X","1","0","0","0","0","1"},
    {"1","0","1","0","0","0","0","1","0","1","0","0","0","0","1","0","1","0","0","0","0","1"},
    {"1","0","1","1","1","1","0","1","0","1","1","1","1","0","1","0","1","0","1","1","1","1"},
    {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","X","1"},
    {"1","1","1","1","1","0","1","1","1","1","0","1","0","0","0","0","0","0","1","1","1","1"},
    {"1","0","0","0","0","0","1","0","0","0","0","1","0","0","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","1","1","1","1","1","1","0","1"},
    {"E","0","0","0","0","0","1","0","1","0","0","1","0","0","0","0","0","0","0","1","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","P","1"},
    {"1","0","0","0","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","1","1"},
    {"1","0","0","0","0","0","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","X","0","0","0","0","0","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","1","1","1","1","1","E","1","1","1","1","1","1","1","1","1"}
  };

// MAzeboard for Room 7
const char *mazeboard5[R][C] =
  {
    {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
    {"1","X","1","0","0","0","0","1","X","1","0","0","0","0","1","X","1","0","0","0","0","1"},
    {"1","0","1","0","0","0","0","1","0","1","0","0","0","0","1","0","1","0","0","0","0","1"},
    {"1","0","1","1","1","1","0","1","0","1","1","1","1","0","1","0","1","0","1","1","1","1"},
    {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","P","1"},
    {"1","1","1","1","1","0","1","1","1","1","0","1","0","0","0","0","0","0","1","1","1","1"},
    {"1","0","0","0","0","0","1","0","0","0","0","1","0","0","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","1","1","1","1","1","1","0","1"},
    {"E","0","0","0","0","0","1","0","1","0","0","1","0","0","0","0","0","0","0","1","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","X","1"},
    {"1","0","0","0","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","1","1"},
    {"1","0","0","0","0","0","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","X","0","0","0","0","0","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","1","1","1","1","1","E","1","1","1","1","1","1","1","1","1"}
  };

// Mazebaord for Room 8
const char *mazeboard6[R][C] =
  {
    {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"},
    {"1","X","1","0","0","0","0","1","X","1","0","0","0","0","1","X","1","0","0","0","0","1"},
    {"1","0","1","0","0","0","0","1","0","1","0","0","0","0","1","0","1","0","0","0","0","1"},
    {"1","0","1","1","1","1","0","1","0","1","1","1","1","0","1","0","1","0","1","1","1","1"},
    {"1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","X","1"},
    {"1","1","1","1","1","0","1","1","1","1","0","1","0","0","0","0","0","0","1","1","1","1"},
    {"1","0","0","0","0","0","1","0","0","0","0","1","0","0","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","1","1","1","1","1","1","0","1"},
    {"E","0","0","0","0","0","1","0","1","0","0","1","0","0","0","0","0","0","0","1","0","1"},
    {"1","1","1","1","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","X","1"},
    {"1","0","0","0","1","0","1","0","1","0","0","1","0","1","0","0","0","0","0","1","1","1"},
    {"1","0","0","0","0","0","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","P","0","0","0","0","0","0","1","0","0","1","0","1","0","0","0","0","0","0","0","1"},
    {"1","1","1","1","1","1","1","1","1","1","1","1","E","1","1","1","1","1","1","1","1","1"}
  };

// Game Loop Variables
bool isRunning = false; // Controls if the game is running.
char direction; // Gets user input which determines the direction they move.
int playerRow = 0; // Stores the Row# that the player is in ("P")
int playerCol = 0; // Stores the Col# that the player is in ("P")
int gameLevel = 0; // Controls which room the player starts from.

// Function to Check if moving position is valid -- Shanika Code
bool isValid(int gameLevel, int newRow, int newCol) {

    // Switch Case to Determine which mazeboard (starting room) to read from.
    switch (gameLevel) {
        /*
        MAJOR IF-ELSE Statement:

        This "IF-ELSE STATEMENT" is what checks if the player is able to move into his desired direction.
        The statement is fed the position (row and column) of the new location where the player
        would like to move to. The statement then checks if that location is either a "0" or a "2"
        or a "E". If the location is any of those characters, it returns "true" allowing the player
        to move.
        ELSE, the location is not valid and the player is unable to move.

        The code below is the implementation of the above, as well as specifying what mazeboard to read from.
        */

    case 1:
        if (*mazeboard1[newRow][newCol] == '0' || *mazeboard1[newRow][newCol] == '2' || *mazeboard1[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 2:
        if (*mazeboard2[newRow][newCol] == '0' || *mazeboard2[newRow][newCol] == '2' || *mazeboard2[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 3:
        if (*mazeboard3[newRow][newCol] == '0' || *mazeboard3[newRow][newCol] == '2' || *mazeboard3[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 4:
        if (*mazeboard4[newRow][newCol] == '0' || *mazeboard4[newRow][newCol] == '2' || *mazeboard4[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 5:
        if (*mazeboard5[newRow][newCol] == '0' || *mazeboard5[newRow][newCol] == '2' || *mazeboard5[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 6:
        if (*mazeboard6[newRow][newCol] == '0' || *mazeboard6[newRow][newCol] == '2' || *mazeboard6[newRow][newCol] == 'E') return true;
        else return false;
        break;

    default:
        return false;
    }
}

// Function to Check if moving position is an exit -- Bryanna Code
bool isExit(int gameLevel, int newRow, int newCol) {

    // Switch Case to Determine which mazeboard (starting room) to read from.
    switch (gameLevel) {

        /*
        MAJOR IF-ELSE STATEMENT:

        This "IF-ELSE STATEMENT" determines if the location the player is moving to is an
        Exit. The statement is fed the location to which the player would like to move to
        (row and column) and reads to see if it is an "E". If the location is an exit, it
        will return "true".
        ELSE, the game shall continue since the player has not exited the maze as yet.

        The following code is an implentation of above as well as specifying what mazeboard
        to read from.
        */

    case 1:
        if (*mazeboard1[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 2:
        if (*mazeboard2[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 3:
        if (*mazeboard3[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 4:
        if (*mazeboard4[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 5:
        if (*mazeboard5[newRow][newCol] == 'E') return true;
        else return false;
        break;

    case 6:
        if (*mazeboard6[newRow][newCol] == 'E') return true;
        else return false;
        break;

    default:
        return false;
    }
}

//Function to find the player's position in the mazeboard array -- Garson Code
void findPlayer(int gameLevel) {

    // Switch Case to Determine which mazeboard (starting room) to read from.
    switch (gameLevel) {

        /*
        MAJOR FOR LOOP STRUCTURE:
        This "FOR LOOP STRUCTURE" cycles through the appropriate mazeboard in order to find
        the player location (the "P" in the mazeboard array). Once the location (the "P" in
        the mazeboard array) is found, its indices are recorded in the "playerRow" and
        "playerCol" variables ('i' being the index of the Row and 'i2' being the index of
        the Column).

        The following code is an implementation of the above as well as specifying which
        mazeboard to read from.
        */

    case 1:
        for (int i = 0; i < R; i++) {
            for (int i2 = 0; i2 < C; i2++) {
                if (*mazeboard1[i][i2] == 'P') {
                    playerRow = i; // Row Value
                    playerCol = i2; // Col Value
                }
            }
        }
        break;

    case 2:
        for (int i = 0; i < R; i++) {
            for (int i2 = 0; i2 < C; i2++) {
                if (*mazeboard2[i][i2] == 'P') {
                    playerRow = i; // Row Value
                    playerCol = i2; // Col Value
                }
            }
        }
        break;

    case 3:
        for (int i = 0; i < R; i++) {
            for (int i2 = 0; i2 < C; i2++) {
                if (*mazeboard3[i][i2] == 'P') {
                    playerRow = i; // Row Value
                    playerCol = i2; // Col Value
                }
            }
        }
        break;

    case 4:
        for (int i = 0; i < R; i++) {
            for (int i2 = 0; i2 < C; i2++) {
                if (*mazeboard4[i][i2] == 'P') {
                    playerRow = i; // Row Value
                    playerCol = i2; // Col Value
                }
            }
        }
        break;

    case 5:
        for (int i = 0; i < R; i++) {
            for (int i2 = 0; i2 < C; i2++) {
                if (*mazeboard5[i][i2] == 'P') {
                    playerRow = i; // Row Value
                    playerCol = i2; // Col Value
                }
            }
        }
        break;

    case 6:
        for (int i = 0; i < R; i++) {
            for (int i2 = 0; i2 < C; i2++) {
                if (*mazeboard6[i][i2] == 'P') {
                    playerRow = i; // Row Value
                    playerCol = i2; // Col Value
                }
            }
        }
        break;
    }
}

// Basic Game Function Code -- Chris Code
void gameFunction(int gameLevel, int newRow, int newCol) {

    // Switch Case to Determine which mazeboard (starting room) to read from.
    switch (gameLevel) {
        /*
        MAJOR NESTED IF-ELSE STATEMENT:

        This "NESTED IF-ELSE STATEMENT" is the basic function of the game. First, it accepts all
        the values that the game requires (i.e. the game level [which mazeboard to read from] and
        the desired location the player would like to move to [the row and column values]) then
        perform the necessary checks using the "isValid" function and "isExit" function (see above).

        If "isValid" and "isExit" are both true, the game prompts the user that they have won.
        If "isValid" is true but "isExit" is false, the game moves the player to the new location.
        If "isValid" is false, the player does not move at all and is prompted to move elsewhere.

        The following code is an implementation of the above as well as specifying what mazeboard
        to read from.
        */

    case 1:
        if (isValid(gameLevel, newRow, newCol)) {
            if (isExit(gameLevel, newRow, newCol)) {
                isRunning = false;
                mazeboard1[playerRow][playerCol] = "2";		//Repesentation of each move by Player
                mazeboard1[newRow][newCol] = "P";			//Player position in each maze
                system("cls");
                for (int x1 = 0; x1 < R; x1++)				//For loop to capture each move by player- X-axis coordinates and how to handle count
                {
                    for (int y1 = 0; y1 < C; y1++)			//Y-axis coordinates and how to handle count
                    {
                        if (mazeboard1[x1][y1] == "2")		//when x and Y equals 2 add to counter
                        {
                            counter1++;						//counter to store each valid move by player
                        }
                    }
                }
                if (counter1 - 1 > 16)						//shortest path is less than 16 so if count is greater , print below
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nBut this was not the shortest path in Room 1, " << counter1 << " Hops \n\n\n";
                }
                if (counter1 - 1 <= 16)						//shortest path is less than or equal 16 so if count is less , print below
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nThis is the shortest path in Room 1, " << counter1 << "Hops \n\n\n";
                }
                displayMaze(gameLevel);
                system("pause");
                system("cls");
            }
            else {
                mazeboard1[playerRow][playerCol] = "2";
                mazeboard1[newRow][newCol] = "P";
                system("cls");
            }
        }
        else {
            system("cls");
            cout << "Invalid Move. Try Again.\n";
        }
        break;

    case 2:
        if (isValid(gameLevel, newRow, newCol)) {
            if (isExit(gameLevel, newRow, newCol)) {
                isRunning = false;
                mazeboard2[playerRow][playerCol] = "2";
                mazeboard2[newRow][newCol] = "P";
                system("cls");
                for (int x1 = 0; x1 < R; x1++)
                {
                    for (int y1 = 0; y1 < C; y1++)
                    {
                        if (mazeboard2[x1][y1] == "2")
                        {
                            counter2++;
                        }
                    }
                }
                if (counter2 - 1 > 15)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nBut this was not the shortest path in Room 3, " << counter2 << " Hops \n\n\n";
                }
                if (counter2 - 1 <= 15)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nThis is the shortest path in Room 3, " << counter2 << "Hops \n\n\n";
                }
                displayMaze(gameLevel);
                system("pause");
                system("cls");
            }
            else {
                mazeboard2[playerRow][playerCol] = "2";
                mazeboard2[newRow][newCol] = "P";
                system("cls");
            }
        }
        else {
            system("cls");
            cout << "Invalid Move. Try Again.\n";
        }
        break;

    case 3:
        if (isValid(gameLevel, newRow, newCol)) {
            if (isExit(gameLevel, newRow, newCol)) {
                isRunning = false;
                mazeboard3[playerRow][playerCol] = "2";
                mazeboard3[newRow][newCol] = "P";
                system("cls");
                for (int x1 = 0; x1 < R; x1++)
                {
                    for (int y1 = 0; y1 < C; y1++)
                    {
                        if (mazeboard3[x1][y1] == "2")
                        {
                            counter3++;
                        }
                    }
                }
                if (counter3 - 1 > 16)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nBut this was not the shortest path in Room 5, " << counter3 << " Hops \n\n\n";
                }
                if (counter3 - 1 <= 16)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nThis is the shortest path in Room 5, " << counter3 << "Hops \n\n\n";
                }
                displayMaze(gameLevel);
                system("pause");
                system("cls");
            }
            else {
                mazeboard3[playerRow][playerCol] = "2";
                mazeboard3[newRow][newCol] = "P";
                system("cls");
            }
        }
        else {
            system("cls");
            cout << "Invalid Move. Try Again.\n";
        }
        break;

    case 4:
        if (isValid(gameLevel, newRow, newCol)) {
            if (isExit(gameLevel, newRow, newCol)) {
                isRunning = false;
                mazeboard4[playerRow][playerCol] = "2";
                mazeboard4[newRow][newCol] = "P";
                system("cls");
                for (int x1 = 0; x1 < R; x1++)
                {
                    for (int y1 = 0; y1 < C; y1++)
                    {
                        if (mazeboard4[x1][y1] == "2")
                        {
                            counter4++;
                        }
                    }
                }
                if (counter4 - 1 > 19)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nBut this was not the shortest path in Room 6, " << counter4 << " Hops \n\n\n";
                }
                if (counter4 - 1 <= 19)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nThis is the shortest path in Room 6, " << counter4 << "Hops \n\n\n";
                }
                displayMaze(gameLevel);
                system("pause");
                system("cls");
            } 
			else {
                mazeboard4[playerRow][playerCol] = "2";
                mazeboard4[newRow][newCol] = "P";
                system("cls");
            }
        }
        else {
            system("cls");
            cout << "Invalid Move. Try Again.\n";
        }
        break;

    case 5:
        if (isValid(gameLevel, newRow, newCol)) {
            if (isExit(gameLevel, newRow, newCol)) {
                isRunning = false;
                mazeboard5[playerRow][playerCol] = "2";
                mazeboard5[newRow][newCol] = "P";
                system("cls");
                for (int x1 = 0; x1 < R; x1++)
                {
                    for (int y1 = 0; y1 < C; y1++)
                    {
                        if (mazeboard5[x1][y1] == "2")
                        {
                            counter5++;
                        }
                    }
                }
                if (counter5 - 1 > 18)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nBut this was not the shortest path in Room 7, " << counter5 << " Hops \n\n\n";
                }
                if (counter5 - 1 <= 18)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nThis is the shortest path in Room 7, " << counter5 << "Hops \n\n\n";
                }
                displayMaze(gameLevel);
                system("pause");
                system("cls");
            }
            else {
                mazeboard5[playerRow][playerCol] = "2";
                mazeboard5[newRow][newCol] = "P";
                system("cls");
            }
        }
        else {
            system("cls");
            cout << "Invalid Move. Try Again.\n";
        }
        break;

    case 6:
        if (isValid(gameLevel, newRow, newCol)) {
            if (isExit(gameLevel, newRow, newCol)) {
                isRunning = false;
                mazeboard6[playerRow][playerCol] = "2";
                mazeboard6[newRow][newCol] = "P";
                system("cls");
                for (int x1 = 0; x1 < R; x1++)
                {
                    for (int y1 = 0; y1 < C; y1++)
                    {
                        if (mazeboard6[x1][y1] == "2")
                        {
                            counter6++;
                        }
                    }
                }
                if (counter6 - 1 > 30)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nBut this was not the shortest path in Room 8, " << counter6 << " Hops \n\n\n";
                }
                if (counter6 - 1 <= 30)
                {
                    cout << "Congratulations! You Found the Exit! \n\n\nThis is the shortest path in Room 8, " << counter6 << "Hops \n\n\n";
                }
                displayMaze(gameLevel);
                system("pause");
                system("cls");
            }
            else {
                mazeboard6[playerRow][playerCol] = "2";
                mazeboard6[newRow][newCol] = "P";
                system("cls");
            }
        }
        else {
            system("cls");
            cout << "Invalid Move. Try Again.\n";
        }
        break;
    }
}

// Function to start the game and control direction 
void startGame(int gameLevel)
{
    /*
	MAJOR SWITCH STATEMENT:

    This switch statement controls what direction the player moves. When the player enters
    "W", "A", "S" or "D", the switch processes the following:

    If "W" is entered, the new position above the player character ("P") is calculated and
    is passed to the "gameFunction" function to continue the processing of the game logic
    (see above)

    If "A" is entered, the new position left the player character ("P") is calculated and
    is passed to the "gameFunction" function to continue the processing of the game logic
    (see above)

    If "S" is entered, the new position below the player character ("P") is calculated and
    is passed to the "gameFunction" function to continue the processing of the game logic
    (see above)

    If "D" is entered, the new position right the player character ("P") is calculated and
    is passed to the "gameFunction" function to continue the processing of the game logic
    (see above)

    If any other key is entered, the game exits and returns to the main menu.

    The following code is an implementation of the above.
    */

    int newRow, newCol;
    isRunning = true;
    while (isRunning) {
        displayMaze(gameLevel);
        cin >> direction;
        switch (direction) {
			case 'W':
			case 'w':
			{
				findPlayer(gameLevel);
				newRow = playerRow - 1;
				newCol = playerCol;
				gameFunction(gameLevel, newRow, newCol);
				break;
			}

			case 'A':
			case 'a':
			{
				findPlayer(gameLevel);
				newRow = playerRow;
				newCol = playerCol - 1;
				gameFunction(gameLevel, newRow, newCol);
				break;
			}

			case 'S':
			case 's':
			{
				findPlayer(gameLevel);
				newRow = playerRow + 1;
				newCol = playerCol;
				gameFunction(gameLevel, newRow, newCol);
				break;
			}

			case 'D':
			case 'd':
			{
				findPlayer(gameLevel);
				newRow = playerRow;
				newCol = playerCol + 1;
				gameFunction(gameLevel, newRow, newCol);
				break;
			}

			default:
			{
				isRunning = false;
				system("pause");
				system("cls");
				break;
			}
        }
    }
}

// Function to print the maze
void displayMaze(int gameLevel)
{
    // Switch Case to Determine which mazeboard (starting room) to print.
    switch (gameLevel)
    {
        /*
		MAJOR FOR LOOP STRUCTURE:

        The FOR LOOP STRUCTURE print out each row and column by cycling through the array.

        Below is the implentation of above as well as specifying what mazeboard to print from.
        */

    case 1:
        for (int index = 0; index <= 14; index++)
        {
            for (int j = 0; j <= 21; j++)
            {
                cout << mazeboard1[index][j] << " ";
            }
            cout << endl;
        }
		cout << "\n\nYou are in Room 1";
        cout << "\nW - Up\tA - Left\tS - Down\tD - Right\tAny Key To Exit\nEnter a direction: ";
        break;

    case 2:
        for (int index = 0; index <= 14; index++)
        {
            for (int j = 0; j <= 21; j++)
            {
                cout << mazeboard2[index][j] << " ";
            }
            cout << endl;
        }
		cout << "\n\nYou are in Room 3";
        cout << "\n\n\nW - Up\tA - Left\tS - Down\tD - Right\tAny Key To Exit\nEnter a direction: ";
        break;

    case 3:
        for (int index = 0; index <= 14; index++)
        {
            for (int j = 0; j <= 21; j++)
            {
                cout << mazeboard3[index][j] << " ";
            }
            cout << endl;
        }
		cout << "\n\nYou are in Room 5";
        cout << "\n\n\nW - Up\tA - Left\tS - Down\tD - Right\tAny Key To Exit\nEnter a direction: ";
        break;

    case 4:
        for (int index = 0; index <= 14; index++)
        {
            for (int j = 0; j <= 21; j++)
            {
                cout << mazeboard4[index][j] << " ";
            }
            cout << endl;
        }
		cout << "\n\nYou are in Room 6";
        cout << "\n\n\nW - Up\tA - Left\tS - Down\tD - Right\tAny Key To Exit\nEnter a direction: ";
        break;

    case 5:
        for (int index = 0; index <= 14; index++)
        {
            for (int j = 0; j <= 21; j++)
            {
                cout << mazeboard5[index][j] << " ";
            }
            cout << endl;
        }
		cout << "\n\nYou are in Room 7";
        cout << "\n\n\nW - Up\tA - Left\tS - Down\tD - Right\tAny Key To Exit\nEnter a direction: ";
        break;

    case 6:
        for (int index = 0; index <= 14; index++)
        {
            for (int j = 0; j <= 21; j++)
            {
                cout << mazeboard6[index][j] << " ";
            }
            cout << endl;
        }
		cout << "\n\nYou are in Room 8";
        cout << "\n\n\nW - Up\tA - Left\tS - Down\tD - Right\tAny Key To Exit\nEnter a direction: ";
        break;

    default:
        break;
    }
}

// Function to print the game instruction.
void gameinstruction()
{
    //Instructions:
    cout << "This is a maze game\n\n"
		 << "The objective of this game is to move your character \"P\" from your starting position\n"
         << "to an exit \"E\"\n\n"
         << "To do this, you must select either W, A, S or D, then press enter to lock in a direction\n"
         << "Press any other key to exit to the main menu at any time.\n\n";
}

// Main Function
int main()
{
    int choice;
    do {
        system("color 3f"); // Changes the Console Color
		cout << "\t\t__________________________________________________________\n" << endl /* Welcome Screen*/
			 << "\t\t" << " ************  WELCOME TO DSAFM MAZE MANIA  ************" << endl
			 << "\t\t___________________________________________________________\n\n" << endl;
        
		cout << "\t\t\t -_-_-_-_--_-_-_-_-_-_-_-_-_-_-_-_\n" << endl;
        cout << " \t\t\t -_-_ BELOW ARE YOUR OPTIONS-_-_-_\n"; //This allowa you to choose which room you which to start playing the game from.
        cout << "\t\t\t -_-_-_-_--_-_-_-_-_-_-_-_-_-_-_-_\n" << endl << endl;

        cout << "\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << "\t\tPress 1 to Enter Room 1:  " << endl; //Entrance to Room 1
        cout << "\t\tPress 2 to Enter Room 3:  " << endl; //Entrance to Room 2
        cout << "\t\tPress 3 to Enter Room 5:  " << endl; //Entrance to Room 3
        cout << "\t\tPress 4 to Enter Room 6:  " << endl; //Entrance to Room 4
        cout << "\t\tPress 5 to Enter Room 7:  " << endl; //Entrance to Room 5
        cout << "\t\tPress 6 to Enter Room 8:  " << endl; //Entrance to Room 5
        cout << "\t\tPress 7 to Read Instruction " << endl; //Provides a list of instructions to assist with playing the game.
        cout << "\t\tPress 8 to Exit Game:  " << endl; //Exits maze
        cout << "\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        
		cout << endl;
        cin >> choice; //Accept users input

        system("cls"); // Clears the Screen

		// Menu Switch Statement
        switch (choice) {        
		case 1:
            gameLevel = 1; // Sets the game level
            startGame(gameLevel);
            break;
        
		case 2:
            gameLevel = 2; // Sets the game level
            startGame(gameLevel);
            break;

        case 3:
            gameLevel = 3; // Sets the game level
            startGame(gameLevel);
            break;

        case 4:
            gameLevel = 4; // Sets the game level
            startGame(gameLevel);
            break;

        case 5:
            gameLevel = 5; // Sets the game level
            startGame(gameLevel);
            break;

        case 6:
            gameLevel = 6; // Sets the game level
            startGame(gameLevel);
            break;

        case 7:
            gameinstruction();
            system("pause"); // Pauses the console
            system("cls"); // Clears the screen
            break;

        case 8:
            system("cls");
            cout << "Thank you for playing\n\n\n Good Bye!\n\n\n\n";
            system("pause");
            break;

        default:
            cout << "Invalid Selection. Try again \n";
            system("pause");
            system("cls"); // Clears the Screen
            break;
        }
    } while (choice != 8);
}