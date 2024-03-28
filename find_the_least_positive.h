#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
    int n = nums.size();

    // Move non-positive numbers to the beginning and find the start index for positive numbers
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] <= 0) {
            std::swap(nums[i], nums[k++]);
        }
    }

    // Mark the presence of elements
    for (int i = k; i < n; ++i) {
        int val = std::abs(nums[i]);
        if (val + k - 1 < n && nums[val + k - 1] > 0) {
            nums[val + k - 1] = -nums[val + k - 1];
        }
    }

    // Find the first missing positive
    for (int i = k; i < n; ++i) {
        if (nums[i] > 0) {
            return i - k + 1;
        }
    }

    // If all positive numbers from 1 to n-k are present
    return n - k + 1;
}
};