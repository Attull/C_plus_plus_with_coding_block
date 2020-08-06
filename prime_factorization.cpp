#include<iostream>
#include<vector>
using namespace std;

void prime_factors(int n)
{
    vector<pair<int,int>> factors;       //vector is used for dynamic memory
    int cnt;

    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
            factors.push_back(make_pair(i,cnt));         //make_pair() is used to assign value to pair
        }
    }
    if(n!=1)
    {
        //whatever is left is a prime number so store it
        factors.push_back(make_pair(n,1));
    }

    for(auto p:factors)
        cout<<p.first<<"^"<<p.second<<endl;
}

int main()
{
    int n;
    cin>>n;

    prime_factors(n);
    return 0;
}
