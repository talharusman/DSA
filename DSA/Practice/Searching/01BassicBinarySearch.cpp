#include<iostream>
#include<vector>
using namespace std;
//leedtcode 704
// in benary search algorithm the order of menber should be sorded
// Time conplexcity
// O(log n)
// Space complexity

class Solution {
    public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return -1;
    
    }
};




int main(int argc, char const *argv[])
{
    vector<int>num = {1,4,5,6,7,8,9};
    Solution s;
    cout<<s.search(num, 5)<<endl;
    
    
    return 0;
}
