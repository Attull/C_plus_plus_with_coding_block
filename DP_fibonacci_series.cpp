//top down approach
// 1. Recursion (reach to lowest level/condition)
// 2. Memorization (store answer)

//bottom up approach
// 1. Memorization
// 2. Recusrion

#include<iostream>
using namespace std;

//top-down appraoch implementation
int fib_TD(int n,int dp[])
{
    //base case
    if(n==0 || n==1)
        return n;

    //recusrion
    //look up
    if(dp[n]!=0)                //if it is not 0, it means it contain some value
        return dp[n];           //so return that value

    int ans;
    ans=fib_TD(n-1,dp)+fib_TD(n-2,dp);      //recursion
    return dp[n]=ans;           //memorization

}

//bottom down approach
int fib_BU(int n)
{
    int dp[100]={0};
    dp[1]=1;

    for(int i=0;i<n;++i)
        dp[i]=dp[i-1]+dp[i-2];

    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int dp[100]={0};
    cout<<fib_BU(n)<<endl;
    cout<<fib_TD(n,dp);

    return 0;
}
