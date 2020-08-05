#include<iostream>
using namespace std;

#define ll long long

//brute-force method -O(n)
bool is_prime(int n)
{
    if(n==1)
        return false;

    if(n==2)
        return true;

    for(int i=2;i<n;++i)
    {
        if(n%i==0)
            return false;
    }

    return true;
}

//optimize technique - O((sqr(n))
bool iis_prime(int n)
{
    if(n==1)
        return false;

    if(n==2)
        return true;

    for(int i=2;i*i<n;++i)
    {
        if(n%i==0)
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin>>n;

    cout<<iis_prime(n);
    return 0;
}
