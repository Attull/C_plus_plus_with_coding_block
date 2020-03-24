#include<iostream>
using namespace std;
int find_xor(int l,int r)
{
	int temp=0,m=0;
	while(l<=r)
	{
		for(int i=l+1;i<=r;++i)
		{
			temp=l^i;
            if(temp>=m)
            {
                m=temp;
            }
        }
		++l;
	}
    return m;
}
int main() {
	int t;
	cin>>t;                    //number of test case
	while(t--)
	{
		int l,r;
		cin>>l>>r;             //enter the range of which we have to find xor

		cout<<find_xor(l,r)<<endl;
	}
	return 0;
}
