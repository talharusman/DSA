#include <iostream>
#include <vector>
#include <queue>
#include <utility>

std::vector<int> slidingWindowMaximum(const std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::priority_queue<std::pair<int, int>> maxHeap;

    for (int i = 0; i < nums.size(); ++i) {
        maxHeap.push({nums[i], i});

        if (i >= k - 1) {
            while (!maxHeap.empty() && maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
            result.push_back(maxHeap.top().first);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::vector<int> result = slidingWindowMaximum(nums, k);

    std::cout << "Sliding Window Maximum: ";
    for (int maxVal : result) {
        std::cout << maxVal << " ";
    }
    std::cout << std::endl;

    return 0;
}
