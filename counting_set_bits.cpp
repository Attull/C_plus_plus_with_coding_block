#include<iostream>
#include<algorithm>
using namespace std;

void count_set_bits(int n)
{
    int ans=0;
    while(n>0)
    {
        ans+=(1&n);
        n=n>>1;
    }
    cout<<ans<<endl;
}

void count_set_bits_fast(int n)
{
    int ans=0;
    while(n>0)
    {
        n=n&(n-1);
        ++ans;
    }
    cout<<ans<<endl;
}
int main()
{
    int n=63;
    count_set_bits(n);
    count_set_bits_fast(n);
    cout<<__builtin_popcount(n)<<endl;         //inbuild function for counting set bits
    return 0;
}



