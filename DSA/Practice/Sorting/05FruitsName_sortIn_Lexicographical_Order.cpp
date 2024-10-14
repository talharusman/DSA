#include<iostream>
#include<vector>
using namespace std;

/*
    -> Give an array of names of the fruits; you are supposed
       to sort it in lexicographical order using the selection 
       sort algorithm.
       Example.
       Input: ["papaya", "lime", "watermelon", "apple" , "mango" , "kiwi"]
       Output: ["apple", "kiwi", "lime", "mango", "papaya" , "watermelon"]
*/

void Sort_In_Lexicographical_order(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // place the minemum element at the begin of unsorted array
        if (i != min_index) {
            swap(arr[i], arr[min_index]);
        }
    }
}

int main() {
    string arr[] = {"papaya", "lime", "watermelon", "apple", "mango", "kiwi"};
    int n = sizeof(arr) / sizeof(arr[0]);  // Size of the array

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    Sort_In_Lexicographical_order(arr, n);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}
