//find out the numbers of number b/w 1 and n which are divisible by any of prime number less than 20

#include<iostream>
using namespace std;

#define ll long long

int main()
{
    ll t;               //test case
    cin>>t;

    ll primes[]={2,3,5,7,11,13,17,19};

    while(t--)
    {
        ll n;
        cin>>n;

        ll ans=0;
        ll subsets=(1<<8)-1;            //it is 2^8 and 8 is number of prime number less than 20

        for(ll i=1;i<=subsets;++i)
        {
            ll denom=1;
            ll setbits=__builtin_popcount(i);              //to check the set bit of number

            for(ll j=0;j<=7;++j)
            {
                if(i&(1<<j))                              //for example if i=5 then it has two set bits which correspond to two prime number
                {                                         //and multipt them and store in denom
                    denom=denom*primes[j];
                }
            }
            if(setbits&1)           //for odd setbits
            {
                ans+=n/denom;
            }
            else                    //for even setbits
            {
                ans-=n/denom;
            }
        }
    cout<<ans;
    }
    return 0;
}
