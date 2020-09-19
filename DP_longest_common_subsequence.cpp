#include<iostream>
#include<cstring>
using namespace std;

int LCS(char X[],char Y[])
{
    int m=strlen(X);
    int n=strlen(Y);
    int dp[100][100];

    for(int i=0;i<m;++i)
        dp[i][0]=0;

    for(int j=0;j<n;++j)
        dp[0][j]=0;

    for(int i=1;i<=m;++i)
    {
        int q=0;
        for(int j=1;j<=n;++j)
        {
            if(X[i-1] == Y[j-1])
                q=1 + dp[i-1][j-1];
            else
                q=max(dp[i][j-1] , dp[i-1][j]);

            dp[i][j]=q;
        }
    }
    return dp[m][n];
}

int main()
{
    char str1[1000],str2[1000];
    cin>>str1;
    cin>>str2;

    cout<<LCS(str1,str2);
    return 0;
}
