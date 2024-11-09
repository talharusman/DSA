#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& mat, vector<vector<bool>>& visited, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]);
}

void findPaths(int x, int y, vector<vector<int>>& mat, vector<vector<bool>>& visited, int n, string path, vector<string>& paths) {
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    visited[x][y] = true;

    // Move Down
    if (isSafe(x + 1, y, mat, visited, n)) {
        findPaths(x + 1, y, mat, visited, n, path + 'D', paths);
    }

    // Move Left
    if (isSafe(x, y - 1, mat, visited, n)) {
        findPaths(x, y - 1, mat, visited, n, path + 'L', paths);
    }

    // Move Right
    if (isSafe(x, y + 1, mat, visited, n)) {
        findPaths(x, y + 1, mat, visited, n, path + 'R', paths);
    }

    // Move Up
    if (isSafe(x - 1, y, mat, visited, n)) {
        findPaths(x - 1, y, mat, visited, n, path + 'U', paths);
    }
    visited[x][y] = false;
}
vector<string> findAllPaths(vector<vector<int>>& mat, int n) {
    vector<string> paths;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    if (mat[0][0] == 1) {
        findPaths(0, 0, mat, visited, n, "", paths);
    }
    return paths;
}

int main() {
    int n = 4;
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = findAllPaths(mat, n);
    cout << "Possible paths from source to destination:\n";
    for (const string& path : paths) {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}
