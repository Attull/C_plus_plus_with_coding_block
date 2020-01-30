#include<iostream>
using namespace std;

int clear_bit(int n,int pos)
{
    int mask;
    mask=~(1<<pos);

    n=(n&mask);

    return n;
}

int upadte_bit(int n,int pos,int val)
{
    int r,mask;
    if(val==0)
    {
        mask=~(1<<pos);
        r=(n & mask);
    }
    else
    {
        mask=(1<<pos);
        r=(n | mask);
    }
    return r;
}

int main()
{
    int n;
    cout<<"enter the number \n";
    cin>>n;

    int pos;
    cout<<"enter the position from right to clear or update bit\n";
    cin>>pos;

    int r=clear_bit(n,pos);
    cout<<"bit at required position is \n";
    cout<<r<<endl;

    int val;
    cout<<"enter the bit value(0/1) that you want to put at required position \n";
    cin>>val;

    int re=upadte_bit(n,pos,val);
    cout<<"number after updating bit at given poistion \n";
    cout<<re;

}

