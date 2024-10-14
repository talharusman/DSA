#include<iostream>
#include<vector>
using namespace std;
// Repetely find min element in unsorted array and place it at beginning 
// until array is sorted


/*
   -> Total No of time loop will run in wrost case = sum of elements from 1 to n - 1
      i.e. n + (n-1) + (n-2) + ... +
      i.e. n*(n-1)/2

    -> time complexcity = O(n^2)
    -> space complexcity = O(1)
    -> Max Swaps in worst case = O(n)

    -> It is stable sort 

*/
void SelectionSort(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(v[minIndex] > v[j]){
                minIndex = j;
            }
        }
        
        swap(v[i], v[minIndex]);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    SelectionSort(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
