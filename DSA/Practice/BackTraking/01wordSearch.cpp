#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m, n; // Class member variables for rows and columns
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}}; // Directions for moving up, down, left, and right

    // Helper function to search for the word recursively
    bool find(vector<vector<char>>& board, int i, int j, int idx, string word) {
        if (idx == word.length()) // If all characters are found, return true
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') // Check boundaries and avoid revisiting cells
            return false;
        if (board[i][j] != word[idx]) // Check if current character matches
            return false;

        char temp = board[i][j]; // Temporarily mark the cell as visited
        board[i][j] = '$';

        // Explore all four possible directions
        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(board, new_i, new_j, idx + 1, word)) // Recursive call to check the next character
                return true;
        }

        board[i][j] = temp; // Restore the cell's original value
        return false;
    }

    // Main function to check if the word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); // Initialize member variable m
        n = board[0].size(); // Initialize member variable n

        // Iterate through each cell in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start DFS if the first character matches
                if (board[i][j] == word[0] && find(board, i, j, 0, word))
                    return true;
            }
        }

        return false; // Return false if the word cannot be found
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEE";
    Solution solution;
    cout<<solution.exist(board,word)<<endl;
    return 0;
}
