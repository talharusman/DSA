#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<char>>& mat, vector<vector<bool>>& visited, int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || mat[x][y] != 'T' || visited[x][y]) {
        return 0;
    }

    visited[x][y] = true;
    int size = 1;

    size += dfs(mat, visited, x + 1, y, n, m); // Down
    size += dfs(mat, visited, x - 1, y, n, m); // Up
    size += dfs(mat, visited, x, y + 1, n, m); // Right
    size += dfs(mat, visited, x, y - 1, n, m); // Left

    return size;
}

int largestForest(vector<vector<char>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int maxForestSize = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'T' && !visited[i][j]) {
                int forestSize = dfs(mat, visited, i, j, n, m);
                maxForestSize = max(maxForestSize, forestSize);
            }
        }
    }
    return maxForestSize;
}

int main() {
    vector<vector<char>> mat = {
        {'T', 'W', 'W', 'W'},
        {'T', 'T', 'W', 'T'},
        {'T', 'T', 'W', 'W'},
        {'W', 'T', 'T', 'T'}
    };

    int result = largestForest(mat);
    cout << "Size of the largest forest: " << result << endl;

    return 0;
}
