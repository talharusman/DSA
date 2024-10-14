#include <iostream>
using namespace std;

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // Keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i++) {
            // Save arr[i] in temp and make a hole at position i
            int temp = arr[i];

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {12, 34, 54, 2, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
