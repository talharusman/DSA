#include<iostream>
#include<vector>
using namespace std;
/*
  -> Repeatedly take elemnets from unsorted subarray and 
     insert them into the sorted subarray.

  -> Time complexcity = in wost casenO(n^2) and O(n) in the best case when the array is already sorted.
  -> Space complexity = O(1).
  -> it is Stable sort.


*/

void display(vector<int>V){
    for(int i=0;i<V.size();i++){
        cout<<V[i]<<" ";
    }
    cout<<endl;
}
void InsertionSort(vector<int> &v){
     int n = v.size();
     for(int i = 1; i < n; i++){
        int key = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    
     }

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    InsertionSort(a);

    for (int i = 0; i < n; i++)
    {
        
        cout << a[i] << " ";
    }
    

    return 0;
}
