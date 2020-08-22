#include<iostream>
using namespace std;

#define ll long long int

int last_occ(ll *a,ll n,int m,int idx)
{
    if(idx==n)
        return -1;

    int rr=last_occ(a,n,m,idx+1);                //

    if(a[idx]==m && rr==-1)
        return idx;

    return rr;
}

int main() {

	ll n;
    cin>>n;
	ll arr[1001];

	for(ll i=0;i<n;++i)
		cin>>arr[i];

	int m;
    cin>>m;

    cout<<last_occ(arr,n,m,0);
	return 0;
}
