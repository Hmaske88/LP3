#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check the left side of the current column
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    if (col >= n) {
        return true; // All Queens are placed successfully.
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1; // Place the Queen

            if (solveNQueens(board, col + 1, n)) {
                return true; // Recur to place the remaining Queens
            }

            board[i][col] = 0; // Backtrack if no solution is found
        }
    }

    return false; // No solution found in this column
}

void printSolution(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0, n)) {
        cout << "N-Queens solution for n = " << n << ":" << endl;
        printSolution(board);
    } else {
        cout << "No solution exists for n = " << n << "." << endl;
    }

    return 0;
}
