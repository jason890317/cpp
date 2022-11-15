#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "useful.h"
using namespace std;



int main()
{
	string input;
	vector<int> input_vec;
    vector<int> output_vec;
	int target;
	pro_1 sl;	

	getline(cin, input);
	for(int i=0;i<input.length(); ++i )
	{
		if(isNumber(input[i]))
		{
			input_vec.push_back(input[i]-48);
		}
	}
	
	target=input_vec[input_vec.size()-1];
	input_vec.pop_back();
   	output_vec=sl.twoSum(input_vec, target);
	
	//cout<<output_vec.size()<<endl;
	cout<<'['; 
	for(auto x:output_vec)
	{
		cout<<x<<',' ;
	}
	cout<<'\b'<<']'<<endl; 
	
	return 0;
}
