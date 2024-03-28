#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right=nums.size()-1;
        int left=0;

        int mid=(left+right)/2;
        
        while(right>left)
        {
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                
                right=mid;
                
            }
            else{
                
                left=mid+1;
                
            }
            mid=(left+right)/2;
        }
        if(mid==nums.size()-1)
        {
            mid+=1;
        }
        
        return mid;

    }
    
};