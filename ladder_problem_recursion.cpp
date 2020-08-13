//ladder problem
#include<iostream>
using namespace std;

int f(int n,int k)
{
    if(n==0)
        return 1;

    if(n<0)
        return 0;

    int ans=0;

    for(int i=1;i<=k;++i)
        ans+=f(n-i,k);

    return ans;
}

int main()
{
    int n,k;          //n is total number of steps & k is possible step one can take ..if k=2 then he can take 0/1/2 step in one time
    cin>>n>>k;

    cout<<f(n,k)<<endl;
    return 0;
}
