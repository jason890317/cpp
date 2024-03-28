#include<vector>
#include<iostream>
#include<algorithm>
#include <cmath>

using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> temp; //1000000
        
        for(int i=0;i<nums.size()-1;i++)
        {
           
            copy(nums.begin()+(i+1),nums.end(),back_inserter(temp));
            sort(temp.begin(),temp.end());
            if(binarySearch(temp,nums[i])!=-1)
            {
                return nums[i];
            }
            for(auto i:temp)
            {
                temp.pop_back();
            }
            
        }

        return 0;
    }


    int binarySearch(vector<int> &nums,int target) {
    int left = 0;
    int right = nums.size()-1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // This helps to prevent overflow

        if (nums[mid] == target) {
            
            return mid;  // Target found, return its index
        } else if (nums[mid] < target) {
            
            left = mid + 1;  // Target is on the right half
        } else {
            right = mid - 1;  // Target is on the left half
        }
    }

    // Target not found
    return -1;
}
};