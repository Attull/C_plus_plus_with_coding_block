#include<iostream>
#include<climits>
using namespace std;

int min_coins_TD(int num,int coins[],int cnt,int dp[])
{
    //base case
    if(num==0)
        return 0;

    if(dp[num]!=0)
        return dp[num];

    int ans=INT_MAX;
    for(int i=0;i<cnt;++i)
    {
        if(num-coins[i]>=0)
        {
            int subprob=min_coins_TD(num-coins[i],coins,cnt,dp);
            ans=min(ans,subprob+1);
        }
    }
    dp[num]=ans;
    return dp[num];
}

int min_coins_BU(int num,int coins[],int cnt)
{
    int dp[100]={0};

    for(int i=1;i<=num;++i)
    {
        dp[i]=INT_MAX;

        for(int j=0;j<cnt;++j)
        {
            if(i-coins[j]>=0)
            {
                int subprob=dp[i-coins[j]];
                dp[i]=min(dp[i],subprob+1);
            }
        }
    }
    return dp[num];
}

int main()
{
    int num;
    cin>>num;

    int coins[]={1,7,10};
    int dp[100]={0};
    int cnt =sizeof(coins)/sizeof(int);

   // min_coins_TD(num,coins,cnt,dp);

    cout<<min_coins_BU(num,coins,cnt);
    return 0;
}
