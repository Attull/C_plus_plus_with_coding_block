//Given n wines in a row, with integers denoting the cost of each wine respectively.
//Each year you can sale the first or the last wine in the row. However, the price of wines increases over time

#include<iostream>
using namespace std;

int profit(int wines[],int i,int j,int dp[][100],int l)
{
    if(i>j)
        return 0;

    if(dp[i][j]!=0)
        return dp[i][j];

    int max_So_far=0;
    int opt1=wines[i]*l + profit(wines,i+1,j,dp,l+1);
    int opt2=wines[j]*l + profit(wines,i,j-1,dp,l+1);

    int res=max(opt1,opt2);
    return dp[i][j]=res;
}

int main()
{
    int wines[]={2,3,5,1,4};
    int n=sizeof(wines)/sizeof(int);
    int l=1;
    int dp[100][100]={0};
    cout<<profit(wines,0,n-1,dp,l);

    return 0;
}
