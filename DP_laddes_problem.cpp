//Count the number of ways, the person can reach the top given n stairs and person take at most k steps each time

#include<iostream>
using namespace std;

//top down approach
int no_of_ways(int n,int k,int dp[])
{
    if(n==0)
        return 1;

    if(dp[n]!=0)
        return dp[n];

    int ways=0;
    for(int i=1;i<=k;++i)
    {
        if(n-i>=0)
            ways+=no_of_ways(n-i,k,dp);
    }
    return dp[n]=ways;
}

//bottom up approach
int no_of_way(int n,int k)
{
    int dp[100]={0};

    dp[0]=1;

    for(int i=1;i<=n;++i)
    {
        dp[i]=0;
        for(int j=1;j<=k++j)
        {
            if(i-j>=0)
                dp[i]+=dp[i-j];
        }
    }
    return dp[i];
}
//bottom up approach optimised
int no_of_wayo(int n,int k)
{
    int dp[100]={0};

    dp[0]=dp[1]=1;

    for(int i=2;i<=k;++i)
    {
        dp[i]=2*dp[i-1];
    }

    for(int i=k+1;i<=n;++i)
    {
        dp[i]=2*dp[i-1] - dp[i-k-1];
    }

    cout<<"dp array is : \t";
    for(int j=0;j<=n;++j)
        cout<<dp[j]<<" ";

    cout<<endl;
    return dp[n];
}

int main()
{
    int n,k;
    cin>>n>>k;

    int dp[100]={0};
    //cout<<endl<<no_of_ways(n,k,dp);
    cout<<no_of_way(n,k);
    return 0;
}
