#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        bool flag = false;
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }
        if(!flag)
            break;

    }

}
/*
    Stable sort 
        soes not distrub the order of elements with saame value
    unstable sort 
        does not care about the order of elements with same value
    
    bubble sort is stabe sort
*/

/*
    maximum no of swap in worst case in buble sort 
    is n*(n-1)/2-> som fo 1 to n - 1
    * Time complexity = o(n^2)
    * Space compxcity = O(1)
    *  stable sort
    * Max swap in wrost case = O(n^2)

*/

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    bubbleSort(v);
    
    for (int i = 0; i < n; ++i)
    {
        cout<<v[i]<<" ";
    }
   

    return 0;
}
