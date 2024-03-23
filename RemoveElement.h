#include<vector>
#include<algorithm>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        
        int origin_len=nums.size();
        while(std::find(nums.begin(),nums.end(),val) != nums.end())
        {
            nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        }
        
        

        return nums.size();
    }
};