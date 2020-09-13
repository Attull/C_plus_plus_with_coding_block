//find minimum steps to one
//form n we can go to n/3, n/2, n-1

#include<iostream>
#include<climits>>      //for INT_MAX
using namespace std;

int min_steps_TD(int n,int dp[])
{
    //base case
    if(n==1)            //n==1 means we already reached to 1, so 0 steps
        return 0;

    //lookup if n is already computed
    if(dp[n]!=0)
        return dp[n];

    //compute if dp[n] is not known
    int opt1,opt2,opt3;
    opt1=opt2=opt3=INT_MAX;        //default value

    if(n%3==0)
        opt1=min_steps_TD(n/3,dp)+1;

    if(n%2==0)
        opt2=min_steps_TD(n/2,dp)+1;

    opt3=min_steps_TD(n-1,dp)+1;

    int ans=min(min(opt1,opt2),opt3);

    return dp[n]=ans;;

}

int min_steps_BD(int n)
{
    int dp[100]={0};
    dp[1]=0;

    for(int i=2;i<=n;++i)
    {
        int opt1,opt2,opt3;
        opt1=opt2=opt3=INT_MAX;
        if(n%3==0)
            opt1=dp[i/3];
        else if(n%2==0)
            opt2=dp[i/2];

        opt3=dp[i-1];

        dp[i]=min(min(opt1,opt2),opt3)+1;
    }

    return dp[n];
}

int main()
{
    int n;
    cin>>n;

  //  int dp[100]={0};

    //cout<<min_steps_TD(n,dp);

    cout<<min_steps_BD(n);
    return 0;
}
