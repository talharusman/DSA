#include<iostream>
#include<vector>
using namespace std;
/*
    -> Given an integer array arr move all 0's to the end of
       while maintaining the realtive order of the non-Zero elements.
       :- Note That you must do this in-place without making a copy of the array
       Exemple.
       Input: [0,1,0,13,12]
       Output: [1,13,12,0,0]

*/

void display(vector<int>V){
    for(int i=0;i<V.size();i++){
        cout<<V[i]<<" ";
    }
    cout<<endl;
}

 void Move_0s_to_the_end(vector<int> &arr){
    // approch 1

    // int n = arr.size();
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     int j = 0;
    //     bool flage = false;
    //     while (j != i){
    //         if (arr[j] == 0 && arr[j + 1] != 0){
    //             swap(arr[j], arr[j + 1]);
    //             flage = true;
    //         }
    //         j++;
    //     }
    //     if(!flage)
    //     {
    //         break;
    //     }
    // }

    // --------- Approch 2 ----------

    int n = arr.size();
    int lastNonZero = 0; // Pointer for the last non-zero element

    // Shift non-zero elements to the front 
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[lastNonZero]);
            lastNonZero++;
            
        }

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
        Move_0s_to_the_end(a);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    
    
    return 0;
}
