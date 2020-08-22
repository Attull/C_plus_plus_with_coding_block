#include<iostream>
#include<algorithm>
using namespace std;


void coin_exchange(int *coin,int n,int money)
{
    int cnt=0;
    while(money>0)
    {
        int idx=upper_bound(coin,coin+n,money)-1-coin;
        money=money-coin[idx];
        cout<<coin[idx]<<"+";
        cnt++;
    }
    cout<<endl<<cnt;
}
int main()
{
    int money;
    cin>>money;

    int coin[]={1,2,5,10,20,50,100,200,500,1000,2000};
    int n=sizeof(coin)/sizeof(int);
    coin_exchange(coin,n,money);
    return 0;
}
