#include<iostream>
using namespace std;

#define ll long long

void prime_sieve(int *p,int n)
{
    //first mark all odd number's prime because odd number have high possibility of being prime
    for(int i=3;i<=n;i=i+2)
        p[i]=1;

    //sieve
    for(ll i=3;i<n;++i)
    {
        if(p[i]==1)
        {
            //mark all multiple of i as not prime
            for(ll j=i*i;j<=n;j=j+i)
                p[j]=0;
        }
    }

    p[2]=1;
    p[1]=p[0]=0;

}
int main()
{
    int n;
    cin>>n;

    int p[10000]={0};
    prime_sieve(p,n);

    int csum[10000]={0};

    for(int i=1;i<=n;++i)
    {
        csum[i]=csum[i-1]+p[i];
    }

    int a,b;
    cin>>a>>b;
    cout<<csum[b]-csum[a-1]<<endl;

    return 0;
}
