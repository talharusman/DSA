#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<bool>>& board, int row, int col, int n) {
    // Check this row on left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(vector<vector<bool>>& board, int col, int n, vector<string>& solution) {
    if (col >= n) {
        // Store the solution when all queens are placed
        for (int i = 0; i < n; i++) {
            string row;
            for (int j = 0; j < n; j++) {
                if (board[i][j])
                    row += "Q ";
                else
                    row += ". ";
            }
            solution.push_back(row);
        }
        return true; // Solution found, stop further processing
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = true;

            // If a solution is found, return immediately
            if (solveNQueens(board, col + 1, n, solution))
                return true;

            board[i][col] = false; // Backtrack
        }
    }

    return false; 
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (N): ";
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<string> solution;

    if (solveNQueens(board, 0, n, solution)) {
        cout << "One solution:" << endl;
        for (int i = 0; i < n; i++) {
            cout << solution[i] << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
