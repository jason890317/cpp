#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <numeric>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> duo(strs.begin(),strs.end());
        map<string,vector<int>> hash;
        auto sort_str = [](string &a){
            sort(a.begin(),a.end());
        };
        for_each(duo.begin(),duo.end(),sort_str);
        for(int i=0;i<strs.size();i++)
        {
            hash[duo[i]].push_back(i);
        }
        for(auto item:hash)
        {
            vector<string> temp;
            for(auto t:item.second)
            {
                temp.push_back(strs[t]);
            }
            result.push_back(temp);
        }
        return result;
    }
};