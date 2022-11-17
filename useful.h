#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
using namespace std;



/////////////////////////////// PRO_13 //////////////////////////////////
//Roman to int                                                         //
/////////////////////////////////////////////////////////////////////////
class pro_13{
public:
	map<char, int> roman
	{
		{'I' , 1},
		{'V' , 5},
		{'X' , 10},
		{'L' , 50},
		{'C' , 100},
		{'D' , 500},
		{'M' , 1000},
	};
	int romanToInt(string s) {
    	  
		  int sum = roman[s[s.length()-1]];
		  int plus_or_minus;
		  for(int i=s.length()-1; i >0; --i)
		  {
				if(roman[s[i]]-roman[s[i-1]] > 0 )
				{
					plus_or_minus = -1;
				}
				else
				{
					plus_or_minus = 1;
				}

				sum += plus_or_minus*roman[s[i-1]]; 
		  }

		  return sum;
    }
};


///////////////////////////////// PRO_9 /////////////////////////////////
//Palindrome Number                                                    //
/////////////////////////////////////////////////////////////////////////
class pro_9 {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
		for(int i=0; i < num.length(); ++i)
		{
			if(num[i]!=num[num.length()-1-i])
			{
				return false;
			}
		}
		return true;
    }
};
/////////////////////////////////////////////////////////////////////////



///////////////////////// LISTNODE_STRUCTURE/////////////////////////////
// structure of listnode                                               // 
/////////////////////////////////////////////////////////////////////////
struct ListNode 
{
	int val;
	ListNode *nextnode;
	void value(int a){val=a;}
	void next(ListNode* n){nextnode=n;}
	ListNode()
	{
		value(0);
		next(NULL);
	}
	ListNode(int x)
	{
		value(x);
		next(NULL);
	}
	ListNode(int x, ListNode* n)
	{
		value(x);
		next(n);
	}
};
////////////////////////////////////////////////////////////////////////



//////////////////////////// PRO_21 ////////////////////////////////////
// merge two listnodes                                                //
////////////////////////////////////////////////////////////////////////
class pro_21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
	{
		ListNode *list, *ptr;
		if(list1==NULL)
		{
			return list2;
		}
		if(list2 == NULL)
		{
			return list1;
		}
		
		if(list1->val < list2->val)
		{
			ptr=list1;
			list=list1;
			list1=list1->nextnode;
		}
		else
		{
			ptr=list2;
			list=list2;
			list2=list2->nextnode;
		}

		while(list1!= NULL && list2!=NULL)
		{
			if(list1->val < list2->val)
			{
				ptr->nextnode=list1;
				ptr=ptr->nextnode;
				list1=list1->nextnode;
			}
			else
			{
				ptr->nextnode=list2;
				ptr=ptr->nextnode;
				list2=list2->nextnode;
			}
		}
		while(list1!=NULL)
		{
			ptr->nextnode=list1;
			ptr=ptr->nextnode;
			list1=list1->nextnode;
		}
		while(list2!=NULL)
		{
			ptr->nextnode=list2;
			ptr=ptr->nextnode;
			list2=list2->nextnode;
		}
		
		return list;
    }
};
////////////////////////////////////////////////////////////////////////




//////////////////////////// PRO_1 //////////////////////////////////// 
// choose two indexs that the sum of their members equals the target //
/////////////////////////////////////////////////////////////////////// 
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
////////////////////////////////////////////////////////////////////////
