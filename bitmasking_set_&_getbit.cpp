#include<iostream>
using namespace std;

bool isodd(int n)
{
    return (n&1);
}

bool getbit(int n,int pos)
{
    int mask;
    mask=(1<<pos);                     //left shift

    bool r=(n&mask)>0 ? 1 : 0;          //bitwise AND

    return r;
}

int setbit(int n,int pos)
{
    int mask;
    mask=(1<<pos);

    int r=(n | mask);

    return r;
}
int main()
{
    int n;
    cout<<"enter the number \n";
    cin>>n;

    int res=isodd(n);
    if(res==1)
        cout<<"number is odd \n";
    else
        cout<<"number is even";

    int pos;
    cout<<"enter the position from right to get or set bit\n";
    cin>>pos;

    int r=getbit(n,pos);
    cout<<"bit at required position is \n";
    cout<<r<<endl;

    int re=setbit(n,pos);
    cout<<"number after setting bit at given poistion \n";
    cout<<re;

}
