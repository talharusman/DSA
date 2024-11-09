#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum value in the array
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

// Counting Sort for a specific digit place (exp)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array to store sorted order
    int count[10] = {0}; // Count array to store digit frequencies

    // Store count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so that it contains the position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array based on current digit place
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted output array back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
// Radix Sort function
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr); // Get maximum number to know number of digits

    // Apply counting sort for every digit place (1s, 10s, 100s, ...)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    printArray(arr);

    }
}



int main() {
    vector<int> arr = {36,987,654,2,20,99,456,957,555,420,66,3};
    printArray(arr);
    
    // Sort in ascending order
    radixSort(arr);
    cout<<endl;
    // Sort in descending order by reversing the sorted array
    reverse(arr.begin(), arr.end());
    cout <<endl;
    printArray(arr);

    return 0;
}
