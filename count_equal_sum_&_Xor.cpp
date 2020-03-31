#include<iostream>
using namespace std;
int main ()
{
	long int n;
	cin>>n;
	int c=0;
	for(int i=0;i<=n;++i)
    {
        if((n+i)==(n^i))
            ++c;

    }

	cout<<c;
	return 0;
}

//method 2
/*
An efficient solution is as follows

So n + i = n ^ i implies n & i = 0
*/
