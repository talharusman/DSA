#include<iostream>
#include<vector>
using namespace std;

/*
    Given a sorted array of n elements and target 'x'. find the first occurrence of 
    'x' in the array. If 'x' is not present in the array, return -1

*/
int findFirstOccurrence(vector<int>& v,int target){
    int start = 0, end = v.size()-1;
    int result = -1;
    while(start <= end){
        int mid = (end + start)/2;
         if(v[mid] < target){
            start = mid+1;
        }
        else if(v[mid] > target){
            end = mid-1;
        }
        else{
            if(mid > 0 && v[mid - 1] == target)
                end = mid - 1;
            else 
                return mid;
        }
    }
    return result;

}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int target = 5;
    int result = findFirstOccurrence(v, target);
    cout << result << endl;

    return 0;
}
