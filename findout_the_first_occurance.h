    #include<string>
    #include<iostream>
    using namespace std;
    class Solution {
    public:
        int strStr(string haystack, string needle) {
            
            int ptr=0;
            int n;
            int p=0;
            int route=haystack.size()-needle.size()+1;
            bool check=false;
            // cout<<route<<endl;
            while(ptr <=route && check==false)
            {
                p=0;
                n=ptr;
                // cout<<ptr;
                for(int i=0;i<needle.size();i++)
                {
                    if(haystack[n]!=needle[i])
                    {
                        // cout<<haystack[n]<<" "<<needle[i]<<endl;
                        break;
                    }
                    else{
                        // cout<<haystack[n]<<" "<<needle[i]<<endl; 
                        n++;
                        p++;
                        // cout<<n;
                    }
                }
                
                if(p==needle.size())
                {
                    check=true;   
                }
                else{
                    ptr++;
                }
                
                
            }
            // cout<<ptr;
            if(check==false)
            {
                ptr=-1;
            }
            return ptr;
            
        }
    };