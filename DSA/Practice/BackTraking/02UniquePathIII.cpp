#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int m, n;
    int result;
    int nonobstacles;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Function to perform backtracking
    void backtrack(vector<vector<int>>& grid, int count, int i, int j) {
        // If out of bounds or hits an obstacle or visited square, return
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) {
            return;
        }

        // If we reach the end square (grid[i][j] == 2)
        if (grid[i][j] == 2) {
            // Only consider it a valid path if we have visited all non-obstacle squares
            if (count == nonobstacles) {
                result++;
            }
            return;
        }

        // Mark the current square as visited
        int temp = grid[i][j];  // Save current cell value to restore later
        grid[i][j] = -1;        // Mark it visited by setting it to -1

        // Explore all 4 possible directions
        for (vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            backtrack(grid, count + 1, new_i, new_j);
        }

        // Backtrack: Restore the current square's original value
        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();       // Number of rows
        n = grid[0].size();    // Number of columns
        result = 0;
        nonobstacles = 0;

        int start_x = 0, start_y = 0;
        
        // Count non-obstacle squares and find the starting square
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    nonobstacles++; // Count the number of non-obstacle cells
                }
                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;    // Save the coordinates of the start cell
                }
            }
        }

        // Include the start square in the count of non-obstacles
        nonobstacles++;  // Include the starting square in the count
        int count = 0;

        // Start the backtracking from the start square
        backtrack(grid, count, start_x, start_y);
        
        return result;
    }
};

// Main function to demonstrate the solution
int main() {
    Solution solution;

    // Example grid input
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };

    // Call uniquePathsIII and print the result
    int result = solution.uniquePathsIII(grid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
