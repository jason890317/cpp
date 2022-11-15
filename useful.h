#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class pro_1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		
		vector<int> idx;
		//cout<<nums.size()<<endl<<endl;
		for(auto i=0; i<nums.size();++i)
		{
				for(auto j=i+1; j!=nums.size();++j)
				{
						//cout<<nums[i]<<endl;
						if(nums[j]+nums[i]== target)
						{
							idx.push_back(i);
							idx.push_back(j);
							break;
						}
				}
		}
		return idx;
    }
};

bool isNumber(char a)
{
	if(a<=57 && a>=48)
	{
		return true;
	}
	return false;
}
