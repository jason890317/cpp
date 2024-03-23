#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0;
        int right=0;
        int r;
        int j=0;
        vector<int> record;
        while(right<nums.size())
        {
            r=0;
            right=left;
            while(nums[right]==nums[left])
            {
                r++;
                left++;
            }
            nums[j]=nums[left-1];
            j++;
            right+=r;
        }

        // for(int i=0;i<j;i++)
        // {
        //     cout<<nums[i];
        // }
        
       

        return j;

    }
};