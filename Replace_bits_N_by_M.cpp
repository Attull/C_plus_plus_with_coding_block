#include<iostream>
using namespace std;


int clear_bit_in_range(int n,int p,int q)
{
    int a=(1<<p)-1;
    int b=(-1<<(q+1));
    int mask=a|b;
    n=(n&mask);

    return n;
}

void replace_bits(int n,int m,int i,int j)
{
    int num=clear_bit_in_range(n,i,j);            //first clear that range bits
    int r=num|(m<<i);
    cout<<r;

}
int main()
{
    int n=63;
    int m=5;
    replace_bits(n,m,1,3);

    return 0;
}



