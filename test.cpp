#include"btree.h"

int main()
{
    tree<int,int> a;
    a.add(1,0);
    a.add(5,8);
    a.add(4,0);
    a.add(3,5);
    cout<<a.search(5)->tar<<endl;
    
    
    return 0;
}