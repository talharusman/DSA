#include <iostream>
#include <vector>

using namespace std;

// Function to check if the adjacency matrix is symmetric
bool isSymmetric(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false; // Found a mismatch, not symmetric
            }
        }
    }
    return true; // All pairs match, symmetric
}

// Function to print the adjacency matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example adjacency matrix (undirected graph)
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    cout << "Adjacency Matrix:" << endl;
    printMatrix(adjacencyMatrix);

    if (isSymmetric(adjacencyMatrix)) {
        cout << "The graph is symmetric (undirected)." << endl;
    } else {
        cout << "The graph is not symmetric (directed)." << endl;
    }

    return 0;
}