#include<iostream>
using namespace std;

//top-down approach
int max_profit(int arr[],int total_len,int dp[])
{
    if(total_len==0)
        return 0;

    if(dp[total_len]!=0)
        return dp[total_len];

    int best=0;
    for(int len=1;i<total_len;++len)
    {
        int net_profit=arr[len]+max_profit(arr,total_len-len);
        best=max(best,net_profit);
    }
    dp[total_len]=best;
    return dp[total_len];
}

//bottom-up approach
int max_profit_BU(int arr[],int total_len)
{
    int dp[100]={0};

    for(int len=1;len<=total_len;++len)
    {
        int best=0;
        for(int cut=1;cut<=len;++cut)           //cut=1 means we consider 1 length cut
        {
            dp[len]=arr[cut]+dp[len-cut];
            best=max(best,dp[len]);
        }
        dp[len]=best;
    }
    return dp[total_len];
}

int main()
{
    int arr[]={2,3,2,5};
    int n=sizeof(arr)/sizeof(int);

    cout<<max_profit(arr,n);

    return 0;
}
