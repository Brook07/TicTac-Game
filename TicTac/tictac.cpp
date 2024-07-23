#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

bool checkWin(const vector<char>& board, char player) {
    vector<vector<int>> winPatterns = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };
    
    for (auto& pattern : winPatterns) {
        if (board[pattern[0]] == player && board[pattern[1]] == player && board[pattern[2]] == player) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

void playerMove(vector<char>& board, char player) {
    int move;
    while (true) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        if (move >= 1 && move <= 9 && board[move - 1] == '1' + (move - 1)) {
            board[move - 1] = player;
            break;
        } else {
            cout << "Invalid move, try again.\n";
        }
    }
}

int main() {
    vector<char> board(9);
    for (int i = 0; i < 9; ++i) {
        board[i] = '1' + i;
    }

    string player1, player2;
    cout << "Enter Player 1 name: ";
    cin >> player1;
    cout << "Enter Player 2 name: ";
    cin >> player2;

    int player1Score = 0, player2Score = 0;
    char playAgain;

    do {
        char currentPlayer = 'X';
        bool gameWon = false;

        for (int i = 0; i < 9; ++i) {
            board[i] = '1' + i;
        }

        while (true) {
            displayBoard(board);
            playerMove(board, currentPlayer);

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                if (currentPlayer == 'X') {
                    cout << player1 << " (X) wins!\n";
                    player1Score++;
                } else {
                    cout << player2 << " (O) wins!\n";
                    player2Score++;
                }
                gameWon = true;
                break;
            }

            if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Scores:\n" << player1 << ": " << player1Score << "\n" << player2 << ": " << player2Score << "\n";
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y');

    cout << "Thanks for playing! Final scores:\n" << player1 << ": " << player1Score << "\n" << player2 << ": " << player2Score << "\n";
    return 0;
}
