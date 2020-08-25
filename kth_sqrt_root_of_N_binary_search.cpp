#include<iostream>
#include<math.h>
using namespace std;

#define ll long long int

ll kroot(ll n,ll k)
{
    ll res=1;
    ll s=0,e=n;

    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(pow(mid,k)==n)
        {
            res= mid;
            break;
        }
        else if(pow(mid,k)<n)
        {
            res=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }

    return res;
}
int main() {
    int t;                          //no. of test cases
    cin>>t;
    while(t--)
    {
        ll n,k;                     //n is the number whose kth root we have to find & k define root nature
        cin>>n>>k;
        ll ans=kroot(n,k);
        cout<<ans<<endl;
    }
	return 0;
}
