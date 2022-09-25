#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int a=10;
	int b[]={1,2,3};
	b[1]=1;
	vector<int> v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	for(int i : v)
	{
		cout<<i<<endl;
	}
	
	return 0;
}
