#include <iostream>
#include <vector>

using namespace std;

// Function to convert adjacency matrix to adjacency list
vector<vector<int>> matrixToList(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> adjacencyList(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                adjacencyList[i].push_back(j);
            }
        }
    }
    return adjacencyList;
}

// Function to convert adjacency list to adjacency matrix
vector<vector<int>> listToMatrix(const vector<vector<int>>& adjacencyList) {
    int n = adjacencyList.size();
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j : adjacencyList[i]) {
            matrix[i][j] = 1;
        }
    }
    return matrix;
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

// Function to print the adjacency list
void printList(const vector<vector<int>>& adjacencyList) {
    for (int i = 0; i < adjacencyList.size(); i++) {
        cout << i << ": ";
        for (int j : adjacencyList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example adjacency matrix
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    cout << "Adjacency Matrix:" << endl;
    printMatrix(adjacencyMatrix);

    // Convert matrix to list
    vector<vector<int>> adjacencyList = matrixToList(adjacencyMatrix);
    cout << "\nAdjacency List:" << endl;
    printList(adjacencyList);

    // Convert list back to matrix
    vector<vector<int>> convertedMatrix = listToMatrix(adjacencyList);
    cout << "\nConverted Back to Adjacency Matrix:" << endl;
    printMatrix(convertedMatrix);

    return 0;
}