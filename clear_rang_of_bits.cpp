#include<iostream>
using namespace std;

int clear_last_bit(int n,int rng)
{
    int mask;
    mask=-1<<rng;
    n=(n&(mask));

    return n;
}

int clear_bit_in_range(int n,int p,int q)
{
    int b=(~0<<(p+1));
    int a=((1<<q)-1);
    int mask=(a|b);

    n=(n&mask);

    return n;
}
int main()
{
    int n;
    cout<<"enter the number \n";
    cin>>n;

    int rng;
    cout<<"enter the range from last\n";
    cin>>rng;

    int r=clear_last_bit(n,rng);
    cout<<"after clearing bit new number is\n";
    cout<<r<<endl;

    cout<<"after clearing range of bit new number is\n";
    int rr=clear_bit_in_range(n,3,1);

    cout<<rr;

}


