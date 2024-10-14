#include<iostream>
#include<vector>
using namespace std;

/*
    Interpolation Search Algorithm Steps:
    1. The array must be sorted and uniformly distributed.
    2. Initialize start = 0 and end = n - 1.
    3. Calculate the position (pos) to start searching:
       pos = start + ((end - start) / (arr[end] - arr[start])) * (target - arr[start])
    4. If arr[pos] == target, return pos as the index of the element.
    5. If target > arr[pos], adjust the start = pos + 1.
    6. If target < arr[pos], adjust the end = pos - 1.
    7. Exit conditions:
       The search continues while start <= end and target is within the range [arr[start], arr[end]].
*/

// Time complexcity = O(log log n)


int interpolationSearch(vector<int> arr, int target) {
    int n = arr.size();
    int start = 0, end = n - 1;
    
    // Search loop
    while (start <= end && target >= arr[start] && target <= arr[end]) {
        if (start == end) {
            if (arr[start] == target) return start;
            return -1;
        }

        // Calculate position based on interpolation formula
        int pos = start + ((double)(end - start) / (arr[end] - arr[start])) * (target - arr[start]);

        // If target is found at pos
        if (arr[pos] == target) {
            return pos;
        }
        // If target is larger, search in the right half
        if (arr[pos] < target) {
            start = pos + 1;
        }
        // If target is smaller, search in the left half
        else {
            end = pos - 1;
        }
    }
    
    // Return -1 if target is not found
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target = 70;
    
    int index = interpolationSearch(arr, target);
    if (index != -1) {
        cout << "Element " << target << " found at index: " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }
    
    return 0;
}
