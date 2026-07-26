#include <iostream>                  // Includes the input/output stream library (needed for cout, cin)
using namespace std;                  // Allows us to use cout, cin, etc. without writing "std::" every time

// Global 3x3 board ( ' ' = empty, 'X' = player 1, 'O' = player 2 )
char board[3][3] = {{' ', ' ', ' '},   // Row 0: three empty spaces
                    {' ', ' ', ' '},   // Row 1: three empty spaces
                    {' ', ' ', ' '}};  // Row 2: three empty spaces

char currentPlayer = 'X';             // Tracks whose turn it is; game always starts with player X

// Function to display the board on the screen
void displayBoard() {
    cout << "\n";                     // Prints a blank line for better spacing
    cout << "     1   2   3\n";        // Prints column numbers at the top for user guidance
    cout << "   -------------\n";      // Prints a horizontal separator line
    for (int i = 0; i < 3; i++) {      // Loops through each row (i = 0 to 2)
        cout << " " << (i + 1) << " | "; // Prints row number (1, 2, 3) followed by a divider
        for (int j = 0; j < 3; j++) {  // Loops through each column in the current row
            cout << board[i][j];      // Prints the content of the cell (X, O, or space)
            if (j < 2) cout << " | "; // Prints vertical separator after columns 1 and 2 (not after 3)
        }
        cout << "\n   -------------\n"; // Prints horizontal separator after each row
    }
    cout << "\n";                     // Extra blank line at the end for clean look
}

// Function to check if the chosen position is valid and empty
bool isValidMove(int row, int col) {
    if (row < 0  row >= 3  col < 0  col >= 3) {  // Checks if row or col is outside 0-2 range
        return false;              // Invalid: out of board boundaries
    }
    if (board[row][col] != ' ') {  // Checks if the cell already has X or O
        return false;              // Invalid: cell is already occupied
    }
    return true;                   // Valid: cell is empty and within bounds
}

// Function to place the current player's mark on the board
void makeMove(int row, int col) {
    board[row][col] = currentPlayer;  // Puts 'X' or 'O' in the chosen position
}

// Function to check if the current player has won (rows, columns, diagonals)
bool checkWin() {
    // Check all 3 rows for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&     // If all three cells in this row
            board[i][1] == currentPlayer &&     // are the same as current player
            board[i][2] == currentPlayer) {
            return true;                        // Yes → current player wins
        }
    }

    // Check all 3 columns for a win
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == currentPlayer &&     // If all three cells in this column
            board[1][j] == currentPlayer &&     // are the same as current player
            board[2][j] == currentPlayer) {
            return true;                        // Yes → current player wins
        }
    }

    // Check main diagonal (top-left to bottom-right)
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer) {
        return true;                            // Diagonal win
    }

    // Check anti-diagonal (top-right to bottom-left)
    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer) {
        return true;                            // Diagonal win
    }

    return false;                               // No winning pattern found
}

// Function to check if the board is completely full (no empty spaces left)
bool isDraw() {
    for (int i = 0; i < 3; i++) {               // Loop through every row

for (int j = 0; j < 3; j++) {           // Loop through every column
            if (board[i][j] == ' ') {          // If we find any empty space
                return false;                  // Not a draw yet (game can continue)
            }
        }
    }
    return true;
// No empty spaces → it's a draw
}

// Function to switch turns between players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // Ternary operator: if X → switch to O, else to X
}

// Function to clear the board and reset the starting player for a new game
void resetBoard() {
    for (int i = 0; i < 3; i++) {               // Loop through all rows
        for (int j = 0; j < 3; j++) {           // Loop through all columns
            board[i][j] = ' ';                 // Set every cell to empty
        }
    }
    currentPlayer = 'X';                       // Always start new game with player X
}

// Main function — program starts and ends here
int main() {
    char playAgain = 'y';                      // Controls whether to play multiple games

    cout << "Welcome to Tic-Tac-Toe!\n";       // Welcome message
    cout << "Players take turns entering row and column (1-3).\n";  // Instructions

    while (playAgain == 'y'  playAgain == 'Y') {  // Loop to allow playing again
        resetBoard();                          // Clear board and set player to X
        bool gameOver = false;                 // Tracks if current game has ended

        while (!gameOver) {                    // Main game loop — continues until win or draw
            displayBoard();                    // Show current state of the board
            cout << "Player " << currentPlayer << "'s turn.\n";  // Tell whose turn it is
            int row, col;                      // Variables to store user input

            // Input validation loop — keeps asking until a valid move is made
            while (true) {
                cout << "Enter row (1-3): ";   // Prompt for row
                cin >> row;                    // Read row input
                cout << "Enter column (1-3): ";// Prompt for column
                cin >> col;                    // Read column input

                row--;                         // Convert from 1-3 (user-friendly) to 0-2 (array index)
                col--;

                if (isValidMove(row, col)) {   // If the move is allowed
                    break;                     // Exit the input loop → proceed
                } else {
                    cout << "Invalid move! Cell is occupied or out of bounds. Try again.\n";
                }
            }

            makeMove(row, col);                // Place X or O on the board

            if (checkWin()) {                  // Check if current player just won
                displayBoard();                // Show final board
                cout << "Player " << currentPlayer << " wins! Congratulations!\n";
                gameOver = true;               // End the game
            } else if (isDraw()) {             // Check if board is full with no winner
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();                // No one won yet → next player's turn
            }
        }

        cout << "Do you want to play again? (y/n): ";  // Ask if user wants another game
        cin >> playAgain;                  // Read answer (y/Y to continue)
    }

    cout << "Thanks for playing! Goodbye.\n";  // Farewell message when quitting
    return 0;                              // End program successfully
}

 