#include <iostream>
#include <vector>

using namespace std;

void printSolution(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

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
        // A solution is found, print it
        printSolution(board);
        cout << "-------------------" << endl;
        return true;
    }

    bool foundSolution = false;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1; // Place the Queen

            // foundSolution = solveNQueens(board, col + 1, n) || foundSolution;
            if(solveNQueens(board, col + 1, n)==true)
            {
                foundSolution=true;
            }

            board[i][col] = 0; // Backtrack
        }
    }

    return foundSolution;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0, n)) {
        cout << "All solutions for n = " << n << " have been printed." << endl;
    } else {
        cout << "No solution exists for n = " << n << "." << endl;
    }

    return 0;
}
