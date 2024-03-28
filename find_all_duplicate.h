#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> duplicates;

    for (int& num : nums) {
        int index = std::abs(num) - 1;  // Convert to index (1-based to 0-based)
        
        if (nums[index] < 0) {
            // If the number at index is already negative, it's a duplicate
            duplicates.push_back(index + 1);  // Convert back to original number
        } else {
            // Negate the number at index to mark it as seen
            
            nums[index] = -nums[index];
        }
    }

    // Optional: Restore the array to its original state
    for (int& num : nums) {
        num = std::abs(num);
    }

    return duplicates;
}
};

