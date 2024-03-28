#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        matrix=matrix_T(matrix);
        matrix_col_exchange(matrix);
    }
    vector<vector<int>> matrix_multiply(vector<vector<int>>& a,vector<vector<int>>& b)
    {
        int m=a.size();
        int k=a[0].size();
        int n=b[0].size();
        vector<int> temp;
        vector<vector<int>> c;
        int sum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int r=0;r<k;r++)
                {
                    sum+=a[i][r]*b[r][j];
                }
                temp.push_back(sum);
                sum=0;
            }
            c.push_back(temp);
            for(auto &i:temp)
            {
                temp.pop_back();
            }
        }

        return c;
    }

    void matrix_col_exchange(vector<vector<int>> &a)
    {
        int row=a.size();
        int col=a[0].size();
        int temp;
        for(auto &item:a)
        {
            for(int j=0;j<col/2;j++)
            {
                temp=item[j];
                item[j]=item[col-1-j];
                item[col-1-j]=temp;
            }
        }
    }

    vector<vector<int>> matrix_T(vector<vector<int>> &a)
    {
        vector<int> temp;
        vector<vector<int>> result;

        int m=a.size();
        int n=a[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                temp.push_back(a[j][i]);
            }
            result.push_back(temp);
            for(auto i:temp)
            {
                temp.pop_back();
            }
        }
        return result;
    }
     void rotate_potent(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=m;
        
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++){
        reverse(matrix[i].begin(),matrix[i].end());
        
    }
    }
};