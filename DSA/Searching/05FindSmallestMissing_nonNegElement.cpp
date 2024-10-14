#include<iostream>
#include<vector>
using namespace std;

/*
    Given a sorted array of non_negative distinct intergers
    find the smallest missing non_negative element in it.
    
*/

int FindMissing_Non_negative(vector<int> arr) {
    int n = arr.size();
    int lo = 0, hi = n - 1;
    int ans = arr[n - 1] + 1;
    
    while (lo <= hi) {
        int mid = (lo + hi)/ 2;
        if (arr[mid] == mid) {
            lo = mid + 1;
        } else {
            ans = mid;
            hi = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6};
    cout << "Smallest missing non-negative number: " << FindMissing_Non_negative(v) << endl;

    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7}; // Missing 0
    cout << "Smallest missing non-negative number: " << FindMissing_Non_negative(v2) << endl;

    return 0;
}
