#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a=findMin(nums);
        // cout<<a;
        int b=0;
        vector<int> r;
        for(int i=0;i<nums.size();i++)
        {
            r.push_back(nums[(a+i)%nums.size()]);
        }
        for(auto i:r)
        {
            cout<<i<<endl;
        }
        nums=r;
        b=binarySearch(r, target);
        
        if(b==-1)
        {
            return -1;
        }
        else{
            return (b+a)%nums.size();
        }
    }
    int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    // Handle the case where the array is not rotated.
    if (nums[left] <= nums[right]) {
        return left;
    }
    
    // Binary search way
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            // The minimum value must be to the right of mid.
            left = mid + 1;
        } else {
            // The minimum value is not to the right of mid.
            right = mid;
        }
    }
    
    // When left equals right, we found the smallest number.
    return left;
}
    int binarySearch(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

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