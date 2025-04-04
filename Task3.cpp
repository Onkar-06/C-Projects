#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to display the game board
void displayBoard(const vector<char>& board) {
    cout << "\n  Tic-Tac-Toe Board\n";
    for (int i = 0; i < 3; ++i) {
        cout << "  " << board[i * 3] << " | " << board[i * 3 + 1] << " | " << board[i * 3 + 2] << "\n";
        if (i < 2) cout << " ---|---|---\n";
    }
    cout << endl;
}

// Check if the current player has won
bool checkWin(const vector<char>& board, char player) {
    // Winning conditions: rows, columns, diagonals
    for (int i = 0; i < 3; ++i) {
        if ((board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) ||
            (board[i] == player && board[i + 3] == player && board[i + 6] == player)) {
            return true;
        }
    }
    return (board[0] == player && board[4] == player && board[8] == player) || 
           (board[2] == player && board[4] == player && board[6] == player);
}

// Check if the board is full (draw)
bool checkDraw(const vector<char>& board) {
    return all_of(board.begin(), board.end(), [](char c) { return c != ' '; });
}

int main() {
    char playAgain;
    do {
        vector<char> board(9, ' '); // Empty 3x3 board
        char currentPlayer = 'X';
        int move;
        
        cout << "Welcome to Tic-Tac-Toe!\n";
        
        while (true) {
            displayBoard(board);
            cout << "Player " << currentPlayer << ", enter a move (1-9): ";
            cin >> move;

            // Input validation
            if (cin.fail() || move < 1 || move > 9 || board[move - 1] != ' ') {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Oops! Invalid move. Try again.\n";
                continue;
            }

            board[move - 1] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "🎉 Player " << currentPlayer << " wins! Congratulations! 🎉\n";
                break;
            }

            if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw! No more moves left.\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch turns
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        cin.ignore(); 

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! See you next time. 👋\n";
    return 0;
}
