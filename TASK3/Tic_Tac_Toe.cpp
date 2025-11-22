#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<char> board;
    char currentPlayer;

public:
    TicTacToe() {
        resetBoard();
    }

    void resetBoard() {
        board = {'1','2','3','4','5','6','7','8','9'};
        currentPlayer = 'X';
    }

    void showBoard() {
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            cout << " " << board[i] << " ";
            if ((i + 1) % 3 == 0 && i != 8) {
                cout << "\n-----------\n";
            } else if ((i + 1) % 3 != 0) {
                cout << "|";
            }
        }
        cout << "\n\n";
    }

    bool isValidMove(int pos) {
        return pos >= 1 && pos <= 9 && board[pos - 1] == ('0' + pos);
    }

    void makeMove(int pos) {
        board[pos - 1] = currentPlayer;
    }

    bool checkWin() {
        int winPatterns[8][3] = {
            {0,1,2}, {3,4,5}, {6,7,8}, // rows
            {0,3,6}, {1,4,7}, {2,5,8}, // cols
            {0,4,8}, {2,4,6}           // diagonals
        };

        for (auto &pattern : winPatterns) {
            if (board[pattern[0]] == currentPlayer &&
                board[pattern[1]] == currentPlayer &&
                board[pattern[2]] == currentPlayer)
                return true;
        }
        return false;
    }

    bool checkDraw() {
        for (char c : board) {
            if (c >= '1' && c <= '9') return false;
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        while (true) {
            showBoard();
            cout << "Player " << currentPlayer << ", pick a position (1-9): ";
            
            int pos;
            cin >> pos;

            if (!isValidMove(pos)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            makeMove(pos);

            if (checkWin()) {
                showBoard();
                cout << " Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw()) {
                showBoard();
                cout << " It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    char choice;

    do {
        game.resetBoard();
        game.playGame();

        cout << "Play again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
