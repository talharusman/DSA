#include<iostream>
using namespace std;
/*
    => we use here the divide & conquer role
        -> divide problem into subproblems
        -> conquer (solve) the subproblems
        -> combine solutions of subproblems
*/

int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first - 1; // Inserting elements < pivot 

    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Now i is pointing to the last element < pivot
    // Correct position for the pivot is i + 1
    swap(arr[i + 1], arr[last]);

    // Return the position of the pivot
    return i + 1;
}

void QuickSort(int arr[], int first, int last) {
    // Base case: If there's 1 or no element left, stop recursion
    if (first >= last) {
        return;
    }

    // Recursive case
    int pi = partition(arr, first, last); // Partition and get pivot index
    QuickSort(arr, first, pi - 1);  // Sort the left side of pivot
    QuickSort(arr, pi + 1, last);   // Sort the right side of pivot
}

int main(int argc, char const *argv[]) {
    int arr[] = {10, 3, 2, 8, 4, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, n - 1); // Apply quicksort to the entire array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print the sorted array
    }  

    return 0;
}
