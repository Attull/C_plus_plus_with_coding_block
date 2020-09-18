#include<iostream>
using namespace std;

int max_sum(int arr[],int n)
{
    int dp[100]={0};
    dp[0]=arr[0]>0?arr[0]:0;

    int max_sum_so_far=0;
    for(int i=1;i<n;++i)
    {
        dp[i]=dp[i-1]+arr[i];
        if(dp[i]<0)
            dp[i]=0;

        max_sum_so_far=max(dp[i],max_sum_so_far);
    }
    return max_sum_so_far;
}

int main()
{
    int arr[]={-1,3,5,6,-1,5};
    int n=sizeof(arr)/sizeof(int);

    cout<<max_sum(arr,n);

    return 0;
}
