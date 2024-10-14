#include<iostream>
#include<vector>
using namespace std;

/*
    Given a sorted integer array and an integer target, find the lower bound of the target.
    
    The lower bound is defined as the index of the smallest element in the array that is 
    greater than or equal to the target.

    If the target is greater than all elements in the array, return the size of the array.

    Example:
     arr = [-1, 3, 5, 7, 9], target = 6
     The lower bound of 6 is 3 because 7 is the smallest number that is greater than or equal to 6.
     The element at index 3 is 7, so we return 3.
*/
int lower_bound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();
    
    // Binary search for the lower bound
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        
        if (arr[mid] < target) {
            lo = mid + 1; // Move right if the mid value is smaller than the target
        } else {
            hi = mid; // Move left if the mid value is greater than or equal to the target
        }
    }
    
    return lo; // 'lo' will be the index of the lower bound
}

int main() {
    vector<int> arr = {-1, 3, 5, 7, 9};
    int target = 06;
    
    int lb = lower_bound(arr, target);
    cout << "Lower bound of " << target << " is at index: " << lb << endl; // Expected output: 3
    
    return 0;
}
