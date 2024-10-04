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

void solveNQueens(vector<vector<bool>>& board, int col, int n, vector<vector<string>>& solutions) {
    if (col >= n) {
        
        vector<string> solution;
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
        solutions.push_back(solution);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = true;
            solveNQueens(board, col + 1, n, solutions);
            board[i][col] = false;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (N): ";
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<vector<string>> solutions;

    solveNQueens(board, 0, n, solutions);

    cout << "Solutions:" << endl;
    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) {
            cout << solutions[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
