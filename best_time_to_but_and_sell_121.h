#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 100000;
    int maxProfit = 0;
    
    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price; // Keep track of the lowest price seen so far.
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice; // Update max profit if selling today yields more.
        }
    }
    
    return maxProfit;
    }
};