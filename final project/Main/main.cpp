#include <iostream>
using namespace std;

// Global 3x3 board ( ' ' = empty, 'X' = player 1, 'O' = player 2 )
char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

char currentPlayer = 'X';  // Starts with player X

// Function to display the board
void displayBoard() {
    cout << "\n";
    cout << "     1   2   3\n";
    cout << "   -------------\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << (i + 1) << " | ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n   -------------\n";
    }
    cout << "\n";  
}

// Function to check if the chosen position is valid and empty
bool isValidMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false;  // Out of bounds
    }
    if (board[row][col] != ' ') {
        return false;  // Already occupied
    } 
    return true;
}

// Function to make a move
void makeMove(int row, int col) {
    board[row][col] = currentPlayer;
}

// Function to check for a winner (rows, columns, diagonals)
bool checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == currentPlayer &&
            board[1][j] == currentPlayer &&
            board[2][j] == currentPlayer) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer) {
        return true;
    }
    
    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer) {
        return true;
    }

    return false;
}

// Function to check if the board is full (draw)
bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // Still empty space
            } 
        }
    }
    return true;
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to reset the board for a new game
void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

int main() {
    char playAgain = 'y';

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Players take turns entering row and column (1-3).\n";

    while (playAgain == 'y' || playAgain == 'Y') {
        resetBoard();
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            cout << "Player " << currentPlayer << "'s turn.\n";
            int row, col;

            // Input validation loop
            while (true) {
                cout << "Enter row (1-3): ";
                cin >> row;
                cout << "Enter column (1-3): ";
                cin >> col;

                row--;  // Convert to 0-based index
                col--;

                if (isValidMove(row, col)) {
                    break;
                } else {
                    cout << "Invalid move! Cell is occupied or out of bounds. Try again.\n";
                }
            }

            makeMove(row, col);

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins! Congratulations!\n";
                gameOver = true;
            } else if (isDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing! Goodbye.\n";
    return 0;
}